using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BFS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richTextBox1.Text = "1,1,0,0,1,0,0,0,1\n"+
                                "1,0,0,0,0,1,0,0,0\n"+
                                "0,0,0,1,0,0,1,1,0\n"+
                                "0,0,1,0,0,0,0,0,0\n"+
                                "0,0,0,0,0,1,0,0,1\n"+
                                "0,1,0,0,1,0,1,0,1\n"+
                                "0,0,1,0,0,1,0,1,0\n"+
                                "0,0,1,0,0,0,1,0,0\n"+
                                "1,0,0,0,1,1,0,0,0";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox2.Text = "";
            String s = richTextBox1.Text;
            String[] rows = s.Split('\n');
            List<Node> nodes = new List<Node>();
            int index = 0;
            foreach (string str in rows)
            {
                Node nn = new Node();
                nodes.Add(nn);
            }
            foreach (string str in rows)
            {
                String[] temp=str.Split(',');
                int i=0;
                foreach (string a in temp)
                {
                    if (Convert.ToInt32(a) == 1)
                    {
                        
                            if (nodes[index] != nodes[i])
                            {
                                nodes[index].komsular.Add(nodes[i]);
                            }
                        
                    }
                    i++;
                }
                nodes[index].number = index;
                index++;
            }
            BFS(nodes);
        }

        

        void BFS(List<Node> nodes)
        {
            List<int> queues = new List<int>();

            queues.Add(0);
            textBox1.Text = "A";
            textBox2.Text="A";
            nodes[0].ziyaret = 1;
            ////////////////////////////////////////////
            int yatay = 100;
            int dikey = 100;
            System.Drawing.Graphics graphicsObj;
            Font myFont = new System.Drawing.Font("Consolas", 25, FontStyle.Regular);
            Brush myBrush = new SolidBrush(System.Drawing.Color.Yellow);
            Brush myBrush2 = new SolidBrush(System.Drawing.Color.Gray);
            Brush myBrush3 = new SolidBrush(System.Drawing.Color.Black);
            Pen myPen = new Pen(System.Drawing.Color.White, 5);
            Pen myPen1 = new Pen(System.Drawing.Color.Yellow, 5);
            Pen myPen2 = new Pen(System.Drawing.Color.Green, 5);
            graphicsObj = this.CreateGraphics();
            graphicsObj.Clear(Color.YellowGreen);
            for (int i = 1; i <= nodes.Count; i++)
            {
                Rectangle myRectangle = new Rectangle(yatay, dikey, 40, 40);               
                graphicsObj.DrawEllipse(myPen, myRectangle);
                graphicsObj.DrawString(nodes[i - 1].ad(), myFont, myBrush, yatay, dikey);
                nodes[i - 1].p = new Point(yatay+20, dikey+20);
                yatay += 100;

                
                

                if ((i % 3) == 0)
                {
                    dikey += 150;
                    yatay = 100;
                }

                if ((i % 2) == 0)
                {
                    dikey -= 20;
                }
            }
            myPen.Color = Color.Gray;
            Rectangle myRectangle5 = new Rectangle(nodes[0].p.X-20, nodes[0].p.Y-20, 40, 40);
            graphicsObj.DrawEllipse(myPen, myRectangle5);
            
            Pen myPen4 = new Pen(System.Drawing.Color.Gold, 5);
            foreach (Node j in nodes)
            {
                foreach(Node k in j.komsular)
                {
                    graphicsObj.DrawLine(myPen4, j.p, k.p);
                    
                }
                
            }
            Brush myBrush4 = new SolidBrush(System.Drawing.Color.Black);
            Font myFont2 = new System.Drawing.Font("Consolas", 25, FontStyle.Bold);
            foreach (Node f in nodes)
            {
                graphicsObj.DrawString(f.ad(), myFont2, myBrush4, f.p.X - 20, f.p.Y - 20);
            }

            

            ////////////////////////////////////////////
            MessageBox.Show("Start!");
            while (queues.Count != 0)
            {
                for (int i = 0; i < nodes[queues[0]].komsular.Count; i++)
                {
                    if (nodes[queues[0]].komsular[i].ziyaret == 0)
                    {
                        queues.Add(nodes[queues[0]].komsular[i].number);
                        Rectangle myRectangle = new Rectangle(nodes[queues[0]].komsular[i].p.X - 20, nodes[queues[0]].komsular[i].p.Y - 20, 40, 40);
                        myPen.Color = Color.Gray;
                        graphicsObj.DrawEllipse(myPen, myRectangle);
                        nodes[queues[0]].komsular[i].ziyaret = 1;
                        richTextBox2.Text += nodes[queues[0]].ad() + " nodunun komşusu olan " + nodes[queues[0]].komsular[i].ad() + " keşfedildi!\n";
                        graphicsObj.DrawLine(myPen2, nodes[queues[0]].p, nodes[queues[0]].komsular[i].p);
                        foreach (Node f in nodes)
                        {
                            graphicsObj.DrawString(f.ad(), myFont, myBrush4, f.p.X - 20, f.p.Y - 20);
                        }

                        MessageBox.Show(nodes[queues[0]].ad() + " nodunun komşusu olan " + nodes[queues[0]].komsular[i].ad() + " keşfedildi!");
                        textBox2.Text += nodes[queues[0]].komsular[i].ad();
                        textBox1.Text += nodes[queues[0]].komsular[i].ad();
                    }
                    


                }
                nodes[queues[0]].ziyaret = 2;
                Rectangle myRectangle2 = new Rectangle(nodes[queues[0]].p.X-20, nodes[queues[0]].p.Y-20, 40, 40);
                queues.RemoveAt(0);
                myPen.Color = Color.Black;
                graphicsObj.DrawEllipse(myPen, myRectangle2);
                string ss=textBox1.Text;
                textBox1.Text = ss.Remove(0, 1);
            }
        }
    }
}
