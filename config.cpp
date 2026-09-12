class CfgPatches
{
    class ld3k_jca_scar_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_SCAR",
            "weapons_f_jca_SCAR_Rifles_SCAR_H",
            "weapons_f_jca_SCAR_Rifles_SCAR_L"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    // JCA Bullets inherited from vanilla class B_556x45_Ball. To avoid all conflict with other mods, all JCA bullets with JCA as prefixe.
    // class B_556x45_Ball: BulletBase official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class JCA_B_556x45_Ball: BulletBase // M855, ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L117
    {
        ACE_caliber=5.70; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/223-rem-170406-en.pdf
        ACE_bulletLength=23.01; // ACE3
        ACE_bulletMass=4.018; // 62gr
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; // default ACE_ammoTempMuzzleVelocityShifts values (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -8m/s 15°C
        ACE_ballisticCoefficients[]={0.149}; // US Army's Ballistic Research Laboratory ASM BC 0.151 converted to ICAO 0.149012
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        // ACE_barrelLengths[]={210.82,238.76,269.24,299.72,330.2,360.68,391.16,419.1,449.58,480.06,508,609.6}; // default ACE3 barrel lengths https://en.wikipedia.org/wiki/5.56%C3%9745mm_NATO
        // ACE_muzzleVelocities[]={723,764,796,825,843,866,878,892,906,915,922,900}; // default ACE3 MVs 4m https://en.wikipedia.org/wiki/5.56%C3%9745mm_NATO
        // ACE_muzzleVelocities[]={715,784,832,873,890,912,926,904}; // MVs V0 Strelok Pro 15°C
        // ACE_barrelLengths[]={203.2,254,304.8,368.3,406.4,457.2,508,609.6}; // 8", 10", 12", 14.5", 16", 18", 20", 24" barrels lengths
        ACE_muzzleVelocities[]={723,792,840,881,898,920,934}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 791m/s (10.3"), 808m/s (11"), 873m/s (14.5"), 926m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        ACE_barrelLengths[]={203.2,254,304.8,368.3,406.4,457.2,508}; // M4A1 CQB, M4A4, M4A4 EGLM 10.3" (261.62mm), HK433 CQB 11" (279,4mm),  M4A1, M4A1 EGLM, HK433 14.5" (368.3mm), M16A4 20" (508mm) barrels lengths
        airLock=1;
        hit=9.16; // 1723 Joules, B_556x45_Ball 9 1693 Joules
        indirectHit=0;
        indirectHitRange=0;
        cost=1;
        typicalSpeed=926; // 1723 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00133644; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder, ACE3 0.00130094, B_556x45_Ball 0.0012
        waterFriction=-0.3;
        caliber=0.869565; // B_556x45_Ball, M995 AP3 52gr: 12mm RHA 100m MV 1030m/s https://www.nammo.com, effective perforation in-game 12mm RHA "armour_plate_12mm.bisurf" 100m ~900m/s: caliber ~0.9
        // M855: 1020 steel plate (Hardness=50/70 Rb; thickness=3mm) 570m (MV 910m/s), effective perforation in-game 3mm RHA "armour_plate_3mm.bisurf" 570m ~400m/s: caliber ~0.55
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_762x51_Ball, B_556x45_Ball tracer_yellow
        tracerScale=1;
        tracerStartTime=0.17; // Visible 140m 600m (typically 800m) 4g MV 920m/s ICAO according to https://www.nammo.com, ToF 140m 0.17s (Strelok Pro), B_556x45_Ball 0.05
        tracerEndTime=1.62; // Visible 140m 600m (typically 800m) 4g MV 920m/s ICAO according to https://www.nammo.com, ToF 800m 1.62s (Strelok Pro), B_556x45_Ball 1
        nvgOnly=0; // B_556x45_Ball w/o nvgOnly
        audibleFire=35;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        aiAmmoUsageFlags=64;
        class CamShakeExplode
        {
            power=2.23607;
            duration=0.4;
            frequency=20;
            distance=6.7082;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_556x45_Ball_M855A1: JCA_B_556x45_Ball // M855A1 Lake City Army Ammunition Plant, 2022/23 article https://www.ar15.com/forums/AR-15/M855A1-Accuracy-and-Velocity-updated-/16-783286/
    {
        ACE_bulletLength=25.4; // 1"
        ACE_ballisticCoefficients[]={0.149}; // average ICAO G7 BC 0.149 from "Ballistic Performance of Rifle Bullets" by Bryan Litz, (average ICAO G1 BC 0.291)
        // 76°F (24°C rounded to 25°C for ACE3), 1019mB, 47%, barrel length 20": 3131fps (954m/s - 954m/s in-game), barrel length 14.5": average 2951fps (899m/s - 900m/s in-game) from 2022/23 article values https://www.ar15.com/forums/AR-15/M855A1-Accuracy-and-Velocity-updated-/16-783286/
        ACE_muzzleVelocities[]={734,804,853,894,911,934,948}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 803m/s (10.3"), 821m/s (11"), 886m/s (14.5"), 940m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.44; // 1775 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=940; // 1775 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00132981; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=1; // B_556x45_Ball 0.869565
    };
    class JCA_B_556x45_Ball_M193: JCA_B_556x45_Ball // M193 RUAG Ammotec AG
    {
        ACE_bulletLength=19; // average value
        ACE_bulletMass=3.6; // 55gr
        ACE_ballisticCoefficients[]={0.280}; // M193 RUAG Ammotec AG
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={772,846,898,941,960,983,998}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 846m/s (10.3"), 864m/s (11"), 933m/s (14.5"), 990m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.38; // 1764 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=990; // 1764 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00139457; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_Mk262: JCA_B_556x45_Ball // ACE_556x45_Ball_Mk262 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L141
    {
        ACE_bulletLength=25.25; // 0.994" Strelok Pro
        ACE_bulletMass=4.99; // 77gr
        ACE_ballisticCoefficients[]={0.356}; // ASM BC 0.361 converted to ICAO 0.356247
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={655,717,761,798,813,833,846}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 716m/s (10.3"), 731m/s (11"), 790m/s (14.5"), 838m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.31; // 1752 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=838; // 1752 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00114664; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_Mk318: JCA_B_556x45_Ball // ACE_556x45_Ball_Mk318 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L155
    {
        ACE_bulletLength=23.67; // Mod 1 0.932"
        ACE_bulletMass=4.018; // 62gr
        ACE_ballisticCoefficients[]={0.303}; // ASM BC 0.307 converted to ICAO 0.302958
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={742,812,862,904,921,944,958}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 812m/s (10.3"), 829m/s (11"), 896m/s (14.5"), 950m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.64; // 1813 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=950; // 1813 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00130202; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_M995AP: JCA_B_556x45_Ball // ACE_556x45_Ball_M995_AP https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L168
    {
        ACE_bulletLength=22.7; // AP4, AP3 20.6
        ACE_bulletMass=4.536; // 70gr AP4, AP3 52gr
        ACE_ballisticCoefficients[]={0.306}; // ASM BC 0.310 converted to ICAO 0.305919
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={687,753,799,838,854,875,888}; // Muzzle Velocities 70°F (21°C, MV 15°C +8m/s), 752m/s (10.3"), 768m/s (11"), 830m/s (14.5"), 880m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.34; // 1757 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=880; // 1757 Joules, B_556x45_Ball 920 1693 Joules
        airFriction=-0.00131582; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=1.2; // ACE_556x45_Ball_M995_AP 1.6, B_556x45_Ball 0.869565
        // M995 AP4 69gr: 7mm RHA 200m MV 900m/s https://www.nammo.com, effective perforation in-game 7mm RHA "armour_plate_7mm.bisurf" 200m ~700m/s: caliber ~0.7
        // M995 AP3 52gr: 12mm RHA 100m MV 1030m/s https://www.nammo.com, effective perforation in-game 12mm RHA "armour_plate_12mm.bisurf" 100m ~900m/s: caliber ~0.9
    };
    /*class B_556x45_dual: B_556x45_Ball // official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        cartridge="FxCartridge_65";
        audibleFire=20;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        typicalSpeed=270;
        airFriction=-0.02;
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };*/
    class JCA_B_556x45_Ball_Dual: JCA_B_556x45_Ball // 5.56mm underwater subsonic DSG Technology https://dsgtec.com https://www.youtube.com/@DSGTechnology/videos https://www.thefirearmblog.com/blog/2017/04/20/dsg-technology-underwater-ammo
    {
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10 (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -1m/s 15°C
        ACE_muzzleVelocities[]={220,241,255,268,273,280,284}; // Muzzle Velocities 70°F (21°C, MV 15°C +1m/s), 242m/s (10.3"), 247m/s (11"), 267m/s (14.5"), 283m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        // cartridge="FxCartridge_65";
        visibleFire=1; // B_127x54_Ball, BulletBase 3
        audibleFire=5; // B_127x54_Ball, B_556x45_Ball 35, B_556x45_dual 20
        dangerRadiusBulletClose=4; // B_556x45_Ball 8
        dangerRadiusHit=8; // B_556x45_Ball 12
        suppressionRadiusBulletClose=2; // B_556x45_Ball 6
        suppressionRadiusHit=4; // B_556x45_Ball 8
        typicalSpeed=283; // B_556x45_dual 270
        airFriction=-0.0005713; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder, https://github.com/acemod/ACE3/pull/7982
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };
    class JCA_B_556x45_Ball_Tracer_Red: JCA_B_556x45_Ball
    {
        visibleFire=5; // B_556x45_Ball 3, B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_556x45_Ball_Tracer_Green: JCA_B_556x45_Ball_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_556x45_Ball_Tracer_Yellow: JCA_B_556x45_Ball_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_556x45_Ball_IR_Dim_Tracer: JCA_B_556x45_Ball
    {
        tracerScale=0.5; // IR dim tracer, B_556x45_Ball 1
        tracerStartTime=0.01; // Visible 13m 600m (typically 950m) 3.9g MV 930m/s ICAO according to https://www.nammo.com, ToF 13m 0.01s (Strelok Pro), B_556x45_Ball 0.05
        tracerEndTime=2.12; // Visible 13m 600m (typically 950m) 3.9g MV 930m/s ICAO according to https://www.nammo.com, ToF 950m 2.12s (Strelok Pro), B_556x45_Ball 1
        nvgOnly=1;
    };
    // JCA Bullets inherited from vanilla class B_762x51_Ball. To avoid all conflict with other mods, all JCA bullets with JCA as prefixe
    // class B_762x51_Ball: BulletBase official BI tool All-in-one Config Arma3 2.23.153886 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class JCA_B_762x51_Ball_M80: BulletBase // B_762x51_Ball https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L293
    {
        ACE_caliber=7.85; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/tabical-en-page125.pdf
        ACE_bulletLength=28.96;
        ACE_bulletMass=9.461; // 146gr
        // ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32
        // ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; // default ACE_ammoTempMuzzleVelocityShifts values (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -8m/s 15°C
        ACE_ammoTempMuzzleVelocityShifts[]={-18.7,-18.2,-16.6,-14,-10.4,-5.7,0,6.8,14.6,23.4,33.3}; // Same curve default ACE_ammoTempMuzzleVelocityShifts. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.2};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={700,746,784,820,833,841,845}; // Muzzle velocities ICAO (15°C, 1013.25hPa, 0%)
        ACE_barrelLengths[]={254,330.2,406.4,508,558.8,609.6,660.4}; // 10, 13, 16, 20, 22, 24, 26" barrels lengths
        hit=12.2; // 3181 Joules, B_762x51_Ball 11.6 3028 Joules
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_762";
        visibleFire=3;
        audibleFire=45;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        cost=1.2;
        airLock=1;
        typicalSpeed=820; // 3181 Joules, B_762x51_Ball 800 3028 Joules
        caliber=1.6; // ??? M80 146gr: 3.5mm NATO plate 550m MV 810m/s https://www.nammo.com
        // effective perforation in-game 3mm RHA "armour_plate_3mm.bisurf" 550m ~445m/s: caliber ~0.45
        // effective perforation in-game 5mm RHA "armour_plate_5mm.bisurf" 550m ~445m/s: caliber ~0.75
        // M993 AP 128gr: 18mm RHA 100m MV 930m/s https://www.nammo.com, effective perforation in-game 18mm RHA "armour.bisurf" thickness .p3d 18mm 100m ~840m/s: caliber ~1.4
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        tracerScale=1; // B_556x45_Ball 1, B_65x39_Caseless 1, B_762x39_Ball_F 1, B_762x51_Ball 0.6
        tracerStartTime=0.18; // Visible 140m 775m (typically 900m) 9g 820m/s ICAO according to https://www.nammo.com, ToF 140m 0.18s (Strelok Pro), B_762x51_Ball 0.0075
        tracerEndTime=1.87; // Visible 140m 775m (typically 900m) 9g 820m/s ICAO according to https://www.nammo.com, ToF 900m 1.87s (Strelok Pro), B_762x51_Ball 5
        nvgOnly=0; // B_762x51_Ball w/o nvgOnly
        airFriction=-0.00103882; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.82843;
            duration=0.6;
            frequency=20;
            distance=8.48528;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_762x51_Ball_M80A1: JCA_B_762x51_Ball_M80
    {
        ACE_bulletLength=30.26; // 1.1915"
        ACE_bulletMass=8.489; // 131gr
        ACE_ballisticCoefficients[]={0.173}; // Bryan Litz
        ACE_muzzleVelocities[]={759,809,850,889,903,912,916}; // 3012fps (918m/s) 22" (558.8mm) 76°F (24.4°C rounded to 25°C), 903m/s ICAO (15°C, 1013.25hPa, 0%) https://www.youtube.com/watch?v=K5h4Kp7zmXw
        hit=12.9; // 3355 Joules, B_762x51_Ball 11.6 3028 Joules
        typicalSpeed=889; // 3355 Joules, B_762x51_Ball 800 3028 Joules
        caliber=2; // B_762x51_Ball 1.6
        airFriction=-0.00116766; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_762x51_Ball_M993AP: JCA_B_762x51_Ball_M80 // ACE_762x51_Ball_M993_AP https://www.nammo.comproduct/our-products/ammunition/small-caliber-ammunition/7-62mm-series/7-62-mm-x-51-armor-piercing-8-m993/
    {
        ACE_bulletLength=28.96; // 1.14"
        ACE_bulletMass=8.23; // 127gr
        ACE_ballisticCoefficients[]={0.359}; // https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L351
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={782,833,875,915,930,939,943}; // 930m/s 22" (558.8mm) ICAO (15°C, 1013.25hPa, 0%)
        hit=13.6; // 3560 Joules, B_762x51_Ball 11.6 3028 Joules
        typicalSpeed=930; // 3560 Joules, B_762x51_Ball 800 3028 Joules
        caliber=2.2; // ??? ~28mm RHA 100m MV 930m/s ACE_762x51_Ball_M993_AP, B_762x51_Ball 1.6
        // M993 AP 128gr: 18mm RHA 100m MV 930m/s https://www.nammo.com, effective perforation in-game 18mm RHA "armour.bisurf" thickness .p3d 18mm 100m ~840m/s: caliber ~1.4
        // M993 AP 128gr: 7mm RHA 500m MV 930m/s https://www.nammo.com, effective perforation in-game 7mm RHA "armour_plate_7mm.bisurf" 500m ~530m/s: caliber ~0.9
        airFriction=-0.0011103; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_762x51_Ball_Mk316: JCA_B_762x51_Ball_M80 // ACE_762x51_Ball_Mk316_Mod_0 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L317
    {
        ACE_bulletLength=31.5; // Strelok Pro, Applied Ballistics
        ACE_bulletMass=11.34; // 175gr
        // ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; default ACE3
        // ACE_ammoTempMuzzleVelocityShifts[]={-5.3,-5.1,-4.6,-4.2,-3.4,-2.6,-1.4,-0.3,1.4,3.0,5.2}; default ACE_762x51_Ball_Mk316_Mod_0
        // ACE_ammoTempMuzzleVelocityShifts[]={-5.31,-5.094,-4.57,-4.024,-3.396,-2.56,-1.528,-0.306,1.192,3.034,5.238}; // default ACE_ammoTempMuzzleVelocityShifts values /5 (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -2m/s 15°C
        // ACE_ammoTempMuzzleVelocityShifts[]={-18.7,-18.2,-16.6,-14,-10.4,-5.7,0,6.8,14.6,23.4,33.3}; // Same curve default ACE_ammoTempMuzzleVelocityShifts. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ammoTempMuzzleVelocityShifts[]={-3.74,-3.64,-3.32,-2.8,-2.08,-1.14,0,1.36,2.92,4.68,6.66}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /5. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        // ACE_ballisticCoefficients[]={0.243}; // Bryan Litz Applied Ballistics ICAO G7 BC based on Sierra ASM G1 BC 0.505 2800 fps (853m/s) and above
        ACE_ballisticCoefficients[]={0.489}; // ICAO G1 BC 0.48947 converted from Sierra bullet 7.62mm 175 Gr. HPBT MatchKing ASM G1 BC 0.496 between 2800fps (853m/s) and 1800fps (549m/s) https://www.sierrabullets.com/product/30-cal-7-62mm-175-gr-hpbt-matchking/
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={674,719,755,790,803,810,814}; // Muzzle velocities ICAO (15°C, 1013.25hPa, 0%)
        hit=13.6; // 3539 Joules, B_762x51_Ball 11.6 3028 Joules
        typicalSpeed=790; // 3539 Joules, B_762x51_Ball 800 3028 Joules
        caliber=1.8; // ACE_762x51_Ball_Mk316_Mod_0, B_762x51_Ball 1.6
        airFriction=-0.00084907; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_762x51_Ball_Mk319: JCA_B_762x51_Ball_M80 // ACE_762x51_Ball_Mk319_Mod_0 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L347
    {
        ACE_bulletLength=25.93; // 1.021"
        ACE_bulletMass=8.424; // 130gr
        // ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; default ACE3
        // ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; default ACE_762x51_Ball_Mk319_Mod_0 values /10
        // ACE_ammoTempMuzzleVelocityShifts[]={-18.7,-18.2,-16.6,-14,-10.4,-5.7,0,6.8,14.6,23.4,33.3}; // Same curve default ACE_ammoTempMuzzleVelocityShifts. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /10. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.377};
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={776,827,869,909,923,932,936}; // 3032fps (924m/s) 22" (558.8mm) 73.8°F (23.2°C rounded to 25°C), 923m/s ICAO (15°C, 1013.25hPa, 0%) https://www.youtube.com/watch?v=Ae2LIkX7PzM
        // 2920fps @78feet 22" test barrel, 7.62mm Small Caliber Ammunition Test Procedure (SCATP) https://forum.cartridgecollectors.org/t/7-62mm-mk319-sost/10459/3
        hit=13.3; // 3481 Joules, B_762x51_Ball 11.6 3028 Joules
        typicalSpeed=909; // 3481 Joules, B_762x51_Ball 800 3028 Joules
        caliber=1.5; // ACE_762x51_Ball_Mk319_Mod_0, B_762x51_Ball 1.6
        airFriction=-0.00105916; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_762x51_Ball_SLAP: JCA_B_762x51_Ball_M80 // 7.62x51 XM948/M948 SLAP and CBJ Tech datas https://forum.cartridgecollectors.org/t/7-62mm-nato-slap-tracer-questions/7398
    {
        ACE_caliber=4.83; // 0.190" https://forum.cartridgecollectors.org/t/7-62mm-nato-slap-tracer-questions/7398/26
        ACE_bulletLength=17.78; // 0.700"
        ACE_bulletMass=3.402; // 52.5gr
        ACE_ballisticCoefficients[]={0.165}; // https://cbjtech.com/ammunition/7-62x51-cbj/
        ACE_muzzleVelocities[]={1015,1082,1137,1190,1208,1220,1226}; // 1220m/s 24" (609.6mm) ICAO (15°C, 1013.25hPa, 0%) https://cbjtech.com/ammunition/7-62x51-cbj/
        hit=9.7; // 2532 Joules, B_762x51_Ball 11.6 3028 Joules
        typicalSpeed=1220; // 2532 Joules, B_762x51_Ball 800 3028 Joules
        caliber=3.2; // B_127x99_SLAP 3.4, B_762x51_Ball 1.6
        airFriction=-0.00107693; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_762x51_Ball_SLAP_Tracer: JCA_B_762x51_Ball_SLAP // 7.62x51 XM959/M959 SLAP Tracer and CBJ Tech datas https://forum.cartridgecollectors.org/t/7-62mm-nato-slap-tracer-questions/7398
    {
        ACE_caliber=5.70; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/223-rem-170406-en.pdf
        ACE_bulletLength=23.11; // 0.91" M196 https://www.inetres.com/gp/military/infantry/rifle/556mm_ammo.html
        ACE_bulletMass=3.421; // 52.8gr M959 https://forum.cartridgecollectors.org/t/7-62mm-nato-slap-tracer-questions/7398/24
        ACE_ballisticCoefficients[]={0.127}; // 5.56 M193
        hit=13.5; // 2546 Joules, B_556x45_Ball 9 1693 Joules
        typicalSpeed=1220; // 2546 Joules, B_556x45_Ball 920 1693 Joules
        caliber=0.9; // B_556x45_Ball 0.869565, B_127x99_SLAP 3.4, B_762x51_Ball 1.6
        airFriction=-0.00139857; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_762x51_Ball_Subsonic: JCA_B_762x51_Ball_M80 // Lapua subsonic B416, 325m/s 16" (406.4mm) barrel (Trajectory charts) https://www.lapua.com/product/308-win-subsonic-fmjbt-tactical-cartridge-13g-200gr-4317340/
    {
        ACE_bulletLength=34.11; // Strelok Pro
        ACE_bulletMass=12.96; // 200 gr
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /10. Muzzle velocity shift 0m/s ICAO (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.518}; // https://www.lapua.com/product/30-cal-fmjbt-subsonic-bullet-b416-130-g-200-gr/
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={290,309,325,340,345,349,350}; // 325m/s 16" (406.4mm) ICAO (15°C, 1013.25hPa, 0%)
        hit=6; // ACE_762x51_Ball_Subsonic, B_762x51_Ball 11.6
        visibleFire=1; // B_127x54_Ball, B_762x51_Ball 3
        audibleFire=5; // B_127x54_Ball, B_762x51_Ball 45
        dangerRadiusBulletClose=4; // B_127x54_Ball, B_762x51_Ball 8
        suppressionRadiusBulletClose=2; // B_127x54_Ball, B_762x51_Ball 6
        typicalSpeed=320; // ACE_762x51_Ball_Subsonic
        caliber=1; // ACE_762x51_Ball_Subsonic, B_762x51_Ball 1.6
        airFriction=-0.00049496; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.23607; // B_127x54_Ball, B_762x51_Ball 2.8284299
            duration=0.4; // B_127x54_Ball, B_762x51_Ball 0.6
            frequency=20; // B_127x54_Ball ,B_762x51_Ball 20
            distance=6.7082; // B_127x54_Ball, B_762x51_Ball 8.48528
        };
    };
    class JCA_B_762x51_Ball_M80_Tracer_Red: JCA_B_762x51_Ball_M80
    {
        visibleFire=5; // B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_762x51_Ball_M80_Tracer_Green: JCA_B_762x51_Ball_M80_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_762x51_Ball_M80_Tracer_Yellow: JCA_B_762x51_Ball_M80_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_762x51_Ball_M80_IR_Dim_Tracer: JCA_B_762x51_Ball_M80
    {
        tracerScale=0.6; // IR dim tracer, B_762x51_Ball
        tracerStartTime=0.02; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 13m 0.02s (Strelok Pro), B_762x51_Ball 0.0075
        tracerEndTime=3.03; // Visible 13m 775m (typically 1250m) 9g 840m/s ICAO according to https://www.nammo.com, ToF 1250m 3.03s (Strelok Pro), B_762x51_Ball 5
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    // JCA 5.56x45 Stanag Magazines uses vanilla class 30Rnd_556x45_Stanag. To avoid all conflict with other mods and RPT Updating base class, all JCA 5.56x45 Stanag Magazines with JCA as prefixe.
    /*class 30Rnd_556x45_Stanag: CA_Magazine official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        picture="\a3\Weapons_F\MagazineProxies\data\UI\icon_30Rnd_556x45_Stanag_CA.paa";
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag0";
        ammo="B_556x45_Ball";
        count=30;
        initSpeed=920;
        tracersEvery=0;
        lastRoundsTracer=4;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
        modelSpecial="\a3\Weapons_F_Exp\MagazineProxies\mag_556x45_stanag_30rnd.p3d";
        modelSpecialIsProxy=1;
    };*/
    class JCA_30Rnd_556x45_Stanag: CA_Magazine // JCA default config with JCA as prefixe
    {
        picture="\weapons_f_JCA_SCAR\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_CA.paa";
        author="Laid3acK";
        scope=2;
        displayName="5.56 mm 30Rnd Mag";
        ammo="JCA_B_556x45_Ball";
        count=30;
        mass=8; // 13.6 Steel magazine 30 rounds (empty) 250g + 30x 12.3g (M855 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=926; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="Caliber: 5.56x45 mm<br />Rounds: 30<br />Used in: 5.56 STANAG Rifles";
        modelSpecial="weapons_f_JCA_SCAR\MagazineProxies\30Rnd_556_SMAG.p3d";
        modelSpecialIsProxy=1;
        displaynameshort="M855";
    };
    class JCA_30Rnd_556x45_Stanag_M855A1: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M855A1 Mag";
        ammo="JCA_B_556x45_Ball_M855A1";
        initSpeed=940; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M855A1";
    };
    class JCA_30Rnd_556x45_Stanag_M193: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M193 Mag";
        ammo="JCA_B_556x45_Ball_M193";
        mass=7.8; // 13.2 Steel magazine 30 rounds (empty) 250g + 30x 11.6g (M193 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=990; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M193";
    };
    class JCA_30Rnd_556x45_Stanag_Mk262: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Mk262 Mag";
        ammo="JCA_B_556x45_Ball_Mk262";
        mass=8.4; // 14.3 Steel magazine 30 rounds (empty) 250g + 30x 13.3g (Mk262 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=838; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk262";
    };
    class JCA_30Rnd_556x45_Stanag_Mk318: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Mk318 Mag";
        ammo="JCA_B_556x45_Ball_Mk318";
        initSpeed=950; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk318";
    };
    class JCA_30Rnd_556x45_Stanag_M995AP: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M995 AP Mag";
        ammo="JCA_B_556x45_Ball_M995AP";
        mass=8.1; // 13.8 Steel magazine 30 rounds (empty) 250g + 30x 12.6g (M995 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=880; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M995 AP";
    };
    class JCA_30Rnd_556x45_Stanag_UW: JCA_30Rnd_556x45_Stanag // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Dual Purpose Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        initSpeed=283; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="UW";
    };
    class JCA_30Rnd_556x45_Stanag_Red: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Green: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Yellow: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_IR: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Mag";
        ammo="JCA_B_556x45_Ball_IR_Dim_Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Red: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Red) Mag";
        tracersEvery=1;
        displaynameshort="M855 Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Green: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_IR: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (IR) Mag";
        ammo="JCA_B_556x45_Ball_IR_Dim_Tracer";
        displaynameshort="M855 Tracer IR";
    };
    class JCA_30Rnd_556x45_Stanag_Sand: JCA_30Rnd_556x45_Stanag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Sand Mag";
        picture="\weapons_f_JCA_SCAR\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_sand_CA.paa";
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_SCAR\MagazineProxies\data\mag_30Rnd_556_SMAG_sand_CO.paa"
        };
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M855A1: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M855A1 Sand Mag";
        ammo="JCA_B_556x45_Ball_M855A1";
        initSpeed=940; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M855A1";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M193: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M193 Sand Mag";
        ammo="JCA_B_556x45_Ball_M193";
        mass=7.8; // 13.2 Steel magazine 30 rounds (empty) 250g + 30x 11.6g (M193 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=990; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M193";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Mk262: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Mk262 Sand Mag";
        ammo="JCA_B_556x45_Ball_Mk262";
        mass=8.4; // 14.3 Steel magazine 30 rounds (empty) 250g + 30x 13.3g (Mk262 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=838; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk262";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Mk318: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Mk318 Sand Mag";
        ammo="JCA_B_556x45_Ball_Mk318";
        initSpeed=950; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk318";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M995AP: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd M995 AP Sand Mag";
        ammo="JCA_B_556x45_Ball_M995AP";
        mass=8.1; // 13.8 Steel magazine 30 rounds (empty) 250g + 30x 12.6g (M995 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=880; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M995 AP";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_UW: JCA_30Rnd_556x45_Stanag_Sand // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Dual Purpose Sand Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        initSpeed=283; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="UW";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Red: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Green: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_IR: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Sand Mag";
        ammo="JCA_B_556x45_Ball_IR_Dim_Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Red) Sand Mag";
        tracersEvery=1;
        displaynameshort="M855 Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Green) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Laid3acK";
        displayName="5.56 mm 30Rnd Tracer (IR) Sand Mag";
        ammo="JCA_B_556x45_Ball_IR_Dim_Tracer";
        displaynameshort="M855 Tracer IR";
    };
    class JCA_20Rnd_762x51_SCAR_Mag: CA_Magazine // JCA default config
    {
        ammo="JCA_B_762x51_Ball_M80";
        mass=12.6; // 16.1 Mag 20 rnds 244g + 20x ~24.3g ~730g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=820; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M80";
    };
    class JCA_20Rnd_762x51_SCAR_M80A1_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR M80A1 Mag";
        ammo="JCA_B_762x51_Ball_M80A1";
        mass=12.3; // 15.7 Mag 20 rnds 244g + 20x ~23.3g ~710g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=889; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M80A1";
    };
    class JCA_20Rnd_762x51_SCAR_M993AP_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR M993 AP Mag";
        ammo="JCA_B_762x51_Ball_M993AP";
        mass=12.2; // 15.6 Mag 20 rnds 244g + 20x ~23.1g ~706g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=915; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M993 AP";
    };
    class JCA_20Rnd_762x51_SCAR_Mk316_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Mk316 Mag";
        ammo="JCA_B_762x51_Ball_Mk316";
        mass=13.2; // 16.9 Mag 20 rnds 244g + 20x ~26.2g ~768g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=790; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk316";
    };
    class JCA_20Rnd_762x51_SCAR_Mk319_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Mk319 Mag";
        ammo="JCA_B_762x51_Ball_Mk319";
        mass=12.3; // 15.7 Mag 20 rnds 244g + 20x ~23.3g ~710g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=909; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk319";
    };
    class JCA_20Rnd_762x51_SCAR_SLAP_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR SLAP Mag";
        ammo="JCA_B_762x51_Ball_SLAP";
        mass=10.7; // 13.7 Mag 20 rnds 244g + 20x ~18.9g ~622g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=1190; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="SLAP";
    };
    class JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag: JCA_20Rnd_762x51_SCAR_SLAP_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR SLAP Tracer Mag";
        ammo="JCA_B_762x51_Ball_SLAP_tracer";
        mass=10.6; // 13.6 Mag 20 rnds 244g + 20x ~18.7g ~618g, 20Rnd_762x51_Mag 12, JCA 10
        tracersEvery=1;
        displaynameshort="SLAP Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Subsonic_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Subsonic Mag";
        ammo="JCA_B_762x51_Ball_Subsonic";
        mass=13.8; // 17.6 Mag 20 rnds 244g + 20x ~27.8g ~800g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=340; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Subsonic";
    };
    class JCA_20Rnd_762x51_SCAR_Red_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Red";
    };
    class JCA_20Rnd_762x51_SCAR_Green_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Green";
    };
    class JCA_20Rnd_762x51_SCAR_Yellow_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_SCAR_IR_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_IR_Dim_Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Red";
        displaynameshort="M80 Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Green";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_IR_Dim_Tracer";
        displaynameshort="M80 Tracer IR";
    };
    class JCA_20Rnd_762x51_SCAR_Sand_Mag: JCA_20Rnd_762x51_SCAR_Mag
    {
    };
    class JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR M80A1 Sand Mag";
        ammo="JCA_B_762x51_Ball_M80A1";
        mass=12.3; // 15.7 Mag 20 rnds 244g + 20x ~23.3g ~710g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=889; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M80A1";
    };
    class JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR M993 AP Sand Mag";
        ammo="JCA_B_762x51_Ball_M993AP";
        mass=12.2; // 15.6 Mag 20 rnds 244g + 20x ~23.1g ~706g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=915; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M993 AP";
    };
    class JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Mk316 Sand Mag";
        ammo="JCA_B_762x51_Ball_Mk316";
        mass=13.2; // 16.9 Mag 20 rnds 244g + 20x ~26.2g ~768g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=790; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk316";
    };
    class JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Mk319 Sand Mag";
        ammo="JCA_B_762x51_Ball_Mk319";
        mass=12.3; // 15.7 Mag 20 rnds 244g + 20x ~23.3g ~710g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=909; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk319";
    };
    class JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR SLAP Sand Mag";
        ammo="JCA_B_762x51_Ball_SLAP";
        mass=10.7; // 13.7 Mag 20 rnds 244g + 20x ~18.9g ~622g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=1190; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="SLAP";
    };
    class JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag: JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR SLAP Tracer Sand Mag";
        ammo="JCA_B_762x51_Ball_SLAP_Tracer";
        mass=10.6; // 13.6 Mag 20 rnds 244g + 20x ~18.7g ~618g, 20Rnd_762x51_Mag 12, JCA 10
        tracersEvery=1;
        displaynameshort="SLAP Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        author="Laid3acK";
        displayName="7.62 mm 20Rnd SCAR Subsonic Sand Mag";
        ammo="JCA_B_762x51_Ball_Subsonic";
        mass=13.8; // 17.6 Mag 20 rnds 244g + 20x ~27.8g ~800g, 20Rnd_762x51_Mag 12, JCA 10
        initSpeed=340; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Subsonic";
    };
    class JCA_20Rnd_762x51_SCAR_Red_Sand_Mag: JCA_20Rnd_762x51_SCAR_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Red";
    };
    class JCA_20Rnd_762x51_SCAR_Green_Sand_Mag: JCA_20Rnd_762x51_SCAR_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Green";
    };
    class JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag: JCA_20Rnd_762x51_SCAR_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_SCAR_IR_Sand_Mag: JCA_20Rnd_762x51_SCAR_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_IR_Dim_Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag: JCA_20Rnd_762x51_SCAR_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Red";
        displaynameshort="M80 Tracer";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Green";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag: JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_762x51_Ball_M80_IR_Dim_Tracer";
        displaynameshort="M80 Tracer IR";
    };
};
class CfgMagazineWells
{
    class STANAG_556x45
    {
        BI_Magazines[]=
        { // 5.56x45mm default Arma3 Mags official BI tool All-in-one Config Arma3 2.23.153886 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag_green",
            "30Rnd_556x45_Stanag_red",
            "30Rnd_556x45_Stanag_Tracer_Red",
            "30Rnd_556x45_Stanag_Tracer_Green",
            "30Rnd_556x45_Stanag_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Sand",
            "30Rnd_556x45_Stanag_Sand_green",
            "30Rnd_556x45_Stanag_Sand_red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "30Rnd_556x45_Stanag_Sand_Tracer_Yellow"
        };
        JCA_Magazines[]= // Weapon initSpeed -1 ACE_barrelLength 508mm (20"): 926, 940, 990, 838, 950, 880, 283m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_556x45 magazines initSpeed
        { // All 5.56x45mm JCA Mags
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
    };
    class JCA_SCAR_762x51
    {
        JCA_Magazines[]= // Weapon initSpeed -1 ACE_barrelLength 508mm (20"): 820, 889, 915, 790, 909, 1190, 340m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_20Rnd_762x51_SCAR magazines initSpeed
        {
            "JCA_20Rnd_762x51_SCAR_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Mag",
            "JCA_20Rnd_762x51_SCAR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
    class InventoryOpticsItem_Base_F;
    class InventoryUnderItem_Base_F;
    class ItemCore;
    class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
    };
    class JCA_arifle_SCAR_L_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=177.8; // 1:7"
        ACE_barrelLength=368.3; // 14.5"
        ACE_railHeightAboveBore=4.38847; // ACE3 checkScopes.sqf
        maxZeroing=1000; // distance 5.56x45 Mk262 Mach 0.8 (272m/s) ICAO, Assault rifles 5.56x45 800
        initSpeed=-0.942679; // 873, 886, 933, 790, 896, 830, 267m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 850
        canShootInWater=1; // SDAR_base_F
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=79.4; // 3.6kg https://fnherstal.com/app/uploads/technical-data-fn-scar-l-mk2-2.pdf, JCA 70
        };
        class Single: Mode_SemiAuto
        {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType // SDAR_base_F
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            class SilencedSound: BaseSoundModeType
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            dispersion=0.000540; // 3.3 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType // SDAR_base_F
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            class SilencedSound: BaseSoundModeType
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            dispersion=0.000540; // 3.3 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_SCAR_L_GL_base_F: JCA_arifle_SCAR_L_base_F
    {
        ACE_barrelLength=254; // 10" https://fnherstal.com/app/uploads/technical-data-fn-scar-l-mk2-2.pdf
        maxZeroing=900; // distance 5.56x45 Mk262 Mach 0.8 (272m/s) ICAO, Assault rifles 5.56x45 800
        initSpeed=-0.8467; // 784, 796, 838, 709, 804, 745, 240m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        descriptionShort="Assault Rifle<br />Caliber: 5.56x45 mm<br />Grenade Launcher<br />Caliber: 40 mm";
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=104.9; // 3.4kg, M203 1.36kg https://fnherstal.com/app/uploads/technical-data-fn-scar-l-mk2-2.pdf https://en.wikipedia.org/wiki/M203_grenade_launcher, JCA 90
        };
        class Single: Single
        {
            dispersion=0.000646; // 3.95 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000646; // 3.95 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00065 (2.23 MOA)
        };
    };
    class JCA_arifle_SCAR_L_short_base_F: JCA_arifle_SCAR_L_base_F
    {
        ACE_barrelLength=254; // 10" https://fnherstal.com/app/uploads/technical-data-fn-scar-l-mk2-2.pdf
        maxZeroing=900; // distance 5.56x45 Mk262 Mach 0.8 (272m/s) ICAO, Assault rifles 5.56x45 800
        initSpeed=-0.8467; // 784, 796, 838, 709, 804, 745, 240m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=75; // 3.4kg https://fnherstal.com/app/uploads/technical-data-fn-scar-l-mk2-2.pdf, JCA 65
        };
        class Single: Single
        {
            dispersion=0.000646; // 3.95 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00085 (2.92 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000646; // 3.95 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00085 (2.92 MOA)
        };
    };
    class JCA_arifle_SCAR_L_sand_F: JCA_arifle_SCAR_L_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_SCAR_L_GL_sand_F: JCA_arifle_SCAR_L_GL_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_SCAR_L_short_sand_F: JCA_arifle_SCAR_L_short_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_SCAR_H_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=304.8; // 1:12"
        ACE_barrelLength=406.4; // 16" https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf
        ACE_railHeightAboveBore=4.38847; // from ACE3 checkScopes.sqf
        maxZeroing=1400; // distance 7.62x51 Mk316 Mach 0.8 (272m/s) ICAO, Marksman Rifles 7.62x51 1600
        initSpeed=-0.9559; // 784, 850, 875, 755, 869, 1137, 325 m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 880
        descriptionShort="Assault Rifle<br />Caliber: 7.62x51 mm";
        magazines[]=
        {
            "JCA_20Rnd_762x51_SCAR_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Mag",
            "JCA_20Rnd_762x51_SCAR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=80; // 3.63kg https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf, JCA 120
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000481; // 2.94 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0006 (2.06 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.000481; // 2.94 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0006 (2.06 MOA)
        };
    };
    class JCA_arifle_SCAR_H_GL_base_F: JCA_arifle_SCAR_H_base_F
    {
        ACE_barrelLength=330.2; // 13" https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf
        maxZeroing=1300; // distance 7.62x51 Mk316 Mach 0.8 (272m/s) ICAO, Marksman Rifles 7.62x51 1600
        initSpeed=-0.9096; // 746, 809, 833, 719, 827, 1082, 309 m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        descriptionShort="Assault Rifle<br />Caliber: 7.62x51 mm<br />Grenade Launcher<br />Caliber: 40 mm";
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=106.3; // 3.46kg, M203 1.36kg https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf https://en.wikipedia.org/wiki/M203_grenade_launcher, JCA 130
        };
        class Single: Single
        {
            dispersion=0.000527; // 3.22 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0006 (2.06 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000527; // 3.22 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0006 (2.06 MOA)
        };
    };
    class JCA_arifle_SCAR_H_short_base_F: JCA_arifle_SCAR_H_base_F
    {
        ACE_barrelLength=330.2; // 13" https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf
        maxZeroing=1300; // distance 7.62x51 Mk316 Mach 0.8 (272m/s) ICAO, Assault rifles 5.56x45 800
        initSpeed=-0.9096; // 746, 809, 833, 719, 827, 1082, 309 m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=76.2; // 3.46kg https://fnherstal.com/app/uploads/technical-data-fn-scar-h-mk2-2.pdf, JCA 115
        };
        class Single: Single
        {
            dispersion=0.000527; // 3.22 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00076 (2.61 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000527; // 3.22 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00076 (2.61 MOA)
        };
    };
    class JCA_arifle_SCAR_H_sand_F: JCA_arifle_SCAR_H_base_F
    {
        magazines[]=
        {
            "JCA_20Rnd_762x51_SCAR_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Mag"
        };
    };
    class JCA_arifle_SCAR_H_GL_sand_F: JCA_arifle_SCAR_H_GL_base_F
    {
        magazines[]=
        {
            "JCA_20Rnd_762x51_SCAR_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Mag"
        };
    };
    class JCA_arifle_SCAR_H_short_sand_F: JCA_arifle_SCAR_H_short_base_F
    {
        magazines[]=
        {
            "JCA_20Rnd_762x51_SCAR_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Sand_Mag",
            "JCA_20Rnd_762x51_SCAR_Mag",
            "JCA_20Rnd_762x51_SCAR_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Red_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Green_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_Yellow_Mag",
            "JCA_20Rnd_762x51_SCAR_Tracer_IR_Mag",
            "JCA_20Rnd_762x51_SCAR_M80A1_Mag",
            "JCA_20Rnd_762x51_SCAR_M993AP_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk316_Mag",
            "JCA_20Rnd_762x51_SCAR_Mk319_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Mag",
            "JCA_20Rnd_762x51_SCAR_SLAP_Tracer_Mag",
            "JCA_20Rnd_762x51_SCAR_Subsonic_Mag"
        };
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo;
    };
    class muzzle_snds_M: muzzle_snds_H // Sound Suppressor 5.56mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=8;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
    class muzzle_snds_B: muzzle_snds_H // Sound Suppressor 7.62mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=12;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.2;
    };
};
