Hello People!

Overview
This project is a simple implementation of an infrared (IR) thermometer using Arduino and the MLX90614 sensor. 
The MLX90614 is a non-contact infrared thermometer sensor that can measure temperature without physically touching the object being measured.
It offers a cost-effective solution for non-contact temperature measurement in various applications, such as industrial, medical, or home automation.


Components:
MLX90614 sensor(Temperature sensor)
Arduino UNO
OLED Display(To display)
Ultrasonic Sensor
Jumper wires
Breadboard

Dependencies:
libraries: Adafruit MLX90614, Adafruit SSD1306, and Adafruit GFX.

How it Works:
The MLX90614 sensor uses infrared radiation emitted by an object to measure its temperature.
The main function of Ultrasonic sensor is to measure the distance between the thermometer and the object as the sensitivity range of the MLX90614 sensor is about 4cm.
If the distance is more than 4cm, the temperature would be displayed in the OLED Display.

