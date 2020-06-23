#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

const int A = 19;
#define LENGTH  20
#define MAX     19

typedef struct //creating the type of the products
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
    int rc;

    fuf = fopen("vesh.csv", "r"); //opening the file that contains the products 
    if (fuf == NULL)
    {
        perror("fopen");
        return 1;
    }
    
    apranq menu[MAX]; 
    
    for (int o = 0; o < A; o++)
    {
        menu[o].product = malloc(LENGTH * sizeof (char)); //allocating memory to store char* pointers in arrays
        if (menu[o].product == NULL)
        {
            perror("malloc");
            return 1;
        }
    
        menu[o].department = malloc(LENGTH * sizeof (char)); //allocating memory to store char* pointers in arrays
        if (menu[o].department == NULL)
        {
            perror("malloc");
            return 1;
        }
        //reading the price, the product, the department, the items left from the vesh.csv file!
        rc = fscanf(fuf, "%f, %[A-Za-z-], %[A-Za-z ], %d ", &menu[o].price, menu[o].product, menu[o].department, &menu[o].stock);
    
//        if (rc == 4) just checking if the assignments are correct
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
