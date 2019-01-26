TITLE Designing low-level I/O procedures     (CS271_Prog6.asm)

; Author: Erin Alltop
; Email: alltope@oregonstate.edu
; Course / Project ID: CS271-400 / Program 6                
; Due Date: 6-12-17
; Description: This program uses macros and procedures to get 10 valid unsigned integers from the user as a
; string, converts the string to numeric values, validates user input, stores the values into an array,
; and then displays the integers, their sum, and their average.

INCLUDE Irvine32.inc

displayString	MACRO	printMe                                  
	push	edx                                                         
    mov     edx, OFFSET printMe
    call    WriteString
    pop     edx                                                         
ENDM

getString	MACRO	var, string         
    push    ecx
    push    edx
    displayString string                    
    mov     edx,OFFSET var                
    mov     ecx,(SIZEOF var) - 1                                        
    call    ReadString
    pop     edx
    pop     ecx
ENDM

.data

MAX_INPUT =	10
CHAR_SUB = 48 ; Number to subtract in number conversion

progName	 BYTE	"Designing low-level I/O procedures", 0
progAuth	 BYTE	"Programmed by Erin Alltop", 0
instr1		 BYTE	"Please provide 10 unsigned decimal integers. ", 0
instr2		 BYTE	"Each number needs to be small enough to fit inside a 32 bit register. ", 0
instr3		 BYTE	"Afterwards, I will display a list of the integers, their sum, and their average value. ", 0
getNum		 BYTE	"Please enter an unsigned integer: ", 0
goodbye 	 BYTE	"That's all for now! Goodbye. ", 0
oopsMsg		 BYTE	"ERROR invalid entry. Please enter an unsigned integer only: ", 0
intSum       BYTE   "The sum of these numbers is: ", 0
intAve       BYTE   "The average is: ", 0
spaceBtwn    BYTE   ", ", 0
listTitle    BYTE   "You entered the following numbers: ", 0
intArray     DWORD  10 DUP(?)
buffer		 BYTE   20 DUP(?)
count        DWORD  0
arraySum     DWORD  0
tempNum		 DWORD  0
tempRes		 DWORD	?

.code

main PROC

; Introduction and instructions
	push	OFFSET progName
	push	OFFSET progAuth
	push	OFFSET instr1
	push	OFFSET instr2
	push	OFFSET instr3
	call	introduction

    mov     ecx, MAX_INPUT           ; MAX_INPUT placed into ecx counter

; Use readVal to get 10 numbers from the user
GETDATA:							 
	push	OFFSET intArray          
    push	count                  
    call	readVal                  
    inc		count               
    loop	GETDATA					; loop 10 times to get 10 user inputted integers
         
; Use writeVal to print the array
    push	OFFSET listTitle
	push	OFFSET intArray                  
    push	MAX_INPUT                     
    call	writeVal 

; Calculate the sum and average of the array
    push	OFFSET intArray                      
    push	MAX_INPUT                          
    push	arraySum
    call	calculations                  

; All done. Say goodbye!
	push	OFFSET goodbye
	call	farewell

	exit
main ENDP


;**************************************************************
; Procedure to introduce program to user
; receives: prog name, author, and instructions for user
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

	mov		edx, [ebp+8]
	call	WriteString				; instruction1
	call	CrLf
	call	CrLf

	pop		ebp
	ret		16
introduction ENDP 

;**************************************************************					
; readVal procedure invokes the getString macro to get the user's
; string of digits, then converts the digit string to numeric,
; while validating the user's input.
; receives: none
; returns: array filled with validated user input
; preconditions: none
; registers changed: esi, ecx, al, edx, ebx
; *************************************************************
readVal PROC
	pushad
    mov		ebp, esp				; setup the stack frame
	mov		tempNum, 0

	getString buffer, getNum		; get an input from the user
    jmp		VALIDATE	

TRYAGAIN:                           
	getString buffer, oopsMsg

VALIDATE:							; validate user input
    mov		ecx, eax				; length of number goes into ecx counter
    mov		esi, OFFSET buffer

VAL_LOOP:                           ; loop one at a time
	lodsb
	cmp		ecx, MAX_INPUT			; lodsb sets ecx to number of digits, if this is greater than 10, it's larger than an unsigned int
	jg		TRYAGAIN
    cmp		al,48                    ; check to see if input is not a number - 0 = 48 in ASCII
    jl      TRYAGAIN                        

    cmp    al,57                    ; 9 = 57 in ASCII
    jg     TRYAGAIN    
	
; Convert string to integer
	mov		tempRes, eax
	mov		ebx, tempNum
	mov		eax, 10	
	mul		ebx					; Multiply tempNum by 10
	mov		tempNum, eax
	mov		eax, tempRes
	sub		eax, 48
	add		tempNum, eax		; tempNum contains number converted to int at end of loop
		                
    loop   VAL_LOOP
    jmp    KEEPGOING				

KEEPGOING:
    mov    edx, [ebp+40]             ; @intArray
    mov    ebx, [ebp+36]             ; current count
    imul   ebx, 4                    ; DWORD = 4 byte, so multiply by 4 to find correct location
	mov	   eax, tempNum
    mov    [edx+ebx], eax            ; insert value into array

    popad
    ret    8
readVal ENDP

;**************************************************************
; writeVal procedure to convert a numeric value to a string of 
; digits and invoke the displayString macro to produce the output
; receives: intArray and MAX_INPUT
; returns: none
; preconditions: Array is full of user input 
; registers changed: edi, ecx
; *************************************************************
writeVal PROC
	call	CrLf
	push    ebp					; setup the stack frame
    mov     ebp, esp
	mov		edx, [ebp+16]		; listTitle
    mov     edi, [ebp+12]		; @intArray
    mov     ecx, [ebp+8]		; MAX_INPUT

	displayString listTitle
	call	CrLf

BEGIN:
    mov     eax, [edi]			; point first element to eax
    call    WriteDec			; print the number
    cmp     ecx, 1              ; if ecx is equal to 1, we are on the last element and should skip the comma
    je      SKIPCOMMA                       
	displayString spaceBtwn		; add a comma 
	add     edi, 4				; point to next element of the array

SKIPCOMMA:
    loop    BEGIN				; one last loop

    pop    ebp
    ret    8
writeVal ENDP


;**************************************************************
; calculations procedure to find sum and average of array
; receives: array, MAX_INPUT for counter, variable for sum of array
; returns: sum and average of array
; preconditions: array is filled with validated user input
; registers changed: eax, ebx, edi
; *************************************************************

calculations PROC
	push	ebp
    mov     ebp, esp			; setup the stack frame
    mov     edi, [ebp+16]		; @intArray
    mov     ecx, [ebp+12]		; MAX_INPUT to counter
    mov     ebx, [ebp+8]		; arraySum variable

; Calculate the sum of the numbers
BEGIN:
    mov     eax, [edi]          ;move the number into eax
    add     ebx, eax            ;add eax to the sum
    add     edi, 4              ;move on to the next one
    loop    BEGIN

	call	CrLf
    displayString intSum	; display sum title
    mov     eax, ebx		; arraySum is in eax
    call    WriteDec
    call    CrLf
    
; Calculate the average of the numbers
	mov		ebx, [ebp+12]	; move MAX_INPUT to ebx
	mov		edx, 0
	idiv	ebx

	displayString intAve	; display average title

    call    WriteDec
    pop     ebp
    ret     12
calculations ENDP


;**************************************************************
; Procedure to say goodbye to the user
; receives: goodbye message
; returns: none
; preconditions: none 
; registers changed: edx
; *************************************************************

farewell PROC
	call	CrLf
	push	ebp						; setup the stack frame
	mov		ebp, esp
	mov		edx, [ebp+8]			; goodbye message
	call	CrLf
	call	WriteString				; say goodbye - see ya!
	call	CrLf
	call	CrLf
	pop		ebp
	ret		4
farewell ENDP

END main