#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Graph の概要
	/// </summary>
	public ref class Graph : public System::Windows::Forms::Form
	{
	private:
		Graph(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}
	public:
		Graph(List<double>^ list) {
			InitializeComponent();
			bmp = gcnew Bitmap(graph_space->Width, graph_space->Height);
			graph_space->Image = bmp;
			gr = Graphics::FromImage(graph_space->Image);
			//枠線の色と太さを指定
			pn = gcnew Pen(Color::Black, 1);
			v_list = list;
		};
	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Graph()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  graph_space;
	protected:

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
			this->graph_space = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph_space))->BeginInit();
			this->SuspendLayout();
			// 
			// graph_space
			// 
			this->graph_space->BackColor = System::Drawing::Color::LightYellow;
			this->graph_space->Location = System::Drawing::Point(34, 55);
			this->graph_space->Margin = System::Windows::Forms::Padding(0);
			this->graph_space->Name = L"graph_space";
			this->graph_space->Size = System::Drawing::Size(500, 500);
			this->graph_space->TabIndex = 0;
			this->graph_space->TabStop = false;
			this->graph_space->MouseEnter += gcnew System::EventHandler(this, &Graph::graph_space_MouseEnter);
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoScrollMargin = System::Drawing::Size(20, 20);
			this->BackColor = System::Drawing::Color::Bisque;
			this->ClientSize = System::Drawing::Size(613, 603);
			this->Controls->Add(this->graph_space);
			this->Name = L"Graph";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &Graph::Graph_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph_space))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		List<double>^ v_list;
		Bitmap^ bmp;
		Graphics^ gr;
		Pen^ pn;
	
	private: System::Void Graph_Load(System::Object^  sender, System::EventArgs^  e) {

		//マウスホイルの操作に関するイベントを定義する
		this->MouseWheel += gcnew MouseEventHandler(this, &Graph::Graph_MouseWheel);

		line_disp();
		sub_disp();

	}
	private: System::Void graph_space_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		//this->graph_space->Select();
		//this->graph_space->Focus();
		//this->MouseWheel += gcnew MouseEventHandler(this, &Graph::Graph_MouseWheel);
	}
	 private: System::Void Graph_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 //スクロール行数の取得
		 int movement = e->Delta;
		 //倍率を定義
		 double magni=1.00;
		 
		 if (movement > 0) {
			 magni = 1.05;
			 /*旧コード
			 gr->InterpolationMode = InterpolationMode::NearestNeighbor;
			 graph_space->SizeMode = PictureBoxSizeMode::AutoSize;

			 Bitmap^ bmp2 = gcnew Bitmap(
				 graph_space->Image,
				 graph_space->Image->Width * 1.1,
				 graph_space->Image->Height * 1.1);

			 graph_space->Image = bmp2;*/

		 }
		 else {
			 magni = 0.95;
		 }
		 bmp = gcnew Bitmap(graph_space->Width*magni, graph_space->Height*magni);
		 graph_space->Image = bmp;
		 gr = Graphics::FromImage(graph_space->Image);

		 line_disp();
		 sub_disp();

		 graph_space->SizeMode = PictureBoxSizeMode::AutoSize;
		 graph_space->Image = bmp;
	 }
	//リスト中の最大値を返す
	private:double maximum(List<double>^ list) {
		double temp;
		for (int i = 0; i < list->Count; i++) {
			if (i == 0) {
				temp = list[i];
			}
			else {
				if (temp < list[i]) {
					temp = list[i];
				}
			}
		}
		return temp;
	}
	//グラフ表示
	private:void sub_disp() {

		//折れ線グラフ表示のためのポイント配列
		array<Point>^ p_list = gcnew array<Point>(v_list->Count);
		//補正率
		double finalize=1.00;

		//データの最大値がグラフの縦幅を超えていれば、補正する
		//最大値をグラフの縦幅の90%として、補正をかける

		double max = maximum(v_list);
		double limit = graph_space->Height*0.9;
		double low_limit = graph_space->Height*0.7;

		if (max > limit) {
			finalize = limit / max;
		}
		else if (max < low_limit) {
			finalize = low_limit / max;
		}

		//ポイントの大きさ
		int p=10;

		//データの個数
		int data_num = v_list->Count;
		//1データあたりの幅
		int data_width = graph_space->Width / data_num;
		//棒データの間隔
		int space = data_width / 3;
		//棒データの太さ
		int s_width = data_width / 3;

		for (int i = 0; i < v_list->Count; i++) {

			Graphics^ gr2 = Graph::CreateGraphics();
			gr2->Clear(Color::Bisque);

			int data_height = v_list[i]*finalize;
			int start_y = graph_space->Height - data_height;

			Point^ point_center = gcnew Point(space + s_width / 2, start_y);

			Point^ rect_xy = gcnew Point(space, start_y);
			System::Drawing::Size^ rect_hw = gcnew System::Drawing::Size((Point)gcnew Point(s_width, data_height));
			Rectangle^ rct = gcnew Rectangle((Point)rect_xy, (System::Drawing::Size)rect_hw);

			gr->FillRectangle(Brushes::Aqua, (Rectangle)rct);

			String^ drawString = "Sample";

			int ds_y = graph_space->Height + 50;

			
			gr2->DrawString(drawString, gcnew Drawing::Font("HG教科書体", 16), gcnew SolidBrush(Color::Black), 150, ds_y, gcnew StringFormat());

			//gr->FillRectangle(Brushes::Orange, space, start_y, s_width, data_height);
			gr->FillEllipse(Brushes::Green, space + s_width / 2 - p / 2, start_y-p/2, p, p);

			p_list[i] = (Point)point_center;
			space += data_width;

		}
		//アンチエイリアシング
		gr->SmoothingMode = SmoothingMode::AntiAlias;
		int line_thick = graph_space->Height / 150;
		//折れ線の設定
		Pen^ l_pn = gcnew Pen(Color::Green, line_thick);
		//折れ線の描画
		gr->DrawLines(l_pn, p_list);
	}
	private:void line_disp() {
		//罫線の数
		int line_num = 3;

		for (int i = 0; i < line_num; i++) {
			//罫線同士の間隔
			int y_space = graph_space->Height / (line_num + 1);
			int y = y_space * (i + 1);

			int x_space= graph_space->Width / (line_num + 1);
			int x = x_space * (i + 1);
				
			gr->SmoothingMode = SmoothingMode::AntiAlias;
			gr->DrawLine(Pens::LightGray, 0, y, graph_space->Width, y);
			gr->DrawLine(Pens::LightGray, x, 0, x, graph_space->Height);
			

		}
	}
};
}
