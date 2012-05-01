#!/bin/sh
if [ $# -gt 0 ]
then
    PATH=$1
else
    cd ../
    PATH=`pwd`
    cd src/
fi

echo "#!/bin/sh
ROOT=\"${PATH}\"
CC=\"gcc\"
CFLAG=\"-O2\"
BIN=\"\${ROOT}/bin\"
LIB=\"\${ROOT}/lib\"
INCLUDE=\"\${ROOT}/include\"
CLIB=\"-lpthread \`pkg-config --cflags --libs glib-2.0\`\"

if [ \$# -eq 0 ] 
then
    echo "ERROR: missing input file."
    exit 1
elif [ \$# -gt 1 ]
then
    echo "ERROR: more than 1 input files."
    exit 2
fi

NSBLFILE=\"\$1\"
CFILE=\"\${NSBLFILE}.c\"
echo \"\$BIN/n2c.exe \$NSBLFILE\"
\$BIN/n2c.exe \$NSBLFILE
if [ \$? -eq 0 ]
then
    echo \"\$CC \$CFLAG \$CFILE -I\$INCLUDE \$LIB/libnsblgraph.a \$CLIB\"
    \$CC \$CFLAG \$CFILE -I\$INCLUDE \$LIB/libnsblgraph.a \$LIB/libmxml.a \$CLIB
fi
" > nsbl
