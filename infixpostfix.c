#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char stk[20];
int top = -1;

int isempty()
{
    return top == -1;
}
int isfull()
{
    return top == MAX - 1;
}
char peek()
{
    return stk[top];
}
char pop()
{
    if(isempty())
        return INT_MIN;

    char ch = stk[top];
    top--;
    return(ch);
}
void push(char oper)
{
    if(isfull())
        printf("Stack Full");
   
    else{
        top++;
        stk[top] = oper;
    }
}
int ifoper(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
} 
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
}
int convert(char* exp) 
{ 
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i) 
    { 
        
        if (ifoper(exp[i])) 
            exp[++j] = exp[i]; 

      
        else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]); 

        
        else if (exp[i]==')' || exp[i]=='}'  || exp[i]==']') 
        {
            if(exp[i]==')')
            {   
                while (!isempty() && peek() != '(') 
                    exp[++j] = pop(); 
                
                
                pop();
            }
            
            if(exp[i]==']')
            {   
                while (!isempty() && peek() != '[') 
                    exp[++j] = pop(); 
                
               
                pop();
            }
           if(exp[i]=='}')
            {   
                while (!isempty() && peek() != '{') 
                    exp[++j] = pop(); 
                
           
                pop();
            }
        }
        else
        { 
            while (!isempty() && precedence(exp[i]) <= precedence(peek())) 
                exp[++j] = pop(); 
            push(exp[i]); 
        } 

    } 

   
    while (!isempty()) 
        exp[++j] = pop(); 

    exp[++j] = '\0'; 
    printf( "%s", exp); 
} 
int main()
{
    char expr[MAX];
	printf("Enter Expression: ");
	fgets(expr,MAX,stdin); 
    convert(expr); 
    return 0; 
}
