#include <stdio.h>
#include "util.h"


int main() {
    // "PART 1"
    printf("PART 1\n");
    int x,y,z,n,password,basamak=0;
    printf("Enter the first integer: ");
    scanf("%d",&x);
    printf("Enter the second integer: ");
    scanf("%d",&y);
    printf("Enter the divisor: ");
    scanf("%d",&z);
    int controlling=1;
    while(controlling==1){ //To check that divisor is zero or nonzero
       if(z==0){
          controlling=1;
          printf("Please enter a non-zero value: ");
          scanf("%d",&z);

       }
       else{
          controlling=0;
       }
    }
    
    
    int first_divisor;
    
    first_divisor=find_divisible(x,y,z);
    
    if(first_divisor!=0 || x==0){ //To find how many next we go
       printf("Enter the number how many next: ");
       scanf("%d",&n);
       int last = find_nth_divisible(n,first_divisor,z);
       if(last<=y){
          printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,last);
       }
       else{
          printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
       }
    }
    // "PART 2"
    printf("PART 2\n");
    char identity_number[11];
    printf("Please enter your ID Number: ");
    scanf("%s",identity_number);
    
    int control = validate_identity_number(identity_number);
    
    while(control==0){ //To check whether the user entered a invalid ID Number
       printf("Please enter a valid ID Number: ");
       scanf("%s",identity_number);
       control = validate_identity_number(identity_number);
    }
    
    printf("Please enter your password: ");
    scanf("%d",&password);
    int temp = password;
    int temp_new = password;
    while(1){ //to check whether the password is 4 digits or not.
       while(temp>0){
       temp = temp/10;
       basamak++;
    }
    if(basamak==4){
       break;
    }
    else{
       printf("Please enter a valid password: ");
       scanf("%d",&temp);
       temp_new=temp;
       basamak=0;
    }
}
 
    create_customer(identity_number,temp_new);
    
    //PART 3
    printf("PART 3\n");
    printf("Please enter your ID Number: ");
    scanf("%s",identity_number);
    printf("Please enter your password: ");
    scanf("%d",&password);
    
    int check = check_login(identity_number,password);
    
    if(check==1){ //If the user logs in successfully, he will be able to withdraw money.
       float cash_amount;
       printf("Enter your withdraw amount: ");
       scanf("%f",&cash_amount);
       int result = withdrawable_amount(cash_amount);
       printf("Withdrawable amount is: %d",result);
       printf("\n");
       
    }
    
    return(0);
}
