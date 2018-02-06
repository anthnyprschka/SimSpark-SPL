
########### next target ###############

set(isfallenperceptor_LIB_SRCS
   export.cpp
   isfallenperceptor.h
   isfallenperceptor.cpp
   isfallenperceptor_c.cpp
)

add_library(isfallenperceptor MODULE ${isfallenperceptor_LIB_SRCS})

target_link_libraries(isfallenperceptor ${spark_libs})

if (NOT APPLE)
   set_target_properties(isfallenperceptor PROPERTIES VERSION 0.0.0 SOVERSION 0)
endif (NOT APPLE)

install(TARGETS isfallenperceptor DESTINATION ${LIBDIR}/${CMAKE_PROJECT_NAME})

