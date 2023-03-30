cmake_minimum_required(VERSION 3.16)
project(mylib)
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Protobuf REQUIRED)

set(PROTOS mymessages.proto)
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER ${PROTOS})
protobuf_generate_python(PROTO_PY ${PROTOS})
add_custom_target(protopydep ALL DEPENDS ${PROTO_PY})
message(TUTAJ ${PROTO_PY})
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})
target_include_directories(proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET proto PROPERTY POSITION_INDEPENDENT_CODE ON)


add_subdirectory(pybind11)
pybind11_add_module(mylib SHARED mylib.cpp ${PROTO_SRC})
#TARGET_LINK_LIBRARIES(mylib PRIVATE proto)
target_link_libraries(mylib PUBLIC proto protobuf pybind11::module ${ITK_LIBRARIES})
