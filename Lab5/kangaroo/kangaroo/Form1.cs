using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace kangaroo
{
    public partial class Form1 : Form
    {
        int[][] arr;
        int nButtons = 44;
        struct coord
        {
            public int x;
            public int y;
        }
        coord kangaroo;
        coord[] bt;
        static bool check(int n, coord c)
        {
            int x = (n / 9) * 136 + 12;
            int y = (n % 9) * 136 + 12;
            int one_step = 272;
            int two_step = 408;
                return ((x + one_step == c.x && y == c.y) ||
                        (x + two_step == c.x && y == c.y) ||
                        (x - one_step == c.x && y == c.y) ||
                        (x - two_step == c.x && y == c.y) ||
                        (x == c.x && y + one_step == c.y) ||
                        (x == c.x && y + two_step == c.y) ||
                        (x == c.x && y - one_step == c.y) ||
                        (x == c.x && y - two_step == c.y));
        }
        static void ChangePos(int n, ref PictureBox pb, ref coord c)
        {
            c.y = pb.Left = (n % 9) * 136 + 12;
            c.x = pb.Top = (n / 9) * 136 + 12;
        }
        static void LeftDown(int n, ref PictureBox pb1, ref PictureBox pb2, coord c)
        {
            int x = (n / 9) * 136 + 12;
            int y = (n % 9) * 136 + 12;
            int one_step = 272;
            int two_step = 408;
            if ((x - one_step == c.x && y == c.y) ||
                (x - two_step == c.x && y == c.y) ||
                (x == c.x && y + one_step == c.y) ||
                (x == c.x && y + two_step == c.y))
            {
                pb1.Visible = false;
                pb2.Visible = true;
            }
            else if ((x + one_step == c.x && y == c.y) ||
                (x + two_step == c.x && y == c.y) ||
                (x == c.x && y - one_step == c.y) ||
                (x == c.x && y - two_step == c.y))
            {
                pb1.Visible = true;
                pb2.Visible = false;
            }
        }
        static bool Moves(coord[] arr, coord c)
        {
            int one_step = 272;
            int two_step = 408;
            for(int i = 0; i < 45; i++)
            {
                if ((arr[i].x + one_step == c.x && arr[i].y == c.y) ||
                        (arr[i].x + two_step == c.x && arr[i].y == c.y) ||
                        (arr[i].x - one_step == c.x && arr[i].y == c.y) ||
                        (arr[i].x - two_step == c.x && arr[i].y == c.y) ||
                        (arr[i].x == c.x && arr[i].y + one_step == c.y) ||
                        (arr[i].x == c.x && arr[i].y + two_step == c.y) ||
                        (arr[i].x == c.x && arr[i].y - one_step == c.y) ||
                        (arr[i].x == c.x && arr[i].y - two_step == c.y))
                {
                    return true;
                }
            }
                return false;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new System.Drawing.Size(1260, 750);
            this.MaximumSize = new System.Drawing.Size(1260, 750);
            arr = new int[5][];
            for (int i = 0; i < 5; i++)
            {
                arr[i] = new int[9];
            }
            Random rnd = new Random();
            kangaroo = new coord();
            kangaroo.x = 12 + rnd.Next(0, 5) * 136;
            kangaroo.y = 12 + rnd.Next(0, 9) * 136;
            bt = new coord[45];
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    bt[i * 9 + j].x = 12 + i * 136;
                    bt[i * 9 + j].y = 12 + j * 136;
                }
            }
            //
            pb1.Left = kangaroo.y;
            pb1.Top = kangaroo.x;
            for (int i = 0; i < 45; i++)
            {
                if (bt[i].x == kangaroo.x && bt[i].y == kangaroo.y)
                {
                    bt[i].x = 0;
                    bt[i].y = 0;
                    switch (i + 1)
                    {
                        case 1:
                            bt1.Visible = false;
                            break;
                        case 2:
                            bt2.Visible = false;
                            break;
                        case 3:
                            bt3.Visible = false;
                            break;
                        case 4:
                            bt4.Visible = false;
                            break;
                        case 5:
                            bt5.Visible = false;
                            break;
                        case 6:
                            bt6.Visible = false;
                            break;
                        case 7:
                            bt7.Visible = false;
                            break;
                        case 8:
                            bt8.Visible = false;
                            break;
                        case 9:
                            bt9.Visible = false;
                            break;
                        case 10:
                            bt10.Visible = false;
                            break;
                        case 11:
                            bt11.Visible = false;
                            break;
                        case 12:
                            bt12.Visible = false;
                            break;
                        case 13:
                            bt13.Visible = false;
                            break;
                        case 14:
                            bt14.Visible = false;
                            break;
                        case 15:
                            bt15.Visible = false;
                            break;
                        case 16:
                            bt16.Visible = false;
                            break;
                        case 17:
                            bt17.Visible = false;
                            break;
                        case 18:
                            bt18.Visible = false;
                            break;
                        case 19:
                            bt19.Visible = false;
                            break;
                        case 20:
                            bt20.Visible = false;
                            break;
                        case 21:
                            bt21.Visible = false;
                            break;
                        case 22:
                            bt22.Visible = false;
                            break;
                        case 23:
                            bt23.Visible = false;
                            break;
                        case 24:
                            bt24.Visible = false;
                            break;
                        case 25:
                            bt25.Visible = false;
                            break;
                        case 26:
                            bt26.Visible = false;
                            break;
                        case 27:
                            bt27.Visible = false;
                            break;
                        case 28:
                            bt28.Visible = false;
                            break;
                        case 29:
                            bt29.Visible = false;
                            break;
                        case 30:
                            bt30.Visible = false;
                            break;
                        case 31:
                            bt31.Visible = false;
                            break;
                        case 32:
                            bt32.Visible = false;
                            break;
                        case 33:
                            bt33.Visible = false;
                            break;
                        case 34:
                            bt34.Visible = false;
                            break;
                        case 35:
                            bt35.Visible = false;
                            break;
                        case 36:
                            bt36.Visible = false;
                            break;
                        case 37:
                            bt37.Visible = false;
                            break;
                        case 38:
                            bt38.Visible = false;
                            break;
                        case 39:
                            bt39.Visible = false;
                            break;
                        case 40:
                            bt40.Visible = false;
                            break;
                        case 41:
                            bt41.Visible = false;
                            break;
                        case 42:
                            bt42.Visible = false;
                            break;
                        case 43:
                            bt43.Visible = false;
                            break;
                        case 44:
                            bt44.Visible = false;
                            break;
                        case 45:
                            bt45.Visible = false;
                            break;
                    }
                }
            }
        }

        private void bt1_Click(object sender, EventArgs e)
        {
            if (check(0, kangaroo))
            {
                bt1.Visible = false;
                LeftDown(0, ref pb1, ref pb2, kangaroo);
                ChangePos(0, ref pb1, ref kangaroo);
                ChangePos(0, ref pb2, ref kangaroo);
                nButtons--;
                bt[0].x = bt[0].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt2_Click(object sender, EventArgs e)
        {
            if (check(1, kangaroo))
            {
                bt2.Visible = false;
                LeftDown(1, ref pb1, ref pb2, kangaroo);
                ChangePos(1, ref pb1, ref kangaroo);
                ChangePos(1, ref pb2, ref kangaroo);
                nButtons--;
                bt[1].x = bt[1].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt3_Click(object sender, EventArgs e)
        {
            if (check(2, kangaroo) == true)
            {
                bt3.Visible = false;
                LeftDown(2, ref pb1, ref pb2, kangaroo);
                ChangePos(2, ref pb1, ref kangaroo);
                ChangePos(2, ref pb2, ref kangaroo);
                nButtons--;
                bt[2].x = bt[2].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt4_Click(object sender, EventArgs e)
        {
            if (check(3, kangaroo))
            {
                bt4.Visible = false;
                LeftDown(3, ref pb1, ref pb2, kangaroo);
                ChangePos(3, ref pb1, ref kangaroo);
                ChangePos(3, ref pb2, ref kangaroo);
                nButtons--;
                bt[3].x = bt[3].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt5_Click(object sender, EventArgs e)
        {
            if (check(4, kangaroo))
            {
                bt5.Visible = false;
                LeftDown(4, ref pb1, ref pb2, kangaroo);
                ChangePos(4, ref pb1, ref kangaroo);
                ChangePos(4, ref pb2, ref kangaroo);
                nButtons--;
                bt[4].x = bt[4].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt6_Click(object sender, EventArgs e)
        {
            if (check(5, kangaroo))
            {
                bt6.Visible = false;
                LeftDown(5, ref pb1, ref pb2, kangaroo);
                ChangePos(5, ref pb1, ref kangaroo);
                ChangePos(5, ref pb2, ref kangaroo);
                nButtons--;
                bt[5].x = bt[5].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt7_Click(object sender, EventArgs e)
        {
            if (check(6, kangaroo))
            {
                bt7.Visible = false;
                LeftDown(6, ref pb1, ref pb2, kangaroo);
                ChangePos(6, ref pb1, ref kangaroo);
                ChangePos(6, ref pb2, ref kangaroo);
                nButtons--;
                bt[6].x = bt[6].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt8_Click(object sender, EventArgs e)
        {
            if (check(7, kangaroo))
            {
                bt8.Visible = false;
                LeftDown(7, ref pb1, ref pb2, kangaroo);
                ChangePos(7, ref pb1, ref kangaroo);
                ChangePos(7, ref pb2, ref kangaroo);
                nButtons--;
                bt[7].x = bt[7].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt9_Click(object sender, EventArgs e)
        {
            if (check(8, kangaroo))
            {
                bt9.Visible = false;
                LeftDown(8, ref pb1, ref pb2, kangaroo);
                ChangePos(8, ref pb1, ref kangaroo);
                ChangePos(8, ref pb2, ref kangaroo);
                nButtons--;
                bt[8].x = bt[8].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt10_Click(object sender, EventArgs e)
        {
            if (check(9, kangaroo))
            {
                bt10.Visible = false;
                LeftDown(9, ref pb1, ref pb2, kangaroo);
                ChangePos(9, ref pb1, ref kangaroo);
                ChangePos(9, ref pb2, ref kangaroo);
                nButtons--;
                bt[9].x = bt[9].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt11_Click(object sender, EventArgs e)
        {
            if (check(10, kangaroo))
            {
                bt11.Visible = false;
                LeftDown(10, ref pb1, ref pb2, kangaroo);
                ChangePos(10, ref pb1, ref kangaroo);
                ChangePos(10, ref pb2, ref kangaroo);
                nButtons--;
                bt[10].x = bt[10].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt12_Click(object sender, EventArgs e)
        {
            if (check(11, kangaroo))
            {
                bt12.Visible = false;
                LeftDown(11, ref pb1, ref pb2, kangaroo);
                ChangePos(11, ref pb1, ref kangaroo);
                ChangePos(11, ref pb2, ref kangaroo);
                nButtons--;
                bt[11].x = bt[11].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt13_Click(object sender, EventArgs e)
        {
            if (check(12, kangaroo))
            {
                bt13.Visible = false;
                LeftDown(12, ref pb1, ref pb2, kangaroo);
                ChangePos(12, ref pb1, ref kangaroo);
                ChangePos(12, ref pb2, ref kangaroo);
                nButtons--;
                bt[12].x = bt[12].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt14_Click(object sender, EventArgs e)
        {
            if (check(13, kangaroo))
            {
                bt14.Visible = false;
                LeftDown(13, ref pb1, ref pb2, kangaroo);
                ChangePos(13, ref pb1, ref kangaroo);
                ChangePos(13, ref pb2, ref kangaroo);
                nButtons--;
                bt[13].x = bt[13].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt15_Click(object sender, EventArgs e)
        {
            if (check(14, kangaroo))
            {
                bt15.Visible = false;
                LeftDown(14, ref pb1, ref pb2, kangaroo);
                ChangePos(14, ref pb1, ref kangaroo);
                ChangePos(14, ref pb2, ref kangaroo);
                nButtons--;
                bt[14].x = bt[14].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt16_Click(object sender, EventArgs e)
        {
            if (check(15, kangaroo))
            {
                bt16.Visible = false;
                LeftDown(15, ref pb1, ref pb2, kangaroo);
                ChangePos(15, ref pb1, ref kangaroo);
                ChangePos(15, ref pb2, ref kangaroo);
                nButtons--;
                bt[15].x = bt[15].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt17_Click(object sender, EventArgs e)
        {
            if (check(16, kangaroo))
            {
                bt17.Visible = false;
                LeftDown(16, ref pb1, ref pb2, kangaroo);
                ChangePos(16, ref pb1, ref kangaroo);
                ChangePos(16, ref pb2, ref kangaroo);
                nButtons--;
                bt[16].x = bt[16].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt18_Click(object sender, EventArgs e)
        {
            if (check(17, kangaroo))
            {
                bt18.Visible = false;
                LeftDown(17, ref pb1, ref pb2, kangaroo);
                ChangePos(17, ref pb1, ref kangaroo);
                ChangePos(17, ref pb2, ref kangaroo);
                nButtons--;
                bt[17].x = bt[17].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt19_Click(object sender, EventArgs e)
        {
            if (check(18, kangaroo))
            {
                bt19.Visible = false;
                LeftDown(18, ref pb1, ref pb2, kangaroo);
                ChangePos(18, ref pb1, ref kangaroo);
                ChangePos(18, ref pb2, ref kangaroo);
                nButtons--;
                bt[18].x = bt[18].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt20_Click(object sender, EventArgs e)
        {
            if (check(19, kangaroo))
            {
                bt20.Visible = false;
                LeftDown(19, ref pb1, ref pb2, kangaroo);
                ChangePos(19, ref pb1, ref kangaroo);
                ChangePos(19, ref pb2, ref kangaroo);
                nButtons--;
                bt[19].x = bt[19].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt21_Click(object sender, EventArgs e)
        {
            if (check(20, kangaroo))
            {
                bt21.Visible = false;
                LeftDown(20, ref pb1, ref pb2, kangaroo);
                ChangePos(20, ref pb1, ref kangaroo);
                ChangePos(20, ref pb2, ref kangaroo);
                nButtons--;
                bt[20].x = bt[20].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt22_Click(object sender, EventArgs e)
        {
            if (check(21, kangaroo))
            {
                bt22.Visible = false;
                LeftDown(21, ref pb1, ref pb2, kangaroo);
                ChangePos(21, ref pb1, ref kangaroo);
                ChangePos(21, ref pb2, ref kangaroo);
                nButtons--;
                bt[21].x = bt[21].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt23_Click(object sender, EventArgs e)
        {
            if (check(22, kangaroo))
            {
                bt23.Visible = false;
                LeftDown(22, ref pb1, ref pb2, kangaroo);
                ChangePos(22, ref pb1, ref kangaroo);
                ChangePos(22, ref pb2, ref kangaroo);
                nButtons--;
                bt[22].x = bt[22].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt24_Click(object sender, EventArgs e)
        {
            if (check(23, kangaroo))
            {
                bt24.Visible = false;
                LeftDown(23, ref pb1, ref pb2, kangaroo);
                ChangePos(23, ref pb1, ref kangaroo);
                ChangePos(23, ref pb2, ref kangaroo);
                nButtons--;
                bt[23].x = bt[23].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt25_Click(object sender, EventArgs e)
        {
            if (check(24, kangaroo))
            {
                bt25.Visible = false;
                LeftDown(24, ref pb1, ref pb2, kangaroo);
                ChangePos(24, ref pb1, ref kangaroo);
                ChangePos(24, ref pb2, ref kangaroo);
                nButtons--;
                bt[24].x = bt[24].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt26_Click(object sender, EventArgs e)
        {
            if (check(25, kangaroo))
            {
                bt26.Visible = false;
                LeftDown(25, ref pb1, ref pb2, kangaroo);
                ChangePos(25, ref pb1, ref kangaroo);
                ChangePos(25, ref pb2, ref kangaroo);
                nButtons--;
                bt[25].x = bt[25].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt27_Click(object sender, EventArgs e)
        {
            if (check(26, kangaroo))
            {
                bt27.Visible = false;
                LeftDown(26, ref pb1, ref pb2, kangaroo);
                ChangePos(26, ref pb1, ref kangaroo);
                ChangePos(26, ref pb2, ref kangaroo);
                nButtons--;
                bt[26].x = bt[26].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt28_Click(object sender, EventArgs e)
        {
            if (check(27, kangaroo))
            {
                bt28.Visible = false;
                LeftDown(27, ref pb1, ref pb2, kangaroo);
                ChangePos(27, ref pb1, ref kangaroo);
                ChangePos(27, ref pb2, ref kangaroo);
                nButtons--;
                bt[27].x = bt[27].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt29_Click(object sender, EventArgs e)
        {
            if (check(28, kangaroo))
            {
                bt29.Visible = false;
                LeftDown(28, ref pb1, ref pb2, kangaroo);
                ChangePos(28, ref pb1, ref kangaroo);
                ChangePos(28, ref pb2, ref kangaroo);
                nButtons--;
                bt[28].x = bt[28].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt30_Click(object sender, EventArgs e)
        {
            if (check(29, kangaroo))
            {
                bt30.Visible = false;
                LeftDown(29, ref pb1, ref pb2, kangaroo);
                ChangePos(29, ref pb1, ref kangaroo);
                ChangePos(29, ref pb2, ref kangaroo);
                nButtons--;
                bt[29].x = bt[29].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt31_Click(object sender, EventArgs e)
        {
            if (check(30, kangaroo))
            {
                bt31.Visible = false;
                LeftDown(30, ref pb1, ref pb2, kangaroo);
                ChangePos(30, ref pb1, ref kangaroo);
                ChangePos(30, ref pb2, ref kangaroo);
                nButtons--;
                bt[30].x = bt[30].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt32_Click(object sender, EventArgs e)
        {
            if (check(31, kangaroo))
            {
                bt32.Visible = false;
                LeftDown(31, ref pb1, ref pb2, kangaroo);
                ChangePos(31, ref pb1, ref kangaroo);
                ChangePos(31, ref pb2, ref kangaroo);
                nButtons--;
                bt[31].x = bt[31].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt33_Click(object sender, EventArgs e)
        {
            if (check(32, kangaroo))
            {
                bt33.Visible = false;
                LeftDown(32, ref pb1, ref pb2, kangaroo);
                ChangePos(32, ref pb1, ref kangaroo);
                ChangePos(32, ref pb2, ref kangaroo);
                nButtons--;
                bt[32].x = bt[32].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt34_Click(object sender, EventArgs e)
        {
            if (check(33, kangaroo))
            {
                bt34.Visible = false;
                LeftDown(33, ref pb1, ref pb2, kangaroo);
                ChangePos(33, ref pb1, ref kangaroo);
                ChangePos(33, ref pb2, ref kangaroo);
                nButtons--;
                bt[33].x = bt[33].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt35_Click(object sender, EventArgs e)
        {
            if (check(34, kangaroo))
            {
                bt35.Visible = false;
                LeftDown(34, ref pb1, ref pb2, kangaroo);
                ChangePos(34, ref pb1, ref kangaroo);
                ChangePos(34, ref pb2, ref kangaroo);
                nButtons--;
                bt[34].x = bt[34].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt36_Click(object sender, EventArgs e)
        {
            if (check(35, kangaroo))
            {
                bt36.Visible = false;
                LeftDown(35, ref pb1, ref pb2, kangaroo);
                ChangePos(35, ref pb1, ref kangaroo);
                ChangePos(35, ref pb2, ref kangaroo);
                nButtons--;
                bt[35].x = bt[35].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt37_Click(object sender, EventArgs e)
        {
            if (check(36, kangaroo))
            {
                bt37.Visible = false;
                LeftDown(36, ref pb1, ref pb2, kangaroo);
                ChangePos(36, ref pb1, ref kangaroo);
                ChangePos(36, ref pb2, ref kangaroo);
                nButtons--;
                bt[36].x = bt[36].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt38_Click(object sender, EventArgs e)
        {
            if (check(37, kangaroo))
            {
                bt38.Visible = false;
                LeftDown(37, ref pb1, ref pb2, kangaroo);
                ChangePos(37, ref pb1, ref kangaroo);
                ChangePos(37, ref pb2, ref kangaroo);
                nButtons--;
                bt[37].x = bt[37].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt39_Click(object sender, EventArgs e)
        {
            if (check(38, kangaroo))
            {
                bt39.Visible = false;
                LeftDown(38, ref pb1, ref pb2, kangaroo);
                ChangePos(38, ref pb1, ref kangaroo);
                ChangePos(38, ref pb2, ref kangaroo);
                nButtons--;
                bt[38].x = bt[38].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt40_Click(object sender, EventArgs e)
        {
            if (check(39, kangaroo))
            {
                bt40.Visible = false;
                LeftDown(39, ref pb1, ref pb2, kangaroo);
                ChangePos(39, ref pb1, ref kangaroo);
                ChangePos(39, ref pb2, ref kangaroo);
                nButtons--;
                bt[39].x = bt[39].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt41_Click(object sender, EventArgs e)
        {
            if (check(40, kangaroo))
            {
                bt41.Visible = false;
                LeftDown(40, ref pb1, ref pb2, kangaroo);
                ChangePos(40, ref pb1, ref kangaroo);
                ChangePos(40, ref pb2, ref kangaroo);
                nButtons--;
                bt[40].x = bt[40].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt42_Click(object sender, EventArgs e)
        {
            if (check(41, kangaroo))
            {
                bt42.Visible = false;
                LeftDown(41, ref pb1, ref pb2, kangaroo);
                ChangePos(41, ref pb1, ref kangaroo);
                ChangePos(41, ref pb2, ref kangaroo);
                nButtons--;
                bt[41].x = bt[41].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt43_Click(object sender, EventArgs e)
        {
            if (check(42, kangaroo))
            {
                bt43.Visible = false;
                LeftDown(42, ref pb1, ref pb2, kangaroo);
                ChangePos(42, ref pb1, ref kangaroo);
                ChangePos(42, ref pb2, ref kangaroo);
                nButtons--;
                bt[42].x = bt[42].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt44_Click(object sender, EventArgs e)
        {
            if (check(43, kangaroo))
            {
                bt44.Visible = false;
                LeftDown(43, ref pb1, ref pb2, kangaroo);
                ChangePos(43, ref pb1, ref kangaroo);
                ChangePos(43, ref pb2, ref kangaroo);
                nButtons--;
                bt[43].x = bt[43].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }

        private void bt45_Click(object sender, EventArgs e)
        {
            if (check(44, kangaroo))
            {
                bt45.Visible = false;
                LeftDown(44, ref pb1, ref pb2, kangaroo);
                ChangePos(44, ref pb1, ref kangaroo);
                ChangePos(44, ref pb2, ref kangaroo);
                nButtons--;
                bt[44].x = bt[44].y = 0;
                if (nButtons == 0)
                {
                    winner.Left = winner.Top = 12;
                    winner.Visible = true;
                    winner.Width = 1224;
                    winner.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
                if (Moves(bt, kangaroo) == false)
                {
                    loser.Left = loser.Top = 12;
                    loser.Visible = true;
                    loser.Width = 1224;
                    loser.Height = 680;
                    pb1.Visible = pb2.Visible = false;
                }
            }
        }
    }
}
