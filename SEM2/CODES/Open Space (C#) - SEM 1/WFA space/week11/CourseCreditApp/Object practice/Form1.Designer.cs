namespace Object_practice
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lblInformation = new System.Windows.Forms.Label();
            this.btnCreate = new System.Windows.Forms.Button();
            this.btnShow = new System.Windows.Forms.Button();
            this.txtbName = new System.Windows.Forms.TextBox();
            this.txtbCredits = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(53, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(101, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Course Name:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(53, 117);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(84, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Course ECs:";
            // 
            // lblInformation
            // 
            this.lblInformation.AutoSize = true;
            this.lblInformation.Location = new System.Drawing.Point(53, 346);
            this.lblInformation.Name = "lblInformation";
            this.lblInformation.Size = new System.Drawing.Size(343, 20);
            this.lblInformation.TabIndex = 2;
            this.lblInformation.Text = "label to display information about a course-object";
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(53, 184);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(343, 29);
            this.btnCreate.TabIndex = 3;
            this.btnCreate.Text = "Create Course-Object";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // btnShow
            // 
            this.btnShow.Location = new System.Drawing.Point(53, 262);
            this.btnShow.Name = "btnShow";
            this.btnShow.Size = new System.Drawing.Size(343, 29);
            this.btnShow.TabIndex = 4;
            this.btnShow.Text = "Show information of course-object";
            this.btnShow.UseVisualStyleBackColor = true;
            this.btnShow.Click += new System.EventHandler(this.btnShow_Click);
            // 
            // txtbName
            // 
            this.txtbName.Location = new System.Drawing.Point(271, 49);
            this.txtbName.Name = "txtbName";
            this.txtbName.Size = new System.Drawing.Size(125, 27);
            this.txtbName.TabIndex = 5;
            this.txtbName.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // txtbCredits
            // 
            this.txtbCredits.Location = new System.Drawing.Point(271, 114);
            this.txtbCredits.Name = "txtbCredits";
            this.txtbCredits.Size = new System.Drawing.Size(125, 27);
            this.txtbCredits.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(477, 450);
            this.Controls.Add(this.txtbCredits);
            this.Controls.Add(this.txtbName);
            this.Controls.Add(this.btnShow);
            this.Controls.Add(this.btnCreate);
            this.Controls.Add(this.lblInformation);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label label1;
        private Label label2;
        private Label lblInformation;
        private Button btnCreate;
        private Button btnShow;
        private TextBox txtbName;
        private TextBox txtbCredits;
    }
}