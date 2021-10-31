#include <stdio.h>
#include <time.h>

void log_error(const char * restrict const fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "[ERROR]: ");
	vfprintf(stderr, fmt, args);
	va_end(args);
}

void log_warning(const char * restrict const fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "[WARNING]: ");
	vfprintf(stderr, fmt, args);
	va_end(args);
}

void log_debug(const char * restrict const fmt, ...)
{
#ifndef DEBUG
	return;
#endif
	struct timespec t;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "[%ld.%03ld][DEBUG]: ", t.tv_sec, t.tv_nsec / 1000000);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

void log_info(const char * restrict const fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	printf("[INFO]: ");
	vprintf(fmt, args);
	va_end(args);
}
