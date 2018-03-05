/*

			+ - / * 
	islmelerinin olabildigi ve hesaplamayi yapan
	
	OR : 
			infix				 yigin				postfix
	
	A * ( B + C ) * D  				
	  * ( B + C ) * D									A
	    ( B + C ) * D				*					A
	      B + C ) * D		 	   (*					A
	      	+ C ) * D									AB
	      	  C ) * D			  +(*					AB
	      	    ) * D			  			            ABC
	      	      * D			   (*					ABC+
	      	        D				*					ABC+*
	      	        D									ABC+*
	      	        D				*					ABC+*
	      	        				*					ABC+*D
	      	        				
	= ABC+*D*
	
	15 * ( 33 + 2 ) * 10 = 15 * 35 * 10 = 5250
	
	15,33,2,+,*,10,*
	
	15,33,2,+ --> 15,35
	
	15,35,* --> 525
	
	525,10,* --> 5250
	
	Operator yok Sonuc pop	
	// Butun Asamalar Tek Tek Gosterilecek...
	
	Operator gelinse 2 adet eleman cekilecek
	- ve / isaretlerinde ikinciden birinci seklinde olacak,
	+ ve * da direk islem yapilacak, sonuc push.
*/
