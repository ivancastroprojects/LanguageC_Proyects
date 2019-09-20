
	.data
cad1:	.asciiz	"\nIntroduzca 6 numeros enteros: "
cad2:	.asciiz "\nIntroduzca otro número: "
cadr3:	.asciiz "\nLos resultados de las operaciones son:\n"
cadr4:	.asciiz "\nLa suma total es: "
cadr5:	.asciiz "\nLa resta total es: "
cadr6:	.asciiz	"\nLa multiplicacion es : "

	.text
	.globl main

main:
	
	li $v0, 4
	la $a0, cad1
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0	#primero
	
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 5
	syscall
	move $a1, $v0	#segundo
	
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 5
	syscall
	move $a2, $v0	#tercero
	
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 5
	syscall
	move $a3, $v0	#cuarto
	
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 5
	syscall
	addi $sp, $sp, -4
	sw $v0, ($sp)	#quinto
	
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 5
	syscall
	addi $sp, $sp, -4
	sw $v0, ($sp)	#sexto
	
	move $a0, $t0
	
	
	jal calcula
	
	move $t0, $v0
	move $t1, $v1
	lw $t2, ($sp)
	addi $sp, $sp, 4
	
	
	li $v0, 4
	la $a0, cadr3
	syscall
	
	li $v0, 4
	la $a0, cadr4
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, cadr5
	syscall
	
	move $a0, $t2
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, cadr6
	syscall
	
	move $a0, $t1
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
	
calcula:
	li $v0, 0	#almacen suma
	li $v1, 0	#almacen multiplicacion
	li $t0, 0	#almacen resta
	
	lw $t2, ($sp)
	addi $sp, $sp, 4
	
	lw $t1, ($sp)
	addi $sp, $sp, 4
	
	add $v0, $a0, $a1	#suma
	add $v0, $v0, $a2
	add $v0, $v0, $a3
	add $v0, $v0, $t2
	add $v0, $v0, $t1
	
	mul $v1, $a0, $a1	#multiplicacion
	mul $v1, $v1, $a2
	mul $v1, $v1, $a3
	mul $v1, $v1, $t2
	mul $v1, $v1, $t1
	
	sub $t0, $a2, $t1	#resta
	
	addi $sp, $sp, -4
	sw $t0, ($sp)
	
	jr $ra
	

	
	
	
	
	