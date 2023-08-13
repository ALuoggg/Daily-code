
main.out: main.o text.o
	clang -g main.o  text.o -o main.out

main.o: main.c
	clang -c -g main.c -o main.o -Weverything -Werror
text.o: text.c
	clang -c -g text.c -o text.o -Weverything -Werror

clean:
	rm *.o
	rm main.out
