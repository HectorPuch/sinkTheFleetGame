#include <iostream> // Input/Output
#include <string> // std::string
#include <ctime> // Randomizado
#include <cstdlib> // Para la pausa y limpieza de pantalla

int main() {

	srand(time(NULL));
	const int FILAS = 10, COLUMNAS = 10;

	// Tamaños de los barcos (6, 5, 3, 3)
	const int TAMANO_PORTAVIONES = 6, TAMANO_ACORAZADO = 5, TAMANO_BUQUE = 4, TAMANO_SUBMARINO = 3;
	const int TAMANOS_BARCOS[4] = { TAMANO_PORTAVIONES, TAMANO_ACORAZADO, TAMANO_BUQUE, TAMANO_SUBMARINO };
	const int CASILLAS_TOTALES = 18;

	// Tableros de juego
	char tableroJugador1[FILAS][COLUMNAS], tableroJugador2[FILAS][COLUMNAS];

	// Variables de control de juego
	int barcosHundidos1 = 0; // Aciertos del jugador 1 sobre el jugador 2
	int barcosHundidos2 = 0; // Aciertos del jugador 2 sobre el jugador 1
	int turnoActual = 1; // Comienza el jugador 1
	bool juegoTerminado = false;

	// Variables de coordenadas
	int filaInicio, columnaInicio, orientacion;
	int filaAtaque, columnaAtaque;

	// Colocación del símbolo ~ en cada una de las casillas
	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			tableroJugador1[i][j] = '~';
			tableroJugador2[i][j] = '~';
		}
	}

	// Impresión del tablero del Jugador 1
	std::cout << "Tablero Jugador 1\n";
	for (int k = 0; k < FILAS; k++)
	{
		for (int l = 0; l < COLUMNAS; l++)
		{
			std::cout << tableroJugador1[k][l] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Impresión del tablero del Jugador 2
	std::cout << "Tablero Jugador 2\n";
	for (int m = 0; m < FILAS; m++)
	{
		for (int n = 0; n < COLUMNAS; n++)
		{
			std::cout << tableroJugador2[m][n] << " ";
		}
		std::cout << std::endl;
	}

	// Bucle externo para colocar todos los barcos en el tablero del Jugador 1
	for (int indiceBarco = 0; indiceBarco < 4; indiceBarco++)
	{
		int TAMANO_ACTUAL = TAMANOS_BARCOS[indiceBarco];
		bool posicionValida;

		do
		{
			filaInicio = rand() % FILAS;
			columnaInicio = rand() % COLUMNAS;
			orientacion = rand() % 2;

			posicionValida = false;

			// Validación de los límites y solapamiento en el tablero del Jugador 1
			if (orientacion == 0) // Si la orientación es horizontal (validación columna)
			{
				if (columnaInicio + TAMANO_ACTUAL - 1 < COLUMNAS)
				{
					bool noSolapamiento = true;
					for (int i = 0; i < TAMANO_ACTUAL; i++)
					{
						if (tableroJugador1[filaInicio][columnaInicio + i] != '~')
						{
							noSolapamiento = false;
							break;
						}
					}
					if (noSolapamiento)
					{
						posicionValida = true;
					}
				}
			}
			else // Si la orientación es vertical (validación fila)
			{
				if (filaInicio + TAMANO_ACTUAL - 1 < FILAS)
				{
					bool noSolapamiento = true;
					for (int i = 0; i < TAMANO_ACTUAL; i++)
					{
						if (tableroJugador1[filaInicio + i][columnaInicio] != '~')
						{
							noSolapamiento = false;
							break;
						}
					}
					if (noSolapamiento)
					{
						posicionValida = true;
					}
				}
			}
		} while (!posicionValida);

		// Colocación del barco en el tablero del Jugador 1
		for (int i = 0; i < TAMANO_ACTUAL; i++)
		{
			if (orientacion == 0)
			{
				tableroJugador1[filaInicio][columnaInicio + i] = TAMANO_ACTUAL + '0'; // Horizontal
			}
			else
			{
				tableroJugador1[filaInicio + i][columnaInicio] = TAMANO_ACTUAL + '0'; // Vertical
			}
		}
	}

	// Bucle externo para colocar todos los barcos en el tablero del Jugador 2
	for (int indiceBarco = 0; indiceBarco < 4; indiceBarco++)
	{
		int TAMANO_ACTUAL = TAMANOS_BARCOS[indiceBarco];
		bool posicionValida;

		do
		{
			filaInicio = rand() % FILAS;
			columnaInicio = rand() % COLUMNAS;
			orientacion = rand() % 2;

			posicionValida = false;

			// Validación de los límites y solapamiento en el tablero del Jugador 2
			if (orientacion == 0) // Si la orientación es horizontal (validación columna)
			{
				if (columnaInicio + TAMANO_ACTUAL - 1 < COLUMNAS)
				{
					bool noSolapamiento = true;
					for (int i = 0; i < TAMANO_ACTUAL; i++)
					{
						if (tableroJugador2[filaInicio][columnaInicio + i] != '~')
						{
							noSolapamiento = false;
							break;
						}
					}
					if (noSolapamiento)
					{
						posicionValida = true;
					}
				}
			}
			else // Si la orientación es vertical (validación fila)
			{
				if (filaInicio + TAMANO_ACTUAL - 1  < FILAS)
				{
					bool noSolapamiento = true;
					for (int i = 0; i < TAMANO_ACTUAL; i++)
					{
						if (tableroJugador2[filaInicio + i][columnaInicio] != '~')
						{
							noSolapamiento = false;
							break;
						}
					}
					if (noSolapamiento)
					{
						posicionValida = true;
					}
				}
			}
		} while (!posicionValida);

		// Colocación del barco en el tablero del Jugador 2
		for (int i = 0; i < TAMANO_ACTUAL; i++)
		{
			if (orientacion == 0)
			{
				tableroJugador2[filaInicio][columnaInicio + i] = TAMANO_ACTUAL + '0'; // Horizontal
			}
			else
			{
				tableroJugador2[filaInicio + i][columnaInicio] = TAMANO_ACTUAL + '0'; // Vertical
			}
		}
	}

	std::cout << std::endl;

	// Impresión inicial del tablero del Jugador 1 con los barcos posicionados
	std::cout << "Tablero Jugador 1\n";
	for (int k = 0; k < FILAS; k++)
	{
		for (int l = 0; l < COLUMNAS; l++)
		{
			std::cout << tableroJugador1[k][l] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	// Impresión inicial del tablero del Jugador 2 con los barcos posicionados
	std::cout << "Tablero Jugador 2\n";
	for (int m = 0; m < FILAS; m++)
	{
		for (int n = 0; n < COLUMNAS; n++)
		{
			std::cout << tableroJugador2[m][n] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Bucle principal del juego
	while (!juegoTerminado)
	{
		// Impresión del tablero del Jugador 1 con los barcos ocultos
		std::cout << "Tablero Jugador 1\n";
		for (int k = 0; k < FILAS; k++)
		{
			for (int l = 0; l < COLUMNAS; l++)
			{
				char casilla = tableroJugador1[k][l];

				if (casilla >= '3' && casilla <= '6')
				{
					std::cout << "~ ";
				}
				else
				{
					std::cout << casilla << " ";
				}
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		// Impresión del tablero del Jugador 2 con los barcos ocultos
		std::cout << "Tablero Jugador 2\n";
		for (int m = 0; m < FILAS; m++)
		{
			for (int n = 0; n < COLUMNAS; n++)
			{
				char casilla = tableroJugador2[m][n];

				if (casilla >= '3' && casilla <= '6')
				{
					std::cout << "~ ";
				}
				else
				{
					std::cout << casilla << " ";
				}
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		// Gestión del turno
		if (turnoActual == 1) // Turno del Jugador 1
		{
			std::cout << "--- Turno del Jugador 1 ---\n";

			// Entrada de coordenadas (Jugador 1 ataca a Jugador 2)
			do
			{
				std::cout << "Introduce Fila a atacar (1-10): ";
				std::cin >> filaAtaque;
				std::cout << "Introduce Columna a atacar (1-10): ";
				std::cin >> columnaAtaque;

				int fila = filaAtaque - 1;
				int columna = columnaAtaque - 1;

				// La casilla no debe haber sido atacada antes
				if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS)
				{
					if (tableroJugador2[fila][columna] != 'X' && tableroJugador2[fila][columna] != 'O')
					{
						break;
					}
					else
					{
						std::cout << std::endl;
						std::cout << "Casilla ya atacada. Intenta de nuevo.\n";
						std::cout << std::endl;
					}
				}
				else
				{
					std::cout << std::endl;
					std::cout << "Coordenadas fuera de rango. Deben ser de 1 a 10.\n";
					std::cout << std::endl;
				}

			} while (true);

			// Resolución del ataque Jugador 1
			int fila = filaAtaque - 1;
			int columna = columnaAtaque - 1;

			if (tableroJugador2[fila][columna] >= '3' && tableroJugador2[fila][columna] <= '6')
			{
				std::cout << std::endl;
				std::cout << "IMPACTO!\n";
				tableroJugador2[fila][columna] = 'O'; // Marcamos el acierto en el tablero del Jugador 2
				barcosHundidos1++; // Sumamos el acierto al Jugador 1
			}
			else if (tableroJugador2[fila][columna] == '~')
			{
				std::cout << std::endl;
				std::cout << "AGUA!\n";
				tableroJugador2[fila][columna] = 'X'; // Marcamos el fallo en el tablero del Jugador 2
			}

			std::cout << std::endl;
			std::cout << "Aciertos Jugador 1: " << barcosHundidos1 << " / " << CASILLAS_TOTALES << std::endl;
			std::cout << "Aciertos Jugador 2: " << barcosHundidos2 << " / " << CASILLAS_TOTALES << std::endl;

			// Revisión de la condición de victoria del Jugador 1
			if (barcosHundidos1 == CASILLAS_TOTALES)
			{
				juegoTerminado = true;
				std::cout << std::endl;
				std::cout << "El Jugador 1 ha ganado el juego!\n";
			}

			// Cambio de turno
			if (!juegoTerminado)
			{
				turnoActual = 2; // El próximo turno es el Jugador 2
			}
		}
		else // Turno del Jugador 2
		{
			std::cout << "--- Turno del Jugador 2 ---\n";

			// Entrada de coordenadas (Jugador 2 ataca a Jugador 1)
			do
			{
				std::cout << "Introduce Fila a atacar (1-10): ";
				std::cin >> filaAtaque;
				std::cout << "Introduce Columna a atacar (1-10): ";
				std::cin >> columnaAtaque;

				int fila = filaAtaque - 1;
				int columna = columnaAtaque - 1;

				// La casilla no debe haber sido atacada antes
				if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS)
				{
					if (tableroJugador1[fila][columna] != 'X' && tableroJugador1[fila][columna] != 'O')
					{
						break;
					}
					else
					{
						std::cout << std::endl;
						std::cout << "Casilla ya atacada. Intenta de nuevo.\n";
						std::cout << std::endl;
					}
				}
				else
				{
					std::cout << std::endl;
					std::cout << "Coordenadas fuera de rango. Deben ser de 1 a 10.\n";
					std::cout << std::endl;
				}

			} while (true);

			// Resolución del ataque Jugador 2
			int fila = filaAtaque - 1;
			int columna = columnaAtaque - 1;

			if (tableroJugador1[fila][columna] >= '3' && tableroJugador1[fila][columna] <= '6')
			{
				std::cout << std::endl;
				std::cout << "IMPACTO!\n";
				tableroJugador1[fila][columna] = 'O'; // Marcamos el acierto en el tablero del Jugador 1
				barcosHundidos2++; // Sumamos el acierto al Jugador 2
			}
			else if (tableroJugador1[fila][columna] == '~')
			{
				std::cout << std::endl;
				std::cout << "AGUA!\n";
				tableroJugador1[fila][columna] = 'X'; // Marcamos el fallo en el tablero del Jugador 1
			}

			std::cout << std::endl;
			std::cout << "Aciertos Jugador 1: " << barcosHundidos1 << " / " << CASILLAS_TOTALES << std::endl;
			std::cout << "Aciertos Jugador 2: " << barcosHundidos2 << " / " << CASILLAS_TOTALES << std::endl;

			// Revisión de la condición de victoria del Jugador 2
			if (barcosHundidos2 == CASILLAS_TOTALES)
			{
				juegoTerminado = true;
				std::cout << std::endl;
				std::cout << "El Jugador 2 ha ganado el juego!\n";
			}

			if (!juegoTerminado)
			{
				turnoActual = 1; // El próximo es el Jugador 1
			}
		}

		std::cout << std::endl;

		if (!juegoTerminado)
		{
			std::cout << "Presiona ENTER para continuar el turno del Jugador " << turnoActual << "...";
			std::cin.ignore();
			std::cin.get();
			std::cout << std::endl;
		}
	}

	return 0;
}