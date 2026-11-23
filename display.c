// display.c - 신인섭
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int read_number(int min, int max)
{
    int n;
    int result;
    int c;
        while (1) {
        result = scanf("%d", &n);
        if (result == EOF) { 
            exit(0);
        }
        if (result == 1 && n >= min && n <= max) {
            return n; 
        }
       
        // 남은 입력 지우기
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        printf("%d~%d 사이 숫자를 다시 입력하세요: ", min, max);
    }
}

void print_zone(int course, int aim)
{
    int n;
        for (n = 1; n <= 9; n++) {
        if (n == course && n == aim) {
            printf("[@]");
        }
        else if (n == course) {
            printf("[*]");
            
        }
        else if (n == aim) {
            printf("[O]");
            
        }
        else {
            printf("[%d]", n);
            
        }
        if (n % 3 == 0) { // 3칸마다 줄바꿈
            printf("\n");
            
        }
        
    }
    if (course == 0) {
        printf("(공이 존 밖으로 빠졌다)\n");
    }
}

void print_mark(int on)
{
    if (on == 1) {
        printf("●");
        
    }
    else {
        printf("○");
     
    }
}

void print_bases(Situation *s)
{
    printf("\n         ");
    print_mark(s->base[1]);
    printf(" 2루\n");
    printf("   3루 ");
    print_mark(s->base[2]);
    printf("       ");
    print_mark(s->base[0]);
    printf(" 1루     %d아웃\n", s->outs);
}

void print_scoreboard(Team *away, Team *home, int innings, int done)
{
    int i;

    printf("\n         ");
    for (i = 0; i < innings; i++) {
        printf("%2d ", i + 1);
        
    }
    printf("|  R  H\n");
    
    printf(" 내 팀   ");
    for (i = 0; i < innings; i++) {
        if (i < done) {
            printf("%2d ", away->score[i]);
            
        }
        else {
            printf(" - ");
            
        }
       
    }
    printf("| %2d %2d\n", away->runs, away->hits);
    
    printf(" 컴퓨터  ");
    for (i = 0; i < innings; i++) {
        if (i >= done) {
            printf(" - ");
            
        }
        else if (home->score[i] == -1) {
            printf(" X "); // 마지막 이닝 말 공격 안 함
            
        }
        else {
            printf("%2d ", home->score[i]);
            
        }
        
    }
    printf("| %2d %2d\n", home->runs, home->hits);
}
