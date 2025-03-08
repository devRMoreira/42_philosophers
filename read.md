1. Initialize Project
Set up the project structure and create necessary files.
Define the t_data structure and declare functions in philo.h.
2. Parse Input
Implement parse_input to read and validate command-line arguments.
Initialize the t_data structure with parsed values.
3. Initialize Resources
Allocate memory for philosopher threads and forks (mutexes).
Initialize mutexes for forks and a print lock.
4. Philosopher Behavior
Implement the philosopher function to define the behavior of each philosopher:
Thinking
Picking up forks (locking mutexes)
Eating
Putting down forks (unlocking mutexes)
Sleeping
5. Create and Manage Threads
Create philosopher threads and pass the t_data structure to each thread.
Wait for all threads to finish.
Clean up resources (destroy mutexes, free memory).


## Detailed Pseudocode


main(argc, argv)
    if argc != 6
        print_error("Invalid number of arguments")
        return 1

	 if parse_input(argv, &philo)
        print_error("Invalid input")
        return 1

    allocate memory for threads and forks
    initialize mutexes for forks and print lock

    for each philosopher
        create a thread and pass the philo structure

    for each philosopher
        wait for the thread to finish

    destroy mutexes and free memory
    return 0

parse_input(argv, philo)
    convert argv to integers and store in input array
    if validate(input)
        return 1
    init_struct(input, philo)
    return 0

philosopher(arg)
    while simulation not ended
        print "Philosopher is thinking"
        sleep for a short duration

        lock left fork
        lock right fork
        print "Philosopher picked up forks"

        print "Philosopher is eating"
        sleep for eating duration

        unlock right fork
        unlock left fork

        print "Philosopher is sleeping"
        sleep for sleeping duration

validate(input)
    for each value in input
        if value is invalid
            return 1
    return 0

init_struct(input, philo)
    philo.total_philo = input[0]
    philo.time_die = input[1]
    philo.time_eat = input[2]
    philo.time_sleep = input[3]
    philo.amount_eat = input[4]

print_error(descriptor)
    print "Error: " + descriptor to stderr

print_data(data)
    print each field of the data structure
