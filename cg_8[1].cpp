int main(){
int i;
double t,xt,yt;
int window1 = initwindow(800,800);
int ch;
cout<<"Enter the 1 for Bezier Curve and 2 for hermite curve"<<endl;
cin>>ch;
switch(ch){
case 1:{
int x[4]={400,300,400,450};
int y[4]={400,350,275,300};
outtextxy(50,50,"Bezier Curve");
for(t=0;t<=1;t=t+0.0005){
xt = pow(1-t,3)x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)(1-
t)*x[2]+pow(t,3)*x[3];
yt = pow(1-t,3)y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)(1-t)*y[2]+pow(t,3)*y[3];
putpixel (xt, yt,WHITE);}
for (i=0; i<4; i++){
putpixel (x[i], y[i], YELLOW);
delay(4000);}
break;}
case 2:{
int x1[4]={200,100,200,250};
int y1[4]={200,150,75,100};
outtextxy(50,50,"Hermite Curve");
for(t=0;t<=1;t=t+0.00001){
xt=x1[0](2*pow(t,3)-(3*t*t)+1)+x1[1](-2*pow(t,3)+(3*t*t))+x1[2]*(pow(t,3)-
(2*t*t)+t)+x1[3]*(pow(t,3)-(t*t));
yt=y1[0](2*pow(t,3)-(3*t*t)+1)+y1[1](-2*pow(t,3)+(3*t*t))+y1[2]*(pow(t,3)-
(2*t*t)+t)+y1[3]*(pow(t,3)-(t*t));
putpixel (xt, yt,WHITE);}
for (i=0; i<4; i++){
putpixel (x1[i], y1[i], YELLOW);
delay(9000);}
break;}
}
