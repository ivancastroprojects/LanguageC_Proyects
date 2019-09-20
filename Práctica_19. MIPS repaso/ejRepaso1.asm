# 3. Realice un programa que solicite al usuario una cadena de texto y que cambie las 
# letras 'a' por el carácter 'x'.


.data

cad1: .asciiz "Inserte una cadena de texto: \n"
cad2: .asciiz "\n Su cadena transformada es: \n"
cadleida: .space 1000
letraa: .byte 'a'
letrax: .byte 'x'

.text                 
.globl main

main:

	# Solicitamos al usuario que introduzca la cadena
	
	li $v0, 4 	# Código del sistema para imprimir una cadena (print_string)
	la $a0, cad1	# Cargamos en $a0 la cadena a imprimir
	syscall		# Realizamos la llamada al sistema para que se ejecute	
	
	li $v0, 8 		# Código del sistema para leer una cadena (read_string)
	la $a0, cadleida	# Indicamos dónde debe almacenar dicha cadena
	li $a1, 1000		# Indicamos la extensión máxima de dicha cadena
	syscall			# Realizamos la llamada al sistema para que se ejecute	
	
	
	la $a0, cadleida
	lb $a1, letraa
	lb $a2, letrax
	jal sustituye
	
	
fin:
	# Iprimimos la cadena modificada y finalizamos el programa
	
	li $v0, 4 	# Código del sistema para imprimir una cadena (print_string)
	la $a0, cadleida	# Cargamos en $a0 la cadena a imprimir
	syscall		# Realizamos la llamada al sistema para que se ejecute	
	
	li $v0,10	# Llamada al sistema para finalizar el programa
	syscall		# Realizamos la llamada al sistema para que se ejecute
	
	
	
sustituye:
	move $t0, $a1
	move $t1, $a2
	
	# Lo que debemos hacer es recorrer la cadena byte a byte y cuando encontremos
	# una 'a' guardar una 'x'
	
bucle:
	lb $t2, 0($a0)	# Cargamos el primer byte de la cadena
	beqz $t2, fin	# Si ese byte es $zero, entonces hemos terminado de leer la cadena
	beq $t2,$t0, cambialetra # Comparamos el carácter de la cadena con la letra 'a' si es igual vamos a "cambialetra"
	addi $a0,$a0,1	# Actualizamos la dirección de nuestra cadena para leer el siguiente carácter
	j bucle		# Volvemos a repetir el bucle
	
cambialetra:
	sb $t1, 0($a0)	# Guardamos el carácter 'x' en la posición del byte leído
	addi $a0,$a0,1	# Actualizamos la dirección de nuestra cadena para leer el siguiente carácter
	j bucle		# Volvemos a repetir el bucle
		
	
