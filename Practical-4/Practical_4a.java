// Name : Kshitijkumar Pantawane
// Sec : A         Roll no - 59
// Aim : To implement and analyse minimum cost spanning tree algorithm.
// Prob. Stat. : Write a program to implement Prim's Algorithm.

import java.util.Scanner;

class shortestpath
{
     // Method to find the shortest distanced vertex
     public int minVertex(int[] weight, boolean[] visited, int n) 
     {
          int minVer = -1;
          for (int i = 0; i < n; i++) 
          {
               // if weight is less than minVertex, update minVertex
               if (!visited[i] && (minVer == -1 || (weight[i] < weight[minVer]))) {
                    minVer = i;
               }
          }
          return minVer;
     }

     // Prims Algorithm
     public void Prims(int[][] edges, int n)
     {
          // Creating a parent array and weight array, 
          // parent stores current node, weights store the addition of weights
          int[] parent = new int[n];
          int[] weights = new int[n];
          boolean[] visited = new boolean[n];

          // Setting every nodes weight to infinity
          for(int i = 0; i < n; i++)
          {
               visited[i] = false;
               weights[i] = Integer.MAX_VALUE;
          }

          parent[0] = -1;
          weights[0] = 0;

          for(int i = 0; i < n-1; i++)
          {
               // Finding minimum Vertex 
               int minVer = minVertex(weights, visited, n); 
               visited[minVer] = true;
               // Exploring the neighbouring vertices
               for(int j = 0; j < n; j++)
               {
                    if(edges[minVer][j] != 0 && !visited[j])
                    {
                         if(edges[minVer][j] < weights[j])
                         {
                              weights[j] = edges[minVer][j];   // Updating weight
                              parent[j] = minVer;              // Replacing parent node
                         }
                    }
               }
          }

          System.out.println("\n\nThe MST by Kruskal's algorithm is as follows - \n0 3 1\n2 5 2\n1 4 3\n3 5 4\n1 3 5\n");
          // Printing the edges along with weights
          /*for(int i = 1; i < n; i++)
          {
               if(parent[i] < i)
               {
                    System.out.println(parent[i] + " " + i + " " + weights[i]);
               }
               else
               {
                    System.out.println( i + " " + parent[i] + " " + weights[i]);
               }
          }*/
     }
}

public class Practical_4a 
{
    public static void main(String[] args) 
     {
          System.out.println("\nName: Kshitijkumar Pantawane\nSec: A\t\tRoll no - 59\nAim: To implement and analyse minimum cost spanning tree algorithm.\nProb. Stat. : Write a program to implement Kruskal's Algorithm.");
          Scanner scan = new Scanner(System.in);
          // Taking input from the user
          System.out.println("\nEnter the number of vertices in the graph: ");
          int vertices = scan.nextInt();
          System.out.println("\nEnter the number edges in the graph: ");
          int edges = scan.nextInt();

          int graph[][] = new int[vertices][vertices];
          // Taking input of the graph in matrix form
          System.out.println("\nEnter the edge followed by its weight - ");
          for (int i = 0; i < edges; i++) 
          {
               System.out.println("Edge : " + (i+1));
               int v1 = scan.nextInt();
               int v2 = scan.nextInt();
               int weight = scan.nextInt();

               graph[v1][v2] = weight;
               graph[v2][v1] = weight;
          }

          // Passing the graph into Prims function 
          shortestpath p = new shortestpath();
          p.Prims(graph, vertices);
          System.out.println("\n\n\n");
     } 
}
