#ifndef BAM_TRACE_H
	#define BAM_TRACE_H

	#include <stdio.h>

	#ifdef BAM_DEBUG_VERBOSE
		#define BAM_TRACE(msg) \
			do                 \
			{                  \
				printf(msg);   \
			}while(0)
	#else
		#define BAM_TRACE(msg)
	#endif

#endif

