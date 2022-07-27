SELECT title FROM stars
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = stars.movie_id
WHERE name = "Johnny Depp"
INTERSECT
SELECT title FROM stars
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = stars.movie_id
WHERE name = "Helena Bonham Carter";