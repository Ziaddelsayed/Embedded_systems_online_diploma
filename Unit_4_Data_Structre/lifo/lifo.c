/*
 * lifo.c
 *
 *  Created on: Nov 30, 2023
 *      Author: ziade
 */

#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"

//push
LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf ,element_type item)
{
	//check lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	//check lifo is fill
	if(LIFO_IS_FULL(lifo_buf)== LIFO_full)
		return LIFO_full;

	//add value
	*(lifo_buf->head)=item ;
	lifo_buf->head++ ;
	lifo_buf->count++ ;

	return LIFO_no_error;

}
//pop
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf ,element_type* item)
{
	//check lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	//check lifo is empty
	if(lifo_buf->count == 0)
		return LIFO_empty;
	//pop value
	lifo_buf->head-- ;
	*item =*(lifo_buf->head);
	lifo_buf->count-- ;

	return LIFO_no_error;


}
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf ,element_type* buf, unsigned int length)
{
	if(buf == NULL)
		return LIFO_Null;
	lifo_buf ->base=buf;
	lifo_buf ->head=buf;
	lifo_buf ->length=length;
	lifo_buf ->count=0;
	return LIFO_no_error;


}
LIFO_status	LIFO_IS_FULL(LIFO_Buf_t* lifo_buf)
{
	if(!lifo_buf->base || !lifo_buf->head )
		return LIFO_Null;

	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	return LIFO_no_error;
}
