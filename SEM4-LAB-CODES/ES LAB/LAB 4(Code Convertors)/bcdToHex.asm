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
	LDR R0,=BCD 
	LDR R5,=HEX
	LDR R1,[R0]
	MOV R2,R1
	LSR R2,#4
	AND R1,0XF
	MOV R3,#0XA
	MLA R4,R3,R2,R1;
	STR R4,[R5]
STOP B STOP
BCD DCD 0X38
	AREA mydata,DATA,READWRITE
HEX DCD 0
	END
	