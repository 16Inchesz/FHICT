namespace Container_shipping_assignment
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
            this.components = new System.ComponentModel.Container();
            this.btnStartConnection = new System.Windows.Forms.Button();
            this.lbContainers = new System.Windows.Forms.ListBox();
            this.btnGetReport = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // btnStartConnection
            // 
            this.btnStartConnection.Location = new System.Drawing.Point(33, 34);
            this.btnStartConnection.Name = "btnStartConnection";
            this.btnStartConnection.Size = new System.Drawing.Size(764, 51);
            this.btnStartConnection.TabIndex = 1;
            this.btnStartConnection.Text = "Connect";
            this.btnStartConnection.UseVisualStyleBackColor = true;
            this.btnStartConnection.Click += new System.EventHandler(this.btnStartConnection_Click);
            // 
            // lbContainers
            // 
            this.lbContainers.FormattingEnabled = true;
            this.lbContainers.ItemHeight = 20;
            this.lbContainers.Location = new System.Drawing.Point(33, 119);
            this.lbContainers.Name = "lbContainers";
            this.lbContainers.Size = new System.Drawing.Size(755, 124);
            this.lbContainers.TabIndex = 2;
            // 
            // btnGetReport
            // 
            this.btnGetReport.Location = new System.Drawing.Point(33, 295);
            this.btnGetReport.Name = "btnGetReport";
            this.btnGetReport.Size = new System.Drawing.Size(755, 60);
            this.btnGetReport.TabIndex = 3;
            this.btnGetReport.Text = "Get Report";
            this.btnGetReport.UseVisualStyleBackColor = true;
            this.btnGetReport.Click += new System.EventHandler(this.btnGetReport_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 382);
            this.Controls.Add(this.btnGetReport);
            this.Controls.Add(this.lbContainers);
            this.Controls.Add(this.btnStartConnection);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private Button btnStartConnection;
        private ListBox lbContainers;
        private Button btnGetReport;
        private System.Windows.Forms.Timer timer1;
    }
}