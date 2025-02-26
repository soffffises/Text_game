#!/bin/zsh

set -xe

ARTIFACT="pysort.zip"
ARTIFACT_DIR="dist"

rm -rf "$ARTIFACT" "$ARTIFACT_DIR"

mkdir -p "$ARTIFACT_DIR/lib"
mkdir -p "$ARTIFACT_DIR/test"

cp build/Release/*.so "$ARTIFACT_DIR/lib/"
cp lib/pysort.py "$ARTIFACT_DIR/lib/"
cp test/test_pysort.py "$ARTIFACT_DIR/test/"

touch "$ARTIFACT_DIR/lib/__init__.py"
touch "$ARTIFACT_DIR/test/__init__.py"

cp scripts/deployed/test-macos.sh "$ARTIFACT_DIR/test.sh"

zip -r "$ARTIFACT" "$ARTIFACT_DIR"

echo "Artifact created: $ARTIFACT"
