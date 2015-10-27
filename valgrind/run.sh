FILE=a.out

g++ -ggdb mapcheck_char.cpp

if [ "$#" -ne 1 ]; then
  rm $FILE
fi

#g++ -ggdb mapcheck.cpp
if [ -e $FILE ]
 then
 valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
fi
#valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
