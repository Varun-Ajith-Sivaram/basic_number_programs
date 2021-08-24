#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void check_prime();
int is_prime(int);
void display_factor(int);
void factor();
void num_reverse();
void digit_sum();
void check_palindrome();
int reverse(int);
void check_armstrong();
int armstrong(int);
void find_power();
void round_ceil();
void round_floor();
void digit_count();
void check_perfect();
int factor_sum(int);
void find_factorial();
double factorial(int);

int i,ch,num;

void main()
{
    printf("\tImplementation of some basic programs with numbers\n");
    
    do{
        printf("\n Operations Available: \n\n");
        printf("   1.Check prime or not\n");
        printf("   2.Check armstrong or not\n");
        printf("   3.Check perfect or not\n");
        printf("   4.Check palindrome or not\n");
        printf("   5.Reverse a number\n");
        printf("   6.Factorial of a number\n");
        printf("   7.Factors of a number\n");
        printf("   8.Sum of digits of a number\n");
        printf("  9.Power of a number\n");
        printf("  10.Count of digits in a number\n");
        printf("  11.Round up the number to nearest integer(ceil)\n");
        printf("  12.Round down the number to nearest integer(floor)\n");
        printf("  13.Exit\n");
        
        printf("\n   Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: check_prime();
                    break;
            
            case 2: check_armstrong();
                    break;
                    
            case 3: check_perfect();
                    break;
            
            case 4: check_palindrome();
                    break;
                    
            case 5: num_reverse();
                    break;
                    
            case 6: find_factorial();
                    break;
                    
            case 7: factor();
                    break;
                    
            case 8: digit_sum();
                    break;
                    
            case 9: find_power();
                     break;
                    
            case 10: digit_count();
                     break;
                    
            case 11: round_ceil();
                     break;
                     
            case 12: round_floor();
                     break;
                    
            case 13: printf("\n   --> Exited the program\n");
                     break;
            
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
        
    }while(ch!=13);
}

void check_prime()
{
    // Prime numbers are numbers that are only divisible by 1 and the number itself.
    // 0 and 1 are neither prime nor composite.
    
    int condition=1,flag=0;
    
    while(condition)
    {
        printf("\n   Enter a positive integer: ");
        scanf("%d",&num);
    
        if(num == 0 || num == 1)
            printf("\n\t   --> %d is neither prime nor composite\n",num);
        
        else if(num < 0)
        {
            printf("\n\t   -->Invalid, Enter a positive integer!!\n");
            condition = 1;
            continue;
        }    
    
        else
        {
            for(i=2;i<=num/2;i++)
            {
                if(num%i == 0)
                {
                    flag++;
                    break;
                }
            }
        
            if(flag == 0)
                printf("\n\t   --> %d is a prime number\n",num);
        
            else
                printf("\n\t   --> %d is a composite number\n",num);
        }
        
        condition = 0;
    }
}

void factor()
{
    /* Factor is a number that divides another number exactly and without
       leaving a remainder.
       A prime number has only two factors: 1 and the number itself.*/
    
    int condition=1;
    
    while(condition)
    {
        printf("\n   Enter a non-zero integer: ");
        scanf("%d",&num);
        
        if(num == 0  || num == 1 || num == -1)
        {
            switch(num)
            {
                case 0: printf("\n\t   --> Invalid, Enter a non-zero integer!!\n");
                        condition = 1;
                        continue;
                        
                case 1: printf("\n\t   --> Factor of 1: 1\n");
                        break;
                        
                case -1: printf("\n\t   --> Factors of -1: 1, -1\n");
                         break;
            }
            
        }
        
        else if(num > 1 && is_prime(num) == 1)  //+ve  prime number 
        {
            printf("\n\t   --> Factors of %d: 1, %d\n",num,num);
        }
        
        else if(num > 1 && is_prime(num) == 0)  //+ve composite number
        {
            printf("\n\t   --> Factors of %d: 1, ",num);
            display_factor(num);
            printf("%d\n",num);
        }
        
        else if(num < -1)  //-ve numbers
        {
            printf("\n\t   --> Factors of %d: -1, 1, ",num);
            display_factor(num);
            printf("%d, %d\n",num,abs(num));
            
        }
        
        condition = 0;
    }
    
}

int is_prime(int n)
{
    int flag=0;
    
    for(i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            flag++;
            break;
        }
    }
    
    if(flag == 0)
        return 1;
    
    else
        return 0;
}

void display_factor(int a)
{
    int n = abs(a);
    
    if(a>0)
    {
        for(i=2;i<=n/2;i++)
        {
            if(n%i == 0)
            {
                printf("%d, ",i);
            }
        }
    }
    
    else
    {
        for(i=2;i<=n/2;i++)
        {
            if(n%i == 0)
            {
                printf("%d, %d, ",-i,i);
            }
        }
    }
}

void num_reverse()
{
    int n, rev = 0;
    
    printf("\n   Enter an integer: ");
    scanf("%d",&num);
    
    printf("\n\t   --> Number: %d\n",num);
    
    
    
    if(num>0)
    {
        while(num!=0)
        {
            n = num%10;
            rev = rev*10 + n;
            num = num/10;
        }
        
        printf("\n\t   --> Reverse of number: %d\n",rev);
    }
    
    else
    {
        int a = abs(num);
        
        while(a!=0)
        {
            n = a%10;
            rev = rev*10 + n;
            a = a/10;
        }
        
        printf("\n\t   --> Reverse of number: %d\n",-rev);
    }
}

void check_palindrome()
{
    int condition=1;
    
    while(condition)
    {
        printf("\n   Enter a positive integer: ");
        scanf("%d",&num);
        
        if(num<0)
        {
            printf("\n\t   --> Invalid, Enter a positive integer!!\n");
            condition = 1;
            continue;
        }
        
        int rev = reverse(num);
        
        if(num == rev)
            printf("\n\t   --> %d is a palindrome number\n",num);
            
        else
            printf("\n\t   --> %d is not a palindrome number\n",num);
        
        condition=0;
    }
}

int reverse(int a)
{
    int n,rev=0;
    
    while(a!=0)
    {
        n = a%10;
        rev = rev*10 + n;
        a = a/10;
    }
    
    return(rev);
}

void check_armstrong()
{
    /*Armstrong number is a number equal to the sum of the cubes of its digits.
    Eg: 0, 1, 153, 370, 371, 407*/
    
    int condition=1;
    
    while(condition)
    {
        printf("\n   Enter a positive integer: ");
        scanf("%d",&num);
        
        if(num<0)
        {
            printf("\n\t   --> Invalid, Enter a positive integer!!\n");
            condition = 1;
            continue;
        }
        
        int arm = armstrong(num);
        
        if(num == arm)
            printf("\n\t   --> %d is an armstrong number\n",num);
            
        else
            printf("\n\t   --> %d is not an armstrong number\n",num);
        
        condition=0;
    }
}

int armstrong(int a)
{
    int n,sum=0;
    
    while(a!=0)
    {
        n = a%10;
        sum = sum + pow(n,3);
        a = a/10;
    }
    
    return(sum);
}

void find_power()
{
    double base,expo;
    
    printf("\n   Enter a number: ");
    scanf("%lf",&base);
        
    printf("\n   Enter the power to which the number is to be raised(exponent): ");
    scanf("%lf",&expo);
    
    printf("\n\t   --> Result of %lf^%lf =  %e\n",base,expo,pow(base,expo));
}

void round_ceil()
{
    double number;
    
    printf("\n   Enter a number: ");
    scanf("%lf",&number);
    
    num = ceil(number);
    
    printf("\n\t   --> Result after rounding up the number to nearest integer: %d\n",num);
}

void round_floor()
{
    double number;
    
    printf("\n   Enter a number: ");
    scanf("%lf",&number);
    
    num = floor(number);
    
    printf("\n\t   --> Result after rounding down the number to nearest integer: %d\n",num);
}

void digit_sum()
{
    int n,digits,condition=1,sum=0;
    
    while(condition)
    {
        printf("\n   Enter the no. of digits in the number (including sign for -ve numbers): ");
        scanf("%d",&digits);
    
        getchar();
    
        char number[digits+1];
    
        printf("\n   Enter the integer: ");
        fgets(number,digits+1,stdin);
        
        int length = strlen(number);
        
        if(digits != length)
        {
            printf("\n\t   --> Invalid, No. of digits in the number does not match the user's previous input!!\n");
            condition=1;
            continue;
        }
        
        printf("\n\t   --> Number: %s\n",number);
        
        if(number[0]=='-')
            i=1;
        else
            i=0;
        
        for(i;number[i]!='\0';i++)
        {
            n = number[i] - 48;   
            sum += n;
        }
        
        printf("\n\t   --> Sum of digits of the number: %d\n",sum);
        
        condition=0;
    }
}

void digit_count()
{
    int n,digits,condition=1,count=0;
    int max_size=30;
    
    while(condition)
    {
        char number[max_size];
    
        printf("\n   Enter an integer(with not more than 30 digits, including sign of -ve numbers): ");
        scanf("%s",number);
        
        int length = strlen(number);
        
        if(length > max_size)
        {
            printf("\n\t   -->Inputted number too large, max. length shall not exceed 30!!\n");
            condition=1;
            continue;
        }
        
        printf("\n\t   --> Number: %s\n",number);
        
        if(number[0] == '-')
            length -= 1;
            
        printf("\n\t   --> Count of digits: %d\n",length);
        
        condition=0;
    }
}

void check_perfect()
{
    /*Perfect number is a positive integer that is equal to the sum of its positive
      divisors, excluding the number itself.
      Eg: 6, 28, 496, 8128, 33550336
      A prime number can never be a perfect number.*/
    
    int condition=1;
    
    while(condition)
    {
        printf("\n   Enter a positive integer: ");
        scanf("%d",&num);
        
        if(num < 0)
        {
            printf("\n\t   --> Invalid, Enter a positive integer!!\n");
            condition = 1;
            continue;
        }
        
        if(num == 0 || num == 1)
        {
            printf("\n\t   --> %d is not a perfect number\n",num);
        }
        
        else if(is_prime(num))
        {
            printf("\n\t   --> %d is not a perfect number\n",num);
        }
        
        else
        {
            int f_sum = factor_sum(num);
            
            if(f_sum == num)
                printf("\n\t   --> %d is a perfect number\n",num);
            
            else
                printf("\n\t   --> %d is not a perfect number\n",num);
        }
            
        condition=0;
    }
}

int factor_sum(int n)
{
    int sum=1;
    
    for(i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            sum += i;
        }
    }
    
    return(sum);
}

void find_factorial()
{
    /*Factorial of a positive number is the product of all positive integers
      less than or equal to the number.*/
    
    int condition=1;
    
    while(condition)
    {
        printf("\n   Enter a positive integer: ");
        scanf("%d",&num);
        
        if(num < 0)
        {
            printf("\n\t   --> Invalid, Enter a positive integer!!\n");
            condition = 1;
            continue;
        }
        
        printf("\n\t   --> Number: %d",num);
        
        printf("\n\t   --> Factorial of %d, %d!: %e\n",num,num,factorial(num));
            
        condition=0;
    }
}

double factorial(int n)
{
    long double fact=1;
    
    while(n!=0)
        {
            fact *= n;
            n--;
        }
        
        return(fact);
}
