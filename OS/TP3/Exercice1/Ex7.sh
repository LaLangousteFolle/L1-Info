#1/bin/bash

if [ -f $1 ]; then
  echo "Fichier"
else
  echo "Dossier"
fi
