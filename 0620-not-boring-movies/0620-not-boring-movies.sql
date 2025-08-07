# Write your MySQL query statement below
#select id,description,rating from Cinema where id/2=1 && description <> 'boring' ;
SELECT id, movie, description, rating
FROM Cinema
WHERE id % 2 = 1
  AND description <> 'boring'
ORDER BY rating DESC;
