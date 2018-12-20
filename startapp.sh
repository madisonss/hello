#!/bin/sh
id
tinymix controls
env
instances="${1:-2}"
loops="${2:-10}"
note="Starting..."
#while true; do
    logger -p local0.notice -t hello "$note"
    i=1
    pids=
    while [ $i -le $instances ]; do
	hello $i $loops &
	pids="$pids $!"
	i=`expr $i + 1`
    done
    wait $pids
    exit 69
#    note="Restarting..."
#done
