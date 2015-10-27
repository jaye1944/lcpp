g++ -ggdb mlist.cpp
valgrind -v --tool=memcheck --leak-check=full --log-file=logs/valgrind.log ./a.out
