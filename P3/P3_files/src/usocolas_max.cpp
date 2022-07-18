#include <iostream>
#include <cola_max.h>

using namespace std;

int main(){

  Cola_max cola;
  int i;

  // Añadimos los elementos
  for (i=10; i>0; i--){
    cola.poner(i);
    cout << "Añadido " << i << endl;
  }

  // Imprimimos la cola
  cout << "Cola:" << endl;
  while (!cola.vacia()){
    elemento x = cola.frente();
    cout << x << endl;
    cola.quitar();
  }

  return 0;
}