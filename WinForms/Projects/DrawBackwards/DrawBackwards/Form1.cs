using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DrawBackwards
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Создаем объект Bitmap
            Bitmap bm = new Bitmap(380, 100);
            using (Graphics gr = Graphics.FromImage(bm))
            {
                gr.TextRenderingHint =
                    System.Drawing.Text.TextRenderingHint.AntiAliasGridFit;
                gr.ScaleTransform(-1, 1);
                using (Font the_font = new Font("Comic Sans MS", 40))
                {
                    gr.DrawString("Привет", the_font, Brushes.Black, -280, 0);
                    picBackward.Image = bm;
                }
            }
        }
    }
}
