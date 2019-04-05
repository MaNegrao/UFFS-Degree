require 'pg'

begin

    con = PG.connect :dbname => 'aulas', :user => 'matheus'
    
    con.transaction do |con|
        
        con.exec "UPDATE Cars SET Price=23700 WHERE Id=8"
        con.exec "INSERT INTO Cars VALUES(9,'Mazda',27770)"
    
    end
    
rescue PG::Error => e

	puts 'ROLLBACK'
    puts e.message

else
	puts 'COMMIT' 
    
ensure

    con.close if con   
end