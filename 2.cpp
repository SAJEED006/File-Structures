#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
class stud{
	char id[10],name[10],sem[10],buf[53];
	public:
	void read();
	void pack();
	void unpack();
	void modify();
	void search();
	}s;
	fstream f;
	void stud::read()
	{
		cout<<"enter id,name,sem\n";
		cin>>id>>name>>sem;
	}
	void stud::pack()
	{
		f.open("5.txt",ios::app);
		int len,pad=0;
		strcpy(buf,id);
		strcat(buf,"|");
		strcat(buf,name);
		strcat(buf,"|");
		strcat(buf,sem);
		len=strlen(buf);
		pad=50-len;
		for(int i=0;buf[i]!='\0';i++)
		f.put(buf[i]);
		while(pad>0)
		{
			f.put('  ');
			pad--;
		}
		f.close();
	}
	void stud::unpack()
	{
		cout<<"id\tname\tsem\n";
		f.open("5.txt",ios::in);
		while(1)
		{
			if(f.eof())
			break;
			loop:f.getline(buf,51);
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
		f.close();
	}
	void stud::modify()
	{
	int flag=0;
	char idl[10];
	char tempid[10];
	cout<<"enter id of the record to be modified \n";
	cin>>idl;
	f.open("5.txt",ios::in|ios::out);
	while(1)
	{
		if(f.eof())
		{
			cout<<"id not found\n";
			break;
		}
		loop:f.getline(buf,51);
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='|';i++)
		tempid[i]=buf[i];
		tempid[i]='\0';
		if(strcmp(idl,tempid)==0)
		{
			f.seekp(-50,ios::cur);
			f.put('$');
			flag=1;
			break;
		}
	}
	f.close();
	if(flag)
	{
	cout<<"enter the new values\n";
	read();
	pack();
	cout<<"modified records are:\n";
	unpack();
	}
}
void stud::search()
{
	char idl[10],tempid[10];
	cout<<"enter the id to be searched\n";
	cin>>idl;
	f.open("5.txt",ios::in);
	while(1)
	{
		if(f.eof())
		{
			cout<<"record not found\n";
			break;
		}
		loop:f.getline(buf,51);
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='|';i++)
		tempid[i]=buf[i];
		tempid[i]='\0';
		if(strcmp(idl,tempid)==0)
		{
			cout<<"record found\n";
			for(i=0;buf[i]!='\0';i++)
			if(buf[i]=='|')
			cout<<"\t";
			else if(buf[i]==' ');
			else
			cout<<buf[i];
			break;
		}
		}
		f.close();
		}
		void main()
		{
			clrscr();
			while(1)
			{
				cout<<"\n\t\t menu:\n\n"<<"1.INSERT\n 2.DISPLAY\n 3.SEARCH\n 4.MODIFY\n 5.EXIT\n";
				cout<<"enter your choice\n";
				int ch;
				cin>>ch;
				switch(ch)
				{
					case 1:s.read();
					       s.pack();
					case 2:s.unpack();
						break;
					case 3:s.search();
						break;
					case 4:s.modify();
						break;
					case 5:exit(0);
				}
			}
		}