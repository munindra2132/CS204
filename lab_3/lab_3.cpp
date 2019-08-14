#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>

using namespace std;

void check(char str[], int len)
{
char t[100];
int top=-1;
int c=0;
for(int i=0;i<len;i++) 
 {
  if(str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]=='<')
   { top++;
     t[top]=str[i];
      
   }
  if(str[i]=')' && str[i]!='}' && str[i]!=']' && str[i]!='>' && str[i]!='(' && str[i]!='{' && str[i]!='[' && str[i]!='<' && str[i]!='|')
   c++;
  if(str[i]==')' || str[i]=='}' || str[i]==']' || str[i]=='>')
    {
      if(t[top]=='(' && str[i]==')')
       {top--;}
      /*else
         {
          cout<<"NO";
          return;
         }*/
       if(t[top]=='{' && str[i]=='}')
       {top--;}
      else
         /*{
          cout<<"NO";
          return;
         }*/
       if(t[top]=='[' && str[i]==']')
         {top--;}
        else
         /*{
          cout<<"NO";
          return;
         }*/
       if(t[top]=='<' && str[i]=='>')
         {top--;}
         /*else
         {
          cout<<"NO";
          return;
         }*/
      }
  if(t[top]=='|' && str[i]=='|')
   {
     top--;
   }
   else
    { if(str[i]=='|')
       {top++;
        t[top]=str[i];
        }
     }
 }

if(top!=-1 || c!=0 )
  cout<<"NO"<<endl;
 else
  cout<<"YES"<<endl;
return;
}

int main()
{
 char a[100];
 int cas;
 int i;
 cin>>cas;
 while(cas--)
  {
   cin>>a;
   i=strlen(a);
   check(a,i);
   }
return 1;
}
