#include <iostream>
#include <string>

class ServicioNotificacion
{
public:
    virtual void enviarMensaje(const std::string &mensaje) const = 0;
};

class ServicioCorreoElectronico : public ServicioNotificacion
{
public:
    void enviarMensaje(const std::string &mensaje) const override
    {
        std::cout << "Enviando correo electrónico: " << mensaje << std::endl;
    }
};

class ServicioMensajeTexto : public ServicioNotificacion
{
public:
    void enviarMensaje(const std::string &mensaje) const override
    {
        std::cout << "Enviando mensaje de texto: " << mensaje << std::endl;
    }
};

class ClienteNotificador
{
public:
    ClienteNotificador(ServicioNotificacion &servicio) : servicioNotificacion(servicio) {}

    void notificarUsuario(const std::string &mensaje) const
    {
        servicioNotificacion.enviarMensaje(mensaje);
    }

private:
    ServicioNotificacion &servicioNotificacion;
};

int main()
{
    ServicioCorreoElectronico servicioCorreo;
    ClienteNotificador clienteCorreo(servicioCorreo);
    clienteCorreo.notificarUsuario("¡Hola! Esto es un correo electrónico.");

    ServicioMensajeTexto servicioTexto;
    ClienteNotificador clienteTexto(servicioTexto);
    clienteTexto.notificarUsuario("¡Hola! Esto es un mensaje de texto.");

    return 0;
}
