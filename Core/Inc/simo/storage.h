
/**
  @file store.h
  @brief Funciones para respaldar datos en memoria. 
  @author German Velardez
  @date 10/2021

*/


#ifndef SIMO_CORE_H

  #include "simo/core.h"
  #define SIMO_CORE_H 

#endif




/**
 * @brief   Inicia el sistema de archivos del sistema
 * 
 * @param   None
 * @return  status_t:  Estado del sistema
 * 
 * **/
status_t init_storage(void);



/**
 * @brief   Cierra el sistema de archivos del sistema
 * @param   None
 * @return  None
 * 
 * **/
void deinit_storage(void);




/**
 * @brief   Ingreso un dato en el sistema de archivos
 * @param   frame_t*: Direccion de memoria del dato a almacenar
 * @retval  status_t: Estado del sistema
 * 
 * **/
status_t set_data_in_storage(frame_t* data);




/**
 * @brief   Extraigo un dato del sistema de archivos
 * @param   frame_t*: Direccion de memoria donde se guardara el dato extraido 
 * @retval  status_t: Estado del sistema
 * 
 * **/
status_t get_data_in_storage(frame_t* data);