#include <bam_free.h>

void bam_free(void **ptrptr)
{
	assert(ptrptr);

	if(*ptrptr)
	{
		free(*ptrptr);
		*ptrptr = NULL;
	}
}

