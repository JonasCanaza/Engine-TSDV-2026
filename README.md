Motor de videojuegos 2D modular desarrollado en **C++** sobre **OpenGL 3.3 Core**, compilado como librería dinámica (`ENGINE_API`). Implementa un pipeline de renderizado programable, sistema de entidades con transformaciones basadas en cuaterniones, animaciones por *sprite sheet*, gestión de entrada por estados y detección de colisiones AABB.

---

## Características Principales

* **Pipeline de Renderizado (OpenGL 3.3 Core):** Gestión de buffers `VAO`, `VBO` y `EBO` con layout intercalado de vértices (`vec3` posición, `vec4` color RGBA, `vec2` coordenadas UV), proyección ortográfica 2D y soporte de transparencias mediante *Alpha Blending* (`GL_SRC_ALPHA`, `GL_ONE_MINUS_SRC_ALPHA`).
* **Shaders y Materiales:** Compilación y enlazado dinámico de *Vertex* y *Fragment Shaders* en GLSL, con gestión de ubicaciones de *uniforms* (`model`, `view`, `projection`).
* **Texturas y Mipmapping:** Carga de imágenes en formatos `RGB`, `RGBA`, `RED` y `ALPHA` mediante `stb_image`, con generación automática de mipmaps (`glGenerateMipmap`), filtrado trilineal (`GL_LINEAR_MIPMAP_LINEAR`) y manejo de alineación de memoria (`GL_UNPACK_ALIGNMENT`).
* **Animación 2D por Sprite Sheets:** Recorte de cuadros mediante coordenadas UV normalizadas, control de duración por ciclo y actualización dinámica del `VBO` en tiempo de ejecución.
* **Sistema de Entidades y Transformaciones (TRS):** Jerarquía `Entity` -> `Entity2D` -> `Shape` / `Sprite` con matrices de transformación global, rotaciones con cuaterniones (`glm::quat`) y recálculo automático de volúmenes delimitadores.
* **Detección de Colisiones AABB:** Evaluación de superposición entre cajas alineadas a los ejes con cálculo de vector de penetración (`intersection`) y resolución del lado de impacto (`Top`, `Bottom`, `Left`, `Right`).
* **Sistema de Input:** Mapeo de teclado sobre GLFW con detección precisa de transiciones por frame (`KeyPressed`, `KeyDown`, `JustReleased`, `KeyUp`).

---

## Arquitectura de Módulos

| Módulo / Namespace | Responsabilidad |
| :--- | :--- |
| **`Window`** | Creación y administración de la ventana GLFW, contexto OpenGL e intercambio de buffers (*double buffering*). |
| **`Renderer`** | Inicialización de GLEW, creación/destrucción de modelos y texturas, actualización de VBOs y ejecución de *draw calls* (`DrawShape`, `DrawSprite`). |
| **`ShaderProgram` / `Material`** | Encapsulamiento de programas GLSL y administración de shaders base y personalizados. |
| **`Entity` / `Entity2D`** | Clase base con estado de color, transformaciones TRS (`Translate`, `Rotate`, `Scale`), actualización de matrices y cálculo de AABB. |
| **`Shape` / `Shapes`** | Primitivas geométricas 2D (como `Triangle`) renderizadas mediante colores por vértice. |
| **`Sprite`** | Entidad texturizada basada en un quad indexado con soporte para tintado de color y reproducción de animaciones. |
| **`TextureImporter`** | Decodificación de archivos de imagen desde disco con `stb_image` y subida a GPU a través del `Renderer`. |
| **`Animation` / `AnimationFrame`** | Administración de secuencias de cuadros UV, temporizadores de reproducción y reinicio de ciclos. |
| **`CollisionManager`** | Consultas de colisión AABB entre entidades (booleana, con profundidad de intersección y con detección de cara de colisión). |
| **`Input`** | Sondeo de teclado desacoplado de GLFW mediante enumeraciones propias (`EngineInput` y `EngineInputState`). |
| **`Exceptions`** | Manejo de errores de inicialización de GLEW y compilación/enlazado de shaders. |

---

## Dependencias y Tecnologías

* **Lenguaje:** C++ (Visual Studio 2022 / MSVC)
* **API Gráfica:** OpenGL 3.3 Core
* **Gestión de Ventana e Input:** [GLFW](https://www.glfw.org/)
* **Extensiones OpenGL:** [GLEW](http://glew.sourceforge.net/)
* **Matemática Vectorial y Matricial:** [GLM](https://github.com/g-truc/glm)
* **Carga de Imágenes:** [stb_image](https://github.com/nothings/stb)

  ## Uso

  **El repositorio contiene un programa de ejemplo ubicado en la carpeta "Exe"

---## Compilación

1. Clonar el repositorio en un entorno **Windows** con **Visual Studio 2022**.
2. Asegurar que las rutas de inclusión y librerías estáticas/dinámicas de **GLFW**, **GLEW**, **GLM** y **stb_image** estén vinculadas en las propiedades del proyecto.
3. Compilar la solución en configuración **Debug** o **Release** (`x64`) para generar la DLL del motor junto con su archivo `.lib` asociado y enlazarlo al proyecto ejecutable del juego.

---

## Autor

Desarrollado por **Agustín Laure** — Tecnicatura en Programación de Videojuegos con Motores (Image Campus).
