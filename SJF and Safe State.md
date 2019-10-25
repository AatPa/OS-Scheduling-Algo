# OS-Scheduling-Algo
Safe State

    A state is safe if the system can allocate all resources requested by all processes ( up to their stated maximums ) without entering a deadlock state.
    More formally, a state is safe if there exists a safe sequence of processes { P0, P1, P2, ..., PN } such that all of the resource requests for Pi can be granted using the resources currently allocated to Pi and all processes Pj where j < i. ( I.e. if all the processes prior to Pi finish and free up their resources, then Pi will be able to finish also, using the resources that they have freed up. )
    If a safe sequence does not exist, then the system is in an unsafe state, which MAY lead to deadlock. ( All safe states are deadlock free, but not all unsafe states lead to deadlocks. )


Shortest Job First scheduling works on the process with the shortest burst time or duration first.

    This is the best approach to minimize waiting time.
    This is used in Batch Systems.
    It is of two types:
        Non Pre-emptive
        Pre-emptive
    To successfully implement it, the burst time/duration time of the processes should be known to the processor in advance, which is practically not feasible all the time.
    This scheduling algorithm is optimal if all the jobs/processes are available at the same time. (either Arrival time is 0 for all, or Arrival time is same for all)
