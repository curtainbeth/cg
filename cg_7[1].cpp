#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

int main() {
    // Initialize graphics window
    int window1 = initwindow(800, 800);

    // Draw initial 3D bar
    bar3d(270, 200, 370, 300, 50, 5);

    int ch;
    cout << "Select Your Choice for 3D Transformation\n";
    cout << "1. Translate\n2. Scale\n3. Rotation along x-axis\n4. Shearing\n";
    cin >> ch;
    cleardevice();

    switch (ch) {
    case 1: { // Translation
        int tx, ty;
        cout << "Enter the translation factor for x, y axis" << endl;
        cin >> tx >> ty;
        bar3d(270 + tx, 200 + ty, 370 + tx, 300 + ty, 50, 5);
        delay(7000);
        cleardevice();
        outtextxy(10, 20, "Parallel projection side view");
        bar3d(0, 200 + ty, 100, 300 + ty, 50, 5);
        delay(7000);
        break;
    }
    case 2: { // Scaling
        int sx, sy;
        cout << "Enter the scaling factor for x, y axis" << endl;
        cin >> sx >> sy;
        bar3d(270 * sx, 200 * sy, 370 * sx, 300 * sy, 50, 5);
        delay(7000);
        cleardevice();
        outtextxy(10, 20, "Parallel projection side view");
        bar3d(0, 200 * sy, 100, 300 * sy, 50, 5);
        delay(7000);
        break;
    }
    case 3: { // Rotation along x-axis
        int ang;
        cout << "Enter the rotation angle (in degrees)" << endl;
        cin >> ang;
        float rad = (ang * 3.14) / 180; // Convert angle to radians
        int x1 = 270;
        int y1 = 200 * cos(rad) - 50 * sin(rad);
        int x2 = 370;
        int y2 = 300 * cos(rad) - 50 * sin(rad);
        bar3d(x1, y1, x2, y2, 50, 5);
        delay(7000);
        break;
    }
    case 4: { // Shearing
        int shx, shy;
        cout << "Enter the shearing factor for x, y axis" << endl;
        cin >> shx >> shy;
        bar3d(270, 200 + (shy * 270), 370, 300 + (shy * 50), 50 + (270 * shx), 5);
        delay(7000);
        break;
    }
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }

    closegraph();
    return 0;
}

