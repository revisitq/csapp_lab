int a[6];
int *p = a; //r13
int *q = a; //rsi
int *r = a; //r14
int i = 0; //r12d

int bomb(void){return 0;}

int  main(void){
L1:
 int *s = p; //rbp
 int val = *s;
 if(val -1 > 5) bomb();
 else{
     i = i+1; //r12d
     if(i==6) goto L3;
     else{
         int j = i;//ebx
         L2:
         if(a[j]==*s) bomb();
         else{
             j = j+1;
             if(j <=5) goto L2;
             else{
                 p = p + 1;
                 goto L1;
             }
         }
     }
 L3:
    int *end = a+6;
    for(int *val=a;val!=end;val++){*val = 7 - *val;}
    long *b = 0x6032d0;
    i = 0;
    goto L7;
    L4:
        long x = *(c+1);
        k = k+1;
        if(a[i]!=k) goto L4;
        else goto L6;
    L5:
        int tmp = 0x6032d0;
    L6:
        b[k] = tmp;
        k = k + 1;
        if(k==6) goto L8;
        else if(a[k]<=1) goto L5;
        else{
            tmp = 0x6032d0;
            goto L4;
        }
    L7:
    if(a[i]<=1) goto L5;
    else{
        int k = 1;
        int *c = 0x6032d0;
        goto L4;
    }
    L8:
    
 return 0;
}