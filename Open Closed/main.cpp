#include <iostream>
#include <vector>

class Forma
{
public:
    virtual double calcularArea() const = 0;
};

class Circulo : public Forma
{
public:
    Circulo(double radio) : radio(radio) {}

    double calcularArea() const override
    {
        return 3.14 * radio * radio;
    }

private:
    double radio;
};

class Rectangulo : public Forma
{
public:
    Rectangulo(double ancho, double altura) : ancho(ancho), altura(altura) {}

    double calcularArea() const override
    {
        return ancho * altura;
    }

private:
    double ancho;
    double altura;
};

double calcularAreaTotal(const std::vector<Forma *> &formas)
{
    double areaTotal = 0.0;
    for (const auto &forma : formas)
    {
        areaTotal += forma->calcularArea();
    }
    return areaTotal;
}

int main()
{
    Circulo circulo(5.0);
    Rectangulo rectangulo(4.0, 6.0);

    std::vector<Forma *> formas;
    formas.push_back(&circulo);
    formas.push_back(&rectangulo);

    double areaTotal = calcularAreaTotal(formas);

    std::cout << "Área total de las formas: " << areaTotal << std::endl;

    return 0;
}
