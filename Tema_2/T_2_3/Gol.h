/**
 * @brief  Definici�n de una clase. 
 *        Ejemplo T_2_3, de la Teor�a de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file Gol.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */


#include <string>

#ifndef GOL_H
#define	GOL_H

/**
 * @brief Clase Gol. Ejemplo T_2_3 de Teor�a
 * @param autor Nombre del jugador que ha marcado el gol
 * @param minuto Minuto del partido en que se ha marcado el gol
 */

class Gol {
public:                                                     // M�todos p�blicos
    Gol(const std::string elJugador, const int elMinuto);   // M�todo: constructor
    Gol(const Gol& orig);                                   // M�todo: constructor
    ~Gol();                                                 // M�todo: constructor
    void SetMinuto(int minuto);                             // M�todo: mutador
    int GetMinuto() const;                                  // M�todo: observador
    void SetJugador(std::string jugador);                   // M�todo: mutador
    std::string GetJugador() const;                         // M�todo: observador
private:
    bool minutoEsCorrecto(int minuto) const;                // M�todo privado  
private:
    std::string jugador="";                                 // Atributo
    int minuto=0;                                           // Atributo
};

#endif	/* GOL_H */

