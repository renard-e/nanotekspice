//
// 4503.cpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component/chipsets
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sat Mar  4 20:11:09 2017 Rodrigue René
// Last update Sat Mar  4 20:21:55 2017 Rodrigue René
//

#include "Component.hpp"
#include "Processor.hpp"
#include "Computer.hpp"

nts::IComponent	*Computer::create4503(const std::string &value) const
{
  nts::Processor *piece = new nts::Processor("4503", value);
  piece->_name = value;
  piece->_typeProc = "4503";
  //pin1 DIS
  filler(piece, 1, -1, -1, 0);
  //pin2
  filler(piece, 2, -1, -1, 0);
  //pin3
  filler4001(piece, 3, 1, 2, 2);
  std::get<5>(piece->_listPin[3]).push_back(1);
  std::get<5>(piece->_listPin[3]).push_back(2);
  //pin4
  filler4001(piece, 4, -1, -1, 0);

  //pin5
  filler(piece, 5, 1, 4, 2);
  std::get<5>(piece->_listPin[5]).push_back(1);
  std::get<5>(piece->_listPin[5]).push_back(4);

  //pin6
  filler(piece, 6, -1, -1, 0);
  //pin7
  filler(piece, 7, 1, 6, 2);
  std::get<5>(piece->_listPin[7]).push_back(1);
  std::get<5>(piece->_listPin[7]).push_back(6);
  //pin8
  filler(piece, 8, -1, -1, 0);
  //pin9
  filler(piece, 9, 1, 10, 2);
  std::get<5>(piece->_listPin[9]).push_back(10);
  std::get<5>(piece->_listPin[9]).push_back(1);

  //pin10
  filler4001(piece, 10, -1, -1, 0);
  //pin11
  filler4001(piece, 11, 12, 15, 2);
  std::get<5>(piece->_listPin[11]).push_back(12);
  std::get<5>(piece->_listPin[11]).push_back(15);
  //pin12
  filler(piece, 12, -1, -1, 0);
  //pin13
  filler(piece, 13, 15, 14, 2);
  std::get<5>(piece->_listPin[13]).push_back(14);
  std::get<5>(piece->_listPin[13]).push_back(15);
  //pin14
  filler(piece, 14, -1, -1, 0);
  //pin15 DIS2
  filler(piece, 15, -1, -1, 0);

  piece->_maxPin = 16;
  return (dynamic_cast<nts::IComponent *>(piece));
}
