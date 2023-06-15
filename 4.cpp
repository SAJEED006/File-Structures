#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
class stud
{
	char name[10],id[10],sem[10],buf[51];
	public: void read();
		void pack();
		void unpack();
		void search_by_rrn();
}s;
fstream f;
void  stud::read()
{
	cout<<"enter stud details\n";
	cout<<"enter id,name,sem\n";
	cin>>id>>name>>sem;
}
void stud::pack()
{
	f.open("9.txt",ios::app);
	strcpy(buf,id);
	strcat(buf,"|");
	strcat(buf,name);
	strcat(buf,"|");
	strcat(buf,sem);
	strcat(buf,"#");
	for(int i=0;buf[i]!='\0';i++)
		f.put(buf[i]);
		f.close();
}
void stud::unpack()
{
	cout<<"id\tname\tsem\n";
	f.open("9.txt",ios::in);
	while(1)
	{
		if(f.eof())
		break;
		loop:f.getline(buf,50,'#');
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='\0';i++)
		{
			if(buf[i]=='|')
			cout<<"\t";
			else if(buf[i]=='#')
			cout<<"\n";
			else
			cout<<buf[i];
		}
	cout<<"\n";
	}
f.close();
}
void stud::search_by_rrn()
{
	int rrn,count=-1;
	cout<<"enter the rrn to be searched\n";
	cin>>rrn;
	f.open("9.txt",ios::in);
	while(1)
	{
		f.getline(buf,50,'#');
		count++;
		if(f.eof())
		{
			cout<<"record with givn rrn not found\n";
			break;
		}
		else
		{
			if(count==rrn)
			{
				cout<<"record found\n"<<"details:\n";
				for(int i=0;buf[i]!='\0';i++)
				if(buf[i]=='|')
				cout<<"\t";
				else if(buf[i]=='#')
				cout<<"\n";
				else
				cout<<buf[i];
				break;
			}
		}
	}
	f.close();
}
void main()
{
	clrscr();
	while(1)
	{
		cout<<"\n\tmenu:\n\n"<<"1.insert\n2.display\n3.search using rrn\n4.exit\n";
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
			case 3:s.search_by_rrn();
			break;
			case 4:exit(0);
		}
	}
}