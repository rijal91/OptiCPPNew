#pragma once

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <winsock2.h>
#include <NPTrackingTools.h>
#include <trackablesettings.h>
#include "optitrack.h"
#include <iostream>
#include <cmath>
#include <iostream>
#include <math.h>


namespace OptiCPP3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;

	/// <summary>
	/// Summary for OptiForm
	/// </summary>
	OptiTrack* tracker;
	float x = 0.0; 
	float y = 0.0;
	float z = 0.0;
	float yaw = 0.0;
	float pitch = 0.0;
	float roll = 0.0;
	float xp = 0.0; 
	float yp = 0.0;
	float zp = 0.0;
	float xv = 0.0; 
	float yv = 0.0;
	float zv = 0.0;
	float yawp = 0.0;
	float pitchp = 0.0;
	float rollp = 0.0;
	float yawv = 0.0;
	float pitchv = 0.0;
	float rollv = 0.0;
	

	public ref class OptiForm : public System::Windows::Forms::Form
	{
		
	public:
		
		bool runonce;
		OptiForm(void)
		{
			
			tracker = new OptiTrack;
			runonce = true;
			InitializeComponent();
			//main2();
			//
			//TODO: Add the constructor code here
			//
			
				// Load camera and rigid body definition must be done before initialization
				
		}

		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OptiForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  RunOpThread;
	private: System::Windows::Forms::TextBox^  x_tb;
	private: System::Windows::Forms::Label^  x_lb;
	private: System::Windows::Forms::TextBox^  y_tb;
	private: System::Windows::Forms::Label^  y_lb;
	private: System::Windows::Forms::TextBox^  z_tb;
	private: System::Windows::Forms::Label^  z_lb;
	private: System::Windows::Forms::GroupBox^  pos_gb;
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::Windows::Forms::TextBox^  qz_tb;
	private: System::Windows::Forms::Label^  qz_lb;
	private: System::Windows::Forms::TextBox^  qx_tb;
	private: System::Windows::Forms::Label^  qx_lb;
	private: System::Windows::Forms::Label^  qy_lb;
	private: System::Windows::Forms::TextBox^  qy_tb;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  zv_tb;

	private: System::Windows::Forms::Label^  zv_lb;
	private: System::Windows::Forms::TextBox^  xv_tb;


	private: System::Windows::Forms::Label^  xv_lb;
	private: System::Windows::Forms::Label^  yv_lb;
	private: System::Windows::Forms::TextBox^  yv_tb;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  rollv_tb;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  yawv_tb;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  pitchv_tb;



	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->RunOpThread = (gcnew System::Windows::Forms::Timer(this->components));
			this->x_tb = (gcnew System::Windows::Forms::TextBox());
			this->x_lb = (gcnew System::Windows::Forms::Label());
			this->y_tb = (gcnew System::Windows::Forms::TextBox());
			this->y_lb = (gcnew System::Windows::Forms::Label());
			this->z_tb = (gcnew System::Windows::Forms::TextBox());
			this->z_lb = (gcnew System::Windows::Forms::Label());
			this->pos_gb = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->qz_tb = (gcnew System::Windows::Forms::TextBox());
			this->qz_lb = (gcnew System::Windows::Forms::Label());
			this->qx_tb = (gcnew System::Windows::Forms::TextBox());
			this->qx_lb = (gcnew System::Windows::Forms::Label());
			this->qy_lb = (gcnew System::Windows::Forms::Label());
			this->qy_tb = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->zv_tb = (gcnew System::Windows::Forms::TextBox());
			this->zv_lb = (gcnew System::Windows::Forms::Label());
			this->xv_tb = (gcnew System::Windows::Forms::TextBox());
			this->xv_lb = (gcnew System::Windows::Forms::Label());
			this->yv_lb = (gcnew System::Windows::Forms::Label());
			this->yv_tb = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->rollv_tb = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->yawv_tb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pitchv_tb = (gcnew System::Windows::Forms::TextBox());
			this->pos_gb->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(52, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &OptiForm::button1_Click);
			// 
			// RunOpThread
			// 
			this->RunOpThread->Interval = 50;
			this->RunOpThread->Tick += gcnew System::EventHandler(this, &OptiForm::RunOpThread_Tick);
			// 
			// x_tb
			// 
			this->x_tb->Location = System::Drawing::Point(52, 21);
			this->x_tb->Name = L"x_tb";
			this->x_tb->Size = System::Drawing::Size(100, 20);
			this->x_tb->TabIndex = 1;
			// 
			// x_lb
			// 
			this->x_lb->AutoSize = true;
			this->x_lb->Location = System::Drawing::Point(34, 25);
			this->x_lb->Name = L"x_lb";
			this->x_lb->Size = System::Drawing::Size(12, 13);
			this->x_lb->TabIndex = 2;
			this->x_lb->Text = L"x";
			// 
			// y_tb
			// 
			this->y_tb->Location = System::Drawing::Point(52, 47);
			this->y_tb->Name = L"y_tb";
			this->y_tb->Size = System::Drawing::Size(100, 20);
			this->y_tb->TabIndex = 3;
			// 
			// y_lb
			// 
			this->y_lb->AutoSize = true;
			this->y_lb->Location = System::Drawing::Point(34, 48);
			this->y_lb->Name = L"y_lb";
			this->y_lb->Size = System::Drawing::Size(12, 13);
			this->y_lb->TabIndex = 4;
			this->y_lb->Text = L"y";
			// 
			// z_tb
			// 
			this->z_tb->Location = System::Drawing::Point(52, 73);
			this->z_tb->Name = L"z_tb";
			this->z_tb->Size = System::Drawing::Size(100, 20);
			this->z_tb->TabIndex = 5;
			// 
			// z_lb
			// 
			this->z_lb->AutoSize = true;
			this->z_lb->Location = System::Drawing::Point(34, 77);
			this->z_lb->Name = L"z_lb";
			this->z_lb->Size = System::Drawing::Size(12, 13);
			this->z_lb->TabIndex = 6;
			this->z_lb->Text = L"z";
			// 
			// pos_gb
			// 
			this->pos_gb->Controls->Add(this->z_tb);
			this->pos_gb->Controls->Add(this->z_lb);
			this->pos_gb->Controls->Add(this->x_tb);
			this->pos_gb->Controls->Add(this->x_lb);
			this->pos_gb->Controls->Add(this->y_lb);
			this->pos_gb->Controls->Add(this->y_tb);
			this->pos_gb->Location = System::Drawing::Point(52, 89);
			this->pos_gb->Name = L"pos_gb";
			this->pos_gb->Size = System::Drawing::Size(200, 100);
			this->pos_gb->TabIndex = 7;
			this->pos_gb->TabStop = false;
			this->pos_gb->Text = L"Position";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->qz_tb);
			this->groupBox1->Controls->Add(this->qz_lb);
			this->groupBox1->Controls->Add(this->qx_tb);
			this->groupBox1->Controls->Add(this->qx_lb);
			this->groupBox1->Controls->Add(this->qy_lb);
			this->groupBox1->Controls->Add(this->qy_tb);
			this->groupBox1->Location = System::Drawing::Point(272, 89);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Attitude";
			// 
			// qz_tb
			// 
			this->qz_tb->Location = System::Drawing::Point(52, 72);
			this->qz_tb->Name = L"qz_tb";
			this->qz_tb->Size = System::Drawing::Size(100, 20);
			this->qz_tb->TabIndex = 5;
			// 
			// qz_lb
			// 
			this->qz_lb->AutoSize = true;
			this->qz_lb->Location = System::Drawing::Point(27, 75);
			this->qz_lb->Name = L"qz_lb";
			this->qz_lb->Size = System::Drawing::Size(20, 13);
			this->qz_lb->TabIndex = 6;
			this->qz_lb->Text = L"roll";
			// 
			// qx_tb
			// 
			this->qx_tb->Location = System::Drawing::Point(52, 20);
			this->qx_tb->Name = L"qx_tb";
			this->qx_tb->Size = System::Drawing::Size(100, 20);
			this->qx_tb->TabIndex = 1;
			// 
			// qx_lb
			// 
			this->qx_lb->AutoSize = true;
			this->qx_lb->Location = System::Drawing::Point(21, 23);
			this->qx_lb->Name = L"qx_lb";
			this->qx_lb->Size = System::Drawing::Size(26, 13);
			this->qx_lb->TabIndex = 2;
			this->qx_lb->Text = L"yaw";
			// 
			// qy_lb
			// 
			this->qy_lb->AutoSize = true;
			this->qy_lb->Location = System::Drawing::Point(17, 49);
			this->qy_lb->Name = L"qy_lb";
			this->qy_lb->Size = System::Drawing::Size(30, 13);
			this->qy_lb->TabIndex = 4;
			this->qy_lb->Text = L"pitch";
			// 
			// qy_tb
			// 
			this->qy_tb->Location = System::Drawing::Point(52, 46);
			this->qy_tb->Name = L"qy_tb";
			this->qy_tb->Size = System::Drawing::Size(100, 20);
			this->qy_tb->TabIndex = 3;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->zv_tb);
			this->groupBox2->Controls->Add(this->zv_lb);
			this->groupBox2->Controls->Add(this->xv_tb);
			this->groupBox2->Controls->Add(this->xv_lb);
			this->groupBox2->Controls->Add(this->yv_lb);
			this->groupBox2->Controls->Add(this->yv_tb);
			this->groupBox2->Location = System::Drawing::Point(52, 195);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 100);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Velocity";
			// 
			// zv_tb
			// 
			this->zv_tb->Location = System::Drawing::Point(52, 72);
			this->zv_tb->Name = L"zv_tb";
			this->zv_tb->Size = System::Drawing::Size(100, 20);
			this->zv_tb->TabIndex = 5;
			// 
			// zv_lb
			// 
			this->zv_lb->AutoSize = true;
			this->zv_lb->Location = System::Drawing::Point(30, 77);
			this->zv_lb->Name = L"zv_lb";
			this->zv_lb->Size = System::Drawing::Size(18, 13);
			this->zv_lb->TabIndex = 6;
			this->zv_lb->Text = L"zv";
			// 
			// xv_tb
			// 
			this->xv_tb->Location = System::Drawing::Point(52, 20);
			this->xv_tb->Name = L"xv_tb";
			this->xv_tb->Size = System::Drawing::Size(100, 20);
			this->xv_tb->TabIndex = 1;
			// 
			// xv_lb
			// 
			this->xv_lb->AutoSize = true;
			this->xv_lb->Location = System::Drawing::Point(30, 25);
			this->xv_lb->Name = L"xv_lb";
			this->xv_lb->Size = System::Drawing::Size(18, 13);
			this->xv_lb->TabIndex = 2;
			this->xv_lb->Text = L"xv";
			// 
			// yv_lb
			// 
			this->yv_lb->AutoSize = true;
			this->yv_lb->Location = System::Drawing::Point(30, 51);
			this->yv_lb->Name = L"yv_lb";
			this->yv_lb->Size = System::Drawing::Size(18, 13);
			this->yv_lb->TabIndex = 4;
			this->yv_lb->Text = L"yv";
			// 
			// yv_tb
			// 
			this->yv_tb->Location = System::Drawing::Point(52, 46);
			this->yv_tb->Name = L"yv_tb";
			this->yv_tb->Size = System::Drawing::Size(100, 20);
			this->yv_tb->TabIndex = 3;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->rollv_tb);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->yawv_tb);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->pitchv_tb);
			this->groupBox3->Location = System::Drawing::Point(272, 195);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 100);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Velocity";
			// 
			// rollv_tb
			// 
			this->rollv_tb->Location = System::Drawing::Point(52, 72);
			this->rollv_tb->Name = L"rollv_tb";
			this->rollv_tb->Size = System::Drawing::Size(100, 20);
			this->rollv_tb->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"rollv";
			// 
			// yawv_tb
			// 
			this->yawv_tb->Location = System::Drawing::Point(52, 20);
			this->yawv_tb->Name = L"yawv_tb";
			this->yawv_tb->Size = System::Drawing::Size(100, 20);
			this->yawv_tb->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"yawv";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"pitchv";
			// 
			// pitchv_tb
			// 
			this->pitchv_tb->Location = System::Drawing::Point(52, 46);
			this->pitchv_tb->Name = L"pitchv_tb";
			this->pitchv_tb->Size = System::Drawing::Size(100, 20);
			this->pitchv_tb->TabIndex = 3;
			// 
			// OptiForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 339);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pos_gb);
			this->Controls->Add(this->button1);
			this->Name = L"OptiForm";
			this->Text = L"OptiForm";
			this->pos_gb->ResumeLayout(false);
			this->pos_gb->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}

		
		
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 if (button1->Text == "Start"){
					 button1->Text = "Stop";
					 tracker = new OptiTrack;
					 RunOpThread->Enabled=true;

				 }
				 else if (button1->Text == "Stop")
				{
					button1->Text = "Start";
					RunOpThread->Enabled=false;
					delete tracker;
				}

			 }
	private: System::Void RunOpThread_Tick(System::Object^  sender, System::EventArgs^  e) {

				if(runonce){
				tracker->setProjectFile("project.ttp");
	
				tracker->initialize();
				runonce = false;
				}			
				
				//get data
				tracker->getPositionAndOrientation(0, x, y, z, yaw, pitch, roll);

				//calculate for velocity
				xv = (x - xp) / 0.05;
                yv = (y - yp) / 0.05;
                zv = (z - zp) / 0.05;
				
				xp = x; 
                yp = y; 
                zp = z;
							
				//calculate for angular rate
				yawv = (yaw - yawp) / 0.05;
                pitchv = (pitch - pitchp) / 0.05;
                rollv = (roll - rollp) / 0.05;
				
				yawp = yaw; 
                pitchp = pitch; 
                rollp = roll;

				//round off to 3 decimal places
				x = roundoff(x);
				y = roundoff(y);
				z = roundoff(z);

				yaw = roundoff(yaw);
				pitch = roundoff(pitch);
				roll = roundoff(roll);

				xv = roundoff(xv);
				yv = roundoff(yv);
				zv = roundoff(zv);
				
				yawv = roundoff(yawv);
				pitchv = roundoff(pitchv);
				rollv = roundoff(rollv);
				
				// display data in textbox
				x_tb->Text = x.ToString();
				y_tb->Text = y.ToString();
				z_tb->Text = z.ToString();
				
				qx_tb->Text = yaw.ToString();
				qy_tb->Text = pitch.ToString();
				qz_tb->Text = roll.ToString();
				
				xv_tb->Text = xv.ToString();
				yv_tb->Text = yv.ToString();
				zv_tb->Text = zv.ToString();

				yawv_tb->Text = yawv.ToString();
				pitchv_tb->Text = pitchv.ToString();
				rollv_tb->Text = rollv.ToString();

				
					
				//delete tracker;
				
		}
	float roundoff(float val) 
{
	  val = float(int(val * 100 + 0.05)) / 100; 
	  return val;

}
};


	

}


