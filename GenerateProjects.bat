@echo off

REM Verificar si la carpeta build ya existe
if not exist build (
    mkdir build
)

REM Cambiar al directorio build
cd build

REM Ejecutar CMake en el directorio actual (..)
cmake ..

REM Regresar al directorio original
cd ..

REM Mensaje de finalización
echo Proceso completado.

popd
PAUSE