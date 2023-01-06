CC=gcc -g -Wall -Wextra
CFILES=$(wildcard src/*/*.c)
HFILES=$(wildcard src/*/include/*.h)
OBJFILES=$(CFILES:.c=.o)
TCFILES=$(wildcard test/*/*.c)
THFILES=$(wildcard test/*/include/*.h)
TOBJFILES=$(TCFILES:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/main

all: $(OBJFILES) $(TOBJFILES)
	$(CC) $(OBJFILES) $(TOBJFILES) -o $(EXEFILE) -lm

%.o: %.c $(HFILES)%.h $(THFILES)%.h
	$(CC) -c $(CFILES) $(TCFILES) $< -o $@ -lm

vim:
	nvim $(CFILES) $(TCFILES)

vimh:
	nvim $(HFILES) $(THFILES)

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

git-update:
	git add Makefile README.md src/ test/

clean:
	rm $(OBJFILES)
	rm $(TOBJFILES)
	rm $(EXEFILE)
