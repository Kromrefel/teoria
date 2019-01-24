/** 
 * @brief Implmentación de los métodos de la clase EntradaEnFacebook
 * @file EntradaEnFacebook.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:01
 */

#include "EntradaEnFacebook.h"

/**
 * @brief Constructor por defecto de la clase
 * @param nombre Nombre del personaje
 */
EntradaEnFacebook::EntradaEnFacebook(int id, std::string texto, int maxComentarios)
    :id(id)
    , texto(texto)
    , maxComentarios(maxComentarios)
    , numComentarios(0)
    , comentarios(nullptr) {

    if (maxComentarios > 0) {
        comentarios = new std::string[maxComentarios];
    }
}

/**
 * @brief Constructor de copia, PRRIMERA VERSION: Se copian las direcciones de los punteros
 * @param orig Objeto cuyos datos se van a copiar
 */
EntradaEnFacebook::EntradaEnFacebook(const EntradaEnFacebook& orig) // Si quieres usar este costructor de copia debes poner entre comentarios el de abajo
    : id(orig.id)
    , texto(orig.texto)
    , maxComentarios(orig.maxComentarios)
    , numComentarios(orig.numComentarios)
    , comentarios(nullptr) {
    
    comentarios = new std::string[maxComentarios];
    for (int i = 0; i < orig.numComentarios; ++i) {
        comentarios[i] = orig.comentarios[i];
    }
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
EntradaEnFacebook::~EntradaEnFacebook() {
    // Liberamos la memoria que se reservó en el constructor
    if (comentarios) {
        delete [] comentarios;
        comentarios = nullptr;
    }
}

void EntradaEnFacebook::SetId(int id) {
    this->id = id;
}

int EntradaEnFacebook::GetId() const {
    return id;
}

/**
 * @brief Modifica el texto de la entrada
 * @param texto Modifica el texto de la entrada
 * @post Modifica el texto de la entrada
 */
void EntradaEnFacebook::SetTexto(std::string texto) {
    this->texto = texto;
}

/**
 * @brief Devuelve el texto de la entrada
 * @post Devuelve el texto de la entrada
 */
std::string EntradaEnFacebook::GetTexto() const {
    return texto;
}

/**
 * @brief Devuelve el máximo número de comentarios que puede tener la entrada
 * @post Devuelve el máximo número de comentarios que puede tener la entrada 
 */
int EntradaEnFacebook::GetMaxComentarios() const {
    return maxComentarios;
}

/**
 * @brief Devuelve el número de comentarios que tiene la entrada
 * @post Devuelve el número de comentarios que tiene la entrada
 */
int EntradaEnFacebook::GetNumComentarios() const {
    return numComentarios;
}

/**
 * @brief Devuelve el comentario ubicado en la posición pos
 * @param pos Posición del comentario que queremos devolver.
 * @post Devuelve el comentario ubicado en la posición pos
 * @post Si la posición no existe, devuelve la cadena vacía
 */
std::string EntradaEnFacebook::GetComentario(int pos) const {
    return ( pos < 0 || pos > numComentarios) ? "" : comentarios[pos];
}

/**
 * @@brief Añade un nuevo comentario a la entrada
 * @param nuevoComentario Texto del nuevo comentario
 * @post Si existe espacio en el vector de comentarios, añade el nuevo comentario, e incrementa el contador de comentarios
 */
void EntradaEnFacebook::AddComentario(std::string nuevoComentario) {
    if (numComentarios < maxComentarios) {
        comentarios[numComentarios++] = nuevoComentario;
    }
}

/**
 * @brief Compara dos entras a partir de su id
 * @param otro Entrada cuyos datos se quieren comparar
 * @post Devuelve true si ambas entradas tienen el mismo id
 */
bool EntradaEnFacebook::operator==(const EntradaEnFacebook& otro) {
    return id==otro.id;
}


/**
 * @brief Compara alfabéticamente dos entras en función del texto que contienen
 * @param otro Entrada cuyos datos se quieren comparar
 * @post Devuelve true si esta entrada es menor o igual que la que se pasa por parámetro, desde un punto de vista alfabético
 */
bool EntradaEnFacebook::operator<=(const EntradaEnFacebook& otro) {
    return texto <= otro.texto;
}

/**
 * @brief Operador asignación
 * @param otro Entrada cuyos datos se quieren copiar
 * @post Asigna los datos de otro en el objeto que recibe la llamada al método.
 * @post Devuelve el mismo objeto que ha recibido la llamada por referencia para "encadenar" asignaciones: a=b=c=d
 */
EntradaEnFacebook& EntradaEnFacebook::operator=(const EntradaEnFacebook& orig) {
    if (this != &orig) {
        texto = orig.texto;
        maxComentarios = orig.maxComentarios;
        if (comentarios) {
            delete [] comentarios;
            comentarios = 0;
        }
        if (maxComentarios > 0) {
            comentarios = new std::string[maxComentarios];
            if (comentarios) {
                numComentarios = orig.numComentarios;
                for (int i = 0; i < orig.numComentarios; ++i) {
                    comentarios[i] = orig.comentarios[i];
                }
            }
        }
    }
    // Devolvermos referencia al propio objeto para las asignaciones encadenadas: a=b=c=d
    return *this;
}