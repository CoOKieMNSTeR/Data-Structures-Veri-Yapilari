import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;

import javax.swing.BorderFactory;
import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.Border;
class AVLTree{
	//Muhammed Said BAKIRCI --16010011029
	
	class Node{
		int N;
		int height=0;
		Node parent=null,left=null,right=null;
		Node(int n,int h,Node P){
			N=n;
			height=h;
			parent=P;
		}
	}

	Node root=null;
	void insert(int N,Node R){
		if(root==null)
			root=new Node(N,1,null);
		else{
			if(N<=R.N){
				if(R.left==null){
					R.left=new Node(N,1,R);
					dobalance(R.left);
				}else
					insert(N,R.left);
			}else{
				if(R.right==null){
					R.right=new Node(N,1,R);
					dobalance(R.right);
				}else
					insert(N,R.right);
			}
		}
	}
	
	void remove(Node x){
		Node y,z=null;
		if(x.left==null || x.right==null)	//en az bir çocuk
			y=x;
		else{								//varisi bulma alt aðçtan
			Node temp=x;
			for(y=temp.parent;y!=null && temp==y.right;y=y.parent){
				temp=y;				
			}
		}									//hem çocuðu var hem de çocuðu yok durumu

	//en fazla bir çocuðu var ise
		if(y.left!=null)
			z=y.left;
		else
			z=y.right;
			
		if(z!=null)							
			z.parent=y.parent;
		
		if(y.parent==null)					//z root olur
			root=z;
		else{								//y silinir
			if(y==y.parent.left)			//y sola kayar
				y.parent.left=z;	
			else
				y.parent.right=z;			//y saða kayar
		}
		x.N=y.N;							//y'yi x'e kopyalama
		y.height=0;
		
		do{
			y=dobalance(y);
		}while(y!=null);						//köke kadar dengelemek
	}
/************
	Silme veya ekleme iþleminden sonra AVL aðaç haline getirme
	iþlemi	(Dengeleme)					***********/
	Node dobalance(Node x){
		int h1=0,h2=0;						//burada h1 x yüksekliði, h2 x`in kardeþinin yüksekliði
		Node n1=null,rent=null;
		Node y=x,z;
		while(y.parent!=null){
			if(y.parent.left==y) n1=y.parent.right;
			else if(y.parent.right==y) n1=y.parent.left;
			h1=y.height;
			if(n1==null)
				h2=0;			
			else
				h2=n1.height;
			if(Math.abs(h2-h1)>1)								
				break;
			y.parent.height=1+Math.max(h1,h2);
			y=y.parent;
		}
		
		if(y.parent==null) 
			return null;		

		z=y.parent;
		rent=z;		
	/*z'yi y'ye ve y'yi x'e baðlar.Kardeþler arasýndaki boy  y ve x maksimuma sahiptir
	*/
		h1=(z.left==null)?0:z.left.height;
		h2=(z.right==null)?0:z.right.height;
		if(h1<h2)
			y=z.right;
		else
			y=z.left;

		h1=(y.left==null)?0:y.left.height;
		h2=(y.right==null)?0:y.right.height;
		if(h1<h2)
			x=y.right;
		else
			x=y.left;
		
		y.parent=z; 
		x.parent=y;		

	//aðaç dengelemek için gerekli rotasyon türünü bulma
		if(z.left==y){
			if(y.left==x)
				Rrotation(y,z);		//L-L rotation
			else{
				Lrotation(x,y);		//L-R rotation
				x.height++;
				Rrotation(x,z);			
			}		
		}else{
			if(y.right==x){
				Lrotation(y,z);		//R-R rotation
			}else{
				Rrotation(x,y);		//R-L rotation
				x.height++;
				Lrotation(x,z);
			}
		}
		
		return rent;
	}
	
/*************
	Saða Düzenleme iþlemi
																		***********/
	void Rrotation(Node y,Node z){
	//y'yi orijinal ebeveyniyle baðlama
		y.parent=z.parent;
		if(y.parent==null)
			root=y;
		else if(y.parent.left==z)
			y.parent.left=y;
		else
			y.parent.right=y;

	//Ayarlama b/w y n z
		z.left=y.right;
		if(z.left!=null)
			z.left.parent=z;
		y.right=z;
		z.parent=y;
		z.height--;
	}

/*************
	Sola Düzennleme Ýþlemi
																		***********/
	void Lrotation(Node y,Node z){
	//y'yi orijinal ebeveyniyle baðlama
		y.parent=z.parent;
		if(z.parent==null)
			root=y;
		else if(z.parent.left==z)
			y.parent.left=y;
		else
			y.parent.right=y;

	//rotation b/w x n y
		z.right=y.left;
		if(z.right!=null)
			z.right.parent=z;
		y.left=z;
		z.parent=y;		
		z.height--;
	}

	
/************
	Agacda Kök'ü arama iþlemi
						**********/
	Node search(int N,Node r){
		if(r==null) return null;
		if(N==r.N)
			return r;
		else if(N<r.N)
			return search(N,r.left);
		else 
			return search(N,r.right);
	}
	
	static AVLTree B;
	public static void main(String[] args){
		B=new AVLTree();
		new Main();
	}			
			
			
	/**** Grahpics ve GUI sýnýflarý ***/
	static class Main extends JFrame implements ActionListener{
		/**
		 * 
		 */
		

		public Main(){
			this.setSize(500,200);
			this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			this.setLocationRelativeTo(null);
			this.setTitle("AVL Tree");
			panel1 = new JPanel();
		/*************buttonlar******/
			button0 = new JButton("Ekle"); 
			button1 = new JButton("Bul");
			button2 = new JButton("Sil");
			button3 = new JButton("Agacý Göster");
			button0.addActionListener(this); 
			button1.addActionListener(this);
			button2.addActionListener(this);
			button3.addActionListener(this);
			panel1.add(button0);
			panel1.add(button1);
			panel1.add(button2);
			panel1.add(button3);
			
			Border b = BorderFactory.createEmptyBorder(45,0,0, 0);
			panel1.setBorder(b);	
			this.add(panel1);			
			this.setVisible(true);	
		}
		JPanel panel1;
		private JButton button0,button1,button2,button3;

		public void actionPerformed(ActionEvent e){		
			if (e.getSource() == button0){
				String s=JOptionPane.showInputDialog("Lütfen Sayý giriniz");
				int i=Integer.parseInt(s);
				B.insert(i,B.root);
			}else if(e.getSource() == button1){
				String s=JOptionPane.showInputDialog("Lütfen Sayý giriniz");
				int i=Integer.parseInt(s);
				if(B.search(i,B.root)==null)
					JOptionPane.showMessageDialog(null,"Bulunamadý");
				else
					JOptionPane.showMessageDialog(null,"Bulundu");
			}else if(e.getSource() == button2){
				String s=JOptionPane.showInputDialog("Lütfen Sayý giriniz");
				int i=Integer.parseInt(s);
				Node temp=B.search(i,B.root);
				if(temp==null)
					JOptionPane.showMessageDialog(null,"Bulunamadý");
				else{
					B.remove(temp);
					JOptionPane.showMessageDialog(null,"Silindi");
				}
			}else if(e.getSource() == button3){
				JFrame f = new JFrame("AVL Tree");
				f.addWindowListener(new WindowAdapter() {
					public void windowClosing(WindowEvent e) { }
				});
				Drawtree applet = new Drawtree();
				f.getContentPane().add("Center", applet);
				Toolkit tk = Toolkit.getDefaultToolkit();  
				int xSize = ((int) tk.getScreenSize().getWidth()); 
				applet.init(B.root,xSize-50);
				f.pack();
				f.setSize(new Dimension(xSize,500));
				f.setVisible(true);
			}
		}
	}
	
/************
	2D grafik kütüphanesi ile Agacý çiziyoruz
									******************/
static class Drawtree extends JApplet {
	/**
	 * 
	 */
	
	final  Color bg = Color.white;
	final  Color fg = Color.black;
    final  Color red = Color.red;
    final  Color white = Color.white;
    final  BasicStroke stroke = new BasicStroke(2.0f);
    final  BasicStroke wideStroke = new BasicStroke(8.0f);

    Dimension totalSize;
	int height,width;
	Node r=null;
	public void init(Node N,int x) {
		//Çizim renklerini ayarlýyorum
		setBackground(bg);
		setForeground(fg);
		r=N;
		width=x;
	}
	Graphics2D g2;
        

    public void paint(Graphics g) {
		g2=  (Graphics2D) g;
		
        getSize();
        inorder(r,0,width,80);
    }
	
	public void draw(int x1,int x2,int y,String n,int d){
	g2.setStroke(stroke);

	g2.setPaint(Color.black);
	int x=(x1+x2)/2;
	if(d==1)
		g2.draw(new Line2D.Double(x2, y-30, x+15, y));
	else if(d==2)
		g2.draw(new Line2D.Double(x+15, y,x1+30 , y-30));
	g2.setPaint(Color.blue);
	Shape circle=new Ellipse2D.Double((x1+x2)/2,y, 30, 30);
        g2.draw(circle);
	g2.fill(circle);
	g2.setPaint(Color.white);
        g2.drawString(n, x+10, y+18);
	}

	int x1=500,y1=30;
	void inorder(Node r,int x1,int x2,int y){
		if(r==null) return;
			
			inorder(r.left,x1,(x1+x2)/2,y+40);
			if(r.parent==null) draw(x1,x2,y,r.N+"",0);
			else{
				if(r.parent.N<r.N)	draw(x1,x2,y,r.N+"",2);	
				else			draw(x1,x2,y,r.N+"",1);	
			}	
			inorder(r.right,(x1+x2)/2,x2,y+40);
	}
}

}