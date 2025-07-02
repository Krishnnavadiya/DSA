CREATE TABLE Customer (
    id INTEGER PRIMARY KEY,
    name TEXT,
    referee_id INTEGER
);
INSERT INTO Customer (id, name, referee_id)
VALUES (1, 'Will', NULL),
    (2, 'Jane', NULL),
    (3, 'Alex', 2),
    (4, 'Bill', NULL),
    (5, 'Zack', 1),
    (6, 'Mark', 2);

-- 584. Find Customer Referee

SELECT name
FROM Customer
WHERE referee_id IS NULL
    OR referee_id != 2;