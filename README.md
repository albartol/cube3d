# Cube 3D 🎮

## Descripción

Este proyecto consiste en la creación de un cubo 3D rotatorio utilizando programación en C y la librería gráfica MLX42. El objetivo principal es profundizar en conceptos de álgebra lineal, geometría y gráficos 3D, aplicados para transformar y visualizar objetos tridimensionales en la pantalla.

Lo que hemos implementado tiene la capacidad de realizar movimientos de rotación en varios ejes, incluyendo un movimiento de rotación de arriba hacia abajo (no es un bug, es un feature), que añade interactividad y dinámica al espacio.

## **Funcionalidades**: 

- ✅ **Movilidad**: Puedes moverte con las teclas **WASD** de tu teclado y rotar la camara con las flechitas del mismo < ˅ ˄ >, si deseas rotarla con el raton presiona la tecla **c** para activar y desactivar el ratón. Puedes pulsar la tecla **m** para evitar mostrar el mapa y **esc** para salir de la simulación
- ✅ **Interactividad**: El proyecto permite interactuar con el cubo, modificando su orientación mediante teclas.
- ✅ **Adaptabilidad**: El proyecto permite crear mapas personalizados siempre y cuando estos tengan la extensión .cub

## Tecnologías Utilizadas 🖥️

- **Lenguaje de Programación**: C
- **Archivo Makefile**: Para compilar todo automaticamente
- **Librería Gráfica**: MLX42
- **Álgebra Lineal y Cálculo Diferencial**: Para las Transformaciones de matrices para rotación, calculo de rayos y mapeo de imagen.
  
## Matemáticas 🖩

El proyecto hace uso de las siguientes técnicas matemáticas fundamentales:

- **Matrices de Transformación**: Se emplean matrices de rotación para modificar la orientación del cubo en el espacio tridimensional.
- **Álgebra Lineal**: Las rotaciones se implementan mediante operaciones matriciales, lo que permite transformar el cubo de manera eficiente.
- **Trigonometría**: Usamos el concepto de las mismas para calcular los rayos que lanza el DDA, calculando las hipotenusas cuando obtenemos las deltas de los catetos.
  
## Videos

A continuación se muestran algunas imágenes del cubo en rotación desde diferentes perspectivas:

![Ejemplo de uso](media/spy_family_map.gif)
![POV Texturas](media/NWSE-demostration.gif)
![POV Backrooms](media/Backrooms.gif)

## Contribuciones

Este proyecto fue realizado en colaboración por @SherlokPE y @Albartol, implementamos juntos todas las funcionalidades como el diseño y estructura del proyecto.

## Instrucciones de Uso

1. Clona el repositorio.
2. Compila el proyecto con el comando `make`.
3. Ejecuta el programa con `./cub3d`. seguido del mapa que renderizarás, puedes encontrar muchos mapas de ejemplo en la carpeta ***scenes***
4. Puedes crear editar y añadir a tu mapa propio personalizado diversas texturas, puedes encontrar muchas de estas en la carpeta ***textures***, todo lo que debes hacer es escribir la ruta a las mismas ♥️
<br>
(Nuestro proyecto usa la librería MLX42, para ello deberás descargar sus dependencias(Próximamente añadiremos una imagen de docker para facilitar su uso))

## Autores

Fabricio López Reyes 
Alejandro Bartolomé Blanco 