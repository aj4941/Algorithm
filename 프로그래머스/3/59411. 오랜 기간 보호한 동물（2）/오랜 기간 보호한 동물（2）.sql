select ins.animal_id, ins.name
from animal_ins ins
left join animal_outs outs
on ins.animal_id = outs.animal_id
where outs.animal_id is not null
order by datediff(outs.datetime, ins.datetime) desc limit 2 
