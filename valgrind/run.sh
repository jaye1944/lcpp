DIR=std::map
FILE=a.out
LOG=valgrind.log
LOGNAME=$DIR'_'$LOG

g++ -ggdb $DIR/mapcheck_char.cpp

if [ "$#" -ne 1 ]; then
  rm $FILE
fi

if [ -e $FILE ]
 then
 valgrind -v --tool=memcheck --leak-check=full --log-file=logs/$LOGNAME ./$FILE
fi
#valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
