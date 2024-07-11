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
    public partial class Form4 : Form
    {
        int bal;
        public Form4(int b)
        {
            InitializeComponent();
            bal = b;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int deb = Convert.ToInt32(textBox2.Text);
            bal=bal-deb;
            MessageBox.Show("Rs"+deb+" has been debited from your account and has been credited to "+textBox1.Text+"current balance is "+bal);
        }

        private void Form4_Load(object sender, EventArgs e)
        {

        }
    }
}
