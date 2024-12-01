#include <iostream>
#include <graphics.h>
using namespace std;
int main(){
	int c,r,xc,yc;
	cout<<"Enter the centre coordinates of the circle =  "<<endl;
	cin>>xc>>yc;
	cout<<"Enter radius of the circle = "<<endl;
	cin>>r;
	int x = 0;
	int y = r;
	int p = 1-r;
	int gd = DETECT, gMode;
	initgraph(&gd,&gMode, NULL);
	
	do{
		putpixel(x+xc, y+yc,4);
		putpixel(xc+x, yc-y,4);
		putpixel(xc-x, yc-y,4);
		putpixel(xc+y, yc+x,4);
		putpixel(xc+y, yc-x,4);
		putpixel(xc-x, yc+y,4);
		putpixel(xc-y, yc+x,4);
		putpixel(xc-y, yc-x,4);

		if(p<0){
			x =x+1;
			p = p+2*x+1;
			putpixel(x+xc, y+yc,4);
			
			
		}
		else{
			x = x+1;
			y = y-1;
			p = p+2*x-2*y+1;
			putpixel(x+xc, y+yc, 4);
			
		}
	}while(x<=y);
	delay(10000);
	return 0; 
}
