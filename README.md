The performance measure awards one point for each clean square at each time step,
over a "lifetime" of 1000 time steps.

The "geography" of the environment is known a priori (Figure 2.2) but the dirt distri -
bution and the initial location of the agent are not. Clean squares stay clean and sucking
cleans the current square. The Lefi and Right actions move the agent left and right
except when this would take the agent outside the environment, in which case the agent
remains where it is.

The only available actions are Left, Right, S u c k , and NoOp (do nothing).

The agent correctly perceives its location and whether that location contains dirt.