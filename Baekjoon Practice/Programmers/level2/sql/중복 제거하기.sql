-- 코드를 입력하세요
SELECT count(distinct NAME) as count
from animal_ins
where name <> 'NULL';