#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int d, m, y;
} date;
typedef struct
{
    int ID_number;
    char First_name[50];
    char Last_name[50];
    date date_of_birth;
    char address[100];
    int class;
    int contact;
    float average;
} student_Records;
int Add(student_Records *p, int n, int ID_number, char *First_name, char *Last_name, date date_of_birth, char *address, int class, int contact, float average)
{
    int i = n;
    p[i].ID_number = ID_number;
    strcpy(p[i].First_name, First_name);
    strcpy(p[i].Last_name, Last_name);
    p[i].date_of_birth.d = date_of_birth.d;
    p[i].date_of_birth.m = date_of_birth.m;
    p[i].date_of_birth.y = date_of_birth.y;
    strcpy(p[i].address, address);
    p[i].class = class;
    p[i].contact = contact;
    p[i].average = average;
    n++;
    return n;
}
int Search(student_Records *p, int n, char *First_name, char *Last_name)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].First_name, First_name) == 0 && strcmp(p[i].Last_name, Last_name) == 0)
        {
            break;
        }
    }
    if (strcmp(p[i].First_name, First_name) == 0 && strcmp(p[i].Last_name, Last_name) == 0)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int Delete(student_Records *p, int n, int Record_Index, float **Mark_atrix)
{
    int i;
    for (i = Record_Index; i < n; i++)
    {
        p[i].ID_number = p[i + 1].ID_number;
        strcpy(p[i].First_name, p[i + 1].First_name);
        strcpy(p[i].Last_name, p[i + 1].Last_name);
        p[i].date_of_birth.d = p[i + 1].date_of_birth.d;
        p[i].date_of_birth.m = p[i + 1].date_of_birth.m;
        p[i].date_of_birth.y = p[i + 1].date_of_birth.y;
        strcpy(p[i].address, p[i + 1].address);
        p[i].class = p[i + 1].class;
        p[i].contact = p[i + 1].contact;
        p[i].average = p[i + 1].average;
        Mark_atrix[i][0] = Mark_atrix[i + 1][0];
        Mark_atrix[i][1] = Mark_atrix[i + 1][1];
        Mark_atrix[i][2] = Mark_atrix[i + 1][2];
        Mark_atrix[i][3] = Mark_atrix[i + 1][3];
    }
    n--;
    return n;
}
float Fill_Marks(float **Mark_atrix, int Record_index, float subj1, float subj2, float subj3, float subj4)
{
    Mark_atrix[Record_index][0] = subj1;
    Mark_atrix[Record_index][1] = subj2;
    Mark_atrix[Record_index][2] = subj3;
    Mark_atrix[Record_index][3] = subj4;
    return (subj1 + subj2 + subj3 + subj4) / 4;
}
void Display_Record(student_Records *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("student number %d: \n", i + 1);
        printf("ID Number: %d \n", p[i].ID_number);
        printf("First Name: %s \n", p[i].First_name);
        printf("Last Name: %s \n", p[i].Last_name);
        printf("Date of Birth: %d/%d/%d \n", p[i].date_of_birth.d, p[i].date_of_birth.m, p[i].date_of_birth.y);
        printf("Adress: %s \n", p[i].address);
        printf("Class: %d \n", p[i].class);
        printf("Emergency Contact: %d \n ", p[i].contact);
        printf("Overall Average: %.2f \n", p[i].average);
    }
}
void Display_Report_Card(student_Records *p, int Record_index, float **Mark_atrix)
{
    int i = Record_index;
    printf("student number %d: \n", i);
    printf("ID Number: %d \n", p[i].ID_number);
    printf("First Name: %s \n", p[i].First_name);
    printf("Last Name: %s \n", p[i].Last_name);
    printf("Date of Birth: %d/%d/%d \n", p[i].date_of_birth.d, p[i].date_of_birth.m, p[i].date_of_birth.y);
    printf("Adress: %s \n", p[i].address);
    printf("Class: %d \n", p[i].class);
    printf("Emergency Contact: %d \n ", p[i].contact);
    printf("Overall Average: %.2f \n", p[i].average);
    printf("\t==========================\n");
    printf("Marks: \n");
    printf("Physics: %.2f   ", Mark_atrix[i][0]);
    printf("Math: %.2f   ", Mark_atrix[i][1]);
    printf("Arabic: %.2f   ", Mark_atrix[i][2]);
    printf("English: %.2f  ", Mark_atrix[i][3]);
}
void Display_By_Criteria(student_Records *p, int n, float v, char *c)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].First_name, c) == 0 || strcmp(p[i].Last_name, c) == 0 || strcmp(p[i].address, c) == 0 || p[i].average == v || p[i].class == v || p[i].contact == v || p[i].ID_number == v || p[i].date_of_birth.d == v || p[i].date_of_birth.m == v || p[i].date_of_birth.y == v)
        {
            printf("student number %d: \n", i + 1);
            printf("ID Number: %d \n", p[i].ID_number);
            printf("First Name: %s \n", p[i].First_name);
            printf("Last Name: %s \n", p[i].Last_name);
            printf("Date of Birth: %d/%d/%d \n", p[i].date_of_birth.d, p[i].date_of_birth.m, p[i].date_of_birth.y);
            printf("Adress: %s \n", p[i].address);
            printf("Class: %d \n", p[i].class);
            printf("Emergency Contact: %d \n ", p[i].contact);
            printf("Overall Average: %.2f \n", p[i].average);
        }
    }
}
int main()
{
    float **Mark_Matrix = malloc(1000 * sizeof(float *));
    for (int j = 0; j < 100; j++)
    {
        Mark_Matrix[j] = (float *)malloc(4 * sizeof(float));
    }
    student_Records a[100];
    int c, i = 0;
    do
    {
        printf("\t===== Student Record Management System =====\n");
        printf("\t============================================\n");
        printf("\t1> Add new student record\n");
        printf("\t2> Delet a student record\n");
        printf("\t3> Display a student record\n");
        printf("\t4> Fill in Marks of student\n");
        printf("\t5> Display a report card of a specific student\n");
        printf("\t6> search\n");
        printf("\t============================================");
        printf("\n");
        printf("0> EXIT \n");
        printf("enter youre choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            int ID;
            char First[50], Last[50];
            date date_birth;
            char addr[100];
            int clas, conct;
            float aver;
            printf("enter the First Name:");
            scanf("%s", First);
            printf("enter the Last Name:");
            scanf("%s", Last);
            printf("enter the ID number:");
            scanf("%d", &ID);
            printf("enter the date of birth:\n");
            printf("day:");
            scanf("%d", &date_birth.d);
            printf("month:");
            scanf("%d", &date_birth.m);
            printf("year:");
            scanf("%d", &date_birth.y);
            printf("enter the address:");
            scanf("%s", addr);
            printf("enter tha class:");
            scanf("%d", &clas);
            printf("enter the contact:");
            scanf("%d", &conct);
            aver = 0;
            i = Add(a, i, ID, First, Last, date_birth, addr, clas, conct, aver);
            break;
        case 2:
            char st1[50], st2[50];
            printf("enter the First Name:");
            scanf("%s", st1);
            printf("enter the Last Name:");
            scanf("%s", st2);
            int j;
            j = Search(a, i, st1, st2);
            if (j == -1)
            {
                printf("these name is not exist\n");
            }
            else
            {
                i = Delete(a, i, j, Mark_Matrix);
            }
            break;
        case 3:
            Display_Record(a, i);
            break;
        case 4:
            char st3[50], st4[50];
            printf("enter the First Name:");
            scanf("%s", st3);
            printf("enter the Last Name:");
            scanf("%s", st4);
            i = Search(a, i, st3, st4);
            if (i == -1)
            {
                printf("these name is not exist\n");
            }
            else
            {
                float s1, s2, s3, s4, m;
                printf("enter the mark of Physics:");
                scanf("%f", &s1);
                printf("enter the mark of Math:");
                scanf("%f", &s2);
                printf("enter the mark of Arabic:");
                scanf("%f", &s3);
                printf("enter the mark of English:");
                scanf("%f", &s4);
                m = Fill_Marks(Mark_Matrix, i, s1, s2, s3, s4);
                a[i].average = m;
            }
            break;
        case 5:
            char st5[50], st6[50];
            printf("enter the First Name:");
            scanf("%s", st5);
            printf("enter the Last Name:");
            scanf("%s", st6);
            Display_Report_Card(a, Search(a, i, st5, st6), Mark_Matrix);
            break;
        case 6:
            int x;
            printf("\tChoose what you want to search for:");
            printf("\t1> By First Name ?\n");
            printf("\t2> By Last Name ?\n");
            printf("\t3> By Address ?\n");
            printf("\t4> By average or ID number or class ? \n");
            printf("enter youre choice:");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                char st[50];
                printf("enter the First Name:");
                scanf("%s", st);
                Display_By_Criteria(a, i, -999, st);
                break;
            case 2:
                char st1[50];
                printf("enter the Last Name:");
                scanf("%s", st1);
                Display_By_Criteria(a, i, -999, st1);
                break;
            case 3:
                char st3[50];
                printf("enter the Address:");
                scanf("%s", st3);
                Display_By_Criteria(a, i, -999, st);
                break;
            case 4:
                float b;
                printf("enter average or ID number or class:");
                scanf("%f", &b);
                Display_By_Criteria(a, i, b, NULL);
                break;
            default:
                printf("error, You entered the wrong number !");
                break;
            }
            break;
        case 0:
            printf("goodbye \n");
            break;
        default:
            printf("error, You entered the wrong number !");
            break;
        }
    } while (c != 0);

    return 0;
}