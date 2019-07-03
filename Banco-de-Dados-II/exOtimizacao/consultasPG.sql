1) (Consulta sem index)
select d.first_name, a.last_name from directors d join actors a on a.first_name = d.last_name; (otimizada)

                                                             QUERY PLAN                                                             
------------------------------------------------------------------------------------------------------------------------------------
 Merge Join  (cost=116309.21..155954.29 rows=2478005 width=14) (actual time=1048.399..1834.191 rows=2661306 loops=1)
   Merge Cond: ((d.last_name)::text = (a.first_name)::text)
   ->  Sort  (cost=8541.89..8759.09 rows=86880 width=14) (actual time=107.348..120.251 rows=86880 loops=1)
         Sort Key: d.last_name
         Sort Method: external merge  Disk: 2176kB
         ->  Seq Scan on directors d  (cost=0.00..1414.80 rows=86880 width=14) (actual time=0.007..8.004 rows=86880 loops=1)
   ->  Materialize  (cost=107763.67..111852.26 rows=817718 width=14) (actual time=941.041..1345.453 rows=3188777 loops=1)
         ->  Sort  (cost=107763.67..109807.97 rows=817718 width=14) (actual time=941.039..1201.566 rows=817693 loops=1)
               Sort Key: a.first_name
               Sort Method: external merge  Disk: 20224kB
               ->  Seq Scan on actors a  (cost=0.00..13483.18 rows=817718 width=14) (actual time=0.054..77.864 rows=817718 loops=1)
 Planning Time: 0.463 ms
 Execution Time: 1904.339 ms
(13 rows)

select d.first_name, a.last_name from directors d join actors a on a.first_name = ((select d.last_name)); (não otimizada)

                                                             QUERY PLAN                                                             
------------------------------------------------------------------------------------------------------------------------------------
 Merge Join  (cost=116305.56..237626.05 rows=4718920 width=14) (actual time=1147.387..2180.634 rows=2661306 loops=1)
   Merge Cond: ((((SubPlan 1))::text) = (a.first_name)::text)
   ->  Sort  (cost=8541.89..8759.09 rows=86880 width=14) (actual time=129.911..153.396 rows=86880 loops=1)
         Sort Key: (((SubPlan 1))::text)
         Sort Method: external merge  Disk: 2848kB
         ->  Seq Scan on directors d  (cost=0.00..1414.80 rows=86880 width=14) (actual time=0.032..30.568 rows=86880 loops=1)
               SubPlan 1
                 ->  Result  (cost=0.00..0.01 rows=1 width=218) (actual time=0.000..0.000 rows=1 loops=86880)
   ->  Materialize  (cost=107763.67..111852.26 rows=817718 width=14) (actual time=1017.462..1541.378 rows=3188777 loops=1)
         ->  Sort  (cost=107763.67..109807.97 rows=817718 width=14) (actual time=1017.460..1354.000 rows=817693 loops=1)
               Sort Key: a.first_name
               Sort Method: external merge  Disk: 20224kB
               ->  Seq Scan on actors a  (cost=0.00..13483.18 rows=817718 width=14) (actual time=0.045..82.640 rows=817718 loops=1)
 Planning Time: 0.247 ms
 Execution Time: 2271.337 ms
(15 rows)




############################################################################################################################################################################################################################

2) (com index)
select genre, prob from directors_genres natural join movies_directors where prob < 1; (otimizada)

                                                                                  QUERY PLAN                                                                                   
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Merge Join  (cost=0.91..27209.37 rows=682011 width=15) (actual time=0.112..431.294 rows=1581876 loops=1)
   Merge Cond: (directors_genres.director_id = movies_directors.director_id)
   ->  Index Scan using directors_genres_director_id on directors_genres  (cost=0.42..5468.26 rows=85414 width=19) (actual time=0.016..32.559 rows=86260 loops=1)
         Filter: (prob < '1'::double precision)
         Rows Removed by Filter: 70302
   ->  Materialize  (cost=0.42..12226.07 rows=371180 width=4) (actual time=0.082..181.688 rows=1692574 loops=1)
         ->  Index Only Scan using movies_directors_director_id on movies_directors  (cost=0.42..11298.12 rows=371180 width=4) (actual time=0.074..74.090 rows=371176 loops=1)
               Heap Fetches: 371176
 Planning Time: 1.405 ms
 Execution Time: 485.419 ms
(10 rows)

select genre, prob from directors_genres natural join movies_directors where prob in (select prob from directors_genres where prob < 1); (não otimizada)

                                                                              QUERY PLAN                                                                               
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Hash Join  (cost=10776.76..52865.58 rows=1250112 width=15) (actual time=87.924..373.320 rows=1581876 loops=1)
   Hash Cond: (movies_directors.director_id = directors_genres.director_id)
   ->  Seq Scan on movies_directors  (cost=0.00..5354.80 rows=371180 width=4) (actual time=0.018..37.998 rows=371180 loops=1)
   ->  Hash  (cost=7901.74..7901.74 rows=156562 width=19) (actual time=87.234..87.234 rows=86260 loops=1)
         Buckets: 65536  Batches: 4  Memory Usage: 1680kB
         ->  Hash Join  (cost=3186.39..7901.74 rows=156562 width=19) (actual time=32.953..70.262 rows=86260 loops=1)
               Hash Cond: (directors_genres.prob = directors_genres_1.prob)
               ->  Seq Scan on directors_genres  (cost=0.00..2562.62 rows=156562 width=19) (actual time=0.010..11.833 rows=156562 loops=1)
               ->  Hash  (cost=3175.93..3175.93 rows=837 width=8) (actual time=32.913..32.913 rows=1812 loops=1)
                     Buckets: 2048 (originally 1024)  Batches: 1 (originally 1)  Memory Usage: 87kB
                     ->  HashAggregate  (cost=3167.56..3175.93 rows=837 width=8) (actual time=32.440..32.648 rows=1812 loops=1)
                           Group Key: directors_genres_1.prob
                           ->  Seq Scan on directors_genres directors_genres_1  (cost=0.00..2954.03 rows=85414 width=8) (actual time=0.012..18.334 rows=86260 loops=1)
                                 Filter: (prob < '1'::double precision)
                                 Rows Removed by Filter: 70302
 Planning Time: 0.717 ms
 Execution Time: 425.182 ms
(17 rows)

################################################################################################################################################################################


3) (sub consulta)
select name, year, rank from movies where rank = (select max(rank) from movies where year < 1990); (otimizada)

                                                                        QUERY PLAN                                                                        
----------------------------------------------------------------------------------------------------------------------------------------------------------
 Gather  (cost=8090.35..13886.77 rows=745 width=31) (actual time=36.602..56.016 rows=40 loops=1)
   Workers Planned: 1
   Params Evaluated: $1
   Workers Launched: 1
   InitPlan 1 (returns $1)
     ->  Finalize Aggregate  (cost=7090.34..7090.35 rows=1 width=8) (actual time=34.271..34.271 rows=1 loops=1)
           ->  Gather  (cost=7090.22..7090.33 rows=1 width=8) (actual time=34.177..34.310 rows=2 loops=1)
                 Workers Planned: 1
                 Workers Launched: 1
                 ->  Partial Aggregate  (cost=6090.22..6090.23 rows=1 width=8) (actual time=31.315..31.316 rows=1 loops=2)
                       ->  Parallel Seq Scan on movies movies_1  (cost=0.00..5721.92 rows=147322 width=8) (actual time=0.015..23.636 rows=125562 loops=2)
                             Filter: (year < 1990)
                             Rows Removed by Filter: 68572
   ->  Parallel Seq Scan on movies  (cost=0.00..5721.92 rows=438 width=31) (actual time=1.312..18.079 rows=20 loops=2)
         Filter: (rank = $1)
         Rows Removed by Filter: 194114
 Planning Time: 0.242 ms
 Execution Time: 56.131 ms
(18 rows)

select name, year, rank from movies where rank = (select max((select rank where rank > 0)) from movies where year < 1990); (não otimizada)

                                                             QUERY PLAN                                                              
-------------------------------------------------------------------------------------------------------------------------------------
 Gather  (cost=12477.08..18273.50 rows=745 width=31) (actual time=120.016..135.590 rows=40 loops=1)
   Workers Planned: 1
   Params Evaluated: $1
   Workers Launched: 1
   InitPlan 2 (returns $1)
     ->  Aggregate  (cost=11477.07..11477.08 rows=1 width=8) (actual time=118.073..118.074 rows=1 loops=1)
           ->  Seq Scan on movies movies_1  (cost=0.00..7720.36 rows=250447 width=8) (actual time=0.394..61.876 rows=251125 loops=1)
                 Filter: (year < 1990)
                 Rows Removed by Filter: 137144
           SubPlan 1
             ->  Result  (cost=0.00..0.01 rows=1 width=8) (actual time=0.000..0.000 rows=0 loops=251125)
                   One-Time Filter: (movies_1.rank > '0'::double precision)
   ->  Parallel Seq Scan on movies  (cost=0.00..5721.92 rows=438 width=31) (actual time=1.156..13.928 rows=20 loops=2)
         Filter: (rank = $1)
         Rows Removed by Filter: 194114
 Planning Time: 7.032 ms
 Execution Time: 135.801 ms
(17 rows)