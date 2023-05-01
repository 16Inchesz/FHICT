namespace Assignment_2A_SEM2
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
            this.BTN_Start = new System.Windows.Forms.Button();
            this.ListBoxInput = new System.Windows.Forms.ListBox();
            this.BTN_show_containers = new System.Windows.Forms.Button();
            this.ListBoxContainers = new System.Windows.Forms.ListBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // BTN_Start
            // 
            this.BTN_Start.Location = new System.Drawing.Point(78, 86);
            this.BTN_Start.Name = "BTN_Start";
            this.BTN_Start.Size = new System.Drawing.Size(106, 70);
            this.BTN_Start.TabIndex = 0;
            this.BTN_Start.Text = "Start connection";
            this.BTN_Start.UseVisualStyleBackColor = true;
            this.BTN_Start.Click += new System.EventHandler(this.BTN_Start_Click);
            // 
            // ListBoxInput
            // 
            this.ListBoxInput.FormattingEnabled = true;
            this.ListBoxInput.ItemHeight = 16;
            this.ListBoxInput.Location = new System.Drawing.Point(257, 12);
            this.ListBoxInput.Name = "ListBoxInput";
            this.ListBoxInput.Size = new System.Drawing.Size(442, 276);
            this.ListBoxInput.TabIndex = 1;
            // 
            // BTN_show_containers
            // 
            this.BTN_show_containers.Location = new System.Drawing.Point(35, 323);
            this.BTN_show_containers.Name = "BTN_show_containers";
            this.BTN_show_containers.Size = new System.Drawing.Size(106, 70);
            this.BTN_show_containers.TabIndex = 2;
            this.BTN_show_containers.Text = "Show containers";
            this.BTN_show_containers.UseVisualStyleBackColor = true;
            this.BTN_show_containers.Click += new System.EventHandler(this.BTN_show_containers_Click);
            // 
            // ListBoxContainers
            // 
            this.ListBoxContainers.FormattingEnabled = true;
            this.ListBoxContainers.ItemHeight = 16;
            this.ListBoxContainers.Location = new System.Drawing.Point(147, 323);
            this.ListBoxContainers.Name = "ListBoxContainers";
            this.ListBoxContainers.Size = new System.Drawing.Size(677, 276);
            this.ListBoxContainers.TabIndex = 3;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(836, 709);
            this.Controls.Add(this.ListBoxContainers);
            this.Controls.Add(this.BTN_show_containers);
            this.Controls.Add(this.ListBoxInput);
            this.Controls.Add(this.BTN_Start);
            this.Name = "Form1";
            this.Text = "Sockets";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BTN_Start;
        private System.Windows.Forms.ListBox ListBoxInput;
        private System.Windows.Forms.Button BTN_show_containers;
        private System.Windows.Forms.ListBox ListBoxContainers;
        private System.Windows.Forms.Timer timer1;
    }
}

