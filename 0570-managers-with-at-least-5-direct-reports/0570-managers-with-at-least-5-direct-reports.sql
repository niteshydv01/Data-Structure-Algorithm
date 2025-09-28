SELECT e.name
FROM Employee e
LEFT JOIN Employee emp
  ON e.id = emp.managerId
GROUP BY e.id, e.name
HAVING COUNT(emp.id) >= 5;
