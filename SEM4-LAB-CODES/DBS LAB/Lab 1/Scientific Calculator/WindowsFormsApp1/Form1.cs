using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace WindowsFormsApp1
{
    public partial class Calculator : Form
    {
        public Calculator()
        {
            InitializeComponent();
        }
        string input = string.Empty;
        string op1 = string.Empty;
        string op2 = string.Empty;
        string Operator;
        double result = 0.0;
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "1";
            this.textBox1.Text += input;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "2";
            this.textBox1.Text += input;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "3";
            this.textBox1.Text += input;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "4";
            this.textBox1.Text += input;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "5";
            this.textBox1.Text += input;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "6";
            this.textBox1.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "7";
            this.textBox1.Text += input;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "8";
            this.textBox1.Text += input;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "9";
            this.textBox1.Text += input;
        }

        private void button0_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "0";
            this.textBox1.Text += input;
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "+";
            input = string.Empty;
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "-";
            input = string.Empty;
        }

        private void buttonMul_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "*";
            input = string.Empty;
        }

        private void buttonDiv_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "/";
            input = string.Empty;
        }
        private void buttonln_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "ln";
            input = string.Empty;
        }
        private void buttonLog_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "log";
            input = string.Empty;
        }

        private void buttonSin_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "sin";
            input = string.Empty;
        }

        private void buttonCos_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "cos";
            input = string.Empty;
        }

        private void buttonTan_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "tan";
            input = string.Empty;
        }

        private void buttonFact_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "!";
            input = string.Empty;
        }
        private void buttonSqrt_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "√";
            input = string.Empty;
        }

        private void buttonSquare_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "x²";
            input = string.Empty;
        }

        private void buttonCube_Click(object sender, EventArgs e)
        {
            op1 = input;
            Operator = "x³";
            input = string.Empty;
        }

        private void buttonEqual_Click(object sender, EventArgs e)
        {
            op2 = input;
            double num1, num2;
            double.TryParse(op1, out num1);
            double.TryParse(op2, out num2);
            if (Operator.Equals("+"))
            {
                result = num1 + num2;
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("-"))
            {
                result = num1 - num2;
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("*"))
            {
                result = num1 * num2;
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("/"))
            {
                if (num2 != 0)
                {
                    result = num1 / num2;
                    this.textBox1.Text = result.ToString();
                }
                else
                {
                    textBox1.Text = "DIV BY ZERO!!";
                }
            }
            else if (Operator.Equals("log")) {
                result = Math.Log10(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("ln"))
            {
                result = Math.Log(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("sin"))
            {
                result = Math.Sin(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("cos"))
            {
                result = Math.Cos(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("tan"))
            {
                result = Math.Tan(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("x²"))
            {
                result = num1 * num1;
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("x³"))
            {
                result = num1 * num1 * num1;
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("√"))
            {
                result = Math.Sqrt(num1);
                this.textBox1.Text = result.ToString();
            }
            else if (Operator.Equals("!"))
            {
                result = 1;
                for (int i = 1; i <= num1; i++)
                    result *= i;
                textBox1.Text = result.ToString(); 
            }
            input = string.Empty;
        }
    

        private void buttonAC_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            result = 0.0;
            op1 = null;
            op2 = null;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

    
    }
}
