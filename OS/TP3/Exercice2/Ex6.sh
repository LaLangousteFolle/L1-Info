#!/bin/bash
$(touch fichier0)
for ((i = 0; i < 99; i++)); do
  $(echo $1 >>fichier0)
done
