DIR=shaired
SOURCE_FILE=shaired.cpp
FILE=a.out
LOG=valgrind.log
LOGNAME=$DIR'_'$LOG

g++ -std=c++11  -ggdb $DIR/$SOURCE_FILE

#if [ "$#" -ne 1 ]; then
 # rm $FILE
#fi

if [ -e $FILE ]
 then
 valgrind -v --tool=memcheck --leak-check=full --log-file=logs/$LOGNAME ./$FILE
fi
rm $FILE
#valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
