require 'pg'

begin

    con = PG.connect :dbname => 'aulas', :user => 'matheus'
    
    con.transaction do |con|
        
        con.exec "UPDATE Cars SET Price=30000 WHERE Id=1"
        con.exec "INSERT INTO Cars VALUES(10,'General Motors', 14000)"
        con.exec "INSERT INTO Cars VALUES(3,'Subaru',24144)"
    end
    
rescue PG::Error => e

	puts 'ROLLBACK'
    puts e.message

else
	puts 'COMMIT'
    
ensure

    con.close if con  
end