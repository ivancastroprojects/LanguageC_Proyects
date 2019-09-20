# 1. 1.	Realice un programa que solicite al usuario un número entero ‘n’ y que calcule el factorial de 
# dicho número, haciendo uso de una subrutina llamada “factorial”. El argumento que se debe pasar es el 
# número indicado por el usuario.
.data

cadpide: .asciiz "Introduzca un nÃºmero positivo: "
cadresultado: .asciiz "El factorial es: "

.globl main

.text

main:

	li $v0, 4		#Llamada al sistema para imprimir una cadena
	la $a0, cadpide
	syscall



	li $v0, 5		#Llamada al sistema para leer una cadena
	syscall
	move $a0, $v0 	# Movemos el valor introducido por el usuario a $a0 
			# Recordando que $a0 es el argumento 1

	jal suma	#Llamada a la funci??n

	move $t0, $v0	#Guardamos el resultado en $t0

	li $v0, 4	#Llamada al sistema para imprimir una cadena
	la $a0, cadresultado
	syscall


	li $v0, 1	#Llamada al sistema para imprimir el resultado
	move $a0, $t0
	syscall

	li $v0, 10
	syscall		#Fin del main


suma:

        #El puntero estÃ¡ en $a0

	li $v0, 1	#Inicializamos $v0 donde guardamos el resultado 1
	li $t0, 1 	#Inicializamos el contador que irÃ¡ de 1 hasta n

bucle:	
	bgt $t0,$a0,fin
	mul $v0,$v0,$t0
	addi $t0,$t0,1
	j bucle



fin:	#El resultado estÃ¡ en $v0

	jr $ra	

