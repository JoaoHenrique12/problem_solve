\i docker-entrypoint-initdb.d/data.sql

CREATE OR REPLACE FUNCTION fatorial(IN n integer) RETURNS integer AS $$
DECLARE
  fat integer := 1;
  i integer := 2;
BEGIN
 for i in 1..n by 1 loop
    fat := fat*i;
  end loop;

  return fat;
END;
$$ language plpgsql;
