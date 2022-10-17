\i docker-entrypoint-initdb.d/data.sql

CREATE OR REPLACE FUNCTION atualiza_estoque() RETURNS TRIGGER as $$
DECLARE
  qtd int;
BEGIN
  select qtde_disponivel from Produto where cod_prod = NEW.cod_venda into qtd;

  IF (qtd < NEW.qtde_vendida) THEN
    raise exception 'Quantidade comprada maior que disponivel em estoque';
  ELSE
    UPDATE Produto SET qtde_disponivel = (qtd - NEW.qtde_vendida) where cod_prod = NEW.cod_venda;
  END IF;

  return NEW;

END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER t_atualiza_estoque
BEFORE INSERT ON ItensVenda
FOR EACH ROW EXECUTE FUNCTION atualiza_estoque();
