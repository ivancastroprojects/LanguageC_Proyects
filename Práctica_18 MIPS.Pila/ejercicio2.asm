	.data
cad1:	.asciiz "\nIntroduzca un número positivo: "
cadError: .asciiz "\nError. El número debe ser positivo."
cad3:	.asciiz "\nEl número de divisores es PAR."
cad4:	.asciiz "\nEl número de divisores es IMPAR."
	.globl main
	.text
	
main:
	li $v0, 4
	la $a0, cad1
	syscall
	
	li $v0, 5
	syscall
	move $a0, $v0
	
	bltz $a0, negativo	#si el numero es negativo se acabó
	bgtz $a0, divisores	#si el numero es positivo calculamos divisores
	
	li $v0, 10
	syscall
	
	
	
negativo:
	li $v0, 4
	la $a0, cadError
	syscall
	
	
divisores:
	li $t1, 0	#contador divisores
	li $t2, 1	#numero comprobado
	
bucle:
	bgt $t2, $a0, comprueba
	div $a0, $t2
	mfhi $t3
	addi $t2, $t2, 1
	bne $t3, $zero, bucle
	addi $t1, $t1, 1
	j bucle
	
comprueba:
	move $v0, $t1
	beq $v0, $zero, espar
	bne $v0, $zero, esimpar
	
espar:
	li $v0, 4
	la $a0, cad3
	syscall

esimpar:
	li $v0, 4
	la $a0, cad4
	syscall
