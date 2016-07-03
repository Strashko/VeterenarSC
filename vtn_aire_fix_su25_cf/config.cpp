class CfgPatches 
{
	class vtn_aire_fix_su25_cf 
	{
		units[] = {"VTN_SU25"};
		weapons[] = {};
		requiredVersion = 0.100000;
		requiredAddons[] = {"A3_Air_F"};
	};
};
class cfgMovesBasic 
{
	class DefaultDie ;
	class ManActions 
	{
		VTN_SU25_Pilot = "VTN_SU25_Pilot";
		VTN_KIA_SU25_Pilot = "VTN_KIA_SU25_Pilot";
	};
};
class CfgMovesMaleSdr : CfgMovesBasic
{
	class States 
	{
		class Crew ;
		class VTN_KIA_SU25_Pilot : DefaultDie
		{
			actions = "DeadActions";
			file = "\vtn_aire_fix_su25_cf\anim\SU25PilotKIA.rtm";
			speed = 1;
			looped = "false";
			terminal = "true";
			connectTo[] = {"Unconscious", 0.100000};
			soundEnabled = 0;
		};
		class VTN_SU25_Pilot : Crew
		{
			file = "\vtn_aire_fix_su25_cf\anim\SU25PILOT.rtm";
			interpolateTo[] = {"VTN_KIA_SU25_Pilot", 1
			};
			leftHandIKCurve[] = {0.500000};
			rightHandIKCurve[] = {0.500000};
		};
	};
};

class CfgVehicles 
{
	class Air;
	class Plane : Air 
	{
		class HitPoints;
		class ViewPilot;
	};
	
	class Plane_Base_F : Plane 
	{
		class AnimationSources;
		
		class HitPoints : HitPoints 
		{
			class HitHull;
		};
	};
	class VTN_SU25_Base : Plane_Base_F
	{
		mapSize = 16.370001;
		author = "VTN";
		_generalMacro = "VTN_SU25_Base";
		displayName = "Su25";
		scope = 0;
		model = "vtn_aire_fix_su25_md\su25.p3d";
		icon = "vtn_aire_fix_su25_cf\ico\icomap_su25";
		picture = "vtn_aire_fix_su25_cf\ico\su25";
		destrType = "DestructWreck";
		unitInfoType = "RscUnitInfoAir";
		armor = 60;
		armorStructural = 1;
		damageResistance = 0.004000;
		accuracy = 0.200000;
		class Library 
		{
			libTextDesc = "$STR_A3_CfgVehicles_O_Plane_CAS_02_F_Library0";
		};
		driverAction = "VTN_SU25_Pilot";
		getinAction = "pilot_plane_cas_02_Enter";
		getoutaction = "pilot_plane_cas_02_Exit";
		precisegetinout = 1;
		viewDriverShadowDiff = 0.500000;
		viewDriverShadowAmb = 0.500000;
		lockDetectionSystem = 8;
		incomingMissileDetectionSystem = 16;
		driverCansee = "2+8";
		class Turrets 
		{
		};
		class ViewPilot : ViewPilot
		{
			initFov = initFov = tan(atan(0.546281) / 1);
			minFov = tan(atan(0.546281) / 1);
			maxFov = tan(atan(0.546281) / 1);
			initAngleX = 6;
			minAngleX = -85;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class TransportItems 
		{
		};
		attenuationEffectType = "HeliAttenuation";
		soundGetIn[] = {"A3\Sounds_F_EPC\CAS_02\TO_getin", "db0", 1};
		soundGetOut[] = {"A3\Sounds_F_EPC\CAS_02\getout", "db0", 1, 40};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_int", 0.794328, 1.000000};
		soundEngineOnExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_ext", 1.000000, 1.000000, 500};
		soundEngineOffInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_int", 0.794328, 1.000000};
		soundEngineOffExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_ext", 1.000000, 1.000000, 500};
		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", 0.100000, 1};
		soundIncommingMissile[] = {"\A3\Sounds_F\weapons\Rockets\locked_3", 0.100000, 1.500000};
		soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.000000, 150};
		soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.000000, 150};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.000000, 100};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.000000, 100};
		class Sounds 
		{
			class EngineLowOut 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_engine_idle_ext", "db5", 1.000000, 2100};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_engine_max_ext", "db6", 1.200000, 2500};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class ForsageOut 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_forsage_ext", 2.511890, 1.200000, 2800};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[] = {3.140000, 3.920000, 2.000000, 0.500000};
			};
			class WindNoiseOut 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\noise", 0.562341, 1.000000, 150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class EngineLowIn 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_engine_idle_int", 0.630957, 1.000000};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighIn 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_engine_max_int", 0.630957, 1.200000};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageIn 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_forsage_int", 0.630957, 1.200000};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};
			class WindNoiseIn 
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\noise_int", "db-6", 1.000000};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
		};
		altNoForce = 35000;
		altFullForce = 12500;
		maxSpeed = 900;
		aileronSensitivity = 0.500000;
		elevatorSensitivity = 0.800000;
		rudderInfluence = 0.500000;
		flapsFrictionCoef = 0.320000;
		angleOfIndicence = 0.052360;
		draconicForceXCoef = 5;
		draconicForceYCoef = 1.000000;
		draconicForceZCoef = 0.500000;
		draconicTorqueXCoef = 0.150000;
		draconicTorqueYCoef = 1.000000;
		envelope[] = {0, 0.100000, 1.000000, 2.000000, 3.250000, 4.000000, 4.000000, 3.000000, 2.000000, 1.000000, 0.500000};
		thrustCoef[] = {1.000000, 1.200000, 2.700000, 1.800000, 1.300000, 1.200000, 1.200000, 1.100000, 0.900000, 0.400000, 0.100000, 0.000000, 0.000000};
		acceleration = 250;
		landingSpeed = 220;
		landingAoa = "rad 10";
		threat[] = {1, 1, 1};
		radarType = 4;
		irScanGround = "true";
		irScanRangeMin = 100;
		irScanRangeMax = 10000;
		irScanToEyeFactor = 2;
		laserScanner = "true";
		minFireTime = 30;
		gunAimDown = 0.004500;
		headAimDown = 4.000000;
		cabinOpening = 1;
		driverLeftHandAnimName = "";
		driverRightHandAnimName = "";
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointLRocket = "Rocket_1";
		memoryPointRRocket = "Rocket_2";
		memoryPointCM[] = {"flare_launcher1", "flare_launcher2"};
		memoryPointCMDir[] = {"FlareLauncher_1_dir", "FlareLauncher_2_dir"};
		memoryPointLDust = "WheelDust_left_pos";
		memoryPointRDust = "WheelDust_right_pos";
		memoryPointGun = "kulomet";
		selectionFireAnim = "zasleh";
		gunBeg = "usti hlavne";
		gunEnd = "konec hlavne";
		driveOnComponent[] = {"gear_f_w", "gear_l_w", "gear_r_w"};
		class Exhausts 
		{
			class Exhaust_1 
			{
				position = "Exhaust_1_pos";
				direction = "Exhaust_1_dir";
				effect = "ExhaustsEffectJet";
			};
			class Exhaust_2 
			{
				position = "Exhaust_2_pos";
				direction = "Exhaust_2_dir";
				effect = "ExhaustsEffectJet";
			};
		};
		class WingVortices 
		{
			class BodyLeft 
			{
				effectName = "BodyVortices";
				position = "Vapour_body_left_pos";
			};
			class BodyRight 
			{
				effectName = "BodyVortices";
				position = "Vapour_body_right_pos";
			};
			class WingTipLeft 
			{
				effectName = "WingVortices";
				position = "Vapour_wintip_left_pos";
			};
			class WingTipRight 
			{
				effectName = "WingVortices";
				position = "Vapour_wintip_right_pos";
			};
		};
		aggregateReflectors[] = {
				{"Light_1"}, {"Light_2"}
		};
		class Reflectors 
		{
			class Light_1 
			{
				color[] = {0.850000, 0.950000, 1.000000};
				ambient[] = {0.008500, 0.009500, 0.010000};
				intensity = 500000;
				size = 1;
				innerAngle = 15;
				outerAngle = 40;
				coneFadeCoef = 5;
				position = "Light_L";
				direction = "Light_L_end";
				hitpoint = "Light_L";
				selection = "";
				useFlare = 0;
				flareSize = 1.500000;
				flareMaxDistance = 500;
				class Attenuation 
				{
					start = 0;
					constant = 0;
					linear = 5;
					quadratic = 2;
					hardLimitStart = 400;
					hardLimitEnd = 500;
				};
			};
			class Light_2 : Light_1
			{
				position = "Light_R";
				direction = "Light_R_end";
				hitpoint = "Light_R";
			};
		};
		class AnimationSources : AnimationSources {};
		class HitPoints : HitPoints
		{
			class HitAmmo : HitHull
			{
				armor = 1;
				material = 51;
				explosionShielding = 3;
				radius = 0.300000;
				passThrough = "true";
				name = "ammo_hit";
				visual = "ammo_hit";
				convexComponent = "ammo_hit";
			};
			class HitAvionics : HitHull
			{
				armor = 1.500000;
				material = 51;
				explosionShielding = 2;
				radius = 0.650000;
				passThrough = "true";
				name = "avionics_hit";
				visual = "avionics_hit";
				convexComponent = "avionics_hit";
			};
			class HitEngine1 : HitHull
			{
				armor = 2;
				material = 51;
				explosionShielding = 3;
				radius = 0.350000;
				passThrough = "true";
				name = "engine_1_hit";
				visual = "engine_1_hit";
				convexComponent = "engine_1_hit";
			};
			class HitEngine2 : HitEngine1
			{
				material = 51;
				name = "engine_2_hit";
				visual = "engine_2_hit";
				convexComponent = "engine_2_hit";
			};
			class HitEngine : HitEngine2
			{
				material = 51;
				armor = "999	name = ""engine_hit""";
				visual = "";
				convexComponent = "engine_hit";
				depends = "0.5*(HitEngine1 + HitEngine2)";
			};
			class HitFuel : HitHull
			{
				material = 51;
				armor = 1.500000;
				explosionShielding = 3;
				radius = 2;
				passThrough = "true";
				name = "fuel_hit";
				visual = "fuel_hit";
				convexComponent = "fuel_hit";
			};
			class HitGlass1 : HitHull
			{
				armor = 3;
				material = -1;
				explosionShielding = 2;
				radius = 0.700000;
				passThrough = "false";
				name = "glass_1";
				visual = "glass_1";
				convexComponent = "glass_1";
			};
			class HitGlass2 : HitGlass1
			{
				armor = 2;
				material = -1;
				explosionShielding = 3;
				radius = 0.700000;
				passThrough = "false";
				name = "glass_2";
				visual = "glass_2";
				convexComponent = "glass_2";
			};
			class HitHull : HitHull
			{
				armor = 100;
				material = 51;
				explosionShielding = 1;
				radius = 9;
				passThrough = 0.500000;
				name = "hull_hit";
				visual = "zbytek";
				depends = "Total";
				minimumHit = 0.050000;
			};
		};
		class Damage 
		{
			tex[] = {};
			mat[] = {"vtn_aire_fix_su25_tx\su25_body1.rvmat", "vtn_aire_fix_su25_tx\su25_body1_damage.rvmat", "vtn_aire_fix_su25_tx\su25_body1_destruct.rvmat", "vtn_aire_fix_su25_tx\su25_body2.rvmat", "vtn_aire_fix_su25_tx\su25_body2_damage.rvmat", "vtn_aire_fix_su25_tx\su25_body2_destruct.rvmat", "vtn_aire_fix_su25_tx\su25_glass.rvmat", "vtn_aire_fix_su25_tx\su25_glass_damage.rvmat", "vtn_aire_fix_su25_tx\su25_glass_destruct.rvmat", "vtn_aire_fix_su25_tx\su25_glass_in.rvmat", "vtn_aire_fix_su25_tx\su25_glass_in_damage.rvmat", "vtn_aire_fix_su25_tx\su25_glass_in_damage.rvmat"
			};
		};
		class MFD 
		{
			class AirplaneHUD 
			{
				class Pos10Vector 
				{
					type = "vector";
					source = "velocity";
					pos0[] = {0.500000, 0.350000};
					pos10[] = {"0.50+0.9", "0.35+0.7"};
				};
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0, 1, 0, 1.000000};
				enableParallax = 1;
				class Bones 
				{
					class ILS_H 
					{
						type = "ils";
						pos0[] = {0.500000, "0.5+0.06"};
						pos3[] = {0.950000, "0.5+0.06"};
					};
					class ILS_W : ILS_H
					{
						pos3[] = {0.500000, 0.920000};
					};
					class PlaneW 
					{
						type = "fixed";
						pos[] = {0.500000, 0.350000};
					};
					class HorizonBankMGun 
					{
						type = "rotational";
						source = "HorizonBank";
						center[] = {0.500000, 0.350000};
						min = -6.283190;
						max = 6.283190;
						minAngle = -360;
						maxAngle = 360;
						aspectRatio = 1;
					};
					class HorizonBankReverted 
					{
						type = "rotational";
						source = "HorizonBank";
						sourceScale = 1.000000;
						center[] = {0.500000, 0.350000};
						min = "-3.14159265*2";
						max = "3.14159265*2";
						minAngle = 360;
						maxAngle = -360;
						aspectRatio = 0.800000;
					};
					class HorizonDive 
					{
						source = "horizonDive";
						type = "linear";
						min = -1;
						max = 1;
						minPos[] = {0.000000, 0.700000};
						maxPos[] = {0.000000, 0.000000};
					};
					class WeaponAim : Pos10Vector
					{
						source = "weapon";
					};
					class Target : Pos10Vector
					{
						source = "target";
					};
					class VelocityNotCenter : Pos10Vector
					{
						type = "vector";
						source = "velocity";
						pos0[] = {0.000000, 0.000000};
						pos10[] = {1.500000, 1.200000};
					};
					class SpdMove2 
					{
						source = "speed";
						min = 0;
						max = 200;
						type = "linear";
						minPos[] = {0.000000, 0.000000};
						maxPos[] = {0.000000, 1.000000};
					};
					class ASLMove1 
					{
						type = "linear";
						source = "altitudeASL";
						min = 0;
						max = 500;
						minPos[] = {0.000000, 0.100000};
						maxPos[] = {0.000000, 0.800000};
					};
					class Heading 
					{
						type = "linear";
						source = "Heading";
						min = -36;
						max = 36;
						minPos[] = {0.000000, 0.000000};
						maxPos[] = {1.000000, 0.000000};
					};
				};
				class Draw 
				{
					alpha = 0.800000;
					color[] = {0.000000, 1.000000, 0.000000};
					condition = "on";
					 // class Static 
					// {
						// clipTL[] = {0.000000, 0.000000};
						// clipBR[] = {1.000000, 0.000000};
						// type = "line";
						// width = 4.000000;
						// points[] = {{"PlaneW", {-0.210000, 0.000000}, 1}, {"PlaneW", {-0.280000, 0.000000}, 1}, {}, {"PlaneW", {0.210000, -0.000000}, 1}, {"PlaneW", {0.280000, -0.000000}, 1}, {}, {"PlaneW", {-0.105000, 0.145492}, 1}, {"PlaneW", {-0.140000, 0.193990}, 1}, {}, {"PlaneW", {0.105000, 0.145492}, 1}, {"PlaneW", {0.140000, 0.193990}, 1}, {}, {"PlaneW", {-0.181865, 0.084000}, 1}, {"PlaneW", {-0.242487, 0.112000}, 1}, {}, {"PlaneW", {0.181865, 0.084000}, 1}, {"PlaneW", {0.242487, 0.112000}, 1}, {}, {"PlaneW", {-0.202844, 0.043482}, 1}, {"PlaneW", {-0.270459, 0.057976}, 1}, {}, {"PlaneW", {0.202844, 0.043482}, 1}, {"PlaneW", {0.270459, 0.057976}, 1}, {}, {"PlaneW", {-0.209201, 0.014642}, 1}, {"PlaneW", {-0.244068, 0.017082}, 1}, {}, {"PlaneW", {-0.206810, 0.029173}, 1}, {"PlaneW", {-0.241278, 0.034035}, 1}, {}, {"PlaneW", {0.206810, 0.029173}, 1}, {"PlaneW", {0.241278, 0.034035}, 1}, {}, {"PlaneW", {0.209201, 0.014642}, 1}, {"PlaneW", {0.244068, 0.017082}, 1}, {}};
					// };
					// class HorizonBank 
					// {
						// clipTL[] = {0.000000, 0.000000};
						// clipBR[] = {1.000000, 1.000000};
						// type = "line";
						// width = 4.000000;
						// points[] = {{"WeaponAim", {0.210000, 0.000000}, 1}, {"WeaponAim", {0.070000, 0.000000}, 1}, {}, {"WeaponAim", {-0.210000, 0.000000}, 1}, {"WeaponAim", {-0.070000, 0.000000}, 1}, {}, {"WeaponAim", {0.000000, 0.140000}, 1}, {"WeaponAim", {0.000000, 0.070000}, 1}, {}, {"WeaponAim", {0.000000, -0.140000}, 1}, {"WeaponAim", {0.000000, -0.070000}, 1}};
					// };
					// class HorizonDive 
					// {
						// clipTL[] = {0.000000, 0.000000};
						// clipBR[] = {1.000000, 1.000000};
						// type = "line";
						// width = 4.000000;
						// points[] = {{"HorizonDive", {0.800000, 0}, 1}, {"HorizonDive", {0.200000, 0}, 1}};
					// };
					// class Target 
					  // {
						// condition = "missile";
						// class Target 
						// {
							// type = "line";
							// width = 3.000000;
							// points[] = {
									// {"Target", {0, -0.050000}, 1}, {"Target", {"(+0.50*0.05)", "(-0.87*0.05)"}, 1}, {"Target", {"(0.87*0.05)", "(-0.50*0.05)"}, 1}, {"Target", {"(0.05)", 0}, 1}, {"Target", {"(0.87*0.05)", "(0.50*0.05)"}, 1}, {"Target", {"(0.50*0.05)", "(0.87*0.05)"}, 1}, {"Target", {0, "(0.05)"}, 1}, {"Target", {"(-0.50*0.05)", "(0.87*0.05)"}, 1}, {"Target", {"(-0.87*0.05)", "(+0.50*0.05)"}, 1}, {"Target", {"(-0.05)", 0}, 1}, {"Target", {"(-0.87*0.05)", "(-0.50*0.05)"}, 1}, {"Target", {"(-0.50*0.05)", "(-0.87*0.05)"}, 1}, {"Target", {0, "(-0.05)"}, 1}
							// };
						 // };
					// }; 
					 class MachineGun 
					 {
							type = "group";
						 condition = "mgun";
						 class Circle 
						 {
							 type = "line";
							 width = 8.0;
							 points[] = {{"WeaponAim", {0.162,-0.594}, 1},{"WeaponAim", {0.174,-0.594}, 1},{"WeaponAim", {0.185,-0.592}, 1},{"WeaponAim", {0.197,-0.590}, 1},{"WeaponAim", {0.214,-0.587}, 1},{"WeaponAim", {0.223,-0.584}, 1},{"WeaponAim", {0.232,-0.581}, 1},{"WeaponAim", {0.242,-0.577}, 1},{"WeaponAim", {0.251,-0.572}, 1},{"WeaponAim", {0.258,-0.568}, 1},{"WeaponAim", {0.266,-0.564}, 1},{"WeaponAim", {0.274,-0.564}, 1},{"WeaponAim", {0.272,-0.560}, 1},{"WeaponAim", {0.279,-0.555}, 1},{"WeaponAim", {0.286,-0.549}, 1},{"WeaponAim", {0.293,-0.544}, 1},{"WeaponAim", {0.301,-0.536}, 1},{"WeaponAim", {0.310,-0.527}, 1},{"WeaponAim", {0.316,-0.520}, 1},{"WeaponAim", {0.322,-0.511}, 1},{"WeaponAim", {0.328,-0.502}, 1},{"WeaponAim", {0.333,-0.496}, 1},{"WeaponAim", {0.340,-0.484}, 1},{"WeaponAim", {0.347,-0.469}, 1},{"WeaponAim", {0.353,-0.455}, 1},{"WeaponAim", {0.357,-0.444}, 1},{"WeaponAim", {0.360,-0.428}, 1},{"WeaponAim", {0.363,-0.415}, 1},{"WeaponAim", {0.364,-0.403}, 1},{"WeaponAim", {0.365,-0.395}, 1},{"WeaponAim", {0.365,-0.388}, 1},{"WeaponAim", {0.365,-0.380},1}};
							 //{"WeaponAim", {0.0855+0.1, -0.293656-0.4}, 1}, {"WeaponAim", {0.125+0.1, -0.270625-0.4}, 1}, {"WeaponAim", {0.1607+0.1, -0.239375-0.4}, 1}, {"WeaponAim", {0.1915+0.1, -0.200875-0.4}, 1}, {"WeaponAim", {0.2165+0.1, -0.15625-0.4}, 1}, {"WeaponAim", {0.234925+0.1, -0.106875-0.4}, 1}, {"WeaponAim", {0.2462+0.1, -0.05425-0.4}, 1}, {"WeaponAim", {0.25+0.1, 0-0.4}, 1}, {"WeaponAim", {0.2462+0.1, 0.05425-0.4}, 1}
							 //{"WeaponAim", {0+0.1, -0.3125+0.1}, 1}, {"WeaponAim", {0.0434+0.1, -0.30775+0.1}, 1}
							// , {"WeaponAim", {0.0855, -0.293656}, 1}, {"WeaponAim", {0.125, -0.270625}, 1}, {"WeaponAim", {0.1607, -0.239375}, 1}, {"WeaponAim", {0.1915, -0.200875}, 1}, {"WeaponAim", {0.2165, -0.15625}, 1}, {"WeaponAim", {0.234925, -0.106875}, 1}, {"WeaponAim", {0.2462, -0.05425}, 1}, {"WeaponAim", {0.25, 0}, 1}, {"WeaponAim", {0.2462, 0.05425}, 1}, {"WeaponAim", {0.234925, 0.106875}, 1}, {"WeaponAim", {0.2165, 0.15625}, 1}, {"WeaponAim", {0.1915, 0.200875}, 1}, {"WeaponAim", {0.1607, 0.239375}, 1}, {"WeaponAim", {0.125, 0.270625}, 1}, {"WeaponAim", {0.0855, 0.293656}, 1}, {"WeaponAim", {0.0434, 0.30775}, 1}, {"WeaponAim", {0, 0.3125}, 1}, {"WeaponAim", {-0.0434, 0.30775}, 1}, {"WeaponAim", {-0.0855, 0.293656}, 1}, {"WeaponAim", {-0.125, 0.270625}, 1}, {"WeaponAim", {-0.1607, 0.239375}, 1}, {"WeaponAim", {-0.1915, 0.200875}, 1}, {"WeaponAim", {-0.2165, 0.15625}, 1}, {"WeaponAim", {-0.234925, 0.106875}, 1}, {"WeaponAim", {-0.2462, 0.05425}, 1}, {"WeaponAim", {-0.25, 0}, 1}, {"WeaponAim", {-0.2462, -0.05425}, 1}, {"WeaponAim", {-0.234925, -0.106875}, 1}, {"WeaponAim", {-0.2165, -0.15625}, 1}, {"WeaponAim", {-0.1915, -0.200875}, 1}, {"WeaponAim", {-0.1607, -0.239375}, 1}, {"WeaponAim", {-0.125, -0.270625}, 1}, {"WeaponAim", {-0.0855, -0.293656}, 1}, {"WeaponAim", {-0.0434, -0.30775}, 1}, {"WeaponAim", {0, -0.3125}, 1}
						 };
					 };
					 class MachineGun1
					{
						condition = "mgun";
						class Cros 
						{
							type = "line";
							width = 6.000000;
							points[] =  
							{
								// {"WeaponAim", {+0.00,+0.00}, 1}, // л-в
								// {"WeaponAim", {+0.10,+0.00}, 1}, // п-в
								// {"WeaponAim", {+0.10,-0.10}, 1}, // п-н
								// {"WeaponAim", {+0.00,-0.10}, 1}, // л-н
								// {}, // квадрат
								// {"WeaponAim", {+0.05,+0.00}, 1}, // ц-в
								// {"WeaponAim", {+0.05,-0.10}, 1}, // ц-н
								// {}, // верт. линия
								// {"WeaponAim", {+0.00,-0.05}, 1}, // л-ц
								// {"WeaponAim", {+0.10,-0.05}, 1}, // п-ц
								// {} // гор. линия
								{"WeaponAim", {0.031, -0.378}, 1}, {"WeaponAim", {0.132, -0.378}, 1}, {}, {"WeaponAim", {0.295, -0.378}, 1}, {"WeaponAim", {0.191, -0.378}, 1}, {}, {"WeaponAim", {0.162, -0.510}, 1}, {"WeaponAim", {0.162, -0.407}, 1}, {}, {"WeaponAim", {0.161, -0.245}, 1}, {"WeaponAim", {0.161, -0.347}, 1}
							};
							//{"WeaponAim", {-0.021, -0.378}, 1}, {"WeaponAim", {0.132, -0.378}, 1}, {}, {"WeaponAim", {0.344, -0.378}, 1}, {"WeaponAim", {0.191, -0.378}, 1}, {}, {"WeaponAim", {0.162, -0.560}, 1}, {"WeaponAim", {0.162, -0.407}, 1}, {}, {"WeaponAim", {0.161, -0.194}, 1}, {"WeaponAim", {0.161, -0.347}, 1}
						};
					};
					// class ATMissile 
					// {
						// condition = "ATmissile";
						// class Cros 
						// {
							// type = "line";
							// width = 8.000000;
							// points[] = {
									// {"WeaponAim", {0.001000, 0}, 1}, {"WeaponAim", {-0.001000, 0}, 1}, {}, {"WeaponAim", {0, 0.001000}, 1}, {"WeaponAim", {0, -0.001000}, 1}, {}, {"WeaponAim", {0, -0.050000}, 1}, {"WeaponAim", {"(+0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {"(0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(0.05)", 0}, 1}, {"WeaponAim", {"(0.87*0.05)", "(0.50*0.05)"}, 1}, {"WeaponAim", {"(0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {0, "(0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(+0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.05)", 0}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {0, "(-0.05)"}, 1}
							// };
						// };
					// };
					// class Bomb 
					// {
						// condition = "Bomb";
						// class Cros 
						// {
							// type = "line";
							// width = 8.000000;
							// points[] = {
									// {"WeaponAim", {0.001000, 0}, 1}, {"WeaponAim", {-0.001000, 0}, 1}, {}, {"WeaponAim", {0, 0.001000}, 1}, {"WeaponAim", {0, -0.001000}, 1}, {}, {"WeaponAim", {0, -0.050000}, 1}, {"WeaponAim", {"(+0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {"(0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(0.05)", 0}, 1}, {"WeaponAim", {"(0.87*0.05)", "(0.50*0.05)"}, 1}, {"WeaponAim", {"(0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {0, "(0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(+0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.05)", 0}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {0, "(-0.05)"}, 1}
							// };
						// };
					// };
					// class Rockets 
					// {
						// condition = "Rocket";
						// class Cros 
						// {
							// type = "line";
							// width = 8.000000;
							// points[] = {
									// {"WeaponAim", {0.001000, 0}, 1}, {"WeaponAim", {-0.001000, 0}, 1}, {}, {"WeaponAim", {0, 0.001000}, 1}, {"WeaponAim", {0, -0.001000}, 1}, {}, {"WeaponAim", {0, -0.050000}, 1}, {"WeaponAim", {"(+0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {"(0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(0.05)", 0}, 1}, {"WeaponAim", {"(0.87*0.05)", "(0.50*0.05)"}, 1}, {"WeaponAim", {"(0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {0, "(0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(+0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.05)", 0}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {0, "(-0.05)"}, 1}
							// };
						// };
					// };
					// class AAMissile 
					// {
						// condition = "AAmissile";
						// class Cros 
						// {
							// type = "line";
							// width = 8.000000;
							// points[] = {
									// {"WeaponAim", {0.001000, 0}, 1}, {"WeaponAim", {-0.001000, 0}, 1}, {}, {"WeaponAim", {0, 0.001000}, 1}, {"WeaponAim", {0, -0.001000}, 1}, {}, {"WeaponAim", {0, -0.050000}, 1}, {"WeaponAim", {"(+0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {"(0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(0.05)", 0}, 1}, {"WeaponAim", {"(0.87*0.05)", "(0.50*0.05)"}, 1}, {"WeaponAim", {"(0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {0, "(0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(0.87*0.05)"}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(+0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.05)", 0}, 1}, {"WeaponAim", {"(-0.87*0.05)", "(-0.50*0.05)"}, 1}, {"WeaponAim", {"(-0.50*0.05)", "(-0.87*0.05)"}, 1}, {"WeaponAim", {0, "(-0.05)"}, 1}
							// };
						// };
					// };
					// class SpeedNumber 
					// {
						// type = "text";
						// align = "right";
						// scale = 1;
						// source = "speed";
						// sourceScale = 3.600000;
						// pos[] = {{0.060000, 0.070000}, 1};
						// right[] = {{0.140000, 0.070000}, 1};
						// down[] = {{0.060000, 0.140000}, 1};
					// };
					// class AltNumber : SpeedNumber
					// {
						// source = "altitudeASL";
						// sourceScale = 1;
						// pos[] = {{0.860000, 0.070000}, 1};
						// right[] = {{0.940000, 0.070000}, 1};
						// down[] = {{0.860000, 0.140000}, 1};
					// };
					// class weapons 
					// {
						// type = "text";
						// source = "weapon";
						// align = "right";
						// scale = 1;
						// sourceScale = 1;
						// pos[] = {{0.060000, 0.700000}, 1};
						// right[] = {{0.100000, 0.700000}, 1};
						// down[] = {{0.060000, 0.740000}, 1};
					// };
					// class ammo 
					// {
						// type = "text";
						// source = "ammo";
						// align = "right";
						// scale = 1;
						// sourceScale = 1;
						// pos[] = {{0.060000, 0.760000}, 1};
						// right[] = {{0.100000, 0.760000}, 1};
						// down[] = {{0.060000, 0.800000}, 1};
					// };
					// class ILS 
					// {
						// condition = "ils";
						// class Glideslope 
						// {
							// clipTL[] = {0.000000, 0.000000};
							// clipBR[] = {1.000000, 1.000000};
							// class ILS 
							// {
								// type = "line";
								// points[] = {
										// {"ILS_W", {-0.400000, 0}, 1}, {"ILS_W", {0.400000, 0}, 1}, {}, {"ILS_W", {0, 0.040000}, 1}, {"ILS_W", {0, -0.040000}, 1}, {}, {"ILS_W", {0.200000, 0.040000}, 1}, {"ILS_W", {0.200000, -0.040000}, 1}, {}, {"ILS_W", {0.400000, 0.040000}, 1}, {"ILS_W", {0.400000, -0.040000}, 1}, {}, {"ILS_W", {-0.200000, 0.040000}, 1}, {"ILS_W", {-0.200000, -0.040000}, 1}, {}, {"ILS_W", {-0.400000, 0.040000}, 1}, {"ILS_W", {-0.400000, -0.040000}, 1}, {}, {"ILS_H", {0, -0.400000}, 1}, {"ILS_H", {0, 0.400000}, 1}, {}, {"ILS_H", {0.040000, 0}, 1}, {"ILS_H", {-0.040000, 0}, 1}, {}, {"ILS_H", {0.040000, 0.200000}, 1}, {"ILS_H", {-0.040000, 0.200000}, 1}, {}, {"ILS_H", {0.040000, 0.400000}, 1}, {"ILS_H", {-0.040000, 0.400000}, 1}, {}, {"ILS_H", {0.040000, -0.200000}, 1}, {"ILS_H", {-0.040000, -0.200000}, 1}, {}, {"ILS_H", {0.040000, -0.400000}, 1}, {"ILS_H", {-0.040000, -0.400000}, 1}, {}
								// };
							// };
						// };
					// };
					// class HeadingArrow 
					// {
						// type = "line";
						// width = 3.000000;
						// points[] = {{{"0.5-0.02", "0.11-0.02"}, 1}, {{0.500000, 0.110000}, 1}, {{"0.5+0.02", "0.11-0.02"}, 1}};
					// };
					// class HeadingLine 
					// {
						// type = "line";
						// width = 4.000000;
						// points[] = {{{0.200000, 0.120000}, 1}, {{0.800000, 0.120000}, 1}};
					// };
					// class HeadingScale 
					// {
						// type = "scale";
						// horizontal = 1;
						// source = "heading";
						// sourceScale = 1.000000;
						// width = 4.000000;
						// top = 0.200000;
						// center = 0.500000;
						// bottom = 0.800000;
						// lineXleft = "0.06+0.05";
						// lineYright = "0.05+0.05";
						// lineXleftMajor = "0.06+0.05";
						// lineYrightMajor = "0.04+0.05";
						// majorLineEach = 5;
						// numberEach = 5;
						// step = "18 9";
						// stepSize = "(0.70-0.3) 15";
						// align = "center";
						// scale = 1.000000;
						// pos[] = {0.200000, "0.0+0.05"};
						// right[] = {0.250000, "0.0+0.05"};
						// down[] = {0.200000, "0.04+0.05"};
					// };
					// class AltitudeArrow 
					// {
						// type = "line";
						// width = 4.000000;
						// points[] = {{{"0.88+0.018", "0.40-0.016"}, 1}, {{0.880000, 0.400000}, 1}, {{"0.88+0.018", "0.40+0.016"}, 1}};
					// };
					// class AltitudeScale 
					// {
						// type = "scale";
						// horizontal = 0;
						// source = "altitudeASL";
						// sourceScale = 1;
						// width = 4.000000;
						// top = 0.700000;
						// center = 0.450000;
						// bottom = 0.200000;
						// lineXleft = 0.880000;
						// lineYright = 0.890000;
						// lineXleftMajor = 0.880000;
						// lineYrightMajor = 0.900000;
						// majorLineEach = 5;
						// numberEach = 5;
						// step = 20;
						// stepSize = "(0.60-0.20) 15";
						// align = "right";
						// scale = 1;
						// pos[] = {0.910000, 0.680000};
						// right[] = {0.960000, 0.680000};
						// down[] = {0.910000, 0.720000};
					// };
				};
			};
		};
		class UserActions 
		{
			class ChangeAltitude 
			{
				displayName = "$STR_VTN_AIR_ACTION_ALT";
				displayNameDefault = "";
				priority = 0;
				radius = 0;
				position = "driver";
				showWindow = 0;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "(driver this != player) && (alive this) && (isEngineOn this) && ((driver this) in (units group player))";
				statement = "this execVM 'VTN_gw_air\data\scripts\changeAltPlane.sqf'";
			};
		};
		class EventHandlers
		{
			  init = "(_this select 0) execvm ""vtn_aire_fix_su25_cf\init.sqf"";";
		};
	};
	class VTN_SU25 : VTN_SU25_Base
	{
		author = "$STR_VTN";
		_generalMacro = "VTN_SU25";
		scope = 2;
		side = 0;
		displayName = "$STR_DN_VTN_SU25";
		faction = "06VTN_MILFOR_VVS";
		vehicleClass = "09VTN_AIRB";
		crew = "VTN_VVS_AIRB_PILOT";
		availableForSupportTypes[] = {"CAS_Bombing"};
		weapons[] = {"Cannon_30mm_Plane_CAS_02_F","VTN_ASO2VM","VTN_GSH302","VTN_B8M1","VTN_AKU581","VTN_P721DB2"};
		magazines[] = {"500Rnd_Cannon_30mm_Plane_CAS_02_F","VTN_PPR26_64","VTN_GSH302_250_HET","VTN_S8KOM_80","VTN_R73RDM1_2_AA","VTN_KH29L_4_AT",
		};
	};
};