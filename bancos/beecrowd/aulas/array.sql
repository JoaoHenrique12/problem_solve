\i docker-entrypoint-initdb.d/data.sql

-- Retornar um array com as pessoas que fazem aniversario no mes solicitado.

CREATE OR REPLACE FUNCTION lista_aniversariantes(IN selected_month INTEGER) RETURNS INTEGER[] AS $$
DECLARE
  linha record;
  id_aniversariantes INTEGER[];
  i integer := 0;
BEGIN
 FOR linha in select id,dt_nasc from professor order by dt_nasc
  LOOP
    IF date_part('month',linha.dt_nasc) = selected_month THEN
      id_aniversariantes[i] := linha.id;
      i := i + 1;
    END IF;
  END LOOP;

  return id_aniversariantes;
END;
$$ language plpgsql;

-- Usando o array para pesquisa. 
-- select nome from professor where id in (select unnest( lista_aniversariantes ) from lista_aniversariantes(1));
