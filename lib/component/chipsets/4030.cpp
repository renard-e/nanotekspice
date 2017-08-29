//
// 4030.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Wed Mar  1 21:05:16 2017 Rodrigue René
// Last update Sun Mar  5 16:46:27 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

void	Computer::filler4030(nts::Processor *piece, int actual, int first, int second, int type) const
{
  std::get<0>(piece->_listPin[actual]) = type;
  std::get<2>(piece->_listPin[actual]) = nts::UNDEFINED;
  if (type == 2)
    {
      std::get<1>(piece->_listPin[actual]) = [piece, first, second]()->nts::Tristate{
	if (std::get<2>(piece->_listPin[first]) == nts::UNDEFINED ||
	    std::get<2>(piece->_listPin[second]) == nts::UNDEFINED)
	  return (nts::UNDEFINED);
	return static_cast<nts::Tristate>(std::get<2>(piece->_listPin[first]) ^
					  std::get<2>(piece->_listPin[second]))
	; };

    }

}

nts::IComponent	*Computer::create4030(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4030", value);
  //  std::cout<<"create4030"<<std::endl;
  piece->_name = value;
  piece->_typeProc = "4030";
  //pin1
  filler(piece, 1, -1, -1, 0);
  //pin2
  filler(piece, 2, -1, -1, 0);
  //pin3
  filler4030(piece, 3, 1, 2, 2);
  std::get<5>(piece->_listPin[3]).push_back(1);
  std::get<5>(piece->_listPin[3]).push_back(2);
  //pin4
  filler4030(piece, 4, 5, 6, 2);
  std::get<5>(piece->_listPin[4]).push_back(5);
  std::get<5>(piece->_listPin[4]).push_back(6);
  //pin5
  filler(piece, 5, -1, -1, 0);
  //pin6
  filler(piece, 6, -1, -1, 0);
  //pin7
  filler(piece, 7, -1, -1, 0);
  //pin8
  filler(piece, 8, -1, -1, 0);
  //pin9
  filler(piece, 9, -1, -1, 0);
  //pin10
  filler4030(piece, 10, 8, 9, 2);
  std::get<5>(piece->_listPin[10]).push_back(8);
  std::get<5>(piece->_listPin[10]).push_back(9);
  //pin11
  filler4030(piece, 11, 12, 13, 2);
  std::get<5>(piece->_listPin[11]).push_back(12);
  std::get<5>(piece->_listPin[11]).push_back(13);
  //pin12
  filler(piece, 12, -1, -1, 0);
  //pin13
  filler(piece, 13, -1, -1, 0);
  //pin14
  filler(piece, 14, -1, -1, 0);
  piece->_maxPin = 14;
  return (dynamic_cast<nts::IComponent *>(piece));
}
