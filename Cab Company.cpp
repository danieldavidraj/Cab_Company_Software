#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<map>
#include<graphics.h>
#include <chrono>
#include <thread>
#include <functional>
typedef std::pair<int, int> int_pair;
using std::priority_queue;
using std::vector;
using std::greater;
using std::list;
using std::cout;
using namespace std;

void House1Mall1(int color)
{
    setcolor(color);
    line(75,50,155,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,25,"5km");
}
void Mall1House2(int color)
{
    setcolor(color);
    line(180,75,180,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(190,100,"7km");
}
void House2House3(int color)
{
    setcolor(color);
    line(75,170,155,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,145,"9km");
}
void House1House3(int color)
{
    setcolor(color);
    line(50,75,50,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,100,"2km");
}
void House3Mall2(int color)
{
    setcolor(color);
    line(50,195,50,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,240,"4km");
}
void Mall2House4(int color)
{
    setcolor(color);
    line(75,320,305,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(170,295,"15km");
}
void House4Mall3(int color)
{
    setcolor(color);
    line(330,195,330,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(340,235,"3km");
}
void Mall3House2(int color)
{
    setcolor(color);
    line(205,170,305,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(235,145,"6km");
}
void Mall1House5(int color)
{
    setcolor(color);
    line(205,50,425,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(305,25,"8km");
}
void House5Mall4(int color)
{
    setcolor(color);
    line(450,75,450,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(460,180,"11km");
}
void House4Mall4(int color)
{
    setcolor(color);
    line(355,320,425,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(370,290,"1km");
}
void Cab1(char *cab)
{
    setcolor(BLACK);
    circle(115,105,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(115,105,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(90,97,cab);
}
void Cab2(char *cab)
{
    setcolor(BLACK);
    circle(350,105,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(350,105,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(325,97,cab);
}
void Cab3(char *cab)
{
    setcolor(BLACK);
    circle(200,240,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(200,240,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(175,233,cab);
}

std::map<std::string, int> roadMap;

class Graph
{
    private:
        unsigned V;
        std::list<std::pair<int, int> > *adj_list;
        void print_path(std::vector<int> &, int, int);
    public:
        Graph(int);
        ~Graph();
        void add_edge(int, int, int);
        int shortest_path(int, int);
        int cab_distance(int, int);
        int shortest_path_display(int, int);
        void remove_edge(int, int);
        void printLoc(int);
        string path[11];
        int i;
};

Graph::Graph(int V)
{
    this->V = V;
    adj_list = new std::list<std::pair<int, int> >[V];
    i=0;
}

Graph::~Graph()
{
    delete [] adj_list;
}

void Graph::add_edge(int u, int v, int w)
{
    adj_list[u].push_back(std::make_pair(v, w));
    adj_list[v].push_back(std::make_pair(u, w));
}

void Graph::printLoc(int v)
{
    std::map<std::string, int>::iterator it;
    for (it=roadMap.begin();it!=roadMap.end();it++)
    {
        if(v==it->second)
        {
            std::cout <<it->first;
            if(it->first.length()>0)
            path[i++]=it->first;
        }
    }
}

void Graph::remove_edge(int u, int v)
{
    std::list<std::pair<int, int> >::iterator itr, itfound;
    for(itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++) {
        if(itr->first==v)
            itfound=itr;
    }
    adj_list[u].erase(itfound);


    for ( itr = adj_list[v].begin(); itr != adj_list[v].end(); itr++) {
        if(itr->first==u)
            itfound=itr;
    }
    adj_list[v].erase(itfound);
}

void Graph::print_path(std::vector<int> &penultimate, int v, int des)
{
    if (penultimate[v] == -1)
    {
        printLoc(v);
        std::cout << "-->";
        return ;
    }
    print_path(penultimate, penultimate[v], des);
    if(v==des)
    {
        printLoc(v);
        std::cout ;
    }
    else
    {
        printLoc(v);
        std::cout << "-->";
    }
}
//only returns the shortest path(without considering cabs)
int Graph::shortest_path(int src, int des)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair> > pq;

    vector<int> dist(V, INT_MAX);

    vector<int> penultimate(V);
    penultimate[src] = -1;

    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();

        list<int_pair>::iterator it;
        for (it = adj_list[u].begin(); it != adj_list[u].end(); it++)
        {
                int v = it->first;
                int w = it->second;
                if (dist[v] > dist[u] + w)
                {
                    if(it->first!=9 && it->first!=10 && it->first!=11)
                    {
                        dist[v] = dist[u] + w;
                        pq.push(std::make_pair(dist[v], v));
                        penultimate[v] = u;
                    }
                }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if(i==des)
        {
            return dist[i];
        }
    }
    return 0;
}
//only returns the shortest path(with considering cabs)
int Graph::cab_distance(int src, int des)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair> > pq;

    vector<int> dist(V, INT_MAX);

    vector<int> penultimate(V);
    penultimate[src] = -1;

    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();

        list<int_pair>::iterator it;
        for (it = adj_list[u].begin(); it != adj_list[u].end(); it++)
        {
                int v = it->first;
                int w = it->second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(std::make_pair(dist[v], v));
                    penultimate[v] = u;
                }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if(i==des)
        {
            return dist[i];
        }
    }
    return 0;
}
//to display the shortest path
int Graph::shortest_path_display(int src, int des)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair> > pq;

    vector<int> dist(V, INT_MAX);

    vector<int> penultimate(V);
    penultimate[src] = -1;

    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();

        list<int_pair>::iterator it;
        for (it = adj_list[u].begin(); it != adj_list[u].end(); it++) {
            int v = it->first;
            int w = it->second;

            if (dist[v] > dist[u] + w)
            {
                if(it->first!=9 && it->first!=10 && it->first!=11)
                {
                    dist[v] = dist[u] + w;
                    pq.push(std::make_pair(dist[v], v));
                    penultimate[v] = u;
                }
            }
        }
    }
    cout << "Shortest Dist      Path\n";
    for (int i = 0; i < V; i++)
    {
        if(i==des){
        cout << dist[i] << "\t\t";
        print_path(penultimate, i, des);
        cout << '\n';
        }
    }
    return 0;
}
std::string findCab(int x, int y, int z,bool cab[])
{
    //check if cab is available else choose another cab
    if(cab[0]==false && cab[1]==false && cab[2]==false)
    {
        cout<<"No Cabs are available\n";
        exit(0);
    }
    else
    {
        if(cab[0]==false)x=INT_MAX;
        if(cab[1]==false)y=INT_MAX;
        if(cab[2]==false)z=INT_MAX;

        int min = x < y ? (x < z ? x : z) : (y < z ? y : z);
        if(min==x)
            return "Cab 1";
        else if(min==y)
            return "Cab 2";
        else
            return "Cab 3";
    }
}

void timer_start(std::function<void(bool&)> func,bool &cab,unsigned int interval)
{
    std::thread([func,&cab,interval]()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        func(cab);
    }).detach();
}
void Cab_Status(bool &cab)
{
    cab=true;

}

int main()
{
    int V = 12;
    Graph g(V);
    //Houses and Malls
    roadMap["House 1"] = 0;
    roadMap["Mall 1"] = 1;
    roadMap["House 5"] = 2;
    roadMap["House 3"] = 3;
    roadMap["House 2"] = 4;
    roadMap["Mall 3"] = 5;
    roadMap["Mall 2"] = 6;
    roadMap["House 4"] = 7;
    roadMap["Mall 4"] = 8;

    g.add_edge(0, 1, 5);
    g.add_edge(1, 2, 8);
    g.add_edge(0, 3, 2);
    g.add_edge(3, 6, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(4, 5, 6);
    g.add_edge(6, 7, 15);
    g.add_edge(5, 7, 3);
    g.add_edge(7, 8, 1);
    g.add_edge(8, 2, 11);
    //Cabs
    bool cab[3];
    cab[0]=true; //true->cab available    false->cab not available
    cab[1]=true;
    cab[2]=true;

    roadMap["Cab 1"] = 9;
    roadMap["Cab 2"] = 10;
    roadMap["Cab 3"] = 11;

    char cab1[10]="Cab1";
    char cab2[10]="Cab2";
    char cab3[10]="Cab3";
    //Cab1
    g.add_edge(9, 0, 1);
    g.add_edge(9, 1, 1);
    g.add_edge(9, 3, 1);
    g.add_edge(9, 4, 1);
    //Cab2
    g.add_edge(10, 1, 1);
    g.add_edge(10, 2, 1);
    g.add_edge(10, 8, 1);
    g.add_edge(10, 7, 1);
    g.add_edge(10, 4, 1);
    g.add_edge(10, 5, 1);
    //Cab3
    g.add_edge(11, 6, 1);
    g.add_edge(11, 3, 1);
    g.add_edge(11, 4, 1);
    g.add_edge(11, 5, 1);
    g.add_edge(11, 7, 1);

    std::map<std::string, int>::iterator it,it1;
    std::string source, destination;
    l1:cin.sync();
    std::cout<<"\nEnter source:";
    std::getline(std::cin, source);
    for(it=roadMap.begin();it!=roadMap.end(); it++)
    {
        if(source==it->first)
            break;
    }
    if(it==roadMap.end())
    {
        cout<<"Enter valid location";
        goto l1;
    }

    l2:std::cout<<"\nEnter destination:";
    std::getline(std::cin, destination);
    for(it=roadMap.begin();it!=roadMap.end(); it++)
    {
        if(destination==it->first)
            break;
    }
    if(it==roadMap.end())
    {
        cout<<"Enter valid location";
        goto l2;
    }
    it=roadMap.find(source);
    it1=roadMap.find(destination);
    if(it->first==it1->first)
    {
        cout<<"Please enter a different destination\n";
        goto l1;
    }

    cout<<"Driver UI:\n\tPick-Up:"<<it->first<<"\n\tDrop:"<<it1->first<<endl;
    int distance=g.shortest_path(it->second, it1->second);
    g.shortest_path_display(it->second, it1->second); // shortest distance between source and destination

    initwindow(640,480,"Map");

    //bg
    setbkcolor(15);
    setfillstyle(SOLID_FILL,15);
    floodfill(1,1,15);

     //mall 1
    setcolor(BLACK);
    rectangle(155,25,205,75);
    setfillstyle(SOLID_FILL,12);
    floodfill(156,26,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(160,45,"Mall 1");

    //mall 2
    setcolor(BLACK);
    rectangle(25,295,75,345);
    setfillstyle(SOLID_FILL,12);
    floodfill(26,296,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(30,315,"Mall 2");

    //mall 3
    setcolor(BLACK);
    rectangle(305,145,355,195);
    setfillstyle(SOLID_FILL,12);
    floodfill(306,146,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(310,165,"Mall 3");

    //mall 4
    setcolor(BLACK);
    rectangle(425,295,475,345);
    setfillstyle(SOLID_FILL,12);
    floodfill(426,296,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(430,315,"Mall 4");

    //house 1
    setcolor(BLACK);
    rectangle(25,25,75,75);
    setfillstyle(SOLID_FILL,7);
    floodfill(26,26,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(28,45,"House 1");

    //house 2
    setcolor(BLACK);
    rectangle(155,145,205,195);
    setfillstyle(SOLID_FILL,7);
    floodfill(156,156,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(158,165,"House 2");

    //house 3
    setcolor(BLACK);
    rectangle(25,145,75,195);
    setfillstyle(SOLID_FILL,7);
    floodfill(26,146,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(28,165,"House 3");

    //house 4
    setcolor(BLACK);
    rectangle(305,295,355,345);
    setfillstyle(SOLID_FILL,7);
    floodfill(306,296,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(308,315,"House 4");

    //house 5
    setcolor(BLACK);
    rectangle(425,25,475,75);
    setfillstyle(SOLID_FILL,7);
    floodfill(426,26,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(428,45,"House 5");

    Cab1(cab1);
    Cab2(cab2);
    Cab3(cab3);

    int color=0;
    House1Mall1(color);
    Mall1House2(color);
    House2House3(color);
    House1House3(color);
    House3Mall2(color);
    Mall2House4(color);
    House4Mall3(color);
    Mall3House2(color);
    Mall1House5(color);
    House5Mall4(color);
    House4Mall4(color);
    for(int i=0;i<10;i++)
    {
        if( (g.path[i]=="House 1" && g.path[i+1]=="Mall 1") || (g.path[i]=="Mall 1" && g.path[i+1]=="House 1") )
        {
            House1Mall1(13);
        }
        if( (g.path[i]=="Mall 1" && g.path[i+1]=="House 2") || (g.path[i]=="House 2" && g.path[i+1]=="Mall 1") )
        {
            Mall1House2(13);
        }
        if( (g.path[i]=="House 2" && g.path[i+1]=="House 3") || (g.path[i]=="House 3" && g.path[i+1]=="House 2") )
        {
            House2House3(13);
        }
        if( (g.path[i]=="House 1" && g.path[i+1]=="House 3") || (g.path[i]=="House 3" && g.path[i+1]=="House 1") )
        {
            House1House3(13);
        }

        if( (g.path[i]=="House 3" && g.path[i+1]=="Mall 2") || (g.path[i]=="Mall 2" && g.path[i+1]=="House 3") )
        {
            House3Mall2(13);
        }
        if( (g.path[i]=="Mall 2" && g.path[i+1]=="House 4") || (g.path[i]=="House 4" && g.path[i+1]=="Mall 2") )
        {
            Mall2House4(13);
        }
        if( (g.path[i]=="House 4" && g.path[i+1]=="Mall 3") || (g.path[i]=="Mall 3" && g.path[i+1]=="House 4") )
        {
            House4Mall3(13);
        }
        if( (g.path[i]=="Mall 3" && g.path[i+1]=="House 2") || (g.path[i]=="House 2" && g.path[i+1]=="Mall 3") )
        {
            Mall3House2(13);
        }

        if( (g.path[i]=="Mall 1" && g.path[i+1]=="House 5") || (g.path[i]=="House 5" && g.path[i+1]=="Mall 1") )
        {
            Mall1House5(13);
        }
        if( (g.path[i]=="House 5" && g.path[i+1]=="Mall 4") || (g.path[i]=="Mall 4" && g.path[i+1]=="House 5") )
        {
            House5Mall4(13);
        }
        if( (g.path[i]=="House 4" && g.path[i+1]=="Mall 4") || (g.path[i]=="Mall 4" && g.path[i+1]=="House 4") )
        {
            House4Mall4(13);
        }
    }
    cout<<"\nCustomer UI:\n";
    string PickupCab=findCab(g.cab_distance(it->second, 9), g.cab_distance(it->second, 10), g.cab_distance(it->second, 11),cab);
    cout<<PickupCab<<" will arrive shortly\n";
    cout<<"Amount:Rs "<<distance*10<<" /-"; //10 Rs for 1 km
    int time=distance*1000; //1 sec to travel 1 km
    if((PickupCab)=="Cab 1")
    {
        cab[0]=false; //mark cab as unavailable as it is occupied
        timer_start(Cab_Status,cab[0],time); //cab will be available after that 'time'
        if(it1->first=="Mall 3" || it1->first=="House 4" || it1->first=="Mall 2")
        {
           //cab 1 goes to the place of cab 3 because destination is close to cab 3
           strcat(cab3,cab1);
           strcpy(cab1,"");
           g.remove_edge(9,0);
           g.remove_edge(9,1);
           g.add_edge(9,5,1);
           g.add_edge(9,7,1);
           g.add_edge(9,6,1);
        }
        if(it1->first=="House 5" || it1->first=="Mall 4")
        {
            //cab 1 goes to the place of cab 2 because destination is close to cab 2
            strcat(cab2,cab1);
            strcpy(cab1,"");
            g.remove_edge(9,0);
            g.remove_edge(9,3);
            g.add_edge(9,2,1);
            g.add_edge(9,8,1);
            g.add_edge(9,5,1);
            g.add_edge(9,7,1);
        }
    }
    if((PickupCab)=="Cab 2")
    {
        cab[1]=false;
        timer_start(Cab_Status,cab[1],time);
        if(it1->first=="House 1" || it1->first=="House 3")
        {
            //cab 2 goes to the place of cab 1 because destination is close to cab 2
            strcat(cab1,cab2);
            strcpy(cab2,"");
            g.remove_edge(10,5);
            g.remove_edge(10,7);
            g.remove_edge(10,8);
            g.remove_edge(10,2);
            g.add_edge(10,0,1);
            g.add_edge(10,3,1);

        }
        if(it1->first=="House 3" || it1->first=="Mall 2")
        {
           //cab 2 goes to the place of cab 3 because destination is close to cab 3
           strcat(cab3,cab2);
           strcpy(cab2,"");
           g.remove_edge(10,1);
           g.remove_edge(10,2);
           g.remove_edge(10,8);
           g.add_edge(10,3,1);
           g.add_edge(10,6,1);
        }
    }
    if((PickupCab)=="Cab 3")
    {
        cab[2]=false;
        timer_start(Cab_Status,cab[2],time);
        if(it1->first=="House 1" || it1->first=="Mall 1")
        {
            //cab 3 goes to the place of cab 1 because destination is close to cab 1
            strcat(cab1,cab3);
            strcpy(cab3,"");
            g.remove_edge(11,5);
            g.remove_edge(11,7);
            g.remove_edge(11,6);
            g.add_edge(11,0,1);
            g.add_edge(11,1,1);

        }
        if(it1->first=="House 5" || it1->first=="Mall 4")
        {
           //cab 3 goes to the place of cab 2 because destination is close to cab 2
           strcat(cab2,cab3);
           strcpy(cab3,"");
           g.remove_edge(11,3);
           g.remove_edge(11,6);
           g.add_edge(11,1,1);
           g.add_edge(11,2,1);
           g.add_edge(11,8,1);
        }
    }
    int n;
    l3:cout<<"\n\n1)Book a Ride\n2)Exit\nChoice:";
    cin>>n;
    if(n==1)
    {
        closegraph(); //closes the graph window
        //clears the path array
        for(int i=0;i<11;i++)
        {
            g.path[i].clear();
        }
        goto l1;
    }
    else if(n==2)
    {
        exit(0);
    }
    else
    {
        cout<<"Invalid Entry\n";
        goto l3;
    }
    return 0;
}
