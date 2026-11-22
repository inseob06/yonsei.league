/* main.c — 경기 전체 흐름 (담당: 신인섭) */
#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"



int main(void)
{
    srand((unsigned int)time(NULL));           

    printf("========== 텍스트 야구 게임 ==========\n");
    printf("(뼈대 버전: 컴파일 확인용)\n");

   
    return 0;
}

void play_half(Team *bat, Team *field, int inning, int user_bats, int last)
{
    
}
