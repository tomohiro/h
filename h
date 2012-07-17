#!/bin/sh

set -e

  display_help() {
    local cmd=$1
    shift

    if ! type $cmd > /dev/null; then
      type $cmd
      return 1
    fi

    local options='--help -h help -help --h'
    for option in $(echo $options); do
      if $cmd $option > /dev/null 2>&1; then
        $cmd $option $@
        return 0
      fi
    done
  }

  usage() {
    echo 'help [cmd]'
  }

if [ -z $1 ]; then
  usage
else
  display_help $@
fi
