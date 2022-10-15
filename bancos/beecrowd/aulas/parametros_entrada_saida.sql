\i docker-entrypoint-initdb.d/data.sql

-- Quando vc usa os parametros OUT, IN, INOUT. 
-- Pode colocar RETURNS record ou omitir o RETURNS.
CREATE OR REPLACE FUNCTION min_avg_max(OUT menor numeric, OUT media numeric, OUT maior numeric) RETURNS record AS $$
BEGIN
  select min(salario) from professor into menor;
  select round(avg(salario),2) from professor into media;
  select max(salario) from professor into maior;
END;
$$ LANGUAGE plpgsql;
