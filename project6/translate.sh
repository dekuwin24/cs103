#!/bin/bash

f="testfile.cpp"
[[ -n "$1" ]] && f="$1"
cat header.html
./cpp2html < "$f"
cat footer.html
