#!/bin/bash

set -eou pipefail # Turn on warnings

IPV4="$1"

ssh -i bjs3118-key-pair-06-02-2021.pem ubuntu@${IPV4}

Sudo apt update 


Sudo apt install g++


cd Information_Processing_Labs

git pull origin

g++ server_a3.cpp -o server 

./server 

