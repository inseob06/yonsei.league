/* display.c — 화면 출력과 입력 (담당: 신인섭) */
#define _CRT_SECURE_NO_WARNINGS     // Visual Studio의 scanf 오류(C4996) 막기 (#include보다 위에)
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

// ※ 뼈대 파일: 함수 모양만 있고 내용은 비어 있다. 하나씩 완성해서 바꾼다. (담당: 신인섭)

int read_number(int min, int max)
{
    // TODO: min~max 사이 숫자를 입력받아 돌려준다. 잘못 입력하면 다시 묻는다.
    return min;
}

void print_zone(int course, int aim)
{
    // TODO: 3x3 스트라이크존을 그린다. 공은 *, 노린 칸은 O, 둘이 같으면 @
}

void print_mark(int on)
{
    // TODO: on이 1이면 ●, 아니면 ○ 출력
}

void print_bases(Situation *s)
{
    // TODO: 주자 상황(1·2·3루)과 아웃 수를 다이아몬드 모양으로 출력
}

void print_scoreboard(Team *away, Team *home, int innings, int done)
{
    // TODO: 이닝별 점수, 득점(R), 안타(H) 점수판 출력
}
