import java.util.Random

class Dot {
	var x: Int
	var y: Int
	init {
		x = 0
		y = 0
	}
}

fun main(args: Array<String>) {
	if (args.size < 1) {
		println("usage: java -jre convexhull.jre [number of dots]")
		return
	}
	val numDots: Int = args[0].toInt()

	var dotArray: Array<Dot> = CreateDots(numDots)
	println(numDots.toString() + " dots created:")
	for (i in 0..numDots-1) {
		println("[" + dotArray[i].x + ", " + dotArray[i].y + "]")
	}


}

fun CreateDots(num: Int) : Array<Dot> {
	var dots : Array<Dot> = Array<Dot>(num, {Dot()});
	val xList = (0..num*4).shuffled().take(num)
	val yList = (0..num*4).shuffled().take(num)
	for (i in 0..num-1) {
		dots[i].x = xList[i]
		dots[i].y = yList[i]
	}
	return dots
}
