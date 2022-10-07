SELECT name from people WHERE id IN (SELECT  people.id  FROM movies JOIN (stars JOIN people ON stars.person_id = people.id) ON movies.id = stars.movie_id
WHERE name = "Kevin Bacon" );