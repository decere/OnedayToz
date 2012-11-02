#include <iostream>
#include <string.h>

using namespace std;

bool patternMatch(char *s, char *p)
{
	int i;
	int j;
	int n;
	int m;
	
	n = strlen(s);
	m = strlen(p);
	
	if (n < m)
	{
		return false;
	}
	
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] == p[j])
		{
			j++;
			if (j == m)
			{
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	char s[] = "Google's mission is to organize the world's information and make it universally accessible and useful.";
	char p[] = "Google mission";
	
	cout << patternMatch(s, p) << '\n';
	
	return 0;
}
