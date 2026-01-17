#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/* CPU clock (állítsd a valós SYSCLK-re) */
#define configCPU_CLOCK_HZ              (12000000UL)
#define configTICK_RATE_HZ              (1000)

/* Scheduler */
#define configUSE_PREEMPTION            1
#define configUSE_TIME_SLICING          0

/* Tasks */
#define configMAX_PRIORITIES            4
#define configMINIMAL_STACK_SIZE        64
#define configTOTAL_HEAP_SIZE           (3 * 1024)

/* Cortex-M0 specifikus */
#define configUSE_16_BIT_TICKS          1
#define configENABLE_MPU 0

/* Synchronization */
#define configUSE_MUTEXES               1
#define configUSE_COUNTING_SEMAPHORES   1

/* Memory */
#define configSUPPORT_STATIC_ALLOCATION 1
#define configSUPPORT_DYNAMIC_ALLOCATION 1

/* Hooks */
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configUSE_MALLOC_FAILED_HOOK    0
#define configCHECK_FOR_STACK_OVERFLOW  2

/* Software timers (később kikapcsolható) */
/*-----------------------------------------------------------
 * Software timer definitions.
 *----------------------------------------------------------*/

#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH        5
#define configTIMER_TASK_STACK_DEPTH    ( configMINIMAL_STACK_SIZE )


/* Optional FreeRTOS API functions */
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_xResumeFromISR              1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_vTaskDelayUntil             1
#define INCLUDE_xTaskGetSchedulerState      1


/* Assertions */
#define configASSERT(x) if((x)==0) { taskDISABLE_INTERRUPTS(); for(;;); }

#endif /* FREERTOS_CONFIG_H */
