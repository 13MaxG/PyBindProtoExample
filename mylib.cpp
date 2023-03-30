#include <pybind11/pybind11.h>
#include <iostream>
#include <algorithm>
#include "mymessages.pb.h"

namespace py = pybind11;

py::bytes process(const std::string& in){
    mymessages::Message m;

    m.ParseFromString(in);
    
    std::string str= m.name();
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    m.set_name(str);

    std::string result;
    m.SerializeToString(&result);
    return py::bytes(result);
}


PYBIND11_MODULE(mylib, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("process", &process, "A function that adds two numbers");
}