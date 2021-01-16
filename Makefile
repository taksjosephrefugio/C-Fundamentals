.DEFAULT_GOAL := keyval

clean:
	@rm keyval

keyval: key_value.c
	gcc key_value.c -o keyval -std=c17

help:
	@echo "Usage: "
	@echo ""
	@echo "make keyval  - compile key_value.c [executable: keyval]"
