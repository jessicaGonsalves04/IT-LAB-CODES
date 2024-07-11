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
	LDR R0,=NUM1
	LDR R0,[R0];R0=NUM1
	LDR R6,=LCM
	LDR R1,=NUM2;
	LDR R1,[R1];R1=NUM2
	MOV R5,#0;
	MOV R7,#1; VALUE OF I
DO 
	MUL R3,R7,R0;i*a is stored in R3
UP CMP R3,R1; Division using repetitive subtraction
	BLO EXIT
	SUB R3,R1
	ADD R5,#1
	B UP	
EXIT
	CMP R3,#0
	BEQ EXITT
	ADD R7,#1
	BNE DO
EXITT
	MUL R8,R7,R0
	STR R8,[R6]
STOP B STOP 
NUM1 DCD 0X8
NUM2 DCD 0X6
	AREA mydata,DATA,READWRITE
LCM DCD 0
	END
	
	
	
