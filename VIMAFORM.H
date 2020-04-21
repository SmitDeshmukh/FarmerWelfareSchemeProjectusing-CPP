#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<constrea.h>
#include<string.h>
struct form1
{

	int income,land,amount,age,area;
	char caste[20],addr[50],bank[50],branch[40],dob[10],nm[50],noc[20];
	int loan;
      //

}*farm_node1,*f21;
void imagev()
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
	outtextxy(50+i,15+i,"Application Form for VIMA");
	}
       setbkcolor(8);
}
void form1v(char farm_id[])
{
cout<<"\n\n\n\n\n\n";
cout<<"Your id is"<<farm_id<<endl;
cout<<"NAME OF BANK: ";
cin>>farm_node1->bank;
cout<<"Branch: ";
cin>>farm_node1->branch;
//gotoxy(0,10);
cout<<"Dear Sir,\nI hereby apply for a loan.\nEnter Amount:                                     :";
cin>>farm_node1->amount;
cout<<"\nFull name of Applicant                            :";
cin>>farm_node1->nm;
cout<<"\nEnter Date of Birth(mm/dd/yy)                     :";
cin>>farm_node1->dob;
cout<<"\nEnter age                                         :";
cin>>farm_node1->age;
cout<<"\nTotal Annual Income                               :";
cin>>farm_node1->income;
cout<<"\nEnter Caste                                       :";
cin>>farm_node1->caste;
cout<<"\nEnter name of crop for vima                       :";
cin>>farm_node1->noc;
cout<<"\nEnter your District Name                          :";
cin>>farm_node1->addr;
cout<<"\nEnter Area of land(in acres)                      :";
cin>>farm_node1->area;

}

void accept_VimaForm(char id[])
{
strcat(id,".dat");
imagev();
form1v(id);
ofstream file2;
file2.open(id,ios::out);
//file2.write((char *)&farm_node1,sizeof(farm_node1));
file2.write((char*)&farm_node1,sizeof(farm_node1));

file2.close();
//cleardevice();
getch();
clearviewport();
//closegraph();
}
void display_VimaForm(char id[])
{
strcat(id,".dat");
imagev();
//itoa(id,idd,20);
ifstream file3(id);
file3.read((char *)&f21,sizeof(f21));
cout<<"\n\n\n\n\n\n";
cout<<"Your id is"<<id<<endl;
cout<<"NAME OF BANK: ";
cout<<f21->bank;
cout<<"Branch: ";
cout<<f21->branch;
//	gotoxy(0,10);
cout<<"Amount for loan                                     :";
cout<<f21->amount;
cout<<"\nFull name of Applicant                            :";
cout<<f21->nm;
cout<<"\nDate of Birth(mm/dd/yy)                           :";
cout<<f21->dob;
cout<<"\nAge                                               :";
cout<<f21->age;
cout<<"\nTotal Annual Income                               :";
cout<<f21->income;
cout<<"\nCaste                                             :";
cout<<f21->caste;
cout<<"\nName of crop                                      :";
cout<<f21->noc;
cout<<"\nDistrict Name Is                                  :";
cout<<f21->addr;
cout<<"\nArea of land(in acres)                            :";
cout<<f21->area;

file3.close();
//cleardevice();
getch();
clearviewport();
//closegraph();
}