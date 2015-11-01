/**
 * @file Guerrero.h
 * Archivo con la declaración de la clase Guerrero
 * @author algarcia
 * @date 2015-10-20
 */

#ifndef GUERRERO_H
#define GUERRERO_H

#include <string>
#include "Arma.h"

using namespace std;

/**
 * @brief Clase para representar los guerreros del juego.
 * 
 * Ejemplo de asociación. Cada guerrero está asociado con su arma, y antes de
 * destruir un objeto de clase Guerrero, es necesario desarmarle primero con
 * el método Guerrero::desarmar
 */
class Guerrero
{
   private:
      string nombre;     ///< Nombre del guerrero
      int energia;       ///< Energía vital. Un valor menor o igual a cero implica muerte
      Arma *armamento;   ///< A través de este atributo se establece la asociación

   public:
      Guerrero ( );
      Guerrero ( string nNombre, int nEnergia=1000 );
      Guerrero ( const Guerrero& orig );
      virtual ~Guerrero ( );
      void setArmamento ( Arma* nArmamento );
      Arma* getArmamento ( ) const;
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Arma *desarmar ();
      int ataque ();
      string info () const;
};

#endif	/* GUERRERO_H */
