import plotly.graph_objects as go
from plotly.subplots import make_subplots

CUSTOM_SCALE = [
    [0, 'blue'],
    [0.3, 'blue'],
    [0.3, 'yellow'],
    [0.35, 'yellow'],
    [0.35, 'forestgreen'],
    [0.47, 'forestgreen'],
    [0.47, '#4b911f'],
    [0.59, '#4b911f'],
    [0.59, 'green'],
    [0.7, 'green'],
    [0.7, 'gray'],
    [0.8, 'gray'],
    [0.8, 'white'],
    [1, 'white']
]


def visualize_map(map):
    fig = make_subplots(
        rows=1, cols=1,
        subplot_titles=(""),
    )

    fig.add_trace(
        go.Heatmap(z=map, colorscale=CUSTOM_SCALE, zmin=0, zmax=1),
        row=1, col=1
    )

    fig.update_layout(
        title_text="Карта высот",
        scene1=dict(
            xaxis_title="X",
            yaxis_title="Y",
            zaxis_title="Высота",
        ),
        width=1000,
        height=1000,
    )

    fig.show()

if __name__ == "__main__":
    with open('height.txt', 'r') as f:
        h = []
        for line in f:
            row = list(map(float, line.split()))
            h.append(row)

for i in range(len(h)):
    for j in range(len(h[i])):
        h[i][j]/=10

visualize_map(h)