import serial
import time
import urllib.request
import urllib.parse

SERIAL_PORT = '/dev/ttyACM0'
BAUD_RATE   = 115200
PHP_URL     = 'http://localhost/index.php'
PUSH_TOKEN  = 'changeme_token_secret'   # même valeur que dans config.php

def push_count(count: int) -> None:
    data = urllib.parse.urlencode({
        'action': 'push',
        'count':  count,
        'token':  PUSH_TOKEN,
    }).encode()
    try:
        req = urllib.request.Request(PHP_URL, data=data, method='POST')
        with urllib.request.urlopen(req, timeout=2) as r:
            print(f"[push] count={count} -> {r.read().decode()}")
    except Exception as e:
        print(f"[push] erreur HTTP : {e}")

def main():
    while True:
        try:
            with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
                print(f"[serial] connecté sur {SERIAL_PORT}")
                while True:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    if not line:
                        continue
                    try:
                        push_count(int(line))
                    except ValueError:
                        print(f"[serial] donnée invalide : {repr(line)}")
        except serial.SerialException as e:
            print(f"[serial] port indisponible : {e} — nouvelle tentative dans 5s")
            time.sleep(5)

if __name__ == '__main__':
    main()
