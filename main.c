#include <stdio.h>
#include <string.h>

void menu()
{
    printf("1. Nhap so lieu ban hang len tep\n");
    printf("2. Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C\n");
    printf("3. Hien thi noi dung tep SO_LIEU.C\n4. Ket thuc\n");
}

struct solieu
{
    char tendonhang[100];
    float dongia;
    int soluong;
    float tong;
};
typedef struct solieu solieu;

void nhapsolieulenfile()
{
    FILE *f;
    f = fopen("SOLIEU.c", "wb");
    solieu solieu;
    printf("\nNhap ten don hang: ");
    fflush(stdin);
    gets(solieu.tendonhang);
    printf("\nNhap don gia : ");
    fflush(stdin);
    scanf("%f", &solieu.dongia);
    printf("\nNhap so luong: ");
    scanf("%d", &solieu.soluong);
    solieu.tong = solieu.dongia * solieu.soluong;
    fwrite(&solieu, sizeof(solieu), 1, f);
    fclose(f);
    printf("Nhap thanh cong!\n");
}

void nhapthemdulieu()
{
    FILE *f;
    f = fopen("SOLIEU.c", "ab");
    solieu solieu;    
    printf("\nNhap ten don hang: ");
    fflush(stdin);
    gets(solieu.tendonhang);
    printf("\nNhap don gia : ");
    fflush(stdin);
    scanf("%f", &solieu.dongia);
    printf("\nNhap so luong: ");
    scanf("%d", &solieu.soluong);
    solieu.tong = solieu.dongia * solieu.soluong;
    fwrite(&solieu, sizeof(solieu), 1, f);
    printf("\nThem thanh cong!\n");
    fclose(f);
}

void hienthidulieu()
{
    FILE *f;
    f = fopen("SOLIEU.c", "rb");

    char stt[] = "STT";
    char tenhang[] = "Ten Hang";
    char dongia[] = "Don Gia";
    char soluong[] = "So luong";
    char thanhtien[] = "Thanh tien";
    char tong[] = "Tong tien";
    printf("========================================\n");
    printf("%5s%20s%10s%10s%20s\n", stt, tenhang, dongia, soluong, thanhtien);
    solieu solieu;
    int i=1;
    float tongtien=0;
    while( fread(&solieu,sizeof(solieu),1,f) != NULL){
        printf("%d%20s\t  %.2f%10d%20f",i,solieu.tendonhang,solieu.dongia,solieu.soluong,solieu.tong);
        tongtien+=solieu.tong;
        i++;
        printf("\n");
    }
    printf("\t\t\t\t\t%10s\t%.5f\n",tong,tongtien);
    fclose(f);
}

int main()
{
    int luachon = 0;
    do
    {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 1 /* constant-expression */:
            /* code */
            nhapsolieulenfile();
            break;
        case 2 /* constant-expression */:
            /* code */
            nhapthemdulieu();
            break;
        case 3 /* constant-expression */:
            /* code */
            hienthidulieu();
            break;
        case 4 /* constant-expression */:
            /* code */
            return 0;
        }
    } while (luachon != 4);
    return 0;
}

// void daochuoi(char s1[50], char s2[50]){
// 	printf("Chuoi 1 va chuoi 2 sau khi dao nguoc: %s\t%s ", strrev(s1),strrev(s2));
// }
// void sosanh(char s1[50], char s2[50]){
//     strrev(s1);
//     strrev(s2);
//     printf("\nPhan thua ra: ");
// 	if(strlen(s1)<strlen(s2)){
//         for(int i=strlen(s1);i<strlen(s2);i++){
//             printf("%c",s2[i]);
//         }
//     }
//     else if(strlen(s1)>strlen(s2)){
//         for(int i=strlen(s2);i<strlen(s1);i++){
//             printf("%c",s1[i]);
//         }
//     }
// }
// void noichuoi(char s1[50], char s2[50]){
// 	char s3[50];
// 	strcpy(s3,s1);
// 	strcat(s3,s2);
// 	printf("\nNoi chuoi: %s", s3);
// 	printf("\nHam moi sau khi in hoa: %s", strupr(s3));
// }
// void tachchuoi(char s4[50],char s5[50]){
//     char s3[50];
//     strcpy(s3,s4);
// 	strcat(s3,s5);
//     strupr(s3);
//     char s1[50];
//     char s2[50];
// 	int k,f=0;

//         k=strlen(s3)/2;
//         for(int i=0;i<k;i++)
//         {
//             s1[i]=s3[i];
//         }
//         for(int i=k;i<strlen(s3);i++)
//         {
//             s2[f] =s3[i];
//             f++;
//         }
//         s2[f]='\0';
//         printf("%s\n",s1);
//         printf("%s\n",s2);

// }
// /*int main(){
// 	char s1[50],s2[50];
//     printf("Nhap s1: "); gets(s1);
//     printf("Nhap s2: "); gets(s2);
//     daochuoi(s1,s2);
// 	sosanh(s1,s2);
//     noichuoi(s1,s2);
// 	tachchuoi(s1,s2);
// 	return (0);
// }*/
