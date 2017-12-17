#!/bin/bash

# WARNING:
#
#       this script will delete *everything* that is not
#       under version control
#

POSITIONAL=()
CLEAN_ALL=false

while [[ $# -gt 0 ]]; do
    key="$1"

    case $key in
        -a|--all)
            CLEAN_ALL=true
            shift
            ;;
        *)
            POSITIONAL+=("$1")
            shift
            ;;
    esac
done

if [ "$CLEAN_ALL" = true ]; then
    git clean -d -x -f
else
    git clean -d -X -f
fi
