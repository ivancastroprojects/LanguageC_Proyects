#Ejercicio
#Escriba un programa que, utilizando los modos de direccionamiento realice las siguientes operaciones
#  sin modificar el segmento de datos:
#
#     �	Calcular la suma del primer word colocado a partir de la etiqueta datos1 y del half que
#          tiene valor 3 y colocar este resultado en el espacio de 2 bytes resaltado en negrita.
#          Imprimir y comprobar el valor.
#     �	Utilizando la etiqueta datos2, almacenar el car�cter ASCII �e� en el byte resaltado en
#          negrita e inicializado a 4. Imprimir y comprobar el valor.
     .data
datos1: .half 4,7,2
        .align 2
        .word 1, -5
        .byte 4
        .align 1
        .half 3
        .align 2
        .word -3
        .space 2
        .byte 'c'
datos2: .byte 2,3,5
     .globl main
     .text
main:
  la $t0, datos1	# Creo un puntero que apunta a datos1 (al word que vale -4)
  lw $t1, 8($t0) # Cargo el word que vale 1 en $t1.
  lh $t2, 18($t0) # Cargo el half que vale 3 en $t2
  add $t2, $t1, $t2  #Sumo ambos valores
  sh $t2, 24($t0)  # Guardo el resultado en el space

  lh $a0, 24($t0)  # Leo el contenido del space para comprobar si es correcto
  li $v0, 1  # Llamada al sistema para imprimir el contenido de $a0
  syscall

  la $t0, datos2 # Creo un puntero que apunta a datos1 (al byte que vale 2)
  lb $t1, -1($t0) # Cargo el byte que vale 'b' en el registro $t0
  addi $t1, $t1, 2 # Le sumo 2 a la ‘c’ para obtener la letra ‘e’
  sb $t1, -11($t0) # Almaceno la letra 'd' en el byte que vale 4

  la $a0, datos2 # Creo un puntero a la cadena (a la letra ‘e’)
  addi $a0, $a0, -11
  li $v0, 4	# Llamada al sistema para imprimir la cadena
  syscall

   li $v0, 10 #Fin del main
   syscall
