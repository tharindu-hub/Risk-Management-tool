	void show_welcome() {
		while(m_usb.isConnected()) {
			m_con.clear();
			m_con << "****************************************" << endl;
			m_con << "*                                      *" << endl;
			m_con << "*               " VERSION "            *" << endl;
			m_con << "****************************************" << endl;
			m_con << "[1] Calibrations" << endl;
			m_con << "[2] PID Control tuning" << endl;
			m_con << "[3] Save changed" << endl;
			m_con << "[4] Load Default" << endl;
			m_con << "[5] Dashboard" << endl;
			switch(m_con.getc()) {
			case '1' :
				show_mpu6050();
				break;
			case '2' :
				show_pid();
				break;
			case '3' :
				saveConfigure();
				break;
			case '4' :
				setDefault();
				break;
			case '5':
				dashboard();
				break;
			case 'H':
				m_con.printf("High-Water Mark:%d\n", getStackHighWaterMark());
				m_con.getc();
				break;
			}
		}
