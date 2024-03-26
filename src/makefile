tokenizer: tokenizer.o history.o uimain.o
	gcc -o tokenizer tokenizer.o history.o uimain.o

tokenizer.o: tokenizer.c tokenizer.h

history.o: history.c history.h

uimain.o: uimain.c

run: ./tokenizer

clean: rm -f *.o tokenizer

