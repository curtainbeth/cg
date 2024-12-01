#include <graphics.h>
#include <iostream>

using namespace std;

const int LEFT = 100;
const int RIGHT = 400;
const int BOTTOM = 300;
const int TOP = 100;

struct Point {
    int x, y;
};

Point getIntersection(Point p1, Point p2, int edge, char edgeType) {
    Point intersection;
    float m;

    if (p2.x != p1.x)
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    else
        m = 0;

    if (edgeType == 'l') {
        intersection.x = edge;
        intersection.y = p1.y + m * (edge - p1.x);
    } else if (edgeType == 'r') {
        intersection.x = edge;
        intersection.y = p1.y + m * (edge - p1.x);
    } else if (edgeType == 'b') {
        intersection.y = edge;
        intersection.x = p1.x + (edge - p1.y) / m;
    } else if (edgeType == 't') {
        intersection.y = edge;
        intersection.x = p1.x + (edge - p1.y) / m;
    }

    return intersection;
}

void clip(Point *input, int &n, int edge, char edgeType) {
    Point output[20];
    int count = 0;
    Point s = input[0];

    for (int i = 0; i < n; i++) {
        Point p = input[(i + 1) % n];

        bool insideP = (edgeType == 'l' && p.x >= edge) ||
                       (edgeType == 'r' && p.x <= edge) ||
                       (edgeType == 'b' && p.y <= edge) ||
                       (edgeType == 't' && p.y >= edge);

        bool insideS = (edgeType == 'l' && s.x >= edge) ||
                       (edgeType == 'r' && s.x <= edge) ||
                       (edgeType == 'b' && s.y <= edge) ||
                       (edgeType == 't' && s.y >= edge);

        if (insideP) {
            if (!insideS) {
                output[count++] = getIntersection(s, p, edge, edgeType);
            }
            output[count++] = p;
        } else if (insideS) {
            output[count++] = getIntersection(s, p, edge, edgeType);
        }

        s = p;
    }

    for (int i = 0; i < count; i++) {
        input[i] = output[i];
    }
    n = count;
}

void drawPolygon(Point *poly, int n) {
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Point poly[20];
    for (int i = 0; i < n; i++) {
        cout << "Enter vertex " << i + 1 << " (x y): ";
        cin >> poly[i].x >> poly[i].y;
    }

    setcolor(WHITE);
    drawPolygon(poly, n);
    outtextxy(10, 10, "Original Polygon");

    rectangle(LEFT, TOP, RIGHT, BOTTOM);

    clip(poly, n, LEFT, 'l');
    clip(poly, n, RIGHT, 'r');
    clip(poly, n, TOP, 't');
    clip(poly, n, BOTTOM, 'b');

    setcolor(RED);
    drawPolygon(poly, n);
    outtextxy(10, 50, "Clipped Polygon");

    getch();
    closegraph();
    return 0;
}


