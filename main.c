/*
** EPITECH PROJECT, 2018
** Day13
** File description:
** task01
*/

#include "main.h"

int main(int argc, char **argv)
{
    test_t *ac;
    texture_t *te;
    sprite_t *sp;
    poub_t *po;
    int oups = 0;

    ac = malloc(sizeof(test_t));
    te = malloc(sizeof(texture_t));
    sp = malloc(sizeof(sprite_t));
    po = malloc(sizeof(poub_t));
    po->b = 940;
    po->tab = malloc(sizeof(char) * 11);
    po->error = fonc_error(argc, argv);
    if (po->error == 84)
        return (84);
    my_strcpy(po->tab, argv[1]);
    my_hunter_easy(ac, po, te, sp);
    return (0);
}
