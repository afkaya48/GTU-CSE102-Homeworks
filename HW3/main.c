#include <stdio.h>
#include <math.h>

int sum(int n1,int n2, int flag);
int multi(int n1, int n2, int flag);

int isprime(int a);

void write_file();
void sort_file();
void print_file();

void cons();

int main() {
    
    int selection =0;
    while(selection==1 || selection == 2 || selection ==3 || selection ==4 || selection ==9 || selection == 0){
    printf("Select operation\n1. Calculate sum/multiplication between two numbers\n2. Calculate prime numbers\n3. Show number sequence in file\n4. Sort number sequence in file\n9. Exit\nYour Choice: ");
    scanf("%d",&selection);
    
    int sum_multi,num_1,num_2,flag,result;
    if(selection == 1){
       int temp, control = 1;
       printf("Please enter '0' for sum, '1' for multiplication: ");
       scanf("%d",&sum_multi);
       //to check sum 
       if(sum_multi==0){
          printf("Please enter '0' to work on even numbers, '1' to work on odd numbers: ");
          scanf("%d",&flag);
          switch(flag) {
             case 0 :
             printf("Please enter two different number: ");
             scanf("%d%d",&num_1,&num_2); 
             if(num_1>num_2){ //if the first number is greater then the second number, it changes
                temp = num_1;
                num_1 = num_2;
                num_2 = temp;
             }
             if(num_2-num_1==1 || num_2==num_1){ //if the difference between the numbers is 1 or 0, it will not return result
                printf("No result!!!");
                control = 0;
                break;
             }
             result = sum(num_1,num_2,flag);
             break;
             case 1 :
             printf("Please enter two different number: ");
             scanf("%d%d",&num_1,&num_2);
             if(num_1>num_2){ //if the first number is greater then the second number, it changes
                temp = num_1;
                num_1 = num_2;
                num_2 = temp;
             }
             if(num_2-num_1==1 || num_2==num_1){ //if the difference between the numbers is 1 or 0, it will not return result
                printf("No result!!!");
                control = 0;
                break;
             }
             result = sum(num_1,num_2,flag);
             break;
             default : 
             printf("You have given the wrong order, please enter it again: ");
             control = 0; 
       }      
          
       }
       //to check multi
       else{
          printf("Please enter '0' to work on even numbers, '1' to work on odd numbers: ");
          scanf("%d",&flag);
          switch(flag) {
             case 0 :
             printf("Please enter two different number: ");
             scanf("%d%d",&num_1,&num_2);
             if(num_1>num_2){ //if the first number is greater then the second number, it changes
                temp = num_1;
                num_1 = num_2;
                num_2 = temp;
             }
             if(num_2-num_1==1 || num_2==num_1){ //if the difference between the numbers is 1 or 0, it will not return result
                printf("No result!!!");
                control = 0;
                break;
             }
             result = multi(num_1,num_2,flag);
             break;
             case 1 :
             printf("Please enter two different number: ");
             scanf("%d%d",&num_1,&num_2);
             if(num_1>num_2){ //if the first number is greater then the second number, it changes
                temp = num_1;
                num_1 = num_2;
                num_2 = temp;
             }
             if(num_2-num_1==1 || num_2==num_1){ //if the difference between the numbers is 1 or 0, it will not return result
                printf("No result");
                control = 0;
                break;
             }
             result = multi(num_1,num_2,flag);
             break;
             default : 
             printf("You have given the wrong order, please enter it again: "); 
             control = 0;
       }
        
      }
      if(control == 1){
         write_file(result);
      }
       
       printf("\n");
    }
    
    else if(selection == 2){
       int a,i;
       printf("Please enter an integer: ");
       scanf("%d",&a);
       
       for(i=2;i<a;i++){ //we take the prime numbers here have them checked in the function
       int divisor = isprime(i);
       if(divisor == 0){
          printf("%d is a prime number.\n",i);
       }
       else{
          printf("%d is not a prime number, it is dividible by %d\n",i,divisor);
       }
      
       }
       
       printf("\n");
    }
    
    else if(selection == 3){
       
       print_file();
       
    }  
    
    else if(selection == 4){
      
       sort_file();
       
    }
    
    else if(selection == 9 ){
       printf("Exited from the program.\n");
       break;
    }  
  }  
    return 0;
}


int sum(int n1,int n2, int flag){ // we are finding the sum of numbers
    int i,sum=0;
    
    if(n1%2==0){ 
       if(flag == 0){ 
          for(i=n1+2;i<n2;i+=2){ 
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("+ ");}
             sum = sum+i;
          }
       }
       else{ 
          for(i=n1+1;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("+ ");}
             sum = sum+i;
          }
       }
    }
    else{ 
       if(flag == 0){ 
          for(i=n1+1;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("+ ");}
             sum = sum+i;
          }
       }
       else{ 
          for(i=n1+2;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("+ ");}
             sum = sum+i;
          }
       }
    }
    
    printf("= %d\n",sum);
    return sum;
  
}



int multi(int n1,int n2, int flag){ //multiplication of numbers is happening here
   int i,multi=1;
   
  
    if(n1%2==0){ 
       if(flag == 0){ 
          for(i=n1+2;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("* ");}
             multi = multi*i;
          }
       }
       else{ 
          for(i=n1+1;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("* ");}
             multi = multi*i;
          }
       }
    }
    else{ 
       if(flag == 0){ 
          for(i=n1+1;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("* ");}
             multi = multi*i;
          }
       }
       else{ 
          for(i=n1+2;i<n2;i+=2){
             printf("%d ",i);
             if(i+2==n2 || i+1==n2){}
             else{printf("* ");}
             multi = multi*i;
          }
       }
    }
    
    printf("= %d\n",multi);
    return multi;
    
}



int isprime(int a){ //checking the number prime or not

int divisor;
int i,flag=0;
if (a == 0 || a == 1)
    flag = 1;

  for (i = 2; i <= sqrt(a); ++i) {
    if (a % i == 0) {
      flag = 1;
      divisor = i;
      break;
    }
  }

  if (flag == 0){
    return flag; //0
    }
  else{
    return divisor; //divisor
    }  
    
}
    
       
    
  
  
void write_file(int number){ //
       
       FILE *dosya = fopen("result.txt","a");
       fprintf(dosya,"%d ",number);
       if(dosya!=NULL){
          printf("The result is written to the result.txt file. ");
       
       }
       fclose(dosya);   

}

void sort_file(){ //This is where the 3 by 3 sorting process
       
       int i,num,num2,num3,temp=99999999,temp1=0,temp2=0,temp3=-99999999,min1=0,min2=0,min3=0;
       
       FILE *dosya2 = fopen("temp.txt","w");
       FILE *fp = fopen("result.txt","r");
       FILE *dosya = fopen("result.txt","r");
       
       int counter=0;
       while(fscanf(dosya,"%d",&num)==1){
          counter++;
       }
       fclose(dosya);
       
       // 15 16 28 40 52 58 85 220 520
       
       for(i=1;i<=counter/3;i++){
           temp = 99999999;
           fp = fopen("result.txt","r");
           while(fscanf(fp,"%d",&num)==1){ //58 15 28 520 220 52 40 85 16
             if(num>temp3){
                if(temp<num){
                   min1 = temp;
                }
                else{
                   min1 = num;
                   temp = num;
                }
              }	       
            }
           
           fclose(fp);
           fp = fopen("result.txt","r");
           temp = 99999999;
           while(fscanf(fp,"%d",&num)==1){ //25 48 10 96 150 78
             if(num>temp3){
               if(num!=min1){
                  if(temp<num){
                   min2 = temp;
                }
                else{
                   min2 = num;
                   temp = num;
                }
               }
                
              }  	       
            } 
           fclose(fp);
           fp = fopen("result.txt","r");
           temp = 99999999;
           while(fscanf(fp,"%d",&num)==1){ //25 48 10 96 150 78
             if(num>temp3){ 
               if(num!=min1 && num!=min2){
               if(temp<num){
                   min3 = temp;
                }
                else{
                   min3 = num;
                   temp = num;
                }
               } 
                
              }  	       
            }
          fclose(fp);     
          temp1 = min1;
          temp2 = min2;
          temp3 = min3;
          
          
          fprintf(dosya2,"%d ",min1);
          fprintf(dosya2,"%d ",min2);    
          fprintf(dosya2,"%d ",min3); 
          
            
  }
  fclose(dosya2);
  cons(counter);
  int number;
  FILE *fp4 = fopen("temp.txt","r");
  FILE *fp3 = fopen("result.txt","w");
  while(fscanf(fp4,"%d",&number)==1){ //i have transferred the sorted numbers in the temp.txt to result.txt
     fprintf(fp3,"%d ",number);
     printf("%d ",number);
  }
  printf("\n");
  fclose(fp4);
  fclose(fp3);
  
}

void cons(int counter){ //After sorting 3 by 3, it helps to sort the consecutive numbers.

if(counter%3==1){
int num,num2;
FILE *dosya2 = fopen("temp.txt","a");
      int control = 0;
      int new_temp;
      
      FILE *sea = fopen("result.txt","r");
      FILE *fp2 = fopen("temp.txt","r");
      int i = 0;

      while(fscanf(sea,"%d",&num)==1){ //520 15 28 58 
      i = 0;
      fp2 = fopen("temp.txt","r");
      control = 0;
         while(fscanf(fp2,"%d",&num2)==1){ //15 28 58
         
            if(num==num2){
               control = 1;
            }
         }
         fclose(fp2);
         if(control==0){
            new_temp = num;
         }
       }

      fclose(sea);
      
      fprintf(dosya2,"%d ",new_temp);

fclose(dosya2);
}

else if(counter%3==2){
int num,num2;
FILE *dosya2 = fopen("temp.txt","a");
      int control = 0;
      int new_temp=0,new_temp2;
      
      FILE *sea = fopen("result.txt","r");
      FILE *fp2 = fopen("temp.txt","r");
      int i = 0;

      while(fscanf(sea,"%d",&num)==1){ //25 48 96 841 10 152 5 520
      i = 0;
      fp2 = fopen("temp.txt","r");
      control = 0;
         while(fscanf(fp2,"%d",&num2)==1){ //5 10 25 48 96 152 
         
            if(num==num2){
               control = 1;
            }
         }
         fclose(fp2);
         if(control==0){
            if(new_temp==0){
               new_temp = num;
               printf("%d ",new_temp);
            }
            else{
               new_temp2 = num;
               printf("%d ",new_temp2);
            }
         }
       }
       if(new_temp>new_temp2){
          fprintf(dosya2,"%d %d",new_temp2,new_temp);
       }
       else{
          fprintf(dosya2,"%d %d",new_temp,new_temp2);
       }
      

      fclose(sea);
      
 
fclose(dosya2);

  }

}
      

void print_file(){ //Prints the number in the file to the terminal

       int number;
       FILE *dosya = fopen("result.txt","r");
       while(fscanf(dosya,"%d",&number) == 1){
       printf("%d ",number);
       
       }
       
       fclose(dosya);
       

}
    
  
    
    

