#!/bin/bash
var=0
for ((i = 0; i < 41; i++)); do
  var=$(($var + $i))
done
echo $var
