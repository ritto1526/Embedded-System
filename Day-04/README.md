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


    
 ## C program to enter temperature in C and convert it to F
   
    #include<stdio.h>  
    void main()
     {
    float a,b;
    printf("enter temperature in C ");
    scanf("%f",&a);
   
    b=(a*(9.0/5.0))+32;
   
    printf("\nc=%f\nF=%f",a,b);
    
     }


  ## C program to reverse a two digit number
   
    #include<stdio.h>  
    void main()
     {
    int a,b,c;
    printf("enter a two digit number");
    scanf("%d",&a);
   
    b=a%10;
    c=a/10;
    printf("Before-swap:%d\n",a);
    printf("After-swap:%d%d\n",b,c);
    
     }

  ## C program to find the reminder and quotient 
   
    #include<stdio.h>  
    void main()
     {
    int a,b,c,d;
    printf("enter a devisor and divident");
    scanf("%d%d",&a,&b);
   
    c=a/b;
    d=a%b;
    printf("Quotient=%d",c);
    printf("\nReminder=%d\n",d);
    
     }
