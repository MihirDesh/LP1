#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void FIFO(int numFrames, const vector<int>& pages)
{
    queue<int> frameQueue;
    unordered_set<int> frameSet;

    int pageFaults = 0;

    for(int page : pages)
    {
        if(frameSet.find(page) == frameSet.end())
        {
            if(frameQueue.size() == numFrames)
            {
                int removedPage = frameQueue.front();
                frameQueue.pop();
                frameSet.erase(removedPage);
            }
            frameQueue.push(page);
            frameSet.insert(page);

            pageFaults++;

            cout << "Page Reference: " << page << " | Status: Miss" << endl;
        }
        else
        {
            cout << "Page Reference: " << page << " | Status: Hit" << endl;
        }
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}
int main() {
    int numFrames, numPages;
    cout << "Enter the number of frames: ";
    cin >> numFrames;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    cout << "Enter the page reference string: ";
    vector<int> pages(numPages);
    for (int i = 0; i < numPages; ++i) {
        cin >> pages[i];
    }

    FIFO(numFrames, pages);

    return 0;
}