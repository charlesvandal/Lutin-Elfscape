#ifndef SIMULATOR_BUILDER_HPP
#define SIMULATOR_BUILDER_HPP

#include "Simulator.hpp"

class SimulatorBuilder
{
    public:
    static std::unique_ptr<Simulator> builSimulator(const uint8_t numberColumns,
                                                    const uint8_t numberRows);

    private:
    SimulatorBuilder() = delete;
    SimulatorBuilder(SimulatorBuilder&) = delete;
    SimulatorBuilder(SimulatorBuilder&&) = delete;
    SimulatorBuilder(const SimulatorBuilder&) = delete;
    SimulatorBuilder(const SimulatorBuilder&&) = delete;
    ~SimulatorBuilder() = delete;
};

#endif // SIMULATOR_BUILDER_HPP