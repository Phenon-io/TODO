# -----------------------------------------------------------------------------
# FILENAME:          Makefile
# DESCRIPTION:       Makefile for a C++ program 
# PURPOSE:           Build a program executable on linux
#
# MODIFICATION HISTORY:
# Author                Date               Version
# ------------------    ----------         ----------------
# Nicholas Whitehorn    2023-02-22         1.0.00     designed for Todo
#-----------------------------------------------------------------------------
#
#
Todo: Todo.o 
	g++ -o  Todo Todo.o Todo.h -std=c++17
Todo.o: Todo.cpp
	g++ -c Todo.cpp 
clean:
	rm *.o
