#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

const int row=33,col=69;
int columnOneThird = col/3;
int columnTwoThird = (col*2)/3;
int rowOneThird = row/3;
int rowTwoThird = (row*2)/3;
char mat[row][col];
char key_press;
int btn=0;
int print = 0;
int cursor[2];
int cpX=0,cpY=0;
bool firstPlayer=true,secondPlayer=false;
int firstPlayerChoice[3][3]={0};
int secondPlayerChoice[3][3]={0};
bool play=true;
bool fw=false,sw=false;
int fieldValue=0;

tuple<int,int> cursorPosition(int x, int y){
  int posX,posY;
  posX = (rowOneThird/2)+(rowOneThird*x);
  posY = (columnOneThird/2)+(columnOneThird*y);

  return make_tuple(posX,posY);
}

void winner(string person){
  cout<<person<<" player is the winner"<<endl;
  play=false;
}

bool win(int ar[3][3]){
  if(((ar[0][0]+ar[0][1]+ar[0][2])==3)
  || (ar[0][0]+ar[1][0]+ar[2][0] == 3)
  || (ar[0][0]+ar[1][1]+ar[2][2] == 3)
  || (ar[1][0]+ar[1][1]+ar[1][2] == 3)
  || (ar[2][0]+ar[2][1]+ar[2][2] == 3)
  || (ar[0][2]+ar[1][2]+ar[2][2] == 3)
  || (ar[0][2]+ar[1][1]+ar[2][0] == 3)
  || (ar[0][1]+ar[1][1]+ar[2][1] == 3)
  ){
    return true;
  }else return false;
}

void logic(){

  // if(((firstPlayerChoice[0][0]+firstPlayerChoice[0][1]+firstPlayerChoice[0][2])==3)
  // || (firstPlayerChoice[0][0]+firstPlayerChoice[1][0]+firstPlayerChoice[2][0] == 3)
  // || (firstPlayerChoice[0][0]+firstPlayerChoice[1][1]+firstPlayerChoice[2][2] == 3)
  // || (firstPlayerChoice[1][0]+firstPlayerChoice[1][1]+firstPlayerChoice[1][2] == 3)
  // || (firstPlayerChoice[2][0]+firstPlayerChoice[2][1]+firstPlayerChoice[2][2] == 3)
  // || (firstPlayerChoice[0][2]+firstPlayerChoice[1][2]+firstPlayerChoice[2][2] == 3)
  // || (firstPlayerChoice[0][2]+firstPlayerChoice[1][1]+firstPlayerChoice[2][0] == 3)
  // || (firstPlayerChoice[0][1]+firstPlayerChoice[1][1]+firstPlayerChoice[2][1] == 3)
  // ) {
  //   fw=true;
  //   winner("First");
  // } 
  if(win(firstPlayerChoice)){
    fw=true;
    winner("First");
  }
    // secondplayer
  //   if(((secondPlayerChoice[0][0]+secondPlayerChoice[0][1]+secondPlayerChoice[0][2])==3)
  // || (secondPlayerChoice[0][0]+secondPlayerChoice[1][0]+secondPlayerChoice[2][0] == 3)
  // || (secondPlayerChoice[0][0]+secondPlayerChoice[1][1]+secondPlayerChoice[2][2] == 3)
  // || (secondPlayerChoice[1][0]+secondPlayerChoice[1][1]+secondPlayerChoice[1][2] == 3)
  // || (secondPlayerChoice[2][0]+secondPlayerChoice[2][1]+secondPlayerChoice[2][2] == 3)
  // || (secondPlayerChoice[0][2]+secondPlayerChoice[1][2]+secondPlayerChoice[2][2] == 3)
  // || (secondPlayerChoice[0][2]+secondPlayerChoice[1][1]+secondPlayerChoice[2][0] == 3)
  // || (secondPlayerChoice[0][1]+secondPlayerChoice[1][1]+secondPlayerChoice[2][1] == 3)
  // ) {
  //   sw=true;
  //   winner("Second");
  // } 
  if(win(secondPlayerChoice)){
    sw=true;
    winner("Second");
  }
  if(!fw && !sw && fieldValue==9){
    cout<<"Game Draw"<<endl;
    play=false;
  }
}


void input() {
  // drawField();
  key_press = getch();
  btn = key_press;
  int iVal,jVal;
  // tie(iVal,jVal)=cursorPosition(cpX,cpY);
  // while(btn!=27){
    // drawField();
    
    // key_press = getch();
    // btn = key_press;
    switch (btn){
      case 97:
        if(cpY!=0)cpY--;
        break;
      case 100:
        if(cpY!=2)cpY++;  
        break;
      case 115:
        if(cpX!=2)cpX++;
        break;
      case 119:
        if(cpX!=0)cpX--;
      default:
        break;
    }
    tie(iVal,jVal)=cursorPosition(cpX,cpY);
    if(mat[iVal][jVal]!='0' && mat[iVal][jVal]!='X')mat[iVal][jVal]='_';
    if(btn==102){
      if(firstPlayer && firstPlayerChoice[cpX][cpY]==0 && secondPlayerChoice[cpX][cpY]==0){
        firstPlayerChoice[cpX][cpY]=1;
        mat[iVal][jVal]='0';
        firstPlayer=false;
        secondPlayer=true;
        fieldValue++;
      }else if(secondPlayer && secondPlayerChoice[cpX][cpY]==0 && firstPlayerChoice[cpX][cpY]==0) {
        secondPlayerChoice[cpX][cpY]=1;
        mat[iVal][jVal]='X';
        firstPlayer=true;
        secondPlayer=false;
        fieldValue++;
      }
    }
    // system("clear");
    // drawField();
  // }
}

void drawField(){
  while(btn!=27 && play){
    system("clear");
    cout << "\n\n\n";
    for(int i=0;i<row;i++){
      cout << "\t\t\t\t";
      for(int j=0;j<col;j++){
        cout<<mat[i][j];
        if(mat[i][j]=='_')mat[i][j]=' ';
      }
      cout<<endl;
    }
    input();
    logic();
  }
}



int main() {
  // int x,y;
  // tie(x,y)=cursorPosition(0,0);
  // cout<<x<<" "<<y<<endl;
  // for(int i=0;i<3;i++){
  //   for(int j=0;j<3;j++){
  //     cout<<firstPlayerChoice[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(j==(columnOneThird-1) || j==(columnTwoThird-1)) {
        mat[i][j] = '|';
        // cout << "|";
      }
      else if(i==(rowOneThird-1) || i==(rowTwoThird-1)) {
        mat[i][j] = '-';
        // cout << "-";
      }
      else {
        mat[i][j] = ' ';
        // cout << " ";
      }
    }
    // cout<<endl;
  }
  drawField();
  // input();

  return 0;
}