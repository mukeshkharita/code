function walker(x,y) {
	if(arguments.length == 2)
	{
		this.pos = createVector(x,y);
		this.stuck = true;
	}
	else
	{
		this.pos = randomPoint();	
		this.stuck = false;	
	}
	this.r = radius;
	this.walk = function(){
		var vel = p5.Vector.random2D();
		this.pos.add(vel);
		this.pos.x = constrain(this.pos.x,0,width);
		this.pos.y = constrain(this.pos.y,0,height);
	}

	this.checkstuck = function(others)
	{
		for (var i = 0; i < others.length; i++) 
		{
			var d = distsq(this.pos,others[i].pos);
			if(d < 4*this.r*others[i].r)
			{
				this.stuck = true;
				return true;
				break;
			}
		}
		return false;
	}

	this.show = function()
	{
		noStroke();
		/*if(this.stuck)
		{
			fill(255,0,0,100);
		}
		else
			fill(255);*/
		var hu = map(this.r,0,8,0,360);
		fill(hu,255,255);
		ellipse(this.pos.x,this.pos.y,this.r*2,this.r*2);
	}
}

function distsq(a,b)
{
	var dx = a.x-b.x;
	var dy = a.y-b.y;
	return (dx*dx+dy*dy);
}

function randomPoint()
{
	var i = floor(random(4));
	if(i===0)
	{
		var x = random(width);
		return createVector(x,0);
	}
	else if(i===1)
	{
		var x = random(width);
		return createVector(x,height);
	}
	else if(i===2)
	{
		var y = random(height);
		return createVector(0,y);
	}
	else
	{
		var y = random(height);
		return createVector(width,y);
	}
}