#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
class library
{int bookno;
char bookname[20];
char authorname[40];
int price;
int issuedcopies;
int noofcopies;
public:
void enter()
{
cout<<"enter the booknumber :  ";
cin>>bookno;
cout<<"enter the book name : ";
gets(bookname);
cout<<"enter the author name : ";
gets(authorname);
cout<<"enter the price of book : ";
cin>>price;
cout<<"enter the number of copies : ";
cin>>noofcopies;
issuedcopies=0;
issue();
}
void issue()
{
if(issuedcopies<noofcopies)
issuedcopies++;
}
void returnbook()
{
issuedcopies--;
}
void show()
{
 cout<<"book number : "<<bookno<<endl;
 cout<<"book name : "<<bookname<<endl;
 cout<<"author name : "<<authorname<<endl;
 cout<<"price : "<<price<<endl;
}
 void chang()
 {
 bookno=bookno+2;
 }
 int retprice()
 {
  return price;
 }
 int retbooknumber()
 {
  return bookno;
 }
 char *retbookname()
 {
  return bookname;
 }
 };   //here class main ends

   void writedata()
 {
  ofstream f;
  f.open("LIBRARY.DAT",ios::binary);
  if(!f)
  { cout<<"file not found";
  exit(0);
  }
  library lobj;
  int n;
  cout<<"Total number of books : ";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
   lobj.enter();
   f.write((char*)&lobj,sizeof(lobj));
   }
   f.close();
  }
    void readdata()
  {
    ifstream f;
    f.open("LIBRARY.DAT",ios::binary);
    if(!f)
    {
     cout<<"file not records";
     exit(0);
    }
    library lobj;
    while(f.read((char*)&lobj,sizeof(lobj)))
    {
     lobj.show();
    }
    f.close();
  }
  void adddata()
  {
   ofstream f;
   f.open("LIBRARY.DAT",ios::app|ios::binary);
   if(!f)
   {
     cout<<"File not found";
     exit(0);
   }
    library lobj;
    lobj.enter();
    f.write((char*)&lobj,sizeof(lobj));
    f.close();
  }
   void searchdata()
   {
     ifstream f;
     f.open("LIBRARY.DAT",ios::binary);
     if(!f)
   {
     cout<<"file not records";
     exit(0);
   }
    library lobj;
    char s[40];
    cout<<"enter book name"<<"\n";
    gets(s);
    while(f.read((char*)&lobj,sizeof(lobj)))
  {
    if(strcmpi(lobj.retbookname(),s)==0)
    lobj.show();
   }
   f.close();
  }
  void copydata()
  {
   ifstream f1;
   ofstream f2;
   f1.open("LIBRARY.DAT",ios::binary);
   f2.open("NEWLIBRARY.DAT",ios::binary);
   if(!f1||!f2)
   {
    cout<<"file not found";
    exit(0);
   }
    library lobj;
    while(f1.read((char*)&lobj,sizeof(lobj)))
    {
     if(lobj.retprice()>=70)
     f2.write((char*)&lobj,sizeof(lobj));
    }
    f1.close();
    f2.close();
   }
   void deletedata()
   {
    ifstream f1;
    ofstream f2;
    f1.open("LIBRARY.DAT",ios::binary);
    f2.open("TEMP.DAT",ios::binary);
    if(!f1||!f2)
    {
     cout<<"file not found";
     exit(0);
    }
    library lobj;
    char s[40];
    cout<<"enter book name"<<"\n";
    gets(s);
    while(f1.read((char*)&lobj,sizeof(lobj)))
    {
     if(!(strcmpi(lobj.retbookname(),s)==0))
       f2.write((char*)&lobj,sizeof(lobj));
    }
    f1.close();
    f2.close();
    remove("LIBRARY.DAT");
    rename("TEMP.DAT","LIBRARY.DAT");
    }
     void updatedata()
     {
      ifstream f1;
      ofstream f2;
      f1.open("LIBRARY.DAT",ios::binary);
      f2.open("TEMP.DAT",ios::binary);
      if(!f1||!f2)
      {
       cout<<"file not found";
       exit(0);
      }
      library sobj;
      char s[40];
      cout<<"enter a book name"<<"\n";
      gets(s);
      while(f1.read((char*)&sobj,sizeof(sobj)))
      {
       if(strcmpi(sobj.retbookname(),s)==0)
       {
	sobj.enter();
	f2.write((char*)&sobj,sizeof(sobj));
       }
      }
      f1.close();
      f2.close();
      remove("LIBRARY.DAT");
      rename("TEMP.DAT","LIBRARY.DAT");
     }
     void main()
    {
     int ch;
     do
      {
      clrscr();
      cout<<"\n main menu"
	  <<"\n 1 : writedata"
	  <<"\n 2 : readdata"
	  <<"\n 3 : adddata"
	  <<"\n 4 : searchdata"
	  <<"\n 5 : copydata"
	  <<"\n 6 : deletedata"
	  <<"\n 7 : updatedata"
	  <<"\n 0 : exit"<<"\n";
    cin>>ch;
    switch(ch)
    {
     case 1: clrscr();
	     writedata();
	     getch();
	     break;

     case 2: clrscr();
	     readdata();
	     getch();
	     break;

     case 3: clrscr();
	     adddata();
	     getch();
	     break;

     case 4: clrscr();
	     searchdata();
	     getch();
	     break;

     case 5: clrscr();
	     copydata();
	     getch();
	     break;

     case 6: clrscr();
	     deletedata();
	     getch();
	     break;

    case 7:  clrscr();
	     updatedata();
	     getch();
	     break;
     }
    }
    while(ch!=0);
   }