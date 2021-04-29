#ifndef Hadrons_MUtilities_Subtract_hpp_
#define Hadrons_MUtilities_Subtract_hpp_

#include <Hadrons/Global.hpp>
#include <Hadrons/Module.hpp>
#include <Hadrons/ModuleFactory.hpp>

BEGIN_HADRONS_NAMESPACE

/******************************************************************************
 *                         Subtract                                 *
 ******************************************************************************/
BEGIN_MODULE_NAMESPACE(MUtilities)

class SubtractPar: Serializable
{
public:
    GRID_SERIALIZABLE_CLASS_MEMBERS(SubtractPar,
                                    std::string, q1,
                                    std::string, q2);
};

template <typename FImpl>
class TSubtract: public Module<SubtractPar>
{
public:
    BASIC_TYPE_ALIASES(FImpl,);
    // constructor
    TSubtract(const std::string name);
    // destructor
    virtual ~TSubtract(void) {};
    // dependency relation
    virtual std::vector<std::string> getInput(void);
    virtual std::vector<std::string> getOutput(void);
    // setup
    virtual void setup(void);
    // execution
    virtual void execute(void);
};

MODULE_REGISTER_TMP(Subtract, TSubtract<FIMPL>, MUtilities);

/******************************************************************************
 *                 TSubtract implementation                             *
 ******************************************************************************/
// constructor /////////////////////////////////////////////////////////////////
template <typename FImpl>
TSubtract<FImpl>::TSubtract(const std::string name)
: Module<SubtractPar>(name)
{}

// dependencies/products ///////////////////////////////////////////////////////
template <typename FImpl>
std::vector<std::string> TSubtract<FImpl>::getInput(void)
{
    std::vector<std::string> in { par().q1, par().q2 };
    
    return in;
}

template <typename FImpl>
std::vector<std::string> TSubtract<FImpl>::getOutput(void)
{
    std::vector<std::string> out = {getName()};
    
    return out;
}

// setup ///////////////////////////////////////////////////////////////////////
template <typename FImpl>
void TSubtract<FImpl>::setup(void)
{
    envCreateLat(PropagatorField, getName());
}

// execution ///////////////////////////////////////////////////////////////////
template <typename FImpl>
void TSubtract<FImpl>::execute(void)
{
   auto &q1 = envGet(PropagatorField, par().q1);
   auto &q2 = envGet(PropagatorField, par().q2);
   auto &res = envGet(PropagatorField, getName());
   res=q1-q2;
}

END_MODULE_NAMESPACE

END_HADRONS_NAMESPACE

#endif // Hadrons_MUtilities_Subtract_hpp_
