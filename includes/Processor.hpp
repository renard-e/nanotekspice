//
// Processor.hpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/includes
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Feb 12 16:56:47 2017 Rodrigue René
// Last update Sat Mar  4 21:21:49 2017 Rodrigue René
//

#ifndef PROCESSOR_HPP_
# define PROCESSOR_HPP_

#include <algorithm>
#include <map>
#include <tuple>
#include <functional>
#include <utility>
#include "Component.hpp"
#include "Gate.hpp"

//typedef std::tuple<nts::Gate *, int, nts::Processor *, int > T_LISTPIN;

namespace nts
{
  /////////////////   0            1              2        3           4            5
  /////////////////  TYPE        LAMBDA,        ETAT, IComptarget, pintarget ,autre(si output)
  typedef std::tuple<int, std::function<int()>, int , IComponent*, int     ,std::vector<int> > T_LISTPIN;

  class Processor : public nts::IComponent
  {

  public:
    std::string								_name;
    std::string								_typeProc;
    std::vector<nts::Tristate>						_inOut;
    std::map<int, T_LISTPIN >						_listPin;
    std::vector<nts::Gate *>						_listGate;
    int									_composants;
    int									_maxPin;

    Processor();
    Processor(std::string const&, std::string const&);
    ~Processor();

    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component,
			 size_t pin_num_target);
    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    // as a trace.
    virtual void	Dump(void) const;
    void	        takeOutput(size_t pin_this, nts::Processor &thisComp);
    void		takeInput(size_t pin_this, nts::Processor &thisComp);
    void		Simulate();
  };
}
#endif /* !PROCESSOR_HPP_ */
