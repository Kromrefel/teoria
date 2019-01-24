/**
 * @brief Implmentación de los métodos de la clase EntradaEnFacebook
 * @file EntradaEnFacebook.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:01
 */

#include "EntradaEnFacebook.h"

/**
 * @brief Constructor por defecto parametrizado de la clase
 * @param texto Texto de la entrada
 * @param maxComentarios Número máximo de comentarios admitidos a la entrada
 */
EntradaEnFacebook::EntradaEnFacebook(int id, std::string texto, int maxComentarios)
    :id(id)
    , texto(texto)
    , maxComentarios(maxComentarios)
    , numComentarios(0)
    , comentarios(0) {

    if (maxComentarios > 0) {
        comentarios = new std::string[maxComentarios];
    }
}

/**
 * @brief Constructor de copia, PRIMERA VERSION: Se copian las direcciones de los punteros
 * @param orig Objeto cuyos datos se van a copiar
 */
EntradaEnFacebook::EntradaEnFacebook(const EntradaEnFacebook& orig) // Si quieres usar este costructor de copia debes poner entre comentarios el de abajo
    : id(orig.id)
    , texto(orig.texto)
    , maxComentarios(orig.maxComentarios)
    , numComentarios(orig.numComentarios)
    , comentarios(0) {

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
std::string EntradaEnFacebook::GetComentario(int pos) const{
    return ( pos<0 || pos>numComentarios )?"":comentarios[pos];
}

/**
 * @@brief Añade un nuevo comentario a la entrada
 * @param nuevoComentario Texto del nuevo comentario
 * @post Si existe espacio en el vector de comentarios, añade el nuevo comentario, e incrementa el contador de comentarios
 */
void EntradaEnFacebook::AddComentario(std::string nuevoComentario) {
    if ( numComentarios<maxComentarios ) {
        comentarios[numComentarios++]=nuevoComentario;
    }
}


