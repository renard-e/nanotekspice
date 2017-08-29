//
// Chipsets.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Tue Feb 14 23:46:04 2017 Gregoire Renard
// Last update Tue Mar  7 10:59:47 2017 Gregoire Renard
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include "Parser.hpp"

int					Parser::rempChipsets(std::string &line,
							     nts::t_ast_node &root)
{
  static auto				it = root.children->begin();
  static int				tour = 0;

  if (tour == 0)
    setIt(".chipsets", it, root, tour);
  if ((setChipsets(it, line)) == -1)
    return (-1);
  return (0);
}

void					Parser::initChild(nts::t_ast_node &root,
							  std::string wanted)
{
  std::vector<nts::t_ast_node *>	*childTab = new std::vector<nts::t_ast_node*>;
  nts::t_ast_node			*child = new nts::t_ast_node(childTab);
  
  child->type = nts::ASTNodeType::SECTION;
  child->lexeme = wanted;
  child->value = wanted;
  root.children->push_back(child);
}

void					Parser::initNewChild(ITERATOR_S &it,
							     std::string const &news)
{
  std::vector<nts::t_ast_node *>	*childTab = new std::vector<nts::t_ast_node*>;
  nts::t_ast_node			*child = new nts::t_ast_node(childTab);

  child->type = nts::ASTNodeType::COMPONENT;
  child->lexeme = news;
  child->value = news;
  (*it)->children->push_back(child);
}

template<typename X>
int					Parser::checkParams(X &params)
{
  auto					it = params.begin();
  int					cpt;

  cpt = 0;
  while (it != params.end() && (*it)[0] != '#' && (*it) != "#")
    {
      cpt++;
      it++;
    }
  if (cpt != 2)
    return (-1);
  return (0);
}

void					Parser::setItChild(ITERATOR_S &it,
							   std::vector<std::string> &params,
							   std::string &tmp)
{
  auto					itParams = params.begin();
  auto					itChild = (*it)->children->begin();

  if ((*itParams) != "input" && (*itParams) != "output"
      && (*itParams) != "clock" && (*itParams) != "true"
      && (*itParams) != "false"&& tmp == "none")
    {
      tmp = (*itParams);
      (*itParams) = "process";
    }
  while (itChild != (*it)->children->end() &&
	 (*itChild)->lexeme != (*itParams))
    itChild++;
  if (itChild == (*it)->children->end())
    {
      initNewChild(it, *itParams);
      setItChild(it, params, tmp);
    }
}

static bool		       		my_strcmp(nts::t_ast_node *child1,
						  nts::t_ast_node *child2)
{
  std::string				str1;
  std::string				str2;
  int					ret;

  str1 = child1->lexeme;
  str2 = child2->lexeme;
  ret = strcmp(str1.c_str(), str2.c_str());
  if (ret < 0)
    return (true);
  else
    return (false);
}


int					Parser::rempChild(ITERATOR_S &it,
							  std::vector<std::string> &params,
							  std::string &tmp)
{
  nts::t_ast_node			*child = new nts::t_ast_node(NULL);
  auto					itParams = params.begin();
  ITERATOR_S				itChild = (*it)->children->begin();
  
  while (itChild != (*it)->children->end()
  	 && (*itChild)->lexeme != (*itParams))
    itChild++;
  itParams++;
  child->lexeme = (*itParams);
  itParams--;
  if ((*itChild)->lexeme == "input" || (*itChild)->lexeme == "clock")
    {
      if ((setValueChild(*child)) == -1)
	return (-1);
    }
  else if ((*itChild)->lexeme == "true")
    child->value = "1";
  else if ((*itChild)->lexeme == "false")
    child->value = "0";
  else if ((*itChild)->lexeme != "process")
    child->value = "0";
  else
    child->value = tmp;
  (*itChild)->children->push_back(child);
  if ((*itChild)->lexeme == "process")
    _cmpt->addComponent(_cmpt->createComponent(child->value, child->lexeme), child->lexeme);
  else
    {
      _cmpt->addComponent(_cmpt->createComponent((*itChild)->lexeme, child->lexeme),
			  child->lexeme);
      std::get<2>(dynamic_cast<nts::Processor *>(_cmpt->devices.find(child->lexeme)->second)->_listPin[1]) = (nts::Tristate)(std::stoi(child->value));
    }
  std::sort((*itChild)->children->begin(), (*itChild)->children->end(), my_strcmp);
  return (0);
}

int					Parser::setChipsets(ITERATOR_S &it,
							    std::string &line)
{
  std::vector<std::string>		params;
  std::string				tmp;

  tmp = "none";
  getParams(line, params);
  if ((checkParams(params)) == -1)
    {
      std::cout << "Error : bad synthax at line \"" << line << "\"" << std::endl;
      return (-1);
    }
  if ((checkDouble((*(params.begin() + 1)), it)) == -1)
    {
      std::cout << "Error : Multi-definition of \"" << (*(params.begin() + 1))
		<< "\"" << std::endl;
      return (-1);
    }
  if ((checkProcess(params)) == -1)
    {
      std::cout << "Error : bad type at line \"" << line << "\"" << std::endl;
      return (-1);
    }
  setItChild(it, params, tmp);
  if ((rempChild(it, params, tmp)) == -1)
    {
      std::cout << "Error : bad or no value for input \"" << (*(params.begin() + 1))
		<< "\"" << std::endl;
      return (-1);
    }
  return (0);
}
