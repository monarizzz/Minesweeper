#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y, Bomb_Sum;
    // ユーザー入力 表のマスの数
    printf("横のマスの数は？ x\n");
    scanf("%d", &x);
    printf("縦のマスの数は？ y\n");
    scanf("%d", &y);
    printf("爆弾の数は？ \n");
    scanf("%d", &Bomb_Sum);

    int count = 0;
    int U_x, U_y, U_x_1, U_y_1;
    int table[x][y];

    // 表 定義
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            table[j][i] = 0;
        }
    }

    // ユーザーによるマスの選択
    printf("どこを開けますか？ x\n");
    scanf("%d", &U_x_1);
    while (U_x_1 < 1 || U_x_1 > x)
    {
        printf("範囲を確認してください\n");
        printf("どこを開けますか？ x\n");
        scanf("%d", &U_x_1);
    }

    printf("どこを開けますか？ y\n");
    scanf("%d", &U_y_1);
    while (U_y_1 < 1 || U_y_1 > y)
    {
        printf("範囲を確認してください\n");
        printf("どこを開けますか？？ x\n");
        scanf("%d", &U_y_1);
    }

    printf("あなたが選んだマスは[%d,%d]です\n\n", U_x_1, U_y_1);

    U_x = U_x_1 - 1;
    U_y = U_y_1 - 1;

    // 表の中の爆弾の数 ランダム1~Bomb_Sum こ
    int Bomb_Num = Bomb_Sum;
    for (int i = 0; i < Bomb_Num; i++)
    {
        // 爆弾の位置
        int Bomb_x = rand() % x;
        int Bomb_y = rand() % y;
        // 表示上 BOMB位置
        int U_Bomb_x = Bomb_x + 1;
        int U_Bomb_y = Bomb_y + 1;

        // 重複回避
        if (table[Bomb_y][Bomb_x] == 0)
        {
            table[Bomb_y][Bomb_x] = 1;
        }
        else
        {
            // 内部 BOMB位置
            Bomb_x = rand() % x;
            Bomb_y = rand() % y;
            table[Bomb_y][Bomb_x] = 1;
            // 表示上 BOMB位置
            int U_Bomb_x = Bomb_x + 1;
            int U_Bomb_y = Bomb_y + 1;
        }
        // 爆弾の位置確認
        // printf("爆弾の位置は%d,%d\n", U_Bomb_x, U_Bomb_y);

        // ユーザーが爆弾の位置を選んでいた場合
        if (Bomb_x == U_x && Bomb_y == U_y)
        {
            printf("爆発しました！\n");
            return 0;
        }
    }

    // 周りにある爆弾の個数
    int judge_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int judge_y[8] = {-1, 1, 0, -1, 1, -1, 1, 0};

    for (int k = 0; k < 8; k++)
    {
        int Count_x = U_x + judge_x[k];
        int Count_y = U_y + judge_y[k];

        if (table[Count_y][Count_x] > 0 && 0 <= Count_x && Count_x < x && 0 <= Count_y && Count_y < y)
        {
            count += table[Count_y][Count_x];
        }
    }

    printf("爆弾は%d個!\n\n", count);

    // 表の表示
    for (int i = 0; i < x; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < x; i++)
    {
        printf("--");
    }
    printf("\n");

    for (int l = 0; l < y; l++)
    {
        for (int m = 0; m < x; m++)
        {
            printf("%d ", table[l][m]);
        }
        printf("| %d\n", l + 1);
    }

    return 0;
}