TITLE Assignment 1     (CS271_prog1.asm)

; Author: Erin Alltop
; Email: alltope@oregonstate.edu
; Course / Project ID: CS271-400 / Program 1                
; Due Date: 4-15-17
; Description: Calculates the sum, difference, product, and quotient of numbers entered by the user.

INCLUDE Irvine32.inc

; (insert constant definitions here)

.data

userName	BYTE	33 DUP(0) ; string for name entered by user
intro_1		BYTE	"Hi, my name is Erin and this is my Programming Assignment #1! ", 0
intro_2		BYTE	"In this program, you will enter two numbers and I will display the sum, difference, product, quotient, and remainder of the numbers. ", 0
prompt_1	BYTE	"Please enter your first number: ", 0
prompt_2	BYTE	"Now enter your second number: ", 0
prompt_3	BYTE	"The second number must be less than the first number! Try that again: ", 0
prompt_4	BYTE	"Would you like to play again? Enter 1 for yes or 0 for no: ", 0
EC_1		BYTE	
numOne		DWORD	?
numTwo		DWORD	?
addNum		BYTE	" + ", 0
subNum		BYTE	" - ", 0
eqNum		BYTE	" = ", 0
divNum		BYTE	" / ", 0
mulNum		BYTE	" x ", 0
remNum		BYTE	" remainder ", 0
goodbye		BYTE	"Thanks for playing! Goodbye ", 0
addRes		DWORD	?
divRes		DWORD	?
mulRes		DWORD	?
diRes		DWORD	?
remRes		DWORD	?
subRes		DWORD	?



.code
main PROC

; Introduction
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CrLf
	call	CrLf
	mov		edx, OFFSET intro_2
	call	WriteString
	call	CrLf

; Get the data
	beginProg:
	call	CrLf
	mov		edx, OFFSET prompt_1
	call	WriteString
	call	ReadInt
	mov		numOne, eax

	mov		edx, OFFSET prompt_2
	call	WriteString
	jmp		compareVal

	compareVal:		; compare the values
	call	ReadInt
	cmp		numOne, eax
	jl		tryAgain
	jnl		continueProg

	tryAgain:		; if less than, prompt for another number
	mov		edx, OFFSET prompt_3
	call	WriteString
	jmp		compareVal

	continueProg:		; if not less than, good to go
	mov		numTwo, eax
	call	CrLf
	

; Calculate the required values
	
	; addition
	mov		eax, numOne
	mov		ebx, numTwo
	add		eax, ebx
	mov		addRes, eax

	;subtraction
	mov		eax, numOne
	mov		ebx, numTwo
	sub		eax, ebx
	mov		subRes, eax

	;multiplication
	mov		eax, numOne
	mov		ebx, numTwo
	mul		ebx
	mov		mulRes, eax

	;division and remainder
	mov		eax, numOne
	cdq
	mov		ebx, numTwo
	div		ebx
	mov		divRes, eax
	mov		remRes, edx
	


; Display the results

	; addition
	mov		eax, numOne
	call	WriteDec
	mov		numOne, eax
	mov		edx, OFFSET addNum
	call	WriteString
	mov		eax, numTwo
	call	WriteDec
	mov		numTwo, eax
	mov		edx, OFFSET	eqNum
	call	WriteString
	mov		eax, addRes
	call	WriteDec
	call	CrLf

	; subtraction
	mov		eax, numOne
	call	WriteDec
	mov		numOne, eax
	mov		edx, OFFSET subNum
	call	WriteString
	mov		eax, numTwo
	call	WriteDec
	mov		numTwo, eax
	mov		edx, OFFSET eqNum
	call	WriteString
	mov		eax, subRes
	call	WriteDec
	call	CrLf

	; multiplication
	mov		eax, numOne
	call	WriteDec
	mov		numOne, eax
	mov		edx, OFFSET mulNum
	call	WriteString
	mov		eax, numTwo
	call	WriteDec
	mov		numTwo, eax
	mov		edx, OFFSET eqNum
	call	WriteString
	mov		eax, mulRes
	call	WriteDec
	call	CrLf

	; division and remainder
	mov		eax, numOne
	call	WriteDec
	mov		numOne, eax
	mov		edx, OFFSET divNum
	call	WriteString
	mov		eax, numTwo
	call	WriteDec
	mov		numTwo, eax
	mov		edx, OFFSET eqNum
	call	WriteString
	mov		eax, divRes
	call	WriteDec
	mov		edx, OFFSET remNum
	call	WriteString
	mov		eax, remRes
	call	WriteDec
	call	CrLf

; Play again?
	call	crLf
	mov		edx, OFFSET prompt_4
	call	WriteString
	call	ReadInt
	cmp		eax, 1
	je		beginProg
	cmp		eax, 0
	je		finishProg
	

; Say goodbye
	finishProg:
	call	crLf
	mov		edx, OFFSET goodbye
	call	WriteString
	call	crLf	
	call	crLf

	exit	; exit to operating system
main ENDP


END main
