#ifndef CUBO_H
#define CUBO_H

typedef struct _cubo Cubo;

Cubo *create_Cubo();
void destroy_Cubo(Cubo **cubo);
void printf_Cubo(const Cubo *cubo);
void add_vals_Cubo(Cubo *cubo, float length, float width, float height);


#endif