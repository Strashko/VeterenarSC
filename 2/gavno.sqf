//if the player is in a vehicle then we don't run this
if(vehicle player iskindof  "plane") then
{
_nearestvehs = nearestobjects [player, ["car","tank","boat","plane","helicopter"], 10]; //check for these vehicle classes

if(count _nearestvehs < 1) exitwith {};

if(isNil "button_clicked") then {button_clicked = 0;}; //keeps our key from constantly having an effect - that is, press it once and it won't do anything again until released and pressed again

_nearestveh = _nearestvehs select 0;

_getinpos = _nearestveh modelToWorld (_nearestveh selectionposition "Katapulta"); //the Katapulta point
_getinpos = worldtoscreen _getinpos; //convert the above to screen coordinates
if(count _getinpos < 2) then {_getinpos = [-100,-100];}; //if the point is outside of our FOV then set it to something ridiculous

_getinpos2 = _nearestveh modelToWorld (_nearestveh selectionposition "Dvig");
_getinpos2 = worldtoscreen _getinpos2;
if(count _getinpos2 < 2) then {_getinpos2 = [-100,-100];};

if(_getinpos distance [0.5,0.5] < 0.4) then {cutText ["Jump","PLAIN",2];}; //change hint to driver if the match is for the driver point
//if(_getinpos distance [0.5,0.5] > 0.4) then {cutText ["","PLAIN",2];};
if(_getinpos2 distance [0.5,0.5] < 0.4) then {cutText ["Engine!","PLAIN",2];};
//if(_getinpos2 distance [0.5,0.5] > 0.4) then {cutText ["","PLAIN",2];};


//check to see if our action is within the right parameters and that the key has been pressed, then do something
if(inputaction "User9" > 0.5 && button_clicked == 0 && _getinpos distance [0.5,0.5] < 0.4) then
{
player action ["Eject", _nearestveh];
button_clicked = 1;
};

if(inputaction "User9" > 0.5 && button_clicked == 0 && _getinpos2 distance [0.5,0.5] < 0.4) then
{
if(isengineon _Plane) then
	{
		player action ["EngineOff", _Plane];
	} else {
		player action ["EngineOn", _Plane];
	};
button_clicked = 1;
};

//clear our key press if it's not being pressed
if(inputaction "User9" < 0.5) then
{
button_clicked = 0;
};
};