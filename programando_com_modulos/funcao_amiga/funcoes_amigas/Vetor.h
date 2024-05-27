#ifndef VETOR_H
#define VETOR_H


class Vetor{
private:
  float x, y;
public:
  // construtor default
  Vetor();
  // construtor com argumentos
  Vetor(float _x, float _y);
  // construtor de copia
  Vetor(const Vetor& v);

  // destrutor
  ~Vetor();
  Vetor soma(Vetor v1);
  void print();

  // sobrecarga de funcoes
  float produto(Vetor _vetor);
  Vetor produto(float escalar);

  void setX(float _x);
  void setY(float _y);

  float getX(void);
  float getY(void);

  void getInfo(void);

  // funcoes amigas
  friend Vetor operator* (float a, Vetor _vetor);
  friend Vetor operator+ (float a, Vetor _vetor);
  friend Vetor operator- (float a, Vetor _vetor);
};

#endif // VETOR_H
