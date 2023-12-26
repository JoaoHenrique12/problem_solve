-- https://www.postgresql.org/docs/current/sql-createtrigger.html
CREATE [ OR REPLACE ] [ CONSTRAINT ] TRIGGER name { BEFORE | AFTER | INSTEAD OF } { event [ OR ... ] }
    ON table_name
    [ FROM referenced_table_name ]
    [ NOT DEFERRABLE | [ DEFERRABLE ] [ INITIALLY IMMEDIATE | INITIALLY DEFERRED ] ]
    [ REFERENCING { { OLD | NEW } TABLE [ AS ] transition_relation_name } [ ... ] ]
    [ FOR [ EACH ] { ROW | STATEMENT } ]
    [ WHEN ( condition ) ]
    EXECUTE { FUNCTION | PROCEDURE } function_name ( arguments )


CREATE TRIGGER trigger_name
BEFORE INSERT ON table_name
FOR EACH ROW
EXECUTE FUNCTION trigger_function();


/*

CREATE TRIGGER view_insert
    INSTEAD OF INSERT ON my_view
    FOR EACH ROW
    EXECUTE FUNCTION view_insert_row();

*/
/*

Function: In PostgreSQL, a function is a named set of SQL and procedural statements that can accept parameters, perform actions, and return a value.
Functions are created using the CREATE FUNCTION statement.

CREATE OR REPLACE FUNCTION add_numbers(a INTEGER, b INTEGER)
RETURNS INTEGER AS
$$
BEGIN
  RETURN a + b;
END;
$$
LANGUAGE plpgsql;


*/

/*
Procedures: return VOID

CREATE OR REPLACE FUNCTION log_message(message TEXT)
RETURNS VOID AS
$$
BEGIN
  -- Perform actions (e.g., logging)
  INSERT INTO log_table(message) VALUES (message);
END;
$$
LANGUAGE plpgsql;
*/
