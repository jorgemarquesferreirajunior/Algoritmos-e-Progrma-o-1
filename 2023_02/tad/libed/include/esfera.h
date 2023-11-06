#ifndef ESFERA_H
#define ESFERA_H

typedef struct _esfera Esfera;

Esfera *createEsfera();

void add_values_into_Esfera(Esfera *sphere, float radius);
void printf_all_Esfera(const Esfera * sphere);
void destroy_Esfera(Esfera **sphere);
float get_radius_Esfera(const Esfera *sphere);
float get_area_Esfera(const Esfera *sphere);
float get_volume_Esfera(const Esfera *sphere);

#endif