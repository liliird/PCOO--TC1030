#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    Banco banco("Banco Ejemplo");

    Cliente* cliente1 = new Cliente("0001", "Lilian Rodriguez", "Epigmenio Gonzalez 500", "4613412144");
    Cuenta* cuentaCorriente1 = new CuentaCorriente("C1", 1000.0, 500.0);
    Cuenta* cuentaAhorro1 = new CuentaAhorro("A1", 2000.0, 0.03);

    cliente1->agregarCuenta(cuentaCorriente1);
    cliente1->agregarCuenta(cuentaAhorro1);

    banco.agregarCliente(cliente1);

    // Buscar cliente
    Cliente* encontrado = banco.buscarCliente("0001");
    if (encontrado) {
        encontrado->consultarCuentas();

        // Realizar depósito en la cuenta corriente
        cuentaCorriente1->depositar(500.0);

        // Consultar cuentas después del depósito
        encontrado->consultarCuentas();
    } else {
        cout << "Cliente no encontrado." << endl;
    }

    return 0;
}
