cmake_minimum_required(VERSION 3.10)
project(Tarea_3_ALSE)

set(CMAKE_CXX_STANDARD 17)

# LeetCode Executable (si existe el archivo)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LeetCode/main.cpp")
    add_executable(EjecutableLeetCode LeetCode/main.cpp)
endif()

# Exercism 01: Crypto Square
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Exercism/01_crypto_square/01_crypto_square.cpp")
    add_executable(01_crypto_square Exercism/01_crypto_square/01_crypto_square.cpp)
endif()