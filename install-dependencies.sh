#!/bin/sh

git clone https://github.com/google/googletest.git
cd googletest
cmake .
make && sudo make install

cd ..
git clone https://github.com/PRDeving/Crypto.git
cd Crypto
make && sudo make install
