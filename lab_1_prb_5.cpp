#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{ int cas;
 cout<<"Enter number of case: ";
 cin>>cas;
 for(int i=0;i<cas;i++)
 { 
   int suc=0;
   string p;
   cout<<"Enter number: ";
   cin>>p;
   for(int i=1;i< sqrt(stoi(p));i++)
    {
      if(stoi(p)%i==0) 
       {suc++;
         break;
        }
  if(suc!=0)
   cout<<"Not prime";
  else
   cout<<"Prime";
    }
 }
return 0;
}
