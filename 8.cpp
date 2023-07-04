#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

class record
{
public:
char name[20];
char usn[20];
}rec[20];
fstream file[8];
int no;
char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};
void merge_file(char* file1,char* file2,char* filename)
{
record recd[20];
int i,k;
k=0;
fstream f1,f2;
f1.open(file1,ios::in);
f2.open(file2,ios::in);
while(!f1.eof())
{
f1.getline(recd[k].name,20,'|');
f1.getline(recd[k++].usn,20,'\n');
}
while(!f2.eof())
{
f2.getline(recd[k].name,20,'|');
f2.getline(recd[k++].usn,20,'\n');
}
int t,y;
record temp;
for(t=0;t<k-2;t++)
for(y=0;y<k-t-2;y++)
if(strcmp(recd[y].name,recd[y+1].name)>0)
{
temp=recd[y];
recd[y]=recd[y+1];
recd[y+1]=temp;
}
fstream temp1;
temp1.open(filename,ios::out);
for(t=1;t<k-1;t++)
temp1<<recd[t].name<<"|"<<recd[t].usn<<"\n";
f1.close();
f2.close();
temp1.close();
return;
}
void kwaymerge()
{
int i,k;
k=0;
char filename[7][20]={"11.txt","22.txt","33.txt","44.txt","111.txt",
"222.txt","1111.txt"};
for(i=0;i<8;i+=2)
{
merge_file(fname[i],fname[i+1],filename[k++]);
}
k=4;
for(i=0;i<4;i+=2)
{
merge_file(filename[i],filename[i+1],filename[k++]);
}
merge_file(filename[4],filename[5],filename[6])
; return;
}
int main()
{
int i;
cout<<"enter no of records\n";
cin>>no;
cout<<"\nenter the details\n";
for(i=0;i<8;i++)
file[i].open(fname[i],ios::out);
for(i=0;i<no;i++)
{
cout<<"\n";
cout<<"Name:";
cin>>rec[i].name;
cout<<"Usn:";
cin>>rec[i].usn;
file[i%8]<<rec[i].name<<"|"<<rec[i].usn<<"\n";
}
for(i=0;i<8;i++)
file[i].close();
kwaymerge();
fstream result;
result.open("1111.txt",ios::in);
cout<<"\n Sorted Records \n";
char name[20],usn[20];
for(i=0;i<no;i++)
{
result.getline(name,20,'|');
result.getline(usn,20,'\n');
cout<<"\nName:"<<name<<"\nUsn:"<<usn<<"\n";
}
return 0;
}
