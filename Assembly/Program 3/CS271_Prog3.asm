TITLE Integer Accumulator     (CS271_Prog3.asm)

; Author: Erin Alltop
; Course / Project ID: CS271-400 / Program 3                 
; Due Date: 5-7-17
; Description: This program prompts the user to enter a number, validates the user input to be
; in [-100, -1] (inclusive). Counts and accumulates the valid user numbers until a non-negative
; number it entered. It then calculates the average of the negative numbers and displays:
; i. the number of negative numbers entered
; ii. the sum of negative numbers entered
; iii. the average, rounded to the nearest integer
; iv. a parting message (with the user's name)

INCLUDE Irvine32.inc

LOWER_LIMIT = -100; 

.data

EC1				BYTE	"EC: Number the lines during user input. ", 0
progName		BYTE	"Integer Accumulator", 0
progAuth		BYTE	"Programmed by Erin Alltop", 0
userName		BYTE	33 DUP(0) ; string for name entered by user
greetUser1		BYTE	"What is your name? ", 0	
greetUser2		BYTE	"Hello, ", 0
farewell		BYTE	"That's all for now! See you later, ", 0
userInstr1		BYTE	"Please enter numbers in [-100, -1] range.", 0
userInstr2		BYTE	"Enter a non-negative number when you are finished to see results. ", 0
userInstr3		BYTE	"Enter a number: ", 0
oopsMess		BYTE	"Oops! That number was too low. Please enter a number in [-100, -1] range. ", 0
accum			SDWORD	0
totAccum		SDWORD	0
numLines		DWORD	1
numLinesText	BYTE	". ", 0
results1		BYTE	"You entered ", 0
results2		BYTE	" valid numbers.", 0
noneEnt			BYTE	"You didn't enter any valid numbers! ", 0
results3		BYTE	"The sum of the numbers you entered is ", 0
aveResults		SDWORD	?
results4		BYTE	"The average of the numbers entered, rounded to the nearest integer is: ", 0

.code
main PROC

; Display program title and programmer's name
	mov		edx, OFFSET progName	
	call	WriteString				; display program name
	call	CrLf
	mov		edx, OFFSET progAuth
	call	WriteString				; display author name
	call	CrLf
	mov		edx, OFFSET EC1
	call	WriteString
	call	CrLf
	call	CrLf

; Get user's name and greet user
	mov		edx, OFFSET greetUser1
	call	WriteString				; ask for user's name
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString
	mov		edx, OFFSET greetUser2
	call	WriteString				; display greeting with user name
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf
	call	CrLf

; Display instructions for the user
	mov		edx, OFFSET userInstr1
	call	WriteString				; display first set of user instructions
	call	CrLf
	mov		edx, OFFSET userInstr2
	call	WriteString				; display second set of user instructions
	call	CrLf

; Prompt user to enter number until non-negative number is entered
PROMPT:
	clc
	mov		eax, numLines
	call	WriteDec
	mov		edx, OFFSET numLinesText
	call	WriteString
	mov		edx, OFFSET userInstr3
	call	WriteString				; prompt user for integer
	call	ReadInt
	test	eax, eax				; check flag
	js		CHECK					; if signed, keep prompting for a number
	jns		CALCULATE				; if not signed, jump to calculations

CHECK:		; Check if number is lower than the lower limit (constant)
	cmp		eax, LOWER_LIMIT
	jl		OOPS
	inc		accum
	inc		numLines
	add		totAccum, eax
	jmp		PROMPT

OOPS:		; Oops, invalid number entered.
	mov		edx, OFFSET oopsMess
	call	WriteString
	call	CrLf
	jmp		PROMPT


CALCULATE:

; i. Display number of negative numbers entered (if none, display a special message and skip to iv)
	mov		eax, accum
	cmp		eax, 0
	je		SKIPME 

; Calculate the (rounded integer) average of the negative numbers
	mov		eax, totAccum
	cdq
	mov		ebx, accum
	idiv	ebx
	mov		aveResults, eax

; Display results:
	call	CrLf
	mov 	edx, OFFSET results1
	call	WriteString
	mov		eax, accum
	call	WriteDec
	mov		edx, OFFSET results2
	call	WriteString
	call	CrLf

; ii. Display the sum of the negative numbers entered
	call	CrLf
	mov		edx, OFFSET results3
	call	WriteString
	mov		eax, totAccum
	call	WriteInt

; iii. Display the average, rounded to the nearest integer
	call	CrLf
	mov		edx, OFFSET results4
	call	WriteString
	mov		eax, aveResults
	call	WriteInt
	jmp		FINISH

; iv. Display a parting message (with the user's name)

SKIPME:		; if there are no valid numbers, display special message
	call	CrLf
	mov		edx, OFFSET noneEnt
	call	WriteString

FINISH:
	call	CrLf
	call	CrLf
	mov		edx, OFFSET farewell
	call	WriteString				; goodbye!
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf
	call	CrLf


	exit	; exit to operating system
main ENDP

; 

END main
