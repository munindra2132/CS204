#include <bits/stdc++.h> 
using namespace std; 
   
  
void div(string num1, long long m1) 
{  
    vector<int> a; 
    long long mod = 0; 
  for (int i = 0; i < num1.size(); i++) 
    {   int d= num1[i] - '0'; 
        mod = mod * 10 + d; 
         int q= mod / m1; 
        a.push_back(q);  
        mod = mod % m1;         
    } 
    cout <<endl<<"Remainder :"<< mod <<endl; 
    cout << "Quotient :";
    int x = 0; 
    for (int i = 0; i <a.size(); i++) 
       { if (a[i] == 0 && x == 0) 
         continue; 
        x = 1; 
        cout << a[i]; 
       } 
  
    return; 
} 
  
int main() 
{ int cas;
  cout<<"Enter  number of cases: ";
  cin>>cas;
 for(int i=0;i<cas;i++)
  {
    string num; 
    long long m;
 cout<<"Enter the larger number then smaller number :"; 
cin>>num>>m;
   div(num, m);
   } 
    return 0; 
} 

