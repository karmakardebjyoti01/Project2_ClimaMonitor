#include <dht.h>

#define DHT11_PIN 2 // Define the pin where the DHT11 is connected

dht DHT;

void setup() {
    Serial.begin(9600); // Start the serial communication
    Serial.println("DHT11 Temperature and Humidity Sensor Test");
    delay(1000); // Wait a bit to let the sensor power up
}

void loop() {
    int chk = DHT.read11(DHT11_PIN); // Read data from the sensor

    switch (chk) {
        case DHTLIB_OK:
            Serial.println("DHT11 OK");
            break;
        case DHTLIB_ERROR_CHECKSUM:
            Serial.println("DHT11 Checksum error");
            break;
        case DHTLIB_ERROR_TIMEOUT:
            Serial.println("DHT11 Time out error");
            break;
        default:
            Serial.println("DHT11 Unknown error");
            break;
    }

    // Print the results to the serial monitor
    Serial.print("Humidity (%): ");
    Serial.println(DHT.humidity, 2);

    Serial.print("Temperature (C): ");
    Serial.println(DHT.temperature, 2);

    delay(2000); // Wait 2 seconds before reading again
}
