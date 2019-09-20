# 4. Teniendo el siguiente segmento de datos:

# datos1: .byte 14, 23
#             .align 2
#             .word 47
#             .align 1
#             .half 9, 12, 15
#             .align 2
# datos2: .space 4
#             .byte 'c','o'

# a) Sumar el word con valor 47, con el half de valor 15 y guardarlo en el .space 4 como dato word, utilizando la etiqueta datos1.
# b) Guardar el carácter 'd' y el carácter 'p' en la posición del half con valor 12, utilizando la etiqueta datos2.

# Pista: 'd' es el carácter siguiente a la letra 'c' y 'p' es el carácter siguiente a la letra 'p'.

.data

datos1:      .byte 14, 23
             .align 2
             .word 47
             .align 1
             .half 9, 12, 15
             .align 2
datos2:      .space 4
             .byte 'c','o'
             
             
.text                 
.globl main

main:

	# Sumar el word 47 con el half 15 y guardarlo en .space 4 como word usando datos1
	
	la $t0, datos1	# Cargamos en $t0 la dirección datos1
	lw $t1, 4($t0)	# Cargamos en $t1 el word 47, posición 4
	lh $t2, 12($t0) # Cargamos en $t2 el half 15, posición 12
	add $t3,$t1,$t2 # Sumamos ambos números
	sw $t3, 16($t0) # Lo guardamos en el .space 4, posición 16
	
	# Guardar 'd' y 'p' en el half de valor 12 usando datos2
	
	la $t0, datos2	# Cargamos en $t0 la dirección datos2
	lb $t1, 4($t0) 	# Cargamos el carácter 'c' en $t1
	lb $t2, 5($t0)	# Cargamos el carácter 'o' en $t2
	addi $t1,$t1,1	# Convertimos la 'c' en 'd' sumando 1 a su valor ASCII
	addi $t2,$t2,1 	# Convertimos la 'o' en 'p' sumando 1 a su valor ASCII
	sb $t1,-6($t0)	# Guardamos la 'd' en el primer byte del half 12
	sb $t2,-5($t0)	# Guardamos la 'p' en el segundo byte del half 12

fin:	li $v0,10	# Llamada al sistema para finalizar el programa
	syscall		# Realizamos la llamada al sistema para que se ejecute
