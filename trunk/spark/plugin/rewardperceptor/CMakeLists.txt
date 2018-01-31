
########### next target ###############

set(rewardperceptor_LIB_SRCS
   export.cpp
   rewardperceptor.h
   rewardperceptor.cpp
   rewardperceptor_c.cpp
)

add_library(rewardperceptor MODULE ${rewardperceptor_LIB_SRCS})

target_link_libraries(rewardperceptor ${spark_libs} ${Boost_LIBRARIES} b64)

if (NOT APPLE)
   set_target_properties(rewardperceptor PROPERTIES VERSION 0.0.0 SOVERSION 0)
endif (NOT APPLE)

if (NOT APPLE)
   install(TARGETS rewardperceptor DESTINATION ${LIBDIR}/${CMAKE_PROJECT_NAME})
endif (NOT APPLE)
