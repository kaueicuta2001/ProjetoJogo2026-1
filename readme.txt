========================================================================
           THE FROG++ - GUIA DE COMPILAÇÃO E EXECUÇÃO (WINDOWS)
========================================================================

Este documento descreve os pré-requisitos e o passo a passo para clonar,
compilar e executar o jogo The Frog++ em ambiente Windows.

------------------------------------------------------------------------
1. PRÉ-REQUISITOS DO SISTEMA
------------------------------------------------------------------------
Certifique-se de ter as seguintes ferramentas instaladas no Windows:

* MSYS2 (Ambiente UCRT64)
  - O MSYS2 deve estar instalado (geralmente em C:\msys64).
  - Certifique-se de que o compilador GCC/G++ está configurado. No terminal
    UCRT64 do MSYS2, os compiladores são instalados via comando:
    pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make

* CMake (Versão para Windows)
  - Baixado e instalado a partir do site oficial do CMake.
  - O executável 'cmake.exe' deve estar configurado nas variáveis de 
    ambiente do sistema (PATH) para ser acessado via prompt.

------------------------------------------------------------------------
2. CONFIGURAÇÃO DAS VARIÁVEIS DE AMBIENTE (PATH)
------------------------------------------------------------------------
Para que o CMake e o compilador funcionem corretamente juntos, o caminho
dos binários do UCRT64 deve estar no PATH do seu Windows:
-> Adicione: C:\msys64\ucrt64\bin

------------------------------------------------------------------------
3. PASSO A PASSO PARA COMPILAR (VIA TERMINAL)
------------------------------------------------------------------------
Abra o prompt de comando (CMD ou PowerShell) na pasta raiz do seu projeto 
(onde se encontra o arquivo principal 'CMakeLists.txt') e execute os
seguintes comandos:

1) Criar e entrar no diretório de build:
   mkdir build
   cd build

2) Gerar os arquivos de build do CMake especificando os compiladores do UCRT64:
   cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=C:/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/msys64/ucrt64/bin/g++.exe ..

3) Compilar o projeto (utilizando múltiplos núcleos para acelerar):
   cmake --build . --config Debug -j 12

------------------------------------------------------------------------
4. EXECUTANDO O JOGO
------------------------------------------------------------------------
Após a conclusão bem-sucedida do build (100%), o arquivo executável 
'ProjetoJogo.exe' será gerado dentro da pasta 'build'.

Para rodar o jogo:
1) Certifique-se de que as DLLs da SFML geradas e a pasta de assets (imagens/sons) 
   estão acessíveis a partir do diretório de execução.
2) No terminal, dentro da pasta build, execute:
   .\ProjetoJogo.exe

------------------------------------------------------------------------
5. RESOLUÇÃO DE PROBLEMAS
------------------------------------------------------------------------
* Erro: "Uma política de Controle de Aplicativo bloqueou este arquivo"
  - O Windows Defender SmartScreen pode barrar executáveis recém-compilados.
  - Solução: Clique com o botão direito no arquivo 'ProjetoJogo.exe', vá em 
    Propriedades, marque a opção "Desbloquear" na aba Geral e aplique. 
    Alternativamente, adicione a pasta do projeto às exclusões do antivírus.

* Erro de Inclusão Cíclica ou Tipos Desconhecidos no Build
  - Certifique-se de que os cabeçalhos (.h) usam Forward Declarations para 
    evitar loops de leitura do compilador e que as assinaturas batam com os .cpp.
========================================================================