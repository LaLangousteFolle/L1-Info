#!/bin/bash
if [ $1 -lt "0" ]; then
  echo "Negatif"
elif [ $1 -gt "0" ]; then
  echo "Positif"
elif [ $1 -eq "0" ]; then
  echo "Nul"
fi
