DIR=shaired
SOURCE_FILE=$1
FILE=a.out
LOG=valgrind.log
LOGNAME=$DIR'_'$LOG

g++ -std=c++11 -pthread -ggdb $SOURCE_FILE

if [ "$2" == "c" ]; 
then
	if [ "$3" == "r" ]; 
	then
		rm $FILE	
	fi
 	exit
fi

if [ "$2" == "gd" ]; 
then
 	gdb -ex=r $FILE
else
	./$FILE	
fi

if [ "$2" == "r" ]; 
then
 	rm $FILE
elif [ "$3" == "r" ]; 
then
	rm $FILE	
fi

#rm $FILE
#if [ "$#" -ne 1 ]; then
 #echo $#
 #rm $FILE
#fi
#
#if [ -e $FILE ]
# then
# valgrind -v --tool=memcheck --leak-check=full --log-file=logs/$LOGNAME ./$FILE
#fi
#rm $FILE
#valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
