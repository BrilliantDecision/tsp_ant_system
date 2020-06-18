#pragma once
#include "graph.h"
#include "windows.h"
#include <string>
#include <fstream>

namespace simulatedAnnealingAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		//0-result
		int lookResult;
		int allLook;
		int switcher;

		double endTimeAntStandard;
		double endTimeAntModify;

		bool standard;
		bool modify;

		int it;
		int a;
		int b;
		int q;
		double p;
		double pheromone_min;
		int elite_ants;
		int ant_squad;
		double maxPher;
		int max;

		bool automaticInput;
		bool drawPath;
		bool drawLastRaw;
		int penSize;
		int circleSize;
		int accuracy;


		Graphics^ gp;
		graph^ g;  //Граф для рисования
		Pen^ pushCirclePen;	//Рисует вершину
		SolidBrush^ fillCircleBrush; //Заполняет вершину
		Pen^ pushRawPen; //Рисует дугу
		Pen^ popRawPen;  //Стирает дугу

		Pen^ drawRawMainAntStandard;
		Pen^ drawRawMainAntModify;

		vector<int>* current;
		vector<int>* last;
		
		vector<int>* looks;

		vector<int>* oldPath;
		vector<vector<int>>* oldPoints;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonLookLeft;
	private: System::Windows::Forms::Button^ buttonLookRight;
	private: System::Windows::Forms::TextBox^ pictureName;
	//ProgresBar
	public: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::TextBox^ progress;
	private: System::Windows::Forms::NumericUpDown^ numeric_a;

	private: System::Windows::Forms::NumericUpDown^ numeric_iterations;
	private: System::Windows::Forms::NumericUpDown^ numeric_min_phen;
	private: System::Windows::Forms::NumericUpDown^ numeric_p;
	private: System::Windows::Forms::NumericUpDown^ numeric_b;





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox_modify;
	private: System::Windows::Forms::CheckBox^ checkBox_standard;
	private: System::Windows::Forms::CheckBox^ checkBox_path;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numeric_q;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ numeric_elite_ants;
	private: System::Windows::Forms::NumericUpDown^ numeric_ant_squad;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::NumericUpDown^ numeric_max_phen;


	private: System::ComponentModel::IContainer^ components;
	public:
		MainForm(void)
		{
			InitializeComponent();
			automaticInput = true;
			lookResult = 0;
			allLook = 0;
			switcher = 0; //Clich on the switch button
			drawPath = true;
			drawLastRaw = false;
			penSize = 3;
			circleSize = 3;
			accuracy = circleSize / 2;
			// In the handle input
			current = new vector<int>(2, 0);  
			last = new vector<int>(2, -1);
			//
			looks = new vector<int>();
			oldPath = new vector<int>();
			oldPoints = new vector<vector<int>>();
			g = gcnew graph();
			gp = this->pictureBox1->CreateGraphics();
			pushCirclePen = gcnew Pen(Color::Black, penSize);
			pushRawPen = gcnew Pen(Color::Black, 1);
			popRawPen = gcnew Pen(Color::White, 3);

			//Colors of the algorithms raws
			drawRawMainAntStandard = gcnew Pen(Color::ForestGreen);
			drawRawMainAntModify = gcnew Pen(Color::Red);
			fillCircleBrush = gcnew SolidBrush(Color::Black);
			gp->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			g->~graph();
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numeric_max_phen = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numeric_elite_ants = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_standard = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_modify = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_path = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numeric_ant_squad = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numeric_q = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numeric_min_phen = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric_p = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric_b = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric_a = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric_iterations = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonLookLeft = (gcnew System::Windows::Forms::Button());
			this->buttonLookRight = (gcnew System::Windows::Forms::Button());
			this->pictureName = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progress = (gcnew System::Windows::Forms::TextBox());
			this->panel2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_max_phen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_elite_ants))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_ant_squad))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_q))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_min_phen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_p))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_iterations))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->button1->Location = System::Drawing::Point(1237, 21);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(42, 43);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->groupBox4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->ForeColor = System::Drawing::Color::Black;
			this->panel2->Location = System::Drawing::Point(8, 608);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1337, 182);
			this->panel2->TabIndex = 4;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->numeric_max_phen);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->numeric_elite_ants);
			this->groupBox4->Controls->Add(this->checkBox_standard);
			this->groupBox4->Controls->Add(this->checkBox_modify);
			this->groupBox4->Location = System::Drawing::Point(645, 2);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(280, 176);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Программная реализация алгоритма";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(5, 108);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(179, 20);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Максимальное число феромонов";
			// 
			// numeric_max_phen
			// 
			this->numeric_max_phen->DecimalPlaces = 5;
			this->numeric_max_phen->Enabled = false;
			this->numeric_max_phen->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numeric_max_phen->Location = System::Drawing::Point(191, 105);
			this->numeric_max_phen->Name = L"numeric_max_phen";
			this->numeric_max_phen->ReadOnly = true;
			this->numeric_max_phen->Size = System::Drawing::Size(84, 20);
			this->numeric_max_phen->TabIndex = 12;
			this->numeric_max_phen->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 65536 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(5, 79);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(163, 13);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Количество элитных муравьёв";
			// 
			// numeric_elite_ants
			// 
			this->numeric_elite_ants->Enabled = false;
			this->numeric_elite_ants->Location = System::Drawing::Point(191, 76);
			this->numeric_elite_ants->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numeric_elite_ants->Name = L"numeric_elite_ants";
			this->numeric_elite_ants->ReadOnly = true;
			this->numeric_elite_ants->Size = System::Drawing::Size(84, 20);
			this->numeric_elite_ants->TabIndex = 3;
			this->numeric_elite_ants->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// checkBox_standard
			// 
			this->checkBox_standard->Checked = true;
			this->checkBox_standard->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_standard->Location = System::Drawing::Point(5, 19);
			this->checkBox_standard->Name = L"checkBox_standard";
			this->checkBox_standard->Size = System::Drawing::Size(214, 24);
			this->checkBox_standard->TabIndex = 2;
			this->checkBox_standard->Text = L"Стандартный алгоритм";
			this->checkBox_standard->UseVisualStyleBackColor = true;
			// 
			// checkBox_modify
			// 
			this->checkBox_modify->Location = System::Drawing::Point(5, 46);
			this->checkBox_modify->Name = L"checkBox_modify";
			this->checkBox_modify->Size = System::Drawing::Size(214, 24);
			this->checkBox_modify->TabIndex = 0;
			this->checkBox_modify->Text = L"Модифицированный алгоритм";
			this->checkBox_modify->UseVisualStyleBackColor = true;
			this->checkBox_modify->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_modify_CheckedChanged);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->button3->Location = System::Drawing::Point(1238, 91);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(41, 41);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(929, 6);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(267, 172);
			this->textBox1->TabIndex = 6;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox_path);
			this->groupBox2->Controls->Add(this->checkBox4);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->numericUpDown4);
			this->groupBox2->Location = System::Drawing::Point(378, 2);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(263, 176);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры ввода/вывода";
			// 
			// checkBox_path
			// 
			this->checkBox_path->Location = System::Drawing::Point(7, 24);
			this->checkBox_path->Name = L"checkBox_path";
			this->checkBox_path->Size = System::Drawing::Size(158, 24);
			this->checkBox_path->TabIndex = 5;
			this->checkBox_path->Text = L"Рисовать начальный путь";
			this->checkBox_path->UseVisualStyleBackColor = true;
			this->checkBox_path->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Checked = true;
			this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox4->Location = System::Drawing::Point(7, 53);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(137, 17);
			this->checkBox4->TabIndex = 4;
			this->checkBox4->Text = L"Автоматический ввод";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox4_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(4, 106);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 24);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Задать граф";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(4, 80);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 16);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Количество узлов";
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(104, 79);
			this->numericUpDown4->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(60, 20);
			this->numericUpDown4->TabIndex = 1;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numeric_ant_squad);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->numeric_q);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numeric_min_phen);
			this->groupBox1->Controls->Add(this->numeric_p);
			this->groupBox1->Controls->Add(this->numeric_b);
			this->groupBox1->Controls->Add(this->numeric_a);
			this->groupBox1->Controls->Add(this->numeric_iterations);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(2, 3);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(371, 175);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры алгоритма";
			// 
			// numeric_ant_squad
			// 
			this->numeric_ant_squad->Location = System::Drawing::Point(243, 150);
			this->numeric_ant_squad->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numeric_ant_squad->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_ant_squad->Name = L"numeric_ant_squad";
			this->numeric_ant_squad->Size = System::Drawing::Size(120, 20);
			this->numeric_ant_squad->TabIndex = 6;
			this->numeric_ant_squad->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(7, 106);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Коэффициент q";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(7, 151);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(149, 17);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Число муравьёв в отряде";
			// 
			// numeric_q
			// 
			this->numeric_q->Location = System::Drawing::Point(243, 105);
			this->numeric_q->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			this->numeric_q->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_q->Name = L"numeric_q";
			this->numeric_q->Size = System::Drawing::Size(120, 20);
			this->numeric_q->TabIndex = 21;
			this->numeric_q->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(7, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 17);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Коэффициент а";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(7, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(162, 16);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Число итераций";
			// 
			// numeric_min_phen
			// 
			this->numeric_min_phen->DecimalPlaces = 5;
			this->numeric_min_phen->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numeric_min_phen->Location = System::Drawing::Point(243, 127);
			this->numeric_min_phen->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numeric_min_phen->Name = L"numeric_min_phen";
			this->numeric_min_phen->Size = System::Drawing::Size(120, 20);
			this->numeric_min_phen->TabIndex = 18;
			this->numeric_min_phen->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			// 
			// numeric_p
			// 
			this->numeric_p->DecimalPlaces = 3;
			this->numeric_p->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numeric_p->Location = System::Drawing::Point(243, 83);
			this->numeric_p->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_p->Name = L"numeric_p";
			this->numeric_p->Size = System::Drawing::Size(120, 20);
			this->numeric_p->TabIndex = 17;
			this->numeric_p->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 27, 0, 0, 131072 });
			// 
			// numeric_b
			// 
			this->numeric_b->Location = System::Drawing::Point(243, 60);
			this->numeric_b->Name = L"numeric_b";
			this->numeric_b->Size = System::Drawing::Size(120, 20);
			this->numeric_b->TabIndex = 16;
			this->numeric_b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// numeric_a
			// 
			this->numeric_a->Location = System::Drawing::Point(243, 37);
			this->numeric_a->Name = L"numeric_a";
			this->numeric_a->Size = System::Drawing::Size(120, 20);
			this->numeric_a->TabIndex = 15;
			this->numeric_a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			// 
			// numeric_iterations
			// 
			this->numeric_iterations->Location = System::Drawing::Point(243, 14);
			this->numeric_iterations->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numeric_iterations->Name = L"numeric_iterations";
			this->numeric_iterations->Size = System::Drawing::Size(120, 20);
			this->numeric_iterations->TabIndex = 14;
			this->numeric_iterations->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(7, 127);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(208, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Минимальное количество феромонов";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(7, 83);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 19);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Коэффициент p";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(7, 62);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(192, 19);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Коэффициент b";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(9, 10);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1336, 545);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseDown);
			// 
			// buttonLookLeft
			// 
			this->buttonLookLeft->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonLookLeft.BackgroundImage")));
			this->buttonLookLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLookLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLookLeft->Location = System::Drawing::Point(640, 559);
			this->buttonLookLeft->Margin = System::Windows::Forms::Padding(2);
			this->buttonLookLeft->Name = L"buttonLookLeft";
			this->buttonLookLeft->Size = System::Drawing::Size(32, 32);
			this->buttonLookLeft->TabIndex = 7;
			this->buttonLookLeft->UseVisualStyleBackColor = true;
			this->buttonLookLeft->Click += gcnew System::EventHandler(this, &MainForm::buttonLookLeft_Click);
			// 
			// buttonLookRight
			// 
			this->buttonLookRight->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonLookRight.BackgroundImage")));
			this->buttonLookRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLookRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLookRight->Location = System::Drawing::Point(676, 559);
			this->buttonLookRight->Margin = System::Windows::Forms::Padding(2);
			this->buttonLookRight->Name = L"buttonLookRight";
			this->buttonLookRight->Size = System::Drawing::Size(26, 32);
			this->buttonLookRight->TabIndex = 8;
			this->buttonLookRight->UseVisualStyleBackColor = true;
			this->buttonLookRight->Click += gcnew System::EventHandler(this, &MainForm::buttonLookRight_Click);
			// 
			// pictureName
			// 
			this->pictureName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pictureName->Location = System::Drawing::Point(1124, 559);
			this->pictureName->Margin = System::Windows::Forms::Padding(2);
			this->pictureName->Multiline = true;
			this->pictureName->Name = L"pictureName";
			this->pictureName->Size = System::Drawing::Size(221, 28);
			this->pictureName->TabIndex = 9;
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::White;
			this->progressBar1->Location = System::Drawing::Point(9, 559);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(328, 19);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 10;
			// 
			// progress
			// 
			this->progress->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->progress->Location = System::Drawing::Point(341, 559);
			this->progress->Margin = System::Windows::Forms::Padding(2);
			this->progress->Multiline = true;
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(82, 19);
			this->progress->TabIndex = 11;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1356, 801);
			this->Controls->Add(this->progress);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->pictureName);
			this->Controls->Add(this->buttonLookRight);
			this->Controls->Add(this->buttonLookLeft);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel2);
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TSP solver";
			this->TransparencyKey = System::Drawing::Color::DarkRed;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_max_phen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_elite_ants))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_ant_squad))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_q))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_min_phen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_p))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_iterations))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (g->getSizePoints() != 0)
		{
			//Предварительная очистка
			g->clearMax();
			g->clearAllPath();
			allLook = 0;
			looks->clear();
			switcher = 0;
			progressBar1->Value = 0;
			progress->Clear();
			progress->Text = "";

			//Параметры
			setPatameters();

			//Рисование крайнего ребра при ручном вводе
			if (!drawLastRaw && checkBox_path->Checked == true)
			{
				gp->DrawLine(pushRawPen, g->getPoint(0)[0], g->getPoint(0)[1], g->getPoint(g->getSizePoints() - 1)[0], g->getPoint(g->getSizePoints() - 1)[1]);
				drawLastRaw = true;
			}

			g->setN(g->getSizePoints());

			Sleep(100);

			//Пути и расстояния
			vector<int> path;
			for (int i = 0; i < g->getSizePoints(); i++)
			{
				path.push_back(i);
			}
			(*oldPath) = path;
			(*oldPoints) = g->getPoints();
			g->setAllPaths(path);
			g->clearDistances();
			g->setDistances();

			//Начальный путь
			double startPath = g->allPath(path);

			//Начальное время
			double startTime;
			progressBar1->Maximum = it * (looks->size() - 1);

			//Старт алгоритма
			startTime = omp_get_wtime();
			if (standard) {
				g->ant_algorithm(it, a, b, pheromone_min, q, p, ant_squad, progressBar1);
				endTimeAntStandard = omp_get_wtime() - startTime;
			}
			startTime = omp_get_wtime();
			if (modify) {
				g->ant_algorithm(it, a, b, pheromone_min, q, p, ant_squad, elite_ants, maxPher, progressBar1);
				endTimeAntModify = omp_get_wtime() - startTime;
			}

			//Вывод результата
			drawResult(g);
			g->setPoints(*oldPoints);
		}
	}
	private: void drawResult(graph^ g) {
		textBox1->Clear();
		Pen^ drawRawMainPath;
		double path;
		double seconds;
		double max;
		//Сортировка вершин по определённому пути
		switch (lookResult)
		{
		case 0:
		{
			pictureName->Text = "Исходный граф";
			g->sortPointsByPath(*oldPath);
			path = g->allPath(*oldPath);
			drawRawMainPath = pushRawPen;
			break;
		}
		case 1:
		{
			pictureName->Text = "Стандартный алгоритм";
			g->sortPointsByPath(g->getPath(0));
			path = g->allPath(g->getPath(0));
			seconds = endTimeAntStandard;
			drawRawMainPath = drawRawMainAntStandard;
			max = g->get_max(0);
			break;
		}
		case 2:
		{
			pictureName->Text = "Модифицированный алгоритм";
			g->sortPointsByPath(g->getPath(1));
			path = g->allPath(g->getPath(1));
			seconds = endTimeAntModify;
			drawRawMainPath = drawRawMainAntModify;
			max = g->get_max(1);
			break;
		}
		}
		//Стираем с экрана
		gp->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, 1500, 1500);
		//Выбранный путь
		for (int i = 0; i < g->getSizePoints() - 1; i++)
			gp->DrawLine(drawRawMainPath, g->getPoint(i)[0], g->getPoint(i)[1], g->getPoint(i + 1)[0], g->getPoint(i + 1)[1]);
		gp->DrawLine(drawRawMainPath, g->getPoint(0)[0], g->getPoint(0)[1], g->getPoint(g->getSizePoints() - 1)[0], g->getPoint(g->getSizePoints() - 1)[1]);

		//Вершины
		for (int i = 0; i < g->getSizePoints(); i++)
		{
			gp->DrawEllipse(pushCirclePen, g->getPoint(i)[0] - accuracy, g->getPoint(i)[1] - accuracy, circleSize, circleSize);
			gp->FillEllipse(fillCircleBrush, g->getPoint(i)[0] - accuracy, g->getPoint(i)[1] - accuracy, circleSize, circleSize);
		}
		//Выводим информацию в окно вывода
		if (lookResult == 0)
		{
			textBox1->Text += "Длина заданного пути:" + round(path).ToString() + Environment::NewLine;
		}
		else
		{
			g->sortPointsByPath(*oldPath);
			textBox1->Text += "Длина заданного пути:" + round(g->allPath(*oldPath)).ToString() + Environment::NewLine;
			textBox1->Text += "Длина найденного пути:" + round(path).ToString() + Environment::NewLine;
			int mins = seconds / 60;
			int hours = mins / 60;
			if (hours != 0)
			{
				int temp = 60 * hours;
				mins -= temp;
				temp = 60 * mins;
				seconds -= temp;
				textBox1->Text += "Время: " + round(hours) + " час." + round(mins) + " мин." + round(seconds) + " сек." + Environment::NewLine;
			}
			else if (mins != 0)
			{
				int temp = 60 * mins;
				seconds -= temp;
				textBox1->Text += "Время: " + round(mins) + " мин." + round(seconds) + " сек." + Environment::NewLine;
			}
			else
			{
				textBox1->Text += "Время: " + round(seconds) + " сек." + Environment::NewLine;
			}
			textBox1->Text += "Максимальное значение феромонов:" + Environment::NewLine + max;
		}
		g->setPoints(*oldPoints);
		//progress->Text = "Готово!";
	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (!automaticInput)
		{
			(*current)[0] = e->X;
			(*current)[1] = e->Y;
			g->addVertex(*current);
			if ((*last)[0] >= 0 && (*last)[1] >= 0)
			{
				gp->DrawLine(pushRawPen, (*last)[0], (*last)[1], e->X, e->Y);
				gp->DrawEllipse(pushCirclePen, (*last)[0] - accuracy, (*last)[1] - accuracy, circleSize, circleSize);
				gp->FillEllipse(fillCircleBrush, (*last)[0] - accuracy, (*last)[1] - accuracy, circleSize, circleSize);
			}
			gp->DrawEllipse(pushCirclePen, e->X - accuracy, e->Y - accuracy, circleSize, circleSize);
			gp->FillEllipse(fillCircleBrush, e->X - accuracy, e->Y - accuracy, circleSize, circleSize);
			(*last) = (*current);
		}
	}
	private: System::Void file_list_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureName->Text = "";
		progressBar1->Value = 0;
		progress->Clear();
		progress->Text = "";
		textBox1->Clear();
		drawLastRaw = false;
		allLook = 0;
		switcher = 0;
		looks->clear();
		gp->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, 1500, 1500);
		g->clearAll();
		g->setN(int(numericUpDown4->Value));
		g->setRandomGraph();

		//вершины
		for (int i = 0; i < g->getSizePoints(); i++)
		{
			gp->DrawEllipse(pushCirclePen, g->getPoint(i)[0] - accuracy, g->getPoint(i)[1] - accuracy, circleSize, circleSize);
			gp->FillEllipse(fillCircleBrush, g->getPoint(i)[0] - accuracy, g->getPoint(i)[1] - accuracy, circleSize, circleSize);
		}

		//выбранный путь
		drawPath = checkBox_path->Checked;
		if (drawPath)
		{
			for (int i = 0; i < g->getSizePoints() - 1; i++)
				gp->DrawLine(pushRawPen, g->getPoint(i)[0], g->getPoint(i)[1], g->getPoint(i + 1)[0], g->getPoint(i + 1)[1]);
			gp->DrawLine(pushRawPen, g->getPoint(0)[0], g->getPoint(0)[1], g->getPoint(g->getSizePoints() - 1)[0], g->getPoint(g->getSizePoints() - 1)[1]);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Clear();
		gp->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, 1500, 1500);
		(*current) = { 2, 0 };
		(*last) = { 2, -1 };
		g->clearAll();
		drawLastRaw = false;
		allLook = 0;
		looks->clear();
		switcher = 0;
		pictureName->Text = "";
		progressBar1->Value = 0;
		progress->Text = "";
	}

	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox4->Checked)
		{
			button2->Enabled = true;
			automaticInput = true;
		}
		else
		{
			button2->Enabled = false;
			automaticInput = false;
		}
	}
	private: void setPatameters() {
		//Параметры
		it = int(numeric_iterations->Value);
		a = int(numeric_a->Value);
		b = int(numeric_b->Value);
		q = int(numeric_q->Value);
		p = double(numeric_p->Value);
		pheromone_min = double(numeric_min_phen->Value);
		elite_ants = int(numeric_elite_ants->Value);
		ant_squad = int(numeric_ant_squad->Value);
		maxPher = double(numeric_max_phen->Value);

		//Виды реализации
		standard = checkBox_standard->Checked;
		modify = checkBox_modify->Checked;
		//

		(*looks).push_back((int)allLook);
		//Просмотр изображений
		allLook++;
		if (standard)
		{
			(*looks).push_back((int)allLook);
		}
		allLook++;
		if (modify)
		{
			(*looks).push_back((int)allLook);
		}
		switcher = looks->size() - 1;
		lookResult = (*looks)[switcher];
		//
	}


private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox_path->Checked) drawPath = true;
	else drawPath = false;
}

private: System::Void buttonLookRight_Click(System::Object^ sender, System::EventArgs^ e) {
	if (allLook != 0)
	{
		if (switcher != looks->size() - 1)
		{
			switcher++;
			lookResult = (*looks)[switcher];
			drawResult(g);
		}
	}
}
private: System::Void buttonLookLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	if (allLook != 0)
	{
		if (switcher != 0)
		{
			switcher--;
			lookResult = (*looks)[switcher];
			drawResult(g);
		}
	}
}
private: System::Void checkBox_modify_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (numeric_elite_ants->ReadOnly == true) {
		numeric_elite_ants->ReadOnly = false;
		numeric_elite_ants->Enabled = true;
	}
	else {
		numeric_elite_ants->ReadOnly = true;
		numeric_elite_ants->Enabled = false;
	}
	if (numeric_max_phen->ReadOnly == true) {
		numeric_max_phen->ReadOnly = false;
		numeric_max_phen->Enabled = true;
	}
	else {
		numeric_max_phen->ReadOnly = true;
		numeric_max_phen->Enabled = false;
	}
}
};
}
