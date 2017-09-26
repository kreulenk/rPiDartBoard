#include <stdio.h>
#include <wiringPi.h>
#include "dartBoard.h"

int main (void) {
	int scoreHit;
	wiringPiSetupPhys();
	while (1) {
		scoreHit = dartCheck();
		if (scoreHit != 0) {		
			printf("%d\n", scoreHit);
		}
	}
	return 0;
}

