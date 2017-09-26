void initialize_top_output_bottom_input() {
	pinMode(15, OUTPUT);
	pinMode(16, OUTPUT);
	pinMode(18, OUTPUT);
	pinMode(19, OUTPUT);
	pinMode(21, OUTPUT);
	pinMode(22, OUTPUT);
	pinMode(23, OUTPUT);
	pinMode(24, OUTPUT);
	pinMode(26, OUTPUT);
	pinMode(29, OUTPUT);
	pinMode(31, OUTPUT);
	pinMode(3, INPUT);
	pinMode(5, INPUT);
	pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
	pullUpDnControl(3, PUD_DOWN);
	pullUpDnControl(5, PUD_DOWN);
	pullUpDnControl(7, PUD_DOWN);
	pullUpDnControl(8, PUD_DOWN);
	pullUpDnControl(10, PUD_DOWN);
	pullUpDnControl(11, PUD_DOWN);
	pullUpDnControl(12, PUD_DOWN);
	pullUpDnControl(13, PUD_DOWN);
}


void initialize_top_input_bottom_output() {
	pinMode(15, INPUT);
	pinMode(16, INPUT);
	pinMode(18, INPUT);
	pinMode(19, INPUT);
	pinMode(21, INPUT);
	pinMode(22, INPUT);
	pinMode(23, INPUT);
	pinMode(24, INPUT);
	pinMode(26, INPUT);
	pinMode(29, INPUT);
	pinMode(31, INPUT);
	pinMode(3, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pullUpDnControl(15, PUD_DOWN);
	pullUpDnControl(16, PUD_DOWN);
	pullUpDnControl(18, PUD_DOWN);
	pullUpDnControl(19, PUD_DOWN);
	pullUpDnControl(21, PUD_DOWN);
	pullUpDnControl(22, PUD_DOWN);
	pullUpDnControl(23, PUD_DOWN);
	pullUpDnControl(24, PUD_DOWN);
	pullUpDnControl(26, PUD_DOWN);
	pullUpDnControl(29, PUD_DOWN);
	pullUpDnControl(31, PUD_DOWN);
}


int dartCheck() {
	initialize_top_output_bottom_input();
	int bottomValue = 0;
	while (bottomValue == 0) {
		if (digitalRead(10)) { //10 and 11 read first in case of single or double bullseye
			if (checkStillHit(10)) {
				bottomValue = 10;
			}
		} else if (digitalRead(11)) {
			if (checkStillHit(11)) {
				bottomValue = 11;
			}
		} else if (digitalRead(3)) {
			if (checkStillHit(3)) {
				bottomValue = 3;
			}
		} else if (digitalRead(5)) {
			if (checkStillHit(5)) {
				bottomValue = 5;
			}
		} else if (digitalRead(7)) {
			if (checkStillHit(7)) {
				bottomValue = 7;
			}
		} else if (digitalRead(8)) {
			if (checkStillHit(8)) {
				bottomValue = 8;
			}
		} else if (digitalRead(12)) {
			if (checkStillHit(12)) {
				bottomValue = 12;
			}
		} else if (digitalRead(13)) {
			if (checkStillHit(13)) {
				bottomValue = 13;
			}
		}
	}
	printf("10 %d\n", digitalRead(10));
	printf("11 %d\n", digitalRead(11));
	printf("3 %d\n", digitalRead(3));
	printf("5 %d\n", digitalRead(5));
	printf("7 %d\n", digitalRead(7));
	printf("8 %d\n", digitalRead(8));
	printf("12 %d\n", digitalRead(12));
	
	initialize_top_input_bottom_output();
	int topValue[] = {0,0};
	
	if (digitalRead(15)){
		topValue[0] = 15;
	}
	if (digitalRead(16)) {
		if (topValue[0] != 0) {
			topValue[1] = 16;
		} else {
			topValue[0] = 16;
		}
	}
	if (digitalRead(18)) {
		if (topValue[0] != 0) {
			topValue[1] = 18;
		} else {
			topValue[0] = 18;
		}
	}
	if (digitalRead(19)) {
		if (topValue[0] != 0) {
			topValue[1] = 19;
		} else {
			topValue[0] = 19;
		}
	}
	if (digitalRead(21)) {
		if (topValue[0] != 0) {
			topValue[1] = 21;
		} else {
			topValue[0] = 21;
		}
	}
	if (digitalRead(22)) {
		if (topValue[0] != 0) {
			return 0; //If 22 is on then bullseye was hit and if topValue of zero is different then two numbers have been hit and there is an incorrect reading
		} else {
			topValue[0] = 22;
		}
	}
	if (digitalRead(23)) {
		if (topValue[0] != 0) {
			topValue[1] = 23;
		} else {
			topValue[0] = 23;
		}
	}
	if (digitalRead(24)) {
		if (topValue[0] != 0) {
			topValue[1] = 24;
		} else {
			topValue[0] = 24;
		}
	}
	if (digitalRead(26)) {
		if (topValue[0] != 0) {
			topValue[1] = 26;
		} else {
			topValue[0] = 26;
		}
	}
	if (digitalRead(29)) {
		if (topValue[0] != 0) {
			topValue[1] = 29;
		} else {
			topValue[0] = 29;
		}
	}
	if (digitalRead(31)) {
		if (topValue[0] != 0) {
			topValue[1] = 31;
		} else {
			topValue[0] = 31;
		}
	}
	if (topValue[0] == 0) {
			return 0;
	} else if (topValue[1] == 0) {
		topValue[1] = topValue[0];
	}
	
	
	
	int numHit = 0;
	if (topValue[0] == 26 && topValue[1] == 29 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 1;
	} else if (topValue[0] == 15 && topValue[1] == 29 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 2;
	} else if (topValue[0] == 16 && topValue[1] == 18 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 3;
	} else if (topValue[0] == 31 && topValue[1] == 31) { // Skipped because repeated twice
		numHit = 4;
	} else if (topValue[0] == 23 && topValue[1] == 24 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 5;
	} else if (topValue[0] == 24 && topValue[1] == 26 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 6;
	} else if (topValue[0] == 19 && topValue[1] == 21 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) { // Because of how board numbering splits
		numHit = 7;
	} else if (topValue[0] == 19 && topValue[1] == 21 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 8;
	} else if (topValue[0] == 15 && topValue[1] == 16 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 9;
	} else if (topValue[0] == 23 && topValue[1] == 24 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 10;
	} else if (topValue[0] == 18 && topValue[1] == 19 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 11;
	} else if (topValue[0] == 15 && topValue[1] == 23 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 12;
	} else if (topValue[0] == 26 && topValue[1] == 31 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 13;
	} else if (topValue[0] == 16 && topValue[1] == 18 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 14;
	} else if (topValue[0] == 23 && topValue[1] == 29 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 15;
	} else if (topValue[0] == 21 && topValue[1] == 21) { // Skipped because repeated twice
		numHit = 16;
	} else if (topValue[0] == 15 && topValue[1] == 16 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 17;
	} else if (topValue[0] == 29 && topValue[1] == 31 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 18;
	} else if (topValue[0] == 18 && topValue[1] == 19 && (bottomValue == 3 || bottomValue == 5 || bottomValue == 7 || bottomValue == 8)) {
		numHit = 19;
	} else if (topValue[0] == 24 && topValue[1] == 26 && (bottomValue == 10 || bottomValue == 11 || bottomValue == 12 || bottomValue == 13)) {
		numHit = 20;
	} else if (topValue[0] == 22 && topValue[1] == 22) {
		numHit = 25;
	}
	return valueCalculator(numHit, bottomValue);
}


int valueCalculator(int numHit, int bottomValue) {
	int multiplier = 0;
	switch(bottomValue) {
		case 3:
			multiplier = 1;
			break;
		case 5:
			multiplier = 3;
			break;
		case 7:
			multiplier = 1;
			break;
		case 8:
			multiplier = 2;
			break;
		case 10:
			if (numHit == 25) {
				multiplier = 2;
			} else {
				multiplier = 1;
			}
			break;
		case 11:
			if (numHit == 25) {
				multiplier = 1;
			} else {
				multiplier = 3;
			}
			break;
		case 12:
			multiplier = 1;
			break;
		case 13:
			multiplier = 2;
			break;
	}
	return (numHit * multiplier);
}

int checkStillHit (int pinNum) {
	//delay(5);
	return digitalRead(pinNum);
}










