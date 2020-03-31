package improve;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;

public class BFSandDFS {
	
	private HashMap<Integer,Node> map = new HashMap<Integer,Node>();
	
	public static class Node{
		private int id;
		LinkedList<Node> adjacents = new LinkedList<BFSandDFS.Node>();
		
		public Node(int id) {
			this.id = id;
		}
	}
	
	public Node getNode(int id) {
		return map.get(id);
	} 
	
	public void addEdge(int source, int destination) {
		Node s = getNode(source);
		Node d = getNode(destination);
		s.adjacents.add(d);
	}

	
	public boolean makeDFS(int source, int destination) {
		HashSet<Integer> visited = new HashSet<Integer>();
		Node s = getNode(source);
		Node d = getNode(destination);
		
		if (DFS(s,d,visited))
			return true;
		
		return false;
	}
	
	public boolean DFS(Node source, Node destination, HashSet<Integer> visited) {
		if (source == destination)
			return true;
		
		if (visited.contains(source.id))
			return false;
		
		visited.add(source.id);
				
		for (Node t : source.adjacents) {
			return DFS(t,destination,visited);
		}
		
		return false;
	}
	
	
	public boolean makeBFS(int source, int destination) {
		LinkedList<Node> queue = new LinkedList<Node>();
		HashSet<Integer> visited = new HashSet<Integer>();

		Node s = getNode(source);
		Node d = getNode(destination);
		
		if (BFS(s,d,queue,visited))
			return true;
		
		return false;
	}
	
	public boolean BFS(Node source, Node destination, LinkedList<Node> queue, HashSet<Integer> visited) {
		queue.add(source);

		while(!queue.isEmpty()) {
			Node s = queue.remove();

			if (s == destination)
				return true;
			
			if (visited.contains(s.id))
				continue;
			
			for (Node t : s.adjacents)
				queue.add(t);
			
			visited.add(s.id);
		}
		return false;
	}
}
