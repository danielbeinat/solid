#include <iostream>

class Ejecutable
{
public:
    virtual void ejecutar() const = 0;
};

class Imprimible
{
public:
    virtual void imprimir() const = 0;
};

class TareaEjecutable : public Ejecutable
{
public:
    void ejecutar() const override
    {
        std::cout << "Ejecutando tarea..." << std::endl;
    }
};

class TareaImprimible : public Imprimible
{
public:
    void imprimir() const override
    {
        std::cout << "Imprimiendo tarea..." << std::endl;
    }
};

class TareaCompleta : public Ejecutable, public Imprimible
{
public:
    void ejecutar() const override
    {
        std::cout << "Ejecutando tarea completa..." << std::endl;
    }

    void imprimir() const override
    {
        std::cout << "Imprimiendo tarea completa..." << std::endl;
    }
};

int main()
{
    TareaEjecutable tarea1;
    tarea1.ejecutar();

    TareaImprimible tarea2;
    tarea2.imprimir();

    TareaCompleta tarea3;
    tarea3.ejecutar();
    tarea3.imprimir();

    return 0;
}
