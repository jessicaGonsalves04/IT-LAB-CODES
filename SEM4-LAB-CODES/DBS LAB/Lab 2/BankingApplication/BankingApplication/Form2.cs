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
    public partial class Form2 : Form
    {
        string password = "";
        public Form2(String pass)
        {
            
            InitializeComponent();
            password = pass;
            //textBox1.Text = pass;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text != password)
            {
                MessageBox.Show("Invalid old password.");
            }
            else if(textBox2.Text != textBox3.Text)
            {
                MessageBox.Show("new password doesnt match.");
            }
            else
            {
                Form1 f1 = new Form1(textBox3.Text);
                f1.Show();
            }
            
        }
    }
}
