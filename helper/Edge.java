
package helper;

public class Edge {		
	public Edge(int n1, int n2, int w) {this.node1_idx = n1; this.node2_idx = n2; this.weight = w; }
	
	private int node1_idx;
	private int node2_idx;
	private int weight;	
	
	public int get_weight() { return this.weight; }
	public int get_node1() { return this.node1_idx; }
	public int get_node2() { return this.node2_idx; }
}
