#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<math.h>
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
 string prdt="";
 cout<<"Enter number 1:";
 cin>>str1;
 cout<<"Enter number 2:";
 cin>>str2;
 int n1 = str1.size();
 int n2 = str2.size();
 int z1,z2;
 int car;
 int in1 = 0,in2=0;
 vector<int> v(n1 + n2,0);
       for(int i = n1 - 1;i >= 0;i--)
       {
        z1 = str1[i] - '0';
	car  = 0;
	in2 = 0;
	 for(int j = n2 - 1;j >= 0;j--)
          {
	     z2 = str2[j] - '0';
	     int sum = z1*z2 + v[in1 + in2] + car;
	     v[in1 + in2] = sum%10;
	     car = sum/10;
	     in2++;
	   }
	if (car > 0)
          { 
            v[in1 + in2] += car;
           }
	in1++;
	}
	int i = v.size() - 1;
  while(v[i] == 0)
      i--;
   for(int j = i;j >= 0;j--)
     cout << v[j];
	
	cout << endl;
}
cout<<endl;
return 1;
}
     
