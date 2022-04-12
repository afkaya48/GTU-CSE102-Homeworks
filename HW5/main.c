#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int select_type();
int select_calc(int);
int calculate(int(), int());
int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);


enum shapes{Triangle=1, Quadrilateral, Circle, Pyramid, Cylinder};
enum calculators{Area, Perimeter, Volume};

int main(){
    int control = 1;
    while(control == 1){ // to do infinite loop
        control = calculate(select_type,select_calc);
    }
    return 0;
}

int select_type(){
    int num;
    printf("Welcome to the geometric calculator!\nSelect a shape to calculate:\n----------------------------\n");
    printf("1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n");
    printf("5. Cylinder\n0. Exit\n----------------------------\nInput: ");
    scanf("%d",&num);
    int check=1;
    while(check==1){ 
       if(num!=0 && num!=1 && num!=2 && num!=3 && num!=4 && num!=5){ //to check if the input is in the given range
          check=1;
          printf("Please enter [0-5] for valid values: ");
          scanf("%d",&num);
       }
       else{
          check=0;
       }
    }
    enum shapes shape;
    shape = num;
    return shape;
}

int select_calc(int shape){
    int num;
    printf("Select calculator:\n----------------------------\n1. Area\n2. Perimeter\n3. Volume\n0. Exit\n----------------------------\nInput:");
    scanf("%d",&num);
    int check=1;
    while(check==1){  
       if(num!=0 && num!=1 && num!=2 && num!=3){ //to check if the input is in the given range
          check=1;
          printf("Please enter [0-3] for valid values: ");
          scanf("%d",&num);
       }
       else{
          check=0;
       }
    }
    enum calculators calculator;
    calculator = num;
    return calculator;
}

int calculate( int (*type)(), int (*calc)() ){
    int ext1 = (*type)(); 
    int ext2;
    if(ext1!=0){ //to control zero or nonzero
        ext2 = (*calc)();
        if(ext2==0){ // to control exit
            printf("Exited the program!");
            return 0;
        }
        else{
        switch (ext1) {
            case 1:
                calc_triangle(ext2); // triangle process
                return 1;
                break;
            case 2:
                calc_quadrilateral(ext2); // quadrilateral process
                return 1;
                break;
            case 3:
                calc_circle(ext2); // circle process
                return 1;
                break;
            case 4:
                calc_pyramid(ext2); // pyramid process
                return 1;
                break;
            case 5:
                calc_cylinder(ext2); //cylinder process
                return 1;
                break;
            default:
                printf("Error!");
        }
      }
    }
    else{
        printf("Exited the program!");
        return 0;
    }
}

int calc_triangle(int ext2){
    float a,b,c;
    float s,area;
    float perimeter;
    int control = 0, control_2 = 0, control_3 = 0;
    switch(ext2){
        case 1: //area of triangle
        while(control == 0){
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter a valid entry.\n");            
            }
            else if(control_3 == 1){ // checking the triangle condition
                printf("ERROR ! Please enter a valid triangle.\n");
            }
            else{
                printf("Please enter three sides of Triangle: ");
            }
            control = 0, control_2 = 0, control_3 = 0;
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&b) !=1){
                    while ((b = getchar()) != '\n' && b != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(scanf("%f",&c) !=1){
                    while ((c = getchar()) != '\n' && c != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(a<=0 || b<=0 || c<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }
            if(a+b<c || a+c<b || b+c<a){ //the condition for creating a triangle
                control = 0;
                control_3 = 1;
            }
            else{
                s = (a+b+c)/2;
                area = sqrt(s*(s-a)*(s-b)*(s-c)); //finding area process
                printf("area of TRIANGLE: %.2f\n",area);
                control = 1;
            }
        }
            break;
        case 2:
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter a valid entry.\n");            
            }
            else if(control_3 == 1){ // checking the triangle condition
                printf("ERROR ! Please enter a valid triangle.\n");
            }
            else{
                printf("Please enter three sides of Triangle: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&b) !=1){
                    while ((b = getchar()) != '\n' && b != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(scanf("%f",&c) !=1){
                    while ((c = getchar()) != '\n' && c != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(a<=0 || b<=0 || c<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }
            if(a+b<c || a+c<b || b+c<a){ //the condition for creating a triangle
                control = 0;
                control_3 = 1;
            }
            else{
                perimeter = a+b+c; //finding perimeter process
                printf("perimeter of TRIANGLE: %.2f\n",perimeter);
                control = 1;
            }
        }
            break;
        case 3: // to show that there is no volume of triangle
            printf("ERROR ! You cannot calculate the volume of a triangle. Please try again.\n");
            break;
    }
}

int calc_quadrilateral(int ext2){
    float a,b,c,d;
    float s,area;
    float perimeter;
    int control = 0, control_2 = 0;
    switch(ext2){
        case 1: //area of quadrilateral
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter a valid entry. \n");            
            }
            else{
                printf("Please enter four sides of Quadrilateral: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&b) !=1){
                    while ((b = getchar()) != '\n' && b != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(scanf("%f",&c) !=1){
                    while ((c = getchar()) != '\n' && c != EOF); // to check if the user give us a input that is not number
                    control_2= 1; 
                    continue;
                }
                if(scanf("%f",&d) !=1){
                    while ((d = getchar()) != '\n' && d != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(a<=0 || b<=0 || c<=0 || d<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            s = (a+b+c+d)/2;
            area = sqrt((s-a)*(s-b)*(s-c)*(s-d)); //finding area process
            printf("Area of QUADRILATERAL: %.2f\n",area);
            control = 1;
        }
            break;
        case 2:
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter a valid entry\n");            
            }
            else{
                printf("Please enter four sides of Quadrilateral: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&b) !=1){
                    while ((b = getchar()) != '\n' && b != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(scanf("%f",&c) !=1){
                    while ((c = getchar()) != '\n' && c != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&d) !=1){
                    while ((d = getchar()) != '\n' && d != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(a<=0 || b<=0 || c<=0 || d<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            perimeter = a+b+c+d; //finding perimeter process
            printf("Perimeter of QUADRILATERAL: %.2f\n",perimeter);
            control = 1;            
        }
            break;
        case 3: // to show that there is no volume of quadrilateral
            printf("ERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n");
            break;
    }
}

int calc_circle(int ext2){
    float r;
    double area;
    double perimeter;
    int control = 0, control_2 = 0;
    switch(ext2){
        case 1: //area of circle
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter a valid value: \n");            
            }
            else{
                printf("Please enter the radius of Circle: ");
            }
                if(scanf("%f",&r) !=1){
                    while ((r = getchar()) != '\n' && r != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(r<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            area = PI*r*r; //finding area process
            printf("Area of CIRCLE: %.2f\n",area);
            control = 1;
        }
            break;
        case 2:
        while(control == 0){ //harf girme durumunu kontrol et
            if(control_2 == 1){
               printf("ERROR ! Please enter a valid value: \n");            
            }
            else{
                printf("Please enter the radius of Circle: ");
            }
                if(scanf("%f",&r) !=1){
                    while ((r = getchar()) != '\n' && r != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(r<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            perimeter = 2*PI*r; //finding perimeter process
            printf("Perimeter of CIRCLE: %.2f\n",perimeter);
            control = 1;            
        }
            break;
        case 3: // to show that there is no volume of circle
            printf("ERROR ! You cannot calculate the volume of a circle. Please try again.\n");
            break;
    }
}

int calc_pyramid(int ext2){
    float a,l,h;
    float base, lateral;
    float area;
    float volume;
    float perimeter;
    int control = 0, control_2 = 0;
    switch(ext2){
        case 1: //area of pyramid
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the base side and slant height of Pyramid: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&l) !=1){
                    while ((l = getchar()) != '\n' && l != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(a<=0 && l<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            base = a*a;
            lateral = 2*a*l;
            area = base+lateral; //finding area process
            printf("Base Surface Area of a PYRAMID : %.2f\n",base);
            printf("\n");
            printf("Lateral Surface Area of a PYRAMID : %.2f\n",lateral);
            printf("\n");
            printf("Surface Area of PYRAMID: %.2f\n",area);
            control = 1;
        }
            break;
        case 2:
        while(control == 0){
            if(control_2 == 1){
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the base side of Pyramid: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(a<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            perimeter = 4*a; //finding perimeter process
            printf("Perimeter of a PYRAMID: %.2f\n",perimeter);
            control = 1;
            break;
        }
            break;
        case 3:
        while(control == 0){
            if(control_2 == 1){
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the base side and height of Pyramid: ");
            }
                if(scanf("%f",&a) !=1){
                    while ((a = getchar()) != '\n' && a != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&h) !=1){
                    while ((h = getchar()) != '\n' && h != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(a<=0 && h<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            volume = (0.3333333)*a*a*h; //finding volume process
            printf("Volume of a PYRAMID: %.2f\n",volume);
            control = 1;
            break;
        }
    }
}

int calc_cylinder(int ext2){
    float r,h;
    float base, lateral;
    float area;
    float volume;
    float perimeter;
    int control = 0, control_2 = 0;
    switch(ext2){
        case 1: //area of pyramid
        while(control == 0){ 
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the radius and height of Cylinder: ");
            }
                if(scanf("%f",&r) !=1){
                    while ((r = getchar()) != '\n' && r != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&h) !=1){
                    while ((h = getchar()) != '\n' && h != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(r<=0 && h<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            base = PI*r*r;
            lateral = 2*PI*r*h;
            area = 2*PI*r*(r+h); //finding area process
            printf("Base Surface Area of a Cylinder : %.2f\n",base);
            printf("\n");
            printf("Lateral Surface Area of a Cylinder : %.2f\n",lateral);
            printf("\n");
            printf("Surface Area of Cylinder: %.2f\n",area);
            control = 1;
        }
            break;
        case 2:
        while(control == 0){
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the radius and height of Cylinder: ");
            }
                if(scanf("%f",&r) !=1){
                    while ((r = getchar()) != '\n' && r != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&h) !=1){
                    while ((h = getchar()) != '\n' && h != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(r<=0 && h<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            perimeter = 2*PI*r; //finding perimeter process
            printf("Perimeter of a Cylinder : %.2f\n",perimeter);
            control = 1;
        }
            break;
        case 3:
        while(control==0){
            if(control_2 == 1){ //checking for all invalid situations
               printf("ERROR ! Please enter valid entry. \n");            
            }
            else{
                printf("Please enter the radius and height of Cylinder: ");
            }
                if(scanf("%f",&r) !=1){
                    while ((r = getchar()) != '\n' && r != EOF); // to check if the user give us a input that is not number
                    control_2= 1;
                    continue;
                }
                if(scanf("%f",&h) !=1){
                    while ((h = getchar()) != '\n' && h != EOF); // to check if the user give us a input that is not number
                    control_2 = 1;
                    continue;
                }
                if(r<=0 && h<=0){ //to check the numbers is under zero or not
                    control_2 = 1;
                    continue;
                }

            volume = PI*r*r*h; //finding volume process
            printf("Volume of a PYRAMID: %.2f\n",volume);
            control = 1;
            break;
        }
    }
}
