SELECT title FROM stars
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = stars.movie_id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;