/**
 * Classes des statistiques
 */

function Statistic (containerId){
	this.containerId = containerId;
	this.companies = [];
	this.schools = [];
}

Statistic.prototype.add = function(data) {
	var that = this;
	data.companies.forEach(function(company){
		var id = company.id;
		var statics = [
			data.month,
			company.availableInternships,
			company.hiredStudents,
			company.laureats.length
		];
		if( ! that.companies[id] )
			that.companies[id] = {
				name: company.name,
				values: []
			};
		if( that.companies[id].values.length > 11 )
			that.companies[id].values.splice(0,1);
		that.companies[id].values.push(statics);
	});

	data.schools.forEach(function(school){
		var id = school.id;
		var p = 0;
		if(school.laureats.length > 0)
			p = Math.floor(school.workingLaureats / school.laureats.length * 100);
		var statics = [
			data.month,
			Math.floor(school.studentsHavingInternship / school.studentsShouldHaveInternship * 100),
			p
		];
		console.log(statics);

		if( ! that.schools[id] )
			that.schools[id] = {
				name: school.name,
				values: []
			};
		if( that.schools[id].values.length > 11 )
			that.schools[id].values.splice(0,1);
		that.schools[id].values.push(statics);
	});
}

Statistic.prototype.show = function() {
	var text = '';
	text += '<div class="col-md-6"><h2> Les entreprises : </h2>';
	this.companies.forEach(function(company){
		text += '<h3>' + company.name + '</h3>';
		text += '<table style="display:none" class="highchart" data-graph-container-before="1" data-graph-type="line">'
            + '<thead><tr><th>Mois</th>'
            + '<th>Offres de stages disponibles</th>'
            + '<th>Nombre des stagiaires</th>'
            + '<th>Lauréats recrutés</th>'
            + '</tr></thead><tbody>';
		company.values.forEach(function(value){
			text += '<tr>'
				+ '<td>' + value[0] + '</td>'
				+ '<td>' + value[1] + '</td>'
				+ '<td>' + value[2] + '</td>'
				+ '<td>' + value[3] + '</td>'
				+ '</tr>';
		});
		text += '</tbody></table>';
	});
	text += '</div>';
	text += '<div class="col-md-6"><h2> Les écoles : </h2>';
	this.schools.forEach(function(school){
		text += '<h3>' + school.name + '</h3>';
		text += '<table style="display:none" class="highchart" data-graph-container-before="1" data-graph-type="line">'
            + '<thead><tr><th>Mois</th>'
            + '<th>Etudiants ayant un stage (%) </th>'
            + '<th>Taux d\'embauche des lauréats</th>'
            + '</tr></thead><tbody>';
		school.values.forEach(function(value){
			text += '<tr>'
				+ '<td>' + value[0] + '</td>'
				+ '<td>' + value[1] + '</td>'
				+ '<td>' + value[2] + '</td>'
				+ '</tr>';
		});
		text += '</tbody></table>';
	});
	text += '</div>';
	$('#' + this.containerId).html(text);
	$('table.highchart').highchartTable();
}