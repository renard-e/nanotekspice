//
// 4069.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Thu Mar  2 01:13:09 2017 Rodrigue René
// Last update Sun Mar  5 17:11:53 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4069(nts::Processor *piece, int actual, int only, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, only]()->nts::Tristate{
	if (std::get<2>(piece->_listPin[only]) == nts::UNDEFINED)
	  return (nts::UNDEFINED);
	return static_cast<nts::Tristate>(!std::get<2>(piece->_listPin[only]));
      };
    }
}

nts::IComponent	*Computer::create4069(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4069", value);
  //  std::cout<<"create4069"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "4069";
  //pin1
  filler(piece, 1, -1, -1, 0);
  //pin2
  filler4069(piece, 2, 1, 2);
  std::get<5>(piece->_listPin[2]).push_back(1);
  //pin3
  filler(piece, 3, -1, -1, 0);
  //pin4
  filler4069(piece, 4, 3, 2);
  std::get<5>(piece->_listPin[4]).push_back(3);
  //pin5
  filler(piece, 5, -1, -1, 0);
  //pin6
  filler4069(piece, 6, 5, 2);
  std::get<5>(piece->_listPin[6]).push_back(5);
  //pin7
  filler4069(piece, 7, -1, 0);
  //pin8
  filler4069(piece, 8, 9, 2);
  std::get<5>(piece->_listPin[8]).push_back(9);
  //pin9
  filler(piece, 9, -1, -1, 0);
  //pin10
  filler4069(piece, 10, 11, 2);
  std::get<5>(piece->_listPin[10]).push_back(11);
  //pin11
  filler(piece, 11, -1, -1, 0);
  //pin12
  filler4069(piece, 12, 13, 2);
  std::get<5>(piece->_listPin[12]).push_back(13);
  //pin13
  filler(piece, 13, -1, -1, 0);
  //pin14
  filler(piece, 14, -1, -1, 0);
  piece->_maxPin = 14;
  return (dynamic_cast<nts::IComponent *>(piece));
}
