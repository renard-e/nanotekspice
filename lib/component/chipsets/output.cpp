//
// output.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Feb 18 00:29:39 2017 Rodrigue René
// Last update Thu Mar  2 18:27:31 2017 Rodrigue René
//

#include "Computer.hpp"
#include "Processor.hpp"

nts::IComponent	*Computer::createOutput(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("output", value);

  //  std::cout<<"createoutput"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "output";
  //pin1
  filler(piece, 1, 2);
  piece->_maxPin = 1;
  return (dynamic_cast<nts::IComponent *>(piece));
}
