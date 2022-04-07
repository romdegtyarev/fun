#include    <stdio.h>
#include    <stdlib.h>
#include    <time.h>


int _DEBUG_ = 0;


typedef enum bool_t {
    FALSE,
    TRUE
} bool;

typedef enum color_T {
    BALK,
    BLUE,
    RED,
    BROWN,
    BLACK,
    UNKNOWN_COLOR
} color;

typedef enum body_type_T {
    SLIM,
    FAT,
    FIT,
    ALIEN_BODY
} body_type;


typedef struct just_girl_T {
    color        eyes_color;
    color        hair_color;
    body_type    body_type;
    bool         is_she_programmer;
    bool         is_she_like_activity;
    bool         is_she_like_rom;
} just_girl;


void generete_girl(just_girl *person) {
    person->eyes_color = rand()%(UNKNOWN_COLOR+1);
    person->hair_color = rand()%(UNKNOWN_COLOR+1);
    person->body_type = rand()%(ALIEN_BODY+1);
    person->is_she_programmer = rand()%2;
    person->is_she_like_activity = rand()%2;
    person->is_she_like_rom = rand()%2;
    return;
}


int update_rom_status(just_girl *person, bool *is_rom_in_love) {
    if (person->eyes_color == BLUE &&
        person->hair_color == BLACK &&
        person->body_type == FIT &&
        person->is_she_programmer &&
        person->is_she_like_activity) {

        *is_rom_in_love = 1;            /* Just Love Her First */
        person->is_she_like_rom = 1;
        printf("Yes\n");
        return 1;
    }

    if (_DEBUG_) {
        printf("No: %d %d %d\n",
               person->eyes_color,
               person->is_she_programmer,
               person->is_she_like_activity);
    }
    return 0;
}


int main (int argc, char** argv) {
    bool         is_rom_in_love = 0;
    just_girl    person;
    int          i = 1;


    srand(time(NULL));
    generete_girl(&person);
    while (!(update_rom_status(&person, &is_rom_in_love))) {
        printf("New girl number: %d\n", i);
        i++;
        generete_girl(&person);
    }
    return 0;
}


