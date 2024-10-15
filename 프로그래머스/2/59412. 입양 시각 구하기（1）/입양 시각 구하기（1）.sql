select hour(datetime) hour, count(datetime) count
from animal_outs
where hour(datetime) >= 9 and hour(datetime) <= 19
group by hour(datetime)
order by hour(datetime)