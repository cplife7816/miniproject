#include "manager.h"

int createProduct (Product *p,int count){
        getchar();
        printf("추가할 제품의 이름은?");
        scanf("%[^\n]s",p[count].name);
        getchar();
        printf("제품 설명은? :");
        scanf("%[^\n]s",p[count].explain);
        getchar();
        printf("원산지는? :");
        scanf("%[^\n]s",p[count].place);
        getchar();
        printf("판매 단위는? :");
        scanf("%[^\n]s",p[count].amount);
        getchar();
        printf("판매 가격은? :");
        scanf("%d",&p[count].price);
        printf("배송방법은?(1:새벽배송 / 2:택배배송):");
        scanf("%d",&p[count].send_type);
#ifdef DEBUG
	printf("\n\nDebuging....\n");
	printf("현재 입력된 제품의 값들\n");
	printf("%s\n",p[count].name);
	printf("%s\n",p[count].explain);
	printf("%s\n",p[count].place);
	printf("%s\n",p[count].amount);
	printf("%d\n",p[count].price);
	printf("%d\n\n",p[count].send_type);
#endif
	return 0;
}

int readProduct(Product * p,int count){
    for (int i = 0 ; i < count ; i++){
	if (p[i].price == -1) continue;
        printf("%s\n",p[i].name);
        printf("%s\n",p[i].explain);
        printf("%d원\n",p[i].price);
        printf("구매혜택   회원 적립금 : +%d원 (상품:%d원)\n",p[i].price/100,p[i].price/100);
        printf("원산지   %s\n",p[i].place);
        printf("%s\n",p[i].amount);
        printf("배송방법 (1: 새벽배송/2: 택배배송) : %d\n\n",p[i].send_type);
}
        return 0;
}

int listProduct(Product *p,int count){
        printf("번호  상품            양                가격    배송");
        for (int i = 0 ; i < count ; i++){
            if (p[i].price == -1)
                continue;
            printf("\n%d.   %s    %s    %d      %d\n",i+1,p[i].name,p[i].amount,p[i].price,p[i].send_type);
        }
        return 0;
}

void SearchProduct(Product *p,int count)
{
    int scan = 0;
    char given[20];
    printf("검색할 제품은? ");
    scanf("%s",given);
    listProduct(p,count);
    for (int i = 0 ; i < count ; i++)
    {    
        if (p[i].price == -1)
        continue;
        if (strstr(p[i].name,given))
        {
	printf("%d번 제품이 일치 합니다!!",i+1);
        scan++;
        }
    }
if (scan == 0 )
    printf("==> 검색된 데이터 없음 !");
printf("\n");
}


int deleteProduct(Product *p,int count)
{
    int num;
    int sel;
    listProduct(p,count);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d",&num);
    if (num != 0)
    {
       printf("정말 삭제하시겠습니까?(삭제 :1)");
       scanf("%d",&sel);
       if (sel == 1)
       {
         num-=1;
         p[num].price = -1;
       }
    }

#ifdef DEBUG
    printf("\n\nDebuging....\n");
    printf("삭제 완료 확인.\n");
    printf("p[%d].price = %d\n\n",count,p[count].price);
#endif
    return 1;
}

void SaveData(Product * p,int count)
{
    FILE *fp;
    fp = fopen("product.txt","wt");

    for (int i = 0 ; i < count ; i++)
    {
        if (p[i].price == -1)
        continue;
    	fprintf(fp,"%s\n",p[i].name);
        fprintf(fp,"%s\n",p[i].explain);
        fprintf(fp,"%s\n",p[i].amount);
        fprintf(fp,"%s\n",p[i].place);
        fprintf(fp,"%d\n",p[i].price);
        fprintf(fp,"%d\n",p[i].send_type);

    }
    fclose(fp);
    printf("저장됨! \n");
}


int LoadData(Product *p)
{
    int i = 0;
    char line[200], *result;
    FILE *fp, *check = NULL;
    if (check = fopen("product.txt","rt"))
    {
       fp = fopen("product.txt","rt");
       while (1)
       {
        if ((result = fgets(line, 256, fp)) != NULL) {
            result[strlen(result) - 1] = '\0';
            strcpy(p[i].name,result);
        }
        if ((result = fgets(line, 256, fp)) != NULL) {
            result[strlen(result) - 1] = '\0';
            strcpy(p[i].explain,result);
        }
        if ((result = fgets(line, 256, fp)) != NULL) {
            result[strlen(result) - 1] = '\0';
            strcpy(p[i].amount,result);
        }
        if ((result = fgets(line, 256, fp)) != NULL) {
            result[strlen(result) - 1] = '\0';
            strcpy(p[i].place,result);
        }
        if ((result = fgets(line, 256, fp)) != NULL) p[i].price = atoi(result);
 	    if ((result = fgets(line, 256, fp)) != NULL) p[i].send_type = atoi(result);
        if(feof(fp)) break;
        i++;
       }
	fclose(fp);
       	printf("==> 로딩 성공! \n");
       	return i;
    }
    else
    printf("==> 파일 없음 \n");
    return 0;
}

int updateProduct(Product *p,int count)
{
    int choose;
    listProduct(p,count);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d",&choose);
    if (choose != 0)
    {
        choose-=1;
        getchar();
        printf("제품의 이름은?");
        scanf("%[^\n]s",p[choose].name);
        getchar();
        printf("제품 설명은? :");
        scanf("%[^\n]s",p[choose].explain);
        getchar();
        printf("원산지는? :");
        scanf("%[^\n]s",p[choose].place);
        getchar();
        printf("판매 단위는? :");
        scanf("%[^\n]s",p[choose].amount);
        getchar();
        printf("판매 가격은? :");
        scanf("%d",&p[choose].price);
        printf("배송방법은?(1:새벽배송 / 2:택배배송):");
        scanf("%d",&p[choose].send_type);
    }
#ifdef DEBUG
    printf("\n\nDebuging....\n");
    printf("현재 입력된 제품의 값들\n");
    printf("%s\n",p[choose].name);
    printf("%s\n",p[choose].explain);
    printf("%s\n",p[choose].place);
    printf("%s\n",p[choose].amount);
    printf("%d\n",p[choose].price);
    printf("%d\n\n",p[choose].send_type);
#endif
    return 0;
}


