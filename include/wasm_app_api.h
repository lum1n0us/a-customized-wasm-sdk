#ifndef _WASM_APP_H_
#define _WASM_APP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus               /* if used by C++ code */
extern "C" {                     /* we need to export the C interface */
#endif

/* Define log levels */
#define LOG_LEVEL_ERR 0
#define LOG_LEVEL_WRN 1
#define LOG_LEVEL_INF 2
#define LOG_LEVEL_DBG 3
#define LOG_LEVEL_VERB 4

/* Set the current log level  */
#define CUR_LOG_LEVEL LOG_LEVEL_INF

/* Define logging macros based on the current log level */
#if CUR_LOG_LEVEL >= LOG_LEVEL_VERB
    #define LOG_VERB(fmt, ...) printf("[WASM_APP_VERB] " fmt, ##__VA_ARGS__)
#else
    #define LOG_VERB(fmt, ...) /* No operation */
#endif

#if CUR_LOG_LEVEL >= LOG_LEVEL_DBG
    #define LOG_DBG(fmt, ...) printf("[WASM_APP_DBG] " fmt, ##__VA_ARGS__)
#else
    #define LOG_DBG(fmt, ...) /* No operation */
#endif

#if CUR_LOG_LEVEL >= LOG_LEVEL_INF
    #define LOG_INF(fmt, ...) printf("[WASM_APP_INF] " fmt, ##__VA_ARGS__)
#else
    #define LOG_INF(fmt, ...) /* No operation */
#endif

#if CUR_LOG_LEVEL >= LOG_LEVEL_WRN
    #define LOG_WRN(fmt, ...) printf("[WASM_APP_WRN] " fmt, ##__VA_ARGS__)
#else
    #define LOG_WRN(fmt, ...) /* No operation */
#endif

#if CUR_LOG_LEVEL >= LOG_LEVEL_ERR
    #define LOG_ERR(fmt, ...) printf("[WASM_APP_ERR] " fmt, ##__VA_ARGS__)
#else
    #define LOG_ERR(fmt, ...) /* No operation */
#endif

#ifdef __cplusplus
}
#endif

#endif
