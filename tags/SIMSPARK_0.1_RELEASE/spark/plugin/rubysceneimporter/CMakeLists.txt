########### next target ###############

set(rubysceneimporter_LIB_SRCS
   export.cpp
   rubysceneimporter.cpp
   rubysceneimporter.h
   rubysceneimporter_c.cpp
)

add_library(rubysceneimporter MODULE ${rubysceneimporter_LIB_SRCS})

target_link_libraries(rubysceneimporter sexp)

set_target_properties(rubysceneimporter PROPERTIES VERSION 0.0.0 SOVERSION 0)
install(TARGETS rubysceneimporter DESTINATION ${LIBDIR}/${CMAKE_PROJECT_NAME})
