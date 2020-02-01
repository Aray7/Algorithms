#include<iostream>
using namespace std;
 
int i = 0;
char s[10000]; // max number of elements 10000
 
long int bracket()
{
	long int a=0;
	long int b=0;
	char operatorSym = '+';
	while( s[i]!=')' )
	{
			if( s[i] == '(' )
			{
					i++;
					b=bracket();
					if(operatorSym == '+')
							a = a + b;
					if(operatorSym == '-')
							a = a - b;
					if(operatorSym == '*')
							a = a * b;
			}
			if( s[i] >= 48 && s[i] <= 57 )
			{               
					b = s[i] - 48;
					if(operatorSym == '+')
							a = a+b;
					if(operatorSym == '-')
							a = a-b;
					if(operatorSym == '*')
							a = a*b;
					i++;
			}
			else
			{
					operatorSym = s[i];
					i++;
			}
	}
	return(a);
}
 
 
int main()
{
	long int a=0;
	long int b=0;
	char operatorSym = '+';
	cin >> s;
	while(s[i] != '\0')
	{
		if( s[i] == '(' )
		{
			i++;
			b = bracket();
			if(operatorSym == '+')
					a = a + b;
			if(operatorSym == '-')
					a = a - b;
			if(operatorSym == '*')
					a = a * b;
		}
		else if( s[i] >= 48 && s[i] <= 57 )
		{               
			b = s[i] - 48;
			if(operatorSym == '+')
					a = a + b;
			if(operatorSym == '-')
					a = a - b;
			if(operatorSym == '*')
					a = a * b;
			i++;
		}
		else
		{
			operatorSym = s[i];
			i++;
		}
	}
	cout << a;
}