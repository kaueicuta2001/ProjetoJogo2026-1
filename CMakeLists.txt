cmake_minimum_required(VERSION 3.12)
project(ProjetoJogo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Desliga extensões que podem chocar com a STL

# Configura as opções do SFML antes de puxar a pasta dele
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE) 

add_subdirectory(SFML-2.6.2)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Garante que as pastas padrão de inclusão do seu compilador (STL) fiquem visíveis no seu alvo
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Linka o SFML ao seu jogo
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Copia as DLLs básicas do compilador para a pasta da build
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/msys64/ucrt64/bin/libgcc_s_seh-1.dll"
        "C:/msys64/ucrt64/bin/libstdc++-6.dll"
        "C:/msys64/ucrt64/bin/libwinpthread-1.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -O3 -march=native)
endif()