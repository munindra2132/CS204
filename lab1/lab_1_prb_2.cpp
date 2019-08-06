#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
 int cas;

cin>>cas;
for(int n=0;n<cas;n++)
{
 string str1;
 string str2;
 string sub="";
 cout<<"Enter number 1:";
 cin>>str1;
 cout<<"Enter number 2:";
 cin>>str2;

 int r,bor=0,ng=0;

     if(str2.length()>str1.length())
       {
         swap(str1,str2);
         ng=1;
        }
     int n1=str1.length();
     int n2=str2.length();
  //cout<<n1<<n2;
    for(int k=n2-1;k>-1;k--)
     {
       
       r= str1[k+n1-n2] - str2[k]-bor;
       if(r<0)
        {
          r=r+10;
          bor=1;
         }
         else
           bor=0;
       sub.push_back(r+'0');
      //cout<<r;
     }
    
    for(int k=n1-n2-1;k>-1;k--)
      { 
        if(bor && str1[k]=='0')
         {
          sub.push_back('9');
          }
          else
           {
             r=str1[k]-48-bor;
             if(r>0)
               sub.push_back(r+48);
              bor=0;
           }
       }
     
     for(int l=sub.length()-1;l>-1;l--)
       cout<<sub[l];
 cout<<endl;
}
return 1;
}
