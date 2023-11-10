#include <iostream>
#include <string>

class EmpleadoInfo
{
public:
    EmpleadoInfo(const std::string &nombre, int salario) : nombre(nombre), salario(salario) {}

    void mostrarInformacion()
    {
        std::cout << "Nombre: " << nombre << ", Salario: " << salario << std::endl;
    }

    const std::string &getNombre() const
    {
        return nombre;
    }

private:
    std::string nombre;
    int salario;
};

class GeneradorInforme
{
public:
    static void generarInforme(const EmpleadoInfo &empleado)
    {
        std::cout << "Informe del empleado: " << empleado.getNombre() << std::endl;
    }
};

int main()
{
    EmpleadoInfo empleado("Juan", 50000);

    empleado.mostrarInformacion();
    GeneradorInforme::generarInforme(empleado);

    return 0;
}
