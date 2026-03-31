#!/bin/bash

for ((i = 0; i < 100; i++)); do
  $(touch fichier$i)
done
