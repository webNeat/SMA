/**
 * Draw class based on canvas
 */

function Draw (canvasId){
	// attributs:
	this.canvas = document.getElementById(canvasId);
	this.context = this.canvas.getContext('2d');
	this.data = null;
	this.params = {
		// Students
		studentWidth: 5,
		studentHeight: 5,
		studentColor: 'blue',
		// Schools
		schoolWidth: 35,
		schoolHeight: 35,
		schoolColor: 'green',
		// Companies
		companyWidth: 35,
		companyHeight: 35,
		companyColor: 'brown',
		// Font
		font: '14pt Calibri',
		// Animation
		StepDuration: 200
	};
	// Initialisation
	this.context.font = this.params.font;
}

Draw.prototype.clean = function() {
    this.canvas.width = this.canvas.width;
}

Draw.prototype.update = function(data) {
	this.data = data;
	this.drawStep(0);
};

Draw.prototype.drawStep = function(i){
	var that = this;
    if(i < 30){
	    this.clean();
		this.drawSchools();
		this.drawCompanies();
    	this.drawStudents(i);
        setTimeout(function(){
            that.drawStep(i + 1);
        }, 200);
    }
}

Draw.prototype.drawStudents = function(i){
	var that = this;
	this.context.beginPath();
	this.data.students.forEach(function(student){
	    if(i < student.positions.length)
		    that.context.rect( 
		    	student.positions[i].x, 
		    	student.positions[i].y, 
		    	that.params.studentWidth, 
		    	that.params.studentHeight
		    );
	});
	this.context.fillStyle = this.params.studentColor;
	this.context.fill();
	this.context.stroke();
}

Draw.prototype.drawSchools = function(){
	var that = this;
	this.context.beginPath();
	this.context.fillStyle = this.params.schoolColor;
	this.data.schools.forEach(function(school){
        that.context.rect( 
	    	school.position.x, 
	    	school.position.y, 
	    	that.params.schoolWidth, 
	    	that.params.schoolHeight
	    );
	    that.context.fillText(
	    	school.name, 
	    	school.position.x, 
	    	school.position.y + that.params.schoolHeight + 10
	    );
	});
	this.context.fill();
	this.context.stroke();
}

Draw.prototype.drawCompanies = function(){
	var that = this;
	this.context.beginPath();
	this.context.fillStyle = this.params.companyColor;
	this.data.companies.forEach(function(company){
        that.context.rect( 
	    	company.position.x, 
	    	company.position.y, 
	    	that.params.companyWidth, 
	    	that.params.companyHeight
	    );
	    that.context.fillText(
	    	company.name, 
	    	company.position.x, 
	    	company.position.y + that.params.companyHeight + 10
	    );
	});
	this.context.fill();
	this.context.stroke();
}