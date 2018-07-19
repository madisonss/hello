#!/bin/sh
instances="${1:-2}"
loops="${2:-100}"
note="Starting..."
while true; do
    echo "$note"
    i=1
    pids=
    while [ $i -le $instances ]; do
	hello $i $loops &
	pids="$pids $!"
	i=`expr $i + 1`
    done
    wait $pids
    note="Restarting..."
done
