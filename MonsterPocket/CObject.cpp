#include "CObject.h"

CObject::CObject()
{
}

CObject::CObject(std::string nameObject, std::string typeOfObject)
{
	m_nameObject = nameObject;
	m_typeOfObject = typeOfObject;
}

CObject::~CObject()
{

}

std::string CObject::getterNameObject()
{
	return m_nameObject;
}

std::string CObject::getterTypeOfObject()
{
	return m_typeOfObject;
}

void CObject::setterNameObject(std::string nameObject)
{
	m_nameObject = nameObject;
}

