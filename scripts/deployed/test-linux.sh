#!/bin/bash

set -xe

export PYTHONPATH=$(pwd)/lib:$(pwd)/test:$PYTHONPATH

python -m unittest test_pysort
