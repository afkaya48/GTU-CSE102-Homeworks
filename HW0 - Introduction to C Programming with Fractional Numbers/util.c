#include <stdio.h>
#include "util.h"

int i,gdc;

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    if(*n==0){ //if the numerator is equal to zero, do nothing
      
    }
       
    if(*n>0 && *d>0){ 
    for(i=1; i<=*n || i<=*d; i++){ //the GDC process and I did the simplification by dividing the numbers by GDC.
       if(*n%i==0 && *d%i==0){
          gdc=i;
          }
       }
    *n = *n/gdc;
    *d = *d/gdc;
    }
    
    if(*n<0 && *d>0){
       *n=*n*(-1); //I multiplied the number by minus to make it easier for the GDC process.
       for(i=1; i<*n || i<*d; i++){ //the GDC process and I did the simplification by dividing the numbers by GDC.
       if(*n%i==0 && *d%i==0){
          gdc=i;
          }
       }
    *n = *n/gdc;
    *d = *d/gdc;
    *n=*n*(-1); //I have reinstated the number by multiplying it by minus again.
    }
    
    if(*n<0 && *d<0){
       *n=*n*(-1); //I multiplied the number by minus to make it easier for the GDC process.
       *d=*d*(-1); //I multiplied the number by minus to make it easier for the GDC process.
       for(i=1; i<*n || i<*d; i++){ //the GDC process and I did the simplification by dividing the numbers by GDC.
       if(*n%i==0 && *d%i==0){
          gdc=i;
          }
       }
    *n = *n/gdc;
    *d = *d/gdc;
    }
    
    if(*n>0 && *d<0){ 
       *d=*d*(-1); //I multiplied the number by minus to make it easier for the GDC process.
       for(i=1; i<*n || i<*d; i++){ //the GDC process and I did the simplification by dividing the numbers by GDC.
       if(*n%i==0 && *d%i==0){
          gdc=i;
          }
       }
    *n = *n/gdc;
    *d = *d/gdc;
    *n=*n*(-1); //I have reinstated the number by multiplying it by minus again.
    } 
    
    if(*d==0){ //if the denominator is equal to zero, indicate that it is undefined.
       printf("UNDEFINED ");
       }  
 
} /* end fraction_div */
