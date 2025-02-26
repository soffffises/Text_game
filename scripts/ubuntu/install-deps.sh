#!/bin/bash

set -xe

sudo apt-get update
sudo apt-get install -y cmake python3 python3-venv python3-dev ninja-build g++
python3 -m venv venv
source venv/bin/activate
pip install conan

mkdir -p ~/.conan2/profiles

if [ ! -e "$HOME/.conan2/profiles/default" ]; then
    echo "[settings]" > ~/.conan2/profiles/default
    echo "os=Linux" >> ~/.conan2/profiles/default
    echo "arch=x86_64" >> ~/.conan2/profiles/default
    echo "build_type=Release" >> ~/.conan2/profiles/default
    echo "compiler=gcc" >> ~/.conan2/profiles/default
    echo "compiler.version=14" >> ~/.conan2/profiles/default
    echo "compiler.libcxx=libstdc++11" >> ~/.conan2/profiles/default
    echo "compiler.cppstd=20" >> ~/.conan2/profiles/default
fi
