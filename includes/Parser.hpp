//
// Parser.hpp for  in /home/renard_e/2/C++/cpp_nanotekspice/includes
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb  8 23:24:46 2017 Gregoire Renard
// Last update Fri Mar  3 15:53:35 2017 Gregoire Renard
//

#ifndef PARSER_HPP_
#define PARSER_HPP_

# include <iostream>
# include <fstream>
# include "Computer.hpp"
# include "cpp_nanotekspice_parser.hpp"

typedef std::vector<nts::t_ast_node*>::iterator ITERATOR_S;

class					Parser : public nts::IParser
{
public:
  virtual ~Parser();
  virtual void				feed(std::string const &imput);
  virtual void				parseTree(nts::t_ast_node &root);
  virtual nts::t_ast_node		*createTree();
  Parser();
  int					startLoopMain(char **argv);
private:
  void					setIt(std::string wanted, ITERATOR_S &it,
					      nts::t_ast_node &root, int &tour);
  void					setNext(std::string &line, int &cpt);
  std::string				checkSection(std::string &line);
  int					rempChipsets(std::string &line,
						    nts::t_ast_node &root);
  int					rempLinks(std::string &line,
						  nts::t_ast_node &root);
  void					initChild(nts::t_ast_node &root, std::string wanted);
  int					setChipsets(ITERATOR_S &it, std::string &line);
  void					getParams(std::string &line,
						  std::vector<std::string> &params);
  void					checkDot();
  template<typename X>
  int					checkParams(X &params);
  void					setItChild(ITERATOR_S &it,
						   std::vector<std::string> &params,
						   std::string &tmp);
  void					initNewChild(ITERATOR_S &it,
						     std::string const &news);
  int					rempChild(ITERATOR_S &it,
						  std::vector<std::string> &params,
						  std::string &tmp);
  void					printTree(nts::t_ast_node &root);
  int					pushLink(std::vector<std::string> &params,
						 ITERATOR_S &it);
  int					extractInfo(std::string &params,
						    std::vector<std::string> &line);
  int					checkDouble(std::string &name,
						    ITERATOR_S &it);
  int					setValueChild(nts::t_ast_node &child);
  int					getInput(char const *input,
						 std::vector<std::string> &params);
  int					startCommandLine(nts::t_ast_node &root);
  int					getLineFromCin(std::string &line);
  void					displayFunc(nts::t_ast_node &root);
  void					simulateFunc(nts::t_ast_node &root);
  void					loopFunc(nts::t_ast_node &root);
  void					dumpFunc(nts::t_ast_node &root);
  int					isInputValue(std::string &line);
  int					setValue(std::string &line, nts::t_ast_node &root);
  ITERATOR_S				searchInTree(nts::t_ast_node &root,
						     std::string section1,
						     std::string section2,
						     ITERATOR_S &itNeeded);
  int					testLine(std::string &line);
  int					testEOF(std::string &line);
  void					setLine(std::string &line);
  int					constructLine(std::string &line, int cpt);
  int					checkProcess(std::vector<std::string> &params);
  int					checkNameLink(std::vector<std::string> &params,
						      nts::t_ast_node &root);
  int					checkValid(std::vector<std::string> &params);
  int					searchNameInChipsets(nts::t_ast_node &root,
							     std::string &name,
							     std::string &pin,
							     std::vector<std::string> &tabType);
  int					searchSection(nts::t_ast_node &root,
						      std::string section,
						      ITERATOR_S &it,
						      ITERATOR_S &itRoot);
  int					checkAllLink(nts::t_ast_node &root);
  int					inversClock(nts::t_ast_node &root);
  std::ifstream				_file;
  std::vector<int>			_checkDot;
  int					_next;
  char					**_argv;
  Computer				*_cmpt;
  std::vector<std::string>		_outputLink;
  int					_sign;
};

#endif /* !PARSER_HPP_ */
