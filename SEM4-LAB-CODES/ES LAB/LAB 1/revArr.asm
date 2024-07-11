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
	LDR R0,=SRC
	LDR R1,=SRC
	ADD R1,#36
	MOV R5,#5
BACK LDR R2,[R0]
	LDR R3,[R1]
	STR R2,[R1],#-4
	STR R3,[R0],#4
	SUB R5,#1
	CMP R5,#0
	BNE BACK
STOP B STOP
	AREA mydata,DATA,READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0
	END
	
	