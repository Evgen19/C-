using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator_wf
{
    public partial class Form1 : Form
    {
        float a, b;
        int count;
        bool znak = true;

        void calculate()
        {
            switch(count)
            {
                case 1:
                    b = a + float.Parse(textBox4.Text);
                    textBox4.Text = b.ToString();
                    break;
                case 2:
                    b = a - float.Parse(textBox4.Text);
                    textBox4.Text = b.ToString();
                    break;
                case 3:
                    b = a * float.Parse(textBox4.Text);
                    textBox4.Text = b.ToString();
                    break;
                case 4:
                    b = a / float.Parse(textBox4.Text);
                    textBox4.Text = b.ToString();
                    break;
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

       
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            a = float.Parse(textBox4.Text);
            textBox4.Clear();
            count = 1;
            label1.Text = a.ToString() + "+";
            znak = true;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            calculate();
            label1.Text = "";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 4;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 1;
        }

        private void button17_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 2;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 3;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 5;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 6;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 7;
        }

        private void button16_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 8;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 9;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + 0;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            textBox4.Text = textBox4.Text + ",";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            a = float.Parse(textBox4.Text);
            textBox4.Clear();
            count = 2;
            label1.Text = a.ToString() + "-";
            znak = true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            a = float.Parse(textBox4.Text);
            textBox4.Clear();
            count = 3;
            label1.Text = a.ToString() + "*";
            znak = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            a = float.Parse(textBox4.Text);
            textBox4.Clear();
            count = 4;
            label1.Text = a.ToString() + "/";
            znak = true;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox4.Text = "";
            label1.Text = "";
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged_1(object sender, EventArgs e)
        {

        }
    }
}
