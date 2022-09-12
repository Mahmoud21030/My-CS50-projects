#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int max(float array[]);

int main(int argc, string argv[])
{

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i]))
        {
            ranks[rank] = i;

            for (int loop = 0; loop < candidate_count; loop++) // debgug
                printf("%d \n", ranks[loop]);

            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    preferences[ranks[0]][ranks[1]]++;
    preferences[ranks[1]][ranks[2]]++;
    for (int rows = 0; rows < candidate_count; rows++)
    {
        for (int columns = 0; columns < candidate_count; columns++)
        {
            printf("%d ", preferences[rows][columns]);
        }
        printf("\n");
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int counter = 0;
    for (int rows = 0; rows < candidate_count; rows++)
    {
        for (int columns = 0; columns < candidate_count; columns++)
        {
            if (rows != columns)
            {
                if (preferences[rows][columns] > preferences[columns][rows])
                {
                    pairs[counter].winner = rows;
                    pairs[counter].loser = columns;
                    counter++;
                    printf("counter is %i\n winner is %i\n loser is %i\n", counter, rows, columns);
                }
            }
        }
    }
    pair_count = counter;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    float array[pair_count];
    pair temp[pair_count];
    int counter = 0;
    for (int i = 0; i < pair_count; i++)
    {
        array[i] = preferences[pairs[i].winner][pairs[i].loser]
        - preferences[pairs[i].loser][pairs[i].winner];
    }
    printf("percent is %0.2f\n", array[0]);

    for (int i = 0; i < pair_count; i++) // search for max
    {
        temp[i] = pairs[max(array)];
        printf("winner %i loser %i \n", temp[i].winner, temp[i].loser);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int rows = 0; rows < pair_count; rows++)
    {
        for (int columns = 0; columns < pair_count; columns++)
        {
            
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

int max(float array[])
{
    int max = 0;
    int index = 0;
    for (int i = 0; i < pair_count; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            index = i;
        }
    }
    printf("%i", index);
    array[index] = 0;
    return index;
}