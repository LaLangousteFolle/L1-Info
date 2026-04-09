#!/bin/bash
f=$(find -type f | grep - -c)
d=$(find -type d | grep - -c)

echo $f
echo $d
