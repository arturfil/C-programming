#!/bin/tcsh

if ($#argv != 2) then
  echo -n "Two arguments are needed"
  exit 5
endif

set OGt = $argv[1]
set NEWt = $argv[2]
foreach File (*.$OGt)
  if (-e $File && -r $File && -w $File) then
    set FileNew = `echo $File | sed "s/\.$OGt/\.$NEWt/"`
    mv "$File" "$FileNew"
    echo "$File has been renamed $FileNew\n"
  endif
end
