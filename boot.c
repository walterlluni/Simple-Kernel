void kmain(void)
{
	const char *str = "Bienvenido al sistema operativo: BlackForest OS";
	char *vidptr = (char*)0xb8000; /*la memoria e video inicia aqui*/
	unsigned int i=0;
	unsigned int j=0;

	/*Este bucle limpia la pantalla */
	while(j < 80 * 25 * 2){
		/*caracter en blanco*/
		vidptr[j]=' ';
		/*Atributo Byte - color gris claro en las letras*/
		vidptr[j+1] = 0x07;
		j = j + 2;
	}

	j = 0;

	/*este bucle escribe la cadena en la memoria de video*/
	while (str[j] != '\0') {
		/*Caracteres Ascii*/
		vidptr[i]= str[j];
		/*Atributo Byte - color gris claro en las letras*/
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}
