#!/bin/bash

CFLAGS="-O2 -Wall --std=c++11"

Letras=( {A..Z} )
echo "Plataforma?"
echo "1- Codeforces"
echo "2- Atcoder"

echo ""
read plataforma
echo ""


if [[ $plataforma -eq 1 ]]; then
	cd /home/rodrigo/Documentos/Entrenamiento\ IOI\ 2020/Codeforces
		echo "Tipo de concurso:"
		echo "1 Div_1"
		echo "2 Div_2"
		echo "3 Div_3"
		echo "4 Educational"

		echo ""
		read input
		echo ""

		if [ ${input} -eq 1 ]
		then
			cd Div_1/
		elif [[ ${input} -eq 2 ]]
		then
			cd Div_2/
		elif [ ${input} -eq 3 ] 
		then
			cd Div_3/
		elif [ ${input} -eq 4]
		then
			cd Educational/
		else
			cd Otros/
		fi
else
	cd /home/rodrigo/Documentos/Entrenamiento\ IOI\ 2020/Atcoder

	echo "Tipo de concurso:"
	echo "1 Beginner"
	echo "2 Regular"
	echo "3 Grand"
	echo "4 Otros"

	echo ""
	read input
	echo ""

	if [ ${input} -eq 1 ]
	then
		cd Beginner/
	elif [[ ${input} -eq 2 ]]
	then
		cd Regular/
	elif [ ${input} -eq 3 ] 
	then
		cd Grand/
	else
		cd Otros/
	fi	
fi






echo "Nombre del concurso"

echo ""
read nombre
echo ""

mkdir ${nombre}
cd ${nombre}/

echo "Número de problemas?"

echo ""
read numero
echo ""

for (( i = 0; i < ${numero}; i++ )); do
	touch ${Letras[${i}]}.cpp
	touch ${Letras[${i}]}.in
done

for (( ; ; )); do
	echo "Escogé el problema"
	echo "-1 para terminar"
	
	echo ""
	read problema
	echo ""

	if [[ ${problema} -eq  -1 ]]; then
		break
	fi
	for (( ; ; )); do
		echo "1-Añadir casos de prueba"
		echo "2-Correr programa"
		echo "-1 - Cambiar de problema"
		echo "************************"
		
		echo ""
		read accion
		echo ""
		
		if [[ ${accion} -eq -1 ]]; then
			break
		fi

		if [[ ${accion} -eq 1 ]]; then
			
			readarray arreglo
			
			echo ${arreglo[*]} >> ${problema}.in
			echo "--------" >> ${problema}.in
		
		elif [[ ${accion} -eq 2 ]]; then
			
			g++ $CFLAGS -o $problema $problema.cpp
			
			if [[ $? -eq 0 ]]; then
				unset entrada
				while EFS= read -r linea; do
					
					if [[ "$linea" == *"-------"* ]]; then
						
						echo ${entrada[@]} > temp.in
						echo "############################"
						./${problema} < temp.in
						echo "############################"
						echo ""
						echo ""
						unset entrada
					else
						entrada=( ${entrada[*]} ${linea} )
					fi
					
				done < ${problema}.in
				echo ""
				rm temp.in
				rm ${problema}
			fi
		fi
	done

done

exit 0