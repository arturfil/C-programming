#!/bin/tcsh

echo -n "Enter a number: "

set input = $<

if ($input =~ "") then
    echo "ERROR: requires one argument"
    exit
endif

set v = `df | grep sda1 | awk '{print $5}' | cut -c 1-2`

if ($v > $input) then
    echo The sad1 percent useage, $v%, excedes the inputed number
else
    echo The sad percent useage, $v%, does not excede the inputed number
endif
