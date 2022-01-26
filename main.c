#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define MAX_LINE 100

/// ���������� ����������� ��� ������ ��� �������� ���������� � ������� � �������, � ������� ��� ���������.
typedef struct
{
    char country[MAX_LINE]; // c�����
    char city[MAX_LINE]; // �����
} CountryInfo;

/// �������� �������, ������� �������� �������� �������, ����������� � ��������� ������.
void FindCity(CountryInfo* arr, int count, char* country)
{
    for(int i = 0; i < count; i++)
        if (strcmp(arr[i].country, country) == 0) // ����� ����� ������
            printf("%s ", arr[i].city); // ����� �������
}

/// ���������� ����������� ��� ������ ��� �������� ���������� � �������: ������������, ���� � ������ � ��������.
typedef struct
{
    char name[MAX_LINE]; // ������������
    float price; // ����
} PriceInfo;

/// �������� �������, ������������ �������� ����� �������� �� ���� ��������� �������.
void HighPrice(PriceInfo product1, PriceInfo product2)
{
    printf("\n����� ������� �����: ");

    if (product1.price > product2.price)
        printf("%s", product1.name);
    else
        printf("%s", product2.name);
}

/// ���������� ����������� ��� ������ ����������� �����: (�������, ����� ��������).
typedef struct
{
    char lastname[MAX_LINE]; // �������
    char number[MAX_LINE]; // ����� ��������
} PhoneBook;

/// �������� �������, ������� �� �������� ������� ���������� ����� ��������. ���� ������� ���, ���������� NULL.
void PhoneNumber(PhoneBook* arr, int count, char* lastname)
{
    for(int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].lastname, lastname) == 0) // ����� ����� �������
        {
            printf("%s", arr[i].number); // ����� ������ ��������
            break; // ���������� �����
        }
        else if (i == count - 1) // ���� ���� ������ �� ���� ���������� ����� � �� ����� �������
        {
            printf("������ ������ ���.\n");
            return NULL;
        }
    }
}

/// �������� �������, ������� �� ��������� ������ �������� ���������� ������� ���������. ���� ������ ���, ���������� NULL.
void PhoneLastname(PhoneBook* arr, int count, char* number)
{
    for(int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].number, number) == 0) // ����� ����� ����� ��������
        {
            printf("%s", arr[i].lastname); // ����� �������
            break; // ���������� �����
        }
        else if (i == count - 1) // ���� ���� ������ �� ���� ���������� ����� � �� ����� �������
        {
            printf("����� ������� ���.\n");
            return NULL;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("\t����� ������� ������ ��������������?\n\n"
           "1 - ������ � ��������� ������\n"
           "2 - ����� ������� �����\n"
           "3 - ���������� �����\n\n");

    int choice;
    scanf("%d", &choice);

    while ((choice < 1) | (choice > 3))
    {
        printf("\n������� ����� �� 1 �� 3! ");
        scanf("%d", &choice);
    }

    if (choice == 1)
    {
        printf("\n\t����� �������� �������, ����������� � ��������� ������.\n\n"
               "������� ���������� ������� ����� � �������: ");

        int count; // ���������� �������� ����� ����� � �������
        scanf("%d", &count);

        CountryInfo arr[count]; // ������������� ���������

        for(int i = 0; i < count; i++)
        {
            printf("\n������� ������ � �����: ");
            scanf("%s %s", arr[i].country, arr[i].city);
        }

        char info[MAX_LINE]; // ��������� ������
        fflush(stdin); // ��� ��������

        printf("\n������� ������: ");
        gets(info);

        printf("\n������ � ���� ������: ");
        FindCity(arr, count, info);
    }

    if (choice == 2)
    {
        PriceInfo product1, product2; // ������������� ���������

        printf("\n\t����� �������� ����� �������� �� ���� ��������� �������.\n\n"
               "������� ������������ ������� ������ � ��� ����: ");
        scanf("%s %f", product1.name, &product1.price);

        printf("\n������� ������������ ������� ������ � ��� ����: ");
        scanf("%s %f", product2.name, &product2.price);

        HighPrice(product1, product2);
    }

    if (choice == 3)
    {
        printf("\n\t���������� �����.\n\n"
               "������� ���������� ������� � ���������� �����: ");
        int count; // ���������� �������� ����� ������� � ������� ���������
        scanf("%d", &count);

        PhoneBook arr[count]; // ������������� ���������

        for(int i = 0; i < count; i++)
        {
            printf("\n������� ������� � ����� ��������: ");
            scanf("%s %s", arr[i].lastname, arr[i].number);
        }

        char info[MAX_LINE]; // ��������� ������� � ����� ��������
        fflush(stdin); // ��� ��������

        printf("\n\n\t����� ������ �������� �� �������� �������.\n\n"
               "������� �������: ");
        gets(info);

        printf("\n����� ��������: ");
        PhoneNumber(arr, count, info);

        printf("\n\n\n\t����� ������� �� ��������� ������ ��������.\n\n"
               "������� ����� ��������: ");
        gets(info);

        printf("\n�������: ");
        PhoneLastname(arr, count, info);
    }

    getch();
    return 0;
}
