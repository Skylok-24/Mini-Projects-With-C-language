#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int winner(char **t)
{
    if (t[0][0] == 'O' && t[0][0] == t[0][1] && t[0][1] == t[0][2])
    {
        return 1;
    }
    else if (t[0][0] == 'X' && t[0][0] == t[0][1] && t[0][1] == t[0][2])
    {
        return -1;
    }
    else if (t[1][0] == 'O' && t[1][0] == t[1][1] && t[1][1] == t[1][2])
    {
        return 1;
    }
    else if (t[1][0] == 'X' && t[1][0] == t[1][1] && t[1][1] == t[1][2])
    {
        return -1;
    }
    else if (t[2][0] == 'O' && t[2][0] == t[2][1] && t[2][1] == t[2][2])
    {
        return 1;
    }
    else if (t[2][0] == 'X' && t[2][0] == t[2][1] && t[2][1] == t[2][2])
    {
        return -1;
    }
    else if (t[0][0] == 'O' && t[0][0] == t[1][0] && t[1][0] == t[2][0])
    {
        return 1;
    }
    else if (t[0][0] == 'X' && t[0][0] == t[1][0] && t[1][0] == t[2][0])
    {
        return -1;
    }
    else if (t[0][1] == 'O' && t[0][1] == t[1][1] && t[1][1] == t[2][1])
    {
        return 1;
    }
    else if (t[0][1] == 'X' && t[0][1] == t[1][1] && t[1][1] == t[2][1])
    {
        return -1;
    }
    else if (t[0][2] == 'O' && t[0][2] == t[1][2] && t[1][2] == t[2][2])
    {
        return 1;
    }
    else if (t[0][2] == 'X' && t[0][2] == t[1][2] && t[1][2] == t[2][2])
    {
        return -1;
    }
    else if (t[0][0] == 'O' && t[0][0] == t[1][1] && t[1][1] == t[2][2])
    {
        return 1;
    }
    else if (t[0][0] == 'X' && t[0][0] == t[1][1] && t[1][1] == t[2][2])
    {
        return -1;
    }
    else if (t[0][2] == 'O' && t[0][2] == t[1][1] && t[1][1] == t[2][0])
    {
        return 1;
    }
    else if (t[0][2] == 'X' && t[0][2] == t[1][1] && t[1][1] == t[2][0])
    {
        return -1;
    }
}
int choose_player()
{
    srand(time(NULL));
    return rand() % 2;
}
int main()
{
    char **play_table = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        play_table[i] = malloc(3 * sizeof(char));
    }
    char player1 = 'O';
    char player2 = 'X';
    int t = choose_player(), x, i, j, s;
    printf("\t====XO GAME====\n");
    printf("\tpress 1 to play\t");
    printf("\t0:EXIT\n");
    scanf("%d", &x);
    if (x == 0)
    {
        /* code */
    }
    else
    {
        char pl1[50], pl2[50];
        printf("player 1 --> enter your name : ");
        scanf("%s", pl1);
        printf("player 2 --> enter your name : ");
        scanf("%s", pl2);
        if (t == 1)
        {
            s = 1;
            printf("%s will be started \n", pl1);
        }
        else
        {
            s = -1;
            printf("%s will be started \n", pl2);
        }
        int n = 0;
        do
        {
            printf("   1  2  3 \n");
            for (i = 0; i < 3; i++)
            {
                printf("%d |", i + 1);
                for (j = 0; j < 3; j++)
                {
                    printf(" %c ", play_table[i][j]);
                    printf("|");
                }
                printf("\n");
            }
            printf("enter the num of row:");
            scanf("%d", &i);
            printf("enter the num of column:");
            scanf("%d", &j);
            if (s == 1)
            {
                play_table[i - 1][j - 1] = player1;
                s = -1;
            }
            else if (s == -1)
            {
                play_table[i - 1][j - 1] = player2;
                s = 1;
            }
            if (winner(play_table) == 1)
            {
                printf("   1  2  3 \n");
                for (i = 0; i < 3; i++)
                {
                    printf("%d |", i + 1);
                    for (j = 0; j < 3; j++)
                    {
                        printf(" %c ", play_table[i][j]);
                        printf("|");
                    }
                    printf("\n");
                }
                printf("%s is the winner \n", pl1);
                break;
            }
            else if (winner(play_table) == -1)
            {
                printf("   1  2  3 \n");
                for (i = 0; i < 3; i++)
                {
                    printf("%d |", i + 1);
                    for (j = 0; j < 3; j++)
                    {
                        printf(" %c ", play_table[i][j]);
                        printf("|");
                    }
                    printf("\n");
                }
                printf("%s is the winner\n", pl2);
                break;
            }
            n++;
        } while (n != 9);
        if (n == 9)
        {
            printf("The result is a draw \n");
            printf("   1  2  3 \n");
            for (i = 0; i < 3; i++)
            {
                printf("%d | ", i + 1);
                for (j = 0; j < 3; j++)
                {
                    printf(" %c ", play_table[i][j]);
                    printf(" | ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}