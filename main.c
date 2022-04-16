#include "product.h"
#include "manager.h"


int main(void)
{
#ifdef DEBUG
	printf("==> DEBUGMODE\n\n");


#endif 
    Product p[20];
    int count = 0, menu;
    count = LoadData(p);
    
#ifdef DEBUG
    printf("\n==> 문제가 있는 기능을 선택하시오.\n");
#endif
    while (1)
    {
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1)
        {
            listProduct(p,count);
        }
        else if (menu == 2)
        {
            createProduct(p,count);
            count+=1;
        }
        else if (menu == 3)
        {
            updateProduct(p,count);
        }
        else if (menu == 4)
        {
        int del = deleteProduct(p,count);
        if (del == 1)
            printf("=> 삭제됨!\n");
        }
        else if (menu == 5)
        {
            SaveData(p,count);
        }
        else if (menu == 6)
        {
            selectOption(p,count,i);
        }
        else if (menu == 7)
        {
            readProduct(p,count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
