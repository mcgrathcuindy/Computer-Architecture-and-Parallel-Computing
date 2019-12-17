/*
Christopher McGrath
CSCI 230 project 1 Task 2
10/20/19
*/
.data


array_source:
	.byte 0x01
	.byte 0x02
	.byte 0x03
	.byte 0x04
	.byte 0x05
	.byte 0x06
	.byte 0x07
	.byte 0x08
	.byte 0x09
	.byte 0x0A
	.byte 0x0B
	.byte 0x0C

array_next_source:
	.byte 0x01
	.byte 0x02
	.byte 0x03
	.byte 0x04
	.byte 0x05
        .byte 0x06
        .byte 0x07
        .byte 0x08
        .byte 0x09
        .byte 0x0A
        .byte 0x0B
        .byte 0x0C

array_destination:
	.byte 0x01
        .byte 0x02
        .byte 0x03
        .byte 0x04
        .byte 0x05
        .byte 0x06
        .byte 0x07
        .byte 0x08
        .byte 0x09
        .byte 0x0A
        .byte 0x0B
        .byte 0x0C

.text
.global _start

_start:

ldr r0, adr_array1
ldr r1, adr_array3
ldr r2, adr_array2
ldmia r0, {r3-r5}
ldmia r1, {r6-r8}
ldmia r2, {r9-r11}

UADD8 r9, r3, r6
UADD8 r10, r4, r7
UADD8 r11, r5, r8

SWI 0

adr_array1: .word array_source
adr_array2: .word array_destination
adr_array3: .word array_next_source


