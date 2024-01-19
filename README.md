# AttendRx: Smart Face Recognition-Based Attendance System

<div>
  <img src="https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/assets/61963755/aa1523e2-6486-4004-ac36-441afc5dc426" alt="Image 1" width="400" height="auto"/>
  <img src="https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/assets/61963755/af3a6a49-e795-42bc-b403-711398fd050b" alt="Image 2" width="400" height="auto"/>
</div>

## Overview

AttendRx is an innovative solution designed to modernize and simplify attendance management in educational institutions. Traditional methods of recording attendance are often time-consuming and prone to errors. This project introduces a smart, automated system utilizing face recognition technology to seamlessly track student attendance.

### Key Features

- **Efficient Attendance Tracking:** Automates the attendance process by leveraging ESP32-CAM modules and face recognition.
- **Real-time Feedback:** Provides live updates on the number of students present in the classroom.
- **User-friendly Interface:** Easy integration into educational settings with minimal setup required.

## Code Integration - ESP32-CAM and Face Recognition

The repository includes code segments that facilitate the interaction between the ESP32-CAM module and the face recognition system.

### ESP32-CAM Integration

The ESP32-CAM code, responsible for handling camera functionality and communication with the AttendRx system, is included within the repository under the `ESP32Cam_Code_AttendRx` folder.

- **`AttendRx.ino`**: This file contains the code for the ESP32-CAM module. It manages the camera, establishes communication, and interacts with the AttendRx system.

### Face Recognition Script

The `ESP32Cam.py` Python script, located in the `FaceRecognition_Code_AttendRx` folder, fetches data from the ESP32-CAM module, processes images, and performs face recognition tasks.

### How It Works

0. **Video Preview**

   https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/assets/61963755/10132f15-a69a-4f67-bb51-405e13502336

2. **ESP32-CAM Integration (`AttendRx.ino`)**:
   - The `AttendRx.ino` code initializes the ESP32-CAM module, establishes Wi-Fi connectivity, and sets up the camera.
   - It communicates with the AttendRx system, allowing the system to interact with the ESP32-CAM module for capturing images.

3. **Face Recognition Script (`ESP32Cam.py`)**:
   - The `ESP32Cam.py` Python script fetches data from the ESP32-CAM module by establishing a connection through Wi-Fi.
   - It processes the captured images using face recognition algorithms to identify students' faces.
   - The script interacts with the AttendRx system to manage attendance based on recognized faces.

 4. **Block Diagram**

    ![image](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/assets/61963755/b668ed57-8b8b-4dff-a37b-1783d611961e)

5. **Face Recognition**

     ![image](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/assets/61963755/df4a9869-4b47-4df6-9aeb-eb94e0f60401)

## Project Impact

The integration of the ESP32-CAM module, `AttendRx.ino` code, and the Face Recognition Script into the AttendRx system represents a significant innovation in attendance tracking for educational institutions. It streamlines administrative tasks, enhances security, and contributes to a more efficient and engaging learning environment.

## Repository Details

- **Repository Link:** [AttendRx Face Recognition Attendance System](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System)
- **Demonstration Video:** [AttendRx Video Demo](https://youtu.be/sz25xxF_AVE?si=RQfvERSrklVlNIQV)
- **ESP32-CAM Code:** [ESP32-CAM Integration Code](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/tree/main/ESP32Cam_Code_AttendRx)
  - **AttendRx Code:** [AttendRx.ino](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/blob/main/ESP32Cam_Code_AttendRx/AttendRx.ino)
- **Face Recognition Script:** [Face Recognition Python Script](https://github.com/onkar69483/AttendRx-Face-Recognition-Attendance-System/blob/main/FaceRecognition_Code_AttendRx/ESP32Cam.py)

### Contributors

- **[@onkar69483](https://github.com/onkar69483)** - Onkar Mendhapurkar
- **[@Praneetm1403](https://github.com/Praneetm1403)** - Praneet Mahendrakar
- **[@prabhat4002](https://github.com/prabhat4002)** - Prabhat Shankar
