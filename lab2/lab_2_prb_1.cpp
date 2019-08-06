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
       if((tmp->x==a) && (tmp->y==b))
       {  
       	 if(prev!=NULL)
           {
            prev->ptr=tmp->ptr;
             tmp=NULL;
             delete tmp;
            return 1;
            }
         else
             { 
               (*head).DelFirst();
               return 1;
              }
        }
        else
        {
         prev=tmp;
          tmp=tmp->ptr;
        } 
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
     if(dis<=d)
       cout<<"("<<tmp->x<<","<<tmp->y<<")";
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
 
 cin>>nol;
 
   for(int i=0;i<nol;i++)
    { 
     cin>>b;
       switch(b)
        {
          case 1:
             { cin>>c>>d;
               (*head).AddFirst(c,d);
               break;
              }
         case 2:
              {jud=(*head).DelFirst();
                 break; 
               }
         case 3:
              { cin>>c>>d;
                jud=(*head).Del(c,d);
              
               break;
               }
         case 4:
               {cin>>c;
                 (*head).Search(c);
                 break;
                }
          case 5:
                { cin>>c>>d;
                 jud=(*head).Search(c,d);
                   if(jud==1)
                    cout<<"\nTrue"<<endl;
                   else
                     cout<<"False"<<endl;
                 break;
                  }
           case 6:
                {
                  int len;
                   len=(*head).Length();
                   cout<<len<<endl;
                  break;
                }
             default:
                   {cout<<"invalid option"<<endl;
                    }
        }
     }
return 0;
}
