# <img src="https://raw.githubusercontent.com/SamHerbert/SVG-Loaders/5deed925369e57e9c58ba576ce303466984db501/svg-loaders/bars.svg" width = 20px> PLATONIC_SOLID_SDL2_X_CPP
Visualizacion "Platonic Solid Models OBJ"  creado en lenguaje C++, usando la libreria SDL2

# <img src="https://raw.githubusercontent.com/SamHerbert/SVG-Loaders/5deed925369e57e9c58ba576ce303466984db501/svg-loaders/bars.svg" width = 15px> Requisitos

- Como primer punto sera necesario que verifiques tener la version C++14, si no sabes como, no te preocupes, puedes consultar el siguiente enlace para conocerlo: https://www.delftstack.com/es/howto/cpp/check-cpp-version/
  (Cualquier otra version de C++, no funcionara, Una disculpa de antemano ). Mas adelante se actualizara el programa para ser ejecutado en versiones mas actuales.
- De tener C++14, verifica tener "make" en la linea de comando de tu terminal de preferencia (No confundir con "cmake"), de no estar seguro, ejecuta el comando "make",
  si muestra el siguiente mensaje podemos continuar:
  
                     *** No se especificó ningún objetivo y no se encontró ningún makefile.  Alto.
                     *** No target was specified and no makefile was found. stop.
  
  En caso contrario puedes configurar "make" siguiendo este video: https://www.youtube.com/watch?v=jfVqzNU3gPg
- (ALTERNATIVA CON COMANDO MAKE, SI HA CONFIGURADO CORRECTAMENTE LO ANTERIOR, PUEDE SALTARSE ESTE PASO):

  Ejecuta el siguiente comando "mingw32-make.exe", (este ejecutable se encontrara en la misma carpeta "bin", direccion agregada al path para compilar con g++ o gcc)
  Este comando funciona de la misma manera que "make".
  
# <img src="https://raw.githubusercontent.com/SamHerbert/SVG-Loaders/5deed925369e57e9c58ba576ce303466984db501/svg-loaders/bars.svg" width = 15px> Construir
- Una vez descargado el pequeño proyecto, dirigete desde tu terminal a la estructura del mismo donde encontraras lo siguiente.

- /NombreCarpeta                            
  - /arc                               
  - /bin                             
  - /build                           
  - /inc                             
  - /lib                             
  - /res                                                   
  - /src        
  - Makefile

- Ejecuta el comando "make" para generar los objetos, dependencias y ejecutable, el proyecto esta creado de tal manera no tengas la necesidad de descargar Librerias, ya que SDL2( SDL2.h, SDL_image.h, SDL_ttf.h ), asi como los .dll estan incluidos hasta este punto.

                 ***NOTA: Cualquier otra libreria extra de SDL2 sera necesario agregarla y linkearla en el archivo Makefile.

- Una vez ejecutado el comando dirigete a la carpeta /bin donde se alojara el ejecutable del proyecto .exe, visualizando asi el mismo.

----

# <img src="https://raw.githubusercontent.com/SamHerbert/SVG-Loaders/5deed925369e57e9c58ba576ce303466984db501/svg-loaders/bars.svg" width = 15px> MODELOS OBJ

En el video presentamos diferentes "cuerpos" cada uno de ellos pueden cambiarse desde el archivo "/src/Main.cpp",  pasando como tercer parametro el nombre de los modelos .obj, alojados en /res/models

              ***Framework Solid(800,500,"Cube","KevinHGX"); <=> Framework Solid(800,500,"Octahedron","KevinHGX");

Link Video: https://youtu.be/t1ES_V6xjzw?si=Kv8Ugli0vZs3qy1V


Creator: KevinHGX
