create or replace function aumentaSalario() returns boolean as $$
		begin
			update dados set salary = salary * 1.1;	
			return FOUND;
		end; $$ LANGUAGE plpgsql;

create or replace function aumentaPorcentagem(ident int, p float) returns boolean as $$
		begin
			p = p / 100;
			update dados set salary = salary + salary * p where dados.id = ident;	
			return FOUND;
		end; $$ LANGUAGE plpgsql;

create or replace function addusuario() returns boolean as $$
		begin
			update dados set usuario = "current_user" and data = current_date;	
			return FOUND;
		end; $$ LANGUAGE plpgsql;

create or replace function aumentodefinitivo(ident int, p float) returns boolean as $$
		begin
			p = p / 100;
			update dados set salary = salary + salary * p where dados.id = ident;
			select addusuario(ident);	
			return FOUND;
		end; $$ LANGUAGE plpgsql;				