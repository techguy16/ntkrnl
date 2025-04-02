#!/usr/bin/env sh

masm=$(realpath $0 | sed 's/masm/ml64/g' | sed 's/sh/exe/g')

# Put backslashes in paths but not switches, make paths absolute (pretty sure Wine uses Z: for the root)
args=""
for i in $*; do
	if [ -e $i ]; then
		args="$args Z:$(realpath $i | sed 's/\//\\/g')"
	else
		args="$args $i"
	fi
done

echo $masm $args
wine $masm $args

