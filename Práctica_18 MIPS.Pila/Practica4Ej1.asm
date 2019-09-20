# 1.Realizar un programa que solicite al usuario 6 números enteros, y utilizando los registros 
# $a0, $a1, $a2, $a3 y la pila, llame a una subrutina que devuelva la suma, la resta y el producto
# de todos ellos. Nota: Recordar que la subrutina devuelve $v0 y $v1, con lo cual, para el 3er 
# resultado habrá que utilizar la pila.
	.data
cadIntro1: .asciiz "A continuación vamos a solicitarle 6 números enteros\nIntroduzca el primer número entero: "
cadIntro2: .asciiz "\nIntroduzca otro número entero: "
cadResul1: .asciiz "\nLos resultados de las operaciones son los siguientes:\n"
cadResul2: .asciiz "\nLa suma total es: "
cadResul3: .asciiz "\nLa resta es: "
cadResul4: .asciiz "\nEl producto es: "

	.text
	.globl main
main:
	# Solicitamos el primer número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro1	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5	# Llamada al sistema para leer un número
	syscall		# Realizamos la llamada al sistema para que se ejecute
	move $t0, $v0   # Movemos el número leído a $t0 para no perderlo y enviarlo como argumento
	
	# Solicitamos el segundo número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5	# Llamada al sistema para leer un número
	syscall		# Realizamos la llamada al sistema para que se ejecute
	move $a1, $v0   # Movemos el número leído a $a1 para no perderlo y enviarlo como argumento
	
	# Solicitamos el tercer número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5	# Llamada al sistema para leer un número
	syscall		# Realizamos la llamada al sistema para que se ejecute
	move $a2, $v0   # Movemos el número leído a $a1 para no perderlo y enviarlo como argumento
	
	# Solicitamos el cuarto número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5	# Llamada al sistema para leer un número
	syscall		# Realizamos la llamada al sistema para que se ejecute
	move $a3, $v0   # Movemos el número leído a $a1 para no perderlo y enviarlo como argumento
	
	# Solicitamos el quinto número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5		# Llamada al sistema para leer un número
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	addi $sp, $sp, -4	# Guardamos el 5 número en la pila
	sw $v0, ($sp)	
	
	# Solicitamos el sexto número
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadIntro2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 5	# Llamada al sistema para leer un número
	syscall		# Realizamos la llamada al sistema para que se ejecute

	addi $sp, $sp, -4	# Guardamos el 6 número en la pila
	sw $v0, ($sp)		
	
	move $a0, $t0		# Antes de llamar a la subrutina, guardamos
				# el primer número insertado en $a0
				
	jal calcula_todo	# Llamamos a la subrutina calcula_todo
	
	move $t0, $v0		# Guardamos el 1 resultado en $t0
	move $t1, $v1		# Guardamos el 2 resultado en $t1
	
	lw $t2, ($sp)		# Desapilamos el 3 resultado en $t2
	addi $sp, $sp, 4	# Actualizamos la pila
	
	# Imprimimos los resultados
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadResul1	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadResul2	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	move $a0, $t0		# Movemos a $a0 el resultado de la suma
	li $v0, 1		# Código del sistema para imprimir un entero
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadResul3	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	move $a0, $t1		# Movemos a $a0 el resultado de la resta
	li $v0, 1		# Código del sistema para imprimir un entero
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 4 		# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadResul4	# Cargamos en $a0 la cadena a imprimir
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	move $a0, $t2		# Movemos a $a0 el resultado del producto
	li $v0, 1		# Código del sistema para imprimir un entero
	syscall			# Realizamos la llamada al sistema para que se ejecute
	
	li $v0, 10	#Llamada al sistema para salir del programa
	syscall
	
	
calcula_todo:
	
	li $v0, 0		# En $v0 almacenaremos la suma
	li $v1, 0		# En $v1 almacenaremos la resta
	li $t0, 0		# En $t0 almacenaremos el producto
	
	lw $t2, ($sp)		# Desapilamos el último número insertado, 
	addi $sp,$sp, 4		# recordando que es el número 6
	
	lw $t1, ($sp)		# Desapilamos el último número insertado, 
	addi $sp,$sp, 4		# recordando que es el número 5
				# la pila está vacía de nuevo.
				
	# Procedemos a realizar la suma
	add $v0, $a0, $a1	# Sumamos el primer número y el segundo
	add $v0, $v0, $a2	# Sumamos el tercero número insertado
	add $v0, $v0, $a3	# Sumamos el cuarto número insertado
	add $v0, $v0, $t1	# Sumamos el quinto número insertado
	add $v0, $v0, $t2	# Sumamos el sexto número insertado
	
	
	# Procedemos a realizar la resta
	sub $v1, $a0, $a1	# Restamos el primer número y el segundo
	sub $v1, $v1, $a2	# Restamos el tercero número insertado
	sub $v1, $v1, $a3	# Restamos el cuarto número insertado
	sub $v1, $v1, $t1	# Restamos el quinto número insertado
	sub $v1, $v1, $t2	# Restamos el sexto número insertado
	
	# Procedemos a realizar la multiplicación
	mul $t0, $a2, $t1	# Multiplicamos el primer número y el segundo
	
	
	# En $v0 tenemos la suma, en $v1 la resta y en $t0 el producto
	# Como solo devuelve $v0 y $v1, apilamos el resultado de $t0
	
	addi $sp, $sp, -4	# Preparamos la pila dejando espacio para un word
	sw $t0, ($sp)		# Apilamos el producto
	
	jr $ra 			# Finalizamos la subrutina