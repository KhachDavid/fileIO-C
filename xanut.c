#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

const int A = 19;
#define LENGTH  20
#define MAX     19

typedef struct
{
    float price;
    char* product;
    char* department;
    int stock;
} 
apranq;

int main(void)
{
    FILE* fuf; 
    
    float val1;
    char desc1[MAX];
    char desc2[MAX];
    int val2;
    int rc;

    fuf = fopen("vesh.csv", "r");
    if (fuf == NULL)
    {
        perror("fopen");
        return 1;
    }
    
    apranq menu[MAX]; 
    
    for (int o = 0; o < A; o++)
    {
        menu[o].product = malloc(LENGTH * sizeof (char));
        if (menu[o].product == NULL)
        {
            perror("malloc");
            return 1;
        }
    
        menu[o].department = malloc(LENGTH * sizeof (char));
        if (menu[o].department == NULL)
        {
            perror("malloc");
            return 1;
        }
        
        rc = fscanf(fuf, "%f, %[A-Za-z-], %[A-Za-z ], %d ", &menu[o].price, menu[o].product, menu[o].department, &menu[o].stock);
    
//        if (rc == 4)
//        {
//            printf("Price: %.01f\t\t", menu[o].price);
//            printf("Product: %s\t\t", menu[o].product);
//            printf("Department: %s\t\t", menu[o].department);
//            printf("Items Left: %d \n", menu[o].stock);
//        }  
    
//        else
//        {
//            printf("Error: only %d tokens scanned\n", rc);
//            return 1;
//        }
    }
    
    char* name= get_string("Enter your name: ");
    char* surname = get_string("Enter your surname: ");
    
    printf("Hello dear %s, thank you for visiting our store.\n", name);
    
    printf("Here is our menu\n");
    
    for (int i = 0; i < A; i++)
    {
        printf("Price:%.02f\t ", menu[i].price);
        printf("Product:%s\t ", menu[i].product);
        printf("Department:%s\t ", menu[i].department);
        printf("Stock:%i", menu[i].stock);
        printf("\n");
    }
    
    fclose(fuf);
    return 0;
}
