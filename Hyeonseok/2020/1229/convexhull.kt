fun main(args: Array<String>) {
	if (args.size < 1) {
		println("usage: java -jre convexhull.jre [number of dots]")
		return
	}
	val numDots: Int = args[0].toInt()
	println(numDots)
} 
