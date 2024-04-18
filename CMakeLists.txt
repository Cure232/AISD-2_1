# CMakeList.txt: проект CMake для AISD-2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("AISD-2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (AISD-2 "AISD-2.cpp"  "LinkedList.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AISD-2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
