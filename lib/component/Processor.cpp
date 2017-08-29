//
// Processor.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Mon Feb 13 01:28:07 2017 Rodrigue René
// Last update Sun Mar  5 19:03:36 2017 Rodrigue René
//

#include <iostream>
#include <tuple>
#include <algorithm>
#include <map>
#include <string>
#include "Processor.hpp"
#include "Component.hpp"

nts::Processor::Processor()
{

}

nts::Processor::Processor(std::string const &type, std::string const &value)
{
  _typeProc = type;
  _name = value;
}

nts::Processor::~Processor()
{

}

nts::Tristate nts::Processor::Compute(size_t pin_num_this) // = 1)
{
  if (_typeProc != "output")
    std::get<2>(_listPin[pin_num_this]) = std::get<1>(_listPin[pin_num_this]) ();
  return (static_cast<nts::Tristate>(std::get<2>(_listPin[pin_num_this])));
}


//go search output and set the value of input
void		nts::Processor::takeInput(size_t pin_this, nts::Processor &thisComp)
{

  nts::Processor *prevIComp = dynamic_cast<nts::Processor *>(std::get<3>(thisComp._listPin[pin_this]));
  int prevpin = std::get<4>(thisComp._listPin[pin_this]);
  takeOutput(static_cast<size_t>(prevpin), *prevIComp);
  std::get<2>(thisComp._listPin[pin_this]) = std::get<2>(prevIComp->_listPin[prevpin]);
}

//go search input and set the value of OUTPUT
void		nts::Processor::takeOutput(size_t pin_this, nts::Processor &thisComp)
{
  if (pin_this == 0)
    {
      std::cout << "Error : need more input " << std::endl;
      exit(-1);
    }
  auto it = std::get<5>(thisComp._listPin[pin_this]).begin();
  for (;it != std::get<5>(thisComp._listPin[pin_this]).end(); it++)
    {
      takeInput(*it, thisComp);
    }

  if (std::get<0>(thisComp._listPin[pin_this]) == 2 && _typeProc != "input")
    std::get<2>(thisComp._listPin[pin_this]) = std::get<1>(thisComp._listPin[pin_this])();
}

void nts::Processor::Simulate()
{
  size_t here = 1;

  takeInput(here, *this);
}




void	nts::Processor::SetLink(size_t pin_num_this, nts::IComponent &component,size_t pin_num_target)
{
  Processor *comp2;

  std::get<3>(_listPin[pin_num_this]) = dynamic_cast<nts::Processor *>(&component);
  std::get<4>(_listPin[pin_num_this]) = pin_num_target;
  comp2 = dynamic_cast<nts::Processor *>(&component);
  std::get<3>(comp2->_listPin[pin_num_target]) = this;
  std::get<4>(comp2->_listPin[pin_num_target]) = pin_num_this;
}

void	nts::Processor::Dump(void)const
{
  std::cout << _name << ":" << std::endl;
  for (int i = 1; i <= _maxPin ;i++)
    {
      std::cout<<"pin "<< i <<" = "<< std::get<2>(this->_listPin.at(i))<< std::endl;
    }
}
