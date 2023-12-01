/*
 * lifo.h
 *
 *  Created on: Nov 30, 2023
 *      Author: ziade
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"

//USER Configuration
//select element type (unit8_t,unit16_t, unit32_t...)

#define element_type uint32_t
//create buffer1
#define width1 5
element_type buffer1[width1];


//type definitions
typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_type* base ;
	element_type* head ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIS
LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf ,element_type item);//push
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf ,element_type* item);//pop
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf ,element_type* buf, unsigned int length);
LIFO_status	LIFO_IS_FULL(LIFO_Buf_t* lifo_buf);




#endif /* LIFO_H_ */
