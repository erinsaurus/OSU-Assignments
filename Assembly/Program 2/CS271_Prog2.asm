TITLE Fibonacci Numbers     (CS271_Prog2.asm)

; Author: Erin Alltop
; Email: alltope@oregonstate.edu
; Course / Project ID: CS271-400 / Program 2
; Due Date: 4-23-17
; Description: This program calculates Fibonacci numbers. It will ask the user to select two numbers within a range,
; validate the input, and calculate and dispay all of the Fibonacci numbers up to an including the nth term.


INCLUDE Irvine32.inc

UPPER_LIMIT = 46 ; upper limit is defined and used as a constant 
LOWER_LIMIT = 1; lower limit


.data

progName	BYTE	"Fibonacci Numbers", 0
progAuth	BYTE	"Programmed by Erin Alltop", 0	
EC1			BYTE	"**EC: Displays the numbers in aligned columns"
userName	BYTE	33 DUP(0) ; string for name entered by user
greetUser1	BYTE	"What is your name? ", 0	
greetUser2	BYTE	"Hello, ", 0
farewell	BYTE	"That's all for now! See you later, ", 0
userInstr1	BYTE	"I will take a number your choosing and display all of the Fibonacci numbers up to and including the nth term! ", 0
userInstr2	BYTE	"Please enter the number of Fibonacci numbers you wish to be displayed. ", 0
userInstr3	BYTE	"Enter the number as an integer in the range [1 .. 46]: ", 0
numTerms	DWORD	?
errInstr	BYTE	"Oops! Your integer is out of range. Please enter an integer in the range [1 .. 46]: ", 0
userInt		DWORD	?
fibSum		DWORD	0
prevFib		DWORD	1
spaces		BYTE	"     ", 0
lineCnt		DWORD	0
printMe		DWORD	?

; Fibonacci numbers displayed as they are generated (does not need to be in an array)

.code
main PROC

; introduction
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


; userInstructions
	mov		edx, OFFSET userInstr1
	call	WriteString				; display first set of user instructions
	call	CrLf
	call	CrLf
	mov		edx, OFFSET userInstr2
	call	WriteString				; display second set of user instructions
	call	CrLf

; getUserData
	getData:
	mov		edx, OFFSET userInstr3
	call	WriteString				; prompt user for integer
	jmp		compareVal

	compareVal:						; comparing upper and lower limits of user input
	call	ReadInt
	mov		userInt, eax
	cmp		userInt, UPPER_LIMIT
	jg		tryAgain			; jump if greater than upper limit
	cmp		userInt, LOWER_LIMIT
	jl		tryAgain			; jump if less than lower limit
	jmp		continueProg		; jump to continue of neither violation found

	tryAgain:
	mov		edx, OFFSET errInstr
	call	WriteString			; display error message and prompt for new number
	jmp		compareVal	

; displayFibs
	continueProg:
	mov		userInt, eax
	mov		ecx, userInt	; move user input to ecx counter
	call	CrLf
		
	
	calculate:				; calculate fib sequence and display as they are calculated
	mov		eax, prevFib
	mov		ebx, fibSum
	add		eax, ebx
	mov		printMe, eax
	mov		eax, printMe
	call	WriteDec
	mov		al, 9			;add a tab 
	call	WriteChar
	call	WriteChar	
	mov		eax, printMe	;move temp holder back to eax
	inc		lineCnt			; incrememnts a variable to count the numbers
	;mov		edx, OFFSET spaces
	;call	WriteString
	mov		prevFib, ebx
	mov		fibSum, eax

	;compare lineCnt to see if it is divisible by 5
	mov		edx, 0
	mov		eax, lineCnt	
	mov		ebx, 5
	div		ebx
	cmp		edx, 0
	je		lineBreak
	loop	calculate		; loop to calculate as many as needed
	
	lineBreak:
	cmp		userInt, ecx
	je		keepGoing
	call	CrLf
	cmp		ecx, 0
	je		finish
	jg		keepGoing

	keepGoing:
	loop	calculate

; farewell
	finish:
	call	CrLf
	mov		edx, OFFSET farewell
	call	WriteString				; goodbye!
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf
	call	CrLf

	exit	; exit to operating system

main ENDP



END main
