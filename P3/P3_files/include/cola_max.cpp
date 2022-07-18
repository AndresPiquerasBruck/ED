using namespace std;

/*_________________________________________________________________________ */

/**
 * @brief Método poner, para poner un elemento al final de la Cola con su máximo
 * @param num Número que se desea poner al final de la Cola
 */
void Cola_max::poner(int num){
  
  if(elementos.vacia()){ // Si la cola está vacía, se añade directamente.

    elementos.poner(elemento{num,num});

  }else{

    Pila<elemento> auxiliar;
    
    while(!elementos.vacia()){
      auxiliar.poner(elementos.tope()); // Volcamos la Cola, (de manera que ahora la veamos en el sentido lógico) en una Pila auxiliar 
      elementos.quitar();               // Mientras que dejamos libre la nuestra
    }

    // Consultamos el último campo máximo para compararlo con el número que se está añadiendo. 
    // Se consulta desde el tope de la Pila auxiliar (al estar al revés en la auxiliar, está en 
    // el sentido lógico, por lo que el tope de la Pila es el final de la Cola)
    int max = auxiliar.tope().maximo; 

    // Añadimos el elemento en la Pila auxiliar con su máximo, resultado de una comparación con el anterior máximo
    auxiliar.poner(elemento{num, num > max ? num : max});

    while(!auxiliar.vacia()){
      elementos.poner(auxiliar.tope()); // Volvemos a volcar la Pila auxiliar en la original, de manera que esté de nuevo al revés en la original,
      auxiliar.quitar();                // Mientras que borramos la auxiliar.
    }

  }
}

/* _________________________________________________________________________ */

/**
 * @brief Método quitar, para quitar un elemento del frente de la Cola
 * Nos damos cuenta que al tener la Cola representada al revés en la Pila, podemos usar
 * el método quitar de la clase Pila. Si no la tuviésemos al revés, no habría manera
 * de quitar un elemento del "frente" de una Pila, ya que en la Pila solo se añaden y quitan
 * elementos desde el final (tope) y no el frente (principio).
 */
void Cola_max::quitar(){
  elementos.quitar();
}
