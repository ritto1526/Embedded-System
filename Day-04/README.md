 ## C program to input number to two variables and swap them without using 3rd variable 
   
    #include<stdio.h>  
    void main()
    {
    int a,b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);

    a=a+b;
    b=a-b;
    a=a-b;

    printf("\na=%d \nb=%d",a,b);
    
    }


    
