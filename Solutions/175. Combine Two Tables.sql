# Write your MySQL query statement below
SELECT p.firstname AS firstName, p.lastname AS lastName, a.city, a.state
FROM person p
LEFT JOIN address a ON p.personid = a.personid;
