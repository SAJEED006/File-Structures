#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
class stud
{
	char id[10],name[10],buf[53],sem[10];
	public: void read();
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
	f.open("7.txt",ios::app);
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
	f.open("7.txt",ios::in);
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
			cout<<'\t';
			else if(buf[i]=='#')
			cout<<"\n";
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
	char idl[10],tempid[10];
	cout<<"enter id of the record to be modified\n";
	cin>>idl;
	f.open("7.txt",ios::in|ios::out);
	while(1)
	{
		if(f.eof())
		{
			cout<<"id not found\n";
			break;
		}
		loop:f.getline(buf,50,'#');
		if(buf[0]=='$')
		goto loop;
		for(int i=0;buf[i]!='|';i++)
		tempid[i]=buf[i];
		tempid[i]='\0';
		if(strcmp(idl,tempid)==0)
		{
			int len=strlen(buf);
			len++;
			f.seekp(-len,ios::cur);
			f.put('$');
			flag=1;
			break;
		}
	}
	f.close();
	if(flag)
	{
		cout<<"enter the new value\n";
		read();
		pack();
		cout<<"modified record:\n";
		unpack();
	}
}
void stud::search()
{
	char idl[10],tempid[10];
	cout<<"enter the id to be searched\n";
	cin>>idl;
	f.open("7.txt",ios::in);
	while(1)
	{
		if(f.eof())
		{
			cout<<"record not found\n";
			break;
		}
		loop:f.getline(buf,50,'#');
		//cout<<buf;
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
				else if(buf[i]=='#')
				cout<<"\n";
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
		cout<<"\n\tmenu:\n\n"<<"1.insert\n2.display\n3.search\n4.modify\n5.exit\n";
		cout<<"enter your choice";
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
			case 4:s.modify();
				break;
			case 5: exit(0);
		}
	}
}
