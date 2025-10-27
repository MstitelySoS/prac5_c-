CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -O2

.PHONY: all clean
all: one-dimension-arr two-dimension-arr two-dimension-arr-contig

one-dimension-arr: one-dimension-arr.c
	$(CC) $(CFLAGS) $< -o $@

two-dimension-arr: two-dimension-arr.c
	$(CC) $(CFLAGS) $< -o $@

two-dimension-arr-contig: two-dimension-arr_contiguous.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f one-dimension-arr two-dimension-arr two-dimension-arr-contig
