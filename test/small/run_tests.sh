#!/bin/bash
#
EXIT_STATUS=0
for f in test_myvm_*.out
do
  ./$f
  if [ $? -ne 0 ]; then
    EXIT_STATUS=1
  fi
done
exit $EXIT_STATUS