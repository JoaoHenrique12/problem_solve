import lark
from lark.visitors import Transformer
from pprint import pprint

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

def lex(src:str) -> list:
    return list(parser.lex(src))

examples = [
    "true",
    "false",
    "null",
    "42",
    '"lorem ipsum dolor met"',
    "[true,false,null,[1,2,3,[]]]",
    '{"ans":[true,false,null,[1,2,3,[]]]}']

for doc in examples:
    print("In: ", repr(doc))
    pprint(lex(doc))
