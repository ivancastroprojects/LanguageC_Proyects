	.data
cad1:	.asciiz "Introduzca una cadena: "
cad2:	.asciiz "La cadena resultante es: "
cadleida: .space 100
cadcopiada: .space 100
	.globl main
	.text
	
main:
	li $v0, 4
	la $a0, cad1
	syscall
	
	li $v0, 8
	la $a0, cadleida
	li $a1, 100
	syscall
	
	la $a0, cadleida
	la $a1, cadcopiada
	
	jal copia
	
	li $v0, 4
	la $a0, cad2
	syscall
	
	li $v0, 4
	la $a0, cadcopiada
	syscall
	
	li $v0, 10
	syscall
	
copia:
	lb $t0, ($a0)
	sb $t0, ($a1)
	beqz $t0, fin
	addi $a0, $a0, 1
	addi $a1, $a1, 1
	j copia
	
fin:
	jr $ra