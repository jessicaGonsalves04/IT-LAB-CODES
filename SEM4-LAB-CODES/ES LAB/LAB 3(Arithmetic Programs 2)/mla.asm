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
	LDR R1,=SRC
	LDR R6,=DST
	LDR R1,[R1]
	MOV R2,R1
	MOV R0,R1
	MLA R3,R0,R1,R2
	MOV R5,#0
	MOV R4,#2
UP CMP R3,R4
	BLO EXIT
	SUB R3,R4
	ADD R5,#1
	B UP
EXIT
	STR R5,[R6]
STOP B STOP
SRC DCD 0X6
	AREA mydata,DATA,READWRITE
DST DCD 0
END
	
