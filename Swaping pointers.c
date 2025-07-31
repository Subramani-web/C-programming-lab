#include <stdio.h>

//Function for call by value
void swapvalue(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("inside swapvalue-a:%d,b:%d\n",a,b);
}

//Function for call by reference
void swapRef(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    //swaps actual variables using pointers
}

int main(){
    int x,y;

    printf("Enter two number:");
    scanf("%d %d",&x,&y);

    printf("\n---before swap---\n");
    printf("x:%d,y:%d\n",x,y);
     swapvalue(x,y);
    printf("After swapvalue (call-by-value):x:%d,y:%d\n",x,y);

     swapRef(&x,&y);
    printf("After swapRef(call-by-reference):x:%d,y:%d\n",x,y);

    return 0;
}
