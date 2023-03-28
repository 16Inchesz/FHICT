namespace assignment_2._3_Car_application
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
            this.btnAccelerate = new System.Windows.Forms.Button();
            this.btnBreaks = new System.Windows.Forms.Button();
            this.information = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnAccelerate
            // 
            this.btnAccelerate.Location = new System.Drawing.Point(45, 184);
            this.btnAccelerate.Name = "btnAccelerate";
            this.btnAccelerate.Size = new System.Drawing.Size(108, 69);
            this.btnAccelerate.TabIndex = 0;
            this.btnAccelerate.Text = "Accelerate";
            this.btnAccelerate.UseVisualStyleBackColor = true;
            this.btnAccelerate.Click += new System.EventHandler(this.btnAccelerate_Click);
            // 
            // btnBreaks
            // 
            this.btnBreaks.Location = new System.Drawing.Point(215, 184);
            this.btnBreaks.Name = "btnBreaks";
            this.btnBreaks.Size = new System.Drawing.Size(108, 69);
            this.btnBreaks.TabIndex = 1;
            this.btnBreaks.Text = "Breaks";
            this.btnBreaks.UseVisualStyleBackColor = true;
            this.btnBreaks.Click += new System.EventHandler(this.btnBreaks_Click);
            // 
            // information
            // 
            this.information.AutoSize = true;
            this.information.Location = new System.Drawing.Point(45, 85);
            this.information.Name = "information";
            this.information.Size = new System.Drawing.Size(87, 20);
            this.information.TabIndex = 2;
            this.information.Text = "Information";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 450);
            this.Controls.Add(this.information);
            this.Controls.Add(this.btnBreaks);
            this.Controls.Add(this.btnAccelerate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button btnAccelerate;
        private Button btnBreaks;
        private Label information;
    }
}