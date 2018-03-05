using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace BFS
{
    class Node
    {
        public int number;
        public List<Node> komsular=new List<Node>();
        public int ziyaret = 0;
        public Point p;

        public String ad()
        {
            if (number == 0)
            {
                return "A";
            }
            else if (number == 1)
            {
                return "B";
            }
            else if (number == 2)
            {
                return "C";
            }
            else if (number == 3)
            {
                return "D";
            }
            else if (number == 4)
            {
                return "E";
            }
            else if (number == 5)
            {
                return "F";
            }
            else if (number == 6)
            {
                return "G";
            }
            else if (number == 7)
            {
                return "H";
            }
            else if (number == 8)
            {
                return "I";
            }
            else
            {
                return number.ToString();
            }
        }
    }
}
