#ifndef BAM_TRACE_H
	#define BAM_TRACE_H

	#include <stdio.h>

	#ifdef BAM_DEBUG_VERBOSE
		#define BAM_TRACE(msg) printf(msg)
	#else
		#define BAM_TRACE(msg)
	#endif

#endif

