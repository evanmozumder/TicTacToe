#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int row = 33;
int column = 69;
int rowOneThird = row/3;
int rowTwoThird = (row*2)/3;
int halfRowOneThird = rowOneThird/2;
int columnOneThird = column/3;
int columnTwoThird = (column*2)/3;
int halfColumnOneThird = columnOneThird/2;
bool choice = true;
int print=0;
int iValue=0;
int jValue=0;
vector<vector<int>> inputValue(3);
vector<vector<char>> value(3);
vector<vector<int>> firstPlayerScore(3);
vector<vector<int>> secondPlayerScore(3);
char key_press;
int ascii_value;
bool firstPlayer = true;
bool secondPlayer = false;
char firstPlayerSymbol = 'O';
char secondPlayerSymbol = 'X';
int firstPersonScore = 0;
int secondPersonScore = 0;
int sum = 0;
bool fPrint = true;
void logic() {
    // firstPerson
    if((firstPlayerScore[0][0]+firstPlayerScore[0][1]+firstPlayerScore[0][2])==3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[0][0]+firstPlayerScore[1][0]+firstPlayerScore[2][0] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[0][0]+firstPlayerScore[1][1]+firstPlayerScore[2][2] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[1][0]+firstPlayerScore[1][1]+firstPlayerScore[1][2] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[2][0]+firstPlayerScore[2][1]+firstPlayerScore[2][2] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[0][2]+firstPlayerScore[1][2]+firstPlayerScore[2][2] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[0][2]+firstPlayerScore[1][1]+firstPlayerScore[2][0] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(firstPlayerScore[0][1]+firstPlayerScore[1][1]+firstPlayerScore[2][1] == 3) {
        cout << "First Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    

    // secondplayer
    if((secondPlayerScore[0][0]+secondPlayerScore[0][1]+secondPlayerScore[0][2]) == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[0][0]+secondPlayerScore[1][0]+secondPlayerScore[2][0] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[0][0]+secondPlayerScore[1][1]+secondPlayerScore[2][2] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[1][0]+secondPlayerScore[1][1]+secondPlayerScore[1][2] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[2][0]+secondPlayerScore[2][1]+secondPlayerScore[2][2] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[0][2]+secondPlayerScore[1][2]+secondPlayerScore[2][2] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[0][2]+secondPlayerScore[1][1]+secondPlayerScore[2][0] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
    else if(secondPlayerScore[0][1]+secondPlayerScore[1][1]+secondPlayerScore[2][1] == 6) {
        cout << "Second Player is the Winner!!!";
        print = 27;
        fPrint = false;
    }
}
void input() {
    key_press = getch();
    ascii_value = key_press;
    // if(ascii_value == 27) {
    //     choice = false;
    // }
    print = ascii_value;
    cout << print << endl;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(inputValue[i][j]==1) {
                inputValue[i][j]=0;
                if(print==97) {
                    j--;
                    if(j>=0)
                        inputValue[i][j] = 1;
                    else {
                        j++;
                        inputValue[i][j] = 1;
                    }
                }
                else if(print==100) {
                    j++;
                    if(j<=2)
                        inputValue[i][j] = 1;
                    else {
                        j--;
                        inputValue[i][j] = 1;
                    }
                }
                else if(print==119) {
                    i--;
                    if(i>=0)
                        inputValue[i][j] = 1;
                    else {
                        i++;
                        inputValue[i][j] = 1;
                    }
                }
                else if(print==115) {
                    i++;
                    if(i<=2)
                        inputValue[i][j] = 1;
                    else {
                        i--;
                        inputValue[i][j] = 1;
                    }
                }
                else if(print==102) {
                    inputValue[i][j] = 1;
                    if(firstPlayer) {
                        value[iValue][jValue] = firstPlayerSymbol;
                        firstPlayerScore[iValue][jValue] = 1;
                        firstPlayer = false;
                        secondPlayer = true;
                    }
                    else if(secondPlayer) {
                        value[iValue][jValue] = secondPlayerSymbol;
                        secondPlayerScore[iValue][jValue] = 2;
                        firstPlayer = true;
                        secondPlayer = false;
                    }
                }
                // switch(print) {
                //     case 97:
                //         j-=1;
                //         break;
                //     case 100:
                //         j+=1;
                //         break;
                //     case 119:
                //         i-=1;
                //         break;
                //     case 115:
                //         i+=1;
                //         break;
                //     default:
                //         break;
                // }
                    
                // if(j<0){
                //     j++;
                //     inputValue[i][j] = 1;
                //     // iValue = i;
                //     // jValue = j;
                // }
                // else if(j>2) {
                //     j--;
                //     inputValue[i][j] = 1;
                //     // iValue = i;
                //     // jValue = j;
                // }
                // if(i<0){
                //     i++;
                //     inputValue[i][j] = 1;
                //     // iValue = i;
                //     // jValue = j;
                // }
                // else if(i>2) {
                //     i--;
                //     inputValue[i][j] = 1;
                //     // iValue = i;
                //     // jValue = j;
                // }
                else {
                    inputValue[i][j] = 1;
                    // iValue = i;
                    // jValue = j;
                    // if(i>=0 and i<=2) {
                    //     if(j>=0 and j<=2)
                    //         inputValue[i][j] = 1;
                    //     else 
                    //         inputValue[i][j] = 0;
                    // }
                    // else 
                    //     inputValue[i][j] = 0;
                }
                break;
            }
            // else 
            //     print = 27;
        }
    }
    for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) {
            if(inputValue[k][l] == 1) {
                iValue = k;
                jValue = l;
            }
        }
    }
    for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) {
            cout << inputValue[k][l] << " ";
        }
        cout << endl;
    }
    logic();
    
    // switch ()
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    // default:
    //     break;
    // }
    //return print;
}

void drawField() {
    //input();
    while(print!=27 and fPrint==true) {
        // system("clear");
        cout << "\n\n\n";
        for(int i = 0; i <= row; ++i) {
            cout << "\t\t\t\t";
            for (int j = 0; j <= column; ++j) {
                if(i==halfRowOneThird) {
                    if(j==halfColumnOneThird) {
                        int thisIvalue = 0;
                        int thisJvalue = 0;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";

                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[thisIvalue][thisJvalue]!=' ')
                                cout << value[thisIvalue][thisJvalue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird+halfColumnOneThird) {
                        int thisIvalue = 0;
                        int thisJvalue = 1;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                        else 
                            cout << " ";
                    }
                    else if(j==columnTwoThird+halfColumnOneThird) {
                        int thisIvalue = 0;
                        int thisJvalue = 2;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird || j==columnTwoThird)
                        cout << "|";
                    else 
                        cout << " ";
                }
                else if(i==(halfRowOneThird+rowOneThird)) {
                    if(j==halfColumnOneThird) {
                        int thisIvalue = 1;
                        int thisJvalue = 0;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";

                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];   
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird+halfColumnOneThird) {
                        int thisIvalue = 1;
                        int thisJvalue = 1;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                            //cout << "_";
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                        else 
                            cout << " ";
                    }
                    else if(j==columnTwoThird+halfColumnOneThird) {
                        int thisIvalue = 1;
                        int thisJvalue = 2;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                            // cout << "_";
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird || j==columnTwoThird) {
                        cout << "|";
                    }
                    else 
                        cout << " ";
                }
                else if(i==rowTwoThird+halfRowOneThird) {
                    if(j==halfColumnOneThird) {
                        int thisIvalue = 2;
                        int thisJvalue = 0;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                            //cout << "_";
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird+halfColumnOneThird) {
                        int thisIvalue = 2;
                        int thisJvalue = 1;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                            //cout << "_";
                        else 
                            cout << " ";
                    }
                    else if (j==columnTwoThird+halfColumnOneThird) {
                        int thisIvalue = 2;
                        int thisJvalue = 2;
                        // if(value[thisIvalue][thisJvalue]!=NULL)
                        //     cout << value[thisIvalue][thisJvalue];
                        // else 
                        //     cout << " ";


                        if(iValue==thisIvalue and jValue==thisJvalue) {
                            if(value[iValue][jValue]!=' ')
                                cout << value[iValue][jValue];
                            else 
                                cout << "_";
                        }
                        else if(value[thisIvalue][thisJvalue]!=' ')
                            cout << value[thisIvalue][thisJvalue];
                            //cout << "_";
                        else 
                            cout << " ";
                    }
                    else if(j==columnOneThird || j==columnTwoThird)
                        cout << "|";
                    else 
                        cout << " ";
                }
                else {
                    if(j==columnOneThird || j==columnTwoThird) 
                        cout << "|";
                    else if(i==rowOneThird || i==rowTwoThird) 
                        cout << "-";
                    else
                        cout << " ";
                } 
            }
            cout << endl;
        }
        //inputValue[iValue][jValue]=0;
        logic();
        input();
    }
}

int main() {
    for(int i = 0; i < 3; ++i) {
        inputValue[i].resize(3);
        for(int j = 0; j < 3; ++j) 
            inputValue[i][j] = 0;
    }
    inputValue[0][0] = 1;
    for(int i = 0; i < 3; ++i) {
        value[i].resize(3);
        for(int j = 0; j < 3; ++j)
            value[i][j] = ' ';
    }
    for(int i = 0; i < 3; ++i) {
        firstPlayerScore[i].resize(3);
        for(int j = 0; j < 3; ++j) {
            firstPlayerScore[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; ++i) {
        secondPlayerScore[i].resize(3);
        for(int j = 0; j < 3; ++j) {
            secondPlayerScore[i][j] = 0;
        }
    }
    // cout << "Hey what's up?" << endl;
    // cout << "Wanna play a game with Evan? ";
    string wish;
    // cin >> wish;
    // if(wish == "yes") {
        cout << "\t\tType 'a' to LEFT\n\t\tType 'd' to RIGHT\n\t\tType 'w' to UP\n\t\tType 's' to DOWN\n\t\tType 'f' to ANS\n\t\tType 'ok' to start\n"; 
        // cout << "Start? ";
        // cin >> wish;
        // if(wish == "ok")
            drawField();
    // }
    // logic();

    //return 0;
}
