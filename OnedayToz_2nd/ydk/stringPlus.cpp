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

char *stringPlus(char *a, char *b)
{
	int i;
	int j;
	int l;
	int n;
	int m;
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
	if (m > n)
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
		A = characterToNumber(x[i]);
		B = 0;
		if (j >= 0)
		{
			B = characterToNumber(y[j]);
		}
		
		t = A + B + t;
		c[i + 1] = numberToCharacter(t);
		
		if (t > 9)
		{
			t = 1;
		}
		else
		{
			t = 0;
		}
	}
	
	c[0] = numberToCharacter(t);
	
	return c;
}

int main()
{
	char a[] = "12348625";
	char b[] = "478920";
	char *c;
	
	c = stringPlus(a, b);
	
	if (c != NULL)
	{
		cout << a << " + " << b << " = " << c << '\n';
		
		delete[] c;
	}
	
	return 0;
}
