#pragma once

#include "Definitions.h"
#include "DiscordRPC.h"
#include "Utils.h"

namespace SuunoNikkiLauncher {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Launcher : public System::Windows::Forms::Form {
		public:
			Launcher(void) {
				InitializeComponent();

				// Q: Why not just set the BackgroundImage of the form?
				// A: Because if I do that, the window flashes weirdly sometimes and it is
				//    also less smoother.
				this->VersionLabel->Parent = this->BackgroundPicture;
				this->CopyrightLabel->Parent = this->BackgroundPicture;
				this->Logo->Parent = this->BackgroundPicture;
			}

		protected:
			~Launcher() {
				if (components) {
					delete components;
				}
			}

		private: bool dragging;
		private: Point offset;

		private: System::Windows::Forms::Label^  VersionLabel;
		protected:
		private: System::Windows::Forms::Label^  CopyrightLabel;
		private: System::Windows::Forms::Button^  CloseButton;
		private: System::Windows::Forms::Button^  CreditsButton;
		private: System::Windows::Forms::Button^  SoundTrackButton;
		private: System::Windows::Forms::Button^  SettingsButton;
		private: System::Windows::Forms::Button^  PlayButton;
		private: System::Windows::Forms::PictureBox^  BackgroundPicture;
		private: System::Windows::Forms::PictureBox^  Logo;

		private: System::ComponentModel::IContainer^  components;

		private:

		#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Launcher::typeid));
			this->VersionLabel = (gcnew System::Windows::Forms::Label());
			this->CopyrightLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->CreditsButton = (gcnew System::Windows::Forms::Button());
			this->SoundTrackButton = (gcnew System::Windows::Forms::Button());
			this->SettingsButton = (gcnew System::Windows::Forms::Button());
			this->PlayButton = (gcnew System::Windows::Forms::Button());
			this->BackgroundPicture = (gcnew System::Windows::Forms::PictureBox());
			this->Logo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackgroundPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->BeginInit();
			this->SuspendLayout();
			// 
			// VersionLabel
			// 
			this->VersionLabel->AutoSize = true;
			this->VersionLabel->BackColor = System::Drawing::Color::Transparent;
			this->VersionLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VersionLabel->ForeColor = System::Drawing::Color::White;
			this->VersionLabel->Location = System::Drawing::Point(12, 517);
			this->VersionLabel->Name = L"VersionLabel";
			this->VersionLabel->Size = System::Drawing::Size(140, 14);
			this->VersionLabel->TabIndex = 0;
			this->VersionLabel->Text = L"Suu no Nikki v1.0.0";
			this->VersionLabel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseDown);
			this->VersionLabel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseMove);
			this->VersionLabel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseUp);
			// 
			// CopyrightLabel
			// 
			this->CopyrightLabel->AutoSize = true;
			this->CopyrightLabel->BackColor = System::Drawing::Color::Transparent;
			this->CopyrightLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CopyrightLabel->ForeColor = System::Drawing::Color::White;
			this->CopyrightLabel->Location = System::Drawing::Point(283, 517);
			this->CopyrightLabel->Name = L"CopyrightLabel";
			this->CopyrightLabel->Size = System::Drawing::Size(112, 14);
			this->CopyrightLabel->TabIndex = 0;
			this->CopyrightLabel->Text = L"Infinite Splits";
			this->CopyrightLabel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseDown);
			this->CopyrightLabel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseMove);
			this->CopyrightLabel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseUp);
			// 
			// CloseButton
			// 
			this->CloseButton->BackColor = System::Drawing::Color::Firebrick;
			this->CloseButton->FlatAppearance->BorderSize = 0;
			this->CloseButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->CloseButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->CloseButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CloseButton->ForeColor = System::Drawing::Color::White;
			this->CloseButton->Location = System::Drawing::Point(12, 333);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(129, 36);
			this->CloseButton->TabIndex = 5;
			this->CloseButton->Text = L"Quit";
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &Launcher::CloseButton_Click);
			// 
			// CreditsButton
			// 
			this->CreditsButton->BackColor = System::Drawing::Color::Firebrick;
			this->CreditsButton->FlatAppearance->BorderSize = 0;
			this->CreditsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->CreditsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->CreditsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CreditsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreditsButton->ForeColor = System::Drawing::Color::White;
			this->CreditsButton->Location = System::Drawing::Point(12, 291);
			this->CreditsButton->Name = L"CreditsButton";
			this->CreditsButton->Size = System::Drawing::Size(129, 36);
			this->CreditsButton->TabIndex = 4;
			this->CreditsButton->Text = L"Credits";
			this->CreditsButton->UseVisualStyleBackColor = false;
			this->CreditsButton->Click += gcnew System::EventHandler(this, &Launcher::CreditsButton_Click);
			// 
			// SoundTrackButton
			// 
			this->SoundTrackButton->BackColor = System::Drawing::Color::Firebrick;
			this->SoundTrackButton->FlatAppearance->BorderSize = 0;
			this->SoundTrackButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SoundTrackButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->SoundTrackButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SoundTrackButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SoundTrackButton->ForeColor = System::Drawing::Color::White;
			this->SoundTrackButton->Location = System::Drawing::Point(12, 249);
			this->SoundTrackButton->Name = L"SoundTrackButton";
			this->SoundTrackButton->Size = System::Drawing::Size(129, 36);
			this->SoundTrackButton->TabIndex = 3;
			this->SoundTrackButton->Text = L"Soundtrack";
			this->SoundTrackButton->UseVisualStyleBackColor = false;
			this->SoundTrackButton->Click += gcnew System::EventHandler(this, &Launcher::SoundTrackButton_Click);
			// 
			// SettingsButton
			// 
			this->SettingsButton->BackColor = System::Drawing::Color::Firebrick;
			this->SettingsButton->FlatAppearance->BorderSize = 0;
			this->SettingsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SettingsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->SettingsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SettingsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SettingsButton->ForeColor = System::Drawing::Color::White;
			this->SettingsButton->Location = System::Drawing::Point(12, 207);
			this->SettingsButton->Name = L"SettingsButton";
			this->SettingsButton->Size = System::Drawing::Size(129, 36);
			this->SettingsButton->TabIndex = 2;
			this->SettingsButton->Text = L"Settings";
			this->SettingsButton->UseVisualStyleBackColor = false;
			this->SettingsButton->Click += gcnew System::EventHandler(this, &Launcher::SettingsButton_Click);
			// 
			// PlayButton
			// 
			this->PlayButton->BackColor = System::Drawing::Color::Firebrick;
			this->PlayButton->FlatAppearance->BorderSize = 0;
			this->PlayButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->PlayButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->PlayButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PlayButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayButton->ForeColor = System::Drawing::Color::White;
			this->PlayButton->Location = System::Drawing::Point(12, 148);
			this->PlayButton->Name = L"PlayButton";
			this->PlayButton->Size = System::Drawing::Size(175, 53);
			this->PlayButton->TabIndex = 1;
			this->PlayButton->Text = L"PLAY";
			this->PlayButton->UseVisualStyleBackColor = false;
			this->PlayButton->Click += gcnew System::EventHandler(this, &Launcher::PlayButton_Click);
			// 
			// BackgroundPicture
			// 
			this->BackgroundPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackgroundPicture.Image")));
			this->BackgroundPicture->Location = System::Drawing::Point(0, 0);
			this->BackgroundPicture->Name = L"BackgroundPicture";
			this->BackgroundPicture->Size = System::Drawing::Size(407, 540);
			this->BackgroundPicture->TabIndex = 7;
			this->BackgroundPicture->TabStop = false;
			this->BackgroundPicture->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseDown);
			this->BackgroundPicture->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseMove);
			this->BackgroundPicture->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseUp);
			// 
			// Logo
			// 
			this->Logo->BackColor = System::Drawing::Color::Transparent;
			this->Logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.Image")));
			this->Logo->Location = System::Drawing::Point(12, 20);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(380, 109);
			this->Logo->TabIndex = 8;
			this->Logo->TabStop = false;
			this->Logo->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseDown);
			this->Logo->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseMove);
			this->Logo->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::WindowOffset_MouseUp);
			// 
			// Launcher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 540);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->VersionLabel);
			this->Controls->Add(this->PlayButton);
			this->Controls->Add(this->SettingsButton);
			this->Controls->Add(this->SoundTrackButton);
			this->Controls->Add(this->CreditsButton);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->CopyrightLabel);
			this->Controls->Add(this->BackgroundPicture);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Launcher";
			this->Text = L"Sue\'s Diary ~ Suu no Nikki";
			this->Load += gcnew System::EventHandler(this, &Launcher::Launcher_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackgroundPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion

		private: System::Void Launcher_Load(System::Object^  sender, System::EventArgs^  e) {
			this->dragging = false;
		}

		private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			Launcher::Close();
		}

		private: System::Void WindowOffset_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}

		private: System::Void WindowOffset_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (this->dragging) {
				Point current_position = PointToScreen(e->Location);
				Location = Point(current_position.X - this->offset.X, current_position.Y - this->offset.Y);
			}
		}

		private: System::Void WindowOffset_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->dragging = false;
		}

		private: System::Void PlayButton_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string exec = std::string("game\\") + EXEC_NAME;

			if (!file_exists(exec)) {
				MessageBox::Show(
					"Couldn't open the game. Make sure you have all game files in the \"game\" folder.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			bool success = start_process(exec.c_str());

			if (!success) {
				return;
			}

			Launcher::Hide();

			initialize_rpc_service();
		}

		private: System::Void SettingsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string exec = std::string("game\\") + CONFIG_NAME;

			if (!file_exists(exec)) {
				MessageBox::Show(
					"Couldn't open settings program. Make sure you have all game files in the \"game\" folder.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			start_process(exec.c_str());
		}

		private: System::Void SoundTrackButton_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string exec = std::string("game\\") + ORGVIEW_NAME;

			if (!file_exists(exec)) {
				MessageBox::Show(
					"Couldn't open organya player. Make sure you have all game files in the \"game\" folder.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			start_process(exec.c_str());
		}

		private: System::Void CreditsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show(
				"Work in progress...",
				"Info",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	};
}
