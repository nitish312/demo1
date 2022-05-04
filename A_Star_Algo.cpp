#include<bits/stdc++.h>
using namespace std;

const int IDIM = 8; 
const int JDIM = 6; 
const int NDIR = 4; 

const int iDir[NDIR] = {1, 0, -1, 0};
const int jDir[NDIR] = {0, 1, 0, -1};
// if NDIR = 8
// const int iDir[NDIR] = {1, 1, 0, -1, -1, -1, 0, 1};
// const int jDir[NDIR] = {0, 1, 1, 1, 0, -1, -1, -1};

int squares[IDIM][JDIM];

int closedNodes[IDIM][JDIM];

int openNodes[IDIM][JDIM];

int dirMap[IDIM][JDIM];

struct Location{
    int row, col;
    Location(){
        row = col = 0;
    };
    Location(int r, int c){
        row = r;
        col = c;
    };
};

class Node
{
    int rPos, cPos;

    int GValue;

    int FValue; 

    public:
        Node(const Location &loc, int g, int f) 
            {rPos = loc.row; cPos = loc.col; GValue = g; FValue = f;}
    
		Location getLocation() const {return Location(rPos,cPos);}
        int getGValue() const {return GValue;}
        int getFValue() const {return FValue;}

        void calculateFValue(const Location& locDest){
             FValue = GValue + getHValue(locDest) * 10; 
        }
        void updateGValue(const int & i){
            GValue += (NDIR == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
        }
        
        const int & getHValue(const Location& locDest) const{
            static int rd, cd, d;
            rd = locDest.row - rPos;
            cd = locDest.col - cPos;         

            d = abs(rd) + abs(cd);
            return(d);
        }

	friend bool operator<(const Node & a, const Node & b){
	    return a.getFValue() > b.getFValue();
	}
};

string pathFind(const Location &locStart, const Location &locFinish){
    static priority_queue<Node> q[2]; 

    static int qi; 

    static Node* pNode1;
    static Node* pNode2;
    static int i, j, row, col, iNext, jNext;
    static char c;
    qi = 0;

    for(j = 0; j < JDIM; j++) {
        for(i = 0; i < IDIM; i++) {
            closedNodes[i][j] = 0;
            openNodes[i][j] = 0;
        }
    }

    pNode1 = new Node(locStart, 0, 0); 
    pNode1->calculateFValue(locFinish);
    q[qi].push(*pNode1);
 
    while(!q[qi].empty()) {
        pNode1 = new Node( q[qi].top().getLocation(), 
                     q[qi].top().getGValue(), q[qi].top().getFValue());

        row = (pNode1->getLocation()).row; 
	    col = pNode1->getLocation().col;
        q[qi].pop(); 
        openNodes[row][col] = 0;

        closedNodes[row][col] = 1;

        if(row == locFinish.row && col == locFinish.col) {
			cout << endl;
			for(j = JDIM - 1; j >= 0; j--) {
				for(i = 0; i < IDIM; i++) {
					cout << dirMap[i][j];
				}
				cout << endl;
			}
			cout << endl;

		    string path = "";
	        while(!(row == locStart.row && col == locStart.col)) {
	            j = dirMap[row][col];
	            c = '0' + (j + NDIR/2) % NDIR;
	            path = c + path;
	            row += iDir[j];
	            col += jDir[j];
	        }

	            // garbage collection
	        delete pNode1;

	            // empty the leftover nodes
	        while(!q[qi].empty()) q[qi].pop();           
	        return path;
	    }

        for(i = 0; i < NDIR; i++) {
            iNext = row + iDir[i]; 
	    jNext = col + jDir[i];

	    if(!(iNext < 0 || iNext > IDIM - 1 || jNext < 0 || jNext > JDIM - 1 || 
			squares[iNext][jNext] == 1 || closedNodes[iNext][jNext] == 1)) {
               
                pNode2 = new Node( Location(iNext, jNext), pNode1->getGValue(), pNode1->getFValue());
                pNode2->updateGValue(i);
                pNode2->calculateFValue(locFinish);

                if(openNodes[iNext][jNext] == 0) {
                    openNodes[iNext][jNext] = pNode2->getFValue();
                    q[qi].push(*pNode2);
                    dirMap[iNext][jNext] = (i + NDIR/2) % NDIR;
                }

		else if(openNodes[iNext][jNext] > pNode2->getFValue()) {
                    openNodes[iNext][jNext] = pNode2->getFValue();

                    dirMap[iNext][jNext] = (i + NDIR/2) % NDIR;

                    while(!(q[qi].top().getLocation().row == iNext && 
                        q[qi].top().getLocation().col == jNext)) {                
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();       
                    }

		    		q[qi].pop(); 
                    
                    if(q[qi].size() > q[1 - qi].size()) qi = 1 - qi;
                    while(!q[qi].empty()) {                
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();       
                    }
                    qi = 1 - qi;

		    		q[qi].push(*pNode2); 
                }
                else delete pNode2; 
            }
        }
        delete pNode1; 
    }
    return ""; 
}

int main()
{
    for(int j = 0; j < JDIM; j++) {
        for(int i = 0; i < IDIM; i++) squares[i][j] = 0;
    }

    squares[4][2] = 1;
    squares[4][3] = 1;
    squares[4][4] = 1;

    int iStart = 1,jStart = 1;
	int iEnd = 7,jEnd = 5;    

    cout << "Grid Size: "<< IDIM<< "," << JDIM << endl;
    cout << "Start: " << iStart<<","<< jStart << endl;
    cout << "Finish: " << iEnd<<","<< jEnd << endl;
 
    string path = pathFind(Location(iStart, jStart), Location(iEnd, jEnd));

    if(path.length() > 0){
        
        char c;
		int m, n;
        int i = iStart;
        int j = jStart;
        squares[i][j] = 2;
        for(m = 0; m < path.length(); m++){
            c = path.at(m);
            n = atoi(&c); 
            i = i + iDir[n];
            j = j + jDir[n];
            squares[i][j] = 3;
        }
        squares[i][j] = 4;
    
        for(j = JDIM - 1; j >= 0; j--) {
            for(i = 0; i < IDIM; i++) {
                if(squares[i][j] == 0)
                    cout << ".";
                else if(squares[i][j] == 1)
                    cout << "|"; //obstacle
                else if(squares[i][j] == 2)
                    cout << "S"; //Initial
                else if(squares[i][j] == 3)
                    cout << "+"; //path
                else if(squares[i][j] == 4)
                    cout << "G"; //final
	    	}
            cout << endl;
        }
    }

    return(0);
}