
# make/make test - to compile for testing
# make clean - remove all *.o file
COPTS=-fprofile-arcs -ftest-coverage 
export GTEST_DIR=/u/e/e1601121/googletest/googletest

test:  libgtest.a Gtest_main.o  linked_list.o linked_list_testcase.o 
	g++ -I $(GTEST_DIR)/include -pthread linked_list.o linked_list_testcase.o Gtest_main.o libgtest.a -o mytest.o

Gtest_main.o: Gtest_main.c
	g++ -c -isystem ~/googletest/googletest/include -I~/googletest/googletest Gtest_main.c
linked_list.o: linked_list.c
	g++ -c linked_list.c -o linked_list.o
linked_list_testcase.o: linked_list_testcase.c
	g++ -c -isystem ~/googletest/googletest/include -I~/googletest/googletest linked_list_testcase.c
libgtest.a:
	
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
clean:
	rm -f *.o *.a
