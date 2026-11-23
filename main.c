// main.c - 신인섭
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main(void)
{
    Team me = { "내 팀", { 0 }, 0, 0, 1 };
    Team com = { "컴퓨터", { 0 }, 0, 0, 1 };

    srand((unsigned int)time(NULL));

    printf("텍스트 야구 게임\n");

    // 1회 초 (내가 공격)
    printf("\n1회 초\n");
    play_half(&me, &com, 0, 1, 0);

    // 1회 말 (컴퓨터 공격)
    printf("\n1회 말\n");
    play_half(&com, &me, 0, 0, 0);

    printf("\n1회 끝 %d : %d\n", me.score[0], com.score[0]);
    return 0;
}

// 3아웃 될 때까지 타석 반복
void play_half(Team *bat, Team *field, int inning, int user_bats, int last)
{
    Situation s = { 0, 0, 0, { 0, 0, 0 } };
    int runs = 0;
    int r;

    while (s.outs < 3) {
        r = play_at_bat(bat, &s, user_bats);
        printf("결과: %d\n", r);
        s.outs++;

        bat->batter++;
        if (bat->batter > 9) {
            bat->batter = 1;
        }
    }

    bat->score[inning] = runs;
    printf("%s %d점\n", bat->name, runs);
}
