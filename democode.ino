#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_GPS.h>
#include <Servo.h>
#include <SD.h>

#define BMP_I2C_ADDRESS 0x77 // or 76?
#define BNO_I2C_ADDRESS 0x29 // or 28?
#define GPS_I2C_ADDRESS 0x10

// Customize here pulse lengths as needed
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MID_PULSE_LENGTH 1100 // Mid pulse length in µs
#define MAX_PULSE_LENGTH 1200 // Maximum pulse length in µs

// Initialize motor objects
Servo motA;
Servo motB;

// Initialize TVC servo objects
Servo servoA;
Servo servoB;

// Initialize sensor objects
Adafruit_BMP3XX bmp;
Adafruit_BNO055 bno(BNO_I2C_ADDRESS);
Adafruit_GPS gps(&Wire);

char data;      // variable for motor data
int pos = 0;    // variable to store the servo position 

// Pin numbers for Teensy 4.0 according to wiring schematic!
const int CS_SD = 10;
const int MOSI_SD = 11;
const int MISO_SD = 12;
const int SCK_SD = 13;
const int SCL0 = 19;
const int SDA0 = 18;

int i = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting");

  // Initialize the pressure sensor
  if (!bmp.begin_I2C(BMP_I2C_ADDRESS)) {
    Serial.println("Check BMP!");
    while (1);
  }

  // Initialize IMU
  if (!bno.begin()) {
    Serial.println("Check BNO!");
    while (1);
  }

  // Initialize the GPS
  gps.begin(GPS_I2C_ADDRESS);

  servoA.attach(6);  // attaches the servo on pin 6
  servoB.attach(7); // attaches the servo on pin 7

  // //For now DO NOT RUN motor portion with propellers on! Motors fire at max speed during calibration sometimes
  // motA.attach(8, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH); //motor on pin 8
  // motB.attach(9, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH); //motor on pin 9
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read data from BMP390
  bmp.performReading();
  Serial.print("Pressure: ");
  Serial.print(bmp.pressure);
  Serial.println(" Pa");

  // Read data from BNO055
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("Orientation: ");
  Serial.print(event.orientation.x);
  Serial.print(", ");
  Serial.print(event.orientation.y);
  Serial.print(", ");
  Serial.println(event.orientation.z);

  // Read data from PA1010D
  char c = gps.read();
  Serial.write(c);

  // Twitch pitch servo of TVC
  servoA.write(90);
  delay(1000);
  servoA.write(105);
  delay(1000);
  servoA.write(90);
  delay(1000);
  servoA.write(75);
  delay(1000);
  servoA.write(90);
  delay(1000);

  // Twitch yaw servo of TVC
  servoB.write(90);
  delay(1000);
  servoB.write(105);
  delay(1000);
  servoB.write(90);
  delay(1000);
  servoB.write(75);
  delay(1000);
  servoB.write(90);

  //Code to fire up motors (DO NOT RUN! Motors currently have bug that runs at 100% speed at calibration!)
  // motA.writeMicroseconds(MIN_PULSE_LENGTH);
  // motB.writeMicroseconds(MIN_PULSE_LENGTH);
  // motA.writeMicroseconds(MAX_PULSE_LENGTH);
  // motB.writeMicroseconds(MAX_PULSE_LENGTH);
  // delay(4000);
  // motA.writeMicroseconds(MIN_PULSE_LENGTH);
  // motB.writeMicroseconds(MIN_PULSE_LENGTH);

  delay(45000);
}
