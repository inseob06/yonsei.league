/* main.c — 경기 전체 흐름 (담당: 신인섭) */
#define _CRT_SECURE_NO_WARNINGS     // Visual Studio의 scanf 오류(C4996) 막기 (#include보다 위에)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

// ※ 뼈대 파일: 함수 모양만 있고 내용은 비어 있다. 하나씩 완성해서 바꾼다. (담당: 신인섭)

int main(void)
{
    srand((unsigned int)time(NULL));            // 난수 시드는 처음에 한 번만

    printf("========== 텍스트 야구 게임 ==========\n");
    printf("(뼈대 버전: 컴파일 확인용)\n");

    // TODO: 이닝 수 입력, 이닝 반복(초·말), 점수판, 승패 출력
    return 0;
}

void play_half(Team *bat, Team *field, int inning, int user_bats, int last)
{
    // TODO: 3아웃까지 play_at_bat 반복, 득점·안타 기록, 끝내기 처리
}
