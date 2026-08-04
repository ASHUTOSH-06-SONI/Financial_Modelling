import json
import matplotlib.pyplot as plt


def draw_tree(tree, title):
    plt.figure(figsize=(10, 6))

    levels = len(tree)

    for i, level in enumerate(tree):
        y = levels - i

        for j, value in enumerate(level):
            x = j - i / 2

            plt.scatter(x, y, s=250)
            plt.text(
                x,
                y + 0.08,
                f"{value:.2f}",
                ha="center",
                fontsize=9
            )

            if i < levels - 1:
                plt.plot(
                    [x, j - (i + 1) / 2],
                    [y, y - 1],
                    "k-",
                    linewidth=1
                )

                plt.plot(
                    [x, j + 1 - (i + 1) / 2],
                    [y, y - 1],
                    "k-",
                    linewidth=1
                )

    plt.title(title)
    plt.axis("off")
    plt.tight_layout()
    plt.show()


with open("stock_tree.json") as f:
    stock_tree = json.load(f)

with open("option_tree.json") as f:
    option_tree = json.load(f)

draw_tree(stock_tree, "Stock Price Tree")
draw_tree(option_tree, "Option Value Tree")