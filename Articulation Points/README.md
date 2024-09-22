<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Articulation Points Finder in a Graph</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 20px;
        }
        h1, h2, h3 {
            color: #333;
        }
        code {
            background-color: #f4f4f4;
            padding: 2px 4px;
            border-radius: 3px;
        }
        ul {
            margin: 10px 0;
            padding-left: 20px;
        }
    </style>
</head>
<body>

<h1>Articulation Points Finder in a Graph</h1>

<p>This program finds the <strong>articulation points</strong> in an undirected graph. An articulation point is a vertex in a graph that, when removed, increases the number of connected components in the graph. In other words, it is a critical point that disconnects parts of the graph when removed.</p>

<h2>Algorithm</h2>

<p>The program implements <strong>Tarjan's Algorithm</strong> using <strong>Depth First Search (DFS)</strong> to find articulation points.</p>

<h3>Key Concepts:</h3>
<ul>
    <li><strong>Discovery Time (<code>st[]</code>)</strong>: The time when a node is first visited.</li>
    <li><strong>Low Value (<code>low[]</code>)</strong>: The smallest discovery time reachable from a node, considering back edges.</li>
    <li><strong>Articulation Point</strong>: A node <code>u</code> is an articulation point if:
        <ul>
            <li><code>u</code> is the root of the DFS tree and has <strong>two or more children</strong>.</li>
            <li><code>u</code> has a child <code>v</code> such that <strong>no vertex in the subtree rooted at <code>v</code> can connect to an ancestor of <code>u</code></strong>.</li>
        </ul>
    </li>
</ul>

<h3>Time Complexity:</h3>
<p>The algorithm runs in <strong>O(V + E)</strong> where <code>V</code> is the number of vertices and <code>E</code> is the number of edges.</p>

</body>
</html>


![Graph of Articulation Points](https://i.sstatic.net/5Uc3C.png)
