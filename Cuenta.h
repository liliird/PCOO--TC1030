#ifndef CUENTA_H
#define CUENTA_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//Declaro la clase Cuenta que es abstracta
class Cuenta{
    //Declaro las variables
    protected:
        string idCuenta;
        double saldo;
    //Declaro los metodos que va a tener el objeto
    public:
        Cuenta(): idCuenta(""), saldo(0){}; //Constructor por default
        Cuenta(string id, double sal): idCuenta(id), saldo(sal){};

        string get_id(){
            return idCuenta;
        }
        double get_saldo(){
            return saldo;
        }
        //Metodo para depositar una cantidad en la cuenta
        virtual void depositar(double cantidad) {
        saldo += cantidad;
        }
        virtual void retirar(double cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
        } else {
            cout << "Saldo insuficiente." <<endl;
        }
        }
        virtual double consultarSaldo() const {
        return saldo;
        }
        virtual ~Cuenta() = default;
        
};

class CuentaCorriente : public Cuenta {
    private:
        double sobregiro;

    public:
        CuentaCorriente(string id, double saldoInicial, double sobregiroInicial) 
        : Cuenta(id, saldoInicial), sobregiro(sobregiroInicial) {}

        void usarSobregiro(double cantidad) {
            if (cantidad <= saldo + sobregiro) {
                saldo -= cantidad;
            } else {
                cout << "Saldo y sobregiro insuficientes." << endl;
            }
        }
};

class CuentaAhorro : public Cuenta {
    private:
        double tasaInteres;

    public:
        CuentaAhorro(string id, double saldoInicial, double tasaInteresl) 
        : Cuenta(id, saldoInicial), tasaInteres(tasaInteres) {}

        double calcularInteres() const {
            return saldo * tasaInteres;
        }
};

#endif
        


