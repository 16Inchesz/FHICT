namespace method_practice
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
            this.lblCheckingBalance = new System.Windows.Forms.Label();
            this.lblSavingsBalance = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.rbChecking = new System.Windows.Forms.RadioButton();
            this.rbSavings = new System.Windows.Forms.RadioButton();
            this.tbAmount = new System.Windows.Forms.TextBox();
            this.btnDeposit = new System.Windows.Forms.Button();
            this.btnWithdraw = new System.Windows.Forms.Button();
            this.lblInfo = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 9F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(45, 63);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(198, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Checking account balance:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 9F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(45, 112);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(188, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Savings account balance:";
            // 
            // lblCheckingBalance
            // 
            this.lblCheckingBalance.AutoSize = true;
            this.lblCheckingBalance.Location = new System.Drawing.Point(274, 63);
            this.lblCheckingBalance.Name = "lblCheckingBalance";
            this.lblCheckingBalance.Size = new System.Drawing.Size(36, 20);
            this.lblCheckingBalance.TabIndex = 2;
            this.lblCheckingBalance.Text = "0.00";
            // 
            // lblSavingsBalance
            // 
            this.lblSavingsBalance.AutoSize = true;
            this.lblSavingsBalance.Location = new System.Drawing.Point(274, 112);
            this.lblSavingsBalance.Name = "lblSavingsBalance";
            this.lblSavingsBalance.Size = new System.Drawing.Size(36, 20);
            this.lblSavingsBalance.TabIndex = 3;
            this.lblSavingsBalance.Text = "0.00";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label5.Location = new System.Drawing.Point(45, 167);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(188, 20);
            this.label5.TabIndex = 4;
            this.label5.Text = "Pease select a bank account";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label6.Location = new System.Drawing.Point(45, 274);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(117, 20);
            this.label6.TabIndex = 5;
            this.label6.Text = "Amount in euros:";
            // 
            // rbChecking
            // 
            this.rbChecking.AutoSize = true;
            this.rbChecking.Location = new System.Drawing.Point(66, 200);
            this.rbChecking.Name = "rbChecking";
            this.rbChecking.Size = new System.Drawing.Size(146, 24);
            this.rbChecking.TabIndex = 6;
            this.rbChecking.TabStop = true;
            this.rbChecking.Text = "Checking account";
            this.rbChecking.UseVisualStyleBackColor = true;
            // 
            // rbSavings
            // 
            this.rbSavings.AutoSize = true;
            this.rbSavings.Location = new System.Drawing.Point(66, 230);
            this.rbSavings.Name = "rbSavings";
            this.rbSavings.Size = new System.Drawing.Size(136, 24);
            this.rbSavings.TabIndex = 7;
            this.rbSavings.TabStop = true;
            this.rbSavings.Text = "Savings account";
            this.rbSavings.UseVisualStyleBackColor = true;
            // 
            // tbAmount
            // 
            this.tbAmount.Location = new System.Drawing.Point(66, 297);
            this.tbAmount.Name = "tbAmount";
            this.tbAmount.Size = new System.Drawing.Size(185, 27);
            this.tbAmount.TabIndex = 8;
            // 
            // btnDeposit
            // 
            this.btnDeposit.Location = new System.Drawing.Point(45, 330);
            this.btnDeposit.Name = "btnDeposit";
            this.btnDeposit.Size = new System.Drawing.Size(94, 29);
            this.btnDeposit.TabIndex = 9;
            this.btnDeposit.Text = "Deposit";
            this.btnDeposit.UseVisualStyleBackColor = true;
            this.btnDeposit.Click += new System.EventHandler(this.btnDeposit_Click);
            // 
            // btnWithdraw
            // 
            this.btnWithdraw.Location = new System.Drawing.Point(157, 330);
            this.btnWithdraw.Name = "btnWithdraw";
            this.btnWithdraw.Size = new System.Drawing.Size(94, 29);
            this.btnWithdraw.TabIndex = 10;
            this.btnWithdraw.Text = "Withdraw";
            this.btnWithdraw.UseVisualStyleBackColor = true;
            this.btnWithdraw.Click += new System.EventHandler(this.btnWithdraw_Click);
            // 
            // lblInfo
            // 
            this.lblInfo.AutoSize = true;
            this.lblInfo.Location = new System.Drawing.Point(29, 396);
            this.lblInfo.Name = "lblInfo";
            this.lblInfo.Size = new System.Drawing.Size(87, 20);
            this.lblInfo.TabIndex = 11;
            this.lblInfo.Text = "Information";
            this.lblInfo.Click += new System.EventHandler(this.lblInfo_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(334, 463);
            this.Controls.Add(this.lblInfo);
            this.Controls.Add(this.btnWithdraw);
            this.Controls.Add(this.btnDeposit);
            this.Controls.Add(this.tbAmount);
            this.Controls.Add(this.rbSavings);
            this.Controls.Add(this.rbChecking);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lblSavingsBalance);
            this.Controls.Add(this.lblCheckingBalance);
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
        private Label lblCheckingBalance;
        private Label label2;
        private Label lblSavingsBalance;
       // private Label lblCheckingBalance;
        private RadioButton rbCheckingAccount;
        private RadioButton rbSavingsAccount;
       // private Label lblSavingsBalance;
        private TextBox tbAmount;
        private Button btnDeposit;
        private Button btnWithdraw;
        private Label lblInfo;
        private Label label5;
        private Label label6;
        private RadioButton rbChecking;
        private RadioButton rbSavings;
        //private Button btnDeposit;
        //private Button btnWithdraw;
    }
}