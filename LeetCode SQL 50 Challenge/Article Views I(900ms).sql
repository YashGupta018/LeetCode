# Write your MySQL query statement below

SELECT DISTINCT author_id id
FROM Views WHERE author_id = viewer_id
ORDER BY author_id;