#include "runner.hpp"
#include "machine.hpp"
#include <cstdio>

void run(program_t& program)
{
    memory_t memory;
    unsigned int pc = 0;

    while (program.instructions[pc].code != OP_END)
    {
        switch (program.instructions[pc].code)
        {
        case OP_INC_PTR:
            memory.advance_ptr();
            break;
        case OP_DEC_PTR:
            memory.regress_ptr();
            break;
        case OP_INC_BYTE:
            memory.increment();
            break;
        case OP_DEC_BYTE:
            memory.decrement();
            break;
        case OP_WRITE:
            putchar(memory.read());
            break;
        case OP_READ:
            memory.write(getchar());
            break;
        case OP_JMP_FORWARD:
            if (memory.read() == 0)
                pc = program.instructions[pc].arg;
            break;
        case OP_JMP_BACK:
            if (memory.read() != 0)
                pc = program.instructions[pc].arg;
            break;
        default:
            fprintf(stderr, "Error: unexpected symbol");
            return;
        }
        pc++;
    }
}
