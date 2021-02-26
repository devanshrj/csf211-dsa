CC = gcc

# compile : main.o readRecords.o insertionSort.o measureTimeAndSpace.o
# 	$(CC) main.o readRecords.o insertionSort.o measureTimeAndSpace.o -o credit_card

# run : compile
# 	./credit_card

# testcompile : test.o readRecords.o insertionSort.o measureTimeAndSpace.o
# 	$(CC) test.o readRecords.o insertionSort.o measureTimeAndSpace.o -o creditcardtest

# main.o : main.c
# 	$(CC) -c main.c

# readRecords.o : readRecords.c readRecords.h
# 	$(CC) -c readRecords.c

# insertionSort.o : insertionSort.c insertionSort.h
# 	$(CC) -c insertionSort.c

# measureTimeAndSpace.o : measureTimeAndSpace.c measureTimeAndSpace.h
# 	$(CC) -c measureTimeAndSpace.c

# test.o : test.c
# 	$(CC) -c test.c

compile : main.c readRecords.c readRecords.h insertionSort.c insertionSort.h measureTimeAndSpace.c measureTimeAndSpace.h
	$(CC) main.c readRecords.c insertionSort.c measureTimeAndSpace.c -o credit_card

run : compile
	./credit_card

test : test.c readRecords.c readRecords.h insertionSort.c insertionSort.h measureTimeAndSpace.c measureTimeAndSpace.h
	$(CC) test.c readRecords.c insertionSort.c measureTimeAndSpace.c -o credit_card_test