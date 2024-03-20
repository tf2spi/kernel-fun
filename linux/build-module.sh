#!/bin/sh

if [ "$1" = "" ] ; then
	echo "Usage: $0 <dir>"
	exit 1
fi

pushd "$1" || exit
make
popd
