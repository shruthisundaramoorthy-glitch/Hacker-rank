#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {

    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {

    return strcmp(b, a);
}

int count_distinct(const char* s) {

    int freq[26] = {0};
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++) {

        int index = s[i] - 'a';

        if(freq[index] == 0) {
            count++;
            freq[index] = 1;
        }
    }

    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

    int count1 = count_distinct(a);
    int count2 = count_distinct(b);

    if(count1 != count2)
        return count1 - count2;

    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {

    int len1 = strlen(a);
    int len2 = strlen(b);

    if(len1 != len2)
        return len1 - len2;

    return strcmp(a, b);
}

void string_sort(char** arr, const int len,
                 int (*cmp_func)(const char* a, const char* b)) {

    for(int i = 0; i < len; i++) {

        for(int j = i + 1; j < len; j++) {

            if(cmp_func(arr[i], arr[j]) > 0) {

                char temp[1024];

                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}