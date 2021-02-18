cmake_minimum_required(VERSION 3.10)

set(SRCS
  "main.cpp"
  "pdf-format.cpp"
  "reader.cpp"
  "worker.cpp"
  "console.cpp"
)
set(HEADERS
  "common.hpp"
    "error_code.hpp"
    "reserved_code.hpp"
  "pdf-format.hpp"
  "reader.hpp"
  "worker.hpp"
  "console.hpp"
)

add_executable(${PROJECT_NAME} 
  ${SRCS}
  ${HEADERS}
)