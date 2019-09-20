# 6. Realice un programa que solicite al usuario un número y compruebe si es un palíndromo. Tras calcular el 
# palíndromo, el programa preguntará al usuario si desea seguir introduciendo más números para comprobar, 
# si inserta un '1' volverá a solicitar al usuario insertar un número, si inserta un '0' saldrá del programa. 
# NOTA: los palíndromos son números que se leen igual de izquierda a derecha que de derecha a izquierda, 
# por ejemplo "10001" es un palíndromo.


.data


cad1: .asciiz "\nIntroduzca un número para comprobar si es un palíndromo: \n"
cad2: .asciiz " es un palíndromo.\n"
cad3: .asciiz " no es un palíndromo.\n"
cad4: .asciiz "¿Desea continuar? 1 sí, 0 no: "
salto: .asciiz "\n"
# num = $t0
# reverse = $t1
# temp = $t2

.align 2

.globl main
.text

main:

comienzo:
    li $t0, 0       # inicializo el contador que suma a 0
    li $t1, 0       # inicializo el contador de inverso a 0
    li $t2, 0       # initializo el temporal a 0
    li $t4, 10      # $t4 = 10

    li $v0, 4             # Código del sistema para imprimir una cadena (print_string)
    la $a0, cad1          # Cargamos en $a0 la cadena a imprimir
    syscall		  # Realizamos la llamada al sistema para que se ejecute

    li $v0, 5             # Llamada al sistema para leer un número
    syscall               # Realizamos la llamada al sistema para que se ejecute
    move $t0, $v0         # Movemos el número leído a $t0 para no perderlo
    move $t2, $t0         # Guardamos también en $t2 el mismo número


bucle:
    beqz $t2, fin         # si $t2 vale 0 finaliza el programa
    mult $t1, $t4         # guardamos inverso*10 in LO
    mflo $t1              # movemos reverse*10 desde mflo a $t1
    div $t2, $t4          # temp%10 en mfhi, temp/10 en mflo
    mfhi $t2              # temp = temp%10
    add $t1, $t1, $t2     # reverse = reverse + temp%10
    mflo $t2              # temp = temp/10
    j bucle               # repetimos

fin:   
    move $a0, $t0	  # igualamos $a0 al número
    li $v0, 1             # Imprimimos el entero
    syscall               # Ejecutamos la llamada al sistema
    
    li $v0, 4             # Código del sistema para imprimir una cadena (print_string)
    bne $t0, $t1, si      # si num != reverse, vamos a la etiqueta "si"
    la $a0, cad2          # sino cargamos la cadena 2
    syscall               # ejecutamos la llamada al sistema
    j sino                # si num == reverse, se salta el "si" y va al "sino"

si:
    la $a0, cad3          # Cargamos en $a0 la cadena a imprimir
    syscall               # Realizamos la llamada al sistema para que se ejecute

sino:
    la $a0, cad4          # Cargamos en $a0 la cadena a imprimir
    syscall               # Realizamos la llamada al sistema para que se ejecute
    li $v0, 5             # Llamada al sistema para leer un número entero
    syscall               # Realizamos la llamada al sistema para que se ejecute

    bnez $v0, comienzo    # si no es 0, volvemos al inicio

	li $v0,10	# Llamada al sistema para finalizar el programa
	syscall		# Realizamos la llamada al sistema para que se ejecute