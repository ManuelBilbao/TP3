#include <iostream>

using namespace std;

class Figuras{
  private:
    string tipo;
  public:
    virtual double calcular_superficie() = 0;
    virtual double calcular_perimetro() = 0;
};
