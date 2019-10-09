cmake_minimum_required(VERSION 3.0)

project(asc++_core VERSION 0.0.1 DESCRIPTION "asc++ core library")

include_directories(include)

add_library(${PROJECT_NAME} SHARED
  "src/sprite.cpp"
  "src/sprite_loader.cpp"
  "src/renderer.cpp"
  "src/game_object.cpp"
  "src/game_scene.cpp"
)

target_link_libraries(${PROJECT_NAME} stdc++fs)

include(GNUInstallDirs)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

target_include_directories(${PROJECT_NAME} PRIVATE include)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/modules/core/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

file(GLOB headers "include/*.h")
install(FILES ${headers}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/asc++_core)
