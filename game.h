
#ifndef GAME_H          
#define GAME_H

#define MAX_INNINGS 9               


#define BALL    0
#define STRIKE  1
#define FOUL    2
#define INPLAY  3                   


#define OUT     0
#define SINGLE  1
#define DOUBLE  2
#define TRIPLE  3
#define HOMERUN 4
#define WALK    5



typedef struct {                    
    int course;                     
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
    int batter;                     
} Team;




int  read_number(int min, int max);
void print_zone(int course, int aim);
void print_mark(int on);
void print_bases(Situation *s);
void print_scoreboard(Team *away, Team *home, int innings, int done);


int  is_next_to(int a, int b);
void choose_pitch(Pitch *p, Situation *s, int user);
int  choose_swing(Pitch *p, Situation *s, int user);
int  judge(Pitch *p, int aim);
int  hit_result(void);
int  run_bases(Situation *s, int n);
int  walk(Situation *s);
int  play_at_bat(Team *bat, Situation *s, int user_bats);


void play_half(Team *bat, Team *field, int inning, int user_bats, int last);

#endif
