/*
 * STD_TYPES.h
 *
 *  Created on: Feb 13, 2023
 *      Author: a-m-m
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned int uint32;
typedef signed int int32;

typedef unsigned short int uint16_t;
typedef signed short int int16_t;

typedef float f32;
typedef long f64;
typedef long double f96;

typedef enum{
	BIT_RESET =0,
	BIT_SET=1
}BitStatus;

#define NULL ((void*)0)

#define ERROR_NULL_PTR  2u
#define STD_TYPES_OK 	1u
#define STD_TYPES_NOK 	0u


#endif /* _STD_TYPES_H_ */
