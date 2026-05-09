#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    
    int k = -1;

    for(int i = n - 2; i >= 0; i--) {

        if(strcmp(s[i], s[i + 1]) < 0) {
            k = i;
            break;
        }
    }

   
    if(k == -1)
        return 0;

    
    int l = -1;

    for(int i = n - 1; i > k; i--) {

        if(strcmp(s[k], s[i]) < 0) {
            l = i;
            break;
        }
    }

   
    char temp[11];

    strcpy(temp, s[k]);
    strcpy(s[k], s[l]);
    strcpy(s[l], temp);

    
    int start = k + 1;
    int end = n - 1;

    while(start < end) {

        strcpy(temp, s[start]);
        strcpy(s[start], s[end]);
        strcpy(s[end], temp);

        start++;
        end--;
    }

    return 1;
}



int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}