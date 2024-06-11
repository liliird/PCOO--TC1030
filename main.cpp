#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    //Creo el objeto Banco llamado banco con el nombre BBVA
    Banco banco1("BBVA");
    //Creo un puntero a un objeto Cliente con id, nombre, dirección y teléfono
    Cliente* cliente1 = new Cliente("0001", "Lilian Rodriguez", "Epigmenio Gonzalez 500", "4613412144");
    //Creo un puntero a un objeto CuentaCorriente con id, saldo inicial y sobregiro
    Cuenta* cuentaCorriente1 = new CuentaCorriente("C1", 1000.0, 500.0);
    //Creo un puntero a un objeto CuentaAhorro con id, saldo inicial y tasa de interés
    Cuenta* cuentaAhorro1 = new CuentaAhorro("A1", 2000.0, 0.03);

    //Agrego las cuentas cuentaCorriente1 y cuentaAhorro1 al cliente1 con el 
    // método agregarCuenta
    cliente1->agregarCuenta(cuentaCorriente1);
    cliente1->agregarCuenta(cuentaAhorro1);

    //Agrego el cliente1 al banco con el método agregarCliente
    banco1.agregarCliente(cliente1);

    // Buscar cliente con id 0001 en banco con el método buscarCliente de la clase Banco
    Cliente* encontrado = banco1.buscarCliente("0001");
    //Si se encuentra el cliente se llama al método consultarCuentas para imprimir 
    // información sobre las cuentas del cliente
    if (encontrado) {
        encontrado->consultarCuentas();

        // Realizar depósito en la cuenta corriente
        cuentaCorriente1->depositar(500.0);

        // Consultar cuentas después del depósito
        encontrado->consultarCuentas();

        // Realizar retiro de la cuenta corriente
        cuentaCorriente1->retirar(300.0);

        // Consultar cuentas después del retiro
        encontrado->consultarCuentas();

        //Usar sobregiro en la cuenta corriente

        //Utilizo dynamic_cast para convertir punteros de la clase Cuenta a punteros
        // de la clase CuentaCorriente para poder llamar a sus métodos
        dynamic_cast<CuentaCorriente*>(cuentaCorriente1)->usarSobregiro(1200.0);

        //Usar calculo de interés en la cuenta de ahorro

        //Utilizo dynamic_cast para convertir punteros de la clase Cuenta a punteros
        // de la clase CuentaAhorro para poder llamar a sus métodos
        double interes = dynamic_cast<CuentaAhorro*>(cuentaAhorro1)->calcularInteres();
        cout<<"Interes en la cuenta: "<<interes<<endl;
    // Si el cliente no se encuentra se imprime un mensaje
    } else {
        cout << "Cliente no encontrado." << endl;
    }
    //Retorna 0 para indicar que el programa finalizó correctamente
    return 0;
}
