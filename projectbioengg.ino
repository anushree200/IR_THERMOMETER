#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int trigPin = 10;
const int echoPin = 11;
const int buttonPin = 3;  // the number of the pushbutton pin
const int ledPin = 13; 
int buttonState = 0;

float getdis(void){
  int duration;
  float distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
struct readings{
  float distance;
  float atemp;
  float otemp;
};

struct readings averagevalues(void){
  float avgdis=0,avgatemp=0,avgotemp=0;
  float sumdis=0,sumatemp=0,sumotemp=0;
  digitalWrite(ledPin, HIGH);
  for (int i=0;i<10;i++){
    sumatemp=sumatemp+mlx.readAmbientTempC();
    sumotemp=sumotemp+mlx.readObjectTempC();
    sumdis=sumdis+getdis();
  }
  avgdis=sumdis/10;
  avgatemp=sumatemp/10;
  avgotemp=sumotemp/10;
  readings R;
  R.distance=avgdis;
  R.atemp=avgatemp;
  R.otemp=avgotemp;
  digitalWrite(ledPin, LOW);
  return R;
}

float averagedistance(void){
  float sumdis=0;
  for(int i=0;i<10;i++){
    sumdis=sumdis+getdis();
  }
  return sumdis/10;
}

void displays(struct readings reading){
  float atemp=reading.atemp;
  float otemp=reading.otemp;
  float dis=reading.distance;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25,0);
  display.print("Ambient= ");
  display.print(atemp);
  display.print("\n");
  display.print("    object:");
  display.print(otemp);
  display.print("\n");
  display.print("    distance:");
  display.print(dis);
  display.display();
  delay(3);
}

void setup()   {  
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)// Check your I2C address and enter it here, in Our case address is 0x3C
  display.clearDisplay();
  display.display(); // this command will display all the data which is in buffer
  Serial.begin(9600);
	while (!Serial);

	if (!mlx.begin()) {
		Serial.println("Error connecting to MLX sensor. Check wiring.");
		while (1);
	};
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() { 
  
  while (1){
    buttonState = digitalRead(buttonPin);
    if (buttonState==HIGH){
      break;
    }
  }
  while (1){
    float newdis = averagedistance();
    if (newdis<=4){
      break;
    }
  }
  readings newreadings;
  newreadings=averagevalues();
  displays(newreadings);
  
  


}