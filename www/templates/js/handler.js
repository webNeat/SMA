/**
TODO:
    Draw Carte and blit schools & Companies
    a loop to show students and Laureats movement (add a vector of positions describing the movement to Student and Laureat)
    Animate everybody at the same time !! (a simple loop !)
    Draw any new Company ( new flag to know if we should draw it or not)
    Hande Clicks on Schools and Companies to show more details !!
 */

var active;
var design;

function loadParams() {
    var request = {
        action: 'get_params'
    }
    $.get('api.php?request=' + JSON.stringify(request), function(response) {
        data = JSON.parse(response);
        var $inputs = $('#params form input');
        $.each(data, function(key, value) {
            $inputs.filter(function() {
                return key == this.name;
            }).val(value);
        });
    });
}

function loadMap(){
    var request = {
        action: 'get_world'
    };
    $.get('api.php?request=' + JSON.stringify(request), function(response) {
        var data = JSON.parse(response);
        design.update(data);
        $('#simulation #month').html(data.month);
        // var text = '';
        // data.schools.forEach(function(school){
        //     text += '<div class="col-xs-6 col-md-3"><div class="blue section">'
        //         + '<h3>' + school.name + '</h3><ul>';
        //         var levelId = 1;
        //         school.levels.forEach(function(level){
        //             text += '<li class="break">Niveau ' + levelId + '</li>'
        //                 + '<li>Nombre d\'étudiants : ' + level.students.length + '</li>'
        //                 + '<li>Etudiants ayant un stage : 0 </li>';
        //             levelId ++;
        //         });
        //         text += '<li class="break">laureats </li>'
        //             + '<li>En chaumage :' + school.laureats.length + '</li>'
        //             + '<li>En stage : 0 </li>'
        //             + '<li>En travail : 0 </li>';
        //         text += '</ul></div></div>';
        // });
        
        // data.companies.forEach(function(company){
        //     text += '<div class="col-xs-6 col-md-3"><div class="brown section">'
        //         + '<h3>' + company.name + '</h3><ul>'
        //         + '<li>Nombre total des employés : ' + company.employeesNumber + '</li>'
        //         + '<li>Nombre total des stages : ' + company.internships.length + '</li>'
        //         + '<li>Nombre total des lauriats : ' + company.laureats.length + '</li>'
        //         + '</ul></div></div>';
        // });
        // $('#simulation #map').html(text);
    });
}

function act(){
    var request = {
        action: 'act'
    }
    $.get('api.php?request=' + JSON.stringify(request), function(response) {
        if(response == 'done'){
            console.log('act done !');
            loadMap();
        }else{
            showMsg('danger','Error: Check the server output !');
        }
    });
}

function showPage(id) {
    switch (id) {
        case 'params':
            loadParams();
        break;
        case 'simulation':
            loadMap();
        break;
        case 'act':
            act();
            return;
        break;
    }
    $('#' + active).slideUp(100);
    $('#' + id).slideDown(500);
    var title = $('#' + id).attr('title');
    $('#header-title').html(title);
    active = id;
    $('#messages').html('');
}

function showMsg(type, text) {
    var html = '<div class="alert alert-' + type + ' alert-dismissable"><button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>' + text + '</div>';
    $('#messages').append(html);
}

function bindFormsEvent(){
    $('form').on("submit", function(event) {
        event.preventDefault();
        var array = $(this).serializeArray();
        var data = {};
        for (var i = 0; i < array.length; i++) {
            data[array[i].name] = array[i].value;
        }
        var request = {
            action: $(this).attr('name'),
            data: data
        };
        var target = $(this).attr('target');
        $.get('api.php?request=' + JSON.stringify(request), function(data) {
            if (data == 'done') {
                showPage(target);
                showMsg('success', 'Paramètres sauvegardés !');
            }else{
                showMsg('danger', 'Erreur !');
            }
        });
    });
}

function makeParamsForm(params){
    var txt = '';

    for(var item in params){
        txt += '<div class="form-group">'
            + '<label class="col-sm-2 control-label">' + item + '</label><div class="col-sm-10">'
            + '<input type="number" class="form-control" name="' + item + '">'
            + '</div></div></div>';
    }

    txt += '<div class="form-group"><div class="col-sm-offset-2 col-sm-10">'
        + '<button type="submit" class="btn btn-primary">Sauvegarder</button>'
        + '</div></div>';

    return txt;
}

$(document).ready(function() {
    // Initialisation
    $('.page').hide();
    active = 'acceuil';
    showPage('acceuil');
    design = new Draw('graph');
        // Création de formulaire des paramètres
        var request = {
            action: 'get_params'
        };
        $.get('api.php?request=' + JSON.stringify(request), function(data) {
            $("#params form").html(makeParamsForm($.parseJSON(data)));
        });

    // Transition d'une page à une autre
    $('.menu-item').click(function() {
        showPage($(this).attr('target'));
    });

    // Gestion des formulaires
    bindFormsEvent();
});
