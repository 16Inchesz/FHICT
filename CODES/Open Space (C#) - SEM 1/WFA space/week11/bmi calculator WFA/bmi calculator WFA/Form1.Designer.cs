namespace bmi_calculator_WFA
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Height = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Calculate_BMI = new System.Windows.Forms.Button();
            this.Weight = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.result = new System.Windows.Forms.Label();
            this.advice = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Height
            // 
            this.Height.Location = new System.Drawing.Point(205, 142);
            this.Height.Name = "Height";
            this.Height.Size = new System.Drawing.Size(125, 27);
            this.Height.TabIndex = 2;
            this.Height.TextChanged += new System.EventHandler(this.Height_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(49, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Weight in KGs";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(49, 149);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(102, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Height in CMs";
            // 
            // Calculate_BMI
            // 
            this.Calculate_BMI.Location = new System.Drawing.Point(49, 215);
            this.Calculate_BMI.Name = "Calculate_BMI";
            this.Calculate_BMI.Size = new System.Drawing.Size(281, 51);
            this.Calculate_BMI.TabIndex = 0;
            this.Calculate_BMI.Text = "Calculate body mass index";
            this.Calculate_BMI.UseVisualStyleBackColor = true;
            this.Calculate_BMI.Click += new System.EventHandler(this.Calculate_BMI_Click);
            // 
            // Weight
            // 
            this.Weight.Location = new System.Drawing.Point(205, 48);
            this.Weight.Name = "Weight";
            this.Weight.Size = new System.Drawing.Size(125, 27);
            this.Weight.TabIndex = 1;
            this.Weight.TextChanged += new System.EventHandler(this.Weight_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(140, 322);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "labelBMI";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(49, 322);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(85, 20);
            this.label4.TabIndex = 6;
            this.label4.Text = "Your BMI is:";
            // 
            // result
            // 
            this.result.AutoSize = true;
            this.result.Location = new System.Drawing.Point(49, 369);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(45, 20);
            this.result.TabIndex = 8;
            this.result.Text = "result";
            // 
            // advice
            // 
            this.advice.AutoSize = true;
            this.advice.Location = new System.Drawing.Point(49, 411);
            this.advice.Name = "advice";
            this.advice.Size = new System.Drawing.Size(54, 20);
            this.advice.TabIndex = 9;
            this.advice.Text = "Advice";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(386, 450);
            this.Controls.Add(this.advice);
            this.Controls.Add(this.result);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Height);
            this.Controls.Add(this.Weight);
            this.Controls.Add(this.Calculate_BMI);
            this.Name = "Form1";
            this.Text = "BMI calculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private TextBox Height;
        private Label label1;
        private Label label2;
        private Button Calculate_BMI;
        private TextBox Weight;
        private Label label3;
        private Label label4;
        private Label result;
        private Label advice;
    }
}