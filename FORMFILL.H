#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<constrea.h>
#include<string.h>
struct form
{

	long double income,land,amount,age,area;
	char caste[20],bank[50],branch[40],dob[10],nm[50];
	int loan;
      //

}*farm_node,*f2;
void image()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	int i,inc;
	char a[30];
	setcolor(13);
	cleardevice();
	settextstyle(8,0,3);
	for(i=0;i<5;i++)
	{
	delay(30);
	setcolor(14);
	outtextxy(50+i,15+i,"Application Form for Agriculture Credit");
	}
       setbkcolor(8);
}
void form1(char farm_id[])
{

cout<<"\n\n\n\n\n\n";
cout<<"Your id is"<<farm_id<<endl;
cout<<"NAME OF BANK: ";
cin>>farm_node->bank;
cout<<"Branch: ";
cin>>farm_node->branch;
//gotoxy(0,10);
cout<<"Dear Sir,\nI hereby apply for a loan.\nEnter Amount:                                     :";
cin>>farm_node->amount;
cout<<"\nFull name of Applicant                            :";
cin>>farm_node->nm;
cout<<"\nEnter Date of Birth(mm/dd/yy)                     :";
cin>>farm_node->dob;
cout<<"\nEnter age                                         :";
cin>>farm_node->age;
cout<<"\nTotal Annual Income                               :";
cin>>farm_node->income;
cout<<"\nEnter Caste                                       :";
cin>>farm_node->caste;
cout<<"\nEnter Area of land(in acres)                      :";
cin>>farm_node->area;

}

void accept_Form(char id[])
{
strcat(id,".txt");
image();
form1(id);
ofstream f;
f.open(id,ios::out);
f.write((char *)&farm_node,sizeof(farm_node));
f.close();
//cleardevice();
getch();
clearviewport();
//closegraph();
}
void display_Form(char id[])
{
char abc[80];
strcpy(abc,id);
strcat(id,".txt");
image();
//itoa(id,idd,20);
ifstream f3(id);
if(!f3)
{
	cout<<"SORRY file not found!";
}
else
{
f3.read((char *)&f2,sizeof(f2));
cout<<"\n\n\n\n\n\n";
cout<<"Your id is"<<abc<<endl;
cout<<"NAME OF BANK: ";
cout<<f2->bank;
cout<<"Branch: ";
cout<<f2->branch;
//	gotoxy(0,10);
cout<<"Amount for loan                                     :";
cout<<f2->amount;
cout<<"\nFull name of Applicant                            :";
cout<<f2->nm;
cout<<"\nDate of Birth(mm/dd/yy)                           :";
cout<<f2->dob;
cout<<"\nAge                                               :";
cout<<f2->age;
cout<<"\nTotal Annual Income                               :";
cout<<f2->income;
cout<<"\nCaste                                             :";
cout<<f2->caste;
cout<<"\nArea of land(in acres)                            :";
cout<<f2->area;
}
f3.close();
//cleardevice();
getch();
clearviewport();
//closegraph();
}