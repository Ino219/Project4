#pragma once
#include"calc.h"
#include"Graph.h"

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			c = gcnew calc();
			val_list = gcnew List<double>;
			op_list = gcnew List<String^>;
			ope = gcnew List<String^>;
			ope->Add("+");
			ope->Add("-");
			ope->Add("*");
			ope->Add("/");
			ope->Add("%");
			ope->Add("=");
			n_op = "";
			v_v_list = gcnew  List<List<double>^>;
			o_o_list = gcnew List<List<String^>^>;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::TextBox^  subtext;
	private: System::Windows::Forms::TextBox^  maintext;
	private: System::Windows::Forms::Button^  button_sub;
	private: System::Windows::Forms::Button^  button_mod;
	private: System::Windows::Forms::Button^  button_div;
	private: System::Windows::Forms::Button^  button_multi;
	private: System::Windows::Forms::Button^  button_add;
	private: System::Windows::Forms::Button^  button_eq;
	private: System::Windows::Forms::Button^  button_clear;
	private: System::Windows::Forms::Button^  button_ks;
	private: System::Windows::Forms::Button^  button_ke;
	private: System::Windows::Forms::DataGridView^  dataView;




	private: System::Windows::Forms::Button^  delete_list;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Check;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Answer;
	private: System::Windows::Forms::Button^  list_all;
	private: System::Windows::Forms::Button^  save_list;
	private: System::Windows::Forms::SaveFileDialog^  saveFile;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::OpenFileDialog^  openFile;


	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->subtext = (gcnew System::Windows::Forms::TextBox());
			this->maintext = (gcnew System::Windows::Forms::TextBox());
			this->button_sub = (gcnew System::Windows::Forms::Button());
			this->button_mod = (gcnew System::Windows::Forms::Button());
			this->button_div = (gcnew System::Windows::Forms::Button());
			this->button_multi = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_eq = (gcnew System::Windows::Forms::Button());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->button_ks = (gcnew System::Windows::Forms::Button());
			this->button_ke = (gcnew System::Windows::Forms::Button());
			this->dataView = (gcnew System::Windows::Forms::DataGridView());
			this->Check = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Answer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->delete_list = (gcnew System::Windows::Forms::Button());
			this->list_all = (gcnew System::Windows::Forms::Button());
			this->save_list = (gcnew System::Windows::Forms::Button());
			this->saveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataView))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MistyRose;
			this->button1->Location = System::Drawing::Point(32, 155);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MistyRose;
			this->button2->Location = System::Drawing::Point(108, 155);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 68);
			this->button2->TabIndex = 1;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::MistyRose;
			this->button3->Location = System::Drawing::Point(184, 155);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 68);
			this->button3->TabIndex = 2;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::MistyRose;
			this->button4->Location = System::Drawing::Point(32, 229);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 68);
			this->button4->TabIndex = 5;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::MistyRose;
			this->button5->Location = System::Drawing::Point(108, 229);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 68);
			this->button5->TabIndex = 4;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::MistyRose;
			this->button6->Location = System::Drawing::Point(184, 229);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 68);
			this->button6->TabIndex = 3;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::MistyRose;
			this->button7->Location = System::Drawing::Point(184, 303);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 68);
			this->button7->TabIndex = 8;
			this->button7->Text = L"9";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::MistyRose;
			this->button8->Location = System::Drawing::Point(108, 303);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 68);
			this->button8->TabIndex = 7;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::MistyRose;
			this->button9->Location = System::Drawing::Point(32, 303);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(70, 68);
			this->button9->TabIndex = 6;
			this->button9->Text = L"7";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::MistyRose;
			this->button0->Location = System::Drawing::Point(108, 377);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(70, 68);
			this->button0->TabIndex = 9;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = false;
			this->button0->Click += gcnew System::EventHandler(this, &MyForm::buttons_click);
			// 
			// subtext
			// 
			this->subtext->Location = System::Drawing::Point(32, 40);
			this->subtext->Name = L"subtext";
			this->subtext->Size = System::Drawing::Size(222, 22);
			this->subtext->TabIndex = 10;
			// 
			// maintext
			// 
			this->maintext->Location = System::Drawing::Point(32, 88);
			this->maintext->Name = L"maintext";
			this->maintext->Size = System::Drawing::Size(222, 22);
			this->maintext->TabIndex = 11;
			// 
			// button_sub
			// 
			this->button_sub->BackColor = System::Drawing::Color::MistyRose;
			this->button_sub->Location = System::Drawing::Point(260, 155);
			this->button_sub->Name = L"button_sub";
			this->button_sub->Size = System::Drawing::Size(70, 68);
			this->button_sub->TabIndex = 12;
			this->button_sub->Text = L"-";
			this->button_sub->UseVisualStyleBackColor = false;
			this->button_sub->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_mod
			// 
			this->button_mod->BackColor = System::Drawing::Color::MistyRose;
			this->button_mod->Location = System::Drawing::Point(260, 377);
			this->button_mod->Name = L"button_mod";
			this->button_mod->Size = System::Drawing::Size(70, 68);
			this->button_mod->TabIndex = 16;
			this->button_mod->Text = L"%";
			this->button_mod->UseVisualStyleBackColor = false;
			this->button_mod->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_div
			// 
			this->button_div->BackColor = System::Drawing::Color::MistyRose;
			this->button_div->Location = System::Drawing::Point(260, 303);
			this->button_div->Name = L"button_div";
			this->button_div->Size = System::Drawing::Size(70, 68);
			this->button_div->TabIndex = 15;
			this->button_div->Text = L"/";
			this->button_div->UseVisualStyleBackColor = false;
			this->button_div->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_multi
			// 
			this->button_multi->BackColor = System::Drawing::Color::MistyRose;
			this->button_multi->Location = System::Drawing::Point(260, 229);
			this->button_multi->Name = L"button_multi";
			this->button_multi->Size = System::Drawing::Size(70, 68);
			this->button_multi->TabIndex = 14;
			this->button_multi->Text = L"*";
			this->button_multi->UseVisualStyleBackColor = false;
			this->button_multi->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::Color::MistyRose;
			this->button_add->Location = System::Drawing::Point(260, 81);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(70, 68);
			this->button_add->TabIndex = 13;
			this->button_add->Text = L"+";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_eq
			// 
			this->button_eq->BackColor = System::Drawing::Color::MistyRose;
			this->button_eq->Location = System::Drawing::Point(336, 81);
			this->button_eq->Name = L"button_eq";
			this->button_eq->Size = System::Drawing::Size(70, 68);
			this->button_eq->TabIndex = 17;
			this->button_eq->Text = L"=";
			this->button_eq->UseVisualStyleBackColor = false;
			this->button_eq->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			// 
			// button_clear
			// 
			this->button_clear->BackColor = System::Drawing::Color::MistyRose;
			this->button_clear->Location = System::Drawing::Point(336, 155);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(70, 68);
			this->button_clear->TabIndex = 18;
			this->button_clear->Text = L"C";
			this->button_clear->UseVisualStyleBackColor = false;
			this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_Click);
			// 
			// button_ks
			// 
			this->button_ks->BackColor = System::Drawing::Color::MistyRose;
			this->button_ks->Location = System::Drawing::Point(336, 377);
			this->button_ks->Name = L"button_ks";
			this->button_ks->Size = System::Drawing::Size(70, 68);
			this->button_ks->TabIndex = 19;
			this->button_ks->Text = L"(";
			this->button_ks->UseVisualStyleBackColor = false;
			this->button_ks->Click += gcnew System::EventHandler(this, &MyForm::button_ks_Click);
			// 
			// button_ke
			// 
			this->button_ke->BackColor = System::Drawing::Color::MistyRose;
			this->button_ke->Location = System::Drawing::Point(412, 377);
			this->button_ke->Name = L"button_ke";
			this->button_ke->Size = System::Drawing::Size(70, 68);
			this->button_ke->TabIndex = 20;
			this->button_ke->Text = L")";
			this->button_ke->UseVisualStyleBackColor = false;
			this->button_ke->Click += gcnew System::EventHandler(this, &MyForm::button_ke_Click);
			// 
			// dataView
			// 
			this->dataView->AllowUserToAddRows = false;
			this->dataView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Check, this->Answer });
			this->dataView->Location = System::Drawing::Point(509, 40);
			this->dataView->Name = L"dataView";
			this->dataView->RowTemplate->Height = 24;
			this->dataView->Size = System::Drawing::Size(400, 300);
			this->dataView->TabIndex = 21;
			// 
			// Check
			// 
			this->Check->HeaderText = L"Check";
			this->Check->Name = L"Check";
			// 
			// Answer
			// 
			this->Answer->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Answer->HeaderText = L"Answer";
			this->Answer->Name = L"Answer";
			// 
			// delete_list
			// 
			this->delete_list->BackColor = System::Drawing::Color::LemonChiffon;
			this->delete_list->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->delete_list->Location = System::Drawing::Point(924, 40);
			this->delete_list->Name = L"delete_list";
			this->delete_list->Size = System::Drawing::Size(122, 68);
			this->delete_list->TabIndex = 23;
			this->delete_list->Text = L"削除";
			this->delete_list->UseVisualStyleBackColor = false;
			this->delete_list->Click += gcnew System::EventHandler(this, &MyForm::delete_list_Click);
			// 
			// list_all
			// 
			this->list_all->BackColor = System::Drawing::Color::LemonChiffon;
			this->list_all->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->list_all->Location = System::Drawing::Point(924, 114);
			this->list_all->Name = L"list_all";
			this->list_all->Size = System::Drawing::Size(122, 68);
			this->list_all->TabIndex = 24;
			this->list_all->Text = L"全選択";
			this->list_all->UseVisualStyleBackColor = false;
			this->list_all->Click += gcnew System::EventHandler(this, &MyForm::list_all_Click);
			// 
			// save_list
			// 
			this->save_list->BackColor = System::Drawing::Color::LemonChiffon;
			this->save_list->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->save_list->Location = System::Drawing::Point(924, 188);
			this->save_list->Name = L"save_list";
			this->save_list->Size = System::Drawing::Size(122, 68);
			this->save_list->TabIndex = 25;
			this->save_list->Text = L"保存";
			this->save_list->UseVisualStyleBackColor = false;
			this->save_list->Click += gcnew System::EventHandler(this, &MyForm::save_list_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::LemonChiffon;
			this->button10->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->button10->Location = System::Drawing::Point(924, 262);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(122, 68);
			this->button10->TabIndex = 26;
			this->button10->Text = L"出力";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1087, 455);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->save_list);
			this->Controls->Add(this->list_all);
			this->Controls->Add(this->delete_list);
			this->Controls->Add(this->dataView);
			this->Controls->Add(this->button_ke);
			this->Controls->Add(this->button_ks);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->button_eq);
			this->Controls->Add(this->button_mod);
			this->Controls->Add(this->button_div);
			this->Controls->Add(this->button_multi);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->button_sub);
			this->Controls->Add(this->maintext);
			this->Controls->Add(this->subtext);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::op_click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		calc^ c;
		//演算子の列挙
		List<String^>^ ope;
		List<double>^ val_list;
		List<String^>^ op_list;
		String^ n_op;
		//カッコ処理のためのリストのリスト
		List<List<double>^>^ v_v_list;
		List<List<String^>^>^ o_o_list;
		//カッコを閉じた後のイコール処理のための真偽値
		bool ke_calc = false;
		//primary_checkのための変数
		double last_num;
		double res;
		double ans;
		String^ file_path;

		private:void number(double num) {
			if (maintext->Text == "0"&&subtext->Text=="0") {
				maintext->Text = num.ToString();
				subtext->Text = num.ToString();
			}
			else if (ope->Contains(maintext->Text)||(subtext->Text=="("&&maintext->Text=="0")) {
				maintext->Text = num.ToString();
				subtext->Text += num.ToString();
			}
			else {
				maintext->Text += num.ToString();
				subtext->Text += num.ToString();
			}
		}
	private: System::Void buttons_click(System::Object^  sender, System::EventArgs^  e) {
		double num = double::Parse(((Button^)sender)->Text);
		number(num);
	}
			 private:void opset(String^ op) {
				 last_num = double::Parse(maintext->Text);

				 if (ke_calc == false) {
					 
					 if (n_op == "*" || n_op == "/" || n_op == "%") {
						 
						 res = c->calc_2(val_list[val_list->Count - 1], n_op, last_num);

						 val_list->RemoveAt(val_list->Count - 1);
						 op_list->RemoveAt(op_list->Count - 1);
						 val_list->Add(res);
					 }
					 else {
						 val_list->Add(last_num);
					 }
				 }
				 else {
					 ke_calc = false;
				 }

				 if (op == "=") {
					 if(val_list->Count==1){
						 ans = val_list[0];
					 }
					 else {
						 ans = c->total_calc(val_list, op_list);
					 }
					 maintext->Text = ans.ToString();
					 dataView->Rows->Add(false,ans.ToString());

				 }
				 //表示の更新とリストの更新
				 else {
					 maintext->Text = op;
					 op_list->Add(op);
					 n_op = op;
				 }
				 subtext->Text += op;
				 
			 }
private: System::Void op_click(System::Object^  sender, System::EventArgs^  e) {
	String^ opr = ((Button^)sender)->Text;
	opset(opr);
}
		 private:void init() {
			 subtext->Text = "0";
			 maintext->Text = "0";
		 }
	 private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 init();
	 }
private: System::Void button_clear_Click(System::Object^  sender, System::EventArgs^  e) {
	init();
	val_list->Clear();
	op_list->Clear();
	n_op = "";
}
private: System::Void button_ks_Click(System::Object^  sender, System::EventArgs^  e) {

	if (maintext->Text == "0") {
		subtext->Text = "(";
	}
	else {
		subtext->Text += "(";
	}

	if (val_list->Count > 0) {		
		v_v_list->Add(val_list);
		o_o_list->Add(op_list);
		val_list = gcnew List<double>;
		op_list = gcnew List<String^>;
		n_op = "";
	}
}
private: System::Void button_ke_Click(System::Object^  sender, System::EventArgs^  e) {
	last_num = double::Parse(maintext->Text);
	
	//乗除の優先
	if (ke_calc == false) {
		if (n_op == "*" || n_op == "/" || n_op == "%") {

			res = c->calc_2(val_list[val_list->Count - 1], n_op, last_num);

			val_list->RemoveAt(val_list->Count - 1);
			op_list->RemoveAt(op_list->Count - 1);
			val_list->Add(res);
		}
		else {
			val_list->Add(last_num);
		}
	}
	else {
		ke_calc = false;
	}

	//値を算出
	if (val_list->Count == 1) {
		ans = val_list[0];
	}
	else {
		ans = c->total_calc(val_list, op_list);
	}

	//式の結合
	if (v_v_list->Count >= 1) {
		val_list = v_v_list[v_v_list->Count - 1];
		op_list = o_o_list[o_o_list->Count - 1];
		v_v_list->RemoveAt(v_v_list->Count - 1);
		o_o_list->RemoveAt(o_o_list->Count - 1);
		val_list->Add(ans);
		n_op = op_list[op_list->Count - 1];
	}
	else {
		val_list = gcnew List<double>;
		op_list = gcnew List<String^>;
		val_list->Add(ans);
		n_op = "";
	}


	subtext->Text += ")";
	ke_calc = true;
}
private: System::Void delete_list_Click(System::Object^  sender, System::EventArgs^  e) {
	if (dataView->RowCount > 0) {
		for (int i = dataView->RowCount - 1; i >= 0; i--) {
			if ((bool)dataView->Rows[i]->Cells[0]->Value) {
				dataView->Rows->RemoveAt(i);
			}
		}
	}
}
private: System::Void list_all_Click(System::Object^  sender, System::EventArgs^  e) {
	if (dataView->RowCount > 0) {
		for (int i = 0; i < dataView->Rows->Count; i++) {
			dataView->Rows[i]->Cells[0]->Value = true;
		}
	}
}
private: System::Void save_list_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str;

	saveFile->FileName = "sample.csv";
	saveFile->Filter = "Comma Separated Values|.csv";
	DialogResult = saveFile->ShowDialog();

	if (DialogResult == System::Windows::Forms::DialogResult::OK) {
		file_path = saveFile->FileName;

		StreamWriter^ sw = gcnew StreamWriter(file_path);
		try {
			for (int i = 0; i < dataView->Rows->Count; i++) {
				if ((bool)dataView->Rows[i]->Cells[0]->Value) {
					str = dataView->Rows[i]->Cells[1]->Value->ToString();
					sw->Write(str);
					sw->WriteLine(",");
				}
			}
		}
		catch (Exception^ e) {
			//エラーキャッチ
			MessageBox::Show("NG:" + e->ToString());
		}
		finally{
			sw->Close();
		}
	}
	else {
		return;
	}
	
}
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ file_title;
		String^ temp_str = "0";
		array<String^>^ arrays = gcnew array<String^>{};
		String^ delim = ",";
		array<Char>^ delim_array = delim->ToCharArray();
		double value;
		List<double>^ d_list = gcnew List<double>;
		StreamReader^ sr;
		openFile->FileName = "sample.csv";
		openFile->Filter = "Comma Separated Values|.csv";
		DialogResult = openFile->ShowDialog();
		if (DialogResult == System::Windows::Forms::DialogResult::OK) {
			file_title = openFile->FileName;
		}
		try {
			sr = gcnew StreamReader(file_title);
			//while (temp_str != nullptr) {
			while(sr->Peek() >= 0){
				temp_str = sr->ReadLine();

				arrays = temp_str->Split(delim_array);

				value = double::Parse(arrays[0]);
				d_list->Add(value);
			}
			
		}
		catch (Exception^ e) {
			//
			MessageBox::Show("ng;");
		}
		finally{
			sr->Close();
		}
			//読み込みの結果はd_listに格納
		Graph^ graph = gcnew Graph(d_list);
		graph->ShowDialog();
	}
};
}
