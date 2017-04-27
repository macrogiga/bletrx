#ifndef	_GLOBAL_H
#define _GLOBAL_H


/*

typedef 				signed char 					int8_t;
typedef					unsigned char 					uint8_t;

typedef 				signed int 						int16_t;
typedef 				unsigned int 					uint16_t;
typedef 				signed long int 				int32_t;
typedef 				unsigned long int 				uint32_t;
//typedef 				signed long long int 			int64_t;
//typedef 				unsigned long long int 			uint64_t;
*/



#define                 FALSE                         	0
#define					TRUE							1

#define                 MAX_uint8_t                     255
#define                 MAX_uint16_t                    65535
#define                 MAX_uint32_t                  	4294967295
#define                 MIN_int8_t                    	-128
#define                 MAX_int8_t                      127

#define                 MIN_int16_t                    	-32768
#define                 MAX_int16_t                    	32767
#define                 MIN_int32_t                    	-2147483648
#define                 MAX_int32_t                    	2147483647

#define					MIN(a,b)
#define					MAX(a,b)
#define					ABS(a,b)
//bit set 1
#define                 BitSet(var,bitno)               ((var) |= (1U<<(bitno)))
//bit clear 0
#define                 BitClr(var,bitno)               ((var) &= (~(1U<<(bitno))))
//bit xor
#define                 BitXor(var,bitno)               ((var) ^= (1U<<(bitno)))
//bit check 
#define                 BitVal(var,bitno)               ((((var)>>(bitno))&0X01))
//((var)	&  (1U<<(bitno)))

#define					NOP								_asm("nop")



#endif
