#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>
class menu
{
	private :
		void new_records(void) ;
		void report(void) ;
		void roomf(void) ;
		void customerf(void) ;

	public :
		void main_scrn() ;
		void login(void) ;

} ;



class room
{
	private :
		int recordno(int) ;
		void display_record(int) ;
		int roomno ;
		char roomcode[5] , status ;
		float tariff ;
	public :
		void add (void) ;
		void modify(void) ;
		void deletion(void) ;
		void display_room_record(int) ;
		void display_list(void) ;
		int room_found( int ) ;
		void change_status(int,char) ;
		char room_status(int);
} ;




class customer
{
	private :
		int recordno(int) ;
		void display_record(int) ;
		void delete_record(int) ;
		int roomno ;
		char name[21] , phone[8] ;
		float advance , misc , room_srv ;
	public :
		void add (void) ;
		void modify(void) ;
		void deletion(void) ;
		void display_list(void) ;
		void display_customer_record(int) ;

} ;

void menu :: login()    //Password Function
{
 int i=0,count=0;
 char str[10],ch;
 do
 {
  int z;
  textattr(2);
  clrscr();
  gotoxy(25,14);
  cout<<"Enter Password:";
  str[i]=getch();
   cout<<"*";
  while(str[i]!=13)
  {
   ch=getch();
   if(ch==8)
   {
    cout<<"\b \b";
    --i;
   }
   else
   {
    str[++i]=ch;
    cout<<"*";
   }
  }
  textcolor(RED);
   gotoxy(25,17);
   cprintf("Checking");
   cprintf(".");
   delay(400);
   cprintf(".");
   delay(400);
   cprintf(".");
   delay(400);
   delay(700);
  gotoxy(25,17); clreol();
  delay(400);
  textcolor(RED);
  cprintf("Checked..!!");
   delay(400);
  str[i]='\0';
  if(strcmp("123456",str)==0)
  {
   gotoxy(25,20);
   textcolor(GREEN + BLINK);
   cout<<"Password Accepted..!!";
   getch();
   break;
  }
  else
  {
   delay(400);
   textattr(132);
   gotoxy(30,20);
   cprintf("Incorrect Password..Try Again..!!\a\a");
   gotoxy(25,22);
   cout<<2-count<<" chances left..!!";
   textcolor(RED + BLINK);
   if(count==2)
   {
    gotoxy(25,24);
    cprintf("Breaking Off !!");
    getch();
    exit(0);
   }
  getch();
 }
 count++;
 i=0;
 if(count==3)
 exit(0);
 }while(count!=3);
}

void menu :: main_scrn()        //Starting Screen Function
{
 int c=0;
 char q[52],ch;int cho;
  textmode(C40);
   delay(10);
  textcolor(c++);
	clrscr();
	textmode(C40);
	textcolor(c++ + BLINK);
	gotoxy(9,1);
	 cprintf("WELCOME TO STARKS HOTEL");
	 getch();
	int z=7,w=8;
	getch();
	 gotoxy(10,4);
	 textcolor(z);
	cprintf("1");
	  delay(50);
	cprintf(".");
	  delay(50);
	cprintf(")");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("E");
	  delay(50);
	cprintf("d");
	  delay(50);
	cprintf("i");
	  delay(50);
	cprintf("t");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("R");
	  delay(50);
	cprintf("e");
	  delay(50);
	cprintf("c");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("r");
	  delay(50);
	cprintf("d");
	  delay(50);
	cprintf("s");
	  delay(50);
       gotoxy(10,7) ;
       textcolor(w);
	cprintf("2");
	  delay(50);
	cprintf(".");
	  delay(50);
	cprintf(")");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("D");
	  delay(50);
	cprintf("i");
	  delay(50);
	cprintf("s");
	  delay(50);
	cprintf("p");
	  delay(50);
	cprintf("l");
	  delay(50);
	cprintf("a");
	  delay(50);
	cprintf("y");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("R");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("m");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("R");
	  delay(50);
	cprintf("e");
	  delay(50);
	cprintf("c");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("r");
	  delay(50);
	cprintf("d");
       gotoxy(10,10) ;
       textcolor(z);
	cprintf("3");
	  delay(50);
	cprintf(".");
	  delay(50);
	cprintf(")");
	 delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("D");
	  delay(50);
	cprintf("i");
	  delay(50);
		cprintf("s");
	  delay(50);
	cprintf("p");
	  delay(50);
	cprintf("l");
	  delay(50);
	cprintf("a");
	  delay(50);
	cprintf("y");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("C");
	  delay(50);
	cprintf("u");
	  delay(50);
	cprintf("s");
	  delay(50);
	cprintf("t");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("m");
	  delay(50);
	cprintf("e");
	  delay(50);
	cprintf("r");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("R");
	  delay(50);
	cprintf("e");
	  delay(50);
	cprintf("c");
	  delay(50);
	cprintf("o");
	  delay(50);
	cprintf("r");
	  delay(50);
	cprintf("d");
       gotoxy(10,13) ;
       textcolor(w);
	cprintf("4");
	  delay(50);
	cprintf(".");
	  delay(50);
	cprintf(")");
	  delay(50);
	cprintf(" ");
	  delay(50);
	cprintf("E");
		  delay(50);
	cprintf("x");
	  delay(50);
	cprintf("i");
	  delay(50);
	cprintf("t");
       textcolor(z);
	  gotoxy(10,17) ;
	cprintf("Enter your choice : ") ;
	 cin>>cho;
      if(cho==3)
      {
       char ans;
       do
       {
	int l;
	clrscr();
	cout<<"Enter the Room No of Customer to be Displayed:-";
	 cin>>l;
	customer c ;
	c.display_customer_record(l) ;
	cout<<"\n Do you wish to see more records(y/n):-";
	 cin>>ans;
       }while(ans=='Y' || ans=='y');
       main_scrn();
      }
      else
       if(cho==2)
       {
	char ans1;
	do
	{
	 clrscr();
	 int m;
	 textmode(MONO);
	 cout<<"Enter Room No Whose Info is to be Displayed:-";
	  cin>>m;
	 room r ;
	 r.display_room_record(m) ;
	 cout<<"\n\n Do u Wish to See More Records(y/n):-";
	  cin>>ans1;
	}while(ans1=='Y' || ans1=='y');
	main_scrn();
       }
      else
       if(cho==1)
	 new_records() ;
      else
       if(cho==4)
       {
	clrscr();
	gotoxy(7,10);
	cout<<" Thanks For Coming..!! ";
	getch();
	gotoxy(4,12);
	cout<<" Visit Again..!!Have a Nice Day " ;
	getch();
	exit(0);
       }
}

void menu :: new_records()
{
 int ch ;
 while(ch!=3)
 {
  clrscr() ;
  textmode(C80);
    gotoxy(30,8) ;
  cprintf("1. Add New Room Records") ;
    gotoxy(30,10) ;
   cprintf("2. Customer Records") ;
    gotoxy(30,12) ;
   cprintf("3. Back") ;
    gotoxy(30,14) ;
   cprintf("Enter your choice : ") ;
    cin>>ch;
    if(ch == 1)
       roomf() ;
    else if(ch == 2)
       customerf() ;
    else if(ch == 3)
       main_scrn();
 }
}

void menu :: roomf(void)
{
  int ch ;
     while(1)
     {
	 clrscr() ;
	 textmode(C80);
	 gotoxy(30,8) ;
	 cout<<"1. Add New Room" ;
	  gotoxy(30,10) ;
	 cout<<"2. Modify Room Record" ;
	  gotoxy(30,12) ;
	 cout<<"3. Delete Room Record" ;
	  gotoxy(30,14) ;
	 cout<<"4. Back" ;
	  gotoxy(30,16) ;
	 cprintf("Enter your choice : ") ;
	  cin>>ch;
	if(ch == 1)
	{
	 clrscr();
	 room r;
	 r.add();
	}
	else if(ch == 2)
	{
	 room r ;
	 r.modify();
	}
	else if(ch == 3)
	{
	 room r ;
	 r.deletion();
	}
	else if(ch == 4)
	 break;
     }
}

void menu :: customerf(void)
{
     int ch ;
	   while(ch!=4)
	   {
		clrscr() ;
		textmode(C80);
		 gotoxy(30,8) ;
		cout<<"1. New Customer Record" ;
		 gotoxy(30,10) ;
		cout<<"2. Modify Customer Record" ;
		 gotoxy(30,12) ;
		cout<<"3. Delete Customer Record";
		 gotoxy(30,14) ;
		cout<<"4. Back" ;
		 gotoxy(30,16) ;
		cout<<"Enter your choice : " ;
		 cin>>ch;
		getch() ;
		if ( ch == 1 )
		{
			customer c ;
			c.add() ;
		}
		else
		if ( ch == 2 )
		{
			customer c ;
			c.modify() ;
		}
		if(ch== 4 )
		{
		break;
		}

	   }
}
void room :: add ()
{
   char ch ;
      char x;int valid = 0 ,flag;
      char t_rcode[5] ;
      int t_roomno ;
      char t_status ;
      float t_tariff ;
      do
      {
	fstream fin;
	fin.open("add.dat", ios::out | ios::app ) ;
	clrscr() ;
	clrscr();
	char c=4;
	  textcolor(c++ + BLINK);
	  textmode(MONO);
	  {
	   gotoxy(28,1);
	   cprintf("PRE-REQUISITE KNOWLEDGE");
	  }
	      textcolor(WHITE);
	      gotoxy(14,3);
	    cprintf("1.) Enter The Room Code as:-SS / DSS / DSD / PS where\n") ;
	      gotoxy(20,5) ;
	    cprintf("SS  : SINGLE SUITE") ;
	      gotoxy(20,7) ;
	    cprintf("DSS : DELUXE SUITE (Single Bed) ") ;
	      gotoxy(20,9) ;
	    cprintf("DSD : DELUXE SUITE (Double Bed) ") ;
	      gotoxy(20,11) ;
	    cprintf("PS  : PRESIDENTIAL SUITE") ;
	      gotoxy(14,13);
	    cprintf("2.) Enter The Room Status As:-\n");
	      gotoxy(20,15);
	    cprintf("O   :  OCCUPIED ROOM STATUS");
	       gotoxy(20,17);
	    cprintf("V   :  VACANT ROOM STATUS");
	       gotoxy(14,19);
	    cprintf("3.) Enter The Room No Between 1 To 100");
	    getch();
	    clrscr();
	    l1:
	    gotoxy(26,1);
	    textcolor(3);
	    cprintf("Enter Information For Room Booking");
	    gotoxy(1,2);
	    textcolor(WHITE);
	    cout<<"Code    :";
	     gets(t_rcode);
	    do
	    {
		valid = 1 ;
		int flag=0;
		char string[3],string1[3],string2[3],string3[3],string4[3],string5[3],string6[3],string7[3];
		strcpy(string ,"SS");
		strcpy(string1,"DSS");
		strcpy(string2,"DSD");
		strcpy(string3,"PS ");
		strcpy(string4,"ss");
		strcpy(string5,"dss");
		strcpy(string6,"dsd");
		strcpy(string7,"ps");
		if(strcmp(t_rcode,string)==0 || strcmp(t_rcode,string1)==0 || strcmp(t_rcode,string2)==0 || strcmp(t_rcode,string3)==0 || strcmp(t_rcode,string4)==0 || strcmp(t_rcode,string5)==0 || strcmp(t_rcode,string6)==0 || strcmp(t_rcode,string7)==0)
		{
		 flag=0;
		 break;
		}
		else
		 flag=1;
		if(flag==1)
		{
		 valid = 0 ;
		 cout<<"INVALID CODE" ;
		 cout<<"\nPress any key to continue..." ;
		 getch();
		 clrscr();
		 goto l1;
		}
	    }while(valid==0);
	    l2:
	    gotoxy(1,3);
	    cout<<"\nRoom No :";
	     cin>>t_roomno;
	    do
	    {
		valid = 1 ;
		if( t_roomno <= 0 || t_roomno > 100 )
		{
		 valid = 0 ;
		 cout<<"\n ROOM NO SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 100" ;
		 cout<<"\n Press any key to continue..." ;
		 getch() ;
		}
		if(room_found(t_roomno))
		{
		  valid = 0 ;
		  cout<<"\nROOM NO. ALREADY EXIST" ;
		  cout<<"\n Press any key to continue..." ;
		  getch() ;
		  for ( int i=4; i<=8; i++ )
		  {
		   gotoxy(1,i) ;	clreol() ;
		  }
		  goto l2;
		 }
	} while (valid==0) ;
	   cout<<"\nStatus  :";
	     cin>>t_status;
	do
	{
		valid = 1 ;
		t_status = toupper(t_status) ;
		if (t_status != 'O' && t_status != 'V')
		{
			valid = 0 ;
			cout<<"\nINVALID DATA ENTERED" ;
			cout<<"\n Press any key to continue..." ;
			getch() ;
		}
	} while ( valid!=1 ) ;
	cout<<"\nEnter Tariff :";
	   cin>>t_tariff;
	do
	{
		valid = 1 ;
		if ( t_tariff <= 0 )
		{
			valid = 0 ;
			cout<<"\nIT SHOULD NOT BE NEGATIVE OR ZERO" ;
			cout<<"\n Press any key to continue..." ;
			getch() ;
		}
	} while ( valid!=1 ) ;
	gotoxy(1,9) ;
	cout<<"\n Do you want to save the record (y/n):" ;
	 cin>>ch;
	do
	{
		valid = 1 ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		   valid = 0 ;
	 } while ( valid!=1 ) ;
	if (ch == 'Y')
	{
		strcpy(roomcode,t_rcode) ;
		roomno  = t_roomno  ;
		status  = t_status  ;
		tariff = t_tariff ;
		fin.write((char *) this, sizeof(room)) ;
	}
	gotoxy(1,9) ;
	cout<<"\nDo you want to add more records (y/n) :  " ;
	 cin>>ch;
	do
	{
		valid = 1 ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
			valid = 0 ;
	} while ( valid!=1 ) ;
	fin.close () ;
      } while ( ch == 'Y') ;
}
void room :: modify(void)
{
	clrscr() ;
	int valid ,result ;
	char ch ;
	char t_rcode[5] ;
	int t_roomno , tr ;
	char t_status ;
	float t_tariff ;


	gotoxy(1,3) ;
	cout<<"Enter the Room no. to be modified " ;
	cin>>tr ;
	getch();
	if ( room_found( tr )!=1 )
	{
		cout<<"ROOM NO. NOT FOUND" ;
		cout<<"\n Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(tr) ;
	gotoxy(1,10) ;
	cout<<"Do you want to modify this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,10) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,9) ;	clreol() ;
		}
	} while ( valid!=1 ) ;
	if (ch == 'N')
		return ;
	gotoxy(1,12) ;
	cout<<"ENTER THE NEW DATA FOR THE ROOM" ;
	l1:
	gotoxy(1,14) ;
	textcolor(WHITE);
	    cout<<"Code    :";
	     gets(t_rcode);
	    do
	    {
		valid = 1 ;
		char string[3],string1[3],string2[3],string3[3],string4[3],string5[3],string6[3],string7[3];
		strcpy(string ,"SS");
		strcpy(string1,"DSS");
		strcpy(string2,"DSD");
		strcpy(string3,"PS ");
		strcpy(string4,"ss");
		strcpy(string5,"dss");
		strcpy(string6,"dsd");
		strcpy(string7,"ps");
		if(strcmp(t_rcode,string)==0 || strcmp(t_rcode,string1)==0 || strcmp(t_rcode,string2)==0 || strcmp(t_rcode,string3)==0 || strcmp(t_rcode,string4)==0 || strcmp(t_rcode,string5)==0 || strcmp(t_rcode,string6)==0 || strcmp(t_rcode,string7)==0)
		  result=0;
		else
		  result=1;
		if (result==1)
		{
		 valid = 0 ;
		 cout<<"INVALID CODE" ;
		 cout<<"\nPress any key to continue..." ;
		 getch();
		 goto l1;
		}
	     }while(valid==0);
	     l2:
	     gotoxy(1,14);
	    cout<<"\nRoom No :";
	     cin>>t_roomno;
	    do
	    {
		valid = 1 ;
		if( t_roomno <= 0 || t_roomno > 100 )
		{
		 valid = 0 ;
		 cout<<"\n ROOM NO SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 100" ;
		 cout<<"\n Press any key to continue..." ;
		 getch() ;
		}
		if(room_found(t_roomno))
		{
		  valid = 0 ;
		  cout<<"\nROOM NO. ALREADY EXIST" ;
		  cout<<"\n Press any key to continue..." ;
		  getch() ;
		  for ( int i=15; i<=20; i++ )
		  {
		   gotoxy(1,i) ;	clreol() ;
		  }
		  goto l2;
		 }
	} while (valid==0) ;
	gotoxy(1,16) ;
	cout<<"Status  :" ;
	 cin>>t_status;
	  do
	  {
		valid = 1 ;
		t_status = toupper(t_status) ;
		if (t_status != 'O' && t_status != 'V')
		{
			valid = 0 ;
			cout<<"\nINVALID DATA ENTERED" ;
			cout<<"\n Press any key to continue..." ;
			getch() ;
		}
	   } while ( valid!=1 ) ;
	 gotoxy(1,17) ;
	cout<<"Tariff  :" ;
	 cin>>t_tariff;
	do
	{
		valid = 1 ;
		if ( t_tariff <= 0 )
		{
			valid = 0 ;
			cout<<"\nIT SHOULD NOT BE NEGATIVE OR ZERO" ;
			cout<<"\n Press any key to continue..." ;
			getch() ;
		}
	} while ( valid!=1 ) ;
	gotoxy(1,18) ;
	cout<<"\n Do you want to save the record (y/n)  :  " ;
	cin>>ch;
	if (ch == 'Y')
	{
	 fstream file ;
	file.open("ROOM.dat", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(room)) ;

		if ( roomno == tr )
		{
		strcpy(roomcode,t_rcode);
		   roomno=t_roomno;
		   status=t_status;
		   tariff=t_tariff;

			temp.write((char *) this, sizeof(room)) ;
		     }
		     else
		     {
		     temp.write((char *) this,sizeof(room));
		     }
		     }
	file.close() ;
	temp.close() ;
	file.open("ROOM.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(room)) ;

		file.write((char *) this, sizeof(room)) ;
	}
	file.close() ;
	temp.close() ;
	remove("temp.dat");
}
}
void room :: deletion(void)
{
	clrscr() ;
	int valid ;
	char ch ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. to be deleted " ;
	cin>>t_roomno ;
	if ( !room_found( t_roomno ) )
	{
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(t_roomno) ;
	gotoxy(1,10) ;
	cout<<"Do you want to delete this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,10) ;
		cin>>ch ;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,9) ;	clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;

	 fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(room)) ;

		if ( roomno == t_roomno )
		{
		     }
		     else
		     {
		     temp.write((char *) this,sizeof(room));
		     }
		     }
	file.close() ;
	temp.close() ;
	file.open("ROOM.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(room)) ;

		file.write((char *) this, sizeof(room)) ;
	}
	file.close() ;
	temp.close() ;
	remove("temp.dat");
}

int room :: room_found ( int t_roomno )    //Function To Search A Room By Room No
{
	fstream fin ;
	fin.open("add.dat", ios::in) ;
	fin.seekg(0) ;
	int found = 0 ;
	while (fin.read((char *) this, sizeof(room)))
	{
		if ( roomno == t_roomno )
			found = 1 ;
	}
	fin.close() ;
	return found ;
}

void room :: display_record(int t_roomno)    //Function to display Details of the room found
{
	fstream fin ;
	fin.open("add.dat", ios::in) ;
	fin.seekg(0) ;
	int found = 0 ;
	while (fin.read((char *) this, sizeof(room)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room code : " <<roomcode ;
			gotoxy(1,6) ;
			cout<<"Room no.  : " <<roomno ;
			gotoxy(1,7) ;
			cout<<"Status    : " <<status ;
			gotoxy(1,8) ;
			cout<<"Tariff    : " <<tariff ;
		}
	}
	fin.close () ;
}

void room :: display_room_record(int t_roomno)
{
	fstream fin ;
	fin.open("add.dat", ios::in) ;
	fin.seekg(0) ;
	int found = 0 ;
	while (fin.read((char *) this, sizeof(room)) && !found)
		{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room code : " <<roomcode ;
			gotoxy(1,6) ;
			cout<<"Room no.  : " <<roomno ;
			gotoxy(1,7) ;
			cout<<"Status    : " <<status ;
			gotoxy(1,8) ;
			cout<<"Tariff    : " <<tariff ;
		}
	}
	fin.close () ;
}


void customer :: add(void)
{
	room r ;
	menu m1;
	char ch ;
	int valid = 1 ;
	int   t_roomno , t_no_cust ;
	char  t_name[21] , t_address[35] , t_phone[8] , t_nation[16] ;
	float t_advance , t_misc , t_room_srv ;
	clrscr() ;
	gotoxy(1,1) ;
	cout<<"Enter the details of the Customer" ;
	gotoxy(1,3) ;
	cout<<"Room no.         : " ;
	gotoxy(1,4) ;
	cout<<"Name             : " ;
	gotoxy(1,5) ;
	cout<<"No. of guests    : " ;
	gotoxy(1,6) ;
	cout<<"Address          : " ;
	gotoxy(1,7) ;
	cout<<"Phone            : " ;
	gotoxy(1,8) ;
	cout<<"Nationality      : " ;
	gotoxy(1,11) ;
	cout<<"Advance          : " ;
	gotoxy(1,12) ;
	cout<<"Miscellineous    : " ;
	gotoxy(1,13) ;
	cout<<"Room service     : " ;
	char t_status;
	do
	{
	valid=1;
	gotoxy(20,3) ;
	cin>>t_roomno ;

	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'O')
	   {
		valid=0;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR NOT VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,3) ;	clreol() ;
	   }
	}while(!valid);
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NAME OF THE CUSTOMER" ;
		gotoxy(20,4) ;
		gets(t_name) ;
		if ((strlen(t_name) <= 0) || (strlen(t_name) > 20))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 20" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,4) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NO. OF GUESTS WITH THE CUSTOMER" ;
		gotoxy(20,5) ;
		cin>>t_no_cust ;
		if ((t_no_cust < 0) || (t_no_cust > 4))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"GUESTS SHOULD NOT BE LESS THAN 0 OR GREATER THAN 4" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,5) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADDRESS OF THE CUSTOMER" ;
		gotoxy(20,6) ;
		gets(t_address) ;

		if ((strlen(t_address) <= 0) || (strlen(t_address) > 50))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 50" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,6) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE PHONE NO. OF THE CUSTOMER, ENTER '-' FOR NO PHONE NO." ;
		gotoxy(20,7) ;
		cin>>t_phone ;
		if ((strlen(t_phone) < 8 && strlen(t_phone) > 1) || (strlen(t_phone) > 8))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN 8 OR GREATER THAN 8" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,7) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER NATIONALITY OF THE CUSTOMER" ;
		gotoxy(20,8) ;
		gets(t_nation) ;

		if ((strlen(t_nation) <= 0) || (strlen(t_nation) > 15))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN ZERO OR GREATER THAN 15" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,8) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADVANCE IN RS. " ;
		gotoxy(20,11) ;
		cin>>t_advance ;
		if (t_advance < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT BE LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,11) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE MISCELLENIOUS CHARGES" ;
		gotoxy(20,12) ;
		cin>>t_misc ;
		if (t_misc < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM SERVICE CHARGES" ;
		gotoxy(20,13) ;
		cin>>t_room_srv ;
		getch();
		if (t_room_srv < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,13) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,15) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,15) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
		   valid = 0 ;
		   gotoxy(42,15) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		r.change_status(t_roomno,'O') ;
		fstream file ;
		file.open("CUSTOMER.DAT", ios::out | ios::app ) ;
		roomno = t_roomno ;
		strcpy(name,t_name) ;
		strcpy(phone,t_phone) ;
		advance = t_advance ;
		misc = t_misc ;
		room_srv = t_room_srv ;
		file.write((char*) this, sizeof(customer)) ;
		file.close() ;
	}
	m1.main_scrn() ;
}

void customer :: modify(void)
{
	clrscr() ;
	room r ;
	int valid ;
	char ch ;
	int t_roomno , tr ;
	char  t_name[21] , t_phone[8] ;
	float t_advance , 	t_misc , t_room_srv ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::ate) ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer to be modified " ;
	cin>>tr ;
	getch();
	char t_status ;
	t_status = r.room_status(tr) ;
	if (!r.room_found(tr) || t_status == 'V')
	{
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(tr) ;
	gotoxy(1,12) ;
	cout<<"Do you want to modify this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,12) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,12) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	gotoxy(1,14) ;
	cout<<"ENTER THE NEW DATA FOR THE CUSTOMER" ;
	gotoxy(1,16) ;
	cout<<"Room no.         : " ;
	gotoxy(1,17) ;
	cout<<"Name             : " ;
	gotoxy(1,18) ;
	cout<<"Phone            : " ;
	gotoxy(1,19) ;
	cout<<"Advance          : " ;
	gotoxy(1,20) ;
	cout<<"Miscellineous    : " ;
	gotoxy(1,21) ;
	cout<<"Room service     : " ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM NUMBER FOR CUSTOMER : " ;
		gotoxy(20,16) ;
		cin>>t_roomno ;
		getch();
		t_status = r.room_status(t_roomno) ;
		if ((!r.room_found(t_roomno)) || (r.room_found(t_roomno) && t_roomno != tr && t_status == 'O'))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"ROOM NO. NOT EXIST OR NOT VACANT" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,16) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NAME OF THE CUSTOMER : " ;
		gotoxy(20,17) ;
		gets(t_name) ;
		getch();
		strupr(t_name) ;
		fflush(stdin) ;
		if ((strlen(t_name) <= 0) || (strlen(t_name) > 20))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 20" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,17) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE PHONE NO. OF THE CUSTOMER, ENTER '-' FOR NO PHONE NO." ;
		gotoxy(20,18) ;
		cin>>t_phone ;
		if ((strlen(t_phone) < 8 && strlen(t_phone) > 1) || (strlen(t_phone) > 8))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN 8 OR GREATER THAN 8" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,18) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADVANCE RS. " ;
		gotoxy(20,19) ;
		cin>>t_advance ;
		getch();
		if (t_advance < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,19) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE MISCALLENIOUS CHARGES" ;
		gotoxy(20,20) ;
		cin>>t_misc ;
		getch();
		if (t_misc < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,20) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM SERVICE CHARGES" ;
		gotoxy(20,21) ;
		cin>>t_room_srv ;
		getch();
		if (t_room_srv < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,21) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,23) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,23) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,23) ; clreol() ;
		}
			} while ( !valid ) ;
	if (ch == 'Y')
	{
		if (t_roomno != tr)
		{
			r.change_status(t_roomno,'O') ;
			r.change_status(tr,'V') ;
		}
		int recno ;
		recno = recordno(tr) ;
		int location ;
		location = (recno-1) * sizeof(customer) ;
		file.seekp(location) ;
		roomno  = t_roomno  ;
		strcpy(name,t_name) ;
		strcpy(phone,t_phone) ;
		room_srv = t_room_srv ;
		advance = t_advance ;
		misc = t_misc ;
		file.write((char *) this, sizeof(customer)) ;
	}
	file.close () ;
}
void customer :: delete_record(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(customer)) ;
		if ( file.eof() )
			break ;
		if ( roomno != t_roomno )
			temp.write((char *) this, sizeof(customer)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("CUSTOMER.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(customer)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(customer)) ;
	}
	file.close() ;
	temp.close() ;
}



void customer :: deletion(void)
{
	clrscr() ;
	room r ;
	int valid ;
	char ch ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer to be deleted " ;
	cin>>t_roomno ;
	char t_status ;
	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'V')
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25l) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(t_roomno) ;
	gotoxy(1,15) ;
	cout<<"Do you want to delete this Customer Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(52,15) ;
		cin>>ch ;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(52,15) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	r.change_status(t_roomno,'V') ;
	delete_record(t_roomno) ;
}


char room :: room_status(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	char t_status ;
	while (file.read((char *) this, sizeof(room)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			t_status = status ;
		}
	}
	file.close () ;
	return t_status ;
}


void room :: change_status(int t_roomno , char t_status)
{
	int recno ;
	recno = recordno(t_roomno) ;
	fstream file ;
	file.open("ROOM.DAT", ios::out | ios::ate) ;
	int location ;
	location = (recno-1) * sizeof(room) ;
	file.seekp(location) ;
	status = t_status  ;

	file.write((char *) this, sizeof(room)) ;
	file.close () ;
}


void customer :: display_record(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	while (file.read((char *) this, sizeof(customer)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room no.             : " <<roomno ;
			gotoxy(1,6) ;
			cout<<"Customer Name        : " <<name ;
			gotoxy(1,7) ;
			cout<<"Phone no.            : " <<phone ;
			gotoxy(1,8) ;
			cout<<"Advance              : " <<advance ;
			gotoxy(1,9) ;
			cout<<"Misc. charges        : " <<misc ;
			gotoxy(1,10) ;
			cout<<"Room Service Charges : " <<room_srv ;
		}
	}
	file.close () ;
   }
   void customer :: display_customer_record(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	while (file.read((char *) this, sizeof(customer)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room no.             : " <<roomno ;
			gotoxy(1,6) ;
			cout<<"Customer Name        : " <<name ;
			gotoxy(1,7) ;
			cout<<"Phone no.            : " <<phone ;
			gotoxy(1,8) ;
			cout<<"Advance              : " <<advance ;
			gotoxy(1,9) ;
			cout<<"Misc. charges        : " <<misc ;
			gotoxy(1,10) ;
			cout<<"Room Service Charges : " <<room_srv ;
		}
	}
	file.close () ;
   }





int customer :: recordno(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int count = 0 ;
	while (file.read((char *) this, sizeof(customer)))
	{
		count++ ;
		if (t_roomno == roomno)
			break ;
	}
	file.close() ;
	return count ;
}


int room :: recordno(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int count = 0 ;
	while (file.read((char *) this, sizeof(room)))
	{
		count++ ;
		if (t_roomno == roomno)
			break ;
	}
	file.close() ;
	return count ;
}





void main ( void )
{
int gdriver=DETECT, gmode;
menu m;
 int midx,midy,rt;
 int w,y,E;
 char q[52];
 {
  clrscr();
   cout<<"\n\n\n\n\n\n";
   cout<<"\n________________________________________________________________________________";
    cout<<"\n***********************                                    *********************";
    cout<<"\n                      --------------------------------------                  ";
    cout<<"\n           **********************  ATHARVA JOSHI  ********************* ";
    cout<<"\n           ********************** GOPAL MAHESHWARI  ********************* ";
    cout<<"\n           ******* BK BIRLA INSTITUTE OF ENGINEERING AND TECHNOLOGY ****** ";
   cout<<"\n--------------------------------------------------------------------------------";
   gotoxy(25,10);
    textcolor(WHITE + BLINK);
    cprintf("WELCOME TO HOTEL MANGEMENT SYSTEM");
   getch();
 }
 m.login();
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 clrscr();
 char str[36];
 strcpy(str," Welcome To Hotel Management System");
 textmode(C40);
 textcolor(BLUE);
 gotoxy(2,11);
 for(int i=0;;i++)
 {
  if(kbhit() && i>=36)
     break;
  if(i<=36)
   cprintf("%c",str[i]);
   delay(150);
   textcolor(9);
 }
 int g,cho;
 m.main_scrn();
getch();
}