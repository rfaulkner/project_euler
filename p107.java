
/**
 * Project Euler problem 107 implementation
 * 
 * http://projecteuler.net/problem=107
 *
 * @author Ryan Faulkner
 */

import java.util.Iterator;
import java.util.ArrayList;
import helper.Edge;
import helper.EdgeComparator;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.PriorityQueue;

public class p107 {
	
	private static int num_nodes = 40;
	private static boolean[] visited = new boolean[num_nodes];
	private static int[][] adj_list = new int[num_nodes][num_nodes];
	
	public static void readfile(String filename) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader(filename));	
		try {      
			String line = br.readLine();
			String[] elems;
			int line_cnt = 0;
			
	        while (line != null) {
	        	elems = line.split(",");
	        	for (int i = 0; i < elems.length; i++)
	        		if (elems[i].equals("-"))
	        			p107.adj_list[line_cnt][i] = -1;
	        		else
	        			p107.adj_list[line_cnt][i] = Integer.parseInt(elems[i]);
	            line = br.readLine();
	            line_cnt++;
	        }
	        System.out.print("\n");
	    } catch (FileNotFoundException e) {
	    	System.out.println("File not found.");
		} finally {
			if (br != null)
				br.close();
		    }
	}
	
	public static void print() {
		for (int i = 0; i < p107.num_nodes; i++) {
			for (int j = 0; j < p107.num_nodes; j++)
				System.out.print(p107.adj_list[i][j] + " ");
			System.out.print("\n");
		}
		System.out.println();
	}
	public static int total_cost() {
		int cost = 0;
		for (int i = 0; i < p107.num_nodes; i++) 
			for (int j = 0; j < p107.num_nodes; j++)
				if (adj_list[i][j] != -1)
					cost += adj_list[i][j];
		return cost / 2;
	}
	/*
	 * Create a minimum spanning tree of graph from network.txt. To do this a greedy approach is used where least 
	 * weight edge is added at each step to expand the network.
	 */
	public static void mst() {
		
		Comparator<Edge> comparator = new EdgeComparator();
		PriorityQueue<Edge> p = new PriorityQueue<Edge>(2000,comparator);
		int new_node;
		
		ArrayList<Edge> edgelist = new ArrayList<Edge>();
		Edge e;
		
		// set the first node
		int node_index = 0;
		
		// Initialize the visited array
		for (int i = 0; i < p107.num_nodes; i++)
			p107.visited[i] = false;
		p107.visited[node_index] = true;
		
		// Add the edges of node 0 to the priority qu 
		for (int i = 0; i < p107.num_nodes; i++) 
			if (p107.adj_list[0][i] != -1)		// only add edges that exist
				p.add(new Edge(0,i,p107.adj_list[0][i]));		
	
		while(p.size() > 0) {			
			new_node = -1;
			e = p.peek();
			
			if (!p107.visited[e.get_node1()]) 
				new_node = e.get_node1();
			else if (!p107.visited[e.get_node2()]) 
				new_node = e.get_node2();
			else {
				p.remove(e);	// the edge leads to visited node.  remove it from the Queue and continue
				continue;
			}
			
			edgelist.add(e);
			p107.visited[new_node] = true;
			for (int i = 0; i < p107.num_nodes; i++)	// add the new node edges to the list
				if (p107.adj_list[new_node][i] != -1)		// only add edges that exist
					p.add(new Edge(new_node,i,p107.adj_list[new_node][i]));
			
			p.remove(e);
			
		}
		
		// Finally create the new graph
		p107.create_new_graph(edgelist);
	}
	
	// Creates a new graph in `adj_list` from edges in edgelist
	private static void create_new_graph(ArrayList<Edge> edgelist) {
		Iterator<Edge> it = edgelist.iterator();
		Edge e;
		
		// Clear out the old matrix -- not great performance-wise
		for (int i = 0; i < p107.num_nodes; i++) 
			for (int j = 0; j < p107.num_nodes; j++)
				p107.adj_list[i][j] = -1;
				
		while(it.hasNext()) {
			e = it.next();
			p107.adj_list[e.get_node1()][e.get_node2()] = e.get_weight(); 
			p107.adj_list[e.get_node2()][e.get_node1()] = e.get_weight();
		}
	}
	
	public static void main(String[] args) {
		int cost_before, cost_after;
		try {			
			p107.readfile("network.txt");
			cost_before = p107.total_cost();
			p107.print();
			
			p107.mst();
			cost_after = p107.total_cost();
			p107.print();
			
			System.out.println("Cost before = " + cost_before);
			System.out.println("Cost after = " + cost_after);
			System.out.println("Savings = " + (cost_before - cost_after));
			
		} catch (Exception e) { return; }
		
	}
}
