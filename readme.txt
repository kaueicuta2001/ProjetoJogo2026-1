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

* VISUAL STUDIO CODE (VSCode)
- Baixado e instalado a partir do site oficial do VSCode
- Baixe as extensões: C/C++, C/C++ Extension Pack e CMake Tools
------------------------------------------------------------------------
2. CONFIGURAÇÃO DAS VARIÁVEIS DE AMBIENTE (PATH)
------------------------------------------------------------------------
Para que o CMake e o compilador funcionem corretamente juntos, o caminho
dos binários do UCRT64 deve estar no PATH do seu Windows:
-> Adicione: C:\msys64\ucrt64\bin

------------------------------------------------------------------------
3. PASSO A PASSO PARA COMPILAR (VIA VSCODE)
------------------------------------------------------------------------
Abra o VSCode com todas as extensões do requisitos baixados e ativados
E então o CMake Tools irá reconhecer o CMake automaticamente
VSCode perguntará qual compilador utilizar
Selecione GCC 15.2.0 X86_64-w64-mingw32 (ucrt64)
Cmake irá começar o build
quando terminar pressione crtl + shift + P
selecione CMake: run without debugging
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
