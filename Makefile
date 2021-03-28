CC = gcc
CFLAGS = -g -std=gnu11

test_copy: xs.c test_xc_copy.c
	$(CC) $(CFLAGS) -o $@ $^
	./$@
	@$(RM) $@
