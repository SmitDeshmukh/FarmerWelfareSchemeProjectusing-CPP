#include<iostream.h>
#include<vimaform.h>
#include<mystyle1.h>
#include<scheme.h>
#include<conio.h>
#include<malloc.h>
#include<graphics.h>
#include<string.h>
#include<formfill.h>
#define M (struct node *)malloc(sizeof(struct node));
struct node         //node for account
{
	char name[20];
	int farm_id;
	long double phone_no;
	char pass[20];
	struct node *ne;
}*uni;
class farmerScheme
{

	public:
	       void option();
};


class other
{
	public:
		int countDigit(int);
};
class farmerForm
{
	public:
		void option(int);
		void receipt(char []);

};
class farmer:public farmerScheme,public farmerForm,public other //INHERITANCE
{
	node *start,*tmp,*curr,*tr;
	public:
		farmer()
		{
			start=NULL;
		}
		void create();
		struct node* createac(int);
		int search(int);
		void login();
		void option(int);
		void signup();
};
struct node* farmer::createac(int ch)   //Link list created
{
	char dname[20];
	int dfarm_id,i;
	char dpass[20];
	      clearviewport();
	      settextstyle(5,0,5);
	      for(i=0;i<5;i++)
		{
		delay(30);
		outtextxy(260+i,15,"Signup");
		}
	tmp=M;
	int x,x1=1;
		do
		{
			if(ch==1)
			{
				cout<<"\n\nEnter 4 digit Id";
				cin>>dfarm_id;
			}
			else
			{
				do
				{
					cout<<"\nEnter id to create account";
					cin>>dfarm_id;
					x=search(dfarm_id);
					if(x==1)
					{
						clrscr();
						cout<<"\nRe";
					}
				}while(x==1);
			}
				int c=countDigit(dfarm_id);
				if(c==4)
			{
				x1=0;
				tmp->farm_id=dfarm_id;
			}
			else   //ID CHECK
			{
				clrscr();
				cout<<"Invalid Id"<<endl<<"It should contain 4 digits"<<endl<<"Re";
			}
			}while(x1==1);
			x1=0;

			cout<<"\nEnter username to create new account";
			cin>>tmp->name;
			//strcpy(tmp->name,dname);
			do
			{
				cout<<"\nEnter password";
				cin>>dpass;
				if(strlen(dpass)>=6)
				{
					x1=1;
					strcpy(tmp->pass,dpass);
				}
				else     //Password Check
					cout<<"INvalid Password"<<endl<<"Password should contain atleast 6 character"<<endl<<"Re";
			}while(x1==0);
	       /*	for(i=1;i<=4;i++)
		{
		tmp->pass[i]=getch();
		cout<<"*";
		}*/
			char x2;
			cout<<"Do you have mobile no";
			cin>>x2;
			if(x2=='Y'||x2=='y')
			{
				cout<<"\nEnter your mobile no";
				cin>>tmp->phone_no;
			}
			return tmp;
}
void farmerForm::receipt(char d[])  //Receipt of applying for scheme
{

	  //	clrscr();
       //	clearviewport();
	setbkcolor(5);
	settextstyle(4,0,8);
	setcolor(14);
	for(int i=0;i<2;i++)
	{
	rectangle(30,30+i,580,120+i);
	outtextxy(40+i,20+i,"Congratulations!");
	}
	gotoxy(100,100);
	cout<<"\t\t\n\n\n\n\n\n\n\n\nYour id is: "<<d;
	cout<<"\t\t\n\nYour Form has been Accepted!!";
	cout<<"\n\nYour Form is Submitted to the bank!!";
	cout<<"\n\nYou will be contacted on your contact Details!";
	//getch();

}

void farmerForm::option(int did)  //Form filling
{

	int ch,m;
	char ddid[10],sid[10];
	clrscr();
	clearviewport();
	do
	{   //    clearviewport();
		cout<<"-----------------------------------------------------";
		cout<<"\n1.Peek weema form"<<endl<<"2.Loan Application form"<<endl<<"3.Display & receipt(loan)"<<endl<<"4.Display & receipt(vima)";
		cout<<endl<<"-----------------------------------------------------"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			     //	cout<<"Press any key";
			     cout<<"Enter id:";
			     cin>>ddid;
			     strcpy(sid,ddid);
			     accept_VimaForm(ddid);

			break;

			case 2:
				cout<<"Enter id: ";
				cin>>ddid;
				strcpy(sid,ddid);
				accept_Form(ddid);
			       // return;
			break;

			case 3:
				display_Form(sid);
				clrscr();
				clearviewport();
				receipt(sid);
				break;
			case 4:
			display_VimaForm(sid);
			clrscr();
			clearviewport();
			receipt(sid);
			break;

			default:
				cout<<"Invalid choice";
		}
		cout<<"\nPress 1 to continue Farmer Form Filling";
		cin>>m;
	}while(m==1);

}
int other::countDigit(int c)
{
	int count=0;
	int n;
	while(c!=0)
	{
		c=c/10;
		count++;
	}
	return count;
}
void farmer::option(int did) //Scheme and form menu
{
	int ch,m;
	do
	{

	    clrscr();
		clearviewport();
		cout<<"----------------------------------------------------------"<<endl;
		cout<<endl<<"1.Scheme Dtails"<<endl<<"2.Aply fo scheme"<<endl<<"3.Exit";
		cout<<endl<<"----------------------------------------------------------";
		cout<<endl<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				farmerScheme::option();
			break;

			case 2:
				farmerForm::option(did);
			break;

		case 3:
			endtheme();
			exit(0);
		break;

		default:
			cout<<"Inavlid choice";
	}
	cout<<"Press 1 to continue Farmer Schemes";
	cin>>m;
}while(m==1);
       //	cout<<endl<<"Press any key to continue";
	//getch();
}
int farmer::search(int i) //searching
{
	curr=start;
	int x=0;
	while(curr!=NULL)
	{
		if(curr->farm_id==i)
		{
			uni=curr;
			x=1;
			break;
		}
		curr=curr->ne;
	}
	if(x==1)
		return 1;
	else
		return 0;
}
void farmer::create()  //Account Successful creation
{
	int x;

	if(start==NULL)
	{
		tmp=createac(1);
		start=tmp;
		start->ne=NULL;
		cout<<endl<<"\nAccount created Successfully"<<endl<<"Press Any key";

		getch();

		clrscr();
		clearviewport();
		option(tmp->farm_id);
	}
	else
	{
		//int ch=0;
			tmp=createac(0);
				while(curr->ne!=NULL)
				{
					curr=curr->ne;
				}
				tmp->ne=NULL;
				curr->ne=tmp;
				cout<<"\nAccount created successfully";

				clrscr();
				clearviewport();
				option(tmp->farm_id);

	}
       //	cout<<endl<<"Press any key to continue";
	//getch();
}
void farmerScheme::option() //Scheme Menu
{
	int c,m;
	int sY;

	do
	{     clrscr();
	      clearviewport();
		cout<<"Enter your choice"<<endl;
		cout<<"1.Scheme1 "<<endl<<"\n2.Scheme2 "<<"\n3.Scheme3 ";
		cin>>c;
		switch(c)
		{
			case 1:
				sc1();
				break;

			case 2:
				sc2();break;
			case 3:
				sc3();
				break;


			default:
				cout<<"Invalid choice";
		}
		cout<<"Press 1 to continues with FArmerChemes";
		cin>>m;
	}while(m==1);

       //	cout<<endl<<"Press any key to continue";
	//getch();
}
void farmer::login() //Login Credentials
{

	char dname[20];
	int dfarm_id;
	char dpass[20];
	int x;
	int Y=1;
	do
	{

		cout<<"\nEnter your account id";
		cin>>dfarm_id;
		x=search(dfarm_id);
		if(x==1)
		{
			cout<<"\nEnter your userename";
			cin>>dname;
			if(strcmp(dname,uni->name)==0)
			{
				cout<<"\nEnter your password";
				cin>>dpass;
				if(strcmp(dpass,uni->pass)==0)
				{
					cout<<"\nLogin successfull";
					option(dfarm_id);
					Y=0;
				}
				else
				{
					cout<<"\nInvalid password";
					cout<<"\nRetry Again";
				}
			}
			else
			{
				cout<<"\nInvalid Username";
				cout<<"\nRetry again";
			}
		}
		else
		{
			cout<<"\nInvalid Id";
			cout<<"\nRetry again";
		}
		if(Y==0)
			break;
		else
		{
			cout<<"\nPress 1 to Retry";
			cin>>Y;
		}

	}while(Y==1);
      //	cout<<endl<<"Press any key to continue";
      //	getch();
}


void farmer::signup()
{
	create();
}
void gar()
{
	addTheme();
      clearviewport();
}
int main()
{
	gar();
	int ch,choice;
	clrscr();
	clearviewport();
	farmer F;
	do
	{
	      //	farmer F;
		cout<<"-----------------------------------------------------";
		cout<<endl<<"  1.Sign Up"<<endl<<"  2.Login"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Enter Your Choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			F.signup();
			break;

			case 2:
			F.login();
			break;

			default:
			cout<<"\nInvalid choice";
		}
		cout<<"\n\n  Press 1 to continue";
		cin>>ch;
	}while(ch==1);
	getch();
	closegraph();
	return 0;
}


