.data           # comienzo del segmento de datos

cad:      .asciiz "Introduce una cadena"
cadleida: .space 100  # Reservo sitio para 100 letras
letra:    .byte 'a'
cadresult: .asciiz "El número de letras es "
        .globl main   # declaración de la etiqueta main como global

        .text         # comienzo del segmento de texto

main:
        li $v0, 4   # llamada al sistema para imprimir cadena cad
        la $a0, cad
        syscall

        li $v0, 8         # llamada al sistema para leer cadena y 
        la $a0, cadleida  # almacenarla en cadleida
        li $a1, 100       # de como máximo 100 caracteres 
        syscall

        li $t0, 0     # Inicializo mi contador de la longitud
        la $t1, cadleida   # Creo un puntero a la cadena leída (a la 1ª letra)
        lb $t3, letra      # Guardo la letra 'a' en $t3
  bucle: 
        lb $t2, ($t1)   # Leo una letra de la cadena (el contenido del puntero)
        beq $t2, $zero, fin   #Compruebo si es el carácter \0 (he acabado)
        addi $t1, $t1, 1      #Muevo el puntero a la dir. Siguiente (sgte. Letra)
        bne $t2, $t3, bucle   #Si no es la 'a', no cuento
        addi $t0, $t0, 1      #contador++;
        j bucle               #sigo recorriendo la cadena

  fin:  
        li $v0, 4
        la $a0, cadresult     # Imprimo la cadena cadresult
        syscall

        li $v0, 1
        move $a0, $t0         # Imprimo el resultado (el contador, es decir $t0)
        syscall

        li $v0, 10            # Fin del main
        syscall
