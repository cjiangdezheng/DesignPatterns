#include "StdAfx.h"
#include "BaseVisitor.h"


CBaseVisitor::CBaseVisitor(void)
{
	m_commonTotal = 0;
	m_managerTotal = 0;
}

CBaseVisitor::~CBaseVisitor(void)
{
}

void CBaseVisitor::Visit(CCommonEmployee commonEmployee)
{
	cout << this->GetCommonEmployee(commonEmployee).c_str() << endl;
	this->CalCommonSalary(commonEmployee.GetSalary());
}

void CBaseVisitor::Visit(CManager manager)
{
	cout << this->GetManagerInfo(manager).c_str() << endl;
	this->CalManagerSalary(manager.GetSalary());
}

string CBaseVisitor::GetBasicInfo(CEmployee *pemployee)
{
	string info = "";
	info.append("姓名：");
	info.append(pemployee->GetName());
	info.append("\t");
	info.append("性别：");

	char strSex[100] = {0} ;
	sprintf(strSex,"%d",pemployee->GetSex());
	//strSex = itoa(pemployee->GetSex());
	info.append(strSex);
	info.append("\t");
	info.append("薪水：");
	char strSalary[100] = {0} ;
	sprintf(strSalary,"%d",pemployee->GetSalary());
	//strSalary = itoa(pemployee->GetSalary());
	info.append(strSalary);
	info.append("\t");
	return info;
}

string CBaseVisitor::GetManagerInfo(CManager manager)
{
	string basicInfo = this->GetBasicInfo(&manager);
	string otherInfo = "";
	otherInfo.append("业绩：");
	otherInfo.append(manager.GetPerformance());
	otherInfo.append("\t");
	basicInfo.append(otherInfo);
	return basicInfo;
}

string CBaseVisitor::GetCommonEmployee(CCommonEmployee employee)
{
	string basicInfo = this->GetBasicInfo(&employee);
	string otherInfo = "";
	otherInfo.append("工作：");
	otherInfo.append(employee.GetJob());
	otherInfo.append("\t");
	basicInfo.append(otherInfo);
	return basicInfo;
}

int CBaseVisitor::GetTotalSalary()
{
	return this->m_commonTotal + this->m_managerTotal;
}

void CBaseVisitor::CalCommonSalary(int salary)
{
	this->m_commonTotal += salary;
}

void CBaseVisitor::CalManagerSalary(int salary)
{
	this->m_managerTotal += salary;
}