select name from Customer where id not in
(select id from Customer where referee_id =2)