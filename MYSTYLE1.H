#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void addTheme()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	int i;
setcolor(13);
cleardevice();
rectangle(0,0,639,479);
setcolor(12);
rectangle(10,10,629,469);
rectangle(20,20,619,70);
setcolor(11);
settextstyle(10,0,4);
outtextxy(60,5,"******Welcome******");
setcolor(14);
settextstyle(4,0,20);
outtextxy(50,53,"Farmers");
setcolor(14);
settextstyle(4,0,20);
outtextxy(150,170,"Welfare");
settextstyle(12,0,15);
outtextxy(350,443,"Developers:Yogesh Smit Akshay");
outtextxy(350,455,"(B1)");
outtextxy(30,370,"LOADING.......");
for(i=0;i<560;i++)
{
delay(10);
setfillstyle(4,RED);
bar(30+i,380,30,400);
}
//getch();
//closegraph();
}
void endtheme()
{
int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	int i,c;
setcolor(13);
cleardevice();
rectangle(0,0,639,479);
setcolor(12);
rectangle(10,10,629,469);
rectangle(20,20,619,70);
setcolor(11);
settextstyle(10,0,4);
outtextxy(60,5,"Farmers Welfare");
setcolor(14);
settextstyle(4,0,10);
outtextxy(100,60,"END");
setcolor(12);
settextstyle(7,0,7);
outtextxy(200,180,"THANK");
outtextxy(250,250,"YOU!");
settextstyle(12,0,15);
outtextxy(350,443,"Developers:Yogesh Smit Akshay");
outtextxy(350,455,"(B1)");
outtextxy(30,370,"Encourage Farmers for Better INDIA.......press any key");
for(i=0;i<170;i++)
{
setfillstyle(1,12);
bar(30+i,380,30,400);
setfillstyle(1,15);
bar(30+i,400,30,420);
setfillstyle(1,2);
bar(30+i,420,30,440);
}
getch();
clrscr();
clearviewport();
rectangle(0,0,639,479);
setcolor(12);
rectangle(10,10,629,469);
outtextxy(50,100,"RATE US:");
outtextxy(50,120,"How many Stars out of 5: ");
cin>>c;
clrscr();
clearviewport();
for(i=0;i<c;i++)
{
cout<<"* ";
}
cout<<"\nThank you for giving us "<<c<<" stars";

getch();
closegraph();
}