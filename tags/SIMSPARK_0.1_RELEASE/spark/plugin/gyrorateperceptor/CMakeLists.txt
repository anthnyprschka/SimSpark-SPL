
########### next target ###############

set(gyrorateperceptor_LIB_SRCS
   export.cpp
   gyrorateperceptor.h
   gyrorateperceptor.cpp
   gyrorateperceptor_c.cpp
)

add_library(gyrorateperceptor MODULE ${gyrorateperceptor_LIB_SRCS})

target_link_libraries(gyrorateperceptor)

set_target_properties(gyrorateperceptor PROPERTIES VERSION 0.0.0 SOVERSION 0)
install(TARGETS gyrorateperceptor DESTINATION ${LIBDIR}/${CMAKE_PROJECT_NAME})
