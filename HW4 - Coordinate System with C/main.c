#include <stdio.h>

void print_file(int a,int b,int c);
void drawing_graph(int a,int b,int c);
void graph_txt(int a,int b,int c);
void blue();
void yellow();
void reset();

int main(){
    
    int selection = 0;
    while(selection == 0 || selection == 1 || selection == 2 || selection == 3 || selection == 4){
    printf("Select an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit.\n\nChoice: ");
    scanf("%d",&selection);
    
        if(selection==1){
            int a,b,c;
            printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\n");
            printf("a: ");
            scanf("%d",&a);
            printf("b: ");
            scanf("%d",&b);
            printf("c: ");
            scanf("%d",&c);

            print_file(a,b,c);
        }

        else if(selection==2){
            int a,b,c;
            FILE *fp = fopen("coefficient.txt","r");
            fscanf(fp,"%d",&a);
            fscanf(fp,"%d",&b);
            fscanf(fp,"%d",&c);
            fclose(fp);
            printf("Coeffiecients has been read from the coefficeint.txt file.\n");
            printf("Printing the graph of x=%d*(y*y) + %d*y + %d\n",a,b,c);

            drawing_graph(a,b,c);
            printf("\n");
        }

        else if(selection==3){
            int a,b,c;
            FILE *fp = fopen("coefficient.txt","r");
            fscanf(fp,"%d",&a);
            fscanf(fp,"%d",&b);
            fscanf(fp,"%d",&c);
            graph_txt(a,b,c);
            fclose(fp);
        }

        else if(selection==4){
            printf("Exited from the program.\n");
            break;
        }
        else{
            printf("You have entered wrong choice!! Please enter again!\n");
        }
    } 
}

void print_file(int a,int b,int c){
    int i;
    FILE *fp = fopen("coefficient.txt","w");
    fprintf(fp,"%d\n",a);
    fprintf(fp,"%d\n",b);
    fprintf(fp,"%d",c);
    printf("coefficients.txt file has been created.\n");
    fclose(fp);
}

void drawing_graph(int a,int b,int c){
    int i,j,sonuc;
    int values_y=15;
    int values_x = -50;
    for(i=16;i>=-15;i--){
        printf("\n");
        for(j=-50;j<=51;j++){
            //to draw the graph
            sonuc = a*(i*i)+b*(i)+c;
            if(i==16 && j==0){
                printf("^");
            }
            else if(i==0 && j==-51){
                printf("<");
            }
            else if(i==0 && j==51){
                printf(">");
            }           
            else if(j==sonuc){
            if(i==-1 && j%10==0) {
                if(j>0){
                    blue();
                    printf("#");
                    values_x = values_x + 10;
                }
                else{
                    blue();
                    printf("\b\b#  ");
                    values_x = values_x + 10;
                }
            }
                else{
                    blue();
                    if(i!=16){
                        printf("#");
                    }
                    else{
                        printf(" ");
                    }
                }
            reset();
            }
            //to print y values
            else if(j==-3 && i%5==0){
                if(values_y>0){
                    if(values_y==5){
                    yellow();
                    printf("%d",values_y);
                    values_y-=5;
                    }
                    else{
                    yellow();
                    printf("\b%d",values_y);
                    values_y-=5;            
                    }
                }
                else{
                    if(values_y == 0){
                    printf("-");
                    values_y-=5;
                    }
                    else if(values_y==-5){
                    yellow();
                    printf("\b%d",values_y);
                    values_y-=5;
                    }
                    else{
                    yellow();
                    printf("\b\b%d",values_y);
                    values_y-=5;
                    }
                }
                reset();
            }

            //to print x values
            else if(i==-1 && j%10==0){
                if(values_x>0){
                    yellow();
                    printf("\b\b%d ",values_x);
                    values_x = values_x + 10;
                    }  
                else{
                    yellow();
                    printf("\b\b%d",values_x);
                    values_x = values_x + 10;
                }
                reset();              
            }

            //to draw c axis
            else if(i==0 && j!=0){
                printf("-");
            }

            //to draw y axis
            else if(j==0){
                printf("|");
            }

            //to put space
            else{
                printf(" ");
            }
        }
    }
}

void graph_txt(int a, int b, int c){
            FILE *fp2 = fopen("graph.txt","w");
            int i,j,sonuc;
            char hashtag = '#', perpendiculer_line = '|', space = ' ',next_line = '\n';
                for(i=16;i>=-15;i--){
                    fprintf(fp2,"%c",next_line);
                for(j=-51;j<=51;j++){
                    sonuc = a*(i*i)+b*(i)+c;
                    if(i==16 && j==0){
                        fprintf(fp2,"^");
                    }
                    else if(i==0 && j==-51){
                        fprintf(fp2,"<");
                    }
                    else if(i==0 && j==51){
                        fprintf(fp2,">");
                    }
                    else if(j==sonuc){
                        fprintf(fp2,"%c",hashtag);   
                    }
                    else if(i==0 && j!=0){
                        fprintf(fp2,"-");
                    }
                    else if(j==0){
                        fprintf(fp2,"%c",perpendiculer_line);
                    }
                    else{
                        fprintf(fp2,"%c",space);
                    }
                }
            }
            printf("Coefficients has been read from the coefficient file.\nThe graph of x = %d*(y*y) + %d*(y) + %d has been written to the graph.txt file.",a,b,c);
            fclose(fp2);
        }

void blue () {
  printf("\033[0;34m");
}

void reset () {
  printf("\033[0m");
}

void yellow () {
  printf("\033[1;33m");
}
