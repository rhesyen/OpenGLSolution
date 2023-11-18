#include "header.h"


/**
* Obowi�zkowe powt�rzenie deklaracji p�l statycznych - w przypadku w�tpliwo�ci prosz� je wykomentowa� i sprawdzi�.
*/
GLuint ProgramMPGK::VAO;
GLuint ProgramMPGK::VBO;
GLuint ProgramMPGK::IBO;
GLuint ProgramMPGK::programZShaderami;
GLuint ProgramMPGK::vertexShaderId;
GLuint ProgramMPGK::fragmentShaderId;
GLint ProgramMPGK::zmiennaShader;

/**
* W konstruktorze ustawiamy parametry okna � odpowiednio wysoko��, szeroko�� oraz po�o�enie x i y.
*/
ProgramMPGK::ProgramMPGK(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

/**
* W konstruktorze ustawiamy parametry okna � odpowiednio wysoko��, szeroko�� oraz po�o�enie x i y.
* @param wysokoscOkna
* @param szerokoscOkna
* @param polozenieOknaX
* @param polozenieOknaY
 */
ProgramMPGK::ProgramMPGK(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

/**
* Destruktor
 */
ProgramMPGK::~ProgramMPGK()
{
}

/**
* Nie ma potrzeby zag��bia� si� w t� metod�.
 */
void ProgramMPGK::stworzenieOkna(int argc, char** argv)
{
	// Inicjalizacja biblioteki GLUT.
	glutInit(&argc, argv);
	// Ustawienie opcji GLUT. 
	// GLUT_DOUBLE � umo�liwia podw�jne buforowanie, czyli rysowanie do bufora w tle, kiedy inny jest wy�wietlany.
	// GLUT_RGBA to tryb kolor�w: Red, Green, Blue, Alpha. 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	// ustawienie kontekstu.
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Program");
}

/**
* Inicjalizacja GLEW i sprawdzenie, czy nie zako�czy�a si� b��dem.
 */
void ProgramMPGK::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		exit(1);
	}
}

/**
* Wprowadza dane do "ukrytego" bufora a nast�pnie zamienia go miejscami z aktualnie wy�wietlonym.
 */
void  ProgramMPGK::wyswietl()
{
	// Czy�ci bufory do wcze�niej ustawionych warto�ci.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Ca�y czas zwi�kszana jest zmienna, co tworzy iluzj� ruchu.
	static GLfloat zmiana = 0.0f;

	GLfloat kierunek = abs(sinf(zmiana));
	zmiana += 0.0005f;

	GLfloat mJ[4][4];

	mJ[0][0] = kierunek; mJ[0][1] = 0.0f;		mJ[0][2] = 0.0f;  mJ[0][3] = 0.0f;
	mJ[1][0] = 0.0f;	 mJ[1][1] = kierunek;	mJ[1][2] = 0.0f;  mJ[1][3] = 0.0f;
	mJ[2][0] = 0.0f;	 mJ[2][1] = 0.0f;		mJ[2][2] = 1.0f;  mJ[2][3] = 0.0f;
	mJ[3][0] = 0.0f;	 mJ[3][1] = 0.0f;		mJ[3][2] = 0.0f;  mJ[3][3] = 1.0f;

	// �aduje dane do zmiennej typu uniform w "shaderze"
	glUniformMatrix4fv(macierzShader, 1, GL_TRUE, &mJ[0][0]);

	// Umo�liwia przekazanie danych z bufora z g��wnego programu do atrybutu z "shadera".Dzieje si� to dzi�ki indeksowi podanemu tu jak i w samym "shaderze."
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// okre�la lokalizacj� i format danych tablicy atrybut�w (informuje potok (pipeline) jak interpretowa� dane z bufora).
	// Pierwszy parametr to indeks, drugi to liczba komponent�w (3 dla X Y Z), trzeci to typ komponent�w, czwarty okre�la 
	// czy dane powinny by� znormalizowane (GL_TRUE), czy przekazane w niezmienionym stanie (GL_FALSE). 
	// Dwa ostatnie parametry glVertexAttribPointer() to odst�p pomi�dzy atrybutami(0 � w przypadku "ciasno upakowanej" tablicy 
	// np.same wierzcho�ki bez kolor�w) i offset, czyli w kt�rym momencie zacz�� pobiera� dane.
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (GLvoid*)(sizeof(GLfloat) * 4));

	// Wybieramy buffor, z kt�rego b�d� pobierane dane.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// Pierwszy parametr to typ prymitywu(np.GL_POINTS, GL_LINE_STRIP, GL_TRIANGLES), drugi to informacja od kt�rego indeksu
	// w tablicy ma si� rozpocz�� rysowanie, trzeci to  typ indeks�w a ostatni to liczba element�w.
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// Blokowanie atrybutu, kt�ry nie jest ju� u�ywany.
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	// Zamiana buffor�w miejscami.
	glutSwapBuffers();
}

/**
* Metoda odpowiedzialna za sprz�tanie.
 */
void ProgramMPGK::usun()
{
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	glDeleteProgram(programZShaderami);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
	glDeleteVertexArrays(1, &VAO);
}

/**
* VAO przechowuje format danych wierzcho�k�w oraz bufory.
 */
void ProgramMPGK::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

/**
* Tworzy bufor (na wierzcho�ki) i wype�nia go danymi.
 */
void ProgramMPGK::stworzenieVBO()
{
	GLfloat wierzcholki[] = {
		-0.4f, -0.4f, 0.0f, 1.0f, // wierzcho�ek
		 1.0f,  0.0f, 0.0f, 1.0f, // kolor
		 0.4f, -0.4f, 0.4f, 1.0f, // wierzcho�ek
		 0.0f,  1.0f, 0.0f, 1.0f, // kolor
		-0.4f,  0.4f, 0.0f, 1.0f, // wierzcho�ek
		 0.0f,  0.0f, 1.0f, 1.0f, // kolor
		 0.4f,  0.4f, 0.0f, 1.0f, // wierzcho�ek
		 0.5f,  0.5f, 0.0f, 1.0f  // kolor
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wierzcholki), wierzcholki, GL_STATIC_DRAW);
}

/**
* Stworzenie bufora na indeksy.
 */
void ProgramMPGK::stworzenieIBO()
{
	// Indeksy odpowiadaj� wierzcho�kom z VBO, dzi�ki czemu mo�na si� odwo�a� wielokrotnie do tego samego wierzcho�ka.
	GLuint indeksyTab[] = {
		0, 1, 2, 1, 2, 3,
	};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeksyTab), indeksyTab, GL_STATIC_DRAW);
}

/**
* Tworzy program (programZShaderami), w kt�rym b�dziemy ��czy� wszystkie "shadery". Weryfikujemy, czy zosta� utworzony.
* W przypadku b��du funkcja glCreateProgram() zwraca 0.
 */
void ProgramMPGK::stworzenieProgramu()
{
	programZShaderami = glCreateProgram();

	if (programZShaderami == 0)
	{
		std::cerr << "Blad podczas tworzenia programu shaderow." << std::endl;
		//system("pause");
		exit(1);
	}

	const GLchar* vertexShader =
		"	#version 330\n																			\
			layout (location = 0) in vec3 polozenie;												\
			layout (location = 1) in vec4 kolorPrzychodzacyVS;										\
			uniform mat4 macierz;																	\
			out vec4 kolorWychodzacyVS;																\
			void main()																				\
			{																						\
				 gl_Position = macierz * vec4(polozenie, 1.0);										\
				 kolorWychodzacyVS = kolorPrzychodzacyVS;											\
			}";


	const GLchar* fragmentShader =
		"	#version 330\n									\
			in vec4 kolorWychodzacyVS;						\
			out vec4 kolorWychodzacyFS;						\
			void main()										\
			{												\
				kolorWychodzacyFS = kolorWychodzacyVS;	    \
			}";

	// Wywo�anie metody: dodanieDoProgramu(). W niej s� kompilowane "shadery" i dodawane do programu.
	vertexShaderId = dodanieDoProgramu(programZShaderami, vertexShader, GL_VERTEX_SHADER);
	fragmentShaderId = dodanieDoProgramu(programZShaderami, fragmentShader, GL_FRAGMENT_SHADER);

	GLint linkowanieOK = 0;
	glLinkProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_LINK_STATUS, &linkowanieOK);
	if (linkowanieOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas linkowania programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	GLint walidacjaOK = 0;
	glValidateProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_VALIDATE_STATUS, &walidacjaOK);
	if (walidacjaOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas walidacji programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	// Okre�la u�ywany aktualnie program (programZShaderami). B�dzie on wykonywany podczas ka�dego rysowania do momentu
	// zast�pienia lub wy��czenia (glUseProgram(NULL))
	glUseProgram(programZShaderami);


	// Odpytuje program z "shadrami" o zmienn� uniform przy pomocy nazwy.Je�li ta ostatnia nie zostanie znaleziona to funkcja 
	// glGetUniformLocation() zwr�ci - 1.
	macierzShader = glGetUniformLocation(programZShaderami, "macierz");
	if (macierzShader == -1)
	{
		std::cerr << "Nie znaleziono zmiennej uniform." << std::endl;
		system("pause");
		exit(1);
	}
}

/**
* Metoda dodanieDoProgramu() jako parametry przyjmuje
* @param programZShaderami (GLuint) - program, w kt�ry zostan� po��czone "shadery",
* @param tekstShadera (const GLchar *) - tekst danego shadera i
* @param typShadera (GLenum) - jego typ.
* @return zwraca jeden z "shader�w" zbudowany w oparciu o przekazane parametry.
 */
GLuint ProgramMPGK::dodanieDoProgramu(GLuint programZShaderami, const GLchar* tekstShadera, GLenum typShadera)
{
	GLuint shader = glCreateShader(typShadera);

	// 35633 -> vertex shader, 35632 -> fragment shader
	const GLchar* typShaderaTekst = typShadera == 35633 ? "vertex" : "fragment";

	if (shader == 0) {
		std::cerr << "Blad podczas tworzenia " << typShaderaTekst << " shadera." << std::endl;
		//system("pause");
		exit(0);
	}

	const GLchar* tekstShaderaTab[1];
	tekstShaderaTab[0] = tekstShadera;
	GLint dlugoscShadera[1];
	dlugoscShadera[0] = strlen(tekstShadera);
	// Przed kompilacj� musi zosta� podany tekst danego "shadera". Funkcja glShaderSource() przyjmuje jako parametry uchwyt do 
	// obiektu (shader), w kt�rym tekst ma by� zast�piony. Drugi to liczba element�w w tablicach, kt�re s� podane jako kolejne 
	// parametry. Pierwsza z nich zawiera wska�niki na �a�cuchy znak�w a druga tablic� liczb ca�kowitych, kt�re podaj� d�ugo��
	// �a�cuch�w odpowiadaj�cych im elementom z pierwszej tablicy. 
	glShaderSource(shader, 1, tekstShaderaTab, dlugoscShadera);

	glCompileShader(shader);
	GLint kompilacjaOK = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &kompilacjaOK);
	if (kompilacjaOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetShaderInfoLog(shader, dlugoscLoga, NULL, &log[0]);
		std::cerr << std::endl;
		std::cerr << "Blad podczas kompilacji " << typShaderaTekst << " shadera." << std::endl;
		std::cerr << std::endl;
		std::cerr << "log: ";
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteShader(shader);
		//system("pause");
		exit(1);
	}

	glAttachShader(programZShaderami, shader);
	return shader;
}

void ProgramMPGK::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


int main(int argc, char** argv)
{
	ProgramMPGK obiektMPGK(786, 786, 100, 100);

	obiektMPGK.stworzenieOkna(argc, argv);
	obiektMPGK.inicjalizacjaGlew();
	obiektMPGK.sprawdzenieWersji();
	obiektMPGK.stworzenieVAO();
	obiektMPGK.stworzenieVBO();
	obiektMPGK.stworzenieIBO();
	obiektMPGK.stworzenieProgramu();
	glutDisplayFunc(obiektMPGK.wyswietl);
	glutIdleFunc(obiektMPGK.wyswietl);
	glutCloseFunc(obiektMPGK.usun);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

	//system("pause");
	return 0;
}