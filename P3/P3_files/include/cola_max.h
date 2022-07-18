#ifndef _COLA_MAX_H_
#define _COLA_MAX_H_

#include <iostream>
#include <pila.h>

using namespace std;

/**
 * @brief Struct elemento
 * Usado para almacenar tanto el elemento como el máximo al añadirse a la Cola
 */
struct elemento{
  int ele;    ///< Elemento a almacenar
  int maximo; ///< El máximo

  friend ostream& operator<<(ostream& os, const elemento& element); //sobrecarga del operador ostream

};

/**
 * @brief Sobrecarga del operador << para mostrar los elementos.
 * 
 * @param os ostream
 * @param element elemento que queramos mostrar
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const elemento& element)
{
    os << element.ele << ' ' << element.maximo;
    return os;
}

/**
 * @brief TDA Cola_max: Representación de una Cola con máximo usando una Pila.
 * 
 * Representar una Cola mediante una Pila solo es posible si en uno de los dos procesos de 
 * poner o quitar elementos se le da la vuelta. Esto es porque por definición, una Pila solo
 * admite la adición y borrado de elementos desde uno de los lados (tope) y la Cola desde los dos
 * (frente y final).
 * 
 * En nuestra representación, la Cola estará contenida al revés en una Pila. De manera que cuando
 * queramos quitar un elemento del principio de la Cola (frente de la Cola) lo podamos hacer
 * quitando el elemento del final de la Pila (tope de la Pila). Cuando queramos poner un elemento
 * al final de la Cola deberemos darle la vuelta a la Pila, ya que en una Pila solo se pueden añadir
 * elementos al final.
 * 
 * (Ver en detalle en los métodos "Poner" y "Quitar" de la clase Cola_max)
 * 
 * @author Javier Osakar Lozano, Andrés Piqueras Brück
 * @date 27/11/2021
 */
class Cola_max{
	
  private:
    
    Pila <elemento> elementos;
    
  public:

    /**
     * @brief Constructor por defecto
     * Usa el constructor por defecto de la clase Pila
     */
    Cola_max() : elementos(){}

    /**
     * @brief Consulta si la Cola está vacía o no
     * 
     * @return true Si la Cola (Pila) está vacía
     * @return false Si la Cola (Pila) está vacía
     */
    bool vacia() const{
      return elementos.num_elementos()==0;
    }

    /**
     * @brief Consultor del elemento en el frente de la Cola
     * 
     * @return elemento& objeto de tipo
     */
    elemento& frente (){
      return elementos.tope();  // Devuelve el elemento del frente de la Cola
    }

    const elemento & frente () const{
      return elementos.tope();  // Devuelve el elemento del frente de la Cola
    }

    void poner(int num);

    void quitar();

    int num_elementos() const{
      return elementos.num_elementos(); 
    }

    
};

#include <cola_max.cpp>

#endif