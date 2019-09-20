		.data
cad:		.asciiz "Introduce un numero: "
cadResult:	.asciiz "La suma de n numeros es: "
		.globl main
		.text

main:
	li $v0, 4
	la $a0, cad
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $t1, 0	#contador
	li $t2, 0	#acumulador de resultado
	
bucle:
	beq $t1, $t0, fin	#si el contador ya es igual que el numero acabamos
	addi $t1, $t1, 1	#sino avanzamos a la proxima posicion
	add $t2, $t2, $t1	#y sumamos el resultado de la suma, mas el siguiente numero
	j bucle
	
fin:
	li $v0, 4
	la $a0, cadResult
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 10
	syscall