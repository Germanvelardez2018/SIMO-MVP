/**
  @file timer.h
  @brief Funciones para lanzar rutinas periodicas o one shot. Nota: no recomendable cuando se necesita una alta presion
  @author German Velardez
  @date 9/2021


*/

#include "FreeRTOSConfig.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"


#include "simo/config.h"



#ifndef SIMO_CORE_H

  #include "simo/core.h"
  #define SIMO_CORE_H 

#endif


typedef void (*callback_function)(void*);
/**< Puntero a funcion callback para asociar a timer por software */

typedef  TimerHandle_t  soft_timer_t; 
/**< Timer por software, basado en api Freertos */










/**
  * @brief Asocia una funcion de callback con un sotf_timer_t
  * @param  soft_timer_t* timer: punter a la instancia del timer
  * @param  callback_function callback: funcion a ejecutar 
  * @param  bool_t periodic:  funcion (x==1)periodica  o (x!=1) one shot
  * @retval status_t: Estado del sistema
  */

status_t create_timer_function( soft_timer_t* timer,callback_function callback, TickType_t time,uint8_t periodic);



/**
  * @brief Elimina la configuracion de un timer
  * @param  soft_timer_t* timer: Puntero a la instancia del timer
  *
  * @retval None
  */

void delete_timer_function(soft_timer_t* timer);

/**
  * @brief Inicia el timer
  * @param  soft_timer_t* timer: Puntero a la instancia del timer
  *
  * @retval None
  */

void start_timer(soft_timer_t* timer);

/**
  * @brief Frena un timer que ya fue configurado e iniciado.
  * @param  soft_timer_t* timer: Puntero a la instancia del timer
  *
  * @retval None
  */

void stop_timer(soft_timer_t* timer);



/**
  * @brief Resetea el contador del timer.
  * @param  soft_timer_t* timer: Puntero a la instancia del timer
  *
  * @retval None
  */

void reset_timer(soft_timer_t* timer)
