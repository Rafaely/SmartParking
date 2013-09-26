// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN1  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN2  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE1 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE2 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


const int RedledCar1 = 13;
const int GreledCar1 = 10;
const int RedledCar2 = 4;
const int GreledCar2 = 3;

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2); // NewPing setup of pins and maximum distance.


void setup() {
  pinMode(RedledCar1, OUTPUT); //initialize the LED pin as an output
  pinMode(GreledCar1, OUTPUT); //initialize the LED pin as an output
  pinMode(RedledCar2, OUTPUT); //initialize the LED pin as an output
  pinMode(GreledCar2, OUTPUT); //initialize the LED pin as an output
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  
}

void loop() {
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("PingCAR1: ");
  Serial.print(uS1 / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("CMCAR1: ");
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS2 = sonar2.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("PingCAR2: ");
  Serial.print(uS2 / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("CMCAR2: ");
  
  int analogValue1 = uS1 / US_ROUNDTRIP_CM; //Distance of Car on parking space 1
  
  int analogValue2 = uS2 / US_ROUNDTRIP_CM; //Distance of Car on parking space 2
  
  
  //if or else statements for parking 1
  if(analogValue1 < 25)
  {
    delay(5000);
    digitalWrite(RedledCar1, HIGH);
  }
  else
  {
    digitalWrite(RedledCar1, LOW);
  }
  if(analogValue1 > 26)
  {
    digitalWrite(GreledCar1, HIGH);
  }
  else
  {
    digitalWrite(GreledCar1, LOW);
  }
  
  
  //If or else statements for Parking space 2
    if(analogValue2 < 25)
  {
    delay(5000);
    digitalWrite(RedledCar2, HIGH);
  }
  else
  {
    digitalWrite(RedledCar2, LOW);
  }
  if(analogValue2 > 26)
  {
    digitalWrite(GreledCar2, HIGH);
  }
  else
  {
    digitalWrite(GreledCar2, LOW);
  
}
}

