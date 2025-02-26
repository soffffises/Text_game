#!/bin/bash

set -xe

source venv/bin/activate

conan install . --build=missing
conan build .
