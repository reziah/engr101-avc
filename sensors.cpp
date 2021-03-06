#include <stdio.h>
#include <time.h>
#include "E101.h"

/*
	- assumes that the main class initialises the RPi.
	- will need to rename sensor pin globals if we use multiple sensors of one type.
		- likely other things will need to change too.
*/

/* Global variables */
int SHORT_RANGE_IR_PIN = 0; // analog pin which the IR sensor is connected to.
int MED_RANGE_IR_PIN = 0;
int PUSH_BUTTON_PIN = 0;

/* Raw readings */

double readShortRangeIR() {
	double value = read_analog(SHORT_RANGE_IR_PIN);
	return value;
}

double readMedRangeIR() {
	double value = read_digital(MED_RANGE_IR_PIN);
	return value;
}

int readPushButton() {
	// assumes a push button is either ON or OFF
	int value = read_digital(PUSH_BUTTON_PIN);
	return value;
}

}

/* Average readings */

double takeAverage(String sensor, int duration = 100, int samples = 20) {
	// Returns the average of _samples_ samples over _duration_ milliseconds
	// for given IR sensor type.
	// String sensor - takes either "ShortRangeIR" or "MedRangeIR"
	// int duration - duration in milliseconds to take samples (Default: 100ms)
	// int samples - number of samples to take an average of (Default: 20 samples)
	
	// TODO: make this work for durations greater than 1000ms (1 second).
	
	double sum = 0;
	int delayBetweenSamples = duration / samples;

	for (int i = 0; i < samples; i++) {
		double value = 0;

		switch(sensor) {
			case 'ShortRangeIR' :
				value = readShortRangeIR();
			case 'MedRangeIR' :
				value = readMedRangeIR();
			default :
				printf("Invalid sensor name given to takeAverage\n");
				break;
		}

		sum += value;
		sleep1(0, delayBetweenSamples * 1000); // sleep1 takes microseconds
	}

	return sum / samples;
}
