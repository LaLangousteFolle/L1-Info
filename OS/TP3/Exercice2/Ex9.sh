#!/bin/bash
n=basename $1/*.JPG
sudo mv $1/*.JPG $1/$n.jpg
