set(GCPP_SRC garbagecollector.cpp gcobject.cpp)

add_library(GCPP ${GCPP_SRC})
target_include_directories(GCPP PRIVATE ${CMAKE_SOURCE_DIR}/include/GCPP/)
target_compile_definitions(GCPP PRIVATE GCPP_LIBRARY)
