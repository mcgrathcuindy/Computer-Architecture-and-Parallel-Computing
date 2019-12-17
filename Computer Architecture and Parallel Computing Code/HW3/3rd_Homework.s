/*
Christopher McGrath
Assembly ARM code to store 1,2,3,4 in contiguous memory
10/8/19
*/
.data
var1: .word 1

.text
.global _start

_start:
	ldr r0, adr_var1
	ldr r1, [r0]
	str r1, [r0, #4]
	mov r7, #1 

	add r7, r7, r1
	str r7, [r0, #8]

	add r7, r7, r1
	str r7, [r0, #12]

	add r7, r7, r1
	str r7, [r0, #16]
SWI 0

adr_var1: .word var1
