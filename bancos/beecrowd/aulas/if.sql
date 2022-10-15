\i docker-entrypoint-initdb.d/data.sql

CREATE OR REPLACE FUNCTION ganha_mais_media_salario(IN id_prof integer) RETURNS boolean AS $$
DECLARE
  media real;
  salario_prof numeric;
BEGIN
  select salario from professor where id = id_prof into salario_prof;
  select AVG(salario) from professor into media;

  IF salario_prof > media THEN
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END IF;
END;
$$ language plpgsql;
