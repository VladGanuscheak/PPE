namespace lab6
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.bt1 = new System.Windows.Forms.Button();
            this.bt2 = new System.Windows.Forms.Button();
            this.bt3 = new System.Windows.Forms.Button();
            this.bt4 = new System.Windows.Forms.Button();
            this.bt5 = new System.Windows.Forms.Button();
            this.bt6 = new System.Windows.Forms.Button();
            this.lose = new System.Windows.Forms.PictureBox();
            this.perfect = new System.Windows.Forms.PictureBox();
            this.pb3 = new System.Windows.Forms.PictureBox();
            this.pb2 = new System.Windows.Forms.PictureBox();
            this.pb1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.View = new System.Windows.Forms.ToolStripMenuItem();
            this.Exit = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Game = new System.Windows.Forms.ToolStripMenuItem();
            this.Author = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.lose)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.perfect)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // bt1
            // 
            this.bt1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt1.Location = new System.Drawing.Point(95, 479);
            this.bt1.Name = "bt1";
            this.bt1.Size = new System.Drawing.Size(115, 80);
            this.bt1.TabIndex = 0;
            this.bt1.Text = "confirm";
            this.bt1.UseVisualStyleBackColor = true;
            this.bt1.Click += new System.EventHandler(this.bt1_Click);
            // 
            // bt2
            // 
            this.bt2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt2.Location = new System.Drawing.Point(441, 479);
            this.bt2.Name = "bt2";
            this.bt2.Size = new System.Drawing.Size(115, 80);
            this.bt2.TabIndex = 1;
            this.bt2.Text = "confirm";
            this.bt2.UseVisualStyleBackColor = true;
            this.bt2.Click += new System.EventHandler(this.bt2_Click);
            // 
            // bt3
            // 
            this.bt3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt3.Location = new System.Drawing.Point(777, 479);
            this.bt3.Name = "bt3";
            this.bt3.Size = new System.Drawing.Size(115, 80);
            this.bt3.TabIndex = 5;
            this.bt3.Text = "confirm";
            this.bt3.UseVisualStyleBackColor = true;
            this.bt3.Click += new System.EventHandler(this.bt3_Click);
            // 
            // bt4
            // 
            this.bt4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt4.Location = new System.Drawing.Point(32, 342);
            this.bt4.Name = "bt4";
            this.bt4.Size = new System.Drawing.Size(245, 120);
            this.bt4.TabIndex = 6;
            this.bt4.Text = "0";
            this.bt4.UseVisualStyleBackColor = true;
            this.bt4.Click += new System.EventHandler(this.bt4_Click);
            // 
            // bt5
            // 
            this.bt5.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt5.Location = new System.Drawing.Point(374, 342);
            this.bt5.Name = "bt5";
            this.bt5.Size = new System.Drawing.Size(245, 120);
            this.bt5.TabIndex = 7;
            this.bt5.Text = "0";
            this.bt5.UseVisualStyleBackColor = true;
            this.bt5.Click += new System.EventHandler(this.bt5_Click_1);
            // 
            // bt6
            // 
            this.bt6.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt6.Location = new System.Drawing.Point(712, 342);
            this.bt6.Name = "bt6";
            this.bt6.Size = new System.Drawing.Size(245, 120);
            this.bt6.TabIndex = 8;
            this.bt6.Text = "0";
            this.bt6.UseVisualStyleBackColor = true;
            this.bt6.Click += new System.EventHandler(this.bt6_Click_1);
            // 
            // lose
            // 
            this.lose.Image = global::lab6.Properties.Resources.lose;
            this.lose.Location = new System.Drawing.Point(238, 52);
            this.lose.Name = "lose";
            this.lose.Size = new System.Drawing.Size(509, 507);
            this.lose.TabIndex = 10;
            this.lose.TabStop = false;
            this.lose.Visible = false;
            // 
            // perfect
            // 
            this.perfect.Image = global::lab6.Properties.Resources.perfect;
            this.perfect.Location = new System.Drawing.Point(90, 171);
            this.perfect.Name = "perfect";
            this.perfect.Size = new System.Drawing.Size(802, 291);
            this.perfect.TabIndex = 9;
            this.perfect.TabStop = false;
            this.perfect.Visible = false;
            // 
            // pb3
            // 
            this.pb3.Image = global::lab6.Properties.Resources.s;
            this.pb3.Location = new System.Drawing.Point(712, 51);
            this.pb3.Name = "pb3";
            this.pb3.Size = new System.Drawing.Size(235, 235);
            this.pb3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pb3.TabIndex = 4;
            this.pb3.TabStop = false;
            // 
            // pb2
            // 
            this.pb2.Image = global::lab6.Properties.Resources.s;
            this.pb2.Location = new System.Drawing.Point(374, 51);
            this.pb2.Name = "pb2";
            this.pb2.Size = new System.Drawing.Size(235, 235);
            this.pb2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pb2.TabIndex = 3;
            this.pb2.TabStop = false;
            // 
            // pb1
            // 
            this.pb1.Image = global::lab6.Properties.Resources.s;
            this.pb1.Location = new System.Drawing.Point(32, 51);
            this.pb1.Name = "pb1";
            this.pb1.Size = new System.Drawing.Size(235, 235);
            this.pb1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pb1.TabIndex = 2;
            this.pb1.TabStop = false;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(982, 24);
            this.menuStrip1.TabIndex = 11;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.View,
            this.Exit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // View
            // 
            this.View.Checked = true;
            this.View.CheckState = System.Windows.Forms.CheckState.Checked;
            this.View.Name = "View";
            this.View.Size = new System.Drawing.Size(152, 22);
            this.View.Text = "View";
            this.View.Click += new System.EventHandler(this.View_Click);
            // 
            // Exit
            // 
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(152, 22);
            this.Exit.Text = "Exit      Ctrl+X";
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Game,
            this.Author});
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(52, 20);
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // Game
            // 
            this.Game.Name = "Game";
            this.Game.Size = new System.Drawing.Size(152, 22);
            this.Game.Text = "Game";
            this.Game.Click += new System.EventHandler(this.Game_Click);
            // 
            // Author
            // 
            this.Author.Name = "Author";
            this.Author.Size = new System.Drawing.Size(152, 22);
            this.Author.Text = "Author";
            this.Author.Click += new System.EventHandler(this.Author_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(982, 612);
            this.Controls.Add(this.lose);
            this.Controls.Add(this.perfect);
            this.Controls.Add(this.bt6);
            this.Controls.Add(this.bt5);
            this.Controls.Add(this.bt4);
            this.Controls.Add(this.bt3);
            this.Controls.Add(this.pb3);
            this.Controls.Add(this.pb2);
            this.Controls.Add(this.pb1);
            this.Controls.Add(this.bt2);
            this.Controls.Add(this.bt1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "[Nim Game] PPE Lab6 Ganusceac Vlad";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.lose)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.perfect)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bt1;
        private System.Windows.Forms.Button bt2;
        private System.Windows.Forms.PictureBox pb1;
        private System.Windows.Forms.PictureBox pb2;
        private System.Windows.Forms.PictureBox pb3;
        private System.Windows.Forms.Button bt3;
        private System.Windows.Forms.Button bt4;
        private System.Windows.Forms.Button bt5;
        private System.Windows.Forms.Button bt6;
        private System.Windows.Forms.PictureBox perfect;
        private System.Windows.Forms.PictureBox lose;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem View;
        private System.Windows.Forms.ToolStripMenuItem Exit;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem Game;
        private System.Windows.Forms.ToolStripMenuItem Author;
    }
}

