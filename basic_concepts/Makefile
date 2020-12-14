.DEFAULT_GOAL: help

help:
	@echo "Usage: "
	@echo ""
	@echo "make pointers - compile pointers.c [executable: pointers]"
	@echo "make clean    - delete all compiled executables"
	@echo "make help     - print help page [this page]"

pointers: pointers.c
	gcc -w pointers.c -o pointers -std=c17

clean:
	@rm -fv pointers
