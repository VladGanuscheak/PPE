using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

using System.Windows.Forms;

namespace lab6
{
    public partial class Form1 : Form
    {
        int val1, val2, val3;
        int? temp1 = null;
        int? temp2 = null;
        int? temp3 = null;

        static bool computerTern(ref int val1, ref int val2, ref int val3)
        {
            if (val2 > 0 && val3 > 0)
            {
                for (int i = 0; i < val1; i++)
                {
                    int v = i ^ val2 ^ val3;
                    if (v == 0)
                    {
                        val1 = i;
                        return true;
                    }
                }
            }

            if (val1 > 0 && val3 > 0)
            {
                for (int i = 0; i < val2; i++)
                {
                    int v = val1 ^ i ^ val3;
                    if (v == 0)
                    {
                        val2 = i;
                        return true;
                    }
                }
            }

            if (val1 > 0 && val2 > 0)
            {
                for (int i = 0; i < val3; i++)
                {
                    int v = val1 ^ val2 * i;
                    if (v == 0)
                    {
                        val3 = i;
                        return true;
                    }
                }
            }

            if (val2 > 0 && val3 == 0)
            {
                for(int i = 0; i < val1; i++)
                {
                    int v = i ^ val2;
                    if (v == 0)
                    {
                        val1 = i;
                        return true;
                    }
                }
            }

            if (val2 == 0 && val3 > 0)
            {
                for (int i = 0; i < val1; i++)
                {
                    int v = i ^ val3;
                    if (v == 0)
                    {
                        val1 = i;
                        return true;
                    }
                }
            }

            if (val1 > 0 && val3 == 0)
            {
                for(int i = 0; i < val2; i++)
                {
                    int v = i ^ val1;
                    if (v == 0)
                    {
                        val2 = i;
                        return true;
                    }
                }
            }

            if (val1 == 0 && val3 > 0)
            {
                for (int i = 0; i < val2; i++)
                {
                    int v = i ^ val3;
                    if (v == 0)
                    {
                        val2 = i;
                        return true;
                    }
                }
            }

            if (val1 > 0 && val2 == 0)
            {
                for (int i = 0; i < val3; i++)
                {
                    int v = i ^ val1;
                    if (v == 0)
                    {
                        val3 = i;
                        return true;
                    }
                }
            }

            if (val1 == 0 && val2 > 0)
            {
                for (int i = 0; i < val3; i++)
                {
                    int v = i ^ val2;
                    if (v == 0)
                    {
                        val3 = i;
                        return true;
                    }
                }
            }

            Random rnd = new Random();
            int ind;
            if (val1 == val2 && val2 == val3 && val3 == 0)
            {
                return false;
            }
            if ((val1 == val2 && val1 == 0) ||
                (val1 == val3 && val1 == 0) ||
                (val2 == val3 && val2 == 0))
            {
                val1 = val2 = val3 = 0;
                return true;
            }

            while (true)
            {
                ind = rnd.Next(1, 4);
                if ((ind == 1 && val1 > 0) || 
                    (ind == 2 && val2 > 0) || 
                    (ind == 3 && val3 > 0))
                {
                    break;
                }
            }
            switch(ind)
            {
                case 1:
                    {
                        int newVal = rnd.Next(0, val1);
                        val1 = newVal;
                        break;
                    }
                case 2:
                    {
                        int newVal = rnd.Next(0, val2);
                        val2 = newVal;
                        break;
                    }
                case 3:
                    {
                        int newVal = rnd.Next(0, val3);
                        val3 = newVal;
                        break;
                    }
            }
            return true;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new System.Drawing.Size(998, 650);
            this.MaximumSize = new System.Drawing.Size(998, 650);
            Random rnd = new Random();
            while (true)
            {
                val1 = rnd.Next(1, 10);
                val2 = rnd.Next(1, 10);
                val3 = rnd.Next(1, 10);
                if (val1 + val2 + val3 > 5)
                {
                    break;
                }
            }
            bt4.Text = val1.ToString();
            bt5.Text = val2.ToString();
            bt6.Text = val3.ToString();
        }

        private void bt4_Click(object sender, EventArgs e)
        {
            if (temp1 == null)
            {
                temp1 = val1;
            }
            if (temp1 > 0)
            {
                temp1--;
            }
            else
            {
                temp1 = val1;
            }
            bt4.Text = temp1.ToString();
        }

        private void bt1_Click(object sender, EventArgs e)
        {
            if (temp1 != val1 && temp1 != null)
            {
                temp2 = val2;
                temp3 = val3;
                bt5.Text = temp2.ToString();
                bt6.Text = temp3.ToString();
                bt4.Text = temp1.ToString();
                val1 = (int)temp1;
            }
            else return;

            if (temp1 < 1)
            {
                bt4.Visible = false;
                bt1.Visible = false;
                pb1.Visible = false;
            }

            if (val1 == val2 && val2 == val3 && val3 == 0)
            {
                perfect.Visible = true;
            }
            else
            {
                System.Threading.Thread.Sleep(4000);
                computerTern(ref val1, ref val2, ref val3);
                if (val1 == val2 && val2 == val3 && val3 == 0)
                {
                    lose.Visible = true;
                }
                temp1 = val1;
                temp2 = val2;
                temp3 = val3;
                bt4.Text = val1.ToString();
                bt5.Text = val2.ToString();
                bt6.Text = val3.ToString();

                if (temp1 < 1)
                {
                    bt4.Visible = false;
                    bt1.Visible = false;
                    pb1.Visible = false;
                }

                if (temp2 < 1)
                {
                    bt5.Visible = false;
                    bt2.Visible = false;
                    pb2.Visible = false;
                }

                if (temp3 < 1)
                {
                    bt6.Visible = false;
                    bt3.Visible = false;
                    pb3.Visible = false;
                }
            }
        }

        private void bt2_Click(object sender, EventArgs e)
        {
            if (temp2 != val2 && temp2 != null)
            {
                temp1 = val1;
                temp3 = val3;
                bt4.Text = temp1.ToString();
                bt6.Text = temp3.ToString();
                bt5.Text = temp2.ToString();
                val2 = (int)temp2;
            }
            else return;

            if (temp2 < 1)
            {
                bt5.Visible = false;
                bt2.Visible = false;
                pb2.Visible = false;
            }

            if (val1 == val2 && val2 == val3 && val3 == 0)
            {
                perfect.Visible = true;
            }
            else
            {
                System.Threading.Thread.Sleep(4000);
                computerTern(ref val1, ref val2, ref val3);
                if (val1 == val2 && val2 == val3 && val3 == 0)
                {
                    lose.Visible = true;
                }
                temp1 = val1;
                temp2 = val2;
                temp3 = val3;
                bt4.Text = val1.ToString();
                bt5.Text = val2.ToString();
                bt6.Text = val3.ToString();

                if (temp1 < 1)
                {
                    bt4.Visible = false;
                    bt1.Visible = false;
                    pb1.Visible = false;
                }

                if (temp2 < 1)
                {
                    bt5.Visible = false;
                    bt2.Visible = false;
                    pb2.Visible = false;
                }

                if (temp3 < 1)
                {
                    bt6.Visible = false;
                    bt3.Visible = false;
                    pb3.Visible = false;
                }
            }
        }

        private void bt3_Click(object sender, EventArgs e)
        {
            if (temp3 != val3 && temp3 != null)
            {
                temp1 = val1;
                temp2 = val2;
                bt4.Text = temp1.ToString();
                bt5.Text = temp2.ToString();
                bt6.Text = temp3.ToString();
                val3 = (int)temp3;
            }
            else return;

            if (temp3 < 1)
            {
                bt6.Visible = false;
                bt3.Visible = false;
                pb3.Visible = false;
            }
            
            if (val1 == val2 && val2 == val3 && val3 == 0)
            {
                perfect.Visible = true;
            }
            else
            {
                System.Threading.Thread.Sleep(4000);
                computerTern(ref val1, ref val2, ref val3);
                if (val1 == val2 && val2 == val3 && val3 == 0)
                {
                    lose.Visible = true;
                }
                temp1 = val1;
                temp2 = val2;
                temp3 = val3;
                bt4.Text = val1.ToString();
                bt5.Text = val2.ToString();
                bt6.Text = val3.ToString();

                if (temp1 < 1)
                {
                    bt4.Visible = false;
                    bt1.Visible = false;
                    pb1.Visible = false;
                }

                if (temp2 < 1)
                {
                    bt5.Visible = false;
                    bt2.Visible = false;
                    pb2.Visible = false;
                }

                if (temp3 < 1)
                {
                    bt6.Visible = false;
                    bt3.Visible = false;
                    pb3.Visible = false;
                }
            }
        }

        private void View_Click(object sender, EventArgs e)
        {
            
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Game_Click(object sender, EventArgs e)
        {
            const string message = "Nim is a 2-player game featuring several piles of matches.\n Players alternate turns, and on his/her turn, a player’s move consists of removing one or more match from any single pile.\n Play ends when all the matches have been removed, at which point the last player to have moved is declared the winner.";
            const string caption = "Rules of the Game";
            var result = MessageBox.Show(message, caption, MessageBoxButtons.OK, MessageBoxIcon.Question);
        }

        private void Author_Click(object sender, EventArgs e)
        {
            const string message = "[ro] Vlad Ganusceac\n[eng] Vlad Ganuscheak";
            const string caption = "Author";
            var result = MessageBox.Show(message, caption, MessageBoxButtons.OK, MessageBoxIcon.Question);
        }

        private void bt5_Click_1(object sender, EventArgs e)
        {
            if (temp2 == null)
            {
                temp2 = val2;
            }
            if (temp2 > 0)
            {
                temp2--;
            }
            else
            {
                temp2 = val2;
            }
            bt5.Text = temp2.ToString();
        }

        private void bt6_Click_1(object sender, EventArgs e)
        {
            if (temp3 == null)
            {
                temp3 = val3;
            }
            if (temp3 > 0)
            {
                temp3--;
            }
            else
            {
                temp3 = val3;
            }
            bt6.Text = temp3.ToString();
        }
    }
}
