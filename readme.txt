MCU: STM8L 
EVB: AS06_VTB01_V3.0


�û������޸ĵĲ���:
1, �㲥���������� adv_data
2, �㲥�����ݳ��� LEN_DATA
3, ������� txcnt
4, ���մ��� rxcnt

5, ��Ƶ���书��BLE_TX_POWER
6, ���ճ�ʱʱ��BLE_RX_TIMEOUT,���ʱ���Ӱ�����Ч�ʺ͹���
7, ���ķ���,����mcuʵ��������ú��ʵ�BLE_START_TIME




20170427	����������,�û����������main()������,������Ҫ����ble���ͺͽ��յĴ���.
20170428	update adv_data in BLE_TRX(), modify indent.
20170502	improve robustness.
20170503	Add macro BLE_GUARD_TIME, clean code.
20170810  Add carrier function call, for xtal capacitor tuning.
20170912  change example adv data, add register setting in BLE_Init().
20171220  change xoib for better chip adaption; merge xtal control into pwrup/down.
