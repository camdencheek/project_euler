cmake_minimum_required ( VERSION 3.5.1 )
project ( p012 )
add_executable ( prog p012.cpp )
target_compile_features(prog PRIVATE cxx_range_for)
