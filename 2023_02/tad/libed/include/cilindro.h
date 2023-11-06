#ifndef CILINDRO_H
#define CILINDRO_H

typedef struct _cilindro Cilindro;

Cilindro *createCilindro();
void add_values_into_Cilindro(Cilindro *cilinder, float radius, float heigth);
void printf_all_Cilindro(const Cilindro * cilinder);
void destroy_Cilindro(Cilindro **cilinder);
float get_radius_Cilindro(const Cilindro *cilinder);
float get_heigth_Cilindro(const Cilindro *cilinder);
float get_area_Cilindro(const Cilindro *cilinder);
float get_volume_Cilindro(const Cilindro *cilinder);

#endif