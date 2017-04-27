#ifndef _MAIN_H_
#define _MAIN_H_

extern volatile uint8_t Work_Mode;


//display all command
#define	Work_Mode_Help 			'0'
//work mode beacon: wechat 
#define	Work_Mode_iBeacon 		'1'
//work mode eddystone
#define	Work_Mode_Eddystone_Uri '2'
#define	Work_Mode_Eddystone_Uid '3'
#define	Work_Mode_Eddystone_Tlm '4'

//work remote  1 key
#define Work_Mode_Remote 		'5'

#define	Work_Mode_Null 			'F'





#endif

