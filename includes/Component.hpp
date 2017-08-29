//
// Component.hpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/includes
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Thu Feb  9 17:45:05 2017 Rodrigue René
// Last update Sat Mar  4 21:18:19 2017 Rodrigue René
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace nts
{
  class Processor;
}

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class IComponent
  {
  public:
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component,
			 size_t pin_num_target) = 0;
    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    // as a trace.
    virtual void Dump(void)const = 0;
    virtual ~IComponent(void) { }
  };
}

#endif // __ICOMPONENT_HPP_
