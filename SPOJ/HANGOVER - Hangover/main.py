while True:
	x = float(input())
	if x == 0.00:
		break
	y = 0
	cards = 0
	denom = 2
	while y <= x:
		y += 1.0 / denom
		cards += 1
		denom += 1
	print(cards, "card(s)")
