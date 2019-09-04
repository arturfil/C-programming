#!/bin/tcsh

set DIRNAME=/usr/bin
set FILETYPE="shell script"
set LOGFILE=logfile
file "$DIRNAME"/* | fgrep "$FILETYPE" | tee $LOGFILE | wc -l
exit 0

#code will work for #!/bin/tcsh as well as #!/bin/csh (both tcsh and csh)
