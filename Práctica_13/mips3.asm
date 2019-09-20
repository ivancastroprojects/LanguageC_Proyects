     .data
datos1: .half 4,7,2
        .align 2
        .word 1, -5
        .byte 4
        .align 1
        .half 3
        .align 2
        .word -3
        .space 2
        .byte 'c'
datos2: .byte 2,3,5

	.globl main
	.text

main:
	la $t0, datos1
	lw $t1, 8($t0)
	lh $t2, 18($t0)
	add $t2, $t1, $t2
	sh $t2, 24($t0)
	
	lh $a0, 24($t0)
	li $v0, 1
	syscall
	
	
	la $t0, datos2
	lb $t1, -1($t0)
	addi $t1, $t1, 2
	sb $t1, -11($t0)
	
	la $a0, datos2
	addi $a0, $a0, -11
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
	#|	4	|		|	7	|		|
	#|	2	|		|		|		|
	#|	1	|		|		|		|
	#|      -5	|		|		|		|
	#|	4	|		|	3	|		|
	#|      -3	|		|		|		|
	#|		|		|	'c'	|	2	|
	#|	3	|	5	|		|		|