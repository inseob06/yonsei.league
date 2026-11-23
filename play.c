
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game.h"


int is_next_to(int a, int b)
{
    int a_row = (a - 1) / 3;
    int a_col = (a - 1) % 3;
    int b_row = (b - 1) / 3;
    int b_col = (b - 1) % 3;

    if (abs(a_row - b_row) + abs(a_col - b_col) == 1) {
        return 1;
    }
    return 0;
}


void choose_pitch(Pitch *p, Situation *s, int user)
{
    int ball_chance;

    if (user == 1) {
        printf("  던질 칸 (1~9, 볼은 0): ");
        p->course = read_number(0, 9);
        printf("  구종 (1 직구, 2 변화구): ");
        p->type = read_number(1, 2);
        return;
    }

   
    if (s->ball == 3) {
        ball_chance = 5;
    } else if (s->strike == 2) {
        ball_chance = 40;
    } else {
        ball_chance = 20;
    }

    if (rand() % 100 < ball_chance) {
        p->course = 0;
    } else {
        p->course = rand() % 9 + 1;
    }
    p->type = rand() % 2 + 1;
}


int choose_swing(Pitch *p, Situation *s, int user)
{
    int swing_chance;

    if (user == 1) {
        printf("  노릴 칸 (1~9, 지켜보기 0): ");
        return read_number(0, 9);
    }

   
    if (p->course == 0) {
        swing_chance = 30;
    } else if (s->strike == 2) {
        swing_chance = 90;
    } else {
        swing_chance = 70;
    }

    if (rand() % 100 < swing_chance) {
        return rand() % 9 + 1;
    }
    return 0;
}


int judge(Pitch *p, int aim)
{
    int chance;

    
    if (aim == 0) {
        if (p->course == 0) {
            return BALL;
        }
        return STRIKE;
    }

    
    if (p->course == 0) {
        chance = 15;
    } else if (p->course == aim) {
        chance = 80;
    } else if (is_next_to(p->course, aim)) {
        chance = 55;
    } else {
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
    int r = rand() % 100;

    if (r < 8) {
        return HOMERUN;   
    }
    if (r < 10) {
        return TRIPLE;    
    }
    if (r < 23) {
        return DOUBLE;    
    }
    if (r < 55) {
        return SINGLE;    
    }
    return OUT;           
}

int run_bases(Situation *s, int n)
{
    
    return 0;
}

int walk(Situation *s)
{
   
    return 0;
}

int play_at_bat(Team *bat, Situation *s, int user_bats)
{
   
    return OUT;
}
