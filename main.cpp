
### **2. main.cpp**

This is the main program simulating the driving glasses interface. It uses **OpenCV** to display the camera feed and detect basic obstacles (like detecting the color red as a simplified "hazard").

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Initialize the video capture (simulating a camera feed for smart glasses)
    VideoCapture cap(0);  // 0 means the first available camera
    if (!cap.isOpened()) {
        cout << "Error: Could not open camera!" << endl;
        return -1;
    }

    // Create a window to display the camera feed
    namedWindow("Smart Driving Glasses", WINDOW_NORMAL);

    while (true) {
        Mat frame;
        cap >> frame; // Capture frame from the camera

        // If the frame is empty, break the loop
        if (frame.empty()) {
            cout << "Error: Empty frame!" << endl;
            break;
        }

        // Convert to HSV for better color detection
        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // Define the range of red color in HSV space
        Scalar lower_red(0, 120, 70);
        Scalar upper_red(10, 255, 255);
        Mat mask;
        inRange(hsv, lower_red, upper_red, mask);

        // Find contours to detect obstacles (simple hazard detection)
        vector<vector<Point>> contours;
        findContours(mask, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

        // Draw contours and indicate hazard
        if (!contours.empty()) {
            drawContours(frame, contours, -1, Scalar(0, 0, 255), 2); // Red color for hazards
            putText(frame, "Hazard Detected!", Point(10, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2, LINE_AA);
        }

        // Display the processed frame
        imshow("Smart Driving Glasses", frame);

        // Wait for 1ms and check for the escape key to stop the loop
        if (waitKey(1) == 27) {
            break;  // Exit the loop if the user presses 'Esc'
        }
    }

    // Release the camera and close all OpenCV windows
    cap.release();
    destroyAllWindows();
    return 0;
}
