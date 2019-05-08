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