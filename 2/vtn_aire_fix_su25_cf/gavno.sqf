//if the player isn't in a plane then we don't run this
if(vehicle player iskindof  "Plane") then
{
_Plane = vehicle player;
		hor = 0.5;
		ver = 0.5;
		_helivel = velocity plane;
_helivelcorx = (_helivel select 0) * 0.03334;
_helivelcory = (_helivel select 1) * 0.03334; 
_helivelcorz = (_helivel select 2) * 0.03334;
_helippos = plane modeltoworld (plane selectionposition "rotor_center");
_helippos = [(_helippos select 0) - (_helivelcorx),(_helippos select 1) - (_helivelcory),(_helippos select 2) - (_helivelcorz)];
if(isNil "button_clicked") then {button_clicked = 0;}; //keeps our key from constantly having an effect - that is, press it once and it won't do anything again until released and pressed again

_controlpos = _Plane modelToWorld (_Plane selectionposition "Katapulta"); //our desired control point

_controlpos1 = _Plane modelToWorld (_Plane selectionposition "Dvig");
_controlpos = worldtoscreen _controlpos; //convert the above to screen coordinates
_controlpos1 = worldtoscreen _controlpos1;
if(count _controlpos < 2) then {_controlpos = [0,0];}; //if the point is outside of our FOV then set it to something ridiculous
if(count _controlpos1 < 2) then {_controlpos1 = [0,0];};


//_hinttext = "nope"; //basic hint to indicate what we're looking at
//hint parseText (_controlpos);
if(_controlpos distance [hor,ver] < 0.030) then {cutText ["Jump","PLAIN",1];} ; //change hint to engine on
//if(_controlpos distance [0.5,0.5] < 0.10) then {_hinttext = "Jump";};
if(_controlpos1 distance [hor,ver] < 0.030) then {cutText ["Engine!","PLAIN",1];} ;
//if(_controlpos1 distance [0.5,0.5] < 0.10) then {_hinttext = "Engine";};
if(inputaction "LookCenter" > 0) then
{
		hor = 0.5;
		ver = 0.5;
	((uiNameSpace getVariable "a10_click_helper") displayCtrl 601) ctrlSetPosition [hor - 0.005,ver - 0.009];
	((uiNameSpace getVariable "a10_click_helper") displayCtrl 602) ctrlSetPosition [hor - 0.25,ver + 0.02];
	((uiNameSpace getVariable "a10_click_helper") displayCtrl 601) ctrlCommit 0.01;
	((uiNameSpace getVariable "a10_click_helper") displayCtrl 602) ctrlCommit 0.01;
};
((uiNameSpace getVariable "a10_click_helper")displayCtrl 602) ctrlSetText _helpertext;

//if(!(_hinttext == "")) then {hintsilent format ["%1",_hinttext];}; //set our hint text


//if(_hinttext == "nope") exitwith {}; //if no action available then we don't need to do anything so quit

//else {cutText ["","PLAIN",2]}


//check to see if our action is within the right parameters and that the key has been pressed, then do something
if(inputaction "User9" > 0.5 && button_clicked == 0 && _controlpos distance [hor,ver] < 0.030) then
{
	if(isengineon _Plane) then
	{
		player action ["Eject", _Plane];
	} else {
		player action ["Eject", _Plane];
	};
button_clicked = 1;
};
if(inputaction "User9" > 0.5 && button_clicked == 0 && _controlpos1 distance [hor,ver] < 0.10) then
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
//hint str _planevel;
hint str _controlpos;
};
