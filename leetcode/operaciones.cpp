#include <iostream>
#include <string>
#include <functional>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 4){
        cerr << "Ha ingresado valores inadecuados para el programa:\n";
        cerr << "USO ./<ejecutable> <num1> <operador> <num2>\n";
        return 1;
    }

    try {
        float a = stof(argv[1]);
        string op = argv[2];
        float b = stof(argv[3]);

        map<string, function<float(float,float)>> operaciones;
        operaciones["+"] = [](float x, float y){ return x + y; };
        operaciones["-"] = [](float x, float y){ return x - y; };
        operaciones["*"] = [](float x, float y){ return x * y; };
        operaciones["x"] = operaciones["*"];
        operaciones["/"] = [](float x, float y){ 
            if(y == 0) throw runtime_error("Division por cero!");
            return x / y; 
        };

        if(operaciones.find(op) == operaciones.end()){
            cerr << "Operador no valido. Use +, -, *, x o /\n";
            return 1;
        }

        float resultado = operaciones[op](a,b);
        cout << "El resultado de la operacion es " << resultado << endl;

    } catch(const exception& e){
        cerr << "Error: " << e.what() << endl;
        cerr << "USO ./<ejecutable> <num1> <operador> <num2>\n";
        return 1;
    }

    return 0;
}
