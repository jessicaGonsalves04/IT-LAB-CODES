	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R4,=STR1
	LDR R0,[R4]
	LDR R5,=STR2
	LDR R1,[R5]
	SUBS R3,R0,R1
STOP B STOP
STR1 DCD 0X00000001
STR2 DCD 0X00000002
	AREA mydata,DATA,READWRITE
DST DCD 0	
	END
	
	
	