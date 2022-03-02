import lark
from lark.visitors import Transformer

#Regra terminal -> true, false null
#Regra nao terminal -> NUMBER, STRING : precisa de mais processamento.
# LETRA MAIUSCULA quer dizer nao terminal

# EBNF : forma extendida de barcs nau

grammar = r"""
start : value
?value : "true" -> true
    | "false"  -> false
    | "null"   -> null
    | array
    | object
    | NUMBER
    | STRING

array : "[" (value ("," value)*)? "]"

object : "{" (pair ("," pair)*)? "}"
pair : STRING ":" value

%import common.ESCAPED_STRING -> STRING
%import common.SIGNED_NUMBER -> NUMBER
"""
class JSONTransformer(lark.Transformer):
    def null(self,children):
        return None

    def false(self,children):
        return False

    def true(self,children):
        return True

    def NUMBER(self,st):
        return int(st)

    def STRING(self,children):
        return children[1:-1]

    def array(self,children):
        return children

    def object(self,children):
        return dict(children)

    def pair(self,children):
        return tuple(children)

    def start(self,children):
        return children[0]

parser = lark.Lark(grammar)

def loads(text:str) -> object:
    tree = parser.parse(text)
    transformer = JSONTransformer()
    tree = transformer.transform(tree)

    if hasattr(tree,'pretty'):
        return tree.pretty()
    return tree

print(loads("true"))
print(loads("false"))
print(loads("null"))
print(loads("42"))
print(loads('"lorem ipsum dolor met"'))
print(loads("[true,false,null,[1,2,3,[]]]"))
print(loads('{"ans":[true,false,null,[1,2,3,[]]]}'))
