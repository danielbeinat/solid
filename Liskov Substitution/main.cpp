
#include <iostream>

class Ave
{
public:
    virtual void volar() const
    {
        std::cout << "El ave vuela." << std::endl;
    }
};

class Pinguino : public Ave
{
public:
    void volar() const override
    {
        std::cout << "El pingüino no puede volar, pero nada en el agua." << std::endl;
    }
};

void realizarVuelo(const Ave &ave)
{
    ave.volar();
}

int main()
{
    Ave aveNormal;
    Pinguino pinguino;

    realizarVuelo(aveNormal);
    realizarVuelo(pinguino);

    return 0;
}
