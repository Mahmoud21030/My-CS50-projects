SELECT  name  FROM movies JOIN (stars JOIN people ON stars.person_id = people.id) ON movies.id = stars.movie_id
WHERE year = 2004 ORDER BY birth ;