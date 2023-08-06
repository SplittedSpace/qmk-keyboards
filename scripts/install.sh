#!/bin/bash

PROJECT_DIR=$(pwd)

echo "Installing VIAL QMK"

git submodule update --init --recursive
rm -rf vial-qmk/keyboards
ln -s $PROJECT_DIR/keyboards vial-qmk/keyboards