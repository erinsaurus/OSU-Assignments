TITLE Sorting Random Integers (CS271_Prog5.asm)

; Author: Erin Alltop
; Email: alltope@oregonstate.edu
; Course / Project ID: CS271-400 / Program 5                
; Due Date: 5-28-17
; Description: This program generates random numbers in the range [100 ... 999], displays the unsorted list
; of numbers, and then sorts the list in descending order (i.e. largest first), calculates and displays the median
; value, rounded to the nearest integer, and displayed the sorted list, 10 numbers per line.
; ***NOTE: The sortList procedure algorithm was adapted from the Kip R. Irvine textbook  - Bubble Sort
; method on page 375, section 9.5***

INCLUDE Irvine32.inc

; (insert constant definitions here)

MAX = 200;	
MIN = 10;
LO = 100;
HI = 999;

.data

progName	BYTE	"Sorting Random Integers", 0
progAuth	BYTE	"Programmed by Erin Alltop", 0
instr1		BYTE	"This program generates random numbers in range [100 .. 999], displays the original list, sorts the list, ", 0
instr2		BYTE	"and caluculates and displays the median value. Lastly, it displays the sorted list in descending order. ", 0
instr3		BYTE	"Pick a number within the [10 .. 200] range to be generated. ", 0
instr4		BYTE	"Enter how many numbers should be generated: ", 0
oops1		BYTE	"Out of range. Pick a number within the [10 .. 200] range. ", 0
goodbye 	BYTE	"That's all for now! Goodbye. ", 0
request		DWORD	?
intArray	DWORD	MAX DUP(?)		
unsorted	BYTE	"Unsorted List of Random Numbers: ", 0
sorted		BYTE	"Sorted List of Random Numbers: ", 0
spaces		BYTE	"    ", 0
median		BYTE	"The median is: ", 0
medianNum	DWORD	?
evenTest	DWORD	?
secMedian	DWORD	?


; (insert variable definitions here)

.code
main PROC

; Introduction and instructions
	push	OFFSET progName
	push	OFFSET progAuth
	push	OFFSET instr1
	push	OFFSET instr2
	push	OFFSET instr3
	call	introduction

; Get the user data and validate
	push	OFFSET instr4
	call	getUserData

; Randomize numbers and fill the array
	push	OFFSET intArray
	push	request
	call	fillArray

; Display the unsorted array to the user
	push	OFFSET intArray
	push	request
	push	OFFSET unsorted
	call	displayList

; Sort the array in descending order
	mov		ecx, request
	dec		ecx
	push	OFFSET intArray
	call	sortList

; Calculate and display the median to the user
	push	request
	push	OFFSET intArray
	push	OFFSET median
	call	displayMedian

; Display the sorted array to the user in descending order
	push	OFFSET intArray
	push	request
	push	OFFSET sorted
	call	displayList

; All done. Say goodbye!
	push	OFFSET goodbye
	call	farewell


	exit	; exit to operating system
main ENDP


;**************************************************************
; Procedure to introduce program to user
; receives: none
; returns: none
; preconditions: none
; registers changed: edx
;**************************************************************

introduction PROC
	push	ebp						;setup the stack frame
	mov		ebp, esp
	mov		edx, [ebp+24]
	call	WriteString				; display program name
	call	CrLf

	mov		edx, [ebp+20]
	call	WriteString				; display author name
	call	CrLf
	call	CrLf

	mov		edx, [ebp+16]
	call	WriteString				; program description1
	call	CrLf

	mov		edx, [ebp+12]
	call	WriteString				; program description2
	call	CrLf
	call	CrLf

	mov		edx, [ebp+8]
	call	WriteString				; instruction1
	call	CrLf
	call	CrLf

	pop		ebp
	ret		16
introduction ENDP 

;**************************************************************
; Procedure to get data from the user
; receives: request (reference)
; returns:  user input is in request variable
; preconditions: none
; registers changed: edx
; *************************************************************

getUserData PROC
	push	ebp						; setup the stack frame
	mov		ebp, esp

	mov		edx, [ebp+8]
	call	WriteString

	call	ReadInt					; obtaining user input
	call	validate				; call validate procedure
	mov		request, eax
	pop		ebp
	ret		8
	
; *********************************************************************
; Procedure to validate user input
; receives: none
; returns: none
; preconditions: user has inputed data
; registers changed: eax, edx
; *********************************************************************

validate PROC	
L1:	cmp		eax, MIN				; compare upper limit, jump to OOPS label if less than
	jl		OOPS
	cmp		eax, MAX				; compare lower limit, jump to OOPS label if greater than
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

;**************************************************************
; fill array {parameters: request (value), array (reference)}
; Procedure to fill the array
; receives: request (value), array (reference)
; returns:  array is filled with random numbers
; preconditions: array created, request/user input is initialized
; HI and LO global variables are set
; registers changed: edx, ecx, eax, edi
; *************************************************************

fillArray PROC
	push	ebp				; setup stack frame
	mov		ebp, esp	
	mov		esi, [ebp+12]	; move array to point to esi
	mov		ecx, [ebp+8]	; move user variable to ecx for counter
	call	Randomize		; Irvine Randomize seed

KeepGoing:
	mov		eax, HI			; range = HI - LO + 1
	sub		eax, LO
	inc		eax
	call	RandomRange		; Irvine RandomRange procedure
	add		eax, LO			; Add LO to eax

	mov		[esi], eax		; move random number to array location
	add		esi, 4			; move to next array location (DWORD = 4 BYTES)
	loop	KeepGoing		

	pop		ebp
	ret		8
fillArray ENDP

;**************************************************************
; Procedure to sort the array
; receives: array(reference), request(value)
; returns: sorted array
; preconditions: array is initialized and filled, user input 
; is valid and initialized
; registers changed: ecx, esi, ebp, eax
; ***This algorithm was adapted from the Irvine textbook Bubble Sort
; method on page 375, section 9.5**
; *************************************************************

sortList PROC
	push	ebp				;setup stack frame
	mov		ebp, esp	

OuterLoop:					;setup the outer loop with ecx
	push	ecx
	mov		esi, [ebp+8]	; move the array (reference) pointer to esi

InnerLoop:
	mov		eax, [esi]		; move first value of array to eax register
	cmp		[esi+4], eax	; compare first value to second (esi+4 is second value because DWORD = 4 bytes)
	jl		noSwap			; if less than, then no swap is necessary, jump to noSwap label
	xchg	eax, [esi+4]	; if not less than, swap the two numbers
	mov		[esi], eax		; move value in eax register to first location

noSwap:
	add		esi, 4			; if no swap is necessary, add 4 to esi register (to move to next element)
	loop	InnerLoop		; continue inner loop

	pop		ecx				; retore ecx loop count for outer loop
	loop	OuterLoop

	pop		ebp
	ret
sortList ENDP


;**************************************************************
; Procedure to display the median of the random numbers
; receives: array(reference), request (value)
; returns: median of the array is displayed
; preconditions: array is initialized and filled, request is 
; initialized
; registers changed:
; *************************************************************

displayMedian PROC
	push	ebp				;setup stack frame
	mov		ebp, esp
	call	CrLf

; Divide to find middle number
	mov		eax, [ebp+16]		; divide request by 2 to find middle number
	cdq
	mov		ebx, 2
	div		ebx					; eax = divisor of division statement / edx = remainder
	mov		evenTest, edx		; store remainder in variable
	mov		medianNum, eax		; store divisor

; Multiply result by 4 to find element location in array
	mov		eax, medianNum
	mov		ebx, 4
	mul		ebx					; eax = divisor * 4 (multiplying by 4 to find location of element in array)
	mov		medianNum, eax		; store result in variable

; Display title and median to screen
	mov		esi, [ebp+12]		; move array to point to esi
	add		esi, medianNum		; find location of element in array
	mov		edx, [ebp+8]
	call	WriteString			; display title for median number
	mov		eax, [esi]
	call	writeDec			; print median number
	call	CrLf 

	pop		ebp
	ret		4
displayMedian ENDP


;**************************************************************
; Procedure to display the Arrray
; receives: array (reference), request (value), title (reference)
; returns: 
; preconditions: array is filled, user input intialized
; registers changed: esi, ecx, edx, ebx
; *************************************************************

displayList PROC
	push	ebp					;setup the stack frame
	mov		ebp, esp
	mov		esi, [ebp+16]		; move @intArray to esi
	mov		ecx, [ebp+12]		; move user input to ecx for loop
	mov		edx, [ebp+8]		; move title to edx
	mov		ebx, 0				; 0 out ebx
	call	CrLf	
	call	WriteString			; display title 
	call	CrLf

KeepGoing:
	inc		ebx					
	mov		eax, [esi]			; move current element to eax and write to screen
	call	WriteDec		
	add		esi, 4				; increment to esi to next element in the array
	cmp		ebx, 10				; if ebx = 10, jump to add a line and reset ebx to 0, else jump to add spaces
	je		AddLine
	jne		AddSpaces

AddLine:
	call	CrLf
	mov		ebx, 0
	jmp		MoveOn

AddSpaces:
	mov		edx, OFFSET spaces
	call	WriteString

MoveOn:
	loop	KeepGoing
	call	CrLf

	pop		ebp
	ret		12
displayList ENDP

;**************************************************************
; Procedure to say goodbye to the user
; receives: goodbye message
; returns: none
; preconditions: none 
; registers changed: edx
; *************************************************************

farewell PROC
	push	ebp						;setup the stack frame
	mov		ebp, esp
	mov		edx, [ebp+8]
	call	CrLf
	call	WriteString				; say goodbye - see ya!
	call	CrLf
	call	CrLf
	pop		ebp
	ret		4

farewell ENDP

END main
