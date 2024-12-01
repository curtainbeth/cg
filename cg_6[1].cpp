#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x, y, w = 1;
};

void drawObject(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        line(points[i].x, points[i].y, points[(i + 1) % n].x, points[(i + 1) % n].y);
    }
}

void multiplyMatrix(float trans[3][3], Point &p) {
    float x = p.x, y = p.y, w = p.w;
    p.x = trans[0][0] * x + trans[0][1] * y + trans[0][2] * w;
    p.y = trans[1][0] * x + trans[1][1] * y + trans[1][2] * w;
    p.w = trans[2][0] * x + trans[2][1] * y + trans[2][2] * w;
}

void applyTransformation(Point *points, int n, float trans[3][3]) {
    for (int i = 0; i < n; i++) {
        multiplyMatrix(trans, points[i]);
    }
}

void translationMatrix(float tx, float ty, float trans[3][3]) {
    trans[0][0] = 1; trans[0][1] = 0; trans[0][2] = tx;
    trans[1][0] = 0; trans[1][1] = 1; trans[1][2] = ty;
    trans[2][0] = 0; trans[2][1] = 0; trans[2][2] = 1;
}

void scalingMatrix(float sx, float sy, float trans[3][3]) {
    trans[0][0] = sx; trans[0][1] = 0; trans[0][2] = 0;
    trans[1][0] = 0; trans[1][1] = sy; trans[1][2] = 0;
    trans[2][0] = 0; trans[2][1] = 0; trans[2][2] = 1;
}

void rotationMatrix(float angle, float trans[3][3]) {
    float rad = angle * (3.14159 / 180);
    trans[0][0] = cos(rad); trans[0][1] = -sin(rad); trans[0][2] = 0;
    trans[1][0] = sin(rad); trans[1][1] = cos(rad); trans[1][2] = 0;
    trans[2][0] = 0; trans[2][1] = 0; trans[2][2] = 1;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    Point points[10];
    for (int i = 0; i < n; i++) {
        cout << "Enter vertex " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }

    setcolor(WHITE);
    drawObject(points, n);
    outtextxy(10, 10, "Original Object");

    float trans[3][3] = {0};
    int choice;
    cout << "\n1. Translation\n2. Scaling\n3. Rotation\nChoose transformation: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            float tx, ty;
            cout << "Enter translation factors (tx ty): ";
            cin >> tx >> ty;
            translationMatrix(tx, ty, trans);
            break;
        }
        case 2: {
            float sx, sy;
            cout << "Enter scaling factors (sx sy): ";
            cin >> sx >> sy;
            scalingMatrix(sx, sy, trans);
            break;
        }
        case 3: {
            float angle;
            cout << "Enter rotation angle: ";
            cin >> angle;
            rotationMatrix(angle, trans);
            break;
        }
        default:
            cout << "Invalid choice";
            getch();
            closegraph();
            return 0;
    }

    applyTransformation(points, n, trans);
    cleardevice();
    setcolor(RED);
    drawObject(points, n);
    outtextxy(10, 10, "Transformed Object");

    getch();
    closegraph();
    return 0;
}

