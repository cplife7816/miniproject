#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    char explain[100];
    char amount[100];
    char place[20];
    int price;
    int send_type;
} Product;

int createProduct(Product *p,int count);
int readProduct(Product *p,int count); 
int listProduct(Product *p, int count);
void SearchProduct(Product *p, int count);
int deleteProduct(Product *s,int count); 
void SaveData(Product *s,int count); 
int LoadData(Product *s); 
int updateProduct(Product *s,int count); 
