#include "simo/timer/timer.h"
#include "simo/gpio/gpio.h"

static int8_t _counter_timer=0;  //instancias de timer en funcionamiento






static inline set_counter()
{
 portENTER_CRITICAL();
   _counter_timer =+1;
 portEXIT_CRITICAL();
}




/**
  * @brief Funcion que gestiona los handlers de los timers.
  * @retval None
  */


static void generic_handler(TimerHandle_t params)
{
    portENTER_CRITICAL();
    callback_function callback = (callback_function) pvTimerGetTimerID(params);
    (callback)(NULL); //ejecuto el callback
    portEXIT_CRITICAL();
}




/**
  * @brief GPIO Initialization Function
  * @param callback_function: funcion a ejecutar 
  * @param  bool_t:  funcion (x==1)periodica  o (x!=1) one shot
  * @retval status_t: Estado del sistema
  */

status_t set_timer_function( soft_timer_t* timer,callback_function callback, TickType_t time,uint8_t periodic)
{

  if((_counter_timer+1)> N_TIMERS_MAX)
  {
    return SIMO_FAIL;
  }

    BaseType_t _periodic;
    _periodic = (periodic == 1)? pdTRUE : pdFALSE;

    (*timer) = xTimerCreate("_SOFT_TIMER_",
                                  time,
                                 _periodic,
                                 (void*)callback,
                                 generic_handler);

    if((*timer) == NULL)
    {
        return SIMO_FAIL;
    }
    return   SIMO_OK;
}









void delete_timer_function(soft_timer_t* timer);



void start_timer(soft_timer_t* timer)
{
  xTimerStart((*timer),0);
}


void stop_timer(soft_timer_t* timer)
{
  xTimerStop((*timer),0);
}




void reset_timer(soft_timer_t* timer)
{
  xTimerReset((*timer),0);
}
