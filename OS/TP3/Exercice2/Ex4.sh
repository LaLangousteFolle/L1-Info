#!/bin/bash
value=0
for ((i = 1; i < 11; i++)); do
  echo "Table de multiplication de $i"
  for ((j = 1; j < 11; j++)); do
    echo
    value=$(($i * $j))
    echo "$i x $j = $value"
  done
done
