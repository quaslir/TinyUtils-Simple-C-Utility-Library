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
int* print_u8_binary(int number) {
int *binary_numbers = malloc(8 * sizeof(int));
int bits = 128;
for(int i =0; i < 8; i++) {
    if(number & bits) {
        binary_numbers[i] = 1;
        bits = bits / 2;
    }
    else {
        binary_numbers[i] = 0;
        bits = bits / 2;
    }
}
return binary_numbers;
}

int* str_to_bits(const char *string) {
    int* array_result = malloc(8 * strlen(string) * sizeof(int));
    int i = 0;
    for(const char *p = string; *p !='\0'; p++) {
       for(int x = 7; x >= 0; x--) {
        array_result[i++] = (*p >> x) & 1;
       }
    }
    return array_result;
}
int *removeElement(int* nums, int numsSize, int val) {
    int size_new_array = 0;
    for(int *p = nums; p < numsSize + nums; p++) {
        if(*p != val)   size_new_array++;
    }
    int *new_array = malloc(size_new_array * sizeof(int));
    int j = 0;
    for(int *p = nums; p < numsSize + nums; p++) {
        if(*p != val)   {
            new_array[j] = *p;
            j++;
        }
    }
    return new_array;
}
int *merge_arrays(const int *a, int size_a, const int *b, int size_b) {
    int *new_array = malloc((size_a + size_b) * sizeof(int));
    int *p = new_array;
    for(const int *i = a; i < size_a + a;i++) {
        *p = *i;
        p++;
    }
    for(const int *i = b; i < size_b + b; i++) {
        *p= *i;
        p++;
    }
    return new_array;
}
char *vowels_string(char *string, int size) {
    int count = 0;
    char vowels[] = {'a','e','o', 'i', 'u'};
    size_t size_vowels = strlen(vowels);
    for(char *p = string; *p != '\0'; p++) {
        for(int i = 0; vowels[i] != '\0'; i++) {
            if(*p == vowels[i]) {
            count++;
            }
        }
    }
    char *new_array = malloc(count * sizeof(char));
    char *a = new_array;
    int j = 0;
    for(char *p = string; *p != '\0'; p++) {
        for(int i = 0; vowels[i] != '\0'; i++) {
            if(*p == vowels[i]) {
            new_array[j] = *p;
            j++;
            }
        }
    }
    return new_array;
}
char *word_remover(char *string, char *word) {
    if(!string || !word || word[0] == '\0') return string;
    size_t wl = strlen(word);
    char *scan = string;
    char *hit;
    while( (hit = strstr(scan, word)) != NULL) {
        memmove(hit, hit + wl, strlen(hit + wl) + 1);
        scan = hit;
    }
    return string;
}
int bubble_sort_strings(char strings[][100], size_t size) {
    int count = 0;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
        strlen(strings[j]) > strlen(strings[j + 1]) ? swap_strings(strings[j], strings[j+1]), count++ : 0;
    }
}
    return count;
}
size_t find_string_with_fewest_vowels(const char strings[][100], size_t start, size_t size) {
    int min_vowels = count_vowels(strings[start]);
    size_t index = start;
    for(int i = start; i < size; i++) {
           int count = count_vowels(strings[i]);
           count < min_vowels ? min_vowels = count, index = i : 0;
    }
    return index;
}
int selection_sort_strings(char strings[][100], size_t size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
            swap_strings(strings[i], strings[find_string_with_fewest_vowels(strings, i, size)]);
            count++;
    }
    return count;
}
void print_numbers(const int array[], int size) {
    int printed = 0;
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("%s%d", printed ? "," : "", array[i]);
        printed++;
    }
}
 int *minmax(int numbers[], int size) {
    int *min_max = malloc(2 * sizeof(int));
    int *min = numbers, *max = numbers;
    min_max[0] = numbers[0];
    min_max[1] = numbers[0];
    for(int *p = numbers; p < size + numbers; p++) {
        if(*p < *min) {min = p;min_max[0] = *min;}
        if(*p > *max) {max = p;min_max[1] = *max;}
    }
    return min_max;
 }
 void reverse_words(char string[], int size) {
    bool word_started = false;
    char *start = string;
    int i = 0;
    for(; string[i] !='\0';i++) {
        if(!isspace(string[i]) && !word_started) {word_started = true; start = string + i;}
        if(isspace(string[i]) && word_started) {
            char *end = &string[i-1];
             while(start < end) {
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
             }
             word_started = false;
    }
}
    if(word_started) {
        char *end = &string[i-1];
        while(start < end) {
        char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
    }
}
}
bool duplicate(int array[], int size) {
    int *left = array;
    int *right = array + size - 1;
    while(left != array + size - 1 && right != array) {
    if(*left == *right) return true;
    left++;
    right--;

}
return false;
}
char *get_middle(const char *inp) {
    char *s = NULL;
    size_t length = strlen(inp);
    if(length == 0) return s;
    else if(length % 2 == 0) {
        s = malloc(3 * sizeof(char));
        s[0] = inp[length / 2 - 1];
        s[1] = inp[length / 2];
        s[2] = '\0';
    }
    else {
        s = malloc(2 * sizeof(char));
        s[0] = inp[(length) / 2];
        s[1] = '\0';
    }
    return s;
    }
void space_remover(char string[]) {
    int pos = 0;
    for(int i = 0; string[i] !='\0'; i++) {
        if(!isspace(string[i])) {
            string[pos] = string[i];
            pos++;
        }
    }
    string[pos] = '\0';
}
void decode(char string[]) {
    for(int i = 0; string[i] !='\0'; i++) {
        if(!isspace(string[i])) {
        string[i] = 'a' + 'z' - string[i];
        }
    }
}
int sumstr(char string[]) {
    int sum = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        if(isdigit(string[i])) {
            sum += string[i] -'a' + '1';
        }
    }
    return sum;
}
void first_and_last_character_remover(char string[], size_t size) {
    int pos = 0;
    for(int i = 0; i < size; i++) {
        if(i != 0 && i != size - 1) {
            string[pos] = string[i];
            pos++;
        }
    }
    string[pos] = '\0';
}
int round_up_5(int number) {
    if(number < 0 && number % 5 != 0) {
        return number + (5 - (5 - (-number % 5)));
    }
   return number % 5 == 0 ? number : number + (5 - number % 5);
}
int size_array(int number) {
unsigned int size = 0;
    while(number > 0) {
        number /= 10;
        size++;
    }
    return size;
}
int *numbers_divider(int number) {
        int size =size_array(number);
    int *numbers = malloc(size * sizeof(int));
    int *p =numbers + size -1;
    while(number > 0) {
        *p = number % 10;
        number /= 10;
        p--;
    }
    return numbers;
}
int comp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x<y) - (x>y);
}
int array_to_integer(int *numbers, int size) {
    int number = 0;
    int square = 1;
    for(int *p = numbers + size - 1; p >= numbers; p--) {
        number += square * *p;
        square *= 10;
    }
    
    return number;
}
long long the_biggest_number(long long n) {
    int *numbers = numbers_divider(n);
    int size = size_array(n);
    qsort(numbers, size, sizeof(numbers[0]), comp);
    long long num = n;
    n = array_to_integer(numbers, size);
    if(num == n) return -1;
    return n;

}
typedef struct Node{
    int v;
    struct Node *next;
}Node;
Node *push(Node *head, int x) {
    Node *n = malloc(sizeof(*n));
    if(!n) return head;
    n->v = x;
    n->next = head;
    return n;
}
void print_list(Node *head) {
    for(Node *p = head; p; p = p->next) {
        printf("%2d", p->v);

    }

}
void freeList(Node *head) {
    while(head) {
        Node *t = head->next;
        free(head);
        head = t;
    }
}