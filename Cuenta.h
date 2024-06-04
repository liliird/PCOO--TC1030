#ifndef CUENTA_H
#define CUENTA_H
 #include <string>
 #include <sstream>
 using namespace std;

//Declaro la clase Cuenta que es abstracta
 class Cuenta{
    //Declaro las variables
    private:
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
        void depositar(double cantidad){
            if (cantidad>0){
                saldo+= cantidad;
            }
        }

        


 }