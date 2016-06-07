cmake_minimum_required ( VERSION 3.5.1 )
project ( p010 )
add_executable ( prog p010.cpp )
target_compile_features(prog PRIVATE cxx_range_for)
