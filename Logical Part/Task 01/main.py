""" The vertices that have been visited are true, and the one's not visited are false
    0 is initially true as it is the starting point,
    so it has already been visited at least once at the beginning """

""" For example 1
    vertices = {
    0: True,
    1: False,
    2: False
}"""


""" For example 2
    vertices = {
    0: True,
    1: False,
    2: False,
    3: False,
    4: False,
    5: False
}"""


vertices = {
    0: True,
    1: False,
    2: False,
    3: False,
    4: False,
    5: False,
    6: False
}

# For example 1
# edges = [[0, 1], [1, 2], [2, 0]]
# For example 2
# edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]]

edges = [[0, 1], [1, 2], [2, 0], [3, 4], [4, 5], [5, 6], [6, 3]]


for edge in edges:
    """ Only if both 0 and 1 exist in the same array inside the edges list,
    then change the value of 1 to true, since 0 is true
    because they being in the same array/group means they have an edge in between them
    thus, they can both be visited """
    if edge[0] in vertices and edge[1] in vertices:

        if vertices[edge[0]] is True:
            vertices[edge[1]] = True

# showing the individual visited status of the vertices
print(vertices)

# Check if all values are True
all_values_true = all(vertices.values())

# Printing the final result
if all_values_true is True:
    print("true")
else:
    print("false")
