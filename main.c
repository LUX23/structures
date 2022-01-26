#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define MAX_LINE 100

/// Определить структурный тип данных для хранения информации о городах и странах, в которых они находятся.
typedef struct
{
    char country[MAX_LINE]; // cтрана
    char city[MAX_LINE]; // город
} CountryInfo;

/// Написать функцию, которая печатает названия городов, находящихся в указанной стране.
void FindCity(CountryInfo* arr, int count, char* country)
{
    for(int i = 0; i < count; i++)
        if (strcmp(arr[i].country, country) == 0) // когда найдёт страну
            printf("%s ", arr[i].city); // вывод городов
}

/// Определить структурный тип данных для хранения информации о товарах: наименование, цена в рублях и копейках.
typedef struct
{
    char name[MAX_LINE]; // наименование
    float price; // цена
} PriceInfo;

/// Написать функцию, возвращающую название более дорогого из двух указанных товаров.
void HighPrice(PriceInfo product1, PriceInfo product2)
{
    printf("\nСамый дорогой товар: ");

    if (product1.price > product2.price)
        printf("%s", product1.name);
    else
        printf("%s", product2.name);
}

/// Определить структурный тип данных «Телефонная книга»: (фамилия, номер телефона).
typedef struct
{
    char lastname[MAX_LINE]; // фамилия
    char number[MAX_LINE]; // номер телефона
} PhoneBook;

/// Написать функцию, которая по заданной фамилии возвращает номер телефона. Если фамилии нет, возвращает NULL.
void PhoneNumber(PhoneBook* arr, int count, char* lastname)
{
    for(int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].lastname, lastname) == 0) // когда найдёт фамилию
        {
            printf("%s", arr[i].number); // вывод номера телефона
            break; // завершение цикла
        }
        else if (i == count - 1) // если цикл прошел по всей телефонной книге и не нашел фамилию
        {
            printf("Такого номера нет.\n");
            return NULL;
        }
    }
}

/// Написать функцию, которая по заданному номеру телефона возвращает фамилию владельца. Если номера нет, возвращает NULL.
void PhoneLastname(PhoneBook* arr, int count, char* number)
{
    for(int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].number, number) == 0) // когда найдёт номер телефона
        {
            printf("%s", arr[i].lastname); // вывод фамилии
            break; // завершение цикла
        }
        else if (i == count - 1) // если цикл прошел по всей телефонной книге и не нашел фамилию
        {
            printf("Такой фамилии нет.\n");
            return NULL;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("\tКакую функцию хотите протестировать?\n\n"
           "1 - Города в указанной стране\n"
           "2 - Самый дорогой товар\n"
           "3 - Телефонная книга\n\n");

    int choice;
    scanf("%d", &choice);

    while ((choice < 1) | (choice > 3))
    {
        printf("\nВведите цифру от 1 до 3! ");
        scanf("%d", &choice);
    }

    if (choice == 1)
    {
        printf("\n\tВывод названия городов, находящихся в указанной стране.\n\n"
               "Введите количество записей стран и городов: ");

        int count; // количество итераций ввода стран и городов
        scanf("%d", &count);

        CountryInfo arr[count]; // инициализация структуры

        for(int i = 0; i < count; i++)
        {
            printf("\nВведите страну и город: ");
            scanf("%s %s", arr[i].country, arr[i].city);
        }

        char info[MAX_LINE]; // введенная страна
        fflush(stdin); // для задержки

        printf("\nВведите страну: ");
        gets(info);

        printf("\nГорода в этой стране: ");
        FindCity(arr, count, info);
    }

    if (choice == 2)
    {
        PriceInfo product1, product2; // инициализация структуры

        printf("\n\tВывод названия более дорогого из двух указанных товаров.\n\n"
               "Введите наименование первого товара и его цену: ");
        scanf("%s %f", product1.name, &product1.price);

        printf("\nВведите наименование второго товара и его цену: ");
        scanf("%s %f", product2.name, &product2.price);

        HighPrice(product1, product2);
    }

    if (choice == 3)
    {
        printf("\n\tТелефонная книга.\n\n"
               "Введите количество записей в телефонной книге: ");
        int count; // количество итераций ввода фамилий и номеров телефонов
        scanf("%d", &count);

        PhoneBook arr[count]; // инициализация структуры

        for(int i = 0; i < count; i++)
        {
            printf("\nВведите фамилию и номер телефона: ");
            scanf("%s %s", arr[i].lastname, arr[i].number);
        }

        char info[MAX_LINE]; // введенная фамилия и номер телефона
        fflush(stdin); // для задержки

        printf("\n\n\tВывод номера телефона по заданной фамилии.\n\n"
               "Введите фамилию: ");
        gets(info);

        printf("\nНомер телефона: ");
        PhoneNumber(arr, count, info);

        printf("\n\n\n\tВывод фамилии по заданному номеру телефона.\n\n"
               "Введите номер телефона: ");
        gets(info);

        printf("\nФамилия: ");
        PhoneLastname(arr, count, info);
    }

    getch();
    return 0;
}
