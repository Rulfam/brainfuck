#pragma once

#include <vector>

enum opcode_t
{
    OP_END = 0,

    OP_INC_PTR = 1,
    OP_DEC_PTR = 2,

    OP_INC_BYTE = 3,
    OP_DEC_BYTE = 4,

    OP_WRITE = 5,
    OP_READ = 6,

    OP_JMP_FORWARD = 7,
    OP_JMP_BACK = 8,
};

struct stack_t
{
  private:
    unsigned int m_ptr = 0;
    std::vector<int> m_data;

  public:
    void push(const char value);
    char pop();
    bool is_empty();
};

struct memory_t
{
  private:
    unsigned int m_ptr = 0;
    std::vector<char> m_data = {0};

  public:
    void write(char data);
    char read();

    unsigned int get_ptr_position();
    void advance_ptr();
    void regress_ptr();

    void increment();
    void decrement();
};

struct instruction_t
{
    char code;
    unsigned int arg;
};

struct program_t
{
    std::pmr::vector<instruction_t> instructions;

    void append_instruction(instruction_t instruction);
    void append_instruction(opcode_t instruction);
    instruction_t read_instruction(unsigned int counter);
};
