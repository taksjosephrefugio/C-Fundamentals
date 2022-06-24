.PHONY := create_outputdir
.DEFAULT_GOAL := simple_threading

clean:
	@rm keyval

simple_threading: threading/simple_threading.c
	$(MAKE) --quiet create_outputdir
	gcc threading/simple_threading.c -o output/simple_threading -std=c17

keyval: key_value.c
	$(MAKE) --quiet create_outputdir
	gcc key_value.c -o keyval -std=c17

create_outputdir:
	@mkdir --parent output

help:
	@echo "Usage: "
	@echo ""
	@echo "make keyval  - compile key_value.c [executable: keyval]"
