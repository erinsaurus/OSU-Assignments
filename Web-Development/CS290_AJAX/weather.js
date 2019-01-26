document.addEventListener('DOMContentLoaded', bindWeatherButton);

function bindWeatherButton(){

  var apiKey = '836b54781410078b56db66e1bb281ad9';
  document.getElementById("zipSubmit").addEventListener('click', function(event){

    var userCity = document.getElementById("city").value;
    var userCountry = document.getElementById("country").value;
    var userZip = document.getElementById("zipCode").value;
    var userState = document.getElementById('state').value;

    var req = new XMLHttpRequest();
    req.open('GET','http://api.openweathermap.org/data/2.5/weather?zip='+userZip+','+userCountry+'&appid='+apiKey+'&units=imperial',true);
    req.addEventListener('load', function(){
      if (req.status >= 200 && req.status < 400){
        var response = JSON.parse(req.responseText);
        document.getElementById("temperature").textContent = response.main.temp +" \u00B0F";
        document.getElementById("humidity").textContent = response.main.humidity+"%";
        document.getElementById("curCity").textContent = response.name;
      }
      else {
        console.log("Error in network request: "+request.statusText);
      }
    });
    req.send(null);
    event.preventDefault();
  });

  document.getElementById("citySubmit").addEventListener('click', function(event){

    var userCity = document.getElementById("city").value;
    var userCountry = document.getElementById("country").value;
    var userZip = document.getElementById("zipCode").value;
    var userState = document.getElementById('state').value;

    var req = new XMLHttpRequest();
    req.open('GET','http://api.openweathermap.org/data/2.5/weather?q='+userCity+'&appid='+apiKey+'&units=imperial',true);
    req.addEventListener('load', function(){
      if (req.status >= 200 && req.status < 400){
        var response = JSON.parse(req.responseText);
        document.getElementById("temperature").textContent = response.main.temp +" \u00B0F";
        document.getElementById("humidity").textContent = response.main.humidity+"%";
        document.getElementById("curCity").textContent = response.name;
      }
      else {
        console.log("Error in network request: "+request.statusText);
      }
    });
    req.send(null);
    event.preventDefault();
  });


}