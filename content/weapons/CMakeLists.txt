add_library(weapons
  none.cpp
  cleaver.cpp
  axe.cpp
  bhammer.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
