# Init stage.

Esquema -> Definicao do banco. Metadados.

Three-Schema Architecture.

- Multiplas visoes para usuarios.
- Armazenamento da descricao da base de dados em diferentes niveis de abstracao.
- Independencia de dados.

# Modelo do banco

- Esquema Conceitual
- Esquema Logico
- Esquema Fisico

## Esquema Fisico

- Tempo de resposta
- Espaco utilizado
- Numero de transacoes

# MER & MER-X

## Entidades Fracas

Geralmente nao possuem chave primaria, mas usam um atributo para complementar a chave da entidade forte.
![fraca](images/entidade_fraca.png)


## Relacionamento Ternario

![ternario](images/ternario.png)

E possivel quebrar o ternario em binarios, mas a semantia e o processamento das operacoes pode ser prejudicada.

![ternario](images/ternario_quebrado_em_binarios.png)

Eles tambem podem ter auto relacionamentos.

![ternario](images/ternario_auto_relacionamento.png)

Ternario complexo.

![ternario](images/ternario_infernal.png)

## Abstracao de Agregacao.

Geralmente acontece quando vc quer relacionar um relacionamento a outras entidades. Ou quando o Conjunto de Relacionamentos tem um identificador proprio. 

![abstracao](images/abstracao_agregacao.png)

A semantica pode ser alterada totalmente, dependendo de onde e colocado o atributo. 
![abstracao](images/livro_texto_semantica.png)

# Generalizacao & Especializacao.

Especializacao com Restricao de 
- Disjuncao: Disciplina so pode ser de graduacao ou pos-graduacao. (D)
- Sobreposicao\[Overlap\]: um funcionario pode acumular mais de uma funcao ao mesmo tempo.(O)
- Especializacao Total: Qualquer disciplina e de pelomenos um tipo. (||)
- Especializacao Parcial: quando existe entidade que nao especializa. (|)

T, P -> total, parcial.
E,S -> exclusica, sobreposta.

![triangulos](images/exemplo_triangulos.png)
![especializar](images/quando_especializar.png)
![especializar](images/heranca_multipla.png)

# Modelo relacional

Relation Intension -> esquema, metadados.
Relation Extension -> instancias do banco.

Valores ATOMICOS: indivisivel, monovalorado.

Super chave: identifica de forma unica a tupla. Mais de um atributo.

Chave candidata: candidata a primaria.

Dominio do atributo:
- Nome.
- Definicao logica.
- Tipo de dado e formato. -> string com tres letras seguidas de um traco e de quatro digitos: FGA-0137

Grau -> numero de atributos.
Dom(Ai) -> dominio do atributo.
## Restricoes
- Dominio
- null para atributo
- unicidade( CHAVE )

Restricao de integridade da entidade: PK nao nula.
Restricao de integridade referencial: FK deve ser compativel.
# Normalizacao

## 1FN

- Atributos Atomicos, ou seja os multivalorados viram uma tabela.

## 2FN

Existe uma tabela com colunas que seriam de duas ou mais tabelas, e as chaves compostas podem indicar as novas tabelas.
Essa normalizacao fala se a sua tabela ta 'grande' de mais e armazenando valores que provavelmente vao ficar null em algum momento.
Solucao: quebrar esta tabela em 2 ou mais.

- Baseado no conceito de dependencia funcional total.
- Cada atributo nao chave depende da PK da relacao.
- Se houver dependencia parcial, cria uma tabela nova com os dados.

## 3FN

- Baseado no conceito de dependencia transitiva.
- Acontece quando um atributo nao chave e determinado por outro atributo nao chave (ou conjunto).

Exemplo: 

tbl\_venda {notaFiscal,codVendedor,nomeVendedor,codProduto,qtdeVendida}

Nome do vendedor depente tambem de codigo do vendedor, entao joga eles numa tabela e deixa na
tabela atual so o codVendedor.

## FNBC

- Duas ou mais chaves candidatas.
- Chaves candidatas sao compostas.
- Elas tem superposicao de atributos.
