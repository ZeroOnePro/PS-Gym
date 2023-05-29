select datetime '시간'
from animal_ins 
where datetime = (select min(datetime)
                                from animal_ins)