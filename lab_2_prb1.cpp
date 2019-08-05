#include<bits/stdc++.h>
#include<math.h>

using namespace std;

class node
{
  int x,y;
  node* ptr;
public:
  void AddFirst(int , int);
  int DelFirst();
  int Del(int, int);
  void Search(int);
  int Search(int,int);
  int Length();
};

node* head;

void node:: AddFirst(int a, int b)
{
   if(head==NULL)
    {
     node* tmp;
     tmp= new node;
     tmp->x=a;
     tmp->y=b;
     head=tmp;
     }
    else
    {
     node* tmp;
     tmp= new node;
     tmp->x=a;
     tmp->y=b;
     tmp->ptr=head;
     head=tmp;
     }
  return ;
 }

int node:: DelFirst()
{
  if(head==NULL)
   return -1;
  else
   {
     node* tmp;
     tmp= new node;
     tmp=head;
     head=head->ptr;
     delete tmp;
    return 1;
    }
}

int node:: Del(int a, int b)
{
 node* tmp; 
 node* prev;
  prev=NULL;
  tmp=head;
   while(tmp!=NULL)
    {
       if(prev!=NULL)
          if((tmp->x==a) && (tmp->y==b))
           {
            prev->ptr=tmp->ptr;
             tmp=NULL;
             delete tmp;
            return 1;
            }
         else
           if((tmp->x==a) && (tmp->y==b))
             {
               DelFirst();
               return 1;
              }
         prev=tmp;
          tmp=tmp->ptr;  
      }
  return -1;
}


void node:: Search(int d)
{
 node* tmp;
 tmp= head;
  while(tmp!=NULL)
   {
    float dis;
    dis= sqrt((tmp->x)*(tmp->x)+(tmp->y)*(tmp->y));
     if(dis<d)
       cout<<"( "<<tmp->x<<","<<tmp->y<<")";
     tmp=tmp->ptr;
    }
}

int node:: Search(int a, int b)
{
 node* tmp;
 tmp=head;
 while(tmp!=NULL)
  {
   if((tmp->x==a) && (tmp->y==b))
    return 1;
   tmp=tmp->ptr;
   }
 return -1;
}

int node:: Length()
{
  node* tmp;
  tmp=head;
  int count=0;
   while(tmp!=NULL)
    {
      count++;
      tmp=tmp->ptr;
     }
 return count;
}

int main()
{
 head=NULL;
 int nol;
 int b,c,d,jud;
 cout<<"Enter no. of operations to be performed : ";
 cin>>nol;
 cout<<"Enter opeartion number1 number2 -"<<endl;
   for(int i=0;i<nol;i++)
    { 
     cin>>b>>c>>d;
       switch(b)
        {
          case 1:
             {
               (*head).AddFirst(b,c);
               break;
              }
         case 2:
              {jud=(*head).DelFirst();
                 if(jud==1)
                   cout<<"Deletion successful"<<endl;
                  else
                   cout<<"Deletion unsuccessful"<<endl;
                break; 
               }
         case 3:
              {
                jud=(*head).Del(b,c);
                 if(jud==1)
                   cout<<"Deletion successful"<<endl;
                  else
                   cout<<"Deletion unsuccessful"<<endl;
               break;
               }
         case 4:
               {
                 (*head).Search(b);
                 break;
                }
          case 5:
                {
                 jud=(*head).Search(b,c);
                   if(jud==1)
                    cout<<"Found"<<endl;
                   else
                     cout<<"Not Found"<<endl;
                 break;
                  }
           case 6:
                {
                  int len;
                   len=(*head).Length();
                   cout<<"Length is "<<len<<endl;
                  break;
                  }
             default:
                   {cout<<"invalid option"<<endl;
                    }
        }
     }
return 0;
}
   
