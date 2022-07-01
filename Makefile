.PHONY := clean create_outputdir
.DEFAULT_GOAL := help

clean:
	@rm -rv output/

simple_threading: threading/simple_threading.c
	@$(MAKE) --quiet create_outputdir
	gcc -o output/simple_threading -std=c17 -pthread threading/simple_threading.c

keyval: key_value.c
	@$(MAKE) --quiet create_outputdir
	gcc -o output/keyval -std=c17 key_value.c

scratch: scratch.c
	@$(MAKE) --quiet create_outputdir
	gcc -o output/scratch -std=c17 scratch.c

create_outputdir:
	@mkdir --parent output

help:
	@echo "Usage: "
	@echo ""
	@echo "make clean               - delete output/ dir and all its contents (all executables)"
	@echo "make scratch             - compile scratch.c"
	@echo "make keyval              - compile key_value.c"
	@echo "make simple_threading    - compile simple_threading.c"
	@echo "make help                - prints this help message"
	@echo
	@echo "Note: Compiled executables are found inside output/ directory"
