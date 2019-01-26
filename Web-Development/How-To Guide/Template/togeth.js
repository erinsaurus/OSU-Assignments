	
Access-Control-Allow-Origin: "https://api.nasa.gov/"


 var rover = "curiosity";
var apiKey = "XLRxi1B4ZROjyYrp37sWmKGTArmDVCxyoftMJrgm";

var manReq = new XMLHttpRequest;
var manUrl = "https://api.nasa.gov/mars-photos/api/v1/manifests/" + rover + "?&api_key=" + apiKey;
manReq.open("GET", manUrl, true);
manReq.send();

manReq.addEventListener("readystatechange", manProcessRequest, false);

function manProcessRequest(e) {
  if (manReq.readyState == 4 && manReq.status == 200) {
    if (response != 0) {
      var response = JSON.parse(manReq.responseText);
      
      document.getElementById("land_date").textContent = response.photo_manifest.landing_date;
      document.getElementById("launch_date").textContent = response.photo_manifest.launch_date;
      document.getElementById("rov_name").textContent = response.photo_manifest.name;
      document.getElementById("status").textContent = response.photo_manifest.status;
      document.getElementById("total_pics").textContent = response.photo_manifest.total_photos;
      document.getElementById("sol_days").textContent = response.photo_manifest.max_sol;

      document.getElementById("submitBtn").addEventListener("click", function() {;
        var solDate = document.getElementById("solRange").value;
    

        var sol = response.photo_manifest.photos[solDate].sol;
        var camera = response.photo_manifest.photos[solDate].cameras[0];

        var req = new XMLHttpRequest;
        var url = "https://api.nasa.gov/mars-photos/api/v1/rovers/" + rover + "/photos?sol=" + sol + "&camera=" + camera + "&api_key=" + apiKey;
        req.open("GET", url, true);
        req.send();

        req.addEventListener("readystatechange", processRequest, false);

        function processRequest() {
          if (req.readyState == 4 && req.status == 200) {
            if (response != 0) {
              var response = JSON.parse(req.responseText);

              document.getElementById("earth_date").textContent = response.photos[1].earth_date;
              document.getElementById("rover_name").textContent = response.photos[1].rover.name;
              document.getElementById("camera_name").textContent = response.photos[1].camera.full_name;

              for (var i = 0; i < response.photos.length; i++) {
                document.getElementById("pic" + i).src = response.photos[i].img_src;
              }
            }
          }
        }
      });
    }
  }
}