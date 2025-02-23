#!/bin/bash

if ! command -v g++ &> /dev/null; then
    echo "\e[31g++ is not installed\e[0m"
    exit 1
fi

g++ compiler.cpp runner.cpp machine.cpp main.cpp compiler.hpp runner.hpp machine.hpp -o build/brainfuck -O3

if [ $? -eq 0 ]; then
    echo -e "\e[32mBuild finished successfully\e[0m"
else
    echo -e "\e[31mError building the program\e[0m"
    exit 1
fi
