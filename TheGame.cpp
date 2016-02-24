//Flipkart round 1
#include<iostream>
#include<vector>
using namespace std;
class Player
{
      public :
             char id;
             Player(char a)
             {
                         id=a;
             }
};
class Game{
      
      vector<vector<char> > v;
      vector<int> last;
      public:
             Game(int r, int c)
             {
                      v.resize(r,vector<char> (c,'_'));
                      last.resize(r,r);
             }
             void printBoard()
             {
              for(int i=0;i<v.size();i++)
              {
                      for(int j=0;j<v[i].size();j++)
                      {
                              cout<<v[i][j]<<" ";
                              }
                              cout<<endl;
                       }
                      /* for(int i=0;i<last.size();i++)
                       cout<<last[i]<<" "; */
                       
              }   
              bool isAvail(int pos)
              {
                   if(last[pos-1]>0)
                   {
                                    return true;
                   }
                   else
                       return false;
                                    
              }
              bool place(int pos,char id)
              {
                   
                   if(isAvail(pos))
                   {
                     v[last[pos-1]-1][pos-1]=id;
                     last[pos-1]--;
                     return true;
                   }
                   else
                   return false;
                   
                   
                   
               }
               int validateVertical(int pos,char id)
               {
                   //check horizontal
                   int curr_col=pos-1;
                   int curr_row=last[pos-1];
                   bool flag_Test=true;
                   //cout<<"\n\n DEBUGGING  :" <<curr_row<<" "<<curr_col<<endl;
                   int i;
                   for(i=curr_row+1;i<curr_row+2&&i<v.size();i++)
                   {
                           if(id==v[i][curr_col])
                           flag_Test=true;
                           else
                           {
                               flag_Test=false;
                               break;
                           }
                   }
                   if(i>=v.size())
                   flag_Test=false;
                   if(flag_Test)
                   return 1;
                   else
                   return 0;
                    
               }
               int validateHorizontal(int pos,char id)
               {
                  int curr_col=pos-1;
                  int curr_row=last[pos-1];
                  /*bool flag_Test=true;
                  //check point 1
                   //cout<<"\n\n DEBUGGING  :" <<curr_row<<" "<<curr_col<<endl;
                  int i;
                  for(i=curr_col+1;i<curr_col+3&&i<v.size();i++)
                  {
                      if(v[curr_row][i]!=id)
                      flag_Test=false;
                  } 
                  if(i>=v.size())
                  flag_Test=false;
                 // bool flag_Test1=true;
                  //cout<<"\n\n DEBUGGING  :" <<curr_row<<" "<<curr_col<<endl;
                  for(i=curr_col-1;i>=curr_col-2&&i>=0;i--)
                  {                     
                      //cout<<v[curr_row][i]<<"T ";
                      if(v[curr_row][i]!=id)
                      flag_Test1=false;
                  }    */
                  if(curr_col-2>=0)
                  {
                                  if(v[curr_row][curr_col]==v[curr_row][curr_col-1])
                                  {
                                             if(v[curr_row][curr_col-2]==v[curr_row][curr_col-1])
                                             {
                                             cout<<v[curr_row][curr_col-2]<<" "<<v[curr_row][curr_col-1]<<" "<<v[curr_row][curr_col];
                                             return 1;
                                             }
                                  }
                  }
                  if(curr_col+2<v.size())
                  {
                                  if(v[curr_row][curr_col]==v[curr_row][curr_col+1])
                                  {
                                             if(v[curr_row][curr_col+2]==v[curr_row][curr_col+1])
                                             {
                                             cout<<v[curr_row][curr_col-2]<<" "<<v[curr_row][curr_col-1]<<" "<<v[curr_row][curr_col];
                                             return 1;
                                             }
                                  }
                  }
                  //if(i<0)
                  //flag_Test1=false;
                  if(curr_col+1<v.size()&&curr_col-1>=0)
                  {
                      if(v[curr_row][curr_col]==v[curr_row][curr_col-1])
                      {
                         if(v[curr_row][curr_col]==v[curr_row][curr_col+1])
                         {
                           return 1;
                         }
                      }
                  }
             
                  /*if(flag_Test)
                  return 1;
                    */
                   
                   
               }
               int validateBoard()
               {
                   bool flag=1;
                   for(int i=0;i<last.size();i++)
                    {
                           if(last[i]!=0)
                           return 0;
                    }
                    return 1;
               }
               int validate(int pos,char id)
               {
                   int check=0;
                   check=validateVertical(pos,id);
                   if(check==1)
                   return 1;
                   check =0;
                   check=validateHorizontal(pos,id);
                   if(check==1)
                   return 1; 
                   check=validateBoard();
                   if(check==1)
                   return 0;
                   
                   
                   
                   
               }
                 
      
      
      
      };      
int main()
{
    cout<<"\nWelcome to the game bro , lets do it :)\n";
    int n=5;
    Game board(n,n);  
    char sym1,sym2;
    cout<<"\nPlayer one Select your symbol :";
    cin>>sym1;    
    cout<<"\nPlayer two select your symbol :";
    cin>>sym2;                             
    cout<<endl<<endl;
    Player p1(sym2),p2(sym1);
    board.printBoard();
    bool turn=true;
    int pos=0;
    while(1)
    {        Player T=p1;
            if(turn==true)
            {           T=p2;
            }
            else
            {
                            T=p1;
            }
                
                       cout<<"\n"<<T.id<<": ";
                       cin>>pos;
                       if(pos<=0 || pos>n)
                       {
                                 cout<<"\n ###  OOPS !!!! come on play inside the board  ###\n";
                                 continue;
                       }
                       if(!board.place(pos,T.id))
                       {
                                  cout<<"\n ### No place in there buddy !! \n";
                                  continue;
                       }
                       else
                       {
                           int check=board.validate(pos,T.id);
                           if(check==0)
                           {
                                       cout<<"\n you guys ended up in a tie :[ \n";
                                       break;
                           }
                           else if(check==1)
                           {
                                cout<<"\nNice move Buddy , you won the game "<<T.id<<endl;
                                break;
                           }
                           turn =!turn;
                           
                       }
                       cout<<endl;
                       board.printBoard();
                       cout<<endl;
                       
            }
            board.printBoard();
            cin>>n;
            
                      
}
    //cin>>n;
    
