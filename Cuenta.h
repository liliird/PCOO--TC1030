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
        
        //getters
        string get_id(){
            return idCuenta;
        }
        double get_saldo(){
            return saldo;
        }
        //setters
        void set_id(int newIdC){
            idCuenta= newIdC;
        }
        void set_saldo(double newSal){
            saldo= newSal;
        }

        //Metodo virtual para depositar una cantidad en la cuenta
        virtual void depositar(double cantidad) {
        saldo += cantidad;
        }

        //Metodo virtual para retirar una cantidad de la cuenta
        void retirar(double cantidad) {
        //Ciclo que verifica si el saldo en la cuenta es suficiente para el retiro
        if (cantidad <= saldo) {
            saldo -= cantidad;
        } else {
            cout << "Saldo insuficiente." <<endl;
        }
        }
        //Metodo virtual para consultar el saldo de la cuenta
        virtual double consultarSaldo() const{
            return saldo;
        }
        //Metodo virtual para consultar el sobregiro/tasa de interes
        virtual string to_string() = 0;

        //Destructor virtual por defecto
        virtual ~Cuenta() = default;
        
};
//Clase CuentaCorriente que hereda de Cuenta
class CuentaCorriente : public Cuenta {
    private:
        double sobregiro;

    public:
        //Constructor
        CuentaCorriente(string id, double saldoInicial, double sobregiroInicial) 
        : Cuenta(id, saldoInicial), sobregiro(sobregiroInicial) {}
        string to_string();
        //Getter
        double getSobregiro(){
            return sobregiro;
        }
        //Setter
        void setSobregiro(double sobG){
            sobregiro=sobG;
        }
        //Método que me permite usar el sobregiro. Permitiendo retirar una
        // cantidad mayor al saldo disponible, hasta el límite del sobregiro
        void usarSobregiro(double cantidad) {
            if (cantidad <= saldo + sobregiro) {
                saldo -= cantidad;
            } else {
                cout << "Saldo y sobregiro insuficientes." << endl;
            }
        }
        
};

string CuentaCorriente::to_string(){
    stringstream aux;
    aux << ", Sobregiro: " << sobregiro << "\n";
    return aux.str();
}
//Clase CuentaAhorro que hereda de Cuenta
class CuentaAhorro : public Cuenta {
    private:
        double tasaInteres;

    public:
        //Constructor
        CuentaAhorro(string id, double saldoInicial, double tasaInteres) 
        : Cuenta(id, saldoInicial), tasaInteres(tasaInteres) {}
        string to_string();
        //Getter
        double getTasaInteres(){
            return tasaInteres;
        }
        //Setter
        void setTasaInteres(double tasa){
            tasaInteres=tasa;
        }
        //Método que calcula el interés en base al saldo y la tasa de interés
        double calcularInteres() const {
            return saldo * tasaInteres;
        }
    
};
string CuentaAhorro::to_string(){
        stringstream aux;
        aux << ", Tasa de interes: " << tasaInteres << "\n";
        return aux.str();
        }

#endif
        


