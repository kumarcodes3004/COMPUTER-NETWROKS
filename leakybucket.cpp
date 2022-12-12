

// cpp program to implement leakybucket
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_queries, storage, output_pkt_size;
    int input_pkt_size, bucket_size, size_left;

    // initial packets in the bucket
    storage = 0;

    // total no. of times bucket content is checked
    no_of_queries = 4;

    // total no. of packets that can
    // be accommodated in the bucket
    bucket_size = 10;

    // no. of packets that enters the bucket at a time
    input_pkt_size = 4;

    // no. of packets that exits the bucket at a time
    output_pkt_size = 1;
    for (int i = 0; i < no_of_queries; i++) // space left
    {
        size_left = bucket_size - storage;
        if (input_pkt_size <= size_left)
        {
            // update storage
            storage += input_pkt_size;
        }
        else
        {
            printf("Packet loss = %d\n", input_pkt_size);
        }
        printf("Buffer size= %d out of bucket size= %d\n",
               storage, bucket_size);
        storage -= output_pkt_size;
    }
    return 0;
}
