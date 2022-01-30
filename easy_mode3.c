/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** easy_mode3
*/

#include "main.h"

int corpse_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    int oups = 0;

    ac->time = sfClock_getElapsedTime(ac->clock);
    po->seconds = ac->time.microseconds / 1000000.0;
    if (po->seconds > 0.15) {
        oups = position_easy(ac, po, te, sp);
        if (oups == 0) {
            return (0);
        }
        draw_easy(ac, po, te, sp);
        while (sfRenderWindow_pollEvent(ac->window, &ac->event)) {
            po->x_mouse = ac->event.mouseWheel.x;
            po->y_mouse = ac->event.mouseWheel.y;
            do_event_easy(ac, po, te, sp);
        }
        sfClock_restart(ac->clock);
    }
    return (1);
}

void draw_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    sfRenderWindow_setFramerateLimit(ac->window, 90);
    sfRenderWindow_drawSprite(ac->window, sp->sprite_fond, NULL);
    sfRenderWindow_drawSprite(ac->window, sp->sprite_canard, NULL);
    sfRenderWindow_drawSprite(ac->window, sp->sprite_canard2, NULL);
    sfRenderWindow_drawText(ac->window, ac->score, NULL);
    sfRenderWindow_display(ac->window);
}

void set_texture_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    ac->clock = sfClock_create();
    po->speed = 30;
    ac->music = sfMusic_createFromFile("Nyan_Cat.ogg");
    ac->score = sfText_create();
    ac->pos_score.x = 1800;
    ac->pos_score.y = 10;
    sfSprite_setTexture(sp->sprite_fond, te->texture_fond, sfTrue);
    sfSprite_setTexture(sp->sprite_canard, te->texture_canard, sfTrue);
    sfSprite_setTexture(sp->sprite_canard2, te->texture_canard2, sfTrue);
}

int my_hunter_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    int oups = 0;

    if (po->error == 84)
        return (84);
    else if (po->error == 42)
        return (0);
    srand(time(0));
    po->str_highscore = malloc(sizeof(char) * 10);
    begin_easy(ac, po, te, sp);
    set_texture_easy(ac, po, te, sp);
    sfMusic_play(ac->music);
    sfMusic_setLoop(ac->music, sfTrue);
    while (sfRenderWindow_isOpen(ac->window)) {
        oups = corpse_easy(ac, po, te, sp);
        if (oups == 0) {
            return (0);
        }
    }
    return (0);
}