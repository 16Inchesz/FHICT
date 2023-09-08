namespace Serial_exercise_4
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.LedOn = new System.Windows.Forms.Button();
            this.LedOff = new System.Windows.Forms.Button();
            this.LedBlinkOn = new System.Windows.Forms.Button();
            this.LedBlinkOff = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM4";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            // 
            // LedOn
            // 
            this.LedOn.Location = new System.Drawing.Point(379, 89);
            this.LedOn.Name = "LedOn";
            this.LedOn.Size = new System.Drawing.Size(137, 67);
            this.LedOn.TabIndex = 1;
            this.LedOn.Text = "LedOn";
            this.LedOn.UseVisualStyleBackColor = true;
            this.LedOn.Click += new System.EventHandler(this.LedOn_Click);
            // 
            // LedOff
            // 
            this.LedOff.Location = new System.Drawing.Point(585, 89);
            this.LedOff.Name = "LedOff";
            this.LedOff.Size = new System.Drawing.Size(137, 67);
            this.LedOff.TabIndex = 2;
            this.LedOff.Text = "LedOff";
            this.LedOff.UseVisualStyleBackColor = true;
            this.LedOff.Click += new System.EventHandler(this.LedOff_Click);
            // 
            // LedBlinkOn
            // 
            this.LedBlinkOn.Location = new System.Drawing.Point(379, 230);
            this.LedBlinkOn.Name = "LedBlinkOn";
            this.LedBlinkOn.Size = new System.Drawing.Size(137, 72);
            this.LedBlinkOn.TabIndex = 3;
            this.LedBlinkOn.Text = "LedBlinkOn";
            this.LedBlinkOn.UseVisualStyleBackColor = true;
            this.LedBlinkOn.Click += new System.EventHandler(this.LedBlinkOn_Click);
            // 
            // LedBlinkOff
            // 
            this.LedBlinkOff.Location = new System.Drawing.Point(585, 230);
            this.LedBlinkOff.Name = "LedBlinkOff";
            this.LedBlinkOff.Size = new System.Drawing.Size(137, 73);
            this.LedBlinkOff.TabIndex = 4;
            this.LedBlinkOff.Text = "LedBlinkOff";
            this.LedBlinkOff.UseVisualStyleBackColor = true;
            this.LedBlinkOff.Click += new System.EventHandler(this.LedBlinkOff_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.LedBlinkOff);
            this.Controls.Add(this.LedBlinkOn);
            this.Controls.Add(this.LedOff);
            this.Controls.Add(this.LedOn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button LedOn;
        private System.Windows.Forms.Button LedOff;
        private System.Windows.Forms.Button LedBlinkOn;
        private System.Windows.Forms.Button LedBlinkOff;
    }
}

