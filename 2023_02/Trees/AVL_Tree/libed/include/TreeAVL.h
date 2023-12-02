#ifndef TreeAVL_H
#define TreeAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _node_avltree NodeAVL;

int calcHeight(NodeAVL *node);
int calcBalanceFactor(NodeAVL *node);
int calcMax(int x, int y);

#endif