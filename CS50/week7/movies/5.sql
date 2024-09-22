SELECT title, rating
FROM movies
JOIN ratings ON movie_id = id
WHERE title LIKE "%Harry Potter%"
ORDER BY year DESC;
