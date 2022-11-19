--1 查询每个员工的编号/姓名/工资/新工资=（原始工资上浮25%）
SELECT employee_id 编号,first_name||' '||last_name 姓名,salary 工资,salary*1.25 新工资 FROM employees;

--2 查询每个员工姓名，工资，奖金，实发工资（工资+奖金）
SELECT first_name||' '||last_name 姓名,salary 工资, FROM employees;

--3 查询每个员工所在的部门编号
SELECT department_id FROM employees;

--4 查询在90号部门员工的信息
SELECT * FROM employees WHERE department_id='90';

--5 查询90年以前入职的员工
SELECT * FROM employees WHERE hire_date<2018/05/31;

--6 查询所有不是50号部门的员工

--7 查询奖金为空的员工的信息/查询没有部门的员工

--8 查询奖金不为空的员工的信息

--9 查询工资在3000到5000之间的员工信息

--10 查询在95年到10年之间入职的员工信息

--11查询（101，102，103）以外的所有员工的信息

--12 查询部门为10，20，50的员工信息

--13 查询last_name是以S开头的所有员工信息

--14 查询last_name是以s结尾的所有员工的信息

--15 查询last_name是以M开头，并且第三个字母是u的员工信息

--16 查询email中包含EN的员工信息

--17 查询job_id 倒数第5个字符为是下划线的员工信息

--18 查询last_name中包含%的员工信息

--19 查询工资超过5000，并且last_name是以s结尾的员工

--20 查询部门是10，20以及没有部门的员工信息

--21 查询员工信息，按入职日期降序排列
