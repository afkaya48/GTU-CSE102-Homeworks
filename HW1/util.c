#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){
   int i,first_divisor=0,next;
   
   if(x>y){ //To check first integer is bigger than second integer or not
      printf("There is no any integer between %d and %d can be divided by %d\n",x,y,z);
   }
   else{
   
   for(i=x;i<=y;i++){ //To find the first divisor between two integers
      if(i%z==0){
         first_divisor = i;
         printf("The first integer between %d and %d is %d\n",x,y,first_divisor);
         break;
      }
   }
      if(first_divisor==0 && x!=0){ //To check the divisor is zero or nonzero
         printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
      }
      
      if(z==0){
         printf("The first integer between %d and %d is %d\n",x,y,first_divisor);
      }
   
   }
   return first_divisor;
}

int find_nth_divisible(int n,int f_l, int z){ //To find out how many next we go

   int last = f_l+(n*z);
   return last;

}

int validate_identity_number(char identity_number[]){
   int i=0,control=1;
    
   while(identity_number[i]){ //To find the number of digits
      i++;
   }
   if(i!=11){ //To check The ID Number is 11 digit or not
      control=0;
   }
   
   for(i=0;i<11;i++){ //To chech that each digit is a digit or not
      if(identity_number[i]>=48 && identity_number[i]<=57){
      
   }
   else{
      control=0;
   }
}

   if(identity_number[0]==0){ //To check whether the first digit is zero or nonzero
      control=0;   
   }
   
   int toplam_odd=0,toplam_even=0,result;
   i=0;
   
   while(identity_number[i]){ //To find the sum of numbers in odd digits(1,3,5,7,9)
      toplam_odd+=(int)identity_number[i]-48;
   
      if(i==8){ //To not to go 11th digit
      break;
      }
      i+=2;
   }
   
   i=1;
   
   while(identity_number[i]){ //to find the sum of numbers in even digits(2,4,6,8)
      toplam_even+=(int)identity_number[i]-48; 
      
      if(i==7){ //To not to go 10th digit
      break;
      }
      i+=2;
   }

   result = toplam_odd*7 - toplam_even; //Substraction the sum of digits 2,4,6,8 from 7 times the sum of digits 1,3,5,7,9

   if(result%10!=(int)identity_number[9]-48){ //kontrol et
      control=0;
   }

   i=0;
   int toplam_ten = 0;
   while(identity_number[i]){ //To find the sum of first 10 digits.
      toplam_ten+=(int)identity_number[i]-48;
      if(i==9){ //To not to go 11th digit
      break;
      }
      i++;
   }
   
   if(toplam_ten%10!=(int)identity_number[10]-48){ //kontrol et
      control=0;
   }
   
   
   return control;
   
}

int create_customer(char identity_number[],int password){ //Creating a file which including both ID Number and Password

   FILE *dosya = fopen("customeraccount.txt","w"); 
   fprintf(dosya, "%s, %d",identity_number,password);
   fclose(dosya);

}

int check_login(char identity_number[],int password){
   int passw,control=1;
   char id_number[12];
   FILE *dosya = fopen("customeraccount.txt","r"); //Reading the file
   fscanf(dosya,"%s%d",id_number,&passw); //Gettting the ID Number and Password
   for(int i=0;i<11;i++){ //Checking ID Number is true or invalid
      if((int)identity_number[i]-48!=(int)id_number[i]-48){
         control=0;
         break;
      }
   }
   
   if(password!=passw){ //Checking the Password is true or invalid
      control=0;
   }
   if(control==0){
      printf("Invalid identity number or password\n");
   }
   else{
      printf("Login Successful\n");
   }

   fclose(dosya);
   return control;

}

int withdrawable_amount(float cash_amount){ //Calculating the withdrawable amount for a requested (10,20,50) cash amount
   
   float temp_cash = cash_amount;
   while(temp_cash>=50){ 
      temp_cash = temp_cash-50;
   }
   
   while(temp_cash>=20){
      temp_cash = temp_cash-20;
   }
   
   while(temp_cash>=10){
      temp_cash = temp_cash-10;
   }
   float result = cash_amount-temp_cash;
   
   return result;
   
   return(0);
   
}
