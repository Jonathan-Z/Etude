#include <stdio.h>
#include <stdlib.h>
#include "MovieData.h"
#ifndef SCREENLEN
#define SCREENLEN 5444
#endif


char* buf;
int i;

int putMovieDataForFrame(int Frame) {
	buf = (char *) malloc(SCREENLEN+1);

	if (buf) {
		for (i=0; ((i <SCREENLEN) && (MOVIE_DATA[i]!='\0')); i++) {
			buf[i] = MOVIE_DATA[i+(SCREENLEN*Frame)];
		}
		buf[i] = '\0';
		puts(buf);
		}
	else {
		fprintf(stderr,"Error: Memory Error");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}