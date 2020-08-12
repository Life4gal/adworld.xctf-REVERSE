#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define FLAG_LEN 20

void * checking(void *arg) {
    char *result = malloc(sizeof(char));
    char *argument = (char *)arg;
    *result = (argument[0]+argument[1]) ^ argument[2];
    return result;
}

int highly_optimized_parallel_comparsion(char *user_string)
{
    int initialization_number;
    int i;
    char generated_string[FLAG_LEN + 1];
    generated_string[FLAG_LEN] = '\0';

	// initialization_number 必须小于64
    while ((initialization_number = random()) >= 64);
    
    int first_letter;
	// 97~108
    first_letter = (initialization_number % 26) + 97;

	// 应该是对每个字符创建一个线程进行检查
    pthread_t thread[FLAG_LEN];
    char differences[FLAG_LEN] = {0, 9, -9, -1, 13, -13, -4, -11, -9, -1, -7, 6, -13, 13, 3, 9, -13, -11, 6, -7};
    char *arguments[20];
    for (i = 0; i < FLAG_LEN; i++) {
        arguments[i] = (char *)malloc(3*sizeof(char));  // 三个字符
        arguments[i][0] = first_letter;   
        arguments[i][1] = differences[i];
        arguments[i][2] = user_string[i];

    	// checking -> (字符1 + 字符2) ^ 字符3 -> (random() + differences[i]) ^ user_string[i]
        pthread_create((pthread_t*)(thread+i), NULL, checking, arguments[i]);
    }

    void *result;
    int just_a_string[FLAG_LEN] = {115, 116, 114, 97, 110, 103, 101, 95, 115, 116, 114, 105, 110, 103, 95, 105, 116, 95, 105, 115};
    for (i = 0; i < FLAG_LEN; i++) {
        pthread_join(*(thread+i), &result); // 这个应该是获取结果
        generated_string[i] = *(char *)result + just_a_string[i];
        free(result);
        free(arguments[i]);
    }

    int is_ok = 1;
    for (i = 0; i < FLAG_LEN; i++) {
        if (generated_string[i] != just_a_string[i])    // 这应该是要求 *result = 0
            return 0;                                   // 即 (random() + differences[i]) ^ user_string[i] = 0
    }

    return 1;
}

int main()
{
    char *user_string = (char *)calloc(FLAG_LEN+1, sizeof(char));
    fgets(user_string, FLAG_LEN+1, stdin);
    int is_ok = highly_optimized_parallel_comparsion(user_string);
    if (is_ok)
        printf("You win!\n");
    else
        printf("Wrong!\n");
    return 0;
}
