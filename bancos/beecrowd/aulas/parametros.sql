\i docker-entrypoint-initdb.d/data.sql

CREATE OR REPLACE FUNCTION adicionaProfessor(id INTEGER, nome VARCHAR, dt_nasc DATE, salario NUMERIC) RETURNS void AS $adicionaProfessor$
BEGIN
  insert into professor values (id, nome, dt_nasc, salario);
END;
$adicionaProfessor$ LANGUAGE plpgsql;
