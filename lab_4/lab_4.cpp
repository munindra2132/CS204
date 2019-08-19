#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



struct et{
string value;
et *r, *l;
};

bool isOperator(string c) 
{ 
     if (!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/") || !c.compare("^")) 
        return true;
    return false; 
} 

et* newNode(string v) 
{ 
    et * temp = new et; 
    temp->l = nullptr; 
    temp->r = nullptr;
    temp->value = v; 
    return temp; 
} 
et* Tree(vector<string> s) 
{ 
    stack<et*> st; 
    et *t, *t1, *t2;
    for (int i=0; i < s.size(); i++) 
    { 
        if (!isOperator(s[i])) 
        { 
            t = newNode(s[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(s[i]); 
            t1 = st.top();
            st.pop();
            t2 = st.top(); 
            st.pop();
            t->r = t1; 
            t->l = t2; 
            st.push(t); 
        } 
    }
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int eval(et* root)  
{   
    if (!root)  
        return 0;   
    if (!root->l && !root->r)  
        return stoi(root->value);  
    int lvalue = eval(root->l);  
    int rvalue = eval(root->r);  
    if (root->value=="+")  
        return lvalue+rvalue;  
  
    if (root->value=="-")  
        return lvalue-rvalue;  
  
    if (root->value=="*")  
        return lvalue*rvalue;  
        
    if (root->value=="/")  
        return lvalue/rvalue; 
  
    return pow(lvalue, rvalue);
}

  

int priority(char a) {
    int temp;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}

string postfx(string d)
{
 int c=d.length();
    stack<char> operator_stack;
     vector<string> f;
      string g;
     int j=0,k=0;
    stringstream output;

    for (unsigned i = 0; i < d.length(); i++) {
        if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/' || d[i] == '^') {
              output<<" ";
              f.push_back(output.str());
               while (!operator_stack.empty() && priority(operator_stack.top()) <= priority(d[i])) {
                output << operator_stack.top();
                output<<" ";
                 operator_stack.pop(); 
                }
                 f.push_back(output.str());  
                  
            operator_stack.push(d[i]);
            
        } 
          else if (d[i] == '(') 
            {
            operator_stack.push(d[i]);
            } 
          else if (d[i] == ')') 
              { f.push_back(output.str());
                output<<" ";
                while (operator_stack.top() != '(') 
               { 
               output << operator_stack.top();
                output<<" ";
                operator_stack.pop();
               }
                f.push_back(output.str()); 
                //output<<" ";
                f.push_back(output.str());    
            operator_stack.pop();
        } else {
            output <<d[i];
         }
          
    }
         output<<" ";
    while (!operator_stack.empty()) {
        output <<operator_stack.top();
         output<<" ";
        operator_stack.pop();
    } 
      output<<" ";
     f.push_back(output.str());
    //cout << output.str() << endl;
     int t=f.size()-1;
      //cout<<f[t]<<endl;
    g=f[t];
     //cout<<g;
    f.clear();
  return g;
}


  
int main() {
long long int a;
  cin>>a;
   while(a--)
   {
    string infix;
    cin>>infix;
    string g=postfx(infix);
    //cout<<g;
     std::istringstream iss(g);
     //cout<< iss.str();
   std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
     cout<<endl;
      //for(int i=0;i<results.size();i++)    
       //cout<<results[i]<<endl;
     et*root=Tree(results);
     cout<< eval(root) << '\n';
   }
    return 0;
}
