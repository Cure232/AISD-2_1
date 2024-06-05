# CMakeList.txt: проект CMake для AISD-2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("AISD-2")

# Добавьте источник в исполняемый файл этого проекта.
#add_executable (AISD-2 "AISD-2.cc"  "include/SearchTree.h")

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.


# Объявляем библиотеку
add_library(main-v1 SHARED
    "include/SearchTree.h"
    "AISD-2.cpp")
target_include_directories(main-v1 PUBLIC "include")

add_executable(main-v1-tests
    "tests/Time_Tests.cc"
)
target_link_libraries(main-v1-tests main-v1 GTest::gtest_main)