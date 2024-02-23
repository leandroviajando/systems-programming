
/**
 * @file GraphSearchExercises.cpp
 * University of Illinois CS 400, MOOC 3, Week 3: Graph Search
 * Spring 2019
 *                        STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
 **/

#include "GraphSearchCommon.h"

// This function should return the number of unique edges in the GridGraph.
// Remember that GridGraph doesn't explicitly store edge objects, but
// instead it stores point adjacency information. Since the graph edges are
// undirected, for any two vertices A and B, the edges (A,B) and (B,A) are the
// same edge. This means if we add up the sizes of the GridGraph::NeighborSet
// sets mapped in adjacencyMap, we'll be double-counting the number of edges.
// We can still use that to get the answer, or instead, the implementation of
// GridGraph::printDetails in GridGraph.h shows another method, by constructing
// a set of the unique edges only.
int GridGraph::countEdges() const {
  int numEdges = 0;

  if (adjacencyMap.empty())
    return numEdges;

  for (auto vIter = adjacencyMap.begin(); vIter != adjacencyMap.end(); vIter++) {
    auto edgePairs = vIter->second;

    for (auto eIter = edgePairs.begin(); eIter != edgePairs.end(); eIter++)
      numEdges++;
  }

  // edges counted twice iterating over all edgePairs
  return numEdges / 2;
}

// This function takes a point (an IntPair) as input, and it should remove
// all references to the point from the data structure. That means it should
// remove the point's key from the adjacency map, and it should also remove
// other points' references to it in the map, if those other points had been
// connected to it by implicit edges. It shouldn't change anything else about
// the graph.
void GridGraph::removePoint(const IntPair& p1) {
  if (!hasPoint(p1)) return;

  const GridGraph::NeighborSet originalNeighbors = adjacencyMap.at(p1);

  for (auto nIter = originalNeighbors.begin(); nIter != originalNeighbors.end(); nIter++)
    removeEdge(*nIter, p1);

  // Finally, for the one point we are removing, erase the point key itself
  // from adjacencyMap directly. (There is no other GridGraph helper function
  // for this, because that's what we're implementing right now! We need to
  // use adjacencyMap's own erase function directly to erase the key.)

  adjacencyMap.erase(p1);
}

// We use BFS (breadth-first search) to find the shortest path from start to
// goal, if there exists any path at all. Then we return the path as a list of
// points. If there is no path, or if we take too many steps without success,
// then we return an empty list.
std::list<IntPair> graphBFS(const IntPair& start, const IntPair& goal, const GridGraph& graph) {
  // We'll hard-code a maximum distance for any shortest path through the graph
  // that we will consider before giving up.
  constexpr int maxDist = 100;

  // Queue of graph vertices to explore next. This is an ordinary FIFO queue
  // (first in, first out), not a priority queue. When we say "explore" a vertex
  // in this assignment, we mean to dequeue it and loop over its adjacent vertices.
  std::queue<IntPair> exploreQ;

  // Map that associates a given point with its predecessor (the neighbor that discovered it first)
  // This will allow us to reconstruct the path once the goal is found.
  std::unordered_map<IntPair, IntPair> pred;
  // Example usage: "pred[B] = A" records A as the predecessor of B, meaning that A discovered B.

  // Map that associates a given point with its shortest-path distance from the starting point.
  // This lets us see if we've taken too many steps (see the above comment about maxDist).
  // The simplest implementations of BFS don't need a distance record like this,
  // but it can be useful information, and other graph search algorithms like Dijkstra's
  // algorithm do need to use such a record.
  // Remember: with std::unordered_map, the first time we look up a key with [], it will be
  //  inserted if it doesn't exist yet. Also, its initial int value will be 0 by default.
  std::unordered_map<IntPair, int> dist;

  // Set of graph vertices that have already been visited. (In this case, by
  // "visited", we mean the same thing as a vertex that has been "discovered"
  // or "reached" -- that is, it has been added to the exploration queue,
  // but not necessarily removed from the queue yet.) This lets us avoid
  // re-enqueueing graph vertices that we've already enqueued for exploration.
  // (For further optimization, we could just use pred to query whether a vertex
  //  has been discovered previously, but using this separate set is more explicit
  //  for the sake of explaining the concepts here.)
  std::unordered_set<IntPair> visitedSet;

  // This "dequeued" set isn't strictly part of the traditional BFS algorithm,
  // but we'll use it for error checking, to make sure that no vertex is ever
  // removed from the queue more than once. This is technically redundant,
  // because we also have the visitedSet to use.
  std::unordered_set<IntPair> dequeuedSet;

  // Check for an erroneous problem specification, in case we made a simple mistake.
  // (Note that for puzzleBFS, the PuzzleState constructors already check for obviously
  //  invalid configurations, so you don't need to do this.)
  if (!graph.hasPoint(start)) throw std::runtime_error("Starting point doesn't exist in graph");
  if (!graph.hasPoint(goal)) throw std::runtime_error("Goal point doesn't exist in graph");

  // Initialize the predecessor of the start vertex as itself. You might
  // wonder why we don't just leave pred[start] non-existent, because that's
  // another way we could check the beginning of the path as we retrace the
  // path steps later. It's because initializing pred[start] sanely here
  // lets us make sure that the start vertex can be treated like any other
  // vertex, which can help prevent subtle bugs in our implementation.
  pred[start] = start;

  // Initialize that the shortest-path distance from start to itself is 0.
  // (This isn't strictly necessary because of how std::unordered_map works.
  //  It would default-initialize dist[start] to 0 later when we referred to it.
  //  However, this is more clear.)
  dist[start] = 0;

  // We begin at the start point, so mark it discovered by putting a copy of it
  // in the visited set.
  visitedSet.insert(start);

  // We will begin searching from the start point. Push a copy of it into the exploration queue.
  exploreQ.push(start);

  // Below, a "flag" just means a variable for controlling a loop condition.

  // foundGoal is a flag for controlling the loop below. It's initialized as false,
  // unless we start at the goal, in which case it's initialized as true.
  bool foundGoal = (start == goal);

  // tooManySteps is a flag that will help us break out of the loop if we detect
  // that we've already taken too many steps and probably need to give up searching.
  bool tooManySteps = false;

  // The main search loop --------------------------------------------------

  // While the exploration queue isn't empty yet, there are still discovered points to explore.
  // Also, we would want to stop looping if foundGoal or tooManySteps became true.
  while (!exploreQ.empty() && !foundGoal && !tooManySteps) {
    // Get a copy of the next point to explore from the front of the queue.
    // This becomes the "current" point.
    auto curPoint = exploreQ.front();
    // Pop to remove the point from the queue.
    exploreQ.pop();

    // Error prevention: Check whether this vertex has ever been dequeued in the past.
    // (Checking for vertices that are dequeued more than once isn't strictly considered
    //  part of the BFS algorithm, because in the loop below, you are meant to check for
    //  previously-visited vertices while considering the adjacent vertices. We do this
    //  here for additional sanity checking, in case you have made any mistakes that would
    //  cause an infinite loop.)
    bool curPointWasPreviouslyDequeued = dequeuedSet.count(curPoint);
    if (curPointWasPreviouslyDequeued) {
      std::cout << "graphBFS ERROR: Dequeued a vertex that had already been dequeued before." << std::endl
                << " If you're using visitedSet correctly, then no vertex should ever be added" << std::endl
                << " to the explore qeueue more than once. [Returning an empty path now.]" << std::endl
                << std::endl;
      return std::list<IntPair>();
    } else {
      // We'll record that this vertex has been dequeued by adding a copy of it to the set.
      dequeuedSet.insert(curPoint);
    }

    // We'll need to loop over the neighbors that are the points adjacent to curPoint.
    // Get a copy of the set of neighbors we're going to loop over.
    GridGraph::NeighborSet neighbors = graph.adjacencyMap.at(curPoint);

    for (auto neighbor : neighbors) {
      // Check whether the neighbor has already been visited.
      bool neighborWasAlreadyVisited = visitedSet.count(neighbor) == 1;

      // If this adjacent vertex has NOT been visited before, we will visit it now.
      // If it HAS been visited before, we do nothing and continue to loop.
      // This way, we avoid enqueueing the same vertex more than once.
      if (!neighborWasAlreadyVisited) {
        // Record that the curPoint is the predecessor of the neighbor point,
        // since curPoint has just led to the discovery of this neighbor for
        // the first time.
        pred[neighbor] = curPoint;

        // Add neighbor to the visited set.
        visitedSet.insert(neighbor);

        // Push neighbor into the exploration queue.
        exploreQ.push(neighbor);

        // Check if we've taken too many steps so far.
        // The shortest-path distance to this neighbor is the shortest-path distance
        // to curPoint, plus one. (We know that dist[curPoint] has already been
        // initialized because we previously reached curPoint from another point,
        // and it was assigned a value at that time, or else curPoint is the
        // start point that we explicitly initialized at the beginning.)
        dist[neighbor] = dist[curPoint] + 1;
        if (dist[neighbor] > maxDist) {
          // If the shortest path to this neighbor is a further distance than we
          // are allowed to explore, then flag that we have taken too many steps,
          // and break out of the nearest loop (the for loop). After that, the
          // tooManySteps flag will cause the while loop to stop also.

          // You may ask: How do we know to give up here? What if there are other
          // paths we can still explore through the exploration queue, that are shorter?
          // We know there are not, because in BFS, we identify all the reachable nodes
          // of distance 1, and only after that, all the reachable nodes with distance 2, etc.
          // So right now, if we need "too many" steps to reach this discovered neighbor,
          // we'll also need "too many" steps to reach any other node later.
          // This is the same reasoning that allows us to conclude we have found the
          // shortest path, when we finally do reach the goal.
          tooManySteps = true;
          break;
        }

        // If we haven't taken too many steps yet, and if the neighbor is the goal,
        // then flag that we have found the goal, and break out of the "for" loop.
        // The foundGoal flag will then cause the "while" loop to stop, also.
        if (neighbor == goal) {
          foundGoal = true;
          break;
        }

      }  // end of handling the just-discovered neighbor

    }  // end of for loop
  }    // end of while loop

  // Now that the looping is over, we can evaluate what the results were.

  // If we took too many steps, we issue an error message and return an empty list.
  if (tooManySteps) {
    std::cout << "graphBFS warning: Could not reach goal within the maximum allowed steps.\n (This may be expected if no path exists.)" << std::endl
              << std::endl;
    return std::list<IntPair>();
  }

  // If we never found the goal even after exploring the entire reachable graph,
  // then issue an error message and return an empty list.
  if (!foundGoal) {
    std::cout << "graphBFS warning: Could not reach goal. (This may be expected\n if no path exists.)" << std::endl
              << std::endl;
    return std::list<IntPair>();
  }

  // Otherwise, we must have found a path from start to goal, and it is as short as possible.
  // (If there exist multiple shortest paths from start to goal that all have the same length,
  //  we have found ONE of these shortest paths.)

  // Make a new, empty list of IntPairs in the stack memory at function scope.
  // This will represent the path from start to goal. We'll return it by value at the end.
  std::list<IntPair> path;
  // We will walk back from the goal to the start using the predecessor records.
  auto cur = goal;
  // Push the currently-walked vertex onto the FRONT of the list, so that as we walk back
  // from goal to start, the created list will be in order from start to goal.
  path.push_front(cur);
  // Make sure that there is a predecessor recorded for cur, and then while the
  // predecessor of cur is not recorded as itself, keep looping. (The start vertex
  // recorded itself as its predecessor, so then we know to stop.)
  while (pred.count(cur) && pred[cur] != cur) {
    // It's good to note here that the "&&" operator has "short circuiting" behavior,
    // which means that in "A && B", if A is false, then B is never evaluated at all.
    // The whole expression is immediately determined to be false. This way, the
    // "A" part can be used as a safeguard on the "B" part, if "B" could cause problems.

    // Push a copy of the predecessor onto the front of the list, as we reconstruct
    // the path back to the start.
    path.push_front(pred[cur]);
    // Step backwards to the predecessor so we can continue looping.
    cur = pred[cur];
  }

  // Return the reconstructed path from start to goal.
  return path;
}
// Given start and goal sates as PuzzleState objects, we perform BFS in the
// imaginary graph model implied by the start state, where the rest of the
// reachable vertices (states) and the edges leading to them (puzzle moves)
// can be figure out based on the tile sliding rules of the puzzle.
// If there exists any path from start to goal, then the puzzle can be solved,
// and we return the shortest path (which represents the solution steps).
// If there is no path to the goal, or if we take too many steps without
// success, then the puzzle cannot be solved, and we return an empty list.
std::list<PuzzleState> puzzleBFS(const PuzzleState& start, const PuzzleState& goal) {
  // For the 8-tile puzzle, it actually never takes as many as 35 steps to
  // solve any given puzzle that has a solution. This has been proven in
  // the past by brute force. So we can implement a failsafe measure:
  // if we've explored all possible 35-move sequences and there's still no
  // solution found, then the puzzle cannot be solved. Then we can give up
  // and return early. (There do exist unreachable states for the 8 puzzle
  // because the tiles can only be rearranged by following the sliding rule.
  // So it's possible to specify some "goal" states that cannot be reached by
  // sliding the tiles.)
  constexpr int maxDist = 35;

  std::queue<PuzzleState> exploreQ;
  std::unordered_map<PuzzleState, PuzzleState> pred;
  std::unordered_map<PuzzleState, int> dist;
  std::unordered_set<PuzzleState> visitedSet;
  std::unordered_set<PuzzleState> dequeuedSet;

  pred[start] = start;
  dist[start] = 0;
  visitedSet.insert(start);
  exploreQ.push(start);

  bool foundGoal = (start == goal);
  bool tooManySteps = false;

  while (!exploreQ.empty() && !foundGoal && !tooManySteps) {
    auto curState = exploreQ.front();
    exploreQ.pop();

    bool curPointWasPreviouslyDequeued = dequeuedSet.count(curState);
    if (curPointWasPreviouslyDequeued) {
      std::cout << "puzzleBFS ERROR: Dequeued a vertex that had already been dequeued before." << std::endl
                << " If you're using visitedSet correctly, then no vertex should ever be added" << std::endl
                << " to the explore qeueue more than once. [Returning an empty path now.]" << std::endl
                << std::endl;
      return std::list<PuzzleState>();
    } else {
      dequeuedSet.insert(curState);
    }

    auto neighbors = curState.getAdjacentStates();

    for (auto neighbor : neighbors) {
      bool neighborWasAlreadyVisited = visitedSet.count(neighbor) == 1;

      if (!neighborWasAlreadyVisited) {
        // Record that the curState is the predecessor of the neighbor point,
        // since curState has just led to the discovery of this neighbor for
        // the first time.
        pred[neighbor] = curState;

        // Add neighbor to the visited set.
        visitedSet.insert(neighbor);

        // Push neighbor into the exploration queue.
        exploreQ.push(neighbor);

        dist[neighbor] = dist[curState] + 1;
        if (dist[neighbor] > maxDist) {
          tooManySteps = true;
          break;
        }

        if (neighbor == goal) {
          foundGoal = true;
          break;
        }
      }
    }
  }
  if (tooManySteps) {
    std::cout << "puzzleBFS warning: Could not reach goal within the maximum allowed steps.\n (This may be expected if no path exists.)" << std::endl
              << std::endl;
    return std::list<PuzzleState>();
  }

  if (!foundGoal) {
    std::cout << "puzzleBFS warning: Could not reach goal. (This may be expected\n if no path exists.)" << std::endl
              << std::endl;
    return std::list<PuzzleState>();
  }

  std::list<PuzzleState> path;
  auto cur = goal;
  path.push_front(cur);
  while (pred.count(cur) && pred[cur] != cur) {
    path.push_front(pred[cur]);
    cur = pred[cur];
  }

  return path;
}
