#!/bin/bash
cd `dirname $0`
echo "`git show sources --summary | grep commit | awk '{print \$2}'`" >../.git/MERGE_HEAD
echo "no-ff" >../.git/MERGE_MODE
