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
    public partial class Form3 : Form
    {
        String accn;
        int balance = 20000;
        public Form3(String accno)
        {
            InitializeComponent();
            accn = accno;
            label1.Text = accn + "\nUsername:Jessica \nBalance=Rs.20000" +
                "\nLast Accessed on:04-02-2024\nDate:"+(DateTime.Today)+
                "\nLast 5 Transactions:Rs200 debited on 05-01-2024\nRs1000 debited on 08-01-2024" +
                "\nRs400 debited on 11-01-2024\nRs200 debited on 26-01-2024\nRs660 debited on 29-01-2024";
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form4 f4 = new Form4(balance);
            f4.Show();
        }
    }
}
