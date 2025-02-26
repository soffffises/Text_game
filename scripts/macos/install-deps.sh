#!/bin/zsh

set -xe

brew update
brew install cmake python@3.13 ninja gcc
python3.13 -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install conan

mkdir -p ~/.conan2/profiles
if [ ! -e "$HOME/.conan2/profiles/default" ]; then
    echo "[settings]" > ~/.conan2/profiles/default
    echo "os=Macos" >> ~/.conan2/profiles/default
    echo "arch=armv8" >> ~/.conan2/profiles/default
    echo "build_type=Release" >> ~/.conan2/profiles/default
    echo "compiler=gcc" >> ~/.conan2/profiles/default
    echo "compiler.version=14" >> ~/.conan2/profiles/default
    echo "compiler.libcxx=libstdc++11" >> ~/.conan2/profiles/default
    echo "compiler.cppstd=20" >> ~/.conan2/profiles/default
fi