#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(const int argc, char *argv[]) { // take command line arguments
    if (argc != 3) {
        printf("Usage: ./waygrep search_word filename"); return 1;
    }
    FILE* fptr = fopen(argv[2], "r"); // open file

    char str[100]; // buffer for line in file

    char lower_word[100];
    strcpy(lower_word, argv[1]);


    for (int i = 0; lower_word[i] != '\0'; i++) {
        lower_word[i] = tolower(lower_word[i]);
    }
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;

    }
    int found = 0; // loop through lines in file
    while(fgets(str,sizeof(str),fptr) != NULL) { // if line contains search word print line else print not found

        char lower_str[100]; // buffer for current line
        strcpy(lower_str, str);

        for (int i = 0; lower_str[i] != '\0'; i++){
            lower_str[i] = tolower(lower_str[i]);
        }

        if (strstr(lower_str,lower_word)) {
            printf("%s",str);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Word Not found\n");
    }
    fclose(fptr);
    return 0;
}
