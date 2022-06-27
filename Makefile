.PHONY := create_outputdir
.DEFAULT_GOAL := simple_threading

clean:
	@rm keyval

simple_threading: threading/simple_threading.c
	@$(MAKE) --quiet create_outputdir
	gcc -o output/simple_threading -std=c17 -pthread threading/simple_threading.c

keyval: key_value.c
	@$(MAKE) --quiet create_outputdir
	gcc -o keyval -std=c17 key_value.c

scratch: scratch.c
	@$(MAKE) --quiet create_outputdir
	gcc -o output/scratch -std=c17 scratch.c

create_outputdir:
	@mkdir --parent output

help:
	@echo "Usage: "
	@echo ""
	@echo "make keyval  - compile key_value.c [executable: keyval]"
