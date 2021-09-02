/**
 * @file core.h
 * @brief Definicion de estructuras y enumeraciones del sistema
 * @author German Velardez
 * @date 9/2021
 * 
 * 
 * */



/*! Modos de funcionamiento del sistema */
typedef enum{

    
    SIMO_ONLINE,   /*!<  Sistema funcionando CON comunicacion a internet */
    
    SIMO_OFFLINE   /*!<  Sistema funcionando SIN comunicacion a internet */

} mode_t;




/*! Estados del sistema */

typedef enum
{
   SIMO_FAIL,   /*!< La funcion fallo */
    
   SIMO_OK   /*!<  La funcion retorno exitosamente */
}status_t;