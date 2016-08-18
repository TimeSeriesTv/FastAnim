#!/usr/bin/env bash

mkdir -p deps
cd deps
  git clone https://github.com/g-truc/glm
  cd glm
    git checkout 0.9.7.5
  cd ..
  git clone https://github.com/MLaszczewski/FastGFX.git
  cd FastGFX
    mkdir -p deps
    cp -R ../glm deps/glm
    ./compile.sh
  cd ..
cd ..
