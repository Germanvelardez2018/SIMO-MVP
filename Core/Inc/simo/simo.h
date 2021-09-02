
/**
  @file simo.h
  @brief Funciones para iniciar el sistema
  @author German Velardez
  @date 9/2021


*/
#ifndef _SIMO_CORE_
#define _SIMO_CORE_
#include "simo/core.h"
#endif

/**
 * @brief   Inicia el sistema
 * @retval  Estado del sistema
 * 
 * **/
status_t init_simo(void);




/**
 * @brief   Apaga el sistema
 * @retval  none
 * 
 * **/
void deinit_simo(void);





/**
 * @brief   Leer en memoria los parametros de configuracion
 * @retval  Estado del sistema
 * 
 * **/

status_t reading_config(void);







/**
 * @brief   Carga los parametros de configuracion
 * @retval  Estado del sistema
 * 
 * **/

status_t load_config(void);