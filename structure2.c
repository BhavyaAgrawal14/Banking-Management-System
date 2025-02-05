#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Array_size 100

typedef struct Bank_Details
{
    int ac_num;
    char name[100];
    float bal;
} Bank_Details;

void bank_balance_details(Bank_Details p[])
{
    for (int i = 0; i < Array_size; i++)
    {
        if (p[i].bal < 100)
        {
            printf("%s => %d\n", p[i].name, p[i].ac_num);
            break;
        }
        else
        {
            printf("No record found");
        }
    }
}

void withdrawal_deposit(Bank_Details p[])
{
    int code, acc_num, choice;
    printf("For withdrawal enter 0\n");
    printf("For deposit enter 1\n");
    printf("______________________________________________________________________\n");

    float amount;

    printf("Enter your account number: ");
    scanf("%d", &acc_num);

    printf("Enter the amount: ");
    scanf("%f", &amount);

    printf("Enter your choice: ");
    scanf("%d", &choice);

    system("cls");

    int flag = 0;
    int i = 0;

    if (choice == 0)
    {
        for (int i = 0; i < Array_size; i++)
        {
            if (acc_num == p[i].ac_num)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            if (amount <= p[i].bal)
                {
                    printf("Rs.%f is successfully withdrawn\n", amount);
                    printf("Your balance is %f\n", p[i].bal-amount);
                }
                else
                {
                    printf("Insufficient bank balance\n");
                }
        }
        else
        {
            printf("No such account found\n");
        }
    }
    else if (choice == 1)
    {
        for (int i = 0; i < Array_size; i++)
        {
            if (acc_num == p[i].ac_num)
            {
                printf("Rs.%f is successfully deposited\n", amount);
                printf("Your balance is %f\n", p[i].bal + amount);
                break;
            }
            else
            {
                printf("No such account found\n");
            }
        }
    }
    else
    {
        printf("Invalid choice entered");
    }
}

int main()
{
    Bank_Details p[Array_size];

    for (int i = 0; i < Array_size; i++)
    {

        printf("Enter the name of account holder %d: ", i + 1);
        fgets(p[i].name, 100, stdin);
        p[i].name[strcspn(p[i].name, "\n")] = '\0';

        printf("Enter your account number: ");
        scanf("%d", &p[i].ac_num);

        printf("Enter the balance in your account: ");
        scanf("%f", &p[i].bal);

        printf("______________________________________________________________________\n");

        fgetc(stdin);
    }

    system("cls");

    printf("Enter 1 to get data for a particular bank balance\n");
    printf("Enter 2 for withdrawal or deposit\n");
    printf("______________________________________________________________________\n");

    int x;

    printf("Enter your choice: ");
    scanf("%d", &x);

    system("cls");

    if (x == 1)
    {
        bank_balance_details(p);
    }

    else if (x == 2)
    {
        withdrawal_deposit(p);
    }

    else
    {
        printf("Invalid choice entered");
    }

    return 0;
}