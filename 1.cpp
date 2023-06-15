#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
class person
{
public:char name[10];
}s;
fstream f1,f2,f3;
void rev(fstream &out,char name[10])
{
	char *r;

	cout<<"\n reverse of the name is";
	r=name+strlen(name)-1;
	while(r>=name)
	{
		cout<< *r;
		out<< *r;
		r--;
	 }
	 cout<<"\n";
	 out<<"\n";
}
void main()
{
	int m ;
	clrscr();
	cout<<"enter the number of names\n";
	cin>>m;
	f1.open("1.txt",ios::out);
	for(int i=0;i<m;i++)
	{
		cout<<"enter th name\n";
		cin>>s.name;
		rev(f1,s.name);
	 }
	 f1.close();
	 cout<<"\n reverse of th entered names are written to file 1 \n";
	 f1.open("1.txt",ios::in);
	 f2.open("2.txt",ios::out);
	 while(1)
	 {
		f1.getline(s.name,'\n');
		if(f1.eof()) break;
		rev(f2,s.name);
	  }
	  f1.close();
	  f2.close();
	  cout<<"\n reverse of the names in file 1 a written to file 2."<<"\n";
	  f2.open("2.txt",ios::in);
	  f3.open("3.txt",ios::out);
	  while(1)
	  {
		f2.getline(s.name,'\n');
		if(f2.eof()) break;
		rev(f3,s.name);
	  }
	  f2.close();
	  f3.close();
	  cout<<"\n reverse of the names in file 2 are written to file 3."<<"\n";
	  getch();
	  }