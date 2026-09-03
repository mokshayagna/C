#include <stdio.h>

int arr[] = {10, 20, 30};
int *p = arr;

printf("%d\n", *p++);
printf("%d\n", *p);