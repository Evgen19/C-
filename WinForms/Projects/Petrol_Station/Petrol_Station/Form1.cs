/*Программа расчитывает количество литров бензина и диз топлива, 
которое можно купить на заданную сумму*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Petrol_Station
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Загрузка формы
        private void Form1_Load(object sender, EventArgs e)
        {
            //Установим стиль списка Бензин, DropDownList
           comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;

            //Добавим элементы в список Бензин
           comboBox1.Items.Add("92");
           comboBox1.Items.Add("95");
           comboBox1.Items.Add("98");
           comboBox1.Items.Add("ДТ");

           button1.Enabled = false;
        }


        //Нажатие клавишы в поле Сумма
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
        //Контроль правильности вводимых данных
if(!Char.IsDigit(e.KeyChar)&& !(Char.IsControl(e.KeyChar)))
{
    if (!((e.KeyChar.ToString() == ",") && (textBox1.Text.IndexOf(",") == -1)))
        e.Handled = true;
}
        }
        //содержимое поля Сумма изменилось
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if ((textBox1.Text != ",") && (textBox1.TextLength > 0) && (comboBox1.SelectedIndex != -1))
                button1.Enabled = true;
            else
                if (!button1.Enabled) button1.Enabled = false;
        }
        //изменился индекс выбранного вида топлива
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if ((textBox1.Text != ",") && (textBox1.TextLength > 0))
                button1.Enabled = true;
        }
        //щелчок по кнопке ОК
        private void button1_Click(object sender, EventArgs e)
        {
            double cl = 34.59F; //цена за литр
            double lt;          //количество литров
            double cash;        //наличные
            double ch;          //сдача

            //цена за литр для выбранного типа топлива
            switch(comboBox1.SelectedIndex)
            {
                case 0: cl = 34.59F; break;
                case 1: cl = 37.89F; break;
                case 2: cl = 44.69F; break;
                case 3: cl = 35.49F; break;
            }

            //количество литров считается с точностью до 0,1 л
            cash = Convert.ToSingle(textBox1.Text);
            lt = (double)Decimal.Truncate((Decimal)(cash * 10 / cl)) / 10;
            ch = cash - lt * cl;

            label3.Text = "Литров: " + lt.ToString("N") +
                "\nСумма: " + cash.ToString("C") +
                "\nСдача: " + ch.ToString("C") +
                "\nЦена за литр: " + cl.ToString("C");
        }
    }
}
