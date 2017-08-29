//
// trueFalseClock.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Thu Mar  2 13:31:28 2017 Rodrigue René
// Last update Thu Mar  2 18:27:53 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

nts::IComponent	*Computer::createTrue(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("true", value);
  //  std::cout<<"createtrue"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "true";
  //pin1
  filler(piece, 1, 0);
  piece->_maxPin = 1;
  return (dynamic_cast<nts::IComponent *>(piece));
}


nts::IComponent	*Computer::createClock(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("clock", value);
  //  std::cout<<"createclock"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "clock";
  //pin1
  filler(piece, 1, 0);
  piece->_maxPin = 1;
  return (dynamic_cast<nts::IComponent *>(piece));
}

nts::IComponent	*Computer::createFalse(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("false", value);
  //  std::cout<<"createfalse"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "false";
  //pin1
  filler(piece, 1, 0);
  piece->_maxPin = 1;
  return (dynamic_cast<nts::IComponent *>(piece));
}
