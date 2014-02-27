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
var statistics;

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
        var percentage = 0;
        if(data.studentsShouldHaveInternship > 0)
            percentage = data.studentsHavingInternship / data.studentsShouldHaveInternship;
        $('#studentsPercent').html( Math.floor(percentage * 100) + '%');
        
        percentage = 0;
        if(data.laureats.length > 0)
            percentage = data.workingLaureats / data.laureats.length;
        $('#laureatsPercent').html(Math.floor(percentage * 100) + '%');
        
        $('#simulation #month').html(data.month);

        statistics.add(data);
        statistics.show();
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
        case 'newSimulation':
            var request = {
                action: 'new'
            }
            $.get('api.php?request=' + JSON.stringify(request), function(response) {
                if(response == 'done'){
                    showPage('simulation');
                }else{
                    showMsg('danger','Error: Check the server output !');
                }
            });
            return;
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
    statistics = new Statistic('statistics');
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
