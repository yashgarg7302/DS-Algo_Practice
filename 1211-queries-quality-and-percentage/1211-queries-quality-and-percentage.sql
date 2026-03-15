# Write your MySQL query statement below
SELECT query_name, 
    ROUND((SUM(qual) / COUNT(*)), 2) AS quality, 
    ROUND((SUM(poor) / COUNT(*) * 100), 2) AS poor_query_percentage
FROM (
    SELECT *,
        rating / position AS qual,
        CASE WHEN rating < 3 THEN 1 ELSE 0 END AS poor
    FROM queries
) AS a
WHERE query_name IS NOT NULL
GROUP BY query_name;