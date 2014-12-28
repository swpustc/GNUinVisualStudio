#!/bin/bash
function removeBOM() {
  for file in $(ls $1 -Ap) ; do
    if [ -d $1$file ] ; then
      if [ "$file"x = ".git/"x ] ; then
        echo skip .git/ directory
      elif [ "$file"x = ".git"x ] ; then
        echo skip .git directory
      else
        echo $1$file
        removeBOM $1$file
      fi
    else
      sed -i 's/\x0d/\x0a/g' $1$file
      sed -i '1 s/^\xef\xbb\xbf//' $1$file
      sed -i -e '$a\' $1$file
    fi
  done
}
for arg in "$@" ; do
  if [ "$arg"x = x ] ; then
    echo too few arguments
    exit
  else
    for first in $(ls $arg -dp) ; do
      if [ -d $first ] ; then
        removeBOM $first
      else
        sed -i 's/\x0d/\x0a/g' $first
        sed -i '1 s/^\xef\xbb\xbf//' $first
        sed -i -e '$a\' $first
      fi
    done
  fi
done
