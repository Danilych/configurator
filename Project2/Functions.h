#pragma once

#include <ctime>
#include <vector>
#include <fstream>
#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "RAM.h"
#include "SATA.h"
#include "PowerBlock.h"
#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	//�������� � ���� ������ ����������� ����
	std::vector<GraphicsCard> cards;
	GraphicsCard card;

	std::fstream GraphicFile("Graphics.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int power;
	int cost;
	int tdp;

	GraphicFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		GraphicFile >> name;
		GraphicFile >> power;
		GraphicFile >> cost;
		GraphicFile >> tdp;
		card.SetData(name, power, cost, tdp);
		cards.push_back(card);
	}

	return cards;
}

std::vector<Motherboard> LoadMothersData()
{
	//�������� � ���� ������ ����������� ����
	std::vector<Motherboard> mothers;
	Motherboard mother;

	std::fstream MBoardFile("Mboards.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int powermin;
	int powermax;
	int cost;
	int size;
	int socket;

	MBoardFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		MBoardFile >> name;
		MBoardFile >> powermin;
		MBoardFile >> powermax;
		MBoardFile >> cost;
		MBoardFile >> size;
		MBoardFile >> socket;
		mother.SetData(name, powermin, powermax, cost, size, socket);
		mothers.push_back(mother);
	}

	return mothers;
}

std::vector<Processor> LoadProcData()
{
	//�������� � ���� ������ �����������
	std::vector<Processor> procs;
	Processor proc;

	std::fstream ProccsFile("Proccs.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int power;
	int cost;
	int socket;
	int tdp;

	ProccsFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		ProccsFile >> name;
		ProccsFile >> power;
		ProccsFile >> cost;
		ProccsFile >> socket;
		ProccsFile >> tdp;
		proc.SetData(name, power, cost, socket, tdp);
		procs.push_back(proc);
	}

	return procs;
}

std::vector<RAM> LoadRAMData()
{
	//�������� � ���� ������ ����������� ������
	std::vector<RAM> RAMS;
	RAM ram;

	std::fstream RAMFile("RAM.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int GBs;
	int cost;

	RAMFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		RAMFile >> name;
		RAMFile >> GBs;
		RAMFile >> cost;
		ram.SetData(name, GBs, cost);
		RAMS.push_back(ram);
	}

	return RAMS;
}

std::vector<SATA> LoadSATAData()
{
	//�������� � ���� ������ ������� ������
	std::vector<SATA> SATS;
	SATA sata;

	std::fstream SATAFile("SATA.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int GBs;
	int type;
	int cost;

	SATAFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		SATAFile >> name;
		SATAFile >> GBs;
		SATAFile >> type;
		SATAFile >> cost;
		sata.SetData(name, GBs, type, cost);
		SATS.push_back(sata);
	}

	return SATS;
}

std::vector<PowerBlock> LoadPowerData()
{
	//�������� � ���� ������ ������� ������
	std::vector<PowerBlock> Powers;
	PowerBlock power;

	std::fstream PowerFile("PowerBlocks.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int Watt;
	int cost;

	PowerFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		PowerFile >> name;
		PowerFile >> Watt;
		PowerFile >> cost;
		power.SetData(name, Watt, cost);
		Powers.push_back(power);
	}

	return Powers;
}

std::vector<Sborka> CreateConfigas(int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, 
std::vector<Motherboard> mothers, std::vector<Processor> process, std::vector<RAM> rams, std::vector<SATA> sats, std::vector<PowerBlock> powers)
{
	//��������� ������
	//��� �������
	srand(time(NULL));

	float OverallPoints = 50;
	float GrahpicPoints = 40;
	float ProccessorPoints = 40;
	float RamPoints = 8;
	float SataPoints = 512;
	int SataType = 1;
	//���� �������� �� ����
	if (configtype == 2)
	{
		OverallPoints = 70;
		GrahpicPoints = 40;
		ProccessorPoints = 60;
		RamPoints = 8;
		SataPoints = 512;
		SataType = 1;
	}
	else if (configtype == 3)
	{
		OverallPoints = 90;
		GrahpicPoints = 80;
		ProccessorPoints = 70;
		RamPoints = 16;
		SataPoints = 256;
		SataType = 2;
	}
	else  if (configtype == 4)
	{
		OverallPoints = 100;
		GrahpicPoints = 100;
		ProccessorPoints = 100;
		RamPoints = 32;
		SataPoints = 1024;
		SataType = 2;
	}

	//������� �� ���� ��������� ������

	int gptb = 0;
	int pptb = 0;
	int rptb = 4;
	int sptb = 256;
	int sttb = 1;

	if (configtype == 2)
	{
		gptb = 10;
		pptb = 20;
	}
	else if (configtype == 3)
	{
		gptb = 30;
		pptb = 30;
		rptb = 8;
		sptb = 512;
	}
	else if (configtype == 4)
	{
		gptb = 40;
		pptb = 50;
		rptb = 8;
		sptb = 512;
		//	sttb = 2;
	}

	//��� �������� ��������� �������
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	int tdp = 0;
	//������� ������
	std::vector<Sborka> Sborki;
	int op = OverallPoints;
	int gp = GrahpicPoints;
	int pp = ProccessorPoints;
	int rp = RamPoints;
	int sp = SataPoints;
	int st = SataType;

	int opt = op;
	int gpt = gp;
	int ppt = pp;
	int rpt = rp;
	int spt = sp;
	int stt = st;
	//��������� 5 (i) ������
	for (int i = 0; i < 10; i++)
	{
		tdp = 0;
		//������������� ����� ����������� �����
		int b = 0;
		int e = cards.size();

		int size = e;

		while (b < e)
		{
			int c = (b + e) / 2;
			//����� ������������ �� ��������
			if (cards[c].GetPoints() < (int)gpt) b = c + 1;
			else e = c;
		}
		card = cards[b];
		tdp += card.GetTdp();

		//����� ���������� �� ��������

		b = 0;
		e = process.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (process[c].GetPoints() < (int)ppt) b = c + 1;
			else e = c;
		}
		int ip = b;
		proces = process[b];
		tdp += proces.GetTdp() + 200;

		//����� ����������� ����� �� ������ ����������

		b = 0;
		e = mothers.size();

		for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

		mother = mothers[b];

		//����� ����������� ������ �� ��������
		
		b = 0;
		e = rams.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (rams[c].GetGB() < (int)rpt) b = c + 1;
			else e = c;
		}

		ram = rams[b];
		
		//����� �������� ����� �� ��������

		b = 0;
		e = sats.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (sats[c].GetGB() < (int)spt && sats[c].GetType() == stt) b = c + 1;
			else e = c;
		}

		sata = sats[b];

		//����� ����� ������� �� ��������

		b = 0;
		e = powers.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (powers[c].GetWatt() < (int)tdp) b = c + 1;
			else e = c;
		}

		power = powers[b];

		//���� ���� ��������� ����������� � ������

		Sborka sb;
		sb.SetConfig(card, mother, proces, ram, sata, power);

		//��������� ���� ������ � ������� �������

		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost )
		{
			if (gpt >= gptb && ppt >= pptb && rpt >= rptb)
				Sborki.push_back(sb);
			else return Sborki;
			//�������� ��������� ������ ������
			if (op > 0) op -= 10;
			if (gp > 0) gp -= 10;
			if (pp > 0) pp -= 10;
			//
			if (rp > 4)
			{
				if ((configtype == 1 || configtype == 2) && op < 40) rp /= 2;
				else if (configtype == 3 && op < 70 && rp > 8) rp /= 2;
				else if (configtype == 4 && op < 80 && rp > 8) rp /= 2;
			}
			//
			if (st == 2 && sp == 256) st -= 1;
			else if (st == 1 && sp > 256) sp /= 2;
			else if (st == 2 && sp > 256) sp /= 2;
			//
			

			opt = op;
		    gpt = gp;
			ppt = pp;
			rpt = rp;
			spt = sp;
			stt = st;

			//return Sborki;
		}
		else
		{
			

			if (!(gpt <= gptb && ppt <= pptb && rpt <= rptb && stt <= sttb && spt == sptb))
			{
				srand(time(NULL));
				//���������� �����-������ ���������
				int r = rand() % 4;;
				bool exit = false;

				while (!exit)
				{

					if (r == 0)
					{
						if (gpt > gptb)
						{
							gpt -= 10;
							exit = true;
						}
						else r += 1;
					}

					if (r == 1)
					{
						if (ppt > pptb)
						{
							ppt -= 10;
							exit = true;
						}
						else r += 1;
					}

					if (r == 2)
					{
						if (rpt > rptb)
						{
							if ((configtype == 1 || configtype == 2) && opt < 40)
							{
								rpt /= 2;
								exit = true;
							}
							else if (configtype == 3 && opt < 70)
							{
								rpt /= 2;
								exit = true;
							}
							else if (configtype == 4 && opt < 80)
							{
								rpt /= 2;
								exit = true;
							}
							else
							{
								r += 1;
								opt -= 10;
							}
						}
						else r += 1;
					}

					if (r == 3)
					{
						if (stt == 2 && spt == sptb)
						{
							stt -= 1;
							exit = true;
						}
						else if (stt == 2 && spt > 256)
						{
							spt /= 2;
							exit = true;
						}
						else if (stt == sttb && spt > sptb)
						{
							spt /= 2;
							exit = true;
						}
						else if (stt == 2 && spt == 256)
						{
							stt = 1;
							spt = 1024;
							exit = true;
						}
						else r = 0;
						
					}
					else
					{
						//if (r )
						r = 0;
						//opt -= 10;
					}
				}
				i--;
			}
			else return Sborki;

		}
	}

	return Sborki;
}