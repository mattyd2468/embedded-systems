#include "Thermometer.h"
#include "LED.h"
#include <Arduino.h>

Thermometer::Thermometer() {
	// do nothing
}

Thermometer::Thermometer(int potPin) {
	this->potPin = potPin;
	pinMode(this->potPin, INPUT);
	this->potVal = 0;

	this->led = new LED(10, 9, 8);
}

int Thermometer::readSensor(int potPin, int potVal) {
	potVal = analogRead(potPin); // read the potentiometer value at the input pin
	return potVal;
}

void Thermometer::setLEDColour(int potVal, LED* led) {

	if (potVal >= 18 && potVal <= 23) { // If the value is between 18 and 23 degrees - GREEN
		led->setColour(0, 255, 0); // green
		led->currentColour = LEDColour::GREEN;
		if (led->colourHasChanged()) {
			Serial.println("Colour has changed to green!");
		}
	} else if (potVal >= 16 && potVal <= 27) { // If the value is between 16 and 27 degrees - YELLOW
		led->setColour(255, 255, 0); // yellow
		led->currentColour = LEDColour::YELLOW;
		if (led->colourHasChanged()) {
			Serial.println("Colour has changed to Amber!");
		}
	} else { // Upper third of potentiometer"s range (682-1023) RED
		led->setColour(255, 0, 0); // red
		led->currentColour = LEDColour::RED;
		if (led->colourHasChanged()) {
			Serial.println("Colour has changed to red!");
		}
	}
}
