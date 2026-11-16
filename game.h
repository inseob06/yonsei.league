/*
 * game.h — 함께 쓰는 "목록표"
 *  - 상수(#define), 구조체, 함수 원형을 모아 둔다.
 *  - display.c, play.c, main.c가 모두 맨 위에서 #include "game.h" 한다.
 *  - 이 파일을 고칠 때는 반드시 팀원에게 먼저 말하기!
 */
#ifndef GAME_H          // 이 파일이 두 번 포함되는 것을 막는 장치 (인클루드 가드)
#define GAME_H

#define MAX_INNINGS 9               // 최대 이닝 수 (점수판 배열 크기)

// 한 구 판정 결과
#define BALL    0
#define STRIKE  1
#define FOUL    2
#define INPLAY  3                   // 공이 앞으로 날아감 (타구)

// 타석 결과 (1~4는 진루할 베이스 수와 같다)
#define OUT     0
#define SINGLE  1
#define DOUBLE  2
#define TRIPLE  3
#define HOMERUN 4
#define WALK    5

// ===================== 구조체 =====================

typedef struct {                    // 공 하나
    int course;                     // 던진 칸 0~9 (0이면 볼)
    int type;                       // 1 직구, 2 변화구
} Pitch;

typedef struct {                    // 반 이닝 동안의 상황
    int outs;                       // 아웃 수
    int strike;                     // 지금 타자의 스트라이크
    int ball;                       // 지금 타자의 볼
    int base[3];                    // base[0]=1루, [1]=2루, [2]=3루 (1이면 주자 있음)
} Situation;

typedef struct {                    // 팀
    char name[20];
    int score[MAX_INNINGS];         // 이닝별 점수
    int runs;                       // 총 득점 (R)
    int hits;                       // 총 안타 (H)
    int batter;                     // 이번 타자 번호 1~9
} Team;

// ===================== 함수 원형 =====================

// display.c — 화면 출력과 입력 (신인섭)
int  read_number(int min, int max);
void print_zone(int course, int aim);
void print_mark(int on);
void print_bases(Situation *s);
void print_scoreboard(Team *away, Team *home, int innings, int done);

// play.c — 투구·타격·판정·주자 (황지현)
int  is_next_to(int a, int b);
void choose_pitch(Pitch *p, Situation *s, int user);
int  choose_swing(Pitch *p, Situation *s, int user);
int  judge(Pitch *p, int aim);
int  hit_result(void);
int  run_bases(Situation *s, int n);
int  walk(Situation *s);
int  play_at_bat(Team *bat, Situation *s, int user_bats);

// main.c — 경기 전체 흐름 (신인섭)
void play_half(Team *bat, Team *field, int inning, int user_bats, int last);

#endif
