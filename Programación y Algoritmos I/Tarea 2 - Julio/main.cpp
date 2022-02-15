#include <iostream>
using namespace std;

enum Status{
    DESCANSANDO,
    TRABAJANDO,
    INVALIDO
};

struct Empleado{
    int age;
    char *name;
    Status status;
};

void empleado_Trabaja(Empleado *a){
    a->status = TRABAJANDO;
}

class CEmpleado{
private:
    int age;
    char *name;
    Status status;
    
public:
    void trabaja(){
        status = TRABAJANDO;
    }

    void setAge(int a){
        if (a>18){
            age = a;
        }
        else {
            age = -1;
            status = INVALIDO;
        }
    }

    int getAge(){
        return age;
    }
};

int main(){
    cout<<"Hello, World! I'm here"<<endl;

    Empleado a;
    CEmpleado b;

    empleado_Trabaja(&a);
    a.age = 35;
    a.name = (char *)"Juan";

    b.setAge(35);

    cout<<"Estatus del empleado: "<<(a.status == 1 ? "Trabajando " : "No se ")<<endl;
    cout<<"La edad del empleado b: "<<b.getAge()<<endl;

    return 0;
}