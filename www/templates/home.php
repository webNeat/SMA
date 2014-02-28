<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="SMA Simulation Project at ISIMA ZZ2F2">
    <meta name="author" content="Ben hammou Amine et Zaini Nabil">
    <title>SMA</title>
    <link href="templates/css/bootstrap.min.css" rel="stylesheet">
    <link href="templates/css/style.css" rel="stylesheet">
    <!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
      <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>
    <div role="navigation" class="navbar navbar-default">
      <div class="container">
        <div class="navbar-header">
          <button data-target=".navbar-collapse" data-toggle="collapse" class="navbar-toggle" type="button">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a href="#" class="navbar-brand"> SMA : <span id="header-title"> Acceuil </span></a>
        </div>
      </div>
    </div>
    <div class="container">
      <div class="row">
        <div class="col-md-8 col-md-offset-2" id="messages">
          
        </div>
      </div>
    </div>
    <!-- Acceuil -->
    <div class="container page" id="acceuil" title="Acceuil">
      <div class="row">
        <div class="col-md-8 col-md-offset-2">
          <button type="button" class="btn btn-primary btn-lg btn-block menu-item" target="newSimulation">Nouvelle Simulation</button>
          <button type="button" class="btn btn-primary btn-lg btn-block menu-item" target="simulation">Continuer</button>
          <button type="button" class="btn btn-primary btn-lg btn-block menu-item" target="params">Configuration</button>
        </div>
      </div>
    </div>
      <!-- Simulation -->
      <div class="container page" id="simulation" title="Simulation">
        <div class="row">
          <center><canvas width="900" height="600" id="graph"></canvas></center>
        </div>
        <div class="row" id="map">
        </div>
        <div class="row">
          <div class="col-md-8 col-md-offset-2">
            <button type="button" class="btn btn-primary btn-lg btn-block menu-item" target="act">
              <span class="badge" id="month"></span>
              Mois Suuivant
            </button>
          </div>
        </div>
        <div class="row">
          <div class="col-md-7 col-md-offset-3">
            <br>  
            <ul class="nav nav-pills">
              <li class="active"><a href="#"> Taux d'embauche des étudiants : <span class="badge" id="studentsPercent">5</span></a></li>
              <li class="active"><a href="#"> Taux d'embauche des lauréats : <span class="badge" id="laureatsPercent">5</span></a></li>
            </ul>
          </div>
        </div>
        <div class="row" id="statistics">
          <div class="col-md-6">
          </div>
        </div>
      </div>
    <!-- Configuration -->
      <div class="container page" id="params" title="Gérer les paramètres">
        <div class="row">
          <div class="col-md-8 col-md-offset-2">
            <form class="form-horizontal" role="form" name="update_params" target="acceuil">            
            </form>
            <button type="button" class="btn btn-primary btn-lg btn-block menu-item" target="acceuil">Retour</button>
          </div>
        </div>
      </div>
    <script src="templates/js/jquery.min.js"></script>
    <script src="templates/js/bootstrap.min.js"></script>
    <script src="templates/js/highcharts/highcharts.js"></script>
    <script src="templates/js/charts.js"></script>
    <script src="templates/js/draw.js"></script>
    <script src="templates/js/statistics.js"></script>
    <script src="templates/js/handler.js"></script>
  </body>
</html>
