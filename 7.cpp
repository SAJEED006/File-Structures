#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
class lists
{
	char name[10],l1[50][50],l2[50][50];
	public:void insert();
	void merge();
	void sort(int);
	void display();
}s;
fstream f1,f2,f3;
int i,j,m,n;
char temp[50];
void lists::insert()
{
	f1.open("list6.txt",ios::app);
	f2.open("list7.txt",ios::app);
	cout<<"Enter the no of names in the list1\n";
	cin>>m;
	cout<<"enter names\n";
	for(i=0;i<m;i++)
	{
		cin>>l1[i];
		f1<<l1[i]<<"\n";
	}
	f1.close();
	m=0;
	sort(1);
	cout<<"enter the no of names in list2\n";
	cin>>n;
	cout<<"Enter names\n";
	for(i=0;i<n;i++)
	{
		cin>>l2[i];
		f2<<l2[i]<<"\n";
	}
	f2.close();
	n=0;
	sort(2);
}
void lists::sort(int x)
{
	if(x==1)
	{
		f1.open("list6.txt",ios::in);
		while(!f1.eof())
		f1.getline(l1[m++],49,'\n');
		m--;
		f1.close();
		f1.open("list6.txt",ios::out);
		f1.seekp(0,ios::beg);
		for(j=0;j<m-1;j++)
		for(i=0;i<m-1;i++)
		if(strcmp(l1[i],l1[i+1])>0)
		{
			strcpy(temp,l1[i]);
			strcpy(l1[i],l1[i+1]);
			strcpy(l1[i+1],temp);
		}
		for(i=0;i<m;i++)
		{
			cout<<l1[i]<<"\n";
			for(j=0;l1[i][j]!='\0';j++)
			f1.put(l1[i][j]);
			f1.put('\n');
		}
		f1.close();
	}
	else if(x==2)
	{
		f2.open("list7.txt",ios::in);
		while(!f2.eof())
		f2.getline(l2[n++],49,'\n');
		n--;
		f2.close();
		f2.open("list7.txt",ios::out);
		f2.seekp(0,ios::beg);
		for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
		if(strcmp(l2[j],l2[j+1])>0)
		{
			strcpy(temp,l2[j]);
			strcpy(l2[j],l2[j+1]);
			strcpy(l2[j+1],temp);
		}
		for(i=0;i<n;i++)
		{
			cout<<l2[i]<<"\n";
			for(j=0;l2[i][j]!='\0';j++)
			f2.put(l2[i][j]);
			f2.put('\n');
		}
		f2.close();
	}
}
void lists::merge()
{
	int i=j=m=n=0;
	f1.open("list6.txt",ios::in);
	f2.open("list7.txt",ios::in);
	f3.open("list8.txt",ios::out);
	while(!f1.eof())
	f1.getline(l1[m++],49,'\n');
	m--;
	while(!f2.eof())
	f2.getline(l2[n++],49,'\n');
	n--;
	cout<<"Names common to both the lists are:\n";
	while(i<m&&j<n)
	{
		if(strcmp(l1[i],l2[j])==0)
		{
			cout<<l1[i]<<"\n";
			f3<<l1[i]<<"\n";
			i++,j++;
		}
		else if(strcmp(l1[i],l2[j])>0)
		j++;
		else
		i++;
	}
	f1.close();
	f2.close();
	f3.close();
}
void lists::display()
{
	f1.open("list6.txt",ios::in);
	f2.open("list7.txt",ios::in);
	cout<<"Names of list1 are:\n";
	while(!f1.eof())
	{
		f1.getline(temp,49);
		cout<<temp<<"\n";
	}
	cout<<"names of list2 are:\n";
	while(!f2.eof())
	{
		f2.getline(temp,49);
		cout<<temp<<"\n";
	}
	f1.close();
	f2.close();
}
void main()
{
	int ch;
	clrscr();
	while(1)
	{
		cout<<"\t\tMENU\n";
		cout<<"\t\t1.Insert\n\t\t2.Display\n\t\t3.Merge\n\t\t4.Exit\n";
		cout<<"Enter the choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:s.insert();
			break;
			case 2:s.display();
			break;
			case 3:s.merge();
			break;
			case 4:exit(0);
		}
	}
}

