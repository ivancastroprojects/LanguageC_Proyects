#Ejercicio 2: Realizar un programa que pida un número por teclado y cuente el número de ceros qu
# tiene cuando se representa en binario.

.data
cad:	.asciiz "Introduzca un número: "
cad2: .asciiz "\nEl número de unos es: "
.globl main
.text
main:
	li $v0, 4	#Llamada al sistema para imprimir la cadena
	la $a0, cad	#indicada por el puntero $a0
	syscall

	li $v0, 5	#Llamada al sistema para leer un número
	syscall
	move $t0, $v0	#Guardamos el número leído en $t0

	li $t1, 32	#N�mero de veces que tenemos que desplazar el número
	li $t2, 0	#Inicializamos el contador de unos

sigue:
	beq $t1, $zero, fin	# Si hemos desplazado 31 posiciones, hemos recorrido todo el nº
	andi $t3, $t0, 1	# Sacamos el bit de menos peso
	addi $t1, $t1, -1	# Descontamos uno al contador de posiciones
	srl $t0, $t0, 1		# Desplazamos el número una posicón a la derecha

	beq $t3, 1, sigue   # Si es 1, no contamos
	addi $t2, $t2, 1 	# Si es 0, le sumamos uno al contador
	j sigue			# y seguimos mirando

fin:	li $v0, 4	#Llamada al sistema para imprimir la cadena
	la $a0, cad2    #indicada por el puntero $a0
	syscall

	li $v0, 1	#Llamada al sistema para imprimir el resultado
	move $a0, $t2	#Pasamos a $a0 el número de unos
	syscall

	li $v0, 10	#Llamada al sistema para salir del programa
	syscall
