#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <hello/hello.h>

int
main (int argc, const char *argv[])
{
	unsigned long iteration, iterations;
	const char *label;

	if (argc > 1)
		label = argv[1];
	else
		label = NULL;
	if (argc > 2) {
		errno = 0;
		iterations = strtoul(argv[2], NULL, 0);
		if (errno != 0) {
			fprintf(stderr, "invalid iteration count: %s\n", argv[2]);
			return 1;
		}
	} else
		iterations = 10;

	printf("%s%srunning for %lu iteration%s...\n",
	       (label ? label : ""), (label ? ": " : ""),
	       iterations, (iterations == 1 ? "" : "s"));
	for (iteration = 1; iteration <= iterations; iteration += 1) {
		hello_there(label, iteration);
		fflush(stdout);
		if (iteration < iterations)
			sleep(10);
	}
	return 0;
}
