#!/bin/bash

var1=$(ls -l $1 | grep - -c)
var2=$(ls -l $2 | grep - -c)

if [ $var1 -gt $var2 ]; then
  echo $1
else
  echo $2
fi
