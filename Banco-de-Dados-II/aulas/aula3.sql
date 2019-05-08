1) 
CREATE TABLE emp (
 empname text,
 salary integer,
 last_date timestamp,
 last_user text
);

CREATE OR REPLACE FUNCTION emp_time() RETURNS trigger AS $$
 BEGIN
 NEW.last_date := current_timestamp;
 NEW.last_user := current_user;
 NEW.salary := NEW.salary * 1.1;
 RETURN NULL;
 END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER emp_time BEFORE INSERT OR UPDATE ON emp
 FOR EACH ROW EXECUTE PROCEDURE emp_time();

 insert into emp(empname, salary) values ('joao',1000);



2) CREATE OR REPLACE FUNCTION emp_time() RETURNS trigger AS $$
  BEGIN
  NEW.last_date := current_timestamp;
  NEW.last_user := current_user;
  NEW.salary := NEW.salary * 1.1;
  RETURN NEW;
  END;
 $$ LANGUAGE plpgsql;

 3)
CREATE TABLE emp (
 empname text,
 salary integer
);
CREATE TABLE emp_audit(
 operation varchar(1) ,
 stamp timestamp,
 username text ,
 empname text ,
 salary integer
);

CREATE OR REPLACE FUNCTION process_emp_audit() RETURNS TRIGGER
AS $$
 BEGIN
 IF (TG_OP = 'DELETE') THEN
 INSERT INTO emp_audit values ('D', now(), current_user, OLD.*);
 RETURN OLD;
 ELSIF (TG_OP = 'UPDATE') THEN
 INSERT INTO emp_audit SELECT 'U', now(), current_user, NEW.*;
 RETURN NEW;
 ELSIF (TG_OP = 'INSERT') THEN
 INSERT INTO emp_audit values ('I', now(), current_user, NEW.*);
 RETURN NEW;
 END IF;
 RETURN NULL;
 END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER emp_audit
AFTER INSERT OR UPDATE OR DELETE ON emp
 FOR EACH ROW EXECUTE PROCEDURE process_emp_audit();

select * from emp;

4-1)
CREATE TABLE empregado( id integer primary key, nome varchar(50), cpf varchar(15),
Num_Departamento integer, Salario DECIMAL(10,2 ), Supervisor
varchar(50));

CREATE TABLE auditoria(empregado_ID int, cpf CHAR(12), Num_Departamento integer,
Salario DECIMAL(10,2 ), Supervisor varchar(50) , evento int, usuario varchar,
date date);

CREATE OR REPLACE FUNCTION empregado_auditoria() RETURNS TRIGGER
AS $$
 BEGIN
 IF (TG_OP = 'DELETE') THEN
 INSERT INTO auditoria values (OLD.id, OLD.cpf, OLD.Num_Departamento, OLD.Salario, OLD.Supervisor, 3, current_user, now());
 RETURN OLD;
 ELSIF (TG_OP = 'UPDATE') THEN
 INSERT INTO auditoria values (NEW.id, NEW.cpf, NEW.Num_Departamento, NEW.Salario, NEW.Supervisor, 2, current_user, now());
 RETURN NEW;
 ELSIF (TG_OP = 'INSERT') THEN
 INSERT INTO auditoria values (NEW.id, NEW.cpf, NEW.Num_Departamento, NEW.Salario, NEW.Supervisor, 1, current_user, now());
 RETURN NEW;
 END IF;
 RETURN NULL;
 END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER empregado_auditoria
AFTER INSERT OR UPDATE OR DELETE ON empregado
 FOR EACH ROW EXECUTE PROCEDURE empregado_auditoria();

 5-2)
CREATE TABLE AvailableFlights(
	Num_flight int, 
    date date, 
    numberoffreeseats int, 
    price float);
    
CREATE TABLE Bookings(
	Num_flight int, 
    date date, 
    passenger int, 
    price float);
    
CREATE OR REPLACE FUNCTION fodepassageiro() returns trigger
AS $$
	DECLARE
    	a int;
    BEGIN    
	select numberoffreeseats into a from AvailableFlights;
    IF(a > 0) THEN
    	UPDATE AvailableFlights set numberoffreeseats = (a - 1) where Num_flight = Num_flight;
        UPDATE AvailableFlights set price = price + 50 where Num_flight = Num_flight;
        return NEW;
    ELSIF(a = 0) THEN
    	return NEW;
    END IF;
    return NULL;
END $$
language 'plpgsql';

CREATE TRIGGER coco after insert or update or delete on Bookings 
for each row execute procedure fodepassageiro();


insert into AvailableFlights values(1, now(), 200, 50);

insert into Bookings values( 1, now(), 1, 50);

6-3)
create table PageRevision(name_post varchar, data date, author varchar ,texto text, ultatu date);
create table PageAudit(name varchar,data date, dif_len int);


CREATE OR REPLACE FUNCTION editawiki() returns trigger as $$
	DECLARE
		a int;
		b int;
	BEGIN
		a = length(OLD.texto);
		b = length(NEW.texto);
		insert into PageAudit values(current_user, now(), b-a);
		NEW.ultatu = now();
	return NEW;
	END $$
language 'plpgsql';

create trigger edita before update on PageRevision for each row execute procedure editawiki();
