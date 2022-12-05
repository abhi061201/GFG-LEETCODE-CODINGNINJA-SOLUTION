CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
     
    select salary from (select * , dense_rank() over(order by salary desc) as rownum from Employee)temptable where temptable.rownum=N limit 1
  );
END