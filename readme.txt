MCU: STM8L 
EVB: AS06_VTB01_V3.0


用户可能修改的参数:
1, 广播包内容数据 adv_data
2, 广播包内容长度 LEN_DATA
3, 发射次数 txcnt
4, 接收次数 rxcnt

5, 射频发射功率BLE_TX_POWER
6, 接收超时时间BLE_RX_TIMEOUT,这个时间会影响接收效率和功耗
7, 功耗方面,根据mcu实际情况设置合适的BLE_START_TIME




20170427	调整程序框架,用户程序可以在main()中增加,根据需要调用ble发送和接收的次数.
20170428	update adv_data in BLE_TRX(), modify indent.
20170502	improve robustness.
20170503	Add macro BLE_GUARD_TIME, clean code.
20170810  Add carrier function call, for xtal capacitor tuning.
20170912  change example adv data, add register setting in BLE_Init().
20171220  change xoib for better chip adaption; merge xtal control into pwrup/down.
