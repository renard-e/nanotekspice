//
// createComponent.cpp for nanoTekSpice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/lib/component
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Feb 12 01:52:47 2017 Rodrigue René
// Last update Tue Feb 14 07:33:04 2017 Rodrigue René
//

#include "Component.hpp"

nts::IComponent *nts::createComponent(const std::string &type, const std::string &value)
{
  newCompo = nts::Processor(type, value);
  return (newCompo);
}
