//Name animation
$(document).ready(function()
{
    $("#JeremyDeppen").mousedown(function()
    {
        $("#JeremyDeppen").fadeTo("slow", 0)
    });
    $("#AndrewSaba").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#KevinMadison").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#ZachYoder").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#AlexFurches").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#AmyJohnson").mousedown(function()
    {
        $(this).animate({fontSize: "40px"}, function()
        {
           $(this).fadeTo("fast", 0)   
        });
    });
    $("#IzaLantgios").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JamesBraza").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JessSocash").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JoeLynch").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JohnMontagna").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JonKenneson").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#MichelleRiffitts").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#TylerDantonio").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#WoodyFulmer").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#ZachEgolf").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#EthanSchumann").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JoshTarlo").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#DanPassarello").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#VanessaColihan").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#ZachEasparro").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#BrianRandall").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#MariaLongo").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#JoshSenft").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });
    $("#AndreaDavis").mousedown(function()
    {
        $(this).fadeTo("slow", 0)
    });

});
//JavaScript to create the animated background
function dream()
{
    var color = 'rgb(249, 243, 22)';  //yellow bubble
    var color2 = 'rgb(0, 0, 150)';    //blue bubble

    //calculating random X position
    var x = Math.floor(Math.random()*$(window).width());

    //calculating random Y position
    var y = Math.floor(Math.random()*$(window).height());

    //creating the dream and hide
    drawingpix = $('<span>').attr({class: 'drawingpix'}).hide();

    //appending it to body
    $(document.body).append(drawingpix);

    //styling dream.. filling colors.. positioning.. showing.. growing..fading
    drawingpix.css({
    'background-color':color,
    'border-radius':'100px',
    '-moz-border-radius': '100px',
    '-webkit-border-radius': '100px',
    top: y-14,    //offsets
    left: x-14 //offsets
    }).show().animate({
        height:'500px',
        width:'500px',
        'border-radius':'500px',
        '-moz-border-radius': '500px',
        '-webkit-border-radius': '500px',
        opacity: 0.1,
        top: y-250,    //offsets
        left: x-250
     }, 3000).fadeOut(2000);
                            
    //Every dream's end starts a new dream
    window.setTimeout('dream()',200);
    } 

function dream2()
{
    
    var color = 'rgb(249, 243, 22)';  //yellow bubble
    var color2 = 'rgb(0, 0, 150)';    //blue bubble

    //calculating random X position
    var x = Math.floor(Math.random()*$(window).width());

    //calculating random Y position
    var y = Math.floor(Math.random()*$(window).height());

    //creating the dream and hide
    drawingpix = $('<span>').attr({class: 'drawingpix'}).hide();

    //appending it to body
    $(document.body).append(drawingpix);

    //styling dream.. filling colors.. positioning.. showing.. growing..fading
    drawingpix.css({
    'background-color':color2,
    'border-radius':'100px',
    '-moz-border-radius': '100px',
    '-webkit-border-radius': '100px',
    top: y-14,    //offsets
    left: x-14 //offsets
    }).show().animate({
        height:'500px',
        width:'500px',
        'border-radius':'500px',
        '-moz-border-radius': '500px',
        '-webkit-border-radius': '500px',
        opacity: 0.1,
        top: y-250,    //offsets
        left: x-250
     }, 3000).fadeOut(2000);
                            
    //Every dream's end starts a new dream
    window.setTimeout('dream2()',200);
    }

    $(document).ready(function() {  
      //calling the first dream
      dream();
      dream2();
    });
