SELECT  COUNT(DISTINCT(name))  FROM movies JOIN (directors JOIN people ON directors.person_id = people.id) ON movies.id = directors.movie_id
WHERE movies.id IN (SELECT movie_id FROM ratings WHERE (rating = 9 OR rating > 9));