cmake_minimum_required(VERSION 3.10)
project(Tarea_3_ALSE)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# LeetCode Executable (si existe)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LeetCode/main.cpp")
    add_executable(EjecutableLeetCode LeetCode/main.cpp)
endif()

# Exercism 01: Crypto Square
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Exercism/01_crypto_square/01_crypto_square.cpp")
    add_executable(01_crypto_square Exercism/01_crypto_square/01_crypto_square.cpp)
endif()

# Exercism 02: Bank Account
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Exercism/02_bank_account/02_bank_account.cpp")
    add_executable(02_bank_account Exercism/02_bank_account/02_bank_account.cpp)
    target_link_libraries(02_bank_account PRIVATE Threads::Threads)
endif()