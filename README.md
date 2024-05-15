Hello People!

Overview
This project is a simple implementation of an infrared (IR) thermometer using Arduino and the MLX90614 sensor. 
The MLX90614 is a non-contact infrared thermometer sensor that can measure temperature without physically touching the object being measured


Components:
MLX90614 sensor(Temperature sensor)
Arduino UNO
OLED Display(To display)
Ultrasonic Sensor
Jumper wires
Breadboard

Dependencies:
Adafruit MLX90614 Library

How it Works:
The MLX90614 sensor uses infrared radiation emitted by an object to measure its temperature.
The main function of Ultrasonic sensor is to measure the distance between the thermometer and the object of interest as the sensitivity range of the MLX90614 sensor is about 4cm.
If the distance is more than 4cm, the temperature would be displayed in the OLED Display.
