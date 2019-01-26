TITLE Composite Numbers     (CS271_Prog4.asm)

; Author: Erin Alltop
; Email: alltope@oregonstate.edu
; Course / Project ID: CS271-400 / Program 4                
; Due Date: 5-14-17
; Description: This program calculates composite numbers. The user is instructed to enter the number of
; composites to be displayed and is prompted to enter an integer in the range [1-400]. The program verifies
; the number is within range, and then displays all of the composite nmbers up to and including the nth
; composite. Results are dispayed 10 composites per line with at least 3 spaces between the numbers.

INCLUDE Irvine32.inc

UPPER_LIMIT = 400;	
LOWER_LIMIT = 1;
LINE_COMP = 0;

.data

progName	BYTE	"Composite Numbers", 0
progAuth	BYTE	"Programmed by Erin Alltop", 0
EC1			BYTE	"**EC1: Displays the results in aligned columns", 0
instr1		BYTE	"Enter the number of composite numbers you would like to see. ", 0
instr2		BYTE	"Pick a number within the [1 .. 400] range. ", 0
instr3		BYTE	"Enter the number of composites to display: ", 0
oops1		BYTE	"Out of range. Pick a number within the [1 .. 400] range. ", 0
goodbye 	BYTE	"That's all for now! Goodbye. ", 0
userNum		DWORD	?			; user input of number desired
primeCom	DWORD	2			; used to test the composites
lineNow		DWORD	-1			; keeps track of when a line is needed
spaces		BYTE	"   ", 0	
trueFalse	DWORD	0			; keeps track of whether a number is composite or not (boolean)
count		DWORD	?			; keeps track of the outer loop counter
comTest		DWORD	4			; the current number being tested (starts at 4 - first composite)


.code
main PROC

; this main procedure block simply calls later procedures in the program

	call	introduction
	call	getUserData
	call	showComposites
	call	farewell

	exit	; exit to operating system
main ENDP

; Introduction procedure

introduction PROC
	mov		edx, OFFSET progName	
	call	WriteString				; display program name
	call	CrLf
	mov		edx, OFFSET progAuth
	call	WriteString				; display author name
	call	CrLf
	mov		edx, OFFSET EC1			; displays extra credit statement
	call	WriteString
	call	CrLf
	call	CrLf
	ret
introduction ENDP

; Getting data from the user

getUserData PROC
	mov		edx, OFFSET instr1		; first instruction 
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instr2		; second instruction
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instr3		; third instruction
	call	WriteString
	call	ReadInt					; obtaining user input
	call	validate				; call validate procedure
	

; validate user input

validate PROC	
L1:	cmp		eax, LOWER_LIMIT		; compare upper limit, jump to OOPS label if less than
	jl		OOPS
	cmp		eax, UPPER_LIMIT		; compare lower limit, jump to OOPS label if greater than
	jg		OOPS
	jmp		GOOD					; move on if ok

OOPS: 
	mov		edx, OFFSET oops1		; error text and requesting new input
	call	WriteString
	call	ReadInt					; read new input and jump to top of validation procedure
	jmp		L1

GOOD:
	ret
validate ENDP

	
getUserData ENDP

; calculate and display composite numbers

showComposites PROC
	mov		userNum, eax	; move the user input to variable
	mov		ecx, userNum	; save user input into ecx for outer loop

L1:	
	mov		count, ecx		; store outer loop count into a variable
	mov		ecx, comTest	; move the first composite number into ecx for inner loop (don't need to loop beyond this number)
	call	isComposite		; call isComposite procedure
	mov		eax, trueFalse	
	cmp		trueFalse, 1	
	je		PRINT			; if number is composite (1), print the number
	jne		KEEPGOING		; if number is not composite (0), move on
	
PRINT:
	mov		eax, lineNow	; divide incremented lineNow variable by 10 to see if a new line is needed
	mov		ebx, 10
	cdq
	div		ebx
	cmp		edx, LINE_COMP
	je		NEWLINE			; add new line if equal
	jne		ADDSPACES		; add spaces if not equal

CONTINUE:
	mov		eax, comTest	; print the current number
	call	WriteDec
	mov		al, 9			; add a tab for aligning columns
	call	WriteChar
	jmp		KEEPGOING		; move on

NEWLINE:
	call	CrLf
	jmp		CONTINUE

ADDSPACES:
	mov		edx, OFFSET spaces
	call	WriteString
	jmp		CONTINUE

KEEPGOING:
	inc		comTest			; increment number we are testing for composite
	mov		primeCom, 2		; reset the composite testing helper variable back to 2

	loop	L1
	ret

showComposites ENDP

; is the number composite? 

isComposite PROC

L2:	mov		eax, comTest	; divide number we are testing by helper number
	cdq
	mov		ebx, primeCom
	div		ebx
	cmp		edx, LINE_COMP ; if the remainder is 0 then we know it is divisible by primeCom
	je		ITSTRUE
	jne		ITSFALSE

ITSTRUE:
	mov		eax, primeCom
	mov		ebx, comTest
	cmp		eax, ebx		; check false flag - was the number being divided by itself?
	je		DONE			; if equal, skip to end
	mov		eax, 1			
	mov		trueFalse, eax	; if not equal mark as true
	inc		lineNow			; increment line counter
	mov		ecx, count		; restore outer loop count to ecx
	ret

ITSFALSE:
	inc		primeCom		; if not divisible, increment primeCom and test again
	loop	L2

DONE:
	mov		eax, 0			; if not composite, set trueFalse to false
	mov		trueFalse, eax
	mov		eax, count		; add 1 back to count for outer loop so it prints correct amount of numbers
	mov		ebx, 1
	add		eax, ebx
	mov		count, eax
	mov		ecx, count		; restore count to ecx for outer loop
	ret

isComposite ENDP


; say goodbye

farewell PROC
	call	CrLf
	call	CrLf
	mov		edx, OFFSET goodbye		; farewell comment block. see ya!
	call	WriteString
	call	CrLf
	call	CrLf
	ret
farewell ENDP

END main
