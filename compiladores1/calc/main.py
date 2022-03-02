import lark
import math
from lark.visitors import Transformer, InlineTransformer

grammar = r"""

?start : sum

?sum : sum "+" mul -> add
     | sum "-" mul -> sub
     | mul 

?mul : mul "*" pow -> mul
     | mul "/" pow -> div
     | pow 

?pow : pow "^" unary -> pow
     | unary 

?unary : "-" atom -> neg
       | "+" atom -> pos
       | atom

?atom : INT

INT : /[0-9]+/

%import common.WS_INLINE
%ignore WS_INLINE
"""
parser = lark.Lark(grammar)

class CalcTransformer(InlineTransformer):
    from operator import (
            add, sub, mul, truediv as div, pow, neg, pos
    )
    INT = int

    def pi(self):
        return math.pi

def loads(text:str) -> object:
    tree = parser.parse(text)
    transformer = CalcTransformer()
    tree = transformer.transform(tree)
    if hasattr(tree,'pretty'):
        print(tree.pretty())

    return tree

examples = [
        "2 + 3 + 5",
        "2 * 3 * 5",
        "2 ^ 3 ^ 1",
]

for doc in examples:
    print("In: ", repr(doc))
    print("Out: ",repr(loads(doc)))
