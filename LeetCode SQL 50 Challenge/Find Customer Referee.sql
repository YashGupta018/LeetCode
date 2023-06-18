-- Active: 1686037786828@@127.0.0.1@3306@mysqldb

# Write your MySQL query statement below

SELECT name
FROM Customer
WHERE COALESCE(referee_id, 0) <> 2;
# COALESCE is used to replace NULL values to 0
# Before even checking weather it equal to 2 or not