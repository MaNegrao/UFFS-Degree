CREATE or REPLACE FUNCTION somefunc() RETURNS void AS $$
DECLARE
	quantity integer := 30;
	BEGIN
		RAISE NOTICE 'A quantidade é %', quantity;
	END; $$

LANGUAGE plpgsql;


create table dados (name varchar(50), salary float, id int);
	insert into dados (name, salary, id) values ('matheus', 15098, 34);

create function selecionar (p_itermo int)
	RETURNS TABLE (name varchar(50), salary float) AS $$
	BEGIN
		RETURN QUERY SELECT s.name, s.salary FROM dados s WHERE s.id = p_itermo;
	END;
	$$ LANGUAGE plpgsql;



create function incrementa (num int)
	RETURNS int as $$
	DECLARE num2 int;
	BEGIN
		num2 = num + 1;
		return (num2);
	END;
	$$ LANGUAGE plpgsql;
