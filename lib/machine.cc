#include "machine.hh"

/* stack_t */

void stack_t::push(const char value)
{
    m_data.push_back(value);
    m_ptr++;
}

char stack_t::pop()
{
    return m_data[--m_ptr];
}

bool stack_t::is_empty()
{
    return m_ptr == 0;
}

/* memory_t */

void memory_t::write(char data)
{
    m_data[m_ptr] = data;
}

char memory_t::read()
{
    return m_data[m_ptr];
}

unsigned int memory_t::get_ptr_position()
{
    return m_ptr;
}

void memory_t::advance_ptr()
{
    m_data.push_back(0);
    m_ptr++;
}

void memory_t::regress_ptr()
{
    m_ptr--;
}

void memory_t::increment()
{
    m_data[m_ptr]++;
}

void memory_t::decrement()
{
    m_data[m_ptr]--;
}

/* program_t */

void program_t::append_instruction(instruction_t instruction)
{
    instructions.push_back(instruction);
}

void program_t::append_instruction(opcode_t instruction)
{
    append_instruction({.code = static_cast<char>(instruction), .arg = 0});
}

instruction_t program_t::read_instruction(unsigned int position)
{
    return instructions[position];
}
