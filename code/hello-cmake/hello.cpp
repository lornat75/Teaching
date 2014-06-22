#include <stdio.h>

int main()
{
    printf("Hello from cmake!\n");
	
    #ifdef _ENABLE_DEBUG_
	fprintf(stderr, "DEBUG enabled");
	#endif

	return 0;
}