\i docker-entrypoint-initdb.d/data.sql

-- O tipo de uma tupla pode ser especificado de duas formas:
 -- var nome_tabela%ROWTYPE
 -- var RECORD

-- RECORD, generico e funciona ate para joins

-- Obtento do tipo especifico variavel tabela.atributo%TYPE

CREATE OR REPLACE FUNCTION list_professores() RETURNS void AS $$
DECLARE
  linha professor%ROWTYPE;
BEGIN
 for linha in select * from professor order by dt_nasc
  loop
    raise notice 'nome: %| idade: %| salario: %', linha.nome,AGE(linha.dt_nasc),
      linha.salario;
  end loop;

END;
$$ language plpgsql;
