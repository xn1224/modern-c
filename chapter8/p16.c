#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int i;
    bool check;
    char str[26] = {0};
    char word1[20], word2[20];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    printf("alpha:  ");
    for (i = 'a'; i < 'a' + 26; i++) {
        printf("%2c ", i);
    }
    printf("\n");

    for (i = 0; i < (int)strlen(word1);i++) {
        str[tolower(word1[i]) - 'a']++;
    }

    printf("before: ");
    for (i = 0; i < 26; i++) {
        printf("%2d ", str[i]);
    }
    printf("\n");

    for (i = 0; i < (int)strlen(word2);i++) {
        str[tolower(word2[i]) - 'a']--;
    }

    printf("after : ");
    for (i = 0; i < 26; i++) {
        printf("%2d ", str[i]);
    }
    printf("\n");
    
    check = true;
    for (i = 0; i < 26; i++) {
        //printf("%d ", str[i]);
        if (str[i] != 0) 
        {
            check = false;
            break;
        }
    }

    if (check) {
        printf("The word are anagrams.\n");
    } else {
        printf("The word are not anagrams.\n");
    }

    return 0;
}
