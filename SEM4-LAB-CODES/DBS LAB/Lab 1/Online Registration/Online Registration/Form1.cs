using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Online_Registration
{
    public partial class Form1 : Form
    {
        String details = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            details += "Name: " + NameBox.Text + "\n";
            details += "Reg No: " + RegNoBox.Text + "\n";
            details += "Branch: " + BranchBox.SelectedItem + "\n";
            details += "Semester: " + SemBox.SelectedItem + "\n";
            details += "Email ID: " + EmailBox.Text + "\n";
            details += "Gender: ";
            if (radioButton1.Checked == true)
                details += radioButton1.Text;
            else if(radioButton2.Checked== true)
                details += radioButton2.Text;
            else details += radioButton3.Text;
            details += "\n";
            details += "Date Of Birth: " + dateTimePicker1.Text + "\n";
            details += "Selected Domains: ";
            if(checkBox1.Checked == true)
                details += checkBox1.Text+"\n";
            if(checkBox2.Checked == true)
                details += checkBox2.Text+"\n";
            if (checkBox3.Checked == true)
                details += checkBox3.Text+"\n";
            if(checkBox4.Checked == true)
                details += checkBox4.Text+"\n";

            MessageBox.Show(details);
        }
    }
}
