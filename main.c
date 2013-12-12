#include <msp430.h> 
#include "Sensor/sensors.h"
#include "Robot-Movement/motors.h"
/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initializeSensors();
	setUpTimerA();
	turnLeftSlight();

	for (;;) {
		int left = checkLeftSensor(), center = checkCenterSensor(), right =
				checkRightSensor();

		if (left > 0x240) {
			fullStop();
			turnRightSlight();
			fullStop();

		} else if (center > 0x2FF) {
			fullStop();
			__delay_cycles(10000);
			reverse();
			__delay_cycles(10000);
			fullStop();
			__delay_cycles(10000);
			turnRightSlight();
			__delay_cycles(10000);
			turnRightSlight();
			__delay_cycles(10000);
			fullStop();
		} else {
			turnLeftSlight();

		}

	}
}
