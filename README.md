# Smart Driving Glasses 🚗👓

## Project Overview
Smart Driving Glasses is an innovative IoT-based project designed to enhance driver safety by providing real-time alerts about traffic conditions, obstacles, and other critical information using a heads-up display. 

## Features
- Obstacle detection using ultrasonic sensors.
- Traffic sign recognition using OpenCV and image processing.
- Real-time notifications via a heads-up display.
- Low-light assistance with night vision.
- Audio feedback for alerts.

## Technologies Used
- **Hardware**: Raspberry Pi, Ultrasonic Sensors, Cameras, OLED Display.
- **Software**: OpenCV (C++), Python (for additional integration), Arduino IDE.
- **Tools**: C++ Compiler, OpenCV library.

## How It Works
1. The ultrasonic sensor detects obstacles and sends data to the Raspberry Pi.
2. The camera captures images, and OpenCV processes them for traffic sign recognition.
3. The OLED display shows traffic signs, distance alerts, and other notifications.
4. Audio feedback is provided for critical warnings.

## Project Structure
- `Code/`: Contains the source code for the project.
- `Images/`: Includes diagrams and screenshots of the project.
- `Documentation/`: Detailed project report and technical documentation.

## Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Smart_Driving_Glasses.git
