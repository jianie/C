#include "AdjMatGraph.h"

void main()
{
	AdjMatGraph g;
	
	for( int i=0 ; i<4 ; i++ )
		g.insertVertex( 'A'+i );

	g.insertEdge(0,1);
	g.insertEdge(0,3);
	g.insertEdge(1,2);
	g.insertEdge(1,3);
	g.insertEdge(2,3);
	printf("���� ��ķ� ǥ���� �׷���\n");
	g.display();
	g.store( "graph.txt" );

	g.reset();
	g.load( "graph.txt" );
	printf("���� ��ķ� ǥ���� �׷��� (����:graph.txt)\n");
	g.display();


/*
	AdjMatGraph g1;
	g1.Load( "graph.txt" );
	printf("���� ��ķ� ǥ���� �׷��� (����:graph.txt)\n");
	g1.display();
*/
}