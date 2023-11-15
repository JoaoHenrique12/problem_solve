#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define PWM_GPIO_PIN 26

#define DIR1 28
#define DIR2 29

// gcc main.c  -lwiringPi -lpthread

/*
 * Example input read from GPIO.
   pinMode(GPIO_PIN, INPUT);
   pullUpDnControl(GPIO_PIN, PUD_DOWN);

  int state = digitalRead(GPIO_PIN);

  printf("GPIO Pin %d state: %s\n", GPIO_PIN, (state == HIGH) ? "HIGH" : "LOW");

 */

int main() {
	if (wiringPiSetup() == -1) {
		fprintf(stderr, "Error initializing WiringPi\n");
		return 1;
	}

	if (softPwmCreate(PWM_GPIO_PIN, 0, 100) != 0) {
		fprintf(stderr, "Error setting up PWM\n");
		return 1;
	}
	pinMode(DIR1, OUTPUT);
	pinMode(DIR2, OUTPUT);

	digitalWrite(DIR1, HIGH);
	digitalWrite(DIR2, LOW);


	printf("PWM is running. Press Ctrl+C to exit.\n");

	while (1) {
		// Increase PWM duty cycle gradually
		for (int i = 0; i <= 100; ++i) {
			softPwmWrite(PWM_GPIO_PIN, i);
			delay(10);
		}

		delay(2000);

		// Decrease PWM duty cycle gradually
		for (int i = 100; i >= 0; --i) {
			softPwmWrite(PWM_GPIO_PIN, i);
			delay(10);
		}

		delay(2000);  // Wait for 1 second
	}

	return 0;
}
