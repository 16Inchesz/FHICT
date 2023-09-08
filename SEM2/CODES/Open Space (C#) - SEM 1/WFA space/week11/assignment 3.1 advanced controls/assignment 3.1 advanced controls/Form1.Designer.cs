namespace assignment_3._1_advanced_controls
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
            this.cmbColor = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.rbOranges = new System.Windows.Forms.RadioButton();
            this.rbBananas = new System.Windows.Forms.RadioButton();
            this.rbApples = new System.Windows.Forms.RadioButton();
            this.btnAdd = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.lbItems = new System.Windows.Forms.ListBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.cbUppercase = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // cmbColor
            // 
            this.cmbColor.FormattingEnabled = true;
            this.cmbColor.Items.AddRange(new object[] {
            "green",
            "blue",
            "red",
            "yellow",
            "purple",
            "black",
            "orange"});
            this.cmbColor.Location = new System.Drawing.Point(206, 35);
            this.cmbColor.Name = "cmbColor";
            this.cmbColor.Size = new System.Drawing.Size(151, 28);
            this.cmbColor.TabIndex = 0;
            this.cmbColor.SelectedIndexChanged += new System.EventHandler(this.cmbColor_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(22, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(111, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Choose a color:";
            // 
            // rbOranges
            // 
            this.rbOranges.AutoSize = true;
            this.rbOranges.Location = new System.Drawing.Point(240, 363);
            this.rbOranges.Name = "rbOranges";
            this.rbOranges.Size = new System.Drawing.Size(85, 24);
            this.rbOranges.TabIndex = 2;
            this.rbOranges.TabStop = true;
            this.rbOranges.Text = "Oranges";
            this.rbOranges.UseVisualStyleBackColor = true;
            // 
            // rbBananas
            // 
            this.rbBananas.AutoSize = true;
            this.rbBananas.Location = new System.Drawing.Point(127, 363);
            this.rbBananas.Name = "rbBananas";
            this.rbBananas.Size = new System.Drawing.Size(85, 24);
            this.rbBananas.TabIndex = 3;
            this.rbBananas.TabStop = true;
            this.rbBananas.Text = "Bananas";
            this.rbBananas.UseVisualStyleBackColor = true;
            // 
            // rbApples
            // 
            this.rbApples.AutoSize = true;
            this.rbApples.Location = new System.Drawing.Point(22, 363);
            this.rbApples.Name = "rbApples";
            this.rbApples.Size = new System.Drawing.Size(76, 24);
            this.rbApples.TabIndex = 4;
            this.rbApples.TabStop = true;
            this.rbApples.Text = "Apples";
            this.rbApples.UseVisualStyleBackColor = true;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(22, 137);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(335, 29);
            this.btnAdd.TabIndex = 5;
            this.btnAdd.Text = "Add items to listbox";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(22, 312);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(272, 20);
            this.label2.TabIndex = 6;
            this.label2.Text = "Select a fruit to be added to the listbox:";
            // 
            // lbItems
            // 
            this.lbItems.FormattingEnabled = true;
            this.lbItems.ItemHeight = 20;
            this.lbItems.Location = new System.Drawing.Point(431, 35);
            this.lbItems.Name = "lbItems";
            this.lbItems.Size = new System.Drawing.Size(239, 304);
            this.lbItems.TabIndex = 7;
            this.lbItems.SelectedIndexChanged += new System.EventHandler(this.lbItems_SelectedIndexChanged);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(431, 377);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(239, 29);
            this.btnClear.TabIndex = 8;
            this.btnClear.Text = "Clear listbox";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // cbUppercase
            // 
            this.cbUppercase.AutoSize = true;
            this.cbUppercase.Location = new System.Drawing.Point(230, 88);
            this.cbUppercase.Name = "cbUppercase";
            this.cbUppercase.Size = new System.Drawing.Size(127, 24);
            this.cbUppercase.TabIndex = 9;
            this.cbUppercase.Text = "to UPPERCASE";
            this.cbUppercase.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.cbUppercase);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.lbItems);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.rbApples);
            this.Controls.Add(this.rbBananas);
            this.Controls.Add(this.rbOranges);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cmbColor);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private ComboBox cmbColor;
        private Label label1;
        private RadioButton rbOranges;
        private RadioButton rbBananas;
        private RadioButton rbApples;
        private Button btnAdd;
        private Label label2;
        private ListBox lbItems;
        private Button btnClear;
        private CheckBox cbUppercase;
    }
}