# Crear un programa que pida una cadena de texto y un número. Después debe llamar
# a una subrutina a la que se le enviarán la cadena de texto y el número como parámetros.
# Dicha subrutina devolverá un 0 si el número insertado es inferior o igual al número
# de caracteres de la cadena insertada y devolverá un 1 en caso contrario. Para realizar 
# este cálculo deberá llamar, dentro de la subrutina a otra subrutina que se encargará de
# contar los caracteres que posee la cadena y devolverá el número de caracteres.
#

.data

cadPideCad: 	.asciiz "\nIntroduzca una cadena de caracteres: "
cadPideNum: 	.asciiz "\nIntroduzca un número entero: "
cadMenos:	.asciiz "\nEl número insertado es inferior o igual al número de caracteres que posee la cadena"
cadMas:		.asciiz "\nEl número insertado es superior al número de caracteres que posee la cadena"
cadNueva:	.space 1000

.text
.globl main

main:	

	li $v0, 4		# Código del sistema para imprimir cadena (print_string)
	la $a0, cadPideCad	# En $a0 enviamos la cadena
	syscall			# Llamamos al sistema

	li $v0, 8		# Código del sistema para leer cadena (read_string)
	la $a0, cadNueva	# En $a0 enviamos la dirección donde almacenamos la cadena
	li $a1, 1000		# Indicamos en $a1 el valor de espacio reservado en memoria para esa cadena
	syscall			# Llamamos al sistema
	
	li $v0, 4		# Código del sistema para imprimir cadena (print_string)
	la $a0, cadPideNum	# En $a0 enviamos la cadena
	syscall			# Llamamos al sistema
	
	li $v0, 5		# Código del sistema para leer número (read_int)
	syscall			# Llamamos al sistema
	
	move $a1, $v0		# Guardamos en $a1 el número para enviarlo a la subrutina
	la $a0, cadNueva	# Cargamos en $a0 la cadena insertada para enviarla a la subrutina
	
	jal subrutina_principal
	
	beqz $v0, son_menos	# Si devuelve 0, el usuario insertó un número inferior o igual	
				# al número de caracteres de la cadena insertada
				
	li $v0, 4		# Código del sistema para imprimir cadena (print_string)
	la $a0, cadMas		# En $a0 enviamos la cadena
	syscall			# Llamamos al sistema 
	
	j fin
	
son_menos:

	li $v0, 4		# Código del sistema para imprimir cadena (print_string)
	la $a0, cadMenos	# En $a0 enviamos la cadena
	syscall			# Llamamos al sistema 
	
fin:	li $v0, 10
	syscall




	# Función principal
subrutina_principal:	
	addi $sp,$sp, -4	# Como vamos a llamar a otra función, almacenamos
	sw $ra, ($sp)		# el registro $ra en la pila

	jal cuenta_caracteres	# Llamamos a la función que cuenta los caracteres

	lw $ra, ($sp)		# Desapilamos $ra
	addi $sp, $sp, 4

	move $t1, $v0
	
	
	
	bgt $a1, $t1, mas_caracteres	# Si el número que insertó el usuario ($a1) es mayor que los caracteres devueltos
					# por la subrutina que cuenta los caracteres, lo enviamos a "mas_caracteres"
					
	
	li $v0, 0			# En otro caso, el número será igual o inferior a los caracteres de la cadena
					# Así que enviaremos 0 en $v0
	j finsub_ppal
	
mas_caracteres:
	li $v0, 1	
	
finsub_ppal:
	jr $ra
	
cuenta_caracteres:
	li $v0, 0		# Contador de caracteres
bucle:
	lb $t1, ($a0)		# Cargamos el primer carácter en $t1
	beqz $t1, fincuenta	# Si $t1 es igual a 0, hemos terminado de leer la cadena
	addi $a0, $a0, 1	# Actualizamos el puntero al siguiente carácter
	addi $v0, $v0, 1	# Actualizamos el contador de caracteres
	j bucle			# 

fincuenta:	
	# Devolvemos en $v0 el número de caracteres
	jr $ra
