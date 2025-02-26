dnf install -y bash
#!/bin/bash

set -xe

dnf update -y
dnf install -y bash cmake python3 python3-pip python3-virtualenv python3-devel ninja-build gcc gcc-c++ gtest-devel pybind11-devel make git redhat-rpm-config

python3 -m venv venv
source venv/bin/activate
pip install conan

arch=$(uname -m)
if [[ "$arch" == "x86_64" ]]; then
    conan_arch="x86_64"
elif [[ "$arch" == "aarch64" || "$arch" == "arm64" ]]; then
    conan_arch="armv8"
else
    echo "Unsupported architecture: $arch"
    exit 1
fi

mkdir -p ~/.conan2/profiles
if [ ! -e "$HOME/.conan2/profiles/default" ]; then
    echo "[settings]" > ~/.conan2/profiles/default
    echo "os=Linux" >> ~/.conan2/profiles/default
    echo "arch=$conan_arch" >> ~/.conan2/profiles/default
    echo "build_type=Release" >> ~/.conan2/profiles/default
    echo "compiler=gcc" >> ~/.conan2/profiles/default
    echo "compiler.version=14" >> ~/.conan2/profiles/default
    echo "compiler.libcxx=libstdc++11" >> ~/.conan2/profiles/default
    echo "compiler.cppstd=20" >> ~/.conan2/profiles/default
fi