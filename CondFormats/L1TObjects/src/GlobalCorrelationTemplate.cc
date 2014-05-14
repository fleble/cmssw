/**
 * \class GlobalCorrelationTemplate
 *
 *
 * Description: L1 Global Trigger correlation template.
 * Includes spatial correlation for two objects of different type.
 *
 * Implementation:
 *    <TODO: enter implementation details>
 *
 * \author: Vasile Mihai Ghete - HEPHY Vienna
 *
 * $Date$
 * $Revision$
 *
 */

// this class header
#include "CondFormats/L1TObjects/interface/GlobalCorrelationTemplate.h"

// system include files

#include <iostream>
#include <iomanip>

// user include files
//   base class

#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetupFwd.h"

// forward declarations

// constructors
//   default

GlobalCorrelationTemplate::GlobalCorrelationTemplate()
        : GlobalCondition()
{

    m_condCategory = l1t::CondCorrelation;
    m_condType = l1t::Type2cor;
    m_condChipNr = -1;

    // there are in fact two objects
    int nObjects = nrObjects();

    if (nObjects > 0) {
        m_objectType.reserve(nObjects);
    }

    m_cond0Category = l1t::CondNull;
    m_cond1Category = l1t::CondNull;
    m_cond0Index = -1;
    m_cond1Index = -1;

}

//   from condition name
GlobalCorrelationTemplate::GlobalCorrelationTemplate(const std::string& cName)
        : GlobalCondition(cName)
{

    m_condCategory = l1t::CondCorrelation;
    m_condType = l1t::Type2cor;
    m_condChipNr = -1;

    // there are in fact two objects
    int nObjects = nrObjects();

    if (nObjects > 0) {
        m_objectType.reserve(nObjects);
    }

    m_cond0Category = l1t::CondNull;
    m_cond1Category = l1t::CondNull;
    m_cond0Index = -1;
    m_cond1Index = -1;

}

//   from condition name, the category of first sub-condition, the category of the
//   second sub-condition, the index of first sub-condition in the cor* vector,
//   the index of second sub-condition in the cor* vector
GlobalCorrelationTemplate::GlobalCorrelationTemplate(const std::string& cName,
        const l1t::GlobalConditionCategory& cond0Cat,
        const l1t::GlobalConditionCategory& cond1Cat,
        const int cond0Index,
        const int cond1index) :
    GlobalCondition(cName),
            m_cond0Category(cond0Cat),
            m_cond1Category(cond1Cat),
            m_cond0Index(cond0Index),
            m_cond1Index(cond1index)

{

    m_condCategory = l1t::CondCorrelation;
    m_condType = l1t::Type2cor;
    m_condChipNr = -1;

    // there are in fact two objects
    int nObjects = nrObjects();

    if (nObjects> 0) {
        m_objectType.resize(nObjects);
    }
}

// copy constructor
GlobalCorrelationTemplate::GlobalCorrelationTemplate(const GlobalCorrelationTemplate& cp)
        : GlobalCondition(cp.m_condName)
{
    copy(cp);
}

// destructor
GlobalCorrelationTemplate::~GlobalCorrelationTemplate()
{
    // empty now
}

// assign operator
GlobalCorrelationTemplate& GlobalCorrelationTemplate::operator= (const GlobalCorrelationTemplate& cp)
{

    copy(cp);
    return *this;
}

// set the category of the two sub-conditions
void GlobalCorrelationTemplate::setCond0Category(
        const l1t::GlobalConditionCategory& condCateg) {

    m_cond0Category = condCateg;
}

void GlobalCorrelationTemplate::setCond1Category(
        const l1t::GlobalConditionCategory& condCateg) {

    m_cond1Category = condCateg;
}


// set the index of the two sub-conditions in the cor* vector from menu
void GlobalCorrelationTemplate::setCond0Index(const int& condIndex) {
    m_cond0Index = condIndex;
}

void GlobalCorrelationTemplate::setCond1Index(const int& condIndex) {
    m_cond1Index = condIndex;
}


// set the correlation parameters of the condition
void GlobalCorrelationTemplate::setCorrelationParameter(
        const CorrelationParameter& corrParameter) {

    m_correlationParameter = corrParameter;

}

void GlobalCorrelationTemplate::print(std::ostream& myCout) const
{

    myCout << "\n  GlobalCorrelationTemplate print..." << std::endl;

    GlobalCondition::print(myCout);

    myCout << "\n  First sub-condition category:  " << m_cond0Category <<  std::endl;
    myCout <<   "  Second sub-condition category: " << m_cond1Category <<  std::endl;

    myCout << "\n  First sub-condition index:  " << m_cond0Index <<  std::endl;
    myCout <<   "  Second sub-condition index: " << m_cond1Index <<  std::endl;

    myCout << "\n  Correlation parameters " << "[ hex ]" <<  std::endl;


    myCout << "    deltaEtaRange      = "
    << std::hex << m_correlationParameter.deltaEtaRange << std::endl;
    myCout << "    deltaPhiRange      = "
    << std::hex << m_correlationParameter.deltaPhiRange << std::endl;
    myCout << "    deltaPhiMaxbits    = "
    << std::hex << m_correlationParameter.deltaPhiMaxbits << std::endl;

    // reset to decimal output
    myCout << std::dec << std::endl;
}

void GlobalCorrelationTemplate::copy(const GlobalCorrelationTemplate& cp)
{

    m_condName     = cp.condName();
    m_condCategory = cp.condCategory();
    m_condType     = cp.condType();
    m_objectType   = cp.objectType();
    m_condGEq      = cp.condGEq();
    m_condChipNr   = cp.condChipNr();

    m_cond0Category = cp.cond0Category();
    m_cond1Category = cp.cond1Category();
    m_cond0Index = cp.cond0Index();
    m_cond1Index = cp.cond1Index();

    m_correlationParameter = *(cp.correlationParameter());

}

// output stream operator
std::ostream& operator<<(std::ostream& os, const GlobalCorrelationTemplate& result)
{
    result.print(os);
    return os;

}



