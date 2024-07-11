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
	LDR R0,=N1
	LDR R0,[R0]
	LDR R1,=N2
	LDR R1,[R1]
	LDR R2,=GCD
UP CMP R0,R1
	BEQ EXIT;
	SUBHI R0 ,R1
	SUBLO R1,R0
	B UP
EXIT STR R0,[R2]
STOP B STOP
N1 DCD 0x20;32
N2 DCD 0x18;24
	AREA mydata,DATA,READWRITE
GCD  DCD 0
	END


	