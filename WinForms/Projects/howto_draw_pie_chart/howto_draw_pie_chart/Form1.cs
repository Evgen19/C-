using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace howto_draw_pie_chart
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        //Рисуем кусковой чарт
        private static void DrawPieChart(Graphics gr, Rectangle rect, Brush[] brushes, Pen[] pens, float[] values)
        {
            //Создаем переменую для всех углов
            float total = values.Sum();

            //Рисуем куски
            float start_angle = 0;
            for (int i = 0; i < values.Length; i++)
            {
                float sweep_angle = values[i] * 360f / total;
                gr.FillPie(brushes[i % brushes.Length],
                    rect, start_angle, sweep_angle);
                gr.DrawPie(pens[i % pens.Length],
                    rect, start_angle, sweep_angle);
                start_angle += sweep_angle;
            }
        }

        // Кисти использованные для цветов сектора.
        private Brush[] SliceBrushes =
        {
    Brushes.Red,
    Brushes.LightGreen,
    Brushes.Blue,
    Brushes.LightBlue,
    Brushes.Green,
    Brushes.Lime,
    Brushes.Orange,
    Brushes.Fuchsia,
    Brushes.Yellow,
    Brushes.Cyan,
};

        // Цвет используемы для отрисовки секторов
        private Pen[] SlicePens = { Pens.Black };

        // Значения для размера графика.
        private float[] Values = new float[10];

       

        private void Form1_Load_1(object sender, EventArgs e)
        {
            Random rand = new Random();
            for (int i = 0; i < Values.Length; i++)
            {
                Values[i] = rand.Next(10, 40);
            }
        }

        private void Form1_Paint_1(object sender, PaintEventArgs e)
        {
            e.Graphics.Clear(BackColor);
            if ((ClientSize.Width < 20) || (ClientSize.Height < 20)) return;

            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            Rectangle rect = new Rectangle(
                10, 10, ClientSize.Width - 20, ClientSize.Height - 20);
            DrawPieChart(e.Graphics, rect, SliceBrushes, SlicePens, Values);
        }
    }
}

