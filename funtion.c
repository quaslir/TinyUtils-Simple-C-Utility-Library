#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
bool contains_only_whitespace(const char s[]) {
    int count = 0; 
    for(int i = 0; s[i] != '\0'; i++) {
        if(isspace(s[i]) == 0) count++;
    }
    return count > 0 ? false : true;
}
int count_words(const char s[]) {
    int count = 0;
    bool word_started = false;
    for(int i = 0; s[i] !=  '\0'; i++) {
        if(isalnum(s[i]))  {
            if(!word_started) {
                count++;
                word_started = true;
            }
            
        }
        else word_started = false;
        
    }
    return count;
}
int count_letters(const char s[]) {
    int count = 0;
    for(int i = 0; s[i] !='\0'; i++) {
        if(isalpha(s[i])) count++;
    }
    return count;
}
int count_digits(const char s[]) {
    int count = 0;
    for(int i =0; s[i] !='\0'; i++) {
        if(isdigit(s[i])) count++;
    }
    return count;
}
int count_uppercase(const char s[]) {
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(isupper(s[i])) count++;
    }
    return count;
}
int count_lowercase(const char s[]) {
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(islower(s[i])) count++;
    }
    return count;
}
void read_string(char s[], const int size) {
    fgets(s, size, stdin);
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        }
}
int sum_array(int numbers[], int size) {
    int sum = 0;

    for(int *p = numbers; p < numbers + size; p++) {
        sum += *p;
    }
    return sum;
}
int min_number(int* arr, int size) {
    int *min = arr;
    for(int *p = arr; p < arr + size; p++) {
        *min > *p ? min = p : 0;
    }
   return *min;

}
int max_number(int *arr, int size) {
    int *max = arr;
    for(int *p = arr; p < arr + size; p++) {
        *p > *max ? max = p : 0;
    }
    return *max;
}
void reverse_array(int *arr, int size) {
    int *left = arr;
    int *right = arr + size -1;
    int temp;
    while(left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        right--;
        left++;
    } 
}
void remove_negatives(int **arr, int *size) {
    int *write = *arr;
    for(int *read = *arr; read < *arr + *size; read++) {
        *read > 0 ? *write++ = *read : 0;
    }
    int new_size = write - *arr;
    *size = new_size;
    *arr = realloc(*arr, new_size * sizeof(int));
    if(&realloc == NULL) {
        printf("Memory allocation failed!");
        return;
    }
}
int main() {
char string[300];
char temp[300];
const int size = count_letters(string);
do {
printf("Enter a sentence (or whitespace to stop): ");
read_string(string, 300);
int count_s = count_words(string);
int count_l = count_letters(string);
int count_d = count_digits(string);
int count_upper = count_uppercase(string);
int count_lower = count_lowercase(string);
printf("Words: %d\n", count_s);
printf("Letters: %d\n", count_l);
printf("Digits: %d\n", count_d);
printf("Uppercase: %d\n", count_upper);
printf("Lowercase: %d\n", count_lower);
printf("The longest word: %s\n", temp);
}while(contains_only_whitespace(string) == 0);
    return 0;
}