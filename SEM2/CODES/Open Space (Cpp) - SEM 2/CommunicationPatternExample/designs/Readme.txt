TRAFFIC LIGHT ASSIGNMENT
Examples based on technical report
===================================

Introduction
------------
In this folder you find examples of how use the communication patterns (see
docs/Technical report.adoc) in communication protocol designs. The examples
are based on the the traffic light assignment. The designs are not complete.

Please, study these examples. You can use these examples for your traffic 
light designs.

Designs
-------
Master1a - This is the initial design of the master traffic light. The
           colors of the traffic light are taken as states. Be aware that
           the states do not turn of or off the lights. The actions
           Turn....On() and Turn....Off() turn the lights on and off.
Master1b - This example is similar as Master1a with actions in the states
           instead of actions on the state-transitions (arrows). We prefer
           Master1a with actions on the state-transitions.
Master2  - This example is based on Master1a. When the master is red then 
           it commands the slave to change lights. The blue colored states 
           have been added. When the slave is red again then the master 
           changes light while the slave stays red.
Master3  - This example is based on Master2. This design adds the handling
           of acknowledgement after the master commands the slave to change
           lights. See the green colored states. The example is incomplete. 
           Furtermore, the states for UNKNOWN, CORRUPTED and TIMEDOUT have
           not been completed and needs to be designed. As an example, the 
           FAILED result loops back so that the commands "$GotoGreen;" is 
           send again to the slave. In this example, the acknowledge 
           handling is only done after sending "$GotoGreen;". The design 
           should also handle the acknowledgements for the other commands. 
           The design ends-up in many states, perhaps the number of states
           can be reduced by nesting certain states in functions, like 
           shown in the technical report. This is a challenge, not 
           necessarily a requirement.
Slave1   - This example illustrated how thr slave can receive the commands
           from the master, carries them out, and returns "$ACK" or "$NACK".
           Again, this design is incomplete and for you to complete it.
