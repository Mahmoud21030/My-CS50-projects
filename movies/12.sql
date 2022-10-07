SELECT  title ,name FROM movies JOIN (stars JOIN people ON stars.person_id = people.id) ON movies.id = stars.movie_id
WHERE people.name = "Johnny Depp" AND people.name = "Helena Bonham";