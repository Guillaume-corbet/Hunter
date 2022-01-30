/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** other_option
*/

#include "main.h"

void display_game_over(poub_t *po)
{
    my_printf("GAME OVER\n\n");
    my_printf("You kill %d ducks\n\n", po->counter);
    if (po->highscore < po->counter) {
        po->highscore = po->counter;
        my_strcpy(po->str_highscore, int_to_str(po->highscore));
        new_highscore(po->str_highscore);
        my_printf("You have the new highscore");
    } else
        my_printf("The highscore was %d\n", po->highscore);
}

void begin_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    ac->video_mode.width = 1900;
    ac->video_mode.height = 1050;
    ac->video_mode.bitsPerPixel = 32;
    ac->rect.top = 0;
    ac->rect.left = 0;
    ac->rect.width = 110;
    ac->rect.height = 110;
    ac->move.x = -110;
    ac->move.y = rand() % (po->b - 50);
    ac->move2.x = -110;
    ac->move2.y = rand() % (po->b - 50);
    po->highscore = my_getnbr_highscore(score());
    ac->window = sfRenderWindow_create(ac->video_mode, "Space Dunk",
    sfDefaultStyle, NULL);
    te->texture_fond = sfTexture_createFromFile("spacerainbow.jpg", NULL);
    te->texture_canard = sfTexture_createFromFile("sprite_canard.png", NULL);
    te->texture_canard2 = sfTexture_createFromFile("sprite_canard.png", NULL);
    sp->sprite_fond = sfSprite_create();
    sp->sprite_canard = sfSprite_create();
    sp->sprite_canard2 = sfSprite_create();
}

void destroy_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    sfMusic_stop(ac->music);
    sfTexture_destroy(te->texture_fond);
    sfTexture_destroy(te->texture_canard);
    sfTexture_destroy(te->texture_canard2);
    sfSprite_destroy(sp->sprite_fond);
    sfSprite_destroy(sp->sprite_canard);
    sfSprite_destroy(sp->sprite_canard2);
    sfMusic_destroy(ac->music);
    sfText_destroy(ac->score);
    sfFont_destroy(ac->font);
    sfRenderWindow_destroy(ac->window);
    display_game_over(po);
    sfRenderWindow_close(ac->window);
}

void do_event_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    if (ac->event.type == sfEvtClosed)
        destroy_easy(ac, po, te, sp);
    if (ac->event.type == sfEvtMouseButtonPressed
    || sfEvtKeyPressed == sfTrue) {
        if (po->x_mouse >= ac->move.x - 150 && po->x_mouse <= ac->move.x + 30
        && po->y_mouse >= ac->move.y - 30 && po->y_mouse <= ac->move.y + 150) {
            ac->move.x = -110;
            ac->move.y = rand() % (po->b - 50);
            po->counter = po->counter + 1;
            po->speed = po->speed + 5;
        }
        if (po->x_mouse >= ac->move2.x - 150 && po->x_mouse <= ac->move2.x + 30
        && po->y_mouse >= ac->move2.y - 30
        && po->y_mouse <= ac->move2.y + 150) {
            ac->move2.x = -110;
            ac->move2.y = rand() % (po->b - 50);
            po->counter = po->counter + 1;
            po->speed = po->speed + 5;
        }
    }
}

int position_easy(test_t *ac, poub_t *po, texture_t *te, sprite_t *sp)
{
    ac->rect.left = ac->rect.left + 110;
    if (ac->rect.left >= 330)
        ac->rect.left = 0;
    ac->font = sfFont_createFromFile("arial.ttf");
    sfText_setString(ac->score, int_to_str(po->counter));
    sfText_setFont(ac->score, ac->font);
    sfText_setCharacterSize(ac->score, 30);
    sfSprite_setPosition(sp->sprite_canard, ac->move);
    sfSprite_setPosition(sp->sprite_canard2, ac->move2);
    sfText_setPosition(ac->score, ac->pos_score);
    ac->move.x = ac->move.x + po->speed;
    ac->move2.x = ac->move2.x + po->speed;
    if (ac->move.x >= 1900 || ac->move2.x >= 1900) {
        destroy_easy(ac, po, te, sp);
        return (0);
    }
    sfSprite_setTextureRect(sp->sprite_canard, ac->rect);
    sfSprite_setTextureRect(sp->sprite_canard2, ac->rect);
    return (1);
}