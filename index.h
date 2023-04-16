const char index_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP-12E-Tutorial</title>
</head>
<body style="background-color: rgb(44, 44, 44);">
    <div style="width: 30%; text-align: center; height: 30%; margin: auto;">
        <table>
            <tr>
                <td>
                    <form action="SET" method="get">
                        <input type="submit" name="Set" value="stop" style="width: 100px; height: 40px; font-size: 20px; background-color: rgb(255, 0, 0); color: rgb(255, 255, 255);" />
                    </form>
                </td>
            </tr>
        </table>
        <br><br>
        <table>
            <tr>
                <td>
                    
                        <input id="txt1" type="text" value="0" style="text-align: center; width: 150px; height: 50px; font-size: 40px;" />
                    
                    <br><br>
                    <button id="btn1" style="width: 140px; height: 40px;" onclick="Ch1sub();">Channel1</button>
                </td>

                <td>
                    
                        <input  id="txt2" type="text" value="0" style="text-align: center; width: 150px; height: 50px; font-size: 40px;" />
                    
                    <br><br>
                    <button id="btn2" style="width: 140px; height: 40px;" onclick="Ch2sub();">Channel2</button>
                </td>

                <td>
                    
                        <input id="txt3" type="text" value="0" style="text-align: center; width: 150px; height: 50px; font-size: 40px;" />
                    
                    <br><br>
                    <button id="btn3" style="width: 140px; height: 40px;" onclick="Ch3sub();">Channel3</button>
                </td>

                <td>
                    
                        <input id="txt4" type="text" value="0" style="text-align: center; width: 150px; height: 50px; font-size: 40px;" />

                    <br><br>
                    <button id="btn4" style="width: 140px; height: 40px;" onclick="Ch4sub();">Channel4</button>
                </td>
            </tr>
        </table>
        
    </div>
    <br><br>
    <div style="width: 30%; text-align: center; height: 30%; margin: auto;">
        <h2 id="HH" style="color:rgb(255, 255, 255);"></h2>
        <h2 id="HH1" style="color:rgb(255, 255, 255);"></h2>
        <h2 id="HH2" style="color:rgb(255, 255, 255);"></h2>
        <h2 id="HH3" style="color:rgb(255, 255, 255);"></h2>
    </div>
    <script>
        function Ch1sub(){
            var V = document.getElementById('txt1').value;
            var req = new XMLHttpRequest();
            if(V == 0){ req.open("GET", "http://192.168.1.103/SET?Set=I", true);
            req.onreadystatechange = function(){
            if(this.readyState == 4 && this.status ==200)
            {
              document.getElementById("HH").innerHTML = this.responseText;
              var response = this.responseText;
                if(response == "channel one is ON")
                {
                    document.getElementById('btn1').style.backgroundColor = '#33cc33';
                }
                if(response == "channel one is OFF")
                {
                    document.getElementById('btn1').style.backgroundColor = '#bfbfbf';
                }
            }
            };
            req.send();
            req.close();
            return;
            }
            var id = setInterval(function(){
                if(V <= 0 ){return;}
                V-=1;
                document.getElementById('txt1').value = V;
                if(V <= 0 )
                {
                    clearInterval(id);
                    req.open("GET", "http://192.168.1.103/SET?Set=I", true);
                    req.onreadystatechange = function(){
                    if(this.readyState == 4 && this.status ==200)
                    {
                      document.getElementById("HH").innerHTML = this.responseText;
                      var response = this.responseText;
                      if(response == "channel one is ON")
                        {
                            document.getElementById('btn1').style.backgroundColor = '#33cc33';
                        }
                        if(response == "channel one is OFF")
                        {
                            document.getElementById('btn1').style.backgroundColor = '#bfbfbf';
                        }
                    }
                    };
                    req.send();
                    req.close();
                    return;
                }
            },1000);
        }


        function Ch2sub(){
            var V = document.getElementById('txt2').value;
            var req = new XMLHttpRequest();
            if(V == 0){req.open("GET", "http://192.168.1.103/SET?Set=II", true);
            req.onreadystatechange = function(){
            if(this.readyState == 4 && this.status ==200)
            {
              document.getElementById("HH1").innerHTML = this.responseText;
              var response = this.responseText;
                if(response == "channel two is ON")
                {
                    document.getElementById('btn2').style.backgroundColor = '#33cc33';
                }
                if(response == "channel two is OFF")
                {
                    document.getElementById('btn2').style.backgroundColor = '#bfbfbf';
                }
            }
            };
           
           
            req.send();
            req.close();
            return;
            }
            var id = setInterval(function(){
              if(V <= 0 ){return;}
                V-=1;
                document.getElementById('txt2').value = V;
                if(V <=0 )
                {
                    clearInterval(id);
                    req.open("GET", "http://192.168.1.103/SET?Set=II", true);
                    req.onreadystatechange = function(){
                    if(this.readyState == 4 && this.status ==200)
                    {
                    document.getElementById("HH1").innerHTML = this.responseText;
                    var response = this.responseText;
                        if(response == "channel two is ON")
                        {
                            document.getElementById('btn2').style.backgroundColor = '#33cc33';
                        }
                        if(response == "channel two is OFF")
                        {
                            document.getElementById('btn2').style.backgroundColor = '#bfbfbf';
                        }
                    }
                    };
                    req.send();
                    req.close();
                    return;
                }
            },1000);
        }


        function Ch3sub(){
            var V = document.getElementById('txt3').value;
            var req = new XMLHttpRequest();
            if(V == 0){req.open("GET", "http://192.168.1.103/SET?Set=III", true);
            req.onreadystatechange = function(){
            if(this.readyState == 4 && this.status ==200)
            {
              document.getElementById("HH2").innerHTML = this.responseText;
              var response = this.responseText;
                if(response == "channel three is ON")
                {
                    document.getElementById('btn3').style.backgroundColor = '#33cc33';
                }
                if(response == "channel three is OFF")
                {
                    document.getElementById('btn3').style.backgroundColor = '#bfbfbf';
                }
            }
            };
            req.send();
            req.close();
            return;
            }
            var id = setInterval(function(){
              if(V <= 0 ){return;}
                V-=1;
                document.getElementById('txt3').value = V;
                if(V <=0 )
                {
                    clearInterval(id);
                    req.open("GET", "http://192.168.1.103/SET?Set=III", true);
                    req.onreadystatechange = function(){
                    if(this.readyState == 4 && this.status ==200)
                    {
                    document.getElementById("HH2").innerHTML = this.responseText;
                    var response = this.responseText;
                        if(response == "channel three is ON")
                        {
                            document.getElementById('btn3').style.backgroundColor = '#33cc33';
                        }
                        if(response == "channel three is OFF")
                        {
                            document.getElementById('btn3').style.backgroundColor = '#bfbfbf';
                        }
                    }
                    };
                    req.send();
                    req.close();
                    return;
                }
            },1000);
        }


        function Ch4sub(){
            var V = document.getElementById('txt4').value;
            var req = new XMLHttpRequest();
            if(V == 0){req.open("GET", "http://192.168.1.103/SET?Set=IIII", true);
            req.onreadystatechange = function(){
            if(this.readyState == 4 && this.status ==200)
            {
              document.getElementById("HH3").innerHTML = this.responseText;
              var response = this.responseText;
                if(response == "channel four is ON")
                {
                    document.getElementById('btn4').style.backgroundColor = '#33cc33';
                }
                if(response == "channel four is OFF")
                {
                    document.getElementById('btn4').style.backgroundColor = '#bfbfbf';
                }
            }
            };
            req.send();
            req.close();
            return;
            }
            var id = setInterval(function(){
              if(V <= 0 ){return;}
                V-=1;
                document.getElementById('txt4').value = V;
                if(V <=0 )
                {
                    clearInterval(id);
                    req.open("GET", "http://192.168.1.103/SET?Set=IIII", true);
                    req.onreadystatechange = function(){
                    if(this.readyState == 4 && this.status ==200)
                    {
                    document.getElementById("HH3").innerHTML = this.responseText;
                    var response = this.responseText;
                        if(response == "channel four is ON")
                        {
                            document.getElementById('btn4').style.backgroundColor = '#33cc33';
                        }
                        if(response == "channel four is OFF")
                        {
                            document.getElementById('btn4').style.backgroundColor = '#bfbfbf';
                        }
                    }
                    };
                    req.send();
                    req.close();
                    return;
                }
            },1000);
        }
    </script>
</body>
</html>
)=====";
