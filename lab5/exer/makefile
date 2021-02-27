CC = gcc

compile : main.c readRecords.c readRecords.h insertionSort.c insertionSort.h measureTimeAndSpace.c measureTimeAndSpace.h
	$(CC) main.c readRecords.c insertionSort.c measureTimeAndSpace.c -o credit_card

run : compile
	./credit_card

test : test.c readRecords.c readRecords.h insertionSort.c insertionSort.h measureTimeAndSpace.c measureTimeAndSpace.h
	$(CC) test.c readRecords.c insertionSort.c measureTimeAndSpace.c -o credit_card_test