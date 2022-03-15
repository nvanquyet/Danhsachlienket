#include <stdio.h>
#include <stdlib.h>

void nhap(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nNhap vao phan tu hang %d cot %d : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}
int **tich2matran(int **a, int **b, int n, int p, int m)
{
    int **c;
    c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        *(c + i) = (int *)malloc(m * sizeof(int));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[i][j] = 0;
            for(int k=0;k<p;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    return c;
}

void menu()
{
    printf("\n1. Nhap 2 ma tran  ");
    printf("\n2. Tinh tich 2 ma tran  ");
    printf("\n3. Hien thi 3 ma tran  ");
    printf("\n4. Ket thuc\n ");
}

int main()
{
    int **a, **b,**c;
    int n, p, m;
    int luachon = 0;
    do
    {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 1:
        {
            printf("\nNhap so hang ma tran A: ");
            scanf("%d", &n);
            printf("\nNhap so cot ma tran A, so hang ma tran B: ");
            scanf("%d", &p);
            printf("\nNhap so cot ma tran B: ");
            scanf("%d", &m);
            a = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < p; i++)
            {
                *(a + i) = (int *)malloc(p * sizeof(int));
            }
            b = (int **)malloc(p * sizeof(int *));
            for (int i = 0; i < m; i++)
            {
                *(b + i) = (int *)malloc(m * sizeof(int));
            }

            printf("\nNhap ma tran A:\n");
            nhap(a, n, p);
            printf("\nNhap ma tran B:\n");
            nhap(b, p, m);
            break;
        }
        case 2:
        {
            c = tich2matran(a,b,n,p,m);
            break;
        }
        case 3:
        {
            printf("\nMa tran A: \n");
            xuat(a,n,p);
            printf("\nMa tran B: \n");
            xuat(b,p,m);
            printf("\nMa tran tich: \n");
            xuat(c,n,m);
            break;
        }
        }
    } while (luachon != 4);
    return 0;
}