package DijkstrasAlgorithm;

import DijkstrasAlgorithm.Vertex;

public class Edge {
    private double weight;
    private Vertex startVetex;
    private Vertex targetVertex;

    // DijkstrasAlgorithm.Edge Constructor
    public Edge(double weight, Vertex startVetex, Vertex targetVertex) {
        this.weight = weight;
        this.startVetex = startVetex;
        this.targetVertex = targetVertex;
    }

    // DijkstrasAlgorithm.Edge related Getters and Setters
    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public Vertex getStartVetex() {
        return startVetex;
    }

    public void setStartVetex(Vertex startVetex) {
        this.startVetex = startVetex;
    }

    public Vertex getTargetVertex() {
        return targetVertex;
    }

    public void setTargetVertex(Vertex targetVertex) {
        this.targetVertex = targetVertex;
    }
}
