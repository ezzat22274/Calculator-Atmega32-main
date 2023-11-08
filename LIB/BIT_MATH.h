/*
 * BIT_MATH.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Lenovo
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BITNUM)		(REG |= (1<<BITNUM))
#define CLR_BIT(REG,BITNUM)		(REG &= (~(1<<BITNUM)))
#define TOG_BIT(REG,BITNUM)		(REG ^= (1<<BITNUM))
#define GET_BIT(REG,BITNUM)		((REG >> BITNUM) & 0x01)

#endif /* LIB_BIT_MATH_H_ */
