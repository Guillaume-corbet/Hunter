/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Font.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "./lib/my/my.h"
#include "./lib/my_printf/my_printf.h"

typedef struct first
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfIntRect rect;
    sfVector2f move;
    sfVector2f move2;
    sfVector2f pos_score;
    sfClock *clock;
    sfEvent event;
    sfTime time;
    sfSound *shoot;
    sfMusic *music;
    sfText *score;
    sfFont *font;
    sfColor color;
}test_t;

typedef struct poubelle
{
    int life;
    int speed;
    int x_mouse;
    int y_mouse;
    int a;
    int b;
    int al;
    int counter;
    int highscore;
    int lenght;
    int error;
    float seconds;
    char *str_highscore;
    char *tab;
}poub_t;

typedef struct texture
{
    sfTexture *texture_fond;
    sfTexture *texture_canard;
    sfTexture *texture_canard2;
    sfTexture *texture_game_over;
}texture_t;

typedef struct sprite
{
    sfSprite *sprite_fond;
    sfSprite *sprite_canard;
    sfSprite *sprite_canard2;
    sfSprite *sprite_game_over;
}sprite_t;

char *int_to_str(int nb);
int my_getnbr_highscore(char const *str);
char *score(void);
void new_highscore(char *easy);
int fonc_error(int argc, char **argv);
void display_game_over(poub_t *po);
void begin_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
void destroy_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
void do_event_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
int position_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
void draw_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
void set_texture_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
int my_hunter_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);
int corpse_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp);

#endif /* !MAIN_H_ */
