//
// cpp_nanotekspice_parser.hpp for  in /home/renard_e/2/C++/cpp_nanotekspice/includes
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb  8 22:23:12 2017 Gregoire Renard
// Last update Tue Feb 14 07:00:04 2017 Gregoire Renard
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP_
#define CPP_NANOTEKSPICE_PARSER_HPP_

# include <string>
# include <vector>

namespace				nts
{
  enum class				ASTNodeType : int
  {
    DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      LINK,
      LINK_END,
      STRING
      };
  
  typedef struct			s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children)
      : children(children) {}
    ASTNodeType				type;
    std::string				lexeme;
    std::string				value;
    std::vector<struct s_ast_node*>	*children;
  }					t_ast_node;
  
  class					IParser
  {
  public:
    virtual ~IParser() {}
    virtual void			feed(std::string const& input) = 0;
    virtual void			parseTree(t_ast_node& root) = 0;
    virtual t_ast_node			*createTree() = 0;
  };
}

#endif /* !CPP_NANOTEKSPICE_PARSER_HPP_ */
