#!/bin/bash

set -xe

source venv/bin/activate

echo ""
echo "STAGE ONE: Testing the C++ library..."
cd build/Release && ctest --output-on-failure

echo ""
echo "STAGE TWO: Testing the Python wrapper library..."
cd ../..
export PYTHONPATH=$(pwd)/build/Release:$(pwd)/test:$PYTHONPATH
python -m unittest test_pysort