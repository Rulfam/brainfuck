#include "compiler.hh"
#include "machine.hh"
#include "runner.hh"
#include <cstdio>
#include <fstream>

int main(const int argc, const char **argv)
{
    /* Open file */

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return 1;
    }

    std::ifstream file(argv[1], std::fstream::in);

    if (!file.good())
    {
        fprintf(stderr, "Error: input (%s) is not a valid file\n", argv[1]);
        return 1;
    }

    /* Validate & Run */

    program_t program;
    int validator_status = compile(file, program);
    file.close();

    if (validator_status == 1)
    {
        fprintf(stderr, "Error: code validation failed\n");
        return 1;
    }

    run(program);

    return 0;
}
