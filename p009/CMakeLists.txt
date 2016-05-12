cmake_minimum_required ( VERSION 3.5.2 )
project ( p009 )
add_executable ( prog p009.cpp )
target_compile_features(prog PRIVATE cxx_range_for)
