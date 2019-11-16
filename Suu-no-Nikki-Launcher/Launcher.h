#pragma once

namespace SuunoNikkiLauncher {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Launcher : public System::Windows::Forms::Form
	{
		public:
			Launcher(void)
			{
				InitializeComponent();
			}

		protected:
			~Launcher()
			{
				if (components)
				{
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

		private:
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Launcher::typeid));
			this->VersionLabel = (gcnew System::Windows::Forms::Label());
			this->CopyrightLabel = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->CreditsButton = (gcnew System::Windows::Forms::Button());
			this->SoundTrackButton = (gcnew System::Windows::Forms::Button());
			this->SettingsButton = (gcnew System::Windows::Forms::Button());
			this->PlayButton = (gcnew System::Windows::Forms::Button());
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
			this->CopyrightLabel->TabIndex = 1;
			this->CopyrightLabel->Text = L"Infinite Splits";

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
			this->CloseButton->TabIndex = 2;
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
			this->CreditsButton->TabIndex = 3;
			this->CreditsButton->Text = L"Credits";
			this->CreditsButton->UseVisualStyleBackColor = false;

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
			this->SoundTrackButton->TabIndex = 4;
			this->SoundTrackButton->Text = L"Soundtrack";
			this->SoundTrackButton->UseVisualStyleBackColor = false;

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
			this->SettingsButton->TabIndex = 5;
			this->SettingsButton->Text = L"Settings";
			this->SettingsButton->UseVisualStyleBackColor = false;

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
			this->PlayButton->TabIndex = 6;
			this->PlayButton->Text = L"PLAY";
			this->PlayButton->UseVisualStyleBackColor = false;

			// 
			// Launcher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(407, 540);
			this->Controls->Add(this->PlayButton);
			this->Controls->Add(this->SettingsButton);
			this->Controls->Add(this->SoundTrackButton);
			this->Controls->Add(this->CreditsButton);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->CopyrightLabel);
			this->Controls->Add(this->VersionLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Launcher";
			this->Text = L"Sue\'s Diary ~ Suu no Nikki";
			this->Load += gcnew System::EventHandler(this, &Launcher::Launcher_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::Launcher_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::Launcher_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Launcher::Launcher_MouseUp);
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

		private: System::Void Launcher_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}

		private: System::Void Launcher_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (this->dragging) {
				Point current_position = PointToScreen(e->Location);
				Location = Point(current_position.X - this->offset.X, current_position.Y - this->offset.Y);
			}
		}

		private: System::Void Launcher_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->dragging = false;
		}
	};
}
