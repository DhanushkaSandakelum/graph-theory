package DijkstrasAlgorithm;

public class App {
    public static void main(String[] args) {
        Vertex A = new Vertex("A");
        Vertex B = new Vertex("B");
        Vertex C = new Vertex("C");
        Vertex D = new Vertex("D");
        Vertex E = new Vertex("E");

        A.addNeighbour(new Edge(6, A, B));
        A.addNeighbour(new Edge(1, A, D));

        B.addNeighbour(new Edge(6, B, A));
        B.addNeighbour(new Edge(2, B, D));
        B.addNeighbour(new Edge(2, B, E));
        B.addNeighbour(new Edge(5, B, C));

        C.addNeighbour(new Edge(5, C, B));
        C.addNeighbour(new Edge(5, C, E));

        D.addNeighbour(new Edge(1, D, A));
        D.addNeighbour(new Edge(2, D, B));
        D.addNeighbour(new Edge(1, D, E));

        E.addNeighbour(new Edge(1, E, D));
        E.addNeighbour(new Edge(2, E, B));
        E.addNeighbour(new Edge(5, E, C));

        ShortestPath shortestPath = new ShortestPath();
        shortestPath.computePaths(A);

        System.out.println("Shortest path from A to C: ");
        System.out.println(shortestPath.getShortestPathTo(C));
    }
}
