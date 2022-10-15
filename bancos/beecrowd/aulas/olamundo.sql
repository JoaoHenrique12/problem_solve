CREATE OR REPLACE FUNCTION olaMundo() RETURNS varchar AS $olaMundo$
DECLARE
  msg varchar := 'Olá, mundo !';
BEGIN
  return msg;
END;
$olaMundo$ LANGUAGE plpgsql;

select olaMundo();
