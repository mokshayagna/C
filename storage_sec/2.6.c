#include <stdio.h>
#include <stdlib.h>

/*
1. Print the addresses of all variables.
2. List all Local variables.
3. List all Global variables.
*/

/* ================= GLOBAL VARIABLES ================= */

int idata1 = 1;
char carray1[10];
char cname1[128] = "Aura Networks";
char *pname1 = "Aura Networks";

int idata2;
int idata3 = 3;
int idata4;

short sh1;
short sh2 = 2;

int iarray1[10] = {1, 2};
int iarray2[10] = {10, 20};

short sh3;
short sh4 = 4;

char ch1 = 1;
char ch2;

short sharray3[10] = {5, 6};

char ch3 = 3;

int idata5 = 10;
int idata6 = 20;


/* Function declarations */

void fun1(void);
void fun2(void);
void fun3(void);


int main(void)
{
    /* ================= LOCAL VARIABLES ================= */

    int ldata1;
    int ldata2 = 2;
    int ldata3;

    static int sdata1;
    static int sdata2 = 10;

    char cname2[128] = "Aura Networks";
    char *pname2 = "Aura Networks";

    int *ptr = malloc(10);


    /* ================= LOCAL VARIABLE ADDRESSES ================= */

    printf("\n========== LOCAL VARIABLES ==========\n");

    printf("&ldata1  = %p\n", (void *)&ldata1);
    printf("&ldata2  = %p\n", (void *)&ldata2);
    printf("&ldata3  = %p\n", (void *)&ldata3);

    printf("&sdata1  = %p\n", (void *)&sdata1);
    printf("&sdata2  = %p\n", (void *)&sdata2);

    printf("cname2   = %p\n", (void *)cname2);
    printf("&cname2  = %p\n", (void *)&cname2);

    printf("pname2   = %p\n", (void *)pname2);
    printf("&pname2  = %p\n", (void *)&pname2);

    printf("ptr      = %p\n", (void *)ptr);
    printf("&ptr     = %p\n", (void *)&ptr);


    /* ================= GLOBAL VARIABLE ADDRESSES ================= */

    printf("\n========== GLOBAL VARIABLES ==========\n");

    printf("&idata1      = %p\n", (void *)&idata1);
    printf("&carray1     = %p\n", (void *)&carray1);

    printf("cname1       = %p\n", (void *)cname1);
    printf("&cname1      = %p\n", (void *)&cname1);

    printf("pname1       = %p\n", (void *)pname1);
    printf("&pname1      = %p\n", (void *)&pname1);

    printf("&idata2      = %p\n", (void *)&idata2);
    printf("&idata3      = %p\n", (void *)&idata3);
    printf("&idata4      = %p\n", (void *)&idata4);

    printf("&sh1         = %p\n", (void *)&sh1);
    printf("&sh2         = %p\n", (void *)&sh2);

    printf("iarray1      = %p\n", (void *)iarray1);
    printf("&iarray1     = %p\n", (void *)&iarray1);

    printf("iarray2      = %p\n", (void *)iarray2);
    printf("&iarray2     = %p\n", (void *)&iarray2);

    printf("&sh3         = %p\n", (void *)&sh3);
    printf("&sh4         = %p\n", (void *)&sh4);

    printf("&ch1         = %p\n", (void *)&ch1);
    printf("&ch2         = %p\n", (void *)&ch2);

    printf("sharray3     = %p\n", (void *)sharray3);
    printf("&sharray3    = %p\n", (void *)&sharray3);

    printf("&ch3         = %p\n", (void *)&ch3);

    printf("&idata5      = %p\n", (void *)&idata5);
    printf("&idata6      = %p\n", (void *)&idata6);


    /* ================= FUNCTION ADDRESSES ================= */

    printf("\n========== FUNCTIONS ==========\n");

    printf("fun1         = %p\n", (void *)fun1);
    printf("fun2         = %p\n", (void *)fun2);
    printf("fun3         = %p\n", (void *)fun3);


    free(ptr);

    return 0;
}


/* ================= FUNCTION 1 ================= */

void fun1(void)
{
    int ldata4;

    printf("\n========== fun1 LOCAL VARIABLE ==========\n");
    printf("&ldata4  = %p\n", (void *)&ldata4);

    printf("I am function 1\n");
}


/* ================= FUNCTION 2 ================= */

void fun2(void)
{
    printf("I am function 2\n");
}


/* ================= FUNCTION 3 ================= */

void fun3(void)
{
    int ldata5 = 10;

    printf("\n========== fun3 LOCAL VARIABLE ==========\n");
    printf("&ldata5  = %p\n", (void *)&ldata5);

    printf("I am function 3\n");
}