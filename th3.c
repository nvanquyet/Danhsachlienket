#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Sinhvien
{
    int stt;
    char name[50];
    int age;
    float diem_tb;
};
typedef struct Sinhvien Sinhvien;

struct NODE
{
    Sinhvien data;
    struct NODE *next;
};
typedef struct NODE NODE;

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct LIST LIST;

void createLIST(LIST *list)
{
    list->pHead = NULL;
    list->pTail = NULL;
}
NODE *createNode(Sinhvien sv)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = sv;
    return temp;
}

LIST *Add(LIST *list, NODE *node)
{
    if (list->pHead == NULL)
    {
        list->pHead = node;
        list->pTail = node;
    }
    else
    {
        list->pTail->next = node;
        list->pTail = node;
        printf("\nThem thanh cong!\n");
    }
    return list;
}
Sinhvien createSV(int i)
{
    Sinhvien sv;
    sv.stt = i;
    printf("\nNhap ho va ten: ");
    fflush(stdin);
    gets(sv.name);
    printf("\nNhap tuoi: ");
    fflush(stdin);
    fflush(stdin);
    scanf("%d", &sv.age);
    printf("\nNhap diem trung binh: ");
    fflush(stdin);
    scanf("%f", &sv.diem_tb);
    return sv;
}
void input(LIST *list, int i)
{
    Sinhvien sv = createSV(i);
    Add(list, createNode(sv));
    updateSTT(list);
}

void output(LIST *list)
{
    char arr[] = "===============Danh sach==============\n";
    char stt[] = "STT";
    char name[] = "Ho va ten";
    char age[] = "Tuoi";
    char diem[] = "Diem TB";
    printf("%40s", arr);
    printf("%5s%30s%10s%10s\n", stt, name, age, diem);
    NODE *temp = list->pHead;
    while (temp != NULL)
    {
        printf("%5d%30s%10d\t%.2f\n", (temp->data.stt + 1), temp->data.name, temp->data.age, temp->data.diem_tb);
        temp = temp->next;
    }
}
void updateSTT(LIST *list)
{
    NODE *temp = list->pHead;
    int i = 0;
    while (temp != NULL)
    {
        temp->data.stt = i;
        i++;
        temp = temp->next;
    }
}

void insertStudent(int vitri, LIST *list, int stt)
{
    if (vitri == 0)
    {
        NODE *temp = list->pHead;
        NODE *insert = (NODE *)malloc(sizeof(NODE));
        insert->next = temp;
        insert->data = createSV(0);
        list->pTail = insert;
        list->pHead = insert;
    }
    else if (vitri > stt)
    {
        NODE *insert = (NODE *)malloc(sizeof(NODE));
        insert->next = NULL;
        insert->data = createSV(stt);
        Add(list, insert);
    }
    else
    {
        for (NODE *p = list->pHead; p != NULL; p = p->next)
        {
            if (p->next->data.stt == (vitri - 1))
            {
                NODE *insert = (NODE *)malloc(sizeof(NODE));
                insert->next = p->next;
                insert->data = createSV(stt);
                p->next = insert;
                break;
            }
        }
    }
    updateSTT(list);
}

void deleteSv(LIST *list, char name[])
{
    NODE *temp = list->pHead;
    bool exits = true;
    if (stricmp(temp->data.name, name) == 0)
    {
        exits = false;
        list->pTail = temp->next;
        list->pHead = temp->next;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->next->data.name, name) == 0)
            {
                exits = false;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    updateSTT(list);
    if (exits)
    {
        printf("\nKhong tim thay sinh vien vui long thu lai! ");
    }
}

void menu()
{
    printf("1. Tao danh sach sinh vien\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Chen them sinh vien vao cuoi danh sach\n");
    printf("4. Chen them sinh vien\n");
    printf("5. Xoa mot sinh vien(theo ten)\n");
    printf("6. Sua mot sinh vien(theo ten)\n");
    printf("7. Ket thuc\n");
}

void suaSv(LIST *list, char name[])
{
    NODE *temp = list->pHead;
    bool exits = true;
    while (temp != NULL)
    {
        if (stricmp(temp->data.name, name) == 0)
        {
            exits = false;
            Sinhvien sv = createSV(temp->data.stt);
            strcpy(temp->data.name, sv.name);
            temp->data.age = sv.age;
            temp->data.diem_tb = sv.diem_tb;
            return;
        }
        temp = temp->next;
    }
    if (exits)
    {
        printf("\nKhong tim thay sinh vien vui long thu lai! ");
    }
}

int main()
{
    int stt = 0;
    int luachon = 0;
    LIST *list = (LIST *)malloc(sizeof(LIST));
    do
    {
        menu();
        printf("\nLua chon cua ban: ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 1:
        {
            createLIST(list);
            printf("Tao moi danh sach thanh cong!\n");
            break;
        }
        case 2:
        {
            output(list);
            break;
        }
        case 3:
        {
            input(list, stt);
            stt++;
            break;
        }
        case 4:
        {
            int vitri = 0;
            printf("\nNhap vi tri muon chen: ");
            scanf("%d", &vitri);
            insertStudent(vitri, list, stt);
            break;
        }
        case 5:
        {
            output(list);
            char name[50];
            printf("\nNhap ten sinh vien can xoa: ");
            fflush(stdin);
            gets(name);
            deleteSv(list, name);
            break;
        }
        case 6:
        {
            output(list);
            char name[50];
            printf("\nNhap ten sinh vien can sua: ");
            fflush(stdin);
            gets(name);
            suaSv(list, name);
            break;
        }
        case 7:
        {
            return 0;
        }
        }
    } while (luachon != 7);
    return 0;
}
