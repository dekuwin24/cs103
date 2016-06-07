#!/bin/bash

./translate.sh testfile.cpp > "./output1.html"
./translate.sh cpp2html.cpp > "./output2.html"

# a few points for something that compiles.
echo @@@ > output
