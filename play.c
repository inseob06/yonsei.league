// play.c — 투구·타격·판정·주자 (담당: 황지현) 
#define _CRT_SECURE_NO_WARNINGS     // Visual Studio의 scanf 오류(C4996) 막기 (#include보다 위에)
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

// ※ 뼈대 파일: 함수 모양만 있고 내용은 비어 있다. 하나씩 완성해서 바꾼다. (담당: 황지현)

int is_next_to(int a, int b)
{
    int a_row = (a - 1) / 3, a_col = (a - 1) % 3; // 칸 번호 -> 행, 열
    int b_row = (b - 1) / 3, b_col = (b - 1) % 3;
    // TODO: 두 칸이 위·아래·왼쪽·오른쪽으로 붙어 있으면 1, 아니면 0
    return abs(a_row - b_row) + abs(a_col - b_col) == 1;
}

void choose_pitch(Pitch *p, Situation *s, int user)
{
    // TODO: 사람(user==1)은 입력, 컴퓨터는 볼카운트를 보고 난수로 코스·구종 결정
    int ball_chance;

    if (user == 1) {
        printf(" 던질 칸 (1~9, 볼은 0): ");
        p->course = read_number(0, 9);
        printf("  구종 (1 직구, 2 변화구): ");
        p->type = read_number(1, 2);
        return;
    }

    if (s->ball == 3) {
        ball_chance = 5;
    }
    else if (s->strike == 2) {
        ball_chance = 40;
    }
    else {
        ball_chance = 20;
    }

    if (rand() % 100 < ball_chance) {
        p->course = 0;
    }
    else {
        p->course = rand() % 9 + 1;
    }
    p->type = rand() % 2 + 1;
}

int choose_swing(Pitch *p, Situation *s, int user)
{
    // TODO: 노릴 칸(1~9) 또는 지켜보기(0)를 돌려준다
    int swing_chance;

    if (user == 1) {
        printf(" 노릴 칸(1~9, 지켜보기 0) :");
        return read_number(0, 9);
    }

    if (p->course == 0) {
          swing_chance = 30;
    } 
    else if (s->strike == 2) {
           swing_chance = 90;
    } 
    else {
           swing_chance = 70;
    }
  
    if (rand() % 100 < swing_chance) {
           return rand() % 9 + 1;                  // 1~9 중 한 칸을 노림
    }
    return 0;
}

int judge(Pitch *p, int aim)
{
    // TODO: BALL / STRIKE / FOUL / INPLAY 중 하나를 돌려준다
    int chance;

    if (aim == 0) {
        if (p->course == 0) {
            return BALL;
        }
        return STRIKE;
    }

    if (p->course == 0) {
        chance = 15;
    }
    else if (p->course == aim) {
        chance = 80;
    }
    else if (is_next_to(p->course, aim)) {
        chance = 55;
    }
    else {
        chance = 20;
    }
    if (p->type == 2) {
        chance = chance - 15;
    }

    if (rand() % 100 >= chance) {
        return STRIKE;
    }
    if (rand() % 100 < 25) {
        return FOUL;
    }
    return INPLAY; 
}

int hit_result(void)
{
    // TODO: 확률로 OUT / SINGLE / DOUBLE / TRIPLE / HOMERUN 중 하나
    return OUT;
}

int run_bases(Situation *s, int n)
{
    // TODO: 모든 주자와 타자를 n칸 진루, 들어온 점수를 돌려준다
    return 0;
}

int walk(Situation *s)
{
    // TODO: 볼넷 — 밀려나는 주자만 진루, 들어온 점수를 돌려준다
    return 0;
}

int play_at_bat(Team *bat, Situation *s, int user_bats)
{
    // TODO: 한 타석 진행. 삼진이면 OUT, 볼넷이면 WALK, 타구면 hit_result() 결과
    printf("  (아직 play_at_bat 미완성: 무조건 아웃)\n");
    return OUT;
}
