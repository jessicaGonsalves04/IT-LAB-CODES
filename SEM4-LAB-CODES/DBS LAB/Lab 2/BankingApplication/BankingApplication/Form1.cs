using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BankingApplication
{
    public partial class Form1 : Form
    {
        string accno = "220911009";
        string password = "PASSWORD";
        public Form1()
        {
            InitializeComponent();
            
        }

        public Form1(string pas)
        {
            InitializeComponent();
            textBox2.Text = pas;
            password = pas;
        }

        private void label4_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2(password);
            f.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == accno && textBox2.Text == password)
            {
                Form3 f3 = new Form3(accno);
                f3.Show();
            }
            else {
                MessageBox.Show("Invalid Creddentials, Please Try Again!!!!");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
