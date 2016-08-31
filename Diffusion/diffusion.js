var tree = [];
var walkers = []
var maxWlakers = 50;
var iterations = 1000;
var radius = 8;

function setup () {
	createCanvas(1200,600);
	colorMode(HSB);
	/*for (var i = 0; i < width; i+=r*2) {
		tree.push(new walker(i,height));
	};*/

	tree[0] = new walker(width/2,height/2);
	radius*=0.99;
	for (var i = 0; i <maxWlakers; i++) {
		walkers[i] = (new walker());
		radius*=0.99;
	}
	

}

function draw () {
	background(0);
	for (var i = 0; i < tree.length; i++) {
		tree[i].show();
	}
	for (var i = 0; i < walkers.length; i++) {
		walkers[i].show();
	}
	for(var n = 0; n < iterations; n++){
		for (var i = 0; i < walkers.length; i++) {
			walkers[i].walk();
			if(walkers[i].checkstuck(tree))
			{
				tree.push(walkers[i]);
				walkers.splice(i,1);
			}
		}
	}
	var r = walkers[walkers.length-1].r;
	while(walkers.length < maxWlakers)
	{
		radius*=0.99;
		if(radius > 1){
			walkers.push(new walker(r*0.99));
		}
	}
}

