select animal_type, 
case when (name is NULL)
        then 'No name'
    else name
end as name, sex_upon_intake
from animal_ins