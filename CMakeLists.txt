CMAKE_MINIMUM_REQUIRED_VERSION(VERSION 3.5)
project(snake)
include_directories(./wintertanchishe)

aux_source_directory(./wintertanchishe SOURCE_DIR)

add_executable(snake ${SOURCE_DIR}) 