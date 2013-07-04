/* Chess Game: Partialy working -- No Graphic libraries used, 
 * only chars used to design boxes, chessboard, queen, kings, etc
 * 
 * Fall, 2011
 * This was my first attempt to make chess game in my First C++ class(just for fun) 
 * 
 * @param board represent the chess board
 * @param box represent the each box of board
 * @param bb black box on Chess board
 * @param wb white box on chess board
 * @param Ac Camel of player A
 * @param Bc Camel of player B
 * @param Ae Elephant of player A
 * @param Be Elephant of player B
 * @param Ah Horse of player A
 * @param Bh horse of player B
 * @param Aq queen of A
 * @param Bq queen of B
 * @param Ak king of player A
 * @param Bk king of player B
 * @param As Soldier of A
 * @param Bs Soldier of B
 * @param Madd
 *
 * @author Gurpreet Singh
 */
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char box[5][7];
box bb,wb,As,Bs, Ac,Bc, Ae,Be, Ah,Bh, Aq,Bq, Ak,Bk,*board[8][8], *Madd[14];             //wq=white queen , bq=black queen.
int I1,I2,O1,O2;

bool setElephant(int x, int y, int i, int j)       // Applied for positon--check validity of that position
   {  if((x==i)||(y==j))
      {  
        if((x==i)&&(j<y))
           for(int u=j; u<y;u++)
              {  if( (board[x][u]==&wb) || (board[x][u]==&bb) ) 
                        { }  //empty...no need to fill                 
                 else
                    return false;   
              }     
        if((x==i)&&(j>y))
           for(int u=y; u<j;u++)
              {  if( (board[x][u]==&wb) || (board[x][u]==&bb) ) 
                        { }  //empty...no need to fill                 
                 else
                    return false;   
              }     
        if((y==j)&&(i<x))
           for(int u=i; u<x;u++)
              {  if( (board[u][y]==&wb) || (board[u][y]==&bb) ) 
                        { }  //empty...no need to fill                 
                 else
                    return false;   
              }     
        if((y==j)&&(i>x))
           for(int u=x; u<i;u++)
              {  if( (board[u][y]==&wb) || (board[u][y]==&bb) ) 
                        { }  //empty...no need to fill                 
                 else
                    return false;   
              } 
           return true;
      }// extreme outer if loop       
         
      return false;     
   }// Function elephant ends here
   
  bool setHorse(int x1, int y1 ,int i, int j)        // change i,j----current location of horse....
          { // x1, y1 = Final Next Move Position
            
            int tempi, tempj;
            int x[8],y[8];   //Array x[8], y[8]--- contain positions where horse can go from its current positions i,j .       
             // Filling positions where horse can go in x[8], y[8].
             tempi=i; tempj=j;
             i-=2; j-=1; x[0]=i; y[0]=j;      //Also fori+2, j+2, j-1
             j=tempj; j+=1;                        //reset j; 
             x[1]=i; y[1]=j;
             i=tempi; j=tempj;              //reset i and j 
             
             i+=2;  j-=1;  x[2]=i;  y[2]=j;      //Also fori+2, j+2, j-1
             j=tempj; j+=1;                        //reset j; 
             x[3]=i; y[3]=j;
             i=tempi; j=tempj;              //reset i and j 
             
             j-=2;  i-=1;  x[4]=i;  y[4]=j;      //Also fori+2, j+2, j-1
             i=tempi; i+=1;                         //reset j; 
             x[5]=i; y[5]=j;
             i=tempi; j=tempj;              //reset i and j 
             
             j+=2;  i-=1;  x[6]=i;  y[6]=j;      //Also fori+2, j+2, j-1
             i=tempi; i+=1;                         //reset j; 
             x[7]=i; y[7]=j;
             i=tempi; j=tempj;
             
            //for(int v=0;v<8;v++)
             //{  cout<<x[v]<<"   "<<y[v]<<endl;  }
      
             // Checking for final position check through traversing x[8], y[8].
            for(int v=0; v<8;v++)
            {   if((x1==x[v])&&(y1==y[v]))
                     return true;             
            }
            
      
         return false;
                                      
      }// Function Horse Check ends here.

       bool setSoldier(int x2, int y2, int i, int j)
          {  int tempj=j, tempi=i;
             i--; j--;                     // one more case still need to add....when something is ahead of soldier
                                           // then soldier can't move...or return false for u=1 if ..som
          for(int u=0; u<3;u++)          //Direct entry for J.....analyze it ....don't get puzzle here
            { if( (x2==i) && (y2==j) )           // for upside Soldier B
                 return true;
               j++;
            }  
          j=tempj;
          i=tempi;  i++; j--;                 // from here downwards ---for downside Soldier A
          for(int u=0; u<3;u++,j++)          //Direct entry for J.....analyze it ....don't get puzzle here
            if( (x2==i) && (y2==j) )
                 return true;
            
            return false;        
          }// Function-setSoldier ends here
          
      bool setCamel(int x3, int y3, int i, int j)             //Applied for position...to check validity 
       { int tempi, tempj;           //c1, d1    Current Position of Camel.
        tempi=i; tempj=j;
        
           while(i!=-1&&j!=-1)                   // Up Left Corner
           {   if( (x3==i)&&(y3==j) )
                    return true;
                i--; j--;
           }
           i=tempi; j=tempj;      
           while(i!=8&&j!=-1)                   //Down Left Corner
           {   if( (x3==i)&&(y3==j) )
                    return true;
                i++; j--; 
           }
          i=tempi; j=tempj;
           while(i!=-1&&j!=8)                    // Up Right Corner
           {   if( (x3==i)&&(y3==j) )
                    return true;
                i--; j++;
            }
            i=tempi; j=tempj;
            while(i!=8&&j!=8)                    //Down Right Corner
           {   if( (x3==i)&&(y3==j) )
                    return true;
                i++; j++;
            }             
              
          return false;    
     }// Function-- Camel ends here.
     
      
    bool setQueen(int x, int y, int i, int j)
       {
          int tempi, tempj;           //c1, d1    Current Position of Camel.
        tempi=i; tempj=j;             
                      
        if( (x==i)||(y==j) )
             return true;   
                
        while(i!=-1&&j!=-1)                   // Up Left Corner
           {   if( (x==i)&&(y==j) )
                    return true;
                i--; j--;
           }
           i=tempi; j=tempj;   
           while(i!=8&&j!=-1)                   //Down Left Corner
           {   if( (x==i)&&(y==j) )
                    return true;
                i++; j--; 
           }
           i=tempi; j=tempj;
           while(i!=-1&&j!=8)                    // Up Right Corner
           {   if( (x==i)&&(y==j) )
                    return true;
                i--; j++;
            }
            i=tempi; j=tempj;
            while(i!=8&&j!=8)                    //Down Right Corner
           {   if( (x==i)&&(y==j) )
                    return true;
                i++; j++;
            }             
                  
          return false;      
        } //Function-- Queen ends here.      
       

bool setKing(int x, int y, int i, int j)
       {
          int tempi, tempj;           //c1, d1    Current Position of Camel.
          tempi=i; tempj=j;
          for(int u=i-1; u<=i+1; u++)
             for(int v=j-1; v<=j+1; v++)
             {   if((x==u)&&(y==v))
                    return true;       
             }
                          
          return false;            
             
      } //Function-- Kinng ends here.

void MemPass() {
     board[O1][O2]=board[I1][I2];
         if((I1+I2)%2==0)
             board[I1][I2]=&wb;
         else
             board[I1][I2]=&bb;
     }// MemPass function ends

int main(){
       int i,j,k,l, f;
       
       
       for(i=0;i<5;i++)
           for( j=0;j<7;j++)
           {  As[i][j]=' ';
              Bs[i][j]=' ';
              Ac[i][j]=' ';
              Bc[i][j]=' ';
              Ae[i][j]=' ';
              Be[i][j]=' ';
              Ah[i][j]=' ';
              Bh[i][j]=' ';
              Aq[i][j]=' ';
              Bq[i][j]=' ';
              Ak[i][j]=' ';
              Bk[i][j]=' ';  
                
          }
    
   //fill in Ak, Bk
       for(i=0;i<5;i++)
           for( j=0;j<7;j++)
           {  if(i==0)
              { Bk[i][j]=' ';
                Ak[i][j]=char(219);    
              }
              else if(i==1)                          
               {  if((j==0)||(j==6))
                    { Bk[i][j]=' ';
                     Ak[i][j]=char(219); } 
                  else
                    { Ak[i][j]=' ';
                     Bk[i][j]=char(219); }                                        
                }
              else
                {
                   if((j==1)||(j==5))
                       { Ak[i][j]=' ';
                         Bk[i][j]=char(219); }
                   else
                     {  Bk[i][j]=' ';
                        Ak[i][j]=char(219); }
                     
                     }   
              
              }//for A- king and B-king.
           //fill in members As
       
           //for( j=1;j<=2;j++)
             // {  // As ---from A Block-Soldier
                 As[1][6]=As[4][3]=As[1][0]=As[0][3]='A';
                 As[2][1]='S';
                 As[2][2]='O';
                 As[2][3]='L';
                 As[2][4]='D';
                 As[2][5]='R';    
                 
                 // Ah----from A Block-Horse   
                  Ah[1][6]=Ah[4][3]=Ah[1][0]=Ah[0][3]='A';
                 Ah[2][1]='H';
                 Ah[2][2]='O';
                 Ah[2][3]='R';
                 Ah[2][4]='S';
                 Ah[2][5]='E';
                // Ac----from A Block-Camel   
                  Ac[1][6]=Ac[4][3]=Ac[1][0]=Ac[0][3]='A';
                 Ac[2][1]='C';
                 Ac[2][2]='A';
                 Ac[2][3]='M';
                 Ac[2][4]='E';
                 Ac[2][5]='L';
                 // Ae----from A Block-Elephant   
                  Ae[1][6]=Ae[4][3]=Ae[1][0]=Ae[0][3]='A';
                 Ae[2][1]='E';
                 Ae[2][2]='L';
                 Ae[2][3]='E';
                 Ae[2][4]='P';
                 Ae[2][5]='H';
                 Ae[2][6]='T';
                 // Aq----from A Block-Queen   
                  Aq[1][6]=Aq[4][3]=Aq[1][0]=Aq[0][3]='A';
                 Aq[2][1]='Q';
                 Aq[2][2]='U';
                 Aq[2][3]='E';
                 Aq[2][4]='E';
                 Aq[2][5]='N';
                 ///////////
                 // Bs ---from B Block-Soldier
                 Bs[1][6]=Bs[4][3]=Bs[1][0]=Bs[0][3]='B';
                 Bs[2][1]='S';
                 Bs[2][2]='O';
                 Bs[2][3]='L';
                 Bs[2][4]='D';
                 Bs[2][5]='R';        
                 // Bh----from B Block-Horse   
                  Bh[1][6]=Bh[4][3]=Bh[1][0]=Bh[0][3]='B';
                 Bh[2][1]='H';
                 Bh[2][2]='O';
                 Bh[2][3]='R';
                 Bh[2][4]='S';
                 Bh[2][5]='E';
                // Bc----from B Block-Camel   
                  Bc[1][6]=Bc[4][3]=Bc[1][0]=Bc[0][3]='B';
                 Bc[2][1]='C';
                 Bc[2][2]='A';
                 Bc[2][3]='M';
                 Bc[2][4]='E';
                 Bc[2][5]='L';
                 // Be----from B Block-Elephant   
                  Be[1][6]=Be[4][3]=Be[1][0]=Be[0][3]='B';
                 Be[2][1]='E';
                 Be[2][2]='L';
                 Be[2][3]='E';
                 Be[2][4]='P';
                 Be[2][5]='H';
                 Be[2][6]='T';
                 // Bq----from B Block-Queen   
                  Bq[1][6]=Bq[4][3]=Bq[1][0]=Bq[0][3]='B';
                 Bq[2][1]='Q';
                 Bq[2][2]='U';
                 Bq[2][3]='E';
                 Bq[2][4]='E';
                 Bq[2][5]='N';
                 
                                            
               //}//for loop ends here
                    
//fill in bb=black box and wb=whitebox
       for(i=0;i<5;i++)
               for( j=0;j<7;j++)
               {   wb[i][j]=' ';
                   bb[i][j]=char(219);    //use 219.
               }
       //fill board with pointers to bb and wb in alternate positions
       for(i=0;i<8;i++)
               for(j=0;j<8;j++)
                       if((i+j)%2==0)
                               board[i][j]=&wb;
                       else
                               board[i][j]=&bb;
     
     //Setting up the initial board--filling with pointers
         for(i=0;i<8;i++)
               for(j=0;j<8;j++)
                    {  if(i>1||i<6)
                           if((i+j)%2==0)
                               board[i][j]=&wb;
                            else
                               board[i][j]=&bb;
                         // if loop for i=2 to i=5
                       // for chess board members ahead  
                          if(i==1)
                          board[i][j]=&As;
                       else if(i==6)
                          board[i][j]=&Bs;
                       else if(i==0)
                         {   if(j==0||j==7)
                                board[i][j]=&Ae;
                             else if(j==1||j==6)
                                board[i][j]=&Ah;
                             else if(j==2||j==5)
                                board[i][j]=&Ac;
                             else if(j==4)    
                                board[i][j]=&Aq;
                             else
                                board[i][j]=&Ak;     
                         }
                        else if(i==7)
                          {   if(j==0||j==7)
                                board[i][j]=&Be;
                             else if(j==1||j==6)
                                board[i][j]=&Bh;
                             else if(j==2||j==5)
                                board[i][j]=&Bc;
                             else if(j==3)    
                                board[i][j]=&Bq;
                             else
                                board[i][j]=&Bk;
                          }    
                               
                                                   
                     }// Set up board
                    
          //Adding Member Pointers to Madd.
       Madd[0]=&wb ;   Madd[1]=&bb ;   Madd[2]=&As ;   Madd[3]=&Bs ;    Madd[4]=&Ac ;
       Madd[5]=&Bc ;   Madd[6]=&Ae ;   Madd[7]=&Be ;   Madd[8]=&Ah ;    Madd[9]=&Bh ;
       Madd[10]=&Aq ;   Madd[11]=&Bq ;  Madd[12]=&Ak ;   Madd[13]=&Bk ;                 
                     
                                          
       // print the board via the pointers in array board
    // first print upper border
    cout<<"     ";
love:    for(i=0;i<7*8;i++)
              cout<<'_';
    cout<<endl;
    // now print the board
    for(i=0;i<8;i++)
        for(k=0;k<5;k++)
          {  cout<<"     "<<char(179); //print left border
             
             for(j=0;j<8;j++)
                for(l=0;l<7;l++)
                    cout<<(*board[i][j])[k][l];
             
             cout<<char(179)<<endl; // at end of line print bar and then newline
          }
       //before exiting print lower border
    cout<<"     ";
    for(i=0;i<7*8;i++)
        cout<<char(196);
    
    cout<<endl;
    
    cout<<"Enter Location no. I1 , I2 : ";
    cin>>I1>>I2;
    cout<<endl<<"Enter Destination Location. O1, O2 : ";
    cin>>O1>>O2;   
    // Checking Input adddress and member address
    for( f=0; f<14; f++)
      {  if(board[I1][I2]==Madd[f])                  //this will give the value of for
                 break;                             // switch statement activating member function  
      }
     
     // Switch Loop to select the Member function.
     switch(f+1)        //wb,bb,As,Bs, Ac,Bc, Ae,Be, Ah,Bh, Aq,Bq, Ak,Bk 
     {
  case 1:
      cout<<"Invalid Move-Must Select Any Member"<<endl;
      break;
  case 2:
      cout<<"Invalid Move-Must Select Any Member"<<endl;
      break;
  case 3:
       if(setSoldier(O1, O2, I1, I2) )    
            MemPass();
       else
          cout<<"Invalid A-Soldier Move"<<endl;
       break;
  case 4:
       if(setSoldier(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-Soldier Move"<<endl;
       break;
  case 5:
       if(setCamel(O1, O2, I1, I2) )    
              MemPass();
       else
           cout<<"Invalid A-Camel Move"<<endl;
       break;
  case 6:
       if(setCamel(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-Camel Move"<<endl;
       break;
    case 7:
       if(setElephant(O1, O2, I1, I2) )    
               MemPass();
       else
           cout<<"Invalid A-Elephant Move"<<endl;
       break;
    case 8:
       if(setElephant(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-Elephant Move"<<endl;
       break;
    case 9:
       if(setHorse(O1, O2, I1, I2) )    
              MemPass();
       else
         cout<<"Invalid A-Horse Move"<<endl;
       break;
    case 10:
       if(setHorse(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-Horse Move"<<endl;
       break;
    case 11:
       if(setQueen(O1, O2, I1, I2) )    
              MemPass();
       else
         cout<<"Invalid A-Queen Move"<<endl;
       break;
    case 12:
       if(setQueen(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-Queen Move"<<endl;
       break;
    case 13:
       if(setKing(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid A-King Move"<<endl;
       break;
    case 14:
       if(setKing(O1, O2, I1, I2) )    
              MemPass();
       else
          cout<<"Invalid B-King Move"<<endl;
       break;
    default:
       cout<<"Invalid Address--Enter Valid one"<<endl;             //case of out of board Input address
} //switch statement ends.
    
    
 
  /*  if(setKing(O1, O2, I1, I2) )          // Testing and assigning stuff...    
       { board[O1][O2]=board[I1][I2];        // after input and output.  
         if((I1+I2)%2==0)
             board[I1][I2]=&wb;
         else
             board[I1][I2]=&bb;
             
       }
    else
      cout<<"Invalid King Move"<<endl;      
    */
    system("pause");
    goto love;
    return 0;
}

