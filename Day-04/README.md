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


    
 ## C program to enter temperature in celcious and convert it to fahrenheit
   
    #include<stdio.h>  
    void main()
     {
    float a,b;
    printf("enter temperature in C ");
    scanf("%f",&a);
   
    b=(a*(9.0/5.0))+32;
   
    printf("\nc=%f\nF=%f",a,b);
    
     }
