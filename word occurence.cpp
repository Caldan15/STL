using namespace std;

int main()
{
    // checking if the file exists or creates
    ifstream file("sample.txt");
    if (!file.is_open())
    {
        cout << "Can't Open" << endl;
    }

    // using map to store word and it's occurrance 
    map<string, int> occurrance;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string a;
        while (ss >> a)
        {
            // removing unwanted characters

            // Convert the word to lowercase, to avoid treating "THIS" and "this" as differnt words
            for (char &c : a)
            {
                c = tolower(c);
            }
            ++occurance[a]; // incrementing the word counter
        }
    }

    file.close();

    // display function
    cout << "Word Counts:" << endl;
    for (auto &i : occurance)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
