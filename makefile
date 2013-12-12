Для Цезаря:

	gcc -c cezar.c -o cezar.o
	gcc -c main_cezar.c -o main_cezar.o
	gcc main_cezar.o cezar.o -o cezar -lm

Для Виженера:

	gcc -c vigenere.c -o vigenere.o
	gcc -c main_vigenere.c -o main_vigenere.o
	gcc main_vigenere.o vigenere.o -o vigenere
