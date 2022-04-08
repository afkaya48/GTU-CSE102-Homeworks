#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

/* Provide your implementations for all the requested functions here */
char dt1a(double pl, double pw, double sl, double sw){
    if(pl<2.45){
       return 's';
    }
    else{
       if(pw<1.75){
          if(pl<4.95){
             if(pw<1.65){
                return 'e';
             }
             else{
                return 'i';
             }
          }
          else{
             return 'i';
          }
       }
       else{
          return 'i';
       }
    }
}

char dt1b(double pl, double pw, double sl, double sw){
    if(pl<2.55){
       return 's';
    }
    else{
       if(pw<1.69){
          if(pl<4.85){
             return 'e';
          }
          else{
             return 'i';
          }
       }
       else{
          return 'i';
       }
    }
}

double dt2a(double x1,double x2,double x3,int x4,int x5){
    if(x1<31.5){
       if(x2>-2.5){
          return 5;
       }
       else{
          if(x2-0.1<=x1 && x1<=x2+0.1){
             return 2.1;
          }
          else{
             return -1.1;
          }
       }
    }
    else{
       if(-1<=x3 && x3<=2){
          return 1.4;
       }
       else{
          if(x4 && x5){
             return -2.23;
          }
       }
    }
}

double dt2b(double x1,double x2,double x3,int x4,int x5){
   if(12<x1 && x1<22){
      if(x3>5.0/3.0){
         return -2.0;
      }
      else{
         if(x1-0.1<=x3 && x3<=x1+0.1){
            return 1.01;
         }
         else{
            return -8;int dt3b(int soc,int hap,int fre,int sec,int bra);
         }
      }
   }
   else{
      if(x4 && x5){
         return -1;
      }
      else{
         if(-1<=x2 && x2<=2){
            return -1.0/7.0;
         }
         else{
            return sqrt(2)/3.0;
         }
      }
   }

}

int dt3a(int soc,int hap,int fre,int sec,int bra){
      
      if(soc<6){
         if(sec==1){
            if(fre==1){
               if(bra==1|bra==3|bra==5){return 1;}
               else{return 2;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 3;}
               else{return 4;}
            }
         }
        else if(sec==2){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 9;}
               else{return 10;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 11;}
               else{return 12;}
            }
        }
        else if(sec==3){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 17;}
               else{return 18;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 19;}
               else{return 20;}
            }
        }
        else if(sec==4){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 25;}
               else{return 26;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 27;}
               else{return 28;}
            }
        }
        else if(sec==5){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 33;}
               else{return 34;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 35;}
               else{return 36;}
            }
        }
      }
      else{
         if(sec==1){
            if(fre==1){
               if(bra==1|bra==3|bra==5){return 5;}
               else{return 6;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 7;}
               else{return 8;}
            }
         }
        else if(sec==2){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 13;}
               else{return 14;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 15;}
               else{return 16;}
            }
        }
        else if(sec==3){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 21;}
               else{return 22;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 23;}
               else{return 24;}
               }
            }
        
        else if(sec==4){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 29;}
               else{return 30;}
            }else{
               if(bra==1|bra==3|bra==5){return 31;}
               else{return 32;}
            
        }
        }else if(sec==5){
           if(fre==1){
               if(bra==1|bra==3|bra==5){return 37;}
               else{return 38;}
            }
            else{
               if(bra==1|bra==3|bra==5){return 39;}
               else{return 40;}
        }
    }
  }
}
/////////
int dt3b(int soc,int hap,int fre,int sec,int bra){
        if(soc<6){ 
         if(bra==1|bra==3|bra==5){
            if(sec==1){return 2;}
            
            else if(sec==2){return 10;}
            
            else if(sec==3){return 18;}
            
            else if(sec==4){return 26;}
            
            else if(sec==5){return 34;}
         }
        
         else{
            if(sec==1){return 3;}
            
            else if(sec==2){return 11;}
            
            else if(sec==3){return 19;}
            
            else if(sec==4){return 27;}
            
            else if(sec==5){return 35;}
         }
       }
       else{
            if(bra==1|bra==3|bra==5){
            if(sec==1){return 1;}
            
            else if(sec==2){return 9;}
            
            else if(sec==3){return 17;}
            
            else if(sec==4){return 25;}
            
            else if(sec==5){return 33;}
         }
        
         else{
            if(sec==1){return 2;}
            
            else if(sec==2){return 10;}
            
            else if(sec==3){return 18;}
            
            else if(sec==4){return 26;}
            
            else if(sec==5){return 34;}
         }
       }

}

