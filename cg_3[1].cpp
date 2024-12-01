#include <iostream>
#include <graphics.h>
using namespace std;
int xmin = 100, ymin = 300, xmax = 500, ymax = 500;
const int Left = 1;
const int Right = 2;
const int Top = 8;
const int Bottom = 4;

int computecode (int x, int y) {
    int code = 0;
    if (x < xmin) code |= Left;
    else if (y < ymin) code |= Bottom;
    if (x > xmax) code |= Right;
    else if (y > ymax) code |= Top;
    return code;
}

void clip (int x0, int x1, int y0, int y1) {
    int code1, code2;
    int accept, flag = 0;
    code1 = computecode(x0, y0);
    code2 = computecode(x1, y1);
    double m = (y1 - y0) / (x1 - x0);
    if ((code1 & code2) != 0) {
        accept = false;
    } else {
        do {
            if (code1 == 0 && code2 == 0) {
                accept = true;
                flag = 1;
            } else {
                int x, y, temp;
                if (code1 == 0) temp = code2;
                else temp=code1;

                if (temp & Top) {
                    x= x0 + (1 / m) * (ymax - y0);
                    y = ymax;
                } else if(temp & Bottom) {
                    x = x0 + (1 / m) * (ymin - y0);
                    y = ymin;
                } else if(temp & Left){
                    y = y0 + m * (xmin - x0);
                    x = xmin;
                } else if(temp & Right) {
                    y = y0 + m * (xmax - x0);
                    x = xmax;
                } 
                if (temp == code1) {
                    x0 = x;
                    y0 = y;
                    code1 = computecode(x0, y0);
                } else {
                    x1 = x;
                    y1 = y;
                    code2 = computecode(x1, y1);
                }
            }
    }while(!flag);// do-while end
    }
    if (accept) {
        cleardevice();
        line(x0, y0, x1, y1);
        rectangle(xmin, ymin, xmax, ymax);
    }
}
int main(){
    int window1 = initwindow(800, 800);
    int x0, x1, y0, y1;
    cout << "Enter the co-ordinate of first point: ";
    cin >> x0 >> y0;
    cout << "Enter the co-ordinate of second point: ";
    cin >> x1 >> y1;
    line(x0, y0, x1, y1);
    rectangle(xmin, ymin, xmax, ymax);
    delay(7000);
    clip(x0, x1, y0, y1);
    system("pause");
    return 0;
}
