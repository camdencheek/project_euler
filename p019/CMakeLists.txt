cmake_minimum_required ( VERSION 3.5.1 )
project ( p019 )
add_executable ( prog p019.cpp )
target_compile_features(prog PRIVATE cxx_range_for)
