#ifndef ENERGYCAMPI_H
#define ENERGYCAMPI_H




#define SAIDENTIFIER  0x18C4
#define MODBUSERROR   (-1)
#define MODBUSOK      0


#define MODBUS_GET_OFFICAL_ADDR_FROM_INTERNAL(addr)               ((addr)+1)
#define MODBUS_GET_INTERNAL_ADDR_FROM_OFFICIAL(addr)              ((addr)-1)

#define MODBUS_COMMON_INPUTREG_MEMMAP_FIRST                       0x0001
#define MODBUS_COMMON_INPUTREG_MEMMAP_PROTOCOLVERSION             (( MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +    0) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_MANUFACTURERIDENTIFICATION  (( MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +    1) 

#define MODBUS_COMMON_INPUTREG_MEMMAP_APPBUILDNUMBER1             (( MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +   11) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_APPBUILDNUMBER0             (( MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +   12) 


#define MODBUS_COMMON_INPUTREG_MEMMAP_SPARE00                     (( MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +   30) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_LAST                        (MODBUS_COMMON_INPUTREG_MEMMAP_SPARE00)


#define MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST                        (MODBUS_COMMON_INPUTREG_MEMMAP_LAST + 1)
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRVALID               ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  2) 

#define MODBUS_SLAVE_INPUTREG_MEMMAP_STATUSENERGYCAM              ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  0) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTINSTALLATION           ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  1) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRINTHIGH             ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 36) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRINTLOW              ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 37) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRFRAC                ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 38) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_OCRPICDONE                   ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 41) 


//HOLDING REGISTER
#define  MODBUS_COMMON_HOLDINGREG_MEMMAP_FIRST                    0x0001
#define  MODBUS_COMMON_HOLDINGREG_MEMMAP_SPARE00                  (( MODBUS_COMMON_HOLDINGREG_MEMMAP_FIRST) +   30) 

#define  MODBUS_COMMON_HOLDINGREG_MEMMAP_LAST                     MODBUS_COMMON_HOLDINGREG_MEMMAP_SPARE00

#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST                      (MODBUS_COMMON_HOLDINGREG_MEMMAP_LAST + 1)
#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_ACTIONOCR                  ((MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST) +  2)  


#endif