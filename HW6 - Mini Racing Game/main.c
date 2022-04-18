#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(char arr[15][30]);
int dice();
char startGame();
int theGame(char start,char arr[15][30]);
void fillingArray(char arr[15][30]);
void printMap(char arr[15][30]);

void red();
void green();
void blue();
void yellow();
void reset();

int main(){
    char arr[15][30];
    int dicenumber,i,j;
    fillingArray(arr);
    printMap(arr); //mapi çizdim arrayi doldurdum
    srand(time(NULL));
    char first = startGame(); //kim başlayacak onu belirledi
    int result = theGame(first,arr);
    if(result == 1){
        yellow();
        printf("***PLAYER 1 WON THE GAME***");
        reset();
    }
    else{
        yellow();
        printf("***PLAYER 2 WON THE GAME***");
        reset();
    }
    return 0;
}

void fillingArray(char arr[15][30]){ //to fill array and doing process after
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            //to print gamers
            if(i==1 && j==1){arr[i][j]='1';}
            else if(i==3 && j==3){arr[i][j]='2';}

            //to print finish lines
            else if(i==2 && j==1){arr[i][j]='_';}
            else if(i==4 && j==3){arr[i][j]='_';}

            //to print penalty points
            else if(i==1 && j==14){arr[i][j]='X';}
            else if(i==7 && j==28){arr[i][j]='X';}
            else if(i==13 && j==14){arr[i][j]='X';}
            else if(i==3 && j==10){arr[i][j]='X';}
            else if(i==3 && j==18){arr[i][j]='X';}
            else if(i==5 && j==26){arr[i][j]='X';}
            else if(i==10 && j==26){arr[i][j]='X';}
            else if(i==11 && j==10){arr[i][j]='X';}
            else if(i==11 && j==18){arr[i][j]='X';}
            
            // to prints first square
            else if(i==0){arr[i][j]='.';}
            else if(i==14){arr[i][j]='.';}
            else if(j==0){arr[i][j]=':';}
            else if(j==29){arr[i][j]=':';}

            // to prints second square
            else if(i==2 && (j>=2 && j<=27)){arr[i][j]='.';}
            else if(i==12 && (j>=2 && j<=27)){arr[i][j]='.';}
            else if(j==2 && (i>=2 && i<=12)){arr[i][j]=':';}
            else if(j==27 && (i>=2 && i<=12)){arr[i][j]=':';}

            // to prints third square
            else if(i==4 && (j>=4 && j<=25)){arr[i][j]='.';}
            else if(i==10 && (j>=4 && j<=25)){arr[i][j]='.';}
            else if(j==4 && (i>=4 && i<=10)){arr[i][j]=':';}
            else if(j==25 && (i>=4 && i<=10)){arr[i][j]=':';}

            else{arr[i][j]=' ';}
        }        
    }
}

void printMap(char arr[15][30]){ //to print map first
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            //to print gamers
            if(i==1 && j==1){yellow();printf("%c",arr[i][j]);reset();}
            else if(i==3 && j==3){blue();printf("%c",arr[i][j]);reset();}

            //to print finish lines
            else if(i==2 && j==1){green();printf("%c",arr[i][j]);reset();}
            else if(i==4 && j==3){green();printf("%c",arr[i][j]);reset();}

            //to print penalty points
            else if(i==1 && j==14){red();printf("%c",arr[i][j]);reset();}
            else if(i==7 && j==28){red();printf("%c",arr[i][j]);reset();}
            else if(i==13 && j==14){red();printf("%c",arr[i][j]);reset();}
            else if(i==3 && j==10){red();printf("%c",arr[i][j]);reset();}
            else if(i==3 && j==18){red();printf("%c",arr[i][j]);reset();}
            else if(i==5 && j==26){red();printf("%c",arr[i][j]);reset();}
            else if(i==10 && j==26){red();printf("%c",arr[i][j]);reset();}
            else if(i==11 && j==10){red();printf("%c",arr[i][j]);reset();}
            else if(i==11 && j==18){red();printf("%c",arr[i][j]);reset();}
            
            // to prints first square
            else if(i==0){printf("%c",arr[i][j]);reset();}
            else if(i==14){printf("%c",arr[i][j]);reset();}
            else if(j==0){printf("%c",arr[i][j]);reset();}
            else if(j==29){printf("%c",arr[i][j]);reset();}

            // to prints second square
            else if(i==2 && (j>=2 && j<=27)){printf("%c",arr[i][j]);reset();}
            else if(i==12 && (j>=2 && j<=27)){printf("%c",arr[i][j]);reset();}
            else if(j==2 && (i>=2 && i<=12)){printf("%c",arr[i][j]);reset();}
            else if(j==27 && (i>=2 && i<=12)){printf("%c",arr[i][j]);reset();}

            // to prints third square
            else if(i==4 && (j>=4 && j<=25)){printf("%c",arr[i][j]);reset();}
            else if(i==10 && (j>=4 && j<=25)){printf("%c",arr[i][j]);reset();}
            else if(j==4 && (i>=4 && i<=10)){printf("%c",arr[i][j]);reset();}
            else if(j==25 && (i>=4 && i<=10)){printf("%c",arr[i][j]);reset();}

            else{printf("%c",arr[i][j]);reset();}
        }
        printf("\n");        
    }  
}

void printMap2(char arr[15][30]){ //printing map for last draw
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            if(arr[i][j] == '1'){
                yellow();
                printf("%c",arr[i][j]);
                reset();
            }
            else if(arr[i][j] == '2'){
                blue();
                printf("%c",arr[i][j]);
                reset();
            }
            else if(arr[i][j] == 'X'){
                red();
                printf("%c",arr[i][j]);
                reset();
            }
            else if(arr[i][j] == '_'){
                green();
                printf("%c",arr[i][j]);
                reset();
            }
            else{
                printf("%c",arr[i][j]);
            }
        }
        printf("\n");
    }
}

char startGame(){
    char ch;
    int control = 0, control2 = 0, go, go2;
    while(control == 0){
            printf("To start the game, players should dice and decide who is going to start first according to it...\n");
            yellow();
            printf("PLAYER 1... Press ENTER to dice");
            ch=fgetc(stdin);
            go = dice(); //to choose who will start first
            printf("DICE: %d\n",go);
            reset();

            blue();
            printf("PLAYER 2... Press ENTER to dice");
            ch=fgetc(stdin);
            go2 = dice(); //to choose who will start first
            printf("DICE: %d\n",go2);
            reset(); 
        while(control2 == 0){
            if(go == go2){
                printf("Same dice value... Please try again.\n");
                printf("To start the game, players should dice and decide who is going to start first according to it...\n");
                yellow();
                printf("PLAYER 1... Press ENTER to dice");
                ch=fgetc(stdin);
                int go = dice(); //to choose who will start first
                printf("DICE: %d\n",go);
                reset();

                blue();
                printf("PLAYER 2... Press ENTER to dice");
                ch=fgetc(stdin);
                int go2 = dice(); //to choose who will start first
                printf("DICE: %d\n",go2);
                reset();
                if(go!=go2){
                    control = 1;
                    break;
                }
            }
            else{
                control = 1;
                control2 = 1;
            }
        }           
    }
    if(go>go2){
        printf(" *** PLAYER 1 will start the game... ***\n");
        return '1';
    }
    else{
        printf(" *** PLAYER 2 will start the game... ***\n");
        return '2';
    }
}

// it finds out how far to go
int dice(){
    int dice = rand()%6+1;
    return dice;
}

int theGame(char start,char arr[15][30]){
    char temp[15][30];
    int go,go2,i,j,a=1,b=1,c=3,d=3;
    int turn;
    int control3;
    int k = 0;
    while((arr[2][1]!='1') || (arr[4][3]!='2')){
    if(start == '1'){
        char ch;
        int control = 0, control2 = 0;
        while(control == 0){
                yellow();
                printf("PLAYER 1... Press ENTER to dice");
                ch=fgetc(stdin);
                go = dice(); //how many times will the first player go
                printf("DICE: %d\n",go);
                reset();

                blue();
                printf("PLAYER 2... Press ENTER to dice");
                ch=fgetc(stdin);
                go2 = dice(); //how many times will the second player go
                printf("DICE: %d\n",go2);
                reset(); 
            while(control2 == 0){
                if(go == go2){
                    printf("Same dice value... Please try again.\n");
                    yellow();
                    printf("PLAYER 1... Press ENTER to dice");
                    ch=fgetc(stdin);
                    go = dice(); //how many times will the first player go
                    printf("DICE: %d\n",go);
                    reset();

                    blue();
                    printf("PLAYER 2... Press ENTER to dice");
                    ch=fgetc(stdin);
                    go2 = dice(); //how many times will the second player go
                    printf("DICE: %d\n",go2);
                    reset();
                    if(go!=go2){
                        control = 1;
                        break;
                    }
                }
                 else{
                    control = 1;
                    control2 = 1;
                }
            }              
        }
    }
    else{
        char ch;
        int control = 0, control2 = 0;
        while(control == 0){
                blue();
                printf("PLAYER 2... Press ENTER to dice");
                ch=fgetc(stdin);
                go2 = dice(); //how many times will the second player go
                printf("DICE: %d\n",go2);
                reset();
                yellow();
                printf("PLAYER 1... Press ENTER to dice");
                ch=fgetc(stdin);
                go = dice(); //how many times will the first player go
                printf("DICE: %d\n",go);
                reset(); 
            while(control2 == 0){
                if(go == go2){
                    printf("Same dice value... Please try again.\n");
                    blue();
                    printf("PLAYER 2... Press ENTER to dice");
                    ch=fgetc(stdin);
                    go2 = dice(); //how many times will the second player go
                    printf("DICE: %d\n",go2);
                    reset();

                    yellow();
                    printf("PLAYER 1... Press ENTER to dice");
                    ch=fgetc(stdin);
                    go = dice(); //how many times will the first player go
                    printf("DICE: %d\n",go);
                    reset();
                    if(go!=go2){
                        control = 1;
                        break;
                    }
                }
                 else{
                    control = 1;
                    control2 = 1;
                }
            }              
        }
    } // the game is starting really
    //first player
    if(a==1 && b!=28){
        if(b+go == 14){
            yellow();
            printf("Penalty for player 1...\n");
            reset();
            if(b==12){
                arr[a][12] = arr[a][b];
                b=12;
            }
            else{
                arr[a][12] = arr[a][b];
                arr[a][b] = ' '; 
                b=12;
            } 
        }
        else if(b+go<29){
            arr[a][b+go] = arr[a][b];
            arr[a][b] = ' ';
            b = b+go;
        }
        else if(b+go>28){
            turn = 28-b; 
            arr[a][b+turn] = arr[a][b];
            arr[a][b] = ' ';
            b = b+turn; 
            arr[a+(go-turn)][b] = arr[a][b]; 
            arr[a][b] = ' ';
            a = a+(go-turn);
        }
    }

    else if(b==28 && a!=13){
        if(a+go==7){
            yellow();
            printf("Penalty for player 1...\n");
            reset();
            if(a==5){
                arr[5][b] = arr[a][b];
                a=5;
            }
            else{
                arr[5][b] = arr[a][b];
                arr[a][b] = ' ';
                a=5;
            }
        }
        else if(a+go<14){
            arr[a+go][b] = arr[a][b];
            arr[a][b] = ' ';
            a = a+go;
        }
        else if(a+go>13){
            turn = 13-a;
            arr[a+turn][b] = arr[a][b];
            arr[a][b] = ' ';
            a = a + turn;
            arr[a][b-(go-turn)] = arr[a][b];
            arr[a][b] = ' ';
            b = b-(go-turn);
        }
    }

    else if(a==13 && b!=1){
        if(b-go == 14){
            yellow();
            printf("Penalty for player 1...\n");
            reset();
            if(b==16){
                arr[a][16] = arr[a][b];
                b=16;
            }
            else{
                arr[a][16] = arr[a][b];
                arr[a][b] = ' ';
                b=16;
            }
        }
        else if(b-go>0){ //sıkıntı yok burada
            arr[a][b-go] = arr[a][b];
            arr[a][b] = ' ';
            b = b-go;
        }
        else if(b-go<1){
            turn = b-1;
            arr[a][b-turn] = arr[a][b]; //b=4 turn=3
            arr[a][b] = ' ';
            b = b-turn; //b=1 
            arr[a-(go-turn)][b] = arr[a][b]; 
            arr[a][b] = ' ';
            a = a-(go-turn);
        }
    }

    else if(b==1){
        if(a-go>2){
            arr[a-go][b] = arr[a][b];
            arr[a][b] =' ';
            a = a-go;
        }
        else if(a-go<=2){//1. oyuncu erken ulaşırsa return değeri atanır
            if(a-go==2){
                turn = a-2; 
                arr[a-turn][b] = arr[a][b];
                arr[a][b] = ' ';
                a = a-turn;
                control3 = 1;
            }
            else{
                turn = a-1; 
                arr[a-turn][b] = arr[a][b];
                arr[a][b] = ' ';
                a = a-turn; 
                arr[a][b+(go-turn)] = arr[a][b]; 
                arr[a][b] = ' ';
                b = b+(go-turn);
                control3 = 1;
            }
            
        }
    }
    //second player
    if(c==3 && d!=26){
        if(d+go2==10){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(d==8){
                arr[c][8] = arr[c][d];
                d=8;
            }
            else{
                arr[c][8] = arr[c][d];
                arr[c][d] = ' '; 
                d=8;
            } 
        }
        else if(d+go2==18){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(d==16){
                arr[c][16] = arr[c][d];
                d=16;
            }
            else{
                arr[c][16] = arr[c][d];
                arr[c][d] = ' '; 
                d=16;
            } 
        }
        else if(d+go2<27){
            arr[c][d+go2] = arr[c][d];
            arr[c][d] = ' ';
            d = d+go2;
        }
        else if(d+go2>26){
            turn = 26-d; 
            arr[c][d+turn] = arr[c][d];
            arr[c][d] = ' ';
            d = d+turn;
            if((c+go2-turn)==5){
                blue();
                printf("Penalty for player 2...\n");
                reset(); 
                arr[3][d] = arr[c][d];
                c=3;
            }
            else{
                arr[c+(go2-turn)][d] = arr[c][d]; 
                arr[c][d] = ' ';
                c = c+(go2-turn);
            }
        }
    }

    else if(d==26 && c!=11){
        if(c+go2==5){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(c==3){
                arr[3][d] = arr[c][d];
                c=3;
            }
            else{
                arr[3][d] = arr[c][d];
                arr[c][d] = ' ';
                c=3;
            }
        }
        else if(c+go2==10){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(c==8){
                arr[8][d] = arr[c][d];
                c=8;
            }
            else{
                arr[8][d] = arr[c][d];
                arr[c][d] = ' ';
                c=8;
            }
        }
        else if(c+go2<12){
            arr[c+go2][d] = arr[c][d];
            arr[c][d] = ' ';
            c = c+go2;
        }
        else if(c+go2>11){
            turn = 11-c;
            arr[c+turn][d] = arr[c][d];
            arr[c][d] = ' ';
            c = c + turn;
            arr[c][d-(go2-turn)] = arr[c][d];
            arr[c][d] = ' ';
            d = d-(go2-turn);
        }
    }

    else if(c==11 && d!=3){
        if(d-go2==10){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(d==12){
                arr[c][12] = arr[c][d];
                d=12;
            }
            else{
                arr[c][12] = arr[c][d];
                arr[c][d] = ' ';
                d=12;
            }
        }
        else if(d-go2==18){
            blue();
            printf("Penalty for player 2...\n");
            reset();
            if(d==20){
                arr[c][20] = arr[c][d];
                d=20;
            }
            else{
                arr[c][20] = arr[c][d];
                arr[c][d] = ' ';
                d=20;
            }
        }
        else if(d-go2>2){
            arr[c][d-go2] = arr[c][d];
            arr[c][d] = ' ';
            d = d-go2;
        }
        else if(d-go2<3){
            turn = d-3;
            arr[c][d-turn] = arr[c][d]; 
            arr[c][d] = ' ';
            d = d-turn;
            arr[c-(go2-turn)][d] = arr[c][d]; 
            arr[c][d] = ' ';
            c = c-(go2-turn);
        }
    }

    else if(d==3){
        if(c-go2>4){
            arr[c-go2][d] = arr[c][d];
            arr[c][d] =' ';
            c = c-go2;
        }
        else if(c-go2<=4){
            if(c-go2==4){
                turn=c-4; 
                arr[c-turn][d] = arr[c][d];
                arr[c][d] = ' ';
                c  = c-turn; 
                control3 = 2;
            }
            else if(c-go2==3){
                arr[c-go2][d] = arr[c][d];
                arr[c][d] =' ';
                c = c-go2;
                control3 = 2;
            }
            else{
                turn = c-3; 
                arr[c-turn][d] = arr[c][d];
                arr[c][d] = ' ';
                c = c-turn; 
                arr[c][d+(go2-turn)] = arr[c][d]; 
                arr[c][d] = ' ';
                d = d+(go2-turn);
                control3 = 2;
            }
        }
    }

    //printing the map
    printMap2(arr);

    if(control3 == 1){ //to check if number 1 is on last line
        if(a==2 && b==1){
            arr[2][1]='1';
        }
        return 1;
        break;
    }
    else if(control3 == 2){ //to check if number 2 is on last line
        if(c==4 && d==3){
            arr[4][3]='2';
        }
        return 2;
        break;
    }
    else{
        continue;
    }
  }
}

// colour codes
void red () {
    printf("\033[1;31m");
}

void green () {
    printf("\033[0;32m");
}

void blue(){
    printf("\033[0;34m");
}

void yellow(){
    printf("\033[0;33m");
}

void reset () {
    printf("\033[0m");
}