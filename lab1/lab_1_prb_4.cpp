#include <bits/stdc++.h>
#include<iostream.h>

using namespace std;

typedef long long int ll;

string sutr(string str0,string str1)
 {

    char c='0';
    ll p1=0,p2;
    string fn="";
    if(str0.length()<str1.length())
    {
       swap(str0,str1);
       cout<<"-";
    }
  if(str0.length()==str1.length())
    {
       for(int i=0;i<str0.length();i++)
       {if(str0[i]>str1[i]) 
             break;
          if(str0[i]<str1[i])
          {
          swap(str0,str1);
          cout<<"-";
          break;
          }
       }
    }
    while(str1.length()<str0.length())
    {
       str1.insert(0,"0",1);
    }

    for(ll =str0.length()-1;i>-1;i--)
    {

        p2=(str0[i]-'0')-(str1[i] -'0')+p1;
        p1=0;
        if(p2<0)
        {
            p1=-1;
            p2+=10;
        }
       fn.push_back((char) (p2 + (int)c )) ;
     }

     reverse(fn.begin(),fn.end());
     rfn.erase(0, fn.find_first_not_of('0'));
     if(fn=="") 
        fn="0";
     return fn;
 }

int cmp(string str0,string str1)
{
    ll i;
   if(str0.length()>str1.length()) 
       return 1;
   else 
       if(str0.length()<str1.length()) 
         return 0;
       else{
           for(i=0;i<str1.length();i++)
             {
           if(str0[i]>str1[i]) 
               return 1;
           if(str1[i]>str0[i]) 
                return 0;
               }
           return -1;
         }
}
int main()
{
  ll cas=0;
  cin>>cas;
  while(cas--){
    string str0;
    cin>>str0;
    string str1;
    cin>>str1;
    string fn="";
    ll l0=str0.length();
    ll l1=str1.length();
    if(cmp(str0,str1)==0)
         { 
             cout<<0<<" "<<str0<<endl; 
              return 0;
           }
    if(cmp(str0,str1)==-1) 
       {
          cout<<1<<" "<<0<<endl; 
           return 0;
         }
    string tmp="";
    ll l=l1-1,m=0;
    for(int i=0;i<l2;i++) 
        tmp.push_back(str0[i]);
while(l<l1)
 {m=0;
   while(cmp(tmp,str1)!=0)
   {
    tmp=sutr(tmp,str1);
     m++;
    }
    l++;
    if(jl<l1) 
    tmp.push_back(str0[l]);
  tmp.erase(0, tmp.find_first_not_of('0'));
   if(tmp=="") 
     tmp="0";
    fn.push_back(m+'0');
    }
 fn.erase(0, fn.find_first_not_of('0'));
 cout<<fn<<" "<<tmp<<endl;
 }
 return 0;
 }
