SELECT  title  FROM movies JOIN (stars JOIN people ON stars.person_id = people.id) ON movies.id = stars.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman" ORDER BY ratings.rating LIMIT 5;