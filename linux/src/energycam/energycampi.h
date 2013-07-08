#ifndef ENERGYCAMPI_H
#define ENERGYCAMPI_H

#define SA_IMG_TYPE_APP_SENSOR              0x0100
#define SA_IMAGE_HEADER_MAGIC               0xFA51BEAF

#define SA_FIRMWARE_TYPE_APP_WMBUS_MODE_T2  0x0001
#define SA_FIRMWARE_TYPE_APP_WMBUS_MODE_S2  0x0002

typedef uint32_t saImageType_t;   
typedef uint32_t saFirmwareType_t; // one of #define SA_FIRMWARE_TYPE_APP_xx; only lower 16 bits are transported via Modbus!

typedef struct _SA_IMAGE_HEADER_ {
    uint32_t  crc32;          // 4 Bytes
    saImageType_t imageType;  // 4 CRC calculation starts here
    uint32_t  imageFirstAddr; // 4 
    uint32_t  length;         // 4 Length of image for CRC calculation (includes field crc32)
    uint32_t  version;        // 4
    uint32_t  magic;          // 4 
    uint32_t  intVecTblAddr;  // 4 
    uint32_t  firmwareType;   // 4 
    uint32_t  spare1;         // 4
    uint32_t  spare2;         // 4
    //                    sum 40 bytes
} tsaImageHeader, *tpsaImageHeader;

typedef struct _SA_IMAGE_ {
    uint8_t  firstByte;          // 1st byte
} tsaImage, *tpsaImage;


//---------------------------------------------------------
#define MODBUS_MAXDATACHUNK_UINT16_CNT 123      																	// max rtu modbus payload counted in uint16_t
#define UPDATE_IMAGE_DATA_BYTE_CNT 		(MODBUS_MAXDATACHUNK_UINT16_CNT*2 -4 -2)    // -4 = sizeof(uint32_t) used for chunkStartAddress, -2 for needed multiple of 4 of imageData

typedef struct _tUpdateChunkAsModbusRegs_ {
    uint16_t chunkStartAddrHigh;
    uint16_t chunkStartAddrLow;
    uint16_t imageData[UPDATE_IMAGE_DATA_BYTE_CNT/2];
} tUpdateChunkAsStruct;

typedef union _tModbusUpdateChunk_ {
    tUpdateChunkAsStruct logical;
    uint16_t             asModbusRegs[MODBUS_MAXDATACHUNK_UINT16_CNT];
} tModbusUpdateChunk, *tpModbusUpdateChunk;

//---------------------------------------------------------

#define SAIDENTIFIER  0x18C4
#define MODBUSERROR   (-1)
#define MODBUSOK      0

//Installation Status
#define INSTALLATION_FAILED  0xFFFF
#define INSTALLATION_NOTDONE 0xFFFE
#define INSTALLATION_ONGOING 0xFFFD
#define INSTALLATION_NODIGITS 0x0000

#define MODBUS_GET_OFFICAL_ADDR_FROM_INTERNAL(addr)               ((addr)+1)
#define MODBUS_GET_INTERNAL_ADDR_FROM_OFFICIAL(addr)              ((addr)-1)

//INPUT REGISTER
#define MODBUS_COMMON_INPUTREG_MEMMAP_FIRST                       0x0001
#define MODBUS_COMMON_INPUTREG_MEMMAP_PROTOCOLVERSION             ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +  0) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_MANUFACTURERIDENTIFICATION  ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) +  1) 

#define MODBUS_COMMON_INPUTREG_MEMMAP_APPBUILDNUMBER1             ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) + 11) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_APPBUILDNUMBER0             ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) + 12) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_APPFIRMWARETYPE             ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) + 16) 

#define MODBUS_COMMON_INPUTREG_MEMMAP_SPARE00                     ((MODBUS_COMMON_INPUTREG_MEMMAP_FIRST) + 30) 
#define MODBUS_COMMON_INPUTREG_MEMMAP_LAST                        (MODBUS_COMMON_INPUTREG_MEMMAP_SPARE00)

#define MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST                        (MODBUS_COMMON_INPUTREG_MEMMAP_LAST + 1)
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRVALID               ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  2) 

#define MODBUS_SLAVE_INPUTREG_MEMMAP_STATUSENERGYCAM              ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  0) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTINSTALLATION           ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) +  1) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRINTHIGH             ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 36) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRINTLOW              ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 37) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_RESULTOCRFRAC                ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 38) 
#define MODBUS_SLAVE_INPUTREG_MEMMAP_OCRPICDONE                   ((MODBUS_SLAVE_INPUTREG_MEMMAP_FIRST) + 41) 

#define MODBUS_COMMON_INPUTREG_VIRTUAL_FIRST                      0x8000    
#define MODBUS_COMMON_INPUTREG_VIRTUAL_UPDATECRCOK                (MODBUS_COMMON_INPUTREG_VIRTUAL_FIRST)

//HOLDING REGISTER
#define MODBUS_COMMON_HOLDINGREG_MEMMAP_FIRST                     0x0001
#define MODBUS_COMMON_HOLDINGREG_MEMMAP_SPARE00                   ((MODBUS_COMMON_HOLDINGREG_MEMMAP_FIRST) + 30) 

#define MODBUS_COMMON_HOLDINGREG_MEMMAP_LAST                      MODBUS_COMMON_HOLDINGREG_MEMMAP_SPARE00

#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST                      (MODBUS_COMMON_HOLDINGREG_MEMMAP_LAST + 1)
#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_ACTIONOCRINSTALLATIONTO    ((MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST) +  0)  
#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_ACTIONOCRINSTALLATION      ((MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST) +  1)  
#define MODBUS_SLAVE_HOLDINGREG_MEMMAP_ACTIONOCR                  ((MODBUS_SLAVE_HOLDINGREG_MEMMAP_FIRST) +  2)  

#define  MODBUS_COMMON_HOLDINGREG_VIRTUAL_FIRST                   0x8000     
#define  MODBUS_COMMON_HOLDINGREG_VIRTUAL_UPDATECHUNKSTREAM       (MODBUS_COMMON_HOLDINGREG_VIRTUAL_FIRST)

#endif
