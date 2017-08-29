//
// input.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Feb 18 00:27:00 2017 Rodrigue René
// Last update Thu Mar  2 18:27:37 2017 Rodrigue René
//

#include "Computer.hpp"
#include "Processor.hpp"

void	Computer::filler(nts::Processor *piece, int actual, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
}

nts::IComponent	*Computer::createInput(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("input", value);
  //  std::cout<<"createinput"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "input";
  //pin1
  filler(piece, 1, 0);
  piece->_maxPin = 1;
  return (dynamic_cast<nts::IComponent *>(piece));
}
