#include <iostream>
#include <string.h>

using namespace std;

int characterToNumber(char c)
{
	int n;
	
	n = (int)(c - '0');
	
	if (n < 0 || n > 9)
	{
		n = 0;
	}
	
	return n;
}

char numberToCharacter(int n)
{
	char c;
	
	if (n > 9)
	{
		n = n - 10;
	}
	else if (n < 0)
	{
		n = 0;
	}
	
	c = (char)(n + '0');
	
	return c;
}

char *stringMinus(char *a, char *b)
{
	int i;
	int j;
	int l;
	int n;
	int m;
	int s;
	int t;
	int A;
	int B;
	char *x;
	char *y;
	char *c;
	
	x = a;
	y = b;
	n = strlen(x);
	m = strlen(y);
	l = n;
	s = 0;
	if (m > n)
	{
		s = 1;
	}
	else if (m == n)
	{
		i = 0;
		while (i < n)
		{
			A = characterToNumber(x[i]);
			B = characterToNumber(y[i]);
			if (A > B)
			{
				break;
			}
			else if (B < A)
			{
				s = 1;
				break;
			}
			else
			{
				i++;
			}
		}
	}
	
	if (s == 1)
	{
		x = b;
		y = a;
		t = n;
		n = m;
		m = t;
		l = n;
	}
	
	if (l <= 0)
	{
		return NULL;
	}
	
	c = new char[l + 2];
	c[l + 1] = '\0';
	
	t = 0;
	for (i = n - 1, j = m - 1; i >= 0; i--, j--)
	{
		A = characterToNumber(x[i]) - t;
		B = 0;
		if (j >= 0)
		{
			B = characterToNumber(y[j]);
		}
		
		t = A - B;
		
		if (t < 0)
		{
			c[i + 1] = numberToCharacter(t + 10);
			t = 1;
		}
		else
		{
			c[i + 1] = numberToCharacter(t);
			t = 0;
		}
	}
	
	c[0] = '0';
	if (s == 1)
	{
		c[0] = '-';
	}
	
	return c;
}

int main()
{
	char a[] = "478920";
	char b[] = "12348625";
	char *c;
	
	c = stringMinus(a, b);
	
	if (c != NULL)
	{
		cout << a << " - " << b << " = " << c << '\n';
		
		delete[] c;
	}
	
	return 0;
}
