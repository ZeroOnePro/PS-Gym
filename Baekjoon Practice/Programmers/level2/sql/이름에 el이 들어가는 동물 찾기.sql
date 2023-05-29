-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME  like '%el%' and ANIMAL_TYPE = 'Dog'
order by NAME;