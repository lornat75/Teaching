#include <Module.h>
#include <yarpWholeBodyInterface/yarpWholeBodyInterface.h>
#include <yarp/os/ResourceFinder.h>
#include <yarp/os/Property.h>
#include <yarp/sig/Vector.h>

double Module::getPeriod () { return 0.01; }

bool Module::updateModule ()
{
    wbi::Frame w_H_b; //identity + zero vector

    //read state
    m_robot->getEstimates(wbi::ESTIMATE_JOINT_POS, positions.data());
    m_robot->getEstimates(wbi::ESTIMATE_JOINT_VEL, velocities.data());
    m_robot->computeGeneralizedBiasForces(positions.data(), w_H_b, zeroDofs.data(),
                                        baseZeroDofs.data(), grav.data(), gravityCompensation.data());

                                        // std::cout << gravityCompensation.toString() <<  "\n";
    //compute control
    for (int i = 0; i < m_robot->getDoFs(); i++) {
        error(i) = referencePositions(i) - positions(i);
        torques(i) = gravityCompensation(i + 6) + kp(i) * error(i) - kd(i) * velocities(i);
    }

    m_robot->setControlReference(torques.data());
    
    return true;
}

bool Module::configure (yarp::os::ResourceFinder &rf)
{
    using namespace yarp::os;
    using namespace yarp::sig;
    
    Property wbiProperties;
    if (!rf.check("wbi_config_file", "Checking wbi configuration file")) {
        std::cout << "No WBI configuration file found.\n";
        return false;
    }

    if (!wbiProperties.fromConfigFile(rf.findFile("wbi_config_file"))) {
        std::cout << "Not possible to load WBI properties from file.\n";
        return false;
    }
    wbiProperties.fromString(rf.toString(), false);

    //retrieve the joint list
    std::string wbiList = rf.check("wbi_list", Value("ROBOT_TORQUE_CONTROL_JOINTS_WITHOUT_PRONOSUP"), "Looking for wbi list").asString();

    wbi::IDList iCubMainJoints;
    if (!yarpWbi::loadIdListFromConfig(wbiList, wbiProperties, iCubMainJoints)) {
        std::cout << "Cannot find joint list\n";
        return false;
    }

    double actuatedDOFs = iCubMainJoints.size();

    //create an instance of wbi
    m_robot = new yarpWbi::yarpWholeBodyInterface("wbi_example_cpp", wbiProperties);
    if (!m_robot) {
        std::cout << "Could not create wbi object.\n";
        return false;
    }

    m_robot->addJoints(iCubMainJoints);
    if (!m_robot->init()) {
        std::cout << "Could not initialize wbi object.\n";
        return false;
    }
    
    //Creating and configuring a wbi instance.
    //We use the yarp implementation.

    //Load information about the joints and global properties for the wbi
    //this file also contains references to the urdf model
    
    std::cout << "Number of DOFs: " << actuatedDOFs << "\n";

    positions.resize(actuatedDOFs, 0.0);
    velocities.resize(actuatedDOFs, 0.0);
    gravityCompensation.resize(actuatedDOFs + 6, 0.0);
    referencePositions.resize(actuatedDOFs, 0.0);
    
    m_robot->getEstimates(wbi::ESTIMATE_JOINT_POS, referencePositions.data());
    
    int index = -1;
    if (!m_robot->getJointList().idToIndex("l_shoulder_pitch", index)) {
        std::cout << "Could not retrieve index of l_shoulder_pitch.\n";
        return false;
    }
    referencePositions(index) += 1.5;
    
    if (!m_robot->getJointList().idToIndex("l_elbow", index)) {
        std::cout << "Could not retrieve index of l_elbow.\n";
        return false;
    }
    referencePositions(index) += 1.5;
    
    if (!m_robot->getJointList().idToIndex("r_shoulder_pitch", index)) {
        std::cout << "Could not retrieve index of r_shoulder_pitch.\n";
        return false;
    }
    referencePositions(index) += 1.5;
    
    if (!m_robot->getJointList().idToIndex("r_elbow", index)) {
        std::cout << "Could not retrieve index of r_elbow.\n";
        return false;
    }
    referencePositions(index) += 1.5;
    
    //write
    error.resize(actuatedDOFs, 0.0);

    kp.resize(actuatedDOFs, 1.5);
    kd.resize(actuatedDOFs, 0.5);
    
    torques.resize(actuatedDOFs, 0.0);
    
    zeroDofs.resize(actuatedDOFs, 0.0);
    baseZeroDofs.resize(6, 0.0);
    
    grav.resize(3, 0.0);
    grav(2) = -9.81;
    
    m_robot->setControlMode(wbi::CTRL_MODE_TORQUE);
    
    return true;
}

bool Module::close ()
{
    m_robot->setControlMode(wbi::CTRL_MODE_POS);

    //cleanup stuff
    m_robot->close();
    delete m_robot;
    m_robot = 0;
    return true;
}

