select id, (
        case 
            when p_id is NULL then 'Root'
            when id in (select p_id from Tree) then 'Inner'
            else 'Leaf' 
        end
    )
    as type
    from Tree
    order by id;
