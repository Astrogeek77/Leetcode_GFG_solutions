SELECT t.name,
IFNULL(SUM(t.distance), 0) AS "travelled_distance"
FROM 
(
    SELECT u.id,u.name,r.user_id,r.distance FROM Users 
    AS u LEFT JOIN Rides AS r ON u.id = r.user_id  
) 
AS t 
GROUP BY id
ORDER BY travelled_distance DESC,t.name ASC;