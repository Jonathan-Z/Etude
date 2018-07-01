#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "EtudeInCMaj.h"
#include "MovieData.h"

#ifndef FRAMECOUNTVID
#define FRAMECOUNTVID 410
#endif


#ifndef FRAMETIME
#define FRAMETIME 1000/16
#endif

void *playMusicInThread(void *vargp) {
	playMusic();
	return NULL;
}

int main(int argc, char const *argv[]) {
	if((argc>=2) && ((strcmp(argv[1], "/?")==0)||(strcmp(argv[1], "--help")==0)||(strcmp(argv[1], "-h")==0))){
		printf("Usage: Etude [OPTION]\n\nPlays magikal ASCII video to the melody of Etude In C Major, Op. 176, No. 24 by Jean-Baptiste Duvernoy.\n\n  -h, --help, /?           display this help and exit\n\n  -f                       display a frame counter while the program is running\n\nAuthor: Jonathan Zhou\n");	
		return EXIT_SUCCESS;
	}
	
	int Frame;

	system("cls");

	pthread_t thread_id;
	if(pthread_create(&thread_id, NULL, playMusicInThread, NULL)){
		fprintf(stderr, "ERROR: Error Creating Music Thread\n");
	};

	for (int Frame = 0; Frame < FRAMECOUNTVID; ++Frame)
	{
		if((argc>=2) && (strcmp(argv[1], "-f")==0)) {
			printf("Frame: %d",Frame);	
		}
		if(putMovieDataForFrame(Frame)) {
			fprintf(stderr,"ERROR: Frame Draw Call Error\n");
			return EXIT_FAILURE;
		}
		Sleep(FRAMETIME);
		system("cls");
	}

	 if(pthread_join(thread_id, NULL)) {
	 	fprintf(stderr, "Error Joining Music Thread 1\n");
	 	return EXIT_FAILURE;
		}

	return EXIT_SUCCESS;
}