#!/bin/bash
# sudo apt-get install lcov

echo -e "Deleting ....\n"
rm a.out
#rm *.gcov
rm *.gcda
rm *.gcno
#lcov
rm -rf out/
rm coverage.info

sleep 3
echo -e "Compiling with gcov \n"

g++ -fprofile-arcs -ftest-coverage $1
./a.out
gcov $1

sleep 3
echo -e "Running Lcov...\n"
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory out

sleep 2
firefox out/index.html