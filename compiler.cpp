#include "compiler.hpp"
#include "machine.hpp"
#include <cstdio>
#include <fstream>

int compile(std::ifstream& file, program_t& program)
{
    unsigned int pc = 0, jpc = 0;
    char word;
    stack_t call_stack;

    while (file >> std::noskipws >> word)
    {
        switch (word)
        {
        case '>':
            program.append_instruction(OP_INC_PTR);
            break;
        case '<':
            program.append_instruction(OP_DEC_PTR);
            break;
        case '+':
            program.append_instruction(OP_INC_BYTE);
            break;
        case '-':
            program.append_instruction(OP_DEC_BYTE);
            break;
        case '.':
            program.append_instruction(OP_WRITE);
            break;
        case ',':
            program.append_instruction(OP_READ);
            break;
        case '[':
            program.append_instruction(OP_JMP_FORWARD);
            call_stack.push(pc);
            break;
        case ']':
            if (call_stack.is_empty())
            {
                fprintf(stderr, "Error: a ']' doesn't have an opening pair\n");
                return 1;
            }

            jpc = call_stack.pop();
            program.append_instruction({.code = OP_JMP_BACK, .arg = jpc});
            program.instructions[jpc].arg = pc;
            break;
        default:
            --pc;
            break;
        }
        ++pc;
    }

    if (!call_stack.is_empty())
    {
        fprintf(stderr, "Error: call stack was not emptied\n");
        return 1;
    }

    program.append_instruction(OP_END);

    return 0;
}
