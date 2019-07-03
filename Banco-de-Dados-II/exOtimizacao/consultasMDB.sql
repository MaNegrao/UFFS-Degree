1)(Consulta sem index) 

select d.first_name, a.last_name from directors d join actors a on a.first_name = d.last_name; (otimizada)

+------+-------------+-------+------+---------------------+---------------------+---------+-----------------------+--------+-----------+----------+------------+-------------+
| id   | select_type | table | type | possible_keys       | key                 | key_len | ref                   | rows   | r_rows    | filtered | r_filtered | Extra       |
+------+-------------+-------+------+---------------------+---------------------+---------+-----------------------+--------+-----------+----------+------------+-------------+
|    1 | SIMPLE      | a     | ALL  | NULL                | NULL                | NULL    | NULL                  | 813717 | 817718.00 |   100.00 |     100.00 | Using where |
|    1 | SIMPLE      | d     | ref  | directors_last_name | directors_last_name | 403     | trabalho.a.first_name |      1 |      3.38 |   100.00 |     100.00 |             |
+------+-------------+-------+------+---------------------+---------------------+---------+-----------------------+--------+-----------+----------+------------+-------------+
2 rows in set (3.062 sec)

select d.first_name, a.last_name from directors d join actors a on a.first_name = ((select d.last_name)); (não otimizada)

+------+--------------------+-------+------+-------------------+-------------------+---------+------+-------+----------+----------+------------+----------------+
| id   | select_type        | table | type | possible_keys     | key               | key_len | ref  | rows  | r_rows   | filtered | r_filtered | Extra          |
+------+--------------------+-------+------+-------------------+-------------------+---------+------+-------+----------+----------+------------+----------------+
|    1 | PRIMARY            | d     | ALL  | NULL              | NULL              | NULL    | NULL | 87248 | 86880.00 |   100.00 |     100.00 |                |
|    1 | PRIMARY            | a     | ref  | actors_first_name | actors_first_name | 403     | func |     4 |    31.78 |   100.00 |     100.00 | Using where    |
|    2 | DEPENDENT SUBQUERY | NULL  | NULL | NULL              | NULL              | NULL    | NULL |  NULL |     NULL |     NULL |       NULL | No tables used |
+------+--------------------+-------+------+-------------------+-------------------+---------+------+-------+----------+----------+------------+----------------+
3 rows in set (4.082 sec)

############################################################################################################################################################################################################################


2)(com index)

select genre, prob from directors_genres natural join movies_directors where prob < 1; (otimizada)


+------+-------------+------------------+------+--------------------------------------+---------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
| id   | select_type | table            | type | possible_keys                        | key     | key_len | ref                                   | rows   | r_rows    | filtered | r_filtered | Extra       |
+------+-------------+------------------+------+--------------------------------------+---------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
|    1 | SIMPLE      | directors_genres | ALL  | PRIMARY,directors_genres_director_id | NULL    | NULL    | NULL                                  | 156565 | 156562.00 |   100.00 |     100.00 | Using where |
|    1 | SIMPLE      | movies_directors | ref  | PRIMARY,movies_directors_director_id | PRIMARY | 4       | trabalho.directors_genres.director_id |      2 |     11.07 |   100.00 |     100.00 | Using index |
+------+-------------+------------------+------+--------------------------------------+---------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
2 rows in set (0.702 sec)


select genre, prob from directors_genres natural join movies_directors where prob in (select prob from directors_genres where prob < 1); (não otimizada)

+------+--------------+------------------+--------+--------------------------------------+--------------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
| id   | select_type  | table            | type   | possible_keys                        | key          | key_len | ref                                   | rows   | r_rows    | filtered | r_filtered | Extra       |
+------+--------------+------------------+--------+--------------------------------------+--------------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
|    1 | PRIMARY      | directors_genres | ALL    | PRIMARY,directors_genres_director_id | NULL         | NULL    | NULL                                  | 156565 | 156562.00 |   100.00 |     100.00 |             |
|    1 | PRIMARY      | <subquery2>      | eq_ref | distinct_key                         | distinct_key | 4       | func                                  |      1 |      0.55 |   100.00 |     100.00 |             |
|    1 | PRIMARY      | movies_directors | ref    | PRIMARY,movies_directors_director_id | PRIMARY      | 4       | trabalho.directors_genres.director_id |      2 |     18.34 |   100.00 |     100.00 | Using index |
|    2 | MATERIALIZED | directors_genres | ALL    | NULL                                 | NULL         | NULL    | NULL                                  | 156565 | 156562.00 |   100.00 |      55.10 | Using where |
+------+--------------+------------------+--------+--------------------------------------+--------------+---------+---------------------------------------+--------+-----------+----------+------------+-------------+
4 rows in set (0.674 sec)

############################################################################################################################################################################################################################


3) (sub consulta)
select name, year, rank from movies where rank = (select max(rank) from movies where year < 1990); (otimizada)
+------+-------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+-------------+
| id   | select_type | table  | type | possible_keys | key  | key_len | ref  | rows   | r_rows    | filtered | r_filtered | Extra       |
+------+-------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+-------------+
|    1 | PRIMARY     | movies | ALL  | NULL          | NULL | NULL    | NULL | 390324 | 388269.00 |   100.00 |       0.01 | Using where |
|    2 | SUBQUERY    | movies | ALL  | NULL          | NULL | NULL    | NULL | 390324 | 388269.00 |   100.00 |      10.17 | Using where |
+------+-------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+-------------+
2 rows in set (0.165 sec)

select name, year, rank from movies where rank = (select max((select rank)) from movies where year < 1990); (não otimizada)

+------+--------------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+----------------+
| id   | select_type        | table  | type | possible_keys | key  | key_len | ref  | rows   | r_rows    | filtered | r_filtered | Extra          |
+------+--------------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+----------------+
|    1 | PRIMARY            | movies | ALL  | NULL          | NULL | NULL    | NULL | 390324 | 388269.00 |   100.00 |       0.01 | Using where    |
|    2 | SUBQUERY           | movies | ALL  | NULL          | NULL | NULL    | NULL | 390324 | 388269.00 |   100.00 |      64.68 | Using where    |
|    3 | DEPENDENT SUBQUERY | NULL   | NULL | NULL          | NULL | NULL    | NULL |   NULL |      NULL |     NULL |       NULL | No tables used |
+------+--------------------+--------+------+---------------+------+---------+------+--------+-----------+----------+------------+----------------+
3 rows in set (0.188 sec)


