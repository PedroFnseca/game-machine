@echo off
setlocal

:: Diretórios
cd ..

set SRC_DIR=src
set BIN_DIR=bin

:: Arquivos fonte
set SRCS=%SRC_DIR%\main.c

:: Nome do executável
set TARGET=%BIN_DIR%\game.exe

:: Flags do compilador
set CFLAGS=-I"C:\allegro\include"
set LDFLAGS=-L"C:\allegro\lib" -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

:: Criar diretório bin se não existir
if not exist %BIN_DIR% mkdir %BIN_DIR%

:: Compilar os arquivos fonte
gcc %SRCS% -o %TARGET% %CFLAGS% %LDFLAGS%

:: Verificar se a compilação foi bem-sucedida
if %errorlevel% neq 0 (
  echo Compilation failed!
  pause
  exit /b
)

:: Executar o jogo
if exist %TARGET% (
  %TARGET%
) else (
  echo Executable not found!
)

pause
endlocal