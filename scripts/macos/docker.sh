#!/bin/zsh

set -xe

DOCKER_BUILDKIT=1 docker build -t fedora-ci .
docker run --rm fedora-ci