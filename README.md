# Coffeegen
A simple generator of simple CoffeeScript code.

## Dependency

[CoffeeScript](http://coffeescript.org/)

## Introduction

`/dataset`: A random generated example dataset of 9 CoffeeScript files and compiled JavaScript files

`/example` : A CoffeeScript to JavaScript example

`/generator` : The generator in C++

`/processed` : The merger in C++

`run.sh` : Bash script to generate the dataset

`/dataset/compileall.sh` : Bash script to compile all .coffee files to .js files.

## Usage

1. Compile `/generator/gen.cpp`, `/processed/merge.cpp`
2. Modify `run.sh` to set the dataset size and run it
3. `/processed/[train|val|eval]_[input|output].txt` shall be generated as the dataset

---

Authored by [Haobin Ni](https://github.com/FTRobbin) Oct 2016
