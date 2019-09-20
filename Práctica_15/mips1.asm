	.data
cad:	.asciiz "Introduzca un numero: "
cadResult: .asciiz "El factorial es: "
	.globl main
	.text
	
main:
	li $v0, 4
	la $a0, cad
	syscall
	
	li $v0, 5
	syscall
	move $a0, $v0
	
	jal suma
	
	move $a0, $v0
	
	li $v0, 4
	la $a0, cadResult
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
	
suma:
	li $v0, 1	#almacen
	li $t0, 1	#contador
	
bucle:
	bgt $t0, $a0, fin
	mul $v0, $v0, $t0
	addi $t0, $t0, 1
	j bucle
	
fin:
	jr $ra