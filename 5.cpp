#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
class stud
{
	char id[10],name[10],sem[10],buf[53];
	public: void read();
		void pack();
		void unpack();
		void del();
		void search();
}s;
fstream f1,f2;
void stud::read()
{
	cout<<"enter ID,Name,Sem\n";
	cin>>id>>name>>sem;
}
void stud::pack()
{
	char x[10]={'0'};
	int len,pad=0;
	f1.open("rec2.txt",ios::app);
	strcpy(buf,id);
	strcat(buf,"|");
	strcat(buf,name);
	strcat(buf,"|");
	strcat(buf,sem);
	len=strlen(buf);
	pad=50-len;
	for(int i=0;buf[i]!='\0';i++)
	f1.put(buf[i]);
	while(pad>0)
	{
		f1.put(' ');
		pad--;
	}
	f1.close();
	f1.open("rec2.txt",ios::in);
	while(1)
	{
		f1.getline(buf,51);
		if(f1.eof())
		break;
		int y=atoi(x);
		y++;
		itoa(y,x,10);
	}
	f1.close();
	f2.open("ind2.txt",ios::app);
	f2<<id<<"|"<<x<<"#";
	f2.close();
}
void stud::unpack()
{
	cout<<"ID\tName\tSem\n";
	f1.open("rec2.txt",ios::in);
	while(1)
	{
		if(f1.eof())
		break;
		loop:f1.getline(buf,51);
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='\0';i++)
		{
			if(buf[i]=='|')
			cout<<"\t";
			else if(buf[i]==' ');
			else
			cout<<buf[i];
		}
		cout<<"\n";
	}
	f1.close();
}
void stud::del()
{
	char idl[10],tempid[10],x[10]={' '};
	cout<<"enter the ID to be deleted\n";
	cin>>idl;
	f2.open("ind2.txt",ios::in|ios::out);
	while(1)
	{
		if(f2.eof())
		{
			cout<<"record not found\n";
			break;
		}
		loop:f2.getline(buf,51,'#');
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='|';i++)
		tempid[i]=buf[i];
		tempid[i++]='\0';
		if(strcmp(idl,tempid)==0)
		{
			int len=strlen(buf);
			len++;
			cout<<"record deleted\n";
			f2.seekp(-len,ios::cur);
			f2.put('$');
			int y=0;
			for(;buf[i]!='\0';i++)
			x[y++]=buf[i];
			x[y]='\0';
			y=atoi(x);
			y--;
			y=(y*50);
			f1.open("rec2.txt",ios::in|ios::out);
			f1.seekp(y,ios::beg);
			f1.put('$');
			break;
		}
	}
	f2.close();
	f1.close();
}
void stud::search()
{
	char idl[10],tempid[10],x[10]={' '};
	cout<<"enter the id to be searched\n";
	cin>>idl;
	f2.open("ind2.txt",ios::in);
	while(1)
	{
		if(f2.eof())
		{
			cout<<"record not found\n";
			break;
		}
		loop:f2.getline(buf,51,'#');
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='|';i++)
		tempid[i]=buf[i];
		tempid[i++]='\0';
		if(strcmp(idl,tempid)==0)
		{
		 cout<<"record found\n";
		 int y=0;
		 for(;buf[i]!='\0';i++)
		 x[y++]=buf[i];
		 x[y]='\0';
		 y=atoi(x);
		 y--;
		 y=(y*50);
		 f1.open("rec2.txt",ios::in);
		 f1.seekg(y,ios::beg);
		 f1.getline(buf,51);
		 cout<<"Details:\n";
		 for(i=0;buf[i]!='\0';i++)
		 if(buf[i]=='|')
		 cout<<"\t";
		 else if(buf[i]==' ');
		 else
		 cout<<buf[i];
		 cout<<"\n";
		 break;
		 }
		}
		f2.close();
		f1.close();
}
void main()
{
	clrscr();
	while(1)
	{
		cout<<"\t\tmenu:\n\n"<<"1.insert\n2.display\n3.search\n4.delete\n5.exit\n";
		cout<<"enter your choice\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:s.read();
			s.pack();
			break;
			case 2:s.unpack();
			break;
			case 3:s.search();
			break;
			case 4:s.del();
			break;
			case 5:exit(0);
		}
	}
}

