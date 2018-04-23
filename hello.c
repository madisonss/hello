#include <stdio.h>
#include <unistd.h>

int
main (int argc, void *argv[])
{
	int iteration;
	for (iteration = 1; iteration <= 1000; iteration += 1) {
		printf("Hello, world! [#%d]\n", iteration);
		fflush(stdout);
		sleep(10);
	}
	return 0;
}
