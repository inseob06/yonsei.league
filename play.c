/* play.c — 투구·타격·판정·주자 (담당: 황지현) */
#define _CRT_SECURE_NO_WARNINGS     // Visual Studio의 scanf 오류(C4996) 막기 (#include보다 위에)
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

// ※ 뼈대 파일: 함수 모양만 있고 내용은 비어 있다. 하나씩 완성해서 바꾼다. (담당: 황지현)

int is_next_to(int a, int b)
{
    // TODO: 두 칸이 위·아래·왼쪽·오른쪽으로 붙어 있으면 1, 아니면 0
    return 0;
}

void choose_pitch(Pitch *p, Situation *s, int user)
{
    // TODO: 사람(user==1)은 입력, 컴퓨터는 볼카운트를 보고 난수로 코스·구종 결정
    p->course = 5;
    p->type = 1;
}

int choose_swing(Pitch *p, Situation *s, int user)
{
    // TODO: 노릴 칸(1~9) 또는 지켜보기(0)를 돌려준다
    return 0;
}

int judge(Pitch *p, int aim)
{
    // TODO: BALL / STRIKE / FOUL / INPLAY 중 하나를 돌려준다
    return STRIKE;
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
