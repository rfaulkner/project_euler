package helper;

import helper.Edge;
import java.util.Comparator;

public class EdgeComparator implements Comparator<Edge> {
 @Override
 public int compare(Edge x, Edge y)
 {
     // Assume neither Edge is null. 
	 if (x.get_weight() < y.get_weight()) { return -1; }
     if (x.get_weight() > y.get_weight()) { return 1; }
     return 0;
 }
}