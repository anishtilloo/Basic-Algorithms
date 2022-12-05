// Name : Kshitijkumar Pantawane
// Sec : A         Roll no - 59
// Aim : To implement and analyse minimum spanning tree algorithm.
// Prob. Stat. : Write a program to implement Kruskal's Algorithm.

import java.util.Scanner;
import java.beans.IndexedPropertyChangeEvent;
import java.util.Arrays;
import java.util.Comparator;

class Edge implements Comparable<Edge> 
{
     public int source;
     public int destination;
     public int weight;

     public Edge(int source, int destination, int weight) 
     {
          this.source = source;
          this.destination = destination;
          this.weight = weight;
     }

     public int compareTo(Edge edge) 
     {
          return this.weight - edge.weight;
     }
}

class shortestpath 
{
     int findParent(int v, int[] parent) 
     {
          if (parent[v] == v) 
          {
               return v;
          }
          return findParent(parent[v], parent);
     }

     // Method implementing Kruskal's Algorithm
     void kruskals(Edge[] graph, int vertices, int edges) 
     {
          // Sorting the inputs in ascending order based on edge weights
          Arrays.sort(graph);

          Edge[] output = new Edge[vertices - 1];
          Edge[] input = new Edge[vertices];
          int[] parent = new int[vertices];

          for (int i = 0; i < vertices; i++) 
          {
               parent[i] = i;
          }

          int count = 0;
          int i = 0;
          while (count != vertices - 1) 
          {
               Edge currentEdge = input[i];

               // Checking if current edge can be added in MST or not
               int sourceParent = findParent(currentEdge.source, parent);
               int destParent = findParent(currentEdge.destination, parent);

               if (sourceParent != destParent) 
               {
                    output[count] = currentEdge;
                    count++;
                    parent[sourceParent] = destParent;
               }
               i++;
          }

          for (i = 0; i < vertices - 1; i++) 
          {
               System.out.println(output[i].source + " " + output[i].destination + " " + output[i].weight);
          }
     }
}

public class Practical_4b 
{
     public static void main(String[] args) 
     {
          System.out.println("\nName: Kshitijkumar Pantawane\nSec: A\t\tRoll no - 59\nAim: To implement and analyse minimal spanning tree algorithm.\nProb. Stat. : Write a program to implement Kruskal's Algorithm.");
          Scanner scan = new Scanner(System.in);

          System.out.println("\nEnter the number of vertices in the graph: ");
          int vertices = scan.nextInt();
          System.out.println("\nEnter the number edges in the graph: ");
          int edges = scan.nextInt();

          Edge[] graph = new Edge[edges];

          System.out.println("\nEnter the edge followed by its weight - ");
          for (int i = 0; i < edges; i++) 
          {
               System.out.println("Edge : " + (i + 1));
               int s = scan.nextInt();
               int d = scan.nextInt();
               int w = scan.nextInt();

               graph[i].source = s;
               graph[i].destination = d;
               graph[i].weight = w;
          }

          shortestpath path = new shortestpath();
          path.kruskals(graph, vertices, edges);
          System.out.println("\n\n\n");
     }
}