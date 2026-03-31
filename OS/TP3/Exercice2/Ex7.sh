#!/bin/bash
dossiers=0
fichiers=0
f = $(find -type f | grep - -c)
d = $(find -type d | grep - -c)

echo $f
echo $d
