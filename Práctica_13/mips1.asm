	.data

cad:		.asciiz "Introduce una cadena\n"
cadleida:	.space 100 #reservo sitio
letra:		.byte 'a'
cadresult:	.asciiz "El numero de letras 'a' es "

	.globl main

	.text

main:
	li  $v0, 4
	la $a0, cad
	syscall
	
	li $v0, 8
	la $a0, cadleida
	li $a1, 100
	syscall
	
	li $t0, 0
	la $t1, cadleida
	
	lb $t3, letra

bucle:
	lb $t2, ($t1)		#leo una letra de la cadena
	beq $t2, $zero, fin	#si es igual a cero acabe me voy a fin
	addi $t1, $t1, 1	#sino paso a la siguiente posicion
	bne $t2, $t3, bucle	#si no es la letra a vuelve a empezar sin contar 
	addi $t0, $t0, 1	#si si es la letra a, contador++
	j bucle

fin:
	li $v0, 4
	la $a0, cadresult
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
	
	
	