1)create or replace table cliente(numero int primary key, cpf varchar(15), nome varchar(50));

begin;
	insert into cliente values (1, '42284870', 'matheus');
	insert into cliente values (2, '15643245', 'isabeli');
	insert into cliente values (3, '19412412', 'joao');
	insert into cliente values (5, '19412', 'pedro');		
end;


2)create table cliente(numero int primary key, cpf int, nome varchar(50));

begin;
	insert into cliente values (1, 42282434870, 'matheus');
	insert into cliente values (2, 12345643245, 'isabeli');
	insert into cliente values (3, 19412412412, 'joao');	
end;


3)

begin;
insert into cliente values (5, '19412', 'pedro');	

select * from cliente;

4)create table cliente2(numero int, cpf int, nome varchar(50));

begin;
	insert into cliente2 values (1, 42234870, 'matheus');
	insert into cliente2 values (1, 12343245, 'isabeli');
	insert into cliente2 values (1, 12412412, 'joao');	
end;x