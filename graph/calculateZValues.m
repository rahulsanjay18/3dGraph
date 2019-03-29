# funcStr: The function whose Z values are being calculated
# dx: the change in x that each block in the x direction represents
# dy: the change in y that each block in the y direction represents
# startPt: the point (in an array of x, y) that center block represents
# size: the side length (in blocks) of the plane

function[zValues] = calculate_z_values(funcStr, dx, dy, startPt, size)

zValues = zeros(size);
eqn = inline(funcStr);

startX = startPt(1);
startY = startPt(2);

for yOffset = 1:size
	for xOffset = 1:size
		xCoord = startX + dx * x;
		yCoord = startY + dy * y;
		zValues(size * yOffset + xOffset) = double(subs(eqn, {x, y}, {xCoord, yCoord});

endfunction