import java.util.Random

class Dot {
	var x: Int
	var y: Int
	init {
		x = 0
		y = 0
	}

	fun equals(other: Dot) : Boolean {
		return (this.x == other.x && this.y == other.y)
	}
}


class Line (var start: Dot, var end: Dot){
}


fun main(args: Array<String>) {
	if (args.size < 1) {
		println("usage: java -jre convexhull.jre [number of dots]")
		return
	}
	val numDots: Int = args[0].toInt()

	// Create n random dots, with x coordinate sorted
	var dotArray: Array<Dot> = CreateDots(numDots)
	// print all dots
	println(numDots.toString() + " dots created:")
	for (i in 0..numDots-1) {
		println("[" + dotArray[i].x + ", " + dotArray[i].y + "]")
	}
	println()

	// Find convex hull among the dots
	val lineList = convexhull(dotArray)
	println(lineList.size.toString() + " lines created:")
	for (line in lineList) {
		println("[" + line.start.x + ", " + line.start.y + "], [" + line.end.x + ", " + line.end.y + "]")
	}
}

// create Array of Dot, with x coordinate sorted with ascending order
fun CreateDots(num: Int) : Array<Dot> {
	var dots : Array<Dot> = Array<Dot>(num, {Dot()});
	var xArray = (0..num*4).shuffled().take(num).toTypedArray()
	xArray.sort()
	val yArray = (0..num*4).shuffled().take(num).toTypedArray()
	for (i in 0..num-1) {
		dots[i].x = xArray[i]
		dots[i].y = yArray[i]
	}
	return dots
}

/*
* 
*
*/
fun convexhull(dots: Array<Dot>): MutableList<Line> {
	val dotsPair = separatePoints(dots, dots[0], dots[dots.size-1])
	val lineList: MutableList<Line> = mutableListOf()

	lineList.addAll(upperhull(dotsPair.first, dots[0], dots[dots.size-1]))
	lineList.addAll(upperhull(dotsPair.second, dots[dots.size-1], dots[0]))

	return lineList
}

fun separatePoints(dots: Array<Dot>, start: Dot, end: Dot) : Pair<MutableList<Dot>, MutableList<Dot>>{
	var upper: MutableList<Dot> = mutableListOf()
	var lower: MutableList<Dot> = mutableListOf()

	for (dot in dots) {
		if (start.equals(dot) || end.equals(dot)) continue
		if (relPosition(start, end, dot) > 0) upper.add(dot)
		else lower.add(dot)
	}

	return Pair(upper, lower)
}

fun relPosition(start: Dot, end: Dot, point: Dot): Int {
	var a = start.y - end.y
	var b = end.x - start.x
	var c = start.x * end.y - start.y * end.x
	return a * point.x + b * point.y + c
}

fun getDistance(start: Dot, end: Dot, point:Dot): Int {
	return Math.abs(relPosition(start, end, point))
}

fun upperhull(dots: MutableList<Dot>, start: Dot, end: Dot) : MutableList<Line> {
		var lineList: MutableList<Line> = mutableListOf()
		if (dots.isEmpty()) {
			lineList.add(Line(start, end))
			return lineList
		}
		
		var maxlen: Int = Int.MIN_VALUE
		var maxpoint: Dot? = null
		for (dot in dots) {
			val dist = getDistance(start, end, dot)
			if (dist > maxlen) {
				maxlen = dist
				maxpoint = dot
			}
		}

		var dotsPair = separatePoints(dots.toTypedArray(), start, maxpoint!!)
		lineList.addAll(upperhull(dotsPair.first, start, maxpoint))
		dotsPair = separatePoints(dots.toTypedArray(), maxpoint, end)
		lineList.addAll(upperhull(dotsPair.first, maxpoint, end))

		return lineList
}
