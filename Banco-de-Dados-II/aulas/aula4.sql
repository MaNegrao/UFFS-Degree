1)	create or replace temporary view teste AS select * from emp where salary > 1500;	

2)	create materialized view empre_audit as select e.nome, e.cpf, e.salario from empregado e, auditoria a where a.empregado_id = e.id;

3)	create materialized view empre_audit as select e.nome, e.cpf, e.salario from empregado e, auditoria a where a.empregado_id = e.id;
	Não é possivel inserir;

4)	A visão materialized serve para criar uma copia ou fazer backup dos dados, para atualizala deve se utilizar o refresh

5)	create table Projeto(codProj int, tipo int, descricao text)‏;
	create table ProjetoEmpregado(codProj int, codEmp int, dataInicial date, dataFinal date);
	create table Empregado(codEmp int, nome text, categoria text, salario float);
	Create view vProjetoAltoEscalao as   select e.codEmp, e.nome, e.salario, p.descricao 	from empregado e, projeto p, projetoEmpregado pe   where e.salario>10000 AND e.codEmp=pe.codEmp AND  pe.codProj=p.codProj
	grant select on vProjetoAltoEscalao to postgres;