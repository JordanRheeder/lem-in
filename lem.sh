#!/bin/sh
make clean
make re
if  [[ $1 = "-a" ]]; then
    echo "All maps being tested"
    sleep 0
    ./lem-in < maps/CharInteger.map
    echo "Sleeping for 2 seconds"
    sleep 2
    ./lem-in < maps/error-end.map
    echo "Sleeping for 2 seconds"
    sleep 2
    ./lem-in < maps/Integer.map
    echo "Sleeping for 2 seconds"
    sleep 2
    ./lem-in < maps/Medium.map
    echo "Sleeping for 2 seconds"
    sleep 2
    ./lem-in < maps/Standard.map
    echo "Sleeping for 1 second"
    sleep 1
    ./lem-in < maps/test.map
    sleep 1
    ./lem-in < maps/Big.map
    echo "Complete"
elif [[ $1 = "-b" ]]; then
  echo "Big map being tested"
  sleep 1
  ./lem-in < maps/Big.map
else
    ./lem-in < maps/Standard.map
fi
