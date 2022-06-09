#!/usr/bin/env bash

g++-11 \
  main.cc \
  -std=c++2a \
  -fPIC \
  -fmodules-ts \
  -o \
  out/cpptmp
