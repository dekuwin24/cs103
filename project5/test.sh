#!/bin/bash
./fsm < testinput.cpp | awk 'NR%2==1 {print "@"} {print $0}' > output
