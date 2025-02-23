#pragma once

#include "machine.hpp"
#include <cstdio>
#include <fstream>

int compile(std::ifstream& file, program_t& program);
