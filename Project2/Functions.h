#pragma once

#include <ctime>
#include <vector>
#include <fstream>

#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	//�������� � ���� ������ ����������� ����
	std::vector<GraphicsCard> cards;
	GraphicsCard card;
	 
	//�������� �����
	std::fstream GraphicFile("Graphics.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int power;
	int cost;
	int tdp;

	GraphicFile >> amount;
	//���������� ����� ������ ���������
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

	//�������� �����
	std::fstream MBoardFile("Mboards.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int powermin;
	int powermax;
	int cost;
	int size;
	int socket;

	MBoardFile >> amount;
	//���������� ����� ������ ����������� ����
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

	//�������� �����
	std::fstream ProccsFile("Proccs.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int power;
	int cost;
	int socket;
	int tdp;

	ProccsFile >> amount;
	//���������� ����� ������ �����������
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

	//�������� �����
	std::fstream RAMFile("RAM.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int GBs;
	int cost;

	RAMFile >> amount;
	//���������� ����� ������ ����������� ������
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

	//�������� �����
	std::fstream SATAFile("SATA.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int GBs;
	int type;
	int cost;

	SATAFile >> amount;
	//���������� ����� ������ ������� ������
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

	//�������� �����
	std::fstream PowerFile("PowerBlocks.txt");

	//������, ��������� � ����� ������
	int amount;
	std::string name;
	int Watt;
	int cost;

	PowerFile >> amount;
	//���������� ����� ������ ������ �������
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

std::vector<Sborka> CreateConfigas(int configtype, int mincost, int maxcost, std::vector<GraphicsCard> cards,
	std::vector<Motherboard>& mothers, std::vector<Processor> process, std::vector<RAM>& rams, std::vector<SATA>& sats, std::vector<PowerBlock>& powers)
{
	srand(time(NULL));

	//��������� ������

	//������������ ���� ������������������ ������� �������������� �� ��������
	int MaxGraphicPoints = 40;
	int MaxProcPoints = 40;
	int MaxRAMPoints = 8;  //�������� ��� �������� ������
	int MaxSATAPoints = 512;
	int MaxSATAType = 1;

	if (configtype == 2) //�������� ��� �������� ����������
	{
		MaxGraphicPoints = 40;  MaxProcPoints = 60;
		MaxRAMPoints = 8;
		MaxSATAPoints = 512; MaxSATAType = 1;
	}
	else if (configtype == 3) //�������� ��� �������� ����������
	{
		MaxGraphicPoints = 80; MaxProcPoints = 70;
		MaxRAMPoints = 16;
		MaxSATAPoints = 256; MaxSATAType = 2;
	}
	else  if (configtype == 4) //�������� ��� ����������������� ����������
	{
		MaxGraphicPoints = 1000; MaxProcPoints = 1000;
		MaxRAMPoints = 64;
		MaxSATAPoints = 1024; MaxSATAType = 2;
	}

	//����������� ������� ����� ������������������, ������ ������� �� ����� ����������� ������

	int MinGraphicPoints = 0;
	int MinProcPoints = 0;
	int MinRAMPoints = 4;
	int MinSATAPoints = 256;
	int MinSATAType = 1;

	if (configtype == 2)
	{
		MinGraphicPoints = 10; MinProcPoints = 20;
	}
	else if (configtype == 3)
	{
		MinGraphicPoints = 30; MinProcPoints = 30;
		MinRAMPoints = 8;
		MinSATAPoints = 512;
	}
	else if (configtype == 4)
	{
		MinGraphicPoints = 40; MinProcPoints = 50;
		MinRAMPoints = 8;
		MinSATAPoints = 512; MinSATAType = 1;
	}

	//����������, ���������� � ����������
	std::vector<Processor> ProcRange;

	//����� ���������, ���������� �� ���������
	for (int i = cards.size() - 1; i >= 0; i--)
		if (cards[i].GetPoints() > MaxGraphicPoints) cards.erase(cards.begin() + i);
		else if (cards[i].GetPoints() < MinGraphicPoints) cards.erase(cards.begin() + i);

	//����� �����������, ���������� �� ���������
	for (int i = process.size() - 1; i >= 0; i--)
		if (process[i].GetPoints() > MaxProcPoints) process.erase(process.begin() + i);
		else if (process[i].GetPoints() < MinProcPoints) process.erase(process.begin() + i);

	//��� ���������� �������� ������� ������������
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	//��������� ������
	std::vector<Sborka> Sborki;

	//������� ������ ��� ������ ������
	int CurrentRAMPoints = MaxRAMPoints;
	int CurrentSATAPoints = MaxSATAPoints;
	int CurrentSATAType = MaxSATAType;
	int tdp = 0;

	//������ �� �������� ����������
	int GraphicNumber = cards.size() - 1;
	card = cards[GraphicNumber];

	// ����� �����������, ���������� � ������� ����������
	if (ProcRange.empty())
		for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]); 

	//��������� ������
	while (true)
	{
		tdp = 0;
		//������ ���������� � � �����������������
		card = cards[GraphicNumber];
		tdp += card.GetTdp();

		//������ ���������� � ��� �����������������
		proces = ProcRange[ProcRange.size() - 1];
		tdp += proces.GetTdp() + 175;

		//����� ����������� ����� �� ������ ����������
		int b = 0;
		int e = mothers.size();

		for (; mothers[b].GetSocket() != proces.GetSocket(); b++);

		mother = mothers[b];

		//����� ����������� ������
		b = 0;
		e = rams.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (rams[c].GetGB() < (int)CurrentRAMPoints) b = c + 1;
			else e = c;
		}

		if (b > (rams.size() - 1)) b = rams.size() - 1;
		ram = rams[b];

		//����� �������� ����� �� ��������
		b = 0;
		e = sats.size();
		for (int j = 0; j < e; j++)
			if (sats[j].GetGB() == CurrentSATAPoints && sats[j].GetType() == CurrentSATAType)
			{
				b = j;
				break;
			}

		sata = sats[b];

		//����� ����� ������� �� �����������������
		b = 0;
		e = powers.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (powers[c].GetWatt() < (int)tdp) b = c + 1;
			else e = c;
		}

		power = powers[b];

		Sborka sb;
		sb.SetConfig(card, mother, proces, ram, sata, power);

		
		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost)
		{
		//��������� ������, ���� ��� �������� �� ���� � �������� ��������� ������ 
			Sborki.push_back(sb);

			//��������� � ���������� ����������, ������� �������� � ��������� ����������, ���� ������� ���, �� ������ ����������
			if (ProcRange.size() > 1) ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1); //��������� ���������
			else
			{
				//��������� ����������
				cards.erase(cards.begin() + cards.size() - 1);
				GraphicNumber = cards.size() - 1;
				
				//���� ��������� ����������, ���������� �� ���������
				if (cards.empty()) return Sborki;
				else
				{
					card = cards[GraphicNumber];
					ProcRange.clear();
					for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
				}
			}

			//����� ��������� ��������� �����������
			CurrentSATAType = MaxSATAType;
			CurrentSATAPoints = MaxSATAPoints;
			CurrentRAMPoints = MaxRAMPoints;
		}
		else //�� ������� �� ����, ��������� �� ������ �������� �������������
		{
			if (CurrentSATAType != MinSATAType || CurrentSATAPoints != MinSATAPoints) //������� ����
			{
				if (CurrentSATAType == MinSATAType && CurrentSATAPoints > MinSATAPoints)
				{
					CurrentSATAPoints /= 2;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints == MinSATAPoints)
				{
					CurrentSATAType--;
					CurrentSATAPoints = 1024;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints > MinSATAPoints)
				{
					CurrentSATAPoints /= 2;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints == 256 && CurrentSATAPoints != MinSATAPoints)
				{
					CurrentSATAType--;
					CurrentSATAPoints = 1024;
					continue;
				}
			}
			else if (CurrentRAMPoints > MinRAMPoints)//����������� ������
			{
				CurrentRAMPoints /= 2;
				continue;
			}
			else
			{
				if (ProcRange.size() > 1) //��������� � ���������� ����������, ������� �������� � ��������� ����������, ���� ������� ���, �� ������ ����������
				{
					ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1);
					//����� ��������� ��������� �����������
					CurrentSATAType = MaxSATAType;
					CurrentSATAPoints = MaxSATAPoints;
					CurrentRAMPoints = MaxRAMPoints;
					continue;
				}
				else //��������� �������� ����������
				{
					cards.erase(cards.begin() + cards.size() - 1);
					GraphicNumber = cards.size() - 1;
					//���� ��������� ����������, ���������� �� ���������
					if (cards.empty()) return Sborki;
					else
					{
						card = cards[GraphicNumber];
						ProcRange.clear();
						for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
					}
					//����� ��������� ��������� �����������
					CurrentSATAType = MaxSATAType;
					CurrentSATAPoints = MaxSATAPoints;
					CurrentRAMPoints = MaxRAMPoints;

					continue;
				}
			}
		}
	}
}