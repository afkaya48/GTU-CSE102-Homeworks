#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {
    int selection;
    while(1){
    /* Ask for the problem selection (1,2,3) .....  */
    printf("(1)Part 1: Flower Desicion Tree\n(2)Part 2: Numbers Tree\n(3)Part 3: Personality and Status Test\nPlease enter a part: ");
    scanf("%d",&selection);
    int check=1;
    while(check==1){ 
       if(selection!=1 && selection!=2 && selection!=3){
          check=1;
          printf("You entered invalid value!\n(1)Part 1: Flower Desicion Tree\n(2)Part 2: Numbers Tree\n(3)Part 3: Personality and Status Test\nPlease enter a part: ");
          scanf("%d",&selection);

       }
       else{
          check=0;
       }
    }
    
    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    if(selection==1){
       double pl,pw,sl,sw;
       char p1_result,p1_result2;
       printf("Please enter PL, PW, SL, SW: ");
       scanf("%lf%lf%lf%lf",&pl,&pw,&sl,&sw);
       p1_result = dt1a(pl,pw,sl,sw);
       p1_result2 = dt1b(pl,pw,sl,sw);
       char s,i,e;
       /* Compare performances and print results */
       if(p1_result == p1_result2){
         if(p1_result=='s'){
            printf("The result of both is Setosa\n");
         }
         else if(p1_result=='i'){
            printf("The result of both is Virginica\n");
         }
         else if(p1_result=='e'){
            printf("The result of both is Versicolor\n");
         }
    }
       else{
         if(p1_result=='s'){
            printf("The result of dt1a is Setosa\n");
         }
         else if(p1_result=='i'){
            printf("The result of dt1a is Virginica\n");
         }
         else if(p1_result=='e'){
            printf("The result of dt1a is Versicolor.\n");
         }
         if(p1_result2=='s'){
            printf("The result of dt1b is Setosa\n");
         }
         else if(p1_result2=='i'){
            printf("The result of dt1b is Virginica\n");
         }
         else if(p1_result2=='e'){
            printf("The result of dt1b is Versicolor.\n");
         }
       }
    }

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    if(selection==2){
        double x1,x2,x3;
        int x4,x5;
        double p2_result,p2_result2;
        printf("Please enter x1, x2, x3: "); /* the trust way of input is mercy */
        scanf("%lf%lf%lf",&x1,&x2,&x3);
        printf("Please enter for x4; (1)TRUE, (0)FALSE: ");
        scanf("%d",&x4);
        printf("Please enter for x5; (1)TRUE, (0)FALSE: ");
        scanf("%d",&x5);
        p2_result = dt2a(x1,x2,x3,x4,x5);
        p2_result2 = dt2b(x1,x2,x3,x4,x5);
        
        /* Compare performances and print results */
        double p2_result12 = p2_result-p2_result2;
        if(p2_result12<0){
           p2_result12 = p2_result12*(-1);
        }
        if(p2_result12<=CLOSE_ENOUGH && p2_result12>0){
           printf("%f",(p2_result+p2_result2)/2);
        }
        if(p2_result == p2_result2){
           printf("The result of both is %.2f\n",p2_result);
     }
        else{
           printf("The result of dt2a is %.2f\n",p2_result);
           printf("The result of dt2b is %.2f\n",p2_result2);
      }        
 
   }
    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */  
    if(selection==3){
    int soc,hap,fre,sec,bra;
        printf("WELCOME TO PERSONALITY and STATUS TEST!\n");
        printf("Please rate your sociability (1-10): "); //sosyallik ölçeği
        scanf("%d",&soc);
        printf("Are you happy with your life? Please rate (1-10): ");
        scanf("%d",&hap);
        printf("Would you like to work a 9 a.m - 5 p.m job(1) or a job with flexible working hours(0): "); //özgür mü stabil mi
        scanf("%d",&fre);
        printf("\n");
        printf("Which of the following describes you more?\n(1)Patience and Practical\n(2)Have an analytical thinking structure\n(3)Excited, Creative and Imaginative\n(4)Helpful and Responsible\n(5)Careful and meticulous\nYour Choice: ");
        scanf("%d",&sec);
        printf("\n");
        printf("Which of the following interest you?\n(1)Solving problems\n(2)Making Fiction or Creating something in mind\n(3)Learning a new language\n(4)Playing an instrument\n(5)Playing strategy games\nYour Choice: ");
        scanf("%d",&bra);
        printf("\n");
        int return_a = dt3a(soc,hap,fre,sec,bra);
        int return_b = dt3b(soc,hap,fre,sec,bra);
        /* Compare performances and print results */
        if(return_a==return_b-1){
               if(return_a==1){printf("Realistic. Left brain is dominant!");}
               else if(return_a==2){printf("Realistic. Right brain is dominant!");}

               else if(return_a==3){printf("Realistic and Independent. Left brain is dominant!");}
               else if(return_a==4){printf("Realistic and Independent. Right brain is dominant!");}

               else if(return_a==9){printf("Researcher. Left brain is dominant!");}
               else if(return_a==10){printf("Researcher. Right brain is dominant!");}
 
               else if(return_a==11){printf("Researcher and Independent. Left brain is dominant!");}
               else if(return_a==12){printf("Researcher and Independent. Right brain is dominant!");}

               else if(return_a==17){printf("Artistic. Left brain is dominant!");}
               else if(return_a==18){printf("Artistic. Right brain is dominant!");}

               else if(return_a==19){printf("Artistic and Independent. Left brain is dominant!");}
               else if(return_a==20){printf("Artistic and Independent. Right brain is dominant!");}
 
               else if(return_a==25){printf("Social. Left brain is dominant!");}
               else if(return_a==26){printf("Social. Right brain is dominant!");}

               else if(return_a==27){printf("Social and Independent. Left brain is dominant!");}
               else if(return_a==28){printf("Social and Independent. Right brain is dominant!");}

               else if(return_a==33){printf("Traditional. Left brain is dominant!");}
               else if(return_a==34){printf("Traditional. Right brain is dominant!");}

               else if(return_a==35){printf("Traditional and Independent. Left brain is dominant!");}
               else if(return_a==36){printf("Traditional and Independent. Right brain is dominant!");}
 
               else if(return_a==5){printf("Realistic and Hiperactive. Left brain is dominant!");}
               else if(return_a==6){printf("Realistic and Hiperactive. Right brain is dominant!");}

               else if(return_a==7){printf("Realistic, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==8){printf("Realistic, Independent and Hiperactive. Right brain is dominant!");}

               else if(return_a==13){printf("Researcher and Hiperactive. Left brain is dominant!");}
               else if(return_a==14){printf("Researcher and Hiperactive. Right brain is dominant!");}

               else if(return_a==15){printf("Researcher, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==16){printf("Researcher, Independent and Hiperactive. Right brain is dominant!");}
 
               else if(return_a==21){printf("Artistic and Hiperactive. Left brain is dominant!");}
               else if(return_a==22){printf("Artistic and Hiperactive. Right brain is dominant!");}
  
               else if(return_a==23){printf("Artistic, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==24){printf("Artistic, Independent and Hiperactive. Right brain is dominant!");}
 
               else if(return_a==29){printf("Social and Hiperactive. Left brain is dominant!");}
               else if(return_a==30){printf("Social and Hiperactive. Right brain is dominant!");}

               else if(return_a==31){printf("Social, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==32){printf("Social, Independent and Hiperactive. Right brain is dominant!");}
            
               else if(return_a==37){printf("Traditional and Hiperactive. Left brain is dominant!");}
               else if(return_a==38){printf("Traditional and Hiperactive. Right brain is dominant!");}

               else if(return_a==39){printf("Traditional, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==40){printf("Traditional,Independent and Hiperactive. Right brain is dominant!");}
               
               if(hap<6){
                  printf(" Not pleased with the life:(\n");
                  return_a++;
               }
               else{
                  printf(" Pleased with the life:)\n");
               } 
        } 
        
        else{
               if(return_a==1){printf("Realistic. Left brain is dominant!");}
               else if(return_a==2){printf("Realistic. Right brain is dominant!");}

               else if(return_a==3){printf("Realistic and Independent. Left brain is dominant!");}
               else if(return_a==4){printf("Realistic and Independent. Right brain is dominant!");}

               else if(return_a==9){printf("Researcher. Left brain is dominant!");}
               else if(return_a==10){printf("Researcher. Right brain is dominant!");}
 
               else if(return_a==11){printf("Researcher and Independent. Left brain is dominant!");}
               else if(return_a==12){printf("Researcher and Independent. Right brain is dominant!");}

               else if(return_a==17){printf("Artistic. Left brain is dominant!");}
               else if(return_a==18){printf("Artistic. Right brain is dominant!");}

               else if(return_a==19){printf("Artistic and Independent. Left brain is dominant!");}
               else if(return_a==20){printf("Artistic and Independent. Right brain is dominant!");}
 
               else if(return_a==25){printf("Social. Left brain is dominant!");}
               else if(return_a==26){printf("Social. Right brain is dominant!");}

               else if(return_a==27){printf("Social and Independent. Left brain is dominant!");}
               else if(return_a==28){printf("Social and Independent. Right brain is dominant!");}

               else if(return_a==33){printf("Traditional. Left brain is dominant!");}
               else if(return_a==34){printf("Traditional. Right brain is dominant!");}

               else if(return_a==35){printf("Traditional and Independent. Left brain is dominant!");}
               else if(return_a==36){printf("Traditional and Independent. Right brain is dominant!");}
 
               else if(return_a==5){printf("Realistic and Hiperactive. Left brain is dominant!");}
               else if(return_a==6){printf("Realistic and Hiperactive. Right brain is dominant!");}

               else if(return_a==7){printf("Realistic, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==8){printf("Realistic, Independent and Hiperactive. Right brain is dominant!");}

               else if(return_a==13){printf("Researcher and Hiperactive. Left brain is dominant!");}
               else if(return_a==14){printf("Researcher and Hiperactive. Right brain is dominant!");}

               else if(return_a==15){printf("Researcher, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==16){printf("Researcher, Independent and Hiperactive. Right brain is dominant!");}
 
               else if(return_a==21){printf("Artistic and Hiperactive. Left brain is dominant!");}
               else if(return_a==22){printf("Artistic and Hiperactive. Right brain is dominant!");}
  
               else if(return_a==23){printf("Artistic, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==24){printf("Artistic, Independent and Hiperactive. Right brain is dominant!");}
 
               else if(return_a==29){printf("Social and Hiperactive. Left brain is dominant!");}
               else if(return_a==30){printf("Social and Hiperactive. Right brain is dominant!");}

               else if(return_a==31){printf("Social, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==32){printf("Social, Independent and Hiperactive. Right brain is dominant!");}
            
               else if(return_a==37){printf("Traditional and Hiperactive. Left brain is dominant!");}
               else if(return_a==38){printf("Traditional and Hiperactive. Right brain is dominant!");}

               else if(return_a==39){printf("Traditional, Independent and Hiperactive. Left brain is dominant!");}
               else if(return_a==40){printf("Traditional,Independent and Hiperactive. Right brain is dominant!");}
               
               if(hap<6){
                  printf(" Not pleased with the life:(\n");
                  return_a++;
               }
               else{
                  printf(" Pleased with the life:)\n");
               } 
               
               if(return_b==1){printf("Realistic. Left brain is dominant!");}
               else if(return_b==2){printf("Realistic. Right brain is dominant!");}
               
               else if(return_b==3){printf("Realistic. and Independent. Right brain is dominant!");}
               else if(return_b==9){printf("Researcher. Left brain is dominant!");}
               
               else if(return_b==10){printf("Researcher. Right brain is dominant!");}
               else if(return_b==11){printf("Researcher and Independent. Left brain is dominant!");}
               
               else if(return_b==17){printf("Artistic. Left brain is dominant!");}
               else if(return_b==18){printf("Artistic. Right brain is dominant!");}
               
               else if(return_b==19){printf("Artistic and Independent. Left brain is dominant!");}
               else if(return_b==25){printf("Social. Left brain is dominant!");}
               
               else if(return_b==26){printf("Social. Right brain is dominant!");}
               else if(return_b==27){printf("Social and Independent. Left brain is dominant!");}
               
               else if(return_b==33){printf("Traditional. Left brain is dominant!");}
               else if(return_b==34){printf("Traditional. Right brain is dominant!");}
               
               else if(return_b==35){printf("Traditional and Independent. Left brain is dominant!");}
               
               if(hap<6){
                  printf(" Not pleased with the life:(\n");
                  return_a++;
               }
               else{
                  printf(" Pleased with the life:)\n");
               } 

        }
  
      
} 
  
         printf("\n");  
}
    return 0;
}
