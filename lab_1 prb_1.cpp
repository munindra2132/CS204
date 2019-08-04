#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
 int cas;
cout<<"Enter number of cases: ";
cin>>cas;
for(int n=0;n<cas;n++)
{
 string str1;
 string str2;
 string sum="";
 cout<<"Enter number 1:";
 cin>>str1;
 cout<<"Enter number 2:";
 cin>>str2;

 int r,c=0;

     if(str1.length()>str2.length())
       swap(str1,str2);
 
      int n1 = str1.length(), n2 = str2.length(); 
         int diff = n2 - n1; 
 //cout<<str1<<"  "<<str2<<endl;
      for(int k=n1-1;k>-1;k--)
            { int su = (str1[k]-48) + (str2[k+diff]-48) + c; 
               sum.push_back(su%10 + 48); 
              c = su/10; 
   
             }
 
 
     for(int k=n2-n1-1;k>-1;k--)
      {
        int su=(str2[k]-48)+c;
        sum.push_back(su%10 +48);
        c=su/10;
       }

  if(c)
   sum.push_back(c+48);

  for(int l=sum.length()-1;l>-1;l--)
    cout<<sum[l];
 cout<<endl;
}
return 1;
}
