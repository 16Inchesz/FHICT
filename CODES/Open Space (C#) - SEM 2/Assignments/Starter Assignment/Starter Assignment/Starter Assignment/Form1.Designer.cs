namespace Starter_Assignment
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
            this.tbStudentName = new System.Windows.Forms.TextBox();
            this.tbStudentNumber = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbStudents = new System.Windows.Forms.ListBox();
            this.lbGroups = new System.Windows.Forms.ListBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lblStudentTotal = new System.Windows.Forms.Label();
            this.lblGroupTotal = new System.Windows.Forms.Label();
            this.btnAddStudent = new System.Windows.Forms.Button();
            this.tbSearchedStudent = new System.Windows.Forms.TextBox();
            this.btnSearchStudent = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.lblSearchedStudent = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.lblSearchedGroup = new System.Windows.Forms.ListBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnSearchGroup = new System.Windows.Forms.Button();
            this.tbSearchedGroup = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // tbStudentName
            // 
            this.tbStudentName.Location = new System.Drawing.Point(134, 26);
            this.tbStudentName.Name = "tbStudentName";
            this.tbStudentName.Size = new System.Drawing.Size(100, 22);
            this.tbStudentName.TabIndex = 0;
            // 
            // tbStudentNumber
            // 
            this.tbStudentNumber.Location = new System.Drawing.Point(134, 55);
            this.tbStudentNumber.Name = "tbStudentNumber";
            this.tbStudentNumber.Size = new System.Drawing.Size(100, 22);
            this.tbStudentNumber.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(6, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(108, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "Student Name:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(6, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(121, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Student Number:";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // lbStudents
            // 
            this.lbStudents.FormattingEnabled = true;
            this.lbStudents.ItemHeight = 16;
            this.lbStudents.Location = new System.Drawing.Point(314, 48);
            this.lbStudents.Name = "lbStudents";
            this.lbStudents.Size = new System.Drawing.Size(228, 276);
            this.lbStudents.TabIndex = 4;
            // 
            // lbGroups
            // 
            this.lbGroups.FormattingEnabled = true;
            this.lbGroups.ItemHeight = 16;
            this.lbGroups.Location = new System.Drawing.Point(611, 48);
            this.lbGroups.Name = "lbGroups";
            this.lbGroups.Size = new System.Drawing.Size(231, 276);
            this.lbGroups.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(314, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 16);
            this.label3.TabIndex = 7;
            this.label3.Text = "STUDENTS";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(608, 13);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 16);
            this.label4.TabIndex = 8;
            this.label4.Text = "GROUPS";
            // 
            // lblStudentTotal
            // 
            this.lblStudentTotal.AutoSize = true;
            this.lblStudentTotal.Location = new System.Drawing.Point(510, 13);
            this.lblStudentTotal.Name = "lblStudentTotal";
            this.lblStudentTotal.Size = new System.Drawing.Size(32, 16);
            this.lblStudentTotal.TabIndex = 10;
            this.lblStudentTotal.Text = "total";
            // 
            // lblGroupTotal
            // 
            this.lblGroupTotal.AutoSize = true;
            this.lblGroupTotal.Location = new System.Drawing.Point(810, 13);
            this.lblGroupTotal.Name = "lblGroupTotal";
            this.lblGroupTotal.Size = new System.Drawing.Size(32, 16);
            this.lblGroupTotal.TabIndex = 11;
            this.lblGroupTotal.Text = "total";
            // 
            // btnAddStudent
            // 
            this.btnAddStudent.Location = new System.Drawing.Point(6, 83);
            this.btnAddStudent.Name = "btnAddStudent";
            this.btnAddStudent.Size = new System.Drawing.Size(227, 42);
            this.btnAddStudent.TabIndex = 14;
            this.btnAddStudent.Text = "Add Student";
            this.btnAddStudent.UseVisualStyleBackColor = true;
            this.btnAddStudent.Click += new System.EventHandler(this.btnAddStudent_Click);
            // 
            // tbSearchedStudent
            // 
            this.tbSearchedStudent.Location = new System.Drawing.Point(6, 33);
            this.tbSearchedStudent.Name = "tbSearchedStudent";
            this.tbSearchedStudent.Size = new System.Drawing.Size(227, 22);
            this.tbSearchedStudent.TabIndex = 15;
            // 
            // btnSearchStudent
            // 
            this.btnSearchStudent.Location = new System.Drawing.Point(6, 74);
            this.btnSearchStudent.Name = "btnSearchStudent";
            this.btnSearchStudent.Size = new System.Drawing.Size(227, 38);
            this.btnSearchStudent.TabIndex = 17;
            this.btnSearchStudent.Text = "Search Student#";
            this.btnSearchStudent.UseVisualStyleBackColor = true;
            this.btnSearchStudent.Click += new System.EventHandler(this.btnSearchStudent_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.tbSearchedStudent);
            this.groupBox1.Controls.Add(this.btnSearchStudent);
            this.groupBox1.Location = new System.Drawing.Point(31, 194);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(240, 130);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Search Student";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.btnAddStudent);
            this.groupBox2.Controls.Add(this.tbStudentNumber);
            this.groupBox2.Controls.Add(this.tbStudentName);
            this.groupBox2.Location = new System.Drawing.Point(31, 48);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(240, 140);
            this.groupBox2.TabIndex = 19;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Add Student";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.lblSearchedStudent);
            this.groupBox3.Location = new System.Drawing.Point(901, 48);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(215, 152);
            this.groupBox3.TabIndex = 20;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Student Searched";
            // 
            // lblSearchedStudent
            // 
            this.lblSearchedStudent.AutoSize = true;
            this.lblSearchedStudent.Location = new System.Drawing.Point(6, 26);
            this.lblSearchedStudent.Name = "lblSearchedStudent";
            this.lblSearchedStudent.Size = new System.Drawing.Size(125, 16);
            this.lblSearchedStudent.TabIndex = 0;
            this.lblSearchedStudent.Text = "lblSearchedStudent";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.lblSearchedGroup);
            this.groupBox4.Location = new System.Drawing.Point(901, 217);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(215, 212);
            this.groupBox4.TabIndex = 21;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Group Searched";
            // 
            // lblSearchedGroup
            // 
            this.lblSearchedGroup.FormattingEnabled = true;
            this.lblSearchedGroup.ItemHeight = 16;
            this.lblSearchedGroup.Location = new System.Drawing.Point(7, 22);
            this.lblSearchedGroup.Name = "lblSearchedGroup";
            this.lblSearchedGroup.Size = new System.Drawing.Size(202, 164);
            this.lblSearchedGroup.TabIndex = 0;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnSearchGroup);
            this.groupBox5.Controls.Add(this.tbSearchedGroup);
            this.groupBox5.Location = new System.Drawing.Point(31, 344);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(240, 112);
            this.groupBox5.TabIndex = 22;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Search Group";
            // 
            // btnSearchGroup
            // 
            this.btnSearchGroup.Location = new System.Drawing.Point(9, 61);
            this.btnSearchGroup.Name = "btnSearchGroup";
            this.btnSearchGroup.Size = new System.Drawing.Size(224, 39);
            this.btnSearchGroup.TabIndex = 1;
            this.btnSearchGroup.Text = "Search Group";
            this.btnSearchGroup.UseVisualStyleBackColor = true;
            this.btnSearchGroup.Click += new System.EventHandler(this.button1_Click);
            // 
            // tbSearchedGroup
            // 
            this.tbSearchedGroup.Location = new System.Drawing.Point(6, 22);
            this.tbSearchedGroup.Name = "tbSearchedGroup";
            this.tbSearchedGroup.Size = new System.Drawing.Size(227, 22);
            this.tbSearchedGroup.TabIndex = 0;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(314, 366);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 16);
            this.label6.TabIndex = 23;
            this.label6.Text = "label6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(463, 13);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(41, 16);
            this.label7.TabIndex = 24;
            this.label7.Text = "Total:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(763, 13);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 16);
            this.label8.TabIndex = 25;
            this.label8.Text = "Total:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1128, 483);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.lblGroupTotal);
            this.Controls.Add(this.lblStudentTotal);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lbGroups);
            this.Controls.Add(this.lbStudents);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbStudentName;
        private System.Windows.Forms.TextBox tbStudentNumber;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox lbStudents;
        private System.Windows.Forms.ListBox lbGroups;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblStudentTotal;
        private System.Windows.Forms.Label lblGroupTotal;
        private System.Windows.Forms.Button btnAddStudent;
        private System.Windows.Forms.TextBox tbSearchedStudent;
        private System.Windows.Forms.Button btnSearchStudent;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label lblSearchedStudent;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ListBox lblSearchedGroup;
        private System.Windows.Forms.TextBox tbSearchedGroup;
        internal System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnSearchGroup;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
    }
}

