# 2.	Escriba un programa que solicite al usuario una cadena de texto y que posteriormente la copie en otra cadena 
#   impriendo el resultado por pantalla. Se le debe pasar a la subrutina ìstrcpyî dos argumentos: un puntero a la cadena 
#  original y un puntero a la cadena destino. NOTA: Recordad que las cadenas terminan con el car·cter ë\0í que tiene el valor $zero.
.data

cadpide: .asciiz "Introduzca una cadena: "

cadresultado: .asciiz "La cadena copiada es: "

cadleida: .space 100

cadcopiada: .space 100



.globl main

.text

main:

	li $v0, 4		#Llamada al sistema para imprimir una cadena
	la $a0, cadpide
	syscall



	li $v0, 8		#Llamada al sistema para leer una cadena
	la $a0, cadleida
	li $a1, 100
	syscall



	la $a0, cadleida	#Argumento 1: puntero a la cadena le?da
	la $a1, cadcopiada	#Argumento 2: puntero a la cadena resultado
	

	jal strcpy	#Llamada a la funci??n

	li $v0, 4	#Llamada al sistema para imprimir una cadena
	la $a0, cadresultado
	syscall


	li $v0, 4	#Llamada al sistema para imprimir el resultado
	la $a0, cadcopiada
	syscall

	li $v0, 10
	syscall		#Fin del main


strcpy:

        #El puntero est√° en $a0


bucle:	

	lb $t0, ($a0)  #Leemos un car√°cter
	sb $t0, ($a1)  #Lo guardamos en la cadena resultado
	beqz $t0, fin #Si llegamos al fin de cadena, salimos
	addi $a0, $a0, 1 #Actualizamos los punteros de ambas cadenas
	addi $a1, $a1, 1
	j bucle



fin:	
	jr $ra	

