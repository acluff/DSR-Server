class CfgPatches
{
    class Desolation {units[] = {};};
};
class Plugins
{
    class Desolation
    {
        name = "Desolation Redux";
        desc = "ArmA 3 Zombie Survival Mod";
        tag = "DS";
    };
};

class CfgPluginActions {
    class Padlocks {
        text = "Unlock";
        Condition = "([_cursor] call DS_fnc_isUnlockable) || ([_cursor] call DS_fnc_isBuildingOwner)";
        
        class Actions {
            class Unlock {
                text = "Unlock";
                condition = "(_cursor getVariable ['bis_disabled_Door_1',1]) != 0";
                action = "createDialog 'DS_Padlock';";
                
            };
            class ChangeLock {
                text = "Reset lock";
                condition = "[_cursor] call DS_fnc_isBuildingOwner";
                action = "createDialog 'DS_Padlock'; call DS_fnc_initLockReset;";
            };
        };
    };
};

class CfgPluginEvents {
    class PlayerEvents {
        overrides = 1;
        class Events {
            class DS_InvTake {
                type = "Take";
                function = "DS_fnc_InvTake";
            };
            class DS_InvPut {
                type = "Put";
                function = "DS_fnc_InvPut";
            };
            class DS_AnimChanged {
                type = "AnimChanged";
                function = "DS_fnc_AnimChanged";
            };
            class DS_InventoryClosed {
                type = "InventoryClosed";
                function = "DS_fnc_InventoryClosed";
            };
            class DS_InventoryOpened {
                type = "InventoryOpened";
                function = "DS_fnc_InventoryOpened";
            };
            class DS_HandleDamage {
                type = "HandleDamage";
                function = "DS_fnc_HandleDamage";
            };
            class DS_Killed {
                type = "Killed";
                function = "DS_fnc_Killed";
            };
        };
    };
    class MissionEventsServer {
        overrides = 0;
        class Events {
            
        };
    };
    class MissionEventsClient {
        overrides = 1;
        class Events {
            class DS_Draw3D {
                type = "Draw3D";
                function = "DS_fnc_Draw3D";
            };
        };
    };
};

class CfgPluginKeybinds 
{
    class OpenJournalIndex 
    {
        displayName = "Open Building Journal";
        tooltip = "Open the journal containing buildables";
        tag = "DS";
        variable = "OpenBuildingJournal";
        defaultKeys[] = {{0x24,0}};
        code = "call DS_fnc_openJournal;";
    };
    class ToggleLight 
    {
        displayName = "Toggle Light";
        tooltip = "Turn camping light in hands on/off";
        tag = "DS";
        variable = "ToggleLight";
        defaultKeys[] = {{0x26,0}};
        code = "call DS_fnc_toggleLight;";
    };
};

class CfgFunctions
{
    class DS
    {
        class Client_Electric_Batteries {
            file = "Desolation\Client\Electric\Batteries";
            isclient = 1;
            class isBatteryInUse {};
            class usePowerCell {};
        };
        class Client_Electric_NVGoggles {
            file = "Desolation\Client\Electric\NVGoggles";
            isclient = 1;
            class initNVGs {};
            class canPowerNVG {};
        };
        class Client_Hands {
            file = "Desolation\Client\Hands";
            isclient = 1;
            class initHoldables {};
            class toggleLight {};
            class takeIntoHand {};
        };
        class Client_Progression {
            file = "Desolation\Client\Progression";
            isclient = 1;
            class addPoints {};
        };
        class Client_PluginEvents {
            file = "Desolation\Client\PluginEvents";
            isclient = 1;
            class Draw3D {};
            class InvTake {};
            class InvPut {};
            class AnimChanged {};
            class InventoryClosed {};
            class InventoryOpened {};
            class Killed {};
            class HandleDamage {};
        };
        class Client_Weapon {
            file = "Desolation\Client\Weapon";
            isclient = 1;
            class swingEvent {};
            class registerMeleeAction {};
        };
        class Client_Weapon_Events {
            file = "Desolation\Client\Weapon\Events";
            isclient = 1;
            class onSwing {};
        };
        class Client_Weapon_Network {
            file = "Desolation\Client\Weapon\Network";
            isclient = 1;
            class onMeleeHit {};
        };
        class Client_Actions_Vehicle {
            file = "Desolation\Client\Actions\Repair";
            isclient = 1;
            class removePart {};
            class repairPart {};
            class refuelVehicle {};
        };
        class Client_Crafting {
            file = "Desolation\Client\Crafting";
            isclient = 1;
            class onCraftClick {};
        };
        class Client_Building_Events {
            file = "Desolation\Client\Building\Events";
            isclient = 1;
            class onBuildClick {};
            class onBuildableLift {};
            class onPlacableLift {};
            class onCrateFilled {};
        };
        class Client_Building_PreviewHandling {
            file = "Desolation\Client\Building\PreviewHandling";
            isclient = 1;
            class liftBuildable {};
            class registerDropped {};
        };
        class Client_Building {
            file = "Desolation\Client\Building";
            isclient = 1;
            class initBuilding {};
            class registerOwner {};
        };
        class Client_Building_Locking {
            file = "Desolation\Client\Building\Locking";
            isclient = 1;
            class initLockReset {};
            class lockReset {};
            class unlock {};
        };
        class Client_Building_Locking_Checks {
            file = "Desolation\Client\Building\Locking\Checks";
            isclient = 1;
            class isBuildingOwner {};
            class isUnlockable {};
        };
        class Client_Spawning {
            file = "Desolation\Client\Spawning";
            isclient = 1;
            class findSpawnPosition {};
            class onRegionSelected {};
            class freshSpawn {};
            class finishSpawn {};
            class showRegionNotification {};
        };
        class Client_Events {
            file = "Desolation\Client\Events";
            isclient = 1;
            class registerPlayer {};
            class registerNewPlayer {};
        };
        class Client_Functions {
            file = "Desolation\Client\Functions";
            isclient = 1;
            class infoText {};
            class notWhitelisted {};
            class crashSmoke {};
            class receiveTransmition {};
            class calcGrayscale {};
            class getCfgValue {};
            class shuffleArray {};
            class handleCallback {};
            class genRandMapPos {};
        };
        class Client_Actions_System {
            file = "Desolation\Client\Actions\System";
            isclient = 1;
            class toggleActions {};
            class draw3DActions {};
            class get3DPartName {};
            class calculate3DActions {};
            class do3DAction {};
        };
        class Client_Actions_Items {
            file = "Desolation\Client\Actions\Items";
            isclient = 1;
            class doAction {};
            class convertAssign {};
            class convertItem {};
            class doActionTarget {};
            class combineMags {};
            class useItem {};
            class useItemTarget {};
            class drink {};
            class eat {};
            class fillblood {};
            class fillhcarbon {};
            class fillwater {};
            class lightfire {};
            class useantibiotic {};
            class usebandage {};
            class useblood {};
            class usedefib {};
            class usedisinfectant {};
            class usehandwarmer {};
            class usepainkillers {};
            class usevitamins {};
            class usewpt {};
            class usesplint {};
            class useCure {};
            class useImmune {};
        };
        class Client_Interface {
            file = "Desolation\Client\Interface";
            isclient = 1;
            class onEscape {};
            class initHud {};
            class openJournal {};
        };
        class Client {
            file = "Desolation\Client";
            isclient = 1;
            class initClient {};
        };
        class Client_Status {
            file = "Desolation\Client\Status";
            isclient = 1;
            class initHealthSys {};
            class onBleedTick {};
            class onBloodReceive {};
            class onDrink {};
            class onEat {};
            class onEffectTick {};
            class onInfectionTick {};
            class onHungerTick {};
            class onThirstTick {};
            class onUpdateTick {};
            class onTick {};
        };
        class Client_Medical {
            file = "Desolation\Client\Medical";
            isclient = 1;
            class knockOut {};
            class stopBleeding {};
        };
        class Client_Medical_Bleeding {
            file = "Desolation\Client\Medical\Bleeding";
            isclient = 1;
            class createBleedSource {};
            class initBleedingSystem {};
            class onHitPartReceived {};
            class removeAllBleedSources {};
            class updateBleedSource {};
        };
        class Client_Inventory {
            file = "Desolation\Client\Inventory";
            isclient = 1;
            class closeButtons {};
            class saveData {};
            class initInvHandler {};
            class itemClick {};
            class setupInvEvents {};
        };
        class Server_Actions_Vehicle {
            file = "Desolation\Server\actions\repair";
            isserver = 1;
            class removePartReq {};
            class repairPartReq {};
            class refuelReq {};
        };
        class Server_Database {
            file = "Desolation\Server\Database";
            isserver = 1;
            class dbRequest {};
            class dbOnSpawnResponse {};
        };
        class Server_Airdrop {
            file = "Desolation\Server\Airdrop";
            isserver = 1;
            class addCrateItems {};
            class DoDrop {};
            class initAirdrops {};
            class spawnCrate {};
            class genCrateItems {};
        };
        class Server_Events {
            file = "Desolation\Server\Events";
            isserver = 1;
            class onPlayerKilled {};
            class handleDisconnect {};
            class playerDisconnected {};
        };
        class Server_Players {
            file = "Desolation\Server\Players";
            isserver = 1;
            class requestLoadSpawn {};
            class requestFreshSpawn {};
            class requestSpawn {};
            class requestSave {};
            class setupLoadout {};
        };
        class Server_Loot {
            file = "Desolation\Server\Loot";
            isserver = 1;
            class lootManager {};
            class spawnLoot {};
            class setLoot {};
            class getLoot {};
            class despawnLoot {};
        };
        class Server_Audio {
            file = "Desolation\Server\Audio";
            isserver = 1;
            class playOverRadio {};
        };
        class Server_Crashes {
            file = "Desolation\Server\Crashes";
            isserver = 1;
            class spawnCrashes {};
            class spawnCrashLoot {};
            class initHeliCrashes {};
            class heliCrashAnim {};
        };
        class Server_Vehicles {
            file = "Desolation\Server\Vehicles";
            isserver = 1;
            class spawnVehicles {};
            class spawnFromDB {};
            class fixBuildingShift {};
            class vehicleMonitor {};
            class simManager {};
        };
        class Server_Crafting {
            file = "Desolation\Server\Crafting";
            isserver = 1;
            class initCraftingSys {};
        };
        class Server_Building_Events {
            file = "Desolation\Server\Building\Events";
            isserver = 1;
            class requestBuild {};
            class requestItemPlace {};
            class finishBuild {};
        };
        class Server_Building_PreviewHandling {
            file = "Desolation\Server\Building\PreviewHandling";
            isserver = 1;
            class buildableDropped {};
            class buildableLifted {};
        };
        class Server_Building {
            file = "Desolation\Server\Building";
            isserver = 1;
            class requestOwned {};
            class buildingMonitor {};
            class initBuildingSys {};
        };
        class Server_Locking {
            file = "Desolation\Server\Locking";
            isserver = 1;
            class checkServerLock {};
            class initLock {};
        };
        class Server {
            file = "Desolation\Server";
            isserver = 1;
            class initServer {};
        };
    };
};
class CfgHeliCrashes {
    class Settings {
        MinTimeBetweenCrashes = 5;
        MaxTimeBetweenCrashes = 20;
        NumberOfCrashesToSpawn = 5;
        MaxSearchDistance = 5000;
    };
    class CrashTypes {
        class Military {
            HeliClass = "RHS_UH1Y_UNARMED";
            WreckClass = "DSR_Object_Wreck4";
            WreckSmoke = 1;
            SpawnAltitude = 600;
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {4060.2971,2753.147},
                {3014.8438,12482.121},
                {7501.166,9649.7529},
                {10790.136,4316.1323}
            };
            
            class loot {
                maxLootpiles = 10;
                weapons[] = {
                    "rhs_weap_m107_w",
                    "rhs_weap_mk18_KAC_wd"
                };
                magazines[] = {
                    "rhs_mag_30Rnd_556x45_Mk262_Stanag",
                    "rhs_mag_30Rnd_556x45_Mk262_Stanag",
                    "rhs_mag_30Rnd_556x45_Mk262_Stanag",
                    "rhsusf_mag_10Rnd_STD_50BMG_M33",
                    "rhsusf_mag_10Rnd_STD_50BMG_mk211",
                    "DSR_Item_MRE",
                    "DSR_Item_Canteen_Full"
                };
                items[] = {
                    "rhs_uniform_FROG01_wd",
                    "tacs_Vest_PlateCarrier_MARPAT",
                    "rhsusf_mich_helmet_marpatwd_alt",
                    "mcu2p2_grey"
                };
                backpacks[] = {
                    "DSR_Coyote_Backpack"
                };
            };
        };
        class Military2 {
            HeliClass = "RHS_UH1Y_UNARMED";
            WreckClass = "DSR_Object_Wreck4";
            WreckSmoke = 1; 
            SpawnAltitude = 600;
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {4060.2971,2753.147},
                {3014.8438,12482.121},
                {7501.166,9649.7529},
                {10790.136,4316.1323}
            };
            
            class loot {
                maxLootpiles = 10;
                weapons[] = {
                    "rhs_weap_m4a1_m203s_wd",
                    "rhs_weap_m24sws_ghillie"
                };
                magazines[] = {
                    "rhs_mag_30Rnd_556x45_M855_Stanag",
                    "rhs_mag_30Rnd_556x45_M855_Stanag",
                    "rhs_mag_30Rnd_556x45_M855_Stanag",
                    "rhsusf_5Rnd_762x51_m993_Mag",
                    "rhsusf_5Rnd_762x51_m118_special_Mag",
                    "rhsusf_acc_M8541_low_wd",
                    "rhsusf_acc_harris_swivel",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bandage",
                    "DSR_Item_MRE"
                };
                items[] = {
                    "U_B_GhillieSuit",
                    "rhsusf_spcs_ocp",
                    "rhsusf_shemagh2_grn"
                };
                backpacks[] = {
                    "B_Carryall_khk"
                };
            };
        };
        class Military3 {
            HeliClass = "rhsgref_ins_Mi8amt";
            WreckClass = "Mi8Wreck";
            WreckSmoke = 1;
            SpawnAltitude = 600;
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {4060.2971,2753.147},
                {3014.8438,12482.121},
                {7501.166,9649.7529},
                {10790.136,4316.1323}
            };
            
            class loot {
                maxLootpiles = 10;
                weapons[] = {
                    "rhs_weap_pkp"
                };
                magazines[] = {
                    "rhs_100Rnd_762x54mmR",
                    "rhs_100Rnd_762x54mmR",
                    "rhs_100Rnd_762x54mmR_7N13",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bandage",
                    "DSR_Item_MRE"
                };
                items[] = {
                    "rhs_uniform_gorka_r_y",
                    "rhs_6b23_6sh116_od",
                    "rhs_altyn_visordown"
                };
                backpacks[] = {
                    "rhs_assault_umbts_engineer_empty"
                };
            };
        };
        class Military4 {
            HeliClass = "rhsgref_ins_Mi8amt";
            WreckClass = "Mi8Wreck";
            SpawnAltitude = 600;
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {4060.2971,2753.147},
                {3014.8438,12482.121},
                {7501.166,9649.7529},
                {10790.136,4316.1323}
            };
            
            class loot {
                maxLootpiles = 10;
                weapons[] = {
                    "rhs_weap_ak104_zenitco01_b33",
                    "rhs_weap_t5000"
                };
                magazines[] = {
                    "rhs_5Rnd_338lapua_t5000",
                    "rhs_5Rnd_338lapua_t5000",
                    "rhs_30Rnd_762x39mm_U",
                    "rhs_30Rnd_762x39mm",
                    "rhs_30Rnd_762x39mm",
                    "DSR_Item_MRE",
                    "rhs_acc_pbs1"
                };
                items[] = {
                    "rhsgref_uniform_para_ttsko_mountain",
                    "rhs_6b23_6sh116_od",
                    "rhs_6b7_1m_olive",
                    "rhs_scarf"
                };
                backpacks[] = {
                    "rhsgref_ttsko_alicepack"
                };
            };
        };
        
        class Medical {
            HeliClass = "RHS_Mi8amt_civilian";
            WreckClass = "Mi8Wreck";
            WreckSmoke = 1; //1 for true 0 for false!
            SpawnAltitude = 600;
            //particle effects config (size and origin)
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {2794.793,6132.3345},
                {12407.456,3987.5303},
                {11379.448,11809.968},
                {10190.923,2723.2224}
            };
            
            class loot {
                maxLootpiles = 10;//not implemented yet
                weapons[] = {

                };
                magazines[] = {
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Morphine",
                    "DSR_Item_Morphine",
                    "DSR_Item_Morphine",
                    "DSR_Item_Bandage",
                    "DSR_Item_Bandage",
                    "DSR_Item_Bandage",
                    "DSR_Item_Painkillers",
                    "DSR_Item_Painkillers",
                    "DSR_Item_Painkillers"
                };
                items[] = {
                };
                backpacks[] = {
                };
            };
        };
        class Medical2 {
            HeliClass = "RHS_Mi8amt_civilian";
            WreckClass = "Mi8Wreck";
            WreckSmoke = 1; //1 for true 0 for false!
            SpawnAltitude = 600;
            //particle effects config (size and origin)
            SmokePos[] = {0,0,0};
            SmokeSize = 7;
            Locations[] =
            {
                {2794.793,6132.3345},
                {12407.456,3987.5303},
                {11379.448,11809.968},
                {10190.923,2723.2224}
            };
            
            class loot {
                maxLootpiles = 10;//not implemented yet
                weapons[] = {

                };
                magazines[] = {
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Bloodbag_Full",
                    "DSR_Item_Morphine",
                    "DSR_Item_Morphine",
                    "DSR_Item_Bandage",
                    "DSR_Item_Bandage",
                    "DSR_Item_Bandage",
                    "DSR_Item_Painkillers",
                    "DSR_Item_Painkillers"
                };
                items[] = {
                };
                backpacks[] = {
                };
            };
        };
    };
};
class CfgAirdropSpawns {
    class MedicDrop {
        name = "Medical Drop";
        weapons[] = {
            
        };
        magazines[] = {
            "DSR_Item_Antibiotic",
            "DSR_Item_Bloodbag_Full",
            "DSR_Item_Bloodbag_Full",
            "DSR_Item_Bloodbag_Full",
            "DSR_Item_Bandage",
            "DSR_Item_Bandage",
            "DSR_Item_Bandage",
            "DSR_Item_Disinfectant",
            "DSR_Item_Painkillers",
            "DSR_Item_Painkillers"
        };
        items[] = {
            "FirstAidKit"
        };
        backpacks[] = {
            
        };
    };
    class AmmoDrop {
        name = "Ammunition Drop";
        weapons[] = {
            
        };
        magazines[] = {
            "rhs_30Rnd_762x39mm_U",
            "rhs_30Rnd_762x39mm_U",
            "rhs_30Rnd_762x39mm_U",
            "30Rnd_762x39_Magazine",
            "30Rnd_762x39_Magazine",
            "30Rnd_762x39_Magazine",
            "rhs_30Rnd_762x39mm",
            "rhs_30Rnd_762x39mm",
            "rhs_30Rnd_762x39mm",
            "rhs_30Rnd_545x39_7U1_AK",
            "rhs_30Rnd_545x39_7U1_AK",
            "rhs_30Rnd_545x39_7U1_AK",
            "rhs_30Rnd_545x39_AK",
            "rhs_30Rnd_545x39_AK",
            "rhs_30Rnd_545x39_AK",
            "rhs_10Rnd_762x54mmR_7N1",
            "rhs_mag_30Rnd_556x45_M855_Stanag",
            "rhs_mag_30Rnd_556x45_M855_Stanag",
            "rhs_mag_30Rnd_556x45_M855_Stanag",
            "rhs_mag_30Rnd_556x45_Mk262_Stanag",
            "20Rnd_762x51_Mag",
            "20Rnd_762x51_Mag",
            "20Rnd_762x51_Mag",
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag",
            "rhsusf_mag_17Rnd_9x19_JHP",
            "rhsusf_mag_17Rnd_9x19_JHP",
            "rhsusf_mag_17Rnd_9x19_FMJ",
            "rhs_mag_9x18_8_57N181S",
            "rhs_mag_9x18_8_57N181S",
            "rhs_mag_9x19_17",
            "rhs_mag_9x19_17"
        };
        items[] = {
            
        };
        backpacks[] = {
            
        };
    };
    class BuildingDrop {
        name = "Building Supplies Drop";
        weapons[] = {
            
        };
        magazines[] = {
            "DSR_Melee_Axe",
            "DSR_Melee_Axe",
            "DSR_Melee_Pickaxe",
            "DSR_Item_Bricks",
            "DSR_Item_Bricks",
            "DSR_Item_Toolbox",
            "DSR_Item_Saw",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Hardware",
            "DSR_Item_Scrap_Metal",
            "DSR_Item_Scrap_Metal",
            "DSR_Item_Scrap_Metal",
            "DSR_Item_Scrap_Metal",
            "DSR_Item_Padlock",
            "DSR_Item_Padlock",
            "DSR_Item_Padlock",
            "DSR_Item_Tarp",
            "DSR_Item_Tarp",
            "DSR_Item_Duct_Tape",
            "DSR_Item_Fabric_Scraps",
            "DSR_Item_Fabric_Scraps",
            "DSR_Item_Electrical_Comp",
            "DSR_Item_Engine_Block",
            "DSR_Item_Tire_RepairKit",
            "DSR_Item_Tire_RepairKit",
            "DSR_Item_Gascan_Small_Full",
            "DSR_Item_Wrench",
            "DSR_Item_Glass_Part",
            "DSR_Item_Glass_Part"
        };
        items[] = {
            
        };
        backpacks[] = {
            "DSR_Carryall_HKitty"
        };
    };
    class FoodDrop {
        name = "Food Supplies Drop";
        weapons[] = {
            
        };
        magazines[] = {
            "DSR_Item_Beans",
            "DSR_Item_Cereal",
            "DSR_Item_Powdered_Milk",
            "DSR_Item_Rice",
            "DSR_Item_Bacon",
            "DSR_Item_Waterbottle_Full",
            "DSR_Item_Canteen_Full",
            "DSR_Item_Spirit",
            "DSR_Item_Franta",
            "DSR_Item_Can_Opener",
            "DSR_Item_Water_Purification_Tablets",
            "DSR_Item_Vitamins"
        };
        items[] = {
            
        };
        backpacks[] = {
            
        };
    };
};
class CfgItemSpawns {
    buildingTypes[] = {"Military","Civilian","Industrial","Commercial","Medical","Mechanical"};
    lootRarity[] = {"rare","semirare","average","semicommon","common"};
    lootTypes[] = {"Weapon","Handgun","Magazine","Food","Drink","Medical","Junk","Backpack","Uniform","Vest","Helmet","Cosmetic","GeneralItem","Construction","Book","Electronic","CarPart","Attachment"};

    class Loot {
        class Military {
            class Weapon {
                //god tier navid spmg m320 fully auto 50rnd I0UHNFFJIBOOOOOOM BOOM BOOM NO SKILL RETARD
                rare[] = {
                    {"rhs_weap_m240G",10},            
                    {"rhs_weap_m249_pip_S_para",10},
                    {"rhsusf_acc_M2010S_sa",30},
                    {"rhs_weap_m107_w",15},
                    {"rhs_weap_t5000",15},
                    {"rhs_weap_pkp",10},
                    {"rhs_weap_m72a7",3}, 
                    {"rhs_weap_rpg7",3},           
                    {"rhs_weap_maaws",3}
                };
                //sniper rifle / high end
                semirare[] = {
                    {"rhs_weap_m24sws_ghillie",7},           
                    {"rhs_weap_mk18_KAC_wd",30},           
                    {"rhs_weap_m92",20},
                    {"bnae_trg42_virtual",5},
                    {"rhs_weap_m40a5_wd",15},   
                    {"bnae_falkor_snd_virtual",8},             
                    {"rhs_weap_m14ebrri",20}
                };
                //assault rifle
                average[] = {
                    {"rhs_weap_ak74m_plummag",9},  
                    {"rhs_weap_ak74m_zenitco01_b33",7},
                    {"rhs_weap_m16a4_carryhandle",8},
                    {"rhs_weap_mosin_sbr",5},
                    {"rhs_30Rnd_762x39mm_Savz58",8},
                    {"bnae_rk95_virtual",9},
                    {"rhs_weap_hk416d10_LMT_wd",7},
                    {"rhs_weap_ak104_zenitco01_b33",7},
                    {"rhs_weap_pm63",9},
                    {"rhs_weap_sr25_ec_wd",7},
                    {"rhs_weap_pm63",9},
                    {"rhs_weap_hk416d145_wd_2",7},
                    {"rhs_weap_m4a1_m203s_wd",7}
                };
                //smg
                semicommon[] = {
                    {"rhs_weap_savz61",34},           
                    {"rhsusf_weap_MP7A2_desert",33},
                    {"rhs_weap_pp2000",33}
                };
                //shotgun
                common[] = {
                    {"rhs_weap_M590_8RD",37},
                    {"rhs_weap_M590_5RD",38},
                    {"DSR_Melee_Axe",25}
                    
                };
            }; 
            class Handgun {
                rare[] = {
                    {"rhs_weap_pya",1}, 
                    {"bnae_r1_t_virtual",1}, 
                    {"rhs_weap_makarov_pm",1}, 
                    {"bnae_lrhs_weap_pb_6p935_c_virtual",1},           
                    {"bnae_saa_c_virtual",1},           
                    {"rhsusf_weap_glock17g4",1},
                    {"rhs_weap_pb_6p9",1},
                    {"rhs_weap_tt33",1},           
                    {"rhs_weap_pp2000_folded",1},           
                    {"bnae_saa_virtual",1}
                };
                semirare[] = {
                    {"rhs_weap_pya",1}, 
                    {"bnae_r1_t_virtual",1}, 
                    {"rhs_weap_makarov_pm",1}, 
                    {"bnae_lrhs_weap_pb_6p935_c_virtual",1},           
                    {"bnae_saa_c_virtual",1},           
                    {"rhsusf_weap_glock17g4",1},
                    {"rhs_weap_pb_6p9",1},
                    {"rhs_weap_tt33",1},           
                    {"rhs_weap_pp2000_folded",1},           
                    {"bnae_saa_virtual",1}
                };
                average[] = {
                    {"rhs_weap_pya",1}, 
                    {"bnae_r1_t_virtual",1}, 
                    {"rhs_weap_makarov_pm",1}, 
                    {"bnae_lrhs_weap_pb_6p935_c_virtual",1},           
                    {"bnae_saa_c_virtual",1},           
                    {"rhsusf_weap_glock17g4",1},
                    {"rhs_weap_pb_6p9",1},
                    {"rhs_weap_tt33",1},           
                    {"rhs_weap_pp2000_folded",1},           
                    {"bnae_saa_virtual",1}
                };
                semicommon[] = {
                    {"rhs_weap_pya",1}, 
                    {"bnae_r1_t_virtual",1}, 
                    {"rhs_weap_makarov_pm",1}, 
                    {"bnae_lrhs_weap_pb_6p935_c_virtual",1},           
                    {"bnae_saa_c_virtual",1},           
                    {"rhsusf_weap_glock17g4",1},
                    {"rhs_weap_pb_6p9",1},
                    {"rhs_weap_tt33",1},           
                    {"rhs_weap_pp2000_folded",1},           
                    {"bnae_saa_virtual",1}
                };
                common[] = {
                    {"rhs_weap_pya",1}, 
                    {"bnae_r1_t_virtual",1}, 
                    {"rhs_weap_makarov_pm",1}, 
                    {"bnae_lrhs_weap_pb_6p935_c_virtual",1},           
                    {"bnae_saa_c_virtual",1},           
                    {"rhsusf_weap_glock17g4",1},
                    {"rhs_weap_pb_6p9",1},
                    {"rhs_weap_tt33",1},           
                    {"rhs_weap_pp2000_folded",1},           
                    {"bnae_saa_virtual",1}
                };
            };
            class Magazine {
                rare[] = {
                    {"rhs_100Rnd_762x54mmR",1},
                    {"6Rnd_357M_Magazine",1},      
                    {"rhs_100Rnd_762x54mmR_7N13",1},
                    {"rhsusf_mag_40Rnd_46x30_FMJ",1},   
                    {"rhsusf_mag_40Rnd_46x30_JHP",1},
                    {"rhsusf_mag_40Rnd_46x30_AP",1},          
                    {"rhsusf_50Rnd_762x51",1},           
                    {"rhsusf_100Rnd_762x51",1},
                    {"rhsusf_5Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_5Rnd_762x51_m993_Mag",1},           
                    {"rhsusf_100Rnd_556x45_M855_soft_pouch",1},           
                    {"rhs_200rnd_556x45_B_SAW",1},
                    {"rhsusf_20Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_20Rnd_762x51_m993_Mag",1},
                    {"rhsgref_5Rnd_762x54_m38",1},                      
                    {"rhsgref_10Rnd_792x57_m76",1},           
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_M33",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_mk211",1},           
                    {"rhsusf_10Rnd_762x51_m118_special_Mag",1},           
                    {"rhs_5Rnd_338lapua_t5000",1},
                    {"rhs_30Rnd_762x39mm_U",1},
                    {"rhs_mag_30Rnd_556x45_Mk262_Stanag",1},
                    {"rhs_10Rnd_762x54mmR_7N1",1}, 
                    {"rhs_mag_m67",1},
                    {"rhs_mag_rdg2_white",1},
                    {"rhs_mag_plamyam",1},
                    {"rhs_mag_rgd5",1},
                    {"rhs_mag_rgn",1},
                    {"rhs_mag_rgo",1},
                    {"rhs_mag_zarya2",1},
                    {"rhs_mag_nspd",1},
                    {"rhs_mag_nspn_green",1},
                    {"rhs_mag_nspn_red",1},
                    {"rhs_mag_nspn_yellow",1},
                    {"rhs_mag_m7a3_cs",1},
                    {"rhs_mag_mk3a2",1},
                    {"rhs_mag_mk84",1},
                    {"rhs_mag_m18_yellow",1},
                    {"rhs_mag_m18_red",1},
                    {"rhs_mag_m18_purple",1},
                    {"rhs_mag_m18_green",1},
                    {"rhs_mag_an_m14_th3",1},
                    {"rhs_mag_an_m8hc",1},
                    {"rhs_mag_fakel",1},
                    {"rhs_mag_fakels",1},
                    {"rhsusf_m112x4_mag",1},
                    {"rhsusf_m112_mag",1},
                    {"APERSTripMine_Wire_Mag",1},
                    {"APERSMine_Range_Mag",1},
                    {"APERSBoundingMine_Range_Mag",1},
                    {"IEDLandBig_Remote_Mag",1},
                    {"IEDUrbanBig_Remote_Mag",1},
                    {"rhs_mine_tm62m_mag",1},
                    {"TrainingMine_Mag",1},
                    {"rhs_mag_mine_ptm1",1},
                    {"IEDLandSmall_Remote_Mag",1},
                    {"IEDUrbanSmall_Remote_Mag",1},
                    {"rhs_mag_mine_pfm1",1},
                    {"rhs_mine_pmn2_mag",1},
                    {"SLAMDirectionalMine_Wire_Mag",1},
                    {"rhs_mine_M19_mag",1},
                    {"rhsusf_mine_m14_mag",1},          
                    {"rhs_10rnd_9x39mm_SP5",1},          
                    {"rhs_mag_9x19_17",1},           
                    {"rhs_mag_9x18_8_57N181S",1},         
                    {"rhs_mag_9x19mm_7n21_44",1},
                    {"rhs_mag_9x19mm_7n31_44",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},
                    {"rhsusf_5Rnd_300winmag_xm2010",1},
                    {"rhs_m72a7_mag",1},
                    {"rhs_mag_762x25_8",1},
                    {"rhs_rpg7_PG7V_mag",1},
                    {"rhs_rpg7_OG7V_mag",1},
                    {"rhs_mag_maaws_HEAT",1},
                    {"rhs_mag_maaws_HEDP",1},
                    {"rhsusf_5Rnd_00Buck",1},
                    {"rhsusf_5Rnd_doomsday_Buck",1},
                    {"rhsusf_5Rnd_Slug",1},
                    {"10Rnd_300WM_Magazine",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"rhs_100Rnd_762x54mmR",1},
                    {"6Rnd_357M_Magazine",1},      
                    {"rhs_100Rnd_762x54mmR_7N13",1},
                    {"rhsusf_mag_40Rnd_46x30_FMJ",1},   
                    {"rhsusf_mag_40Rnd_46x30_JHP",1},
                    {"rhsusf_mag_40Rnd_46x30_AP",1},          
                    {"rhsusf_50Rnd_762x51",1},           
                    {"rhsusf_100Rnd_762x51",1},
                    {"rhsusf_5Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_5Rnd_762x51_m993_Mag",1},           
                    {"rhsusf_100Rnd_556x45_M855_soft_pouch",1},           
                    {"rhs_200rnd_556x45_B_SAW",1},
                    {"rhsusf_20Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_20Rnd_762x51_m993_Mag",1},
                    {"rhsgref_5Rnd_762x54_m38",1},                      
                    {"rhsgref_10Rnd_792x57_m76",1},           
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_M33",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_mk211",1},           
                    {"rhsusf_10Rnd_762x51_m118_special_Mag",1},           
                    {"rhs_5Rnd_338lapua_t5000",1},
                    {"rhs_30Rnd_762x39mm_U",1},
                    {"rhs_mag_30Rnd_556x45_Mk262_Stanag",1},
                    {"rhs_10Rnd_762x54mmR_7N1",1}, 
                    {"rhs_mag_m67",1},
                    {"rhs_mag_rdg2_white",1},
                    {"rhs_mag_plamyam",1},
                    {"rhs_mag_rgd5",1},
                    {"rhs_mag_rgn",1},
                    {"rhs_mag_rgo",1},
                    {"rhs_mag_zarya2",1},
                    {"rhs_mag_nspd",1},
                    {"rhs_mag_nspn_green",1},
                    {"rhs_mag_nspn_red",1},
                    {"rhs_mag_nspn_yellow",1},
                    {"rhs_mag_m7a3_cs",1},
                    {"rhs_mag_mk3a2",1},
                    {"rhs_mag_mk84",1},
                    {"rhs_mag_m18_yellow",1},
                    {"rhs_mag_m18_red",1},
                    {"rhs_mag_m18_purple",1},
                    {"rhs_mag_m18_green",1},
                    {"rhs_mag_an_m14_th3",1},
                    {"rhs_mag_an_m8hc",1},
                    {"rhs_mag_fakel",1},
                    {"rhs_mag_fakels",1},
                    {"rhsusf_m112x4_mag",1},
                    {"rhsusf_m112_mag",1},
                    {"APERSTripMine_Wire_Mag",1},
                    {"APERSMine_Range_Mag",1},
                    {"APERSBoundingMine_Range_Mag",1},
                    {"IEDLandBig_Remote_Mag",1},
                    {"IEDUrbanBig_Remote_Mag",1},
                    {"rhs_mine_tm62m_mag",1},
                    {"TrainingMine_Mag",1},
                    {"rhs_mag_mine_ptm1",1},
                    {"IEDLandSmall_Remote_Mag",1},
                    {"IEDUrbanSmall_Remote_Mag",1},
                    {"rhs_mag_mine_pfm1",1},
                    {"rhs_mine_pmn2_mag",1},
                    {"SLAMDirectionalMine_Wire_Mag",1},
                    {"rhs_mine_M19_mag",1},
                    {"rhsusf_mine_m14_mag",1},          
                    {"rhs_10rnd_9x39mm_SP5",1},          
                    {"rhs_mag_9x19_17",1},           
                    {"rhs_mag_9x18_8_57N181S",1},         
                    {"rhs_mag_9x19mm_7n21_44",1},
                    {"rhs_mag_9x19mm_7n31_44",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},
                    {"rhsusf_5Rnd_300winmag_xm2010",1},
                    {"rhs_m72a7_mag",1},
                    {"rhs_mag_762x25_8",1},
                    {"rhs_rpg7_PG7V_mag",1},
                    {"rhs_rpg7_OG7V_mag",1},
                    {"rhs_mag_maaws_HEAT",1},
                    {"rhs_mag_maaws_HEDP",1},
                    {"rhsusf_5Rnd_00Buck",1},
                    {"rhsusf_5Rnd_doomsday_Buck",1},
                    {"rhsusf_5Rnd_Slug",1},
                    {"10Rnd_300WM_Magazine",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"rhs_100Rnd_762x54mmR",1},
                    {"6Rnd_357M_Magazine",1},      
                    {"rhs_100Rnd_762x54mmR_7N13",1},
                    {"rhsusf_mag_40Rnd_46x30_FMJ",1},   
                    {"rhsusf_mag_40Rnd_46x30_JHP",1},
                    {"rhsusf_mag_40Rnd_46x30_AP",1},          
                    {"rhsusf_50Rnd_762x51",1},           
                    {"rhsusf_100Rnd_762x51",1},
                    {"rhsusf_5Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_5Rnd_762x51_m993_Mag",1},           
                    {"rhsusf_100Rnd_556x45_M855_soft_pouch",1},           
                    {"rhs_200rnd_556x45_B_SAW",1},
                    {"rhsusf_20Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_20Rnd_762x51_m993_Mag",1},
                    {"rhsgref_5Rnd_762x54_m38",1},                      
                    {"rhsgref_10Rnd_792x57_m76",1},           
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_M33",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_mk211",1},           
                    {"rhsusf_10Rnd_762x51_m118_special_Mag",1},           
                    {"rhs_5Rnd_338lapua_t5000",1},
                    {"rhs_30Rnd_762x39mm_U",1},
                    {"rhs_mag_30Rnd_556x45_Mk262_Stanag",1},
                    {"rhs_10Rnd_762x54mmR_7N1",1}, 
                    {"rhs_mag_m67",1},
                    {"rhs_mag_rdg2_white",1},
                    {"rhs_mag_plamyam",1},
                    {"rhs_mag_rgd5",1},
                    {"rhs_mag_rgn",1},
                    {"rhs_mag_rgo",1},
                    {"rhs_mag_zarya2",1},
                    {"rhs_mag_nspd",1},
                    {"rhs_mag_nspn_green",1},
                    {"rhs_mag_nspn_red",1},
                    {"rhs_mag_nspn_yellow",1},
                    {"rhs_mag_m7a3_cs",1},
                    {"rhs_mag_mk3a2",1},
                    {"rhs_mag_mk84",1},
                    {"rhs_mag_m18_yellow",1},
                    {"rhs_mag_m18_red",1},
                    {"rhs_mag_m18_purple",1},
                    {"rhs_mag_m18_green",1},
                    {"rhs_mag_an_m14_th3",1},
                    {"rhs_mag_an_m8hc",1},
                    {"rhs_mag_fakel",1},
                    {"rhs_mag_fakels",1},
                    {"rhsusf_m112x4_mag",1},
                    {"rhsusf_m112_mag",1},
                    {"APERSTripMine_Wire_Mag",1},
                    {"APERSMine_Range_Mag",1},
                    {"APERSBoundingMine_Range_Mag",1},
                    {"IEDLandBig_Remote_Mag",1},
                    {"IEDUrbanBig_Remote_Mag",1},
                    {"rhs_mine_tm62m_mag",1},
                    {"TrainingMine_Mag",1},
                    {"rhs_mag_mine_ptm1",1},
                    {"IEDLandSmall_Remote_Mag",1},
                    {"IEDUrbanSmall_Remote_Mag",1},
                    {"rhs_mag_mine_pfm1",1},
                    {"rhs_mine_pmn2_mag",1},
                    {"SLAMDirectionalMine_Wire_Mag",1},
                    {"rhs_mine_M19_mag",1},
                    {"rhsusf_mine_m14_mag",1},          
                    {"rhs_10rnd_9x39mm_SP5",1},          
                    {"rhs_mag_9x19_17",1},           
                    {"rhs_mag_9x18_8_57N181S",1},         
                    {"rhs_mag_9x19mm_7n21_44",1},
                    {"rhs_mag_9x19mm_7n31_44",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},
                    {"rhsusf_5Rnd_300winmag_xm2010",1},
                    {"rhs_m72a7_mag",1},
                    {"rhs_mag_762x25_8",1},
                    {"rhs_rpg7_PG7V_mag",1},
                    {"rhs_rpg7_OG7V_mag",1},
                    {"rhs_mag_maaws_HEAT",1},
                    {"rhs_mag_maaws_HEDP",1},
                    {"rhsusf_5Rnd_00Buck",1},
                    {"rhsusf_5Rnd_doomsday_Buck",1},
                    {"rhsusf_5Rnd_Slug",1},
                    {"10Rnd_300WM_Magazine",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"rhs_100Rnd_762x54mmR",1},
                    {"6Rnd_357M_Magazine",1},      
                    {"rhs_100Rnd_762x54mmR_7N13",1},
                    {"rhsusf_mag_40Rnd_46x30_FMJ",1},   
                    {"rhsusf_mag_40Rnd_46x30_JHP",1},
                    {"rhsusf_mag_40Rnd_46x30_AP",1},          
                    {"rhsusf_50Rnd_762x51",1},           
                    {"rhsusf_100Rnd_762x51",1},
                    {"rhsusf_5Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_5Rnd_762x51_m993_Mag",1},           
                    {"rhsusf_100Rnd_556x45_M855_soft_pouch",1},           
                    {"rhs_200rnd_556x45_B_SAW",1},
                    {"rhsusf_20Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_20Rnd_762x51_m993_Mag",1},
                    {"rhsgref_5Rnd_762x54_m38",1},                      
                    {"rhsgref_10Rnd_792x57_m76",1},           
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_M33",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_mk211",1},           
                    {"rhsusf_10Rnd_762x51_m118_special_Mag",1},           
                    {"rhs_5Rnd_338lapua_t5000",1},
                    {"rhs_30Rnd_762x39mm_U",1},
                    {"rhs_mag_30Rnd_556x45_Mk262_Stanag",1},
                    {"rhs_10Rnd_762x54mmR_7N1",1}, 
                    {"rhs_mag_m67",1},
                    {"rhs_mag_rdg2_white",1},
                    {"rhs_mag_plamyam",1},
                    {"rhs_mag_rgd5",1},
                    {"rhs_mag_rgn",1},
                    {"rhs_mag_rgo",1},
                    {"rhs_mag_zarya2",1},
                    {"rhs_mag_nspd",1},
                    {"rhs_mag_nspn_green",1},
                    {"rhs_mag_nspn_red",1},
                    {"rhs_mag_nspn_yellow",1},
                    {"rhs_mag_m7a3_cs",1},
                    {"rhs_mag_mk3a2",1},
                    {"rhs_mag_mk84",1},
                    {"rhs_mag_m18_yellow",1},
                    {"rhs_mag_m18_red",1},
                    {"rhs_mag_m18_purple",1},
                    {"rhs_mag_m18_green",1},
                    {"rhs_mag_an_m14_th3",1},
                    {"rhs_mag_an_m8hc",1},
                    {"rhs_mag_fakel",1},
                    {"rhs_mag_fakels",1},
                    {"rhsusf_m112x4_mag",1},
                    {"rhsusf_m112_mag",1},
                    {"APERSTripMine_Wire_Mag",1},
                    {"APERSMine_Range_Mag",1},
                    {"APERSBoundingMine_Range_Mag",1},
                    {"IEDLandBig_Remote_Mag",1},
                    {"IEDUrbanBig_Remote_Mag",1},
                    {"rhs_mine_tm62m_mag",1},
                    {"TrainingMine_Mag",1},
                    {"rhs_mag_mine_ptm1",1},
                    {"IEDLandSmall_Remote_Mag",1},
                    {"IEDUrbanSmall_Remote_Mag",1},
                    {"rhs_mag_mine_pfm1",1},
                    {"rhs_mine_pmn2_mag",1},
                    {"SLAMDirectionalMine_Wire_Mag",1},
                    {"rhs_mine_M19_mag",1},
                    {"rhsusf_mine_m14_mag",1},          
                    {"rhs_10rnd_9x39mm_SP5",1},          
                    {"rhs_mag_9x19_17",1},           
                    {"rhs_mag_9x18_8_57N181S",1},         
                    {"rhs_mag_9x19mm_7n21_44",1},
                    {"rhs_mag_9x19mm_7n31_44",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},
                    {"rhsusf_5Rnd_300winmag_xm2010",1},
                    {"rhs_m72a7_mag",1},
                    {"rhs_mag_762x25_8",1},
                    {"rhs_rpg7_PG7V_mag",1},
                    {"rhs_rpg7_OG7V_mag",1},
                    {"rhs_mag_maaws_HEAT",1},
                    {"rhs_mag_maaws_HEDP",1},
                    {"rhsusf_5Rnd_00Buck",1},
                    {"rhsusf_5Rnd_doomsday_Buck",1},
                    {"rhsusf_5Rnd_Slug",1},
                    {"10Rnd_300WM_Magazine",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"rhs_100Rnd_762x54mmR",1},
                    {"6Rnd_357M_Magazine",1},      
                    {"rhs_100Rnd_762x54mmR_7N13",1},
                    {"rhsusf_mag_40Rnd_46x30_FMJ",1},   
                    {"rhsusf_mag_40Rnd_46x30_JHP",1},
                    {"rhsusf_mag_40Rnd_46x30_AP",1},          
                    {"rhsusf_50Rnd_762x51",1},           
                    {"rhsusf_100Rnd_762x51",1},
                    {"rhsusf_5Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_5Rnd_762x51_m993_Mag",1},           
                    {"rhsusf_100Rnd_556x45_M855_soft_pouch",1},           
                    {"rhs_200rnd_556x45_B_SAW",1},
                    {"rhsusf_20Rnd_762x51_m118_special_Mag",1},
                    {"rhsusf_20Rnd_762x51_m993_Mag",1},
                    {"rhsgref_5Rnd_762x54_m38",1},                      
                    {"rhsgref_10Rnd_792x57_m76",1},           
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_M33",1},
                    {"rhsusf_mag_10Rnd_STD_50BMG_mk211",1},           
                    {"rhsusf_10Rnd_762x51_m118_special_Mag",1},           
                    {"rhs_5Rnd_338lapua_t5000",1},
                    {"rhs_30Rnd_762x39mm_U",1},
                    {"rhs_mag_30Rnd_556x45_Mk262_Stanag",1},
                    {"rhs_10Rnd_762x54mmR_7N1",1}, 
                    {"rhs_mag_m67",1},
                    {"rhs_mag_rdg2_white",1},
                    {"rhs_mag_plamyam",1},
                    {"rhs_mag_rgd5",1},
                    {"rhs_mag_rgn",1},
                    {"rhs_mag_rgo",1},
                    {"rhs_mag_zarya2",1},
                    {"rhs_mag_nspd",1},
                    {"rhs_mag_nspn_green",1},
                    {"rhs_mag_nspn_red",1},
                    {"rhs_mag_nspn_yellow",1},
                    {"rhs_mag_m7a3_cs",1},
                    {"rhs_mag_mk3a2",1},
                    {"rhs_mag_mk84",1},
                    {"rhs_mag_m18_yellow",1},
                    {"rhs_mag_m18_red",1},
                    {"rhs_mag_m18_purple",1},
                    {"rhs_mag_m18_green",1},
                    {"rhs_mag_an_m14_th3",1},
                    {"rhs_mag_an_m8hc",1},
                    {"rhs_mag_fakel",1},
                    {"rhs_mag_fakels",1},
                    {"rhsusf_m112x4_mag",1},
                    {"rhsusf_m112_mag",1},
                    {"APERSTripMine_Wire_Mag",1},
                    {"APERSMine_Range_Mag",1},
                    {"APERSBoundingMine_Range_Mag",1},
                    {"IEDLandBig_Remote_Mag",1},
                    {"IEDUrbanBig_Remote_Mag",1},
                    {"rhs_mine_tm62m_mag",1},
                    {"TrainingMine_Mag",1},
                    {"rhs_mag_mine_ptm1",1},
                    {"IEDLandSmall_Remote_Mag",1},
                    {"IEDUrbanSmall_Remote_Mag",1},
                    {"rhs_mag_mine_pfm1",1},
                    {"rhs_mine_pmn2_mag",1},
                    {"SLAMDirectionalMine_Wire_Mag",1},
                    {"rhs_mine_M19_mag",1},
                    {"rhsusf_mine_m14_mag",1},          
                    {"rhs_10rnd_9x39mm_SP5",1},          
                    {"rhs_mag_9x19_17",1},           
                    {"rhs_mag_9x18_8_57N181S",1},         
                    {"rhs_mag_9x19mm_7n21_44",1},
                    {"rhs_mag_9x19mm_7n31_44",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},
                    {"rhsusf_5Rnd_300winmag_xm2010",1},
                    {"rhs_m72a7_mag",1},
                    {"rhs_mag_762x25_8",1},
                    {"rhs_rpg7_PG7V_mag",1},
                    {"rhs_rpg7_OG7V_mag",1},
                    {"rhs_mag_maaws_HEAT",1},
                    {"rhs_mag_maaws_HEDP",1},
                    {"rhsusf_5Rnd_00Buck",1},
                    {"rhsusf_5Rnd_doomsday_Buck",1},
                    {"rhsusf_5Rnd_Slug",1},
                    {"10Rnd_300WM_Magazine",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {          
                    {"DSR_Alice_Backpack",1},
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Coyote_Backpack",1},           
                    {"DSR_Czech_Camo",1},           
                    {"DSR_Largegunbag",1},
                    {"DSR_Medical_Backpack",1},          
                    {"tacs_Backpack_Carryall_DarkBlack",1},           
                    {"tacs_Backpack_Kitbag_DarkBlack",1},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"rhs_assault_umbts_engineer_empty",1},
                    {"rhs_medic_bag",1},
                    {"rhs_rpg_empty",1},
                    {"rhs_sidor",1},
                    {"rhsgref_ttsko_alicepack",1},
                    {"B_Kitbag_rgr",1},
                    {"B_FieldPack_oli",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_cbr",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Alice_Backpack",1},
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Coyote_Backpack",1},           
                    {"DSR_Czech_Camo",1},           
                    {"DSR_Largegunbag",1},
                    {"DSR_Medical_Backpack",1},         
                    {"tacs_Backpack_Carryall_DarkBlack",1},           
                    {"tacs_Backpack_Kitbag_DarkBlack",1},
                    {"B_Carryall_cbr",1},
                    {"rhs_medic_bag",1},           
                    {"B_Carryall_khk",1},           
                    {"rhs_rpg_empty",1},
                    {"rhs_sidor",1},
                    {"rhsgref_ttsko_alicepack",1},
                    {"B_FieldPack_oli",1},           
                    {"rhs_assault_umbts_engineer_empty",1},           
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_rgr",1},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Alice_Backpack",1},
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},         
                    {"tacs_Backpack_Kitbag_DarkBlack",1},
                    {"B_FieldPack_cbr",1},
                    {"B_FieldPack_oli",1},           
                    {"B_HuntingBackpack",1},           
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_rgr",1},           
                    {"rhs_medic_bag",1},           
                    {"rhs_rpg_empty",1},
                    {"rhs_sidor",1},
                    {"rhsgref_ttsko_alicepack",1},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Alice_Backpack",1},
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},         
                    {"tacs_Backpack_Kitbag_DarkBlack",1},
                    {"B_FieldPack_cbr",1},
                    {"B_FieldPack_oli",1},             
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_rgr",1},           
                    {"rhs_medic_bag",1},           
                    {"rhs_rpg_empty",1},
                    {"rhs_sidor",1},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Alice_Backpack",1},
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},           
                    {"tacs_Backpack_Kitbag_DarkBlack",1},
                    {"B_FieldPack_cbr",1},
                    {"B_FieldPack_oli",1},              
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_rgr",1},           
                    {"rhs_medic_bag",1},           
                    {"rhs_rpg_empty",1},
                    {"rhs_sidor",1},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"rhsgref_uniform_para_ttsko_mountain",1},           
                    {"rhsgref_uniform_ttsko_forest",1},           
                    {"rhsgref_uniform_woodland_olive",1},
                    {"rhs_uniform_msv_patchless",1},           
                    {"rhs_uniform_m88_patchless",1},           
                    {"rhs_uniform_gorka_r_y",1},
                    {"rhs_uniform_g3_m81",1},
                    {"rhs_uniform_g3_rgr",1},           
                    {"rhs_uniform_cu_ocp",1},           
                    {"rhs_uniform_FROG01_wd",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_C_WorkerCoveralls",1},
                    {"U_B_GhillieSuit",1}
                };
                semirare[] = {
                    {"rhsgref_uniform_para_ttsko_mountain",1},           
                    {"rhsgref_uniform_ttsko_forest",1},           
                    {"rhsgref_uniform_woodland_olive",1},
                    {"rhs_uniform_emr_patchless",1},           
                    {"rhs_uniform_m88_patchless",1},
                    {"rhs_uniform_gorka_r_y",1},
                    {"rhs_uniform_g3_m81",1},
                    {"rhs_uniform_g3_rgr",1},           
                    {"rhs_uniform_cu_ocp",1}, 
                    {"U_BG_Guerilla3_1",1},           
                    {"U_C_WorkerCoveralls",1},          
                    {"rhs_uniform_FROG01_wd",1}
                };
                average[] = {
                    {"rhsgref_uniform_para_ttsko_mountain",1},           
                    {"rhsgref_uniform_ttsko_forest",1},           
                    {"rhsgref_uniform_woodland_olive",1},
                    {"rhs_uniform_emr_patchless",1},           
                    {"rhs_uniform_m88_patchless",1},       
                    {"rhs_uniform_cu_ocp",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_C_WorkerCoveralls",1},           
                    {"rhs_uniform_FROG01_wd",1}
                };
                semicommon[] = {
                    {"rhsgref_uniform_para_ttsko_mountain",1},           
                    {"rhsgref_uniform_ttsko_forest",1},           
                    {"rhsgref_uniform_woodland_olive",1},
                    {"rhs_uniform_emr_patchless",1},           
                    {"rhs_uniform_m88_patchless",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_C_WorkerCoveralls",1}
                };
                common[] = {
                    {"rhsgref_uniform_para_ttsko_mountain",1},           
                    {"rhsgref_uniform_ttsko_forest",1},           
                    {"rhsgref_uniform_woodland_olive",1},
                    {"rhs_uniform_m88_patchless",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_C_WorkerCoveralls",1}
                };
            };
            class Vest {
                rare[] = {
                    {"rhs_6b23_6sh116_od",1},           
                    {"rhs_vydra_3m",1},           
                    {"rhs_6sh92_digi",1},
                    {"rhsusf_iotv_ocp_Rifleman",1},
                    {"rhsusf_spcs_ocp_rifleman",1},           
                    {"rhsusf_spc_patchless",1},           
                    {"rhsusf_mbav_light",1},
                    {"V_TacVestIR_blk",1},           
                    {"V_HarnessO_brn",1},           
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_khk",1},
                    {"V_TacVest_camo",1},           
                    {"V_Press_F",1},           
                    {"V_TacVest_blk_POLICE",1},          
                    {"tacs_Vest_PlateCarrier_MARPAT",1},           
                    {"tacs_Vest_PlateCarrier_khaki",1}
                };
                semirare[] = {
                    {"rhs_6b23_6sh116_od",1},  
                    {"rhs_6b23_digi_vydra_3m",1},         
                    {"rhs_vydra_3m",1},           
                    {"rhs_6sh92_digi",1},           
                    {"rhsusf_spc_patchless",1},           
                    {"rhsusf_mbav_light",1},
                    {"V_TacVestIR_blk",1},           
                    {"V_HarnessO_brn",1},           
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_khk",1},
                    {"V_TacVest_camo",1},           
                    {"V_Press_F",1},           
                    {"V_TacVest_blk_POLICE",1},          
                    {"tacs_Vest_PlateCarrier_MARPAT",1},           
                    {"tacs_Vest_PlateCarrier_khaki",1}
                };
                average[] = {
                    {"rhs_6b23_6sh116_od",1},  
                    {"rhs_6b23_digi_vydra_3m",1},         
                    {"rhs_vydra_3m",1},           
                    {"rhs_6sh92_digi",1},           
                    {"V_HarnessO_brn",1},           
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_khk",1},
                    {"V_TacVest_camo",1},           
                    {"V_Press_F",1},           
                    {"V_TacVest_blk_POLICE",1}
                };
                semicommon[] = {
                    {"rhs_vydra_3m",1},           
                    {"rhs_6sh92_digi",1},           
                    {"V_HarnessO_brn",1},           
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_khk",1},
                    {"V_TacVest_camo",1},           
                    {"V_Press_F",1},           
                    {"V_TacVest_blk_POLICE",1}
                };
                common[] = {,           
                    {"V_Rangemaster_belt",1},       
                    {"V_TacVest_blk_POLICE",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"rhsgref_helmet_M1_painted_alt01",1},
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},          
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_khaki_usblack",1},
                    {"H_Cap_khaki_specops_US",1},
                    {"H_ShemagOpen_tan",1},           
                    {"H_ShemagOpen_olive",1},
                    {"rhs_6b7_1m_olive",1},           
                    {"rhs_6b27m_digi",1},           
                    {"rhs_altyn_visordown",1},
                    {"rhs_beanie_green",1},
                    {"rhs_fieldcap_khk",1},           
                    {"rhs_fieldcap_digi2",1},           
                    {"rhsusf_hgu56p_visor_mask_green_mo",1},
                    {"rhsusf_hgu56p_visor_mask_skull",1},
                    {"rhsusf_hgu56p_visor_mask_smiley",1},           
                    {"rhsusf_ach_helmet_ocp",1},           
                    {"rhsusf_opscore_rg_cover",1},
                    {"rhsusf_opscore_mc",1},
                    {"rhsusf_mich_helmet_marpatwd_alt",1},
                    {"rhsusf_patrolcap_ocp",1},           
                    {"rhs_8point_marpatwd",1},
                    {"rhsusf_opscore_paint",1},           
                    {"tacs_Helmet_Ballistic_DarkBlack",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},
                    {"tacs_Hat_Boonie_UCP",1},           
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"rhsgref_helmet_M1_painted_alt01",1},
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},           
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_khaki_usblack",1},
                    {"H_Cap_khaki_specops_US",1},
                    {"H_ShemagOpen_tan",1},           
                    {"H_ShemagOpen_olive",1},
                    {"rhs_6b7_1m_olive",1},           
                    {"rhs_6b27m_digi",1},
                    {"rhs_beanie_green",1},
                    {"rhs_fieldcap_khk",1},           
                    {"rhs_fieldcap_digi2",1},           
                    {"rhsusf_ach_helmet_ocp",1},           
                    {"rhsusf_opscore_rg_cover",1},
                    {"rhsusf_opscore_mc",1},
                    {"rhsusf_mich_helmet_marpatwd_alt",1},
                    {"rhsusf_patrolcap_ocp",1},           
                    {"rhs_8point_marpatwd",1},
                    {"rhsusf_opscore_paint",1},           
                    {"tacs_Helmet_Ballistic_DarkBlack",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},
                    {"tacs_Hat_Boonie_UCP",1},           
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"rhsgref_helmet_M1_painted_alt01",1},
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},           
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_khaki_usblack",1},
                    {"H_Cap_khaki_specops_US",1},
                    {"H_ShemagOpen_tan",1},           
                    {"H_ShemagOpen_olive",1},
                    {"rhs_6b7_1m_olive",1},           
                    {"rhs_6b27m_digi",1},
                    {"rhs_beanie_green",1},
                    {"rhs_fieldcap_khk",1},           
                    {"rhs_fieldcap_digi2",1},           
                    {"rhsusf_ach_helmet_ocp",1}, 
                    {"rhsusf_mich_helmet_marpatwd_alt",1},
                    {"rhsusf_patrolcap_ocp",1},           
                    {"rhs_8point_marpatwd",1},           
                    {"tacs_Helmet_Ballistic_DarkBlack",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},
                    {"tacs_Hat_Boonie_UCP",1},           
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"rhsgref_helmet_M1_painted_alt01",1},
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},           
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_khaki_usblack",1},
                    {"H_Cap_khaki_specops_US",1},
                    {"H_ShemagOpen_tan",1},           
                    {"H_ShemagOpen_olive",1},
                    {"rhs_6b7_1m_olive",1},           
                    {"rhs_6b27m_digi",1},
                    {"rhs_beanie_green",1},
                    {"rhs_fieldcap_khk",1},           
                    {"rhs_fieldcap_digi2",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"rhsgref_helmet_M1_painted_alt01",1},
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},           
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_khaki_usblack",1},
                    {"H_Cap_khaki_specops_US",1},
                    {"H_ShemagOpen_tan",1},           
                    {"H_ShemagOpen_olive",1},
                    {"rhs_beanie_green",1},
                    {"rhs_fieldcap_khk",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},          
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"rhsgref_sdn6_suppressor",1},          
                    {"rhsusf_acc_rotex_mp7_desert",1},          
                    {"bnae_holder_virtual",1}, 
                    {"bnae_scope_snd_virtual",1},
                    {"bnae_bipod_snd_virtual",1},            
                    {"rhsusf_acc_M8541_low_wd",1},           
                    {"rhsusf_acc_M952V",1},
                    {"rhs_acc_tgpa",1},
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},          
                    {"rhsusf_acc_T1_low_fwd",1},           
                    {"rhsusf_acc_harris_bipod",1},
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},           
                    {"rhsusf_acc_rotex5_grey",1},
                    {"rhs_acc_1p29",1},
                    {"rhs_acc_1p63",1},            
                    {"rhs_acc_tgpa",1},           
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},
                    {"rhsusf_acc_T1_low_fwd",1},
                    {"rhsusf_acc_harris_bipod",1},          
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},
                    {"rhsusf_acc_rotex5_grey",1},           
                    {"rhs_acc_1p29",1},           
                    {"rhs_acc_1p63",1},
                    {"rhs_acc_1p78",1},
                    {"rhs_acc_ekp1",1},            
                    {"rhs_acc_pbs1",1},           
                    {"rhs_acc_2dpZenit_ris",1},
                    {"rhs_acc_rakursPM",1},
                    {"rhs_acc_2dpZenit",1},
                    {"rhs_acc_1p87",1},
                    {"rhs_acc_perst1ik",1},          
                    {"rhs_acc_tgpv",1},           
                    {"rhs_acc_dh520x56",1},
                    {"rhs_acc_ekp8_18",1},           
                    {"rhs_acc_ekp8_02",1},           
                    {"rhs_acc_pso1m21",1},
                    {"rhs_acc_pso1m2",1},
                    {"rhs_acc_pkas",1},            
                    {"rhsusf_acc_ELCAN",1},           
                    {"rhsusf_acc_eotech_552_wd",1},
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1},
                    {"rhsusf_acc_SpecterDR_od",1},
                    {"rhsusf_acc_ACOG_MDO",1},          
                    {"rhsusf_acc_ACOG_RMR",1},           
                    {"rhsusf_acc_EOTECH_xps3",1},
                    {"bnae_suppressor_covblk_virtual",1},           
                    {"bnae_muzzle_blk_virtual",1},           
                    {"bnae_scope_blk_virtual",1},
                    {"bnae_bipod_v2_virtual",1},
                    {"rhsusf_acc_omega9k",1},
                    {"acc_flashlight_pistol",1},
                    {"bnae_suppressor_v3_virtual",1},
                    {"bnae_suppressor_v4_virtual",1},
                    {"bnae_reddot_virtual",1},
                    {"rhs_acc_6p9_suppressor",1},
                    {"DSR_optic_Kobra_green",1}
                };
                semirare[] = {
                    {"rhsgref_sdn6_suppressor",1},          
                    {"rhsusf_acc_rotex_mp7_desert",1},          
                    {"bnae_holder_virtual",1}, 
                    {"bnae_scope_snd_virtual",1},
                    {"bnae_bipod_snd_virtual",1},            
                    {"rhsusf_acc_M8541_low_wd",1},           
                    {"rhsusf_acc_M952V",1},
                    {"rhs_acc_tgpa",1},
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},          
                    {"rhsusf_acc_T1_low_fwd",1},           
                    {"rhsusf_acc_harris_bipod",1},
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},           
                    {"rhsusf_acc_rotex5_grey",1},
                    {"rhs_acc_1p29",1},
                    {"rhs_acc_1p63",1},            
                    {"rhs_acc_tgpa",1},           
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},
                    {"rhsusf_acc_T1_low_fwd",1},
                    {"rhsusf_acc_harris_bipod",1},          
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},
                    {"rhsusf_acc_rotex5_grey",1},           
                    {"rhs_acc_1p29",1},           
                    {"rhs_acc_1p63",1},
                    {"rhs_acc_1p78",1},
                    {"rhs_acc_ekp1",1},            
                    {"rhs_acc_pbs1",1},           
                    {"rhs_acc_2dpZenit_ris",1},
                    {"rhs_acc_rakursPM",1},
                    {"rhs_acc_2dpZenit",1},
                    {"rhs_acc_1p87",1},
                    {"rhs_acc_perst1ik",1},          
                    {"rhs_acc_tgpv",1},           
                    {"rhs_acc_dh520x56",1},
                    {"rhs_acc_ekp8_18",1},           
                    {"rhs_acc_ekp8_02",1},           
                    {"rhs_acc_pso1m21",1},
                    {"rhs_acc_pso1m2",1},
                    {"rhs_acc_pkas",1},            
                    {"rhsusf_acc_ELCAN",1},           
                    {"rhsusf_acc_eotech_552_wd",1},
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1},
                    {"rhsusf_acc_SpecterDR_od",1},
                    {"rhsusf_acc_ACOG_MDO",1},          
                    {"rhsusf_acc_ACOG_RMR",1},           
                    {"rhsusf_acc_EOTECH_xps3",1},
                    {"bnae_suppressor_covblk_virtual",1},           
                    {"bnae_muzzle_blk_virtual",1},           
                    {"bnae_scope_blk_virtual",1},
                    {"bnae_bipod_v2_virtual",1},
                    {"rhsusf_acc_omega9k",1},
                    {"acc_flashlight_pistol",1},
                    {"bnae_suppressor_v3_virtual",1},
                    {"bnae_suppressor_v4_virtual",1},
                    {"bnae_reddot_virtual",1},
                    {"rhs_acc_6p9_suppressor",1},
                    {"DSR_optic_Kobra_green",1}
                };
                average[] = {
                    {"rhsgref_sdn6_suppressor",1},          
                    {"rhsusf_acc_rotex_mp7_desert",1},          
                    {"bnae_holder_virtual",1}, 
                    {"bnae_scope_snd_virtual",1},
                    {"bnae_bipod_snd_virtual",1},            
                    {"rhsusf_acc_M8541_low_wd",1},           
                    {"rhsusf_acc_M952V",1},
                    {"rhs_acc_tgpa",1},
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},          
                    {"rhsusf_acc_T1_low_fwd",1},           
                    {"rhsusf_acc_harris_bipod",1},
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},           
                    {"rhsusf_acc_rotex5_grey",1},
                    {"rhs_acc_1p29",1},
                    {"rhs_acc_1p63",1},            
                    {"rhs_acc_tgpa",1},           
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},
                    {"rhsusf_acc_T1_low_fwd",1},
                    {"rhsusf_acc_harris_bipod",1},          
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},
                    {"rhsusf_acc_rotex5_grey",1},           
                    {"rhs_acc_1p29",1},           
                    {"rhs_acc_1p63",1},
                    {"rhs_acc_1p78",1},
                    {"rhs_acc_ekp1",1},            
                    {"rhs_acc_pbs1",1},           
                    {"rhs_acc_2dpZenit_ris",1},
                    {"rhs_acc_rakursPM",1},
                    {"rhs_acc_2dpZenit",1},
                    {"rhs_acc_1p87",1},
                    {"rhs_acc_perst1ik",1},          
                    {"rhs_acc_tgpv",1},           
                    {"rhs_acc_dh520x56",1},
                    {"rhs_acc_ekp8_18",1},           
                    {"rhs_acc_ekp8_02",1},           
                    {"rhs_acc_pso1m21",1},
                    {"rhs_acc_pso1m2",1},
                    {"rhs_acc_pkas",1},            
                    {"rhsusf_acc_ELCAN",1},           
                    {"rhsusf_acc_eotech_552_wd",1},
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1},
                    {"rhsusf_acc_SpecterDR_od",1},
                    {"rhsusf_acc_ACOG_MDO",1},          
                    {"rhsusf_acc_ACOG_RMR",1},           
                    {"rhsusf_acc_EOTECH_xps3",1},
                    {"bnae_suppressor_covblk_virtual",1},           
                    {"bnae_muzzle_blk_virtual",1},           
                    {"bnae_scope_blk_virtual",1},
                    {"bnae_bipod_v2_virtual",1},
                    {"rhsusf_acc_omega9k",1},
                    {"acc_flashlight_pistol",1},
                    {"bnae_suppressor_v3_virtual",1},
                    {"bnae_suppressor_v4_virtual",1},
                    {"bnae_reddot_virtual",1},
                    {"rhs_acc_6p9_suppressor",1},
                    {"DSR_optic_Kobra_green",1}
                };
                semicommon[] = {
                    {"rhsgref_sdn6_suppressor",1},          
                    {"rhsusf_acc_rotex_mp7_desert",1},          
                    {"bnae_holder_virtual",1}, 
                    {"bnae_scope_snd_virtual",1},
                    {"bnae_bipod_snd_virtual",1},            
                    {"rhsusf_acc_M8541_low_wd",1},           
                    {"rhsusf_acc_M952V",1},
                    {"rhs_acc_tgpa",1},
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},          
                    {"rhsusf_acc_T1_low_fwd",1},           
                    {"rhsusf_acc_harris_bipod",1},
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},           
                    {"rhsusf_acc_rotex5_grey",1},
                    {"rhs_acc_1p29",1},
                    {"rhs_acc_1p63",1},            
                    {"rhs_acc_tgpa",1},           
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},
                    {"rhsusf_acc_T1_low_fwd",1},
                    {"rhsusf_acc_harris_bipod",1},          
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},
                    {"rhsusf_acc_rotex5_grey",1},           
                    {"rhs_acc_1p29",1},           
                    {"rhs_acc_1p63",1},
                    {"rhs_acc_1p78",1},
                    {"rhs_acc_ekp1",1},            
                    {"rhs_acc_pbs1",1},           
                    {"rhs_acc_2dpZenit_ris",1},
                    {"rhs_acc_rakursPM",1},
                    {"rhs_acc_2dpZenit",1},
                    {"rhs_acc_1p87",1},
                    {"rhs_acc_perst1ik",1},          
                    {"rhs_acc_tgpv",1},           
                    {"rhs_acc_dh520x56",1},
                    {"rhs_acc_ekp8_18",1},           
                    {"rhs_acc_ekp8_02",1},           
                    {"rhs_acc_pso1m21",1},
                    {"rhs_acc_pso1m2",1},
                    {"rhs_acc_pkas",1},            
                    {"rhsusf_acc_ELCAN",1},           
                    {"rhsusf_acc_eotech_552_wd",1},
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1},
                    {"rhsusf_acc_SpecterDR_od",1},
                    {"rhsusf_acc_ACOG_MDO",1},          
                    {"rhsusf_acc_ACOG_RMR",1},           
                    {"rhsusf_acc_EOTECH_xps3",1},
                    {"bnae_suppressor_covblk_virtual",1},           
                    {"bnae_muzzle_blk_virtual",1},           
                    {"bnae_scope_blk_virtual",1},
                    {"bnae_bipod_v2_virtual",1},
                    {"rhsusf_acc_omega9k",1},
                    {"acc_flashlight_pistol",1},
                    {"bnae_suppressor_v3_virtual",1},
                    {"bnae_suppressor_v4_virtual",1},
                    {"bnae_reddot_virtual",1},
                    {"rhs_acc_6p9_suppressor",1},
                    {"DSR_optic_Kobra_green",1}
                };
                common[] = {
                    {"rhsgref_sdn6_suppressor",1},          
                    {"rhsusf_acc_rotex_mp7_desert",1},          
                    {"bnae_holder_virtual",1}, 
                    {"bnae_scope_snd_virtual",1},
                    {"bnae_bipod_snd_virtual",1},            
                    {"rhsusf_acc_M8541_low_wd",1},           
                    {"rhsusf_acc_M952V",1},
                    {"rhs_acc_tgpa",1},
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},          
                    {"rhsusf_acc_T1_low_fwd",1},           
                    {"rhsusf_acc_harris_bipod",1},
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},           
                    {"rhsusf_acc_rotex5_grey",1},
                    {"rhs_acc_1p29",1},
                    {"rhs_acc_1p63",1},            
                    {"rhs_acc_tgpa",1},           
                    {"rhsusf_acc_premier_low",1},
                    {"rhsusf_acc_T1_high",1},
                    {"rhsusf_acc_T1_low",1},
                    {"rhsusf_acc_T1_low_fwd",1},
                    {"rhsusf_acc_harris_bipod",1},          
                    {"rhsusf_acc_compm4",1},           
                    {"rhs_acc_harris_swivel",1},
                    {"rhsusf_acc_rotex5_grey",1},           
                    {"rhs_acc_1p29",1},           
                    {"rhs_acc_1p63",1},
                    {"rhs_acc_1p78",1},
                    {"rhs_acc_ekp1",1},            
                    {"rhs_acc_pbs1",1},           
                    {"rhs_acc_2dpZenit_ris",1},
                    {"rhs_acc_rakursPM",1},
                    {"rhs_acc_2dpZenit",1},
                    {"rhs_acc_1p87",1},
                    {"rhs_acc_perst1ik",1},          
                    {"rhs_acc_tgpv",1},           
                    {"rhs_acc_dh520x56",1},
                    {"rhs_acc_ekp8_18",1},           
                    {"rhs_acc_ekp8_02",1},           
                    {"rhs_acc_pso1m21",1},
                    {"rhs_acc_pso1m2",1},
                    {"rhs_acc_pkas",1},            
                    {"rhsusf_acc_ELCAN",1},           
                    {"rhsusf_acc_eotech_552_wd",1},
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1},
                    {"rhsusf_acc_SpecterDR_od",1},
                    {"rhsusf_acc_ACOG_MDO",1},          
                    {"rhsusf_acc_ACOG_RMR",1},           
                    {"rhsusf_acc_EOTECH_xps3",1},
                    {"bnae_suppressor_covblk_virtual",1},           
                    {"bnae_muzzle_blk_virtual",1},           
                    {"bnae_scope_blk_virtual",1},
                    {"bnae_bipod_v2_virtual",1},
                    {"rhsusf_acc_omega9k",1},
                    {"acc_flashlight_pistol",1},
                    {"bnae_suppressor_v3_virtual",1},
                    {"bnae_suppressor_v4_virtual",1},
                    {"bnae_reddot_virtual",1},
                    {"rhs_acc_6p9_suppressor",1},
                    {"DSR_optic_Kobra_green",1}
                };
            };
        };
        class Civilian {
            class Weapon {
                rare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semirare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                average[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semicommon[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                common[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
            }; 
            class Handgun {
                rare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semirare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                average[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semicommon[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                common[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
            };
            class Magazine {
                rare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                     {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semirare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                average[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semicommon[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                common[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semirare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                average[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semicommon[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                common[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semirare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                average[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semicommon[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                common[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
            };
        };
        class Industrial {
            class Weapon {
                rare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semirare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                average[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semicommon[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                common[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
            }; 
            class Handgun {
                rare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semirare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                average[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semicommon[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                common[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
            };
            class Magazine {
                rare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                   {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semirare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                average[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semicommon[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                common[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semirare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                average[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semicommon[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                common[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",2},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",3},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},   
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                    
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                     
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},  
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                    
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},     
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                  
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semirare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                average[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semicommon[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                common[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
            };
        };
        class Commercial {
            class Weapon {
                rare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semirare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                average[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semicommon[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                common[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
            }; 
            class Handgun {
                rare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semirare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                average[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semicommon[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                common[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
            };
            class Magazine {
                rare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                   {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semirare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                average[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semicommon[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                common[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semirare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                average[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semicommon[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                common[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semirare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                average[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semicommon[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                common[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
            };
        };
        class Medical {
            class Weapon {
                rare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semirare[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                average[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                semicommon[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
                common[] = {
                    {"rhs_weap_kar98k",2},
                    {"bnae_m97_virtual",3},  
                    {"rhs_weap_kar98k",1},           
                    {"dsr_srifle_cz550_f",1},           
                    {"rhs_weap_savz61",1},
                    {"rhs_weap_Izh18",1},
                    {"rhs_weap_kar98k",2},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"rhs_weap_m38",3},
                    {"bnae_spr220_virtual",3},
                    {"bnae_spr220_so_virtual",3},
                    {"bnae_mk1_virtual",3}
                };
            }; 
            class Handgun {
                rare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semirare[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                average[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                semicommon[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
                common[] = {
                    {"bnae_l35_c_virtual",1},   
                    {"bnae_saa_c_virtual",1}, 
                    {"DSR_hgun_makarov_F",1}, 
                    {"rhsusf_weap_glock17g4",1},           
                    {"bnae_l35_virtual",1},           
                    {"bnae_r1_c_virtual",1},
                    {"rhs_weap_makarov_pm",1},
                    {"rhs_weap_tt33",1}
                };
            };
            class Magazine {
                rare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"rhsgref_1Rnd_00Buck",1},
                    {"rhsgref_1Rnd_Slug",1},
                    {"rhsgref_5Rnd_792x57_kar98k",1},
                    {"rhsgref_5Rnd_762x54_m38",1},
                    {"rhsgref_20rnd_765x17_vz61",1},
                    {"rhs_mag_762x25_8",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                   {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semirare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                average[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semicommon[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                common[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semirare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                average[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semicommon[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                common[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semirare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                average[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semicommon[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                common[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
            };
        };
        class Mechanical {
            class Weapon {
                rare[] = {
                    {"bnae_mk1_virtual",2},
                    {"bnae_spr220_virtual",2},  
                    {"bnae_spr220_so_virtual",3},           
                    {"dsr_srifle_cz550_f",1},           
                    {"bnae_m97_virtual",1},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"DSR_Melee_Bat_Barb",3},
                    {"DSR_Melee_Bat_Lucille",3},
                    {"DSR_Melee_Bat_Nails",3},
                    {"DSR_Melee_Bat_Norm",3}
                };
                semirare[] = {
                    {"bnae_mk1_virtual",2},
                    {"bnae_spr220_virtual",2},  
                    {"bnae_spr220_so_virtual",3},           
                    {"dsr_srifle_cz550_f",1},           
                    {"bnae_m97_virtual",1},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"DSR_Melee_Bat_Barb",3},
                    {"DSR_Melee_Bat_Lucille",3},
                    {"DSR_Melee_Bat_Nails",3},
                    {"DSR_Melee_Bat_Norm",3}
                };
                average[] = {
                    {"bnae_mk1_virtual",2},
                    {"bnae_spr220_virtual",2},  
                    {"bnae_spr220_so_virtual",3},           
                    {"dsr_srifle_cz550_f",1},           
                    {"bnae_m97_virtual",1},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"DSR_Melee_Bat_Barb",3},
                    {"DSR_Melee_Bat_Lucille",3},
                    {"DSR_Melee_Bat_Nails",3},
                    {"DSR_Melee_Bat_Norm",3}
                };
                semicommon[] = {
                    {"bnae_mk1_virtual",2},
                    {"bnae_spr220_virtual",2},  
                    {"bnae_spr220_so_virtual",3},           
                    {"dsr_srifle_cz550_f",1},           
                    {"bnae_m97_virtual",1},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"DSR_Melee_Bat_Barb",3},
                    {"DSR_Melee_Bat_Lucille",3},
                    {"DSR_Melee_Bat_Nails",3},
                    {"DSR_Melee_Bat_Norm",3}
                };
                common[] = {
                    {"bnae_mk1_virtual",2},
                    {"bnae_spr220_virtual",2},  
                    {"bnae_spr220_so_virtual",3},           
                    {"dsr_srifle_cz550_f",1},           
                    {"bnae_m97_virtual",1},
                    {"DSR_Melee_Axe",3},
                    {"DSR_Melee_Fire_Axe",3},
                    {"DSR_Melee_Bat_Barb",3},
                    {"DSR_Melee_Bat_Lucille",3},
                    {"DSR_Melee_Bat_Nails",3},
                    {"DSR_Melee_Bat_Norm",3}
                };
            }; 
            class Handgun {
                rare[] = {
                    {"bnae_l35_c_virtual",4},   
                    {"bnae_saa_c_virtual",6}, 
                    {"rhsusf_weap_glock17g4",1},
                    {"bnae_l35_virtual",1},
                    {"bnae_r1_c_virtual",1},           
                    {"rhs_weap_makarov_pm",8},           
                    {"hgun_Pistol_heavy_02_F",6},           
                    {"DSR_44magnum",7}
                };
                semirare[] = {
                    {"bnae_l35_c_virtual",4},   
                    {"bnae_saa_c_virtual",6}, 
                    {"rhsusf_weap_glock17g4",1},
                    {"bnae_l35_virtual",1}, 
                    {"bnae_r1_c_virtual",1},           
                    {"rhs_weap_makarov_pm",8},           
                    {"hgun_Pistol_heavy_02_F",6},           
                    {"DSR_44magnum",7}
                };
                average[] = {
                    {"bnae_l35_c_virtual",4},   
                    {"bnae_saa_c_virtual",6}, 
                    {"rhsusf_weap_glock17g4",1},
                    {"bnae_l35_virtual",1}, 
                    {"bnae_r1_c_virtual",1},           
                    {"rhs_weap_makarov_pm",8},           
                    {"hgun_Pistol_heavy_02_F",6},           
                    {"DSR_44magnum",7}
                };
                semicommon[] = {
                    {"bnae_l35_c_virtual",4},   
                    {"bnae_saa_c_virtual",6}, 
                    {"rhsusf_weap_glock17g4",1},
                    {"bnae_l35_virtual",1}, 
                    {"bnae_r1_c_virtual",1},           
                    {"rhs_weap_makarov_pm",8},           
                    {"hgun_Pistol_heavy_02_F",6},           
                    {"DSR_44magnum",7}
                };
                common[] = {
                    {"bnae_l35_c_virtual",4},   
                    {"bnae_saa_c_virtual",6}, 
                    {"rhsusf_weap_glock17g4",1},
                    {"bnae_l35_virtual",1}, 
                    {"bnae_r1_c_virtual",1},           
                    {"rhs_weap_makarov_pm",8},           
                    {"hgun_Pistol_heavy_02_F",6},           
                    {"DSR_44magnum",7}
                };
            };
            class Magazine {
                rare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"6Rnd_44_Mag",1},
                    {"4rnd_243win_mag",1}
                };
                semirare[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"6Rnd_44_Mag",1},
                    {"4rnd_243win_mag",1}
                };
                average[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"6Rnd_44_Mag",1},
                    {"4rnd_243win_mag",1}
                }; 
                semicommon[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"6Rnd_44_Mag",1},
                    {"4rnd_243win_mag",1}
                };
                common[] = {
                    {"2Rnd_00_Buckshot_Magazine",1},           
                    {"2Rnd_Slug_Magazine",1},
                    {"6Rnd_00_Buckshot_Magazine",1},
                    {"6Rnd_Slug_Magazine",1},           
                    {"10Rnd_303_Magazine",1},           
                    {"8Rnd_9x19_Magazine",1},
                    {"6Rnd_357M_Magazine",1},
                    {"rhsusf_mag_17Rnd_9x19_JHP",1},           
                    {"rhsusf_mag_17Rnd_9x19_FMJ",1},           
                    {"8Rnd_45ACP_Magazine",1},
                    {"rhs_mag_9x18_8_57N181S",1},
                    {"6Rnd_44_Mag",1},
                    {"4rnd_243win_mag",1}
                }; 
            };
            class Food {
                rare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semirare[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                average[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},              
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_MRE",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1},           
                    {"DSR_Item_Ration",1}
                };
                semicommon[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
                common[] = {
                    {"DSR_Item_Bacon",1},           
                    {"DSR_Item_Beans",1},           
                    {"DSR_Item_Cereal",1},
                    {"DSR_Item_Deviled_Ham",1},
                    {"DSR_Item_Rice",1},   
                    {"DSR_Item_Bag_Rice",1},
                    {"DSR_Item_tuna",1},
                    {"DSR_Item_Can_Chicken",1},           
                    {"DSR_Item_Can_Clams",1},    
                    {"DSR_Item_Powdered_Milk",1},           
                    {"DSR_Item_Instant_Coffee",1}
                };
            };
            class Drink {
                rare[] = {           
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semirare[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Full",1},           
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                average[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                semicommon[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
                common[] = {
                    {"DSR_Item_Waterbottle_Dirty",1},
                    {"DSR_Item_Waterbottle_Empty",1},
                    {"DSR_Item_Canteen_Dirty",1},           
                    {"DSR_Item_Canteen_Empty",1},
                    {"DSR_Item_Spirit",1},
                    {"DSR_Item_Franta",1},           
                    {"DSR_Item_Rusty_Spirit",1}
                };
            };
            class Medical {
                rare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semirare[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                   {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                average[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                semicommon[] = {
                    {"DSR_Item_Antibiotic",1},           
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
                common[] = {
                    {"DSR_Item_Bandage",1},
                    {"DSR_Item_Bloodbag_Empty",1},
                    {"DSR_Item_Bloodbag_Full",1},           
                    {"DSR_Item_Disinfectant",1},
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Painkillers",1},           
                    {"DSR_Item_Vitamins",1},           
                    {"DSR_Item_Syringe",1},
                    {"DSR_Item_Morphine",1}
                };
            };
            class Junk {
                rare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1},
                    {"DSR_Item_Scrap_Metal",1},        
                    {"DSR_Item_Camping_Light",1},
                    {"DSR_Item_Labtop",1},
                    {"DSR_Item_Camping_Chair",1},           
                    {"DSR_Item_Pillow",1},           
                    {"DSR_Item_Handwarmer",1},
                    {"DSR_Item_Water_Purification_Tablets",1},        
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Bucket_Empty",1},
                    {"DSR_Item_Spanner",1},           
                    {"DSR_Item_Watercan_Empty",1},           
                    {"DSR_Item_Watercan_full",1},
                    {"DSR_Item_Shears",1},
                    {"DSR_Item_Lighter",1},           
                    {"DSR_Item_Scissor_Jack",1},           
                    {"DSR_Item_Cooking_Pot",1},
                    {"DSR_Item_Poptobismol",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Electrical_Comp",1},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},           
                    {"DSR_Item_Seeds_Potato",1},           
                    {"DSR_Item_Seeds_Tomato",1},
                    {"DSR_Item_Seeds_Peas",1},
                    {"DSR_Item_Seeds_Lettuce",1},           
                    {"DSR_Item_Seeds_Corn",1},           
                    {"DSR_Item_Seeds_Watermelon",1},
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Tarp",1},             
                    {"DSR_Item_Fabric_Scraps",1},
                    {"DSR_Item_Fertilizer",1},
                    {"DSR_Item_Battery_Charged",1},           
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Camera",1},
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},             
                    {"DSR_Item_Tent_A_Packed",1},           
                    {"DSR_Item_Tent_Dome_Packed",1},
                    {"DSR_Item_Sleeping_Mat",1},
                    {"DSR_Item_Sleeping_Bag",1},           
                    {"DSR_Item_Butane_Torch",1},
                    {"DSR_Item_Can_Opener",1},               
                    {"DSR_Item_Metal_Wire",1},
                    {"DSR_Item_Drill",1},
                    {"DSR_Item_Tin_Container",1},           
                    {"DSR_Item_Nail_File",1},           
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Tape_Measure",1},
                    {"DSR_Item_Multimeter",1},           
                    {"DSR_Item_Pliers",1},           
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Wrench",1},           
                    {"DSR_Item_Plastic_Jug",1},           
                    {"DSR_Item_Suitcase",1},
                    {"DSR_Item_Crushed_Can",1},
                    {"DSR_Item_Photos",1},           
                    {"DSR_Item_Notepad",1},           
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semirare[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_HunterF",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_Hunter",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"DSR_Rpg_Backpack",1},           
                    {"B_FieldPack_cbr",3},
                    {"B_FieldPack_oli",3},           
                    {"B_HuntingBackpack",3},           
                    {"B_Kitbag_sgg",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                average[] = {
                    {"DSR_Carryall_Blue",1},           
                    {"DSR_Carryall_Green",1},
                    {"DSR_Carryall_WHiker",1},
                    {"DSR_Carryall_MHiker",1},           
                    {"DSR_Carryall_HKitty",1},
                    {"DSR_Carryall_Orange",1},
                    {"DSR_Carryall_Purple",1},           
                    {"DSR_Carryall_Red",1},           
                    {"DSR_Carryall_Yellow",1},
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                semicommon[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
                common[] = {
                    {"DSR_Tactical_Black",2},
                    {"DSR_Tactical_Blue",2},           
                    {"DSR_Tactical_Orange",2},           
                    {"DSR_Civil_Assault_Backpack",1},
                    {"DSR_Medical_Backpack",1},
                    {"rhs_Rpg_empty",1},           
                    {"B_FieldPack_khk",3},
                    {"B_FieldPack_oli",3},           
                    {"rhs_sidor",3},           
                    {"rhs_medic_bag",1},
                    {"B_OutdoorPack_blk",3},           
                    {"B_OutdoorPack_blu",3},
                    {"B_OutdoorPack_tan",3},
                    {"DSR_Assaultpack_Coyote",1},           
                    {"DSR_Assaultpack_Blue",1},
                    {"DSR_Assaultpack_Green",1},
                    {"DSR_Assaultpack_Grey",1},
                    {"DSR_Assaultpack_Purple",1},
                    {"DSR_Assaultpack_Red",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semirare[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                average[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                semicommon[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
                common[] = {
                    {"U_I_C_Soldier_Bandit_2_F",1},           
                    {"U_I_G_resistanceLeader_F",1},           
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_burgundy",1},           
                    {"U_C_Poor_1",1},           
                    {"U_C_Journalist",1},
                    {"U_OrestesBody",1},
                    {"U_BG_Guerilla3_1",1},           
                    {"U_BG_Guerilla2_3",1},           
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"tacs_Uniform_Combat_LS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_LS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_LS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_LS_CPS_BP_BB",1},
                    {"tacs_Uniform_Combat_RS_CDBS_GP_TB",1},           
                    {"tacs_Uniform_Combat_RS_CLBS_GP_BB",1},           
                    {"tacs_Uniform_Combat_RS_CLRS_TP_BB",1},
                    {"tacs_Uniform_Combat_RS_CPS_BP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_BS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_LS_LP_BB",1},           
                    {"tacs_Uniform_Tshirt_JP_GS_LP_BB",1},
                    {"tacs_Uniform_Tshirt_JP_WS_LP_BB",1},
                    {"tacs_Uniform_Polo_TP_BS_LP_BB",1},           
                    {"tacs_Uniform_Polo_TP_LS_GP_BB",1},           
                    {"tacs_Uniform_Polo_TP_OS_LP_BB",1},
                    {"tacs_Uniform_Polo_CP_LS_TP_OB",1},
                    {"tacs_Uniform_Polo_CP_RS_LP_BB",1},           
                    {"tacs_Suit_VIP",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semirare[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                average[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                semicommon[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
                common[] = {
                    {"V_Rangemaster_Belt",2},           
                    {"V_BandollierB_khk",2},
                    {"V_BandollierB_rgr",2},
                    {"rhs_6sh46",2},           
                    {"rhs_vest_commander",2},           
                    {"rhs_vydra_3m",3},
                    {"rhsgref_alice_webbing",2},           
                    {"V_TacVest_khk",2},           
                    {"V_TacVest_oli",2},
                    {"V_TacVest_camo",2},
                    {"V_TacVest_blk_POLICE",2},           
                    {"V_HarnessO_brn",2},
                    {"V_Press_F",2},
                    {"tacs_Vest_Tactical_DarkBlack",2}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semirare[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                average[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                semicommon[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
                common[] = {
                    {"H_Bandanna_camo",1},           
                    {"H_Booniehat_oli",1},           
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Booniehat_khk",1},           
                    {"H_Cap_oli",1},           
                    {"H_Cap_headphones",1},
                    {"H_Cap_police",1},
                    {"H_Cap_press",1},           
                    {"H_Cap_blk_CMMG",1},
                    {"rhs_beanie_green",1},
                    {"tacs_Hat_Boonie_RangerGreen",1},      
                    {"tacs_Hat_Boonie_Woodland",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semirare[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                average[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                semicommon[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
                common[] = {
                    {"DSR_mask_metal",1},           
                    {"DSR_mask_metal_bone",1},
                    {"DSR_mask_metal_camoArmy",1},
                    {"DSR_mask_metal_paintOrange",1},           
                    {"DSR_mask_metal_sunburst",1},   
                    {"rhs_scarf",1},           
                    {"rhs_balaclava1_olive",1},           
                    {"rhs_balaclava",1},
                    {"rhsusf_shemagh2_grn",1},
                    {"rhsusf_shemagh2_tan",1},
                    {"mcu2p2_grey",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semirare[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                average[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                semicommon[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
                common[] = {
                    {"DSR_Flashlight",25},  
                    {"ItemMap",25},           
                    {"Binocular",25},           
                    {"ItemRadio",10},
                    {"ItemWatch",15}
                };
            };
            class Construction {
                rare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",2},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",3},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},    
                    {"DSR_Item_Scrap_Metal",3},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                      
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semirare[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},   
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                    
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                average[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                     
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                semicommon[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},  
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                    
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
                common[] = {
                    {"DSR_Melee_Axe",1}, 
                    {"DSR_Melee_Pickaxe",1},
                    {"DSR_Item_Saw",1},           
                    {"DSR_Item_Toolbox",1},
                    {"DSR_Item_Bricks",1},
                    {"DSR_Item_Plastic_Drum",1},           
                    {"DSR_Item_Duct_Tape",1},           
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},     
                    {"DSR_Item_Scrap_Metal",8},
                    {"DSR_Item_Metal_Wire",1},           
                    {"DSR_Item_Grinder",1},
                    {"DSR_Item_Hammer",1},
                    {"DSR_Item_Wrench",1},
                    {"DSR_Item_Pliers",1},                  
                    {"DSR_Item_Screw_Driver_Phillips",1},
                    {"DSR_Item_Tape_Measure",1}
                };
            };
            class Book {
                rare[] = {
                    {"DSR_Item_Crushed_Can",5},  
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semirare[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                average[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                semicommon[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
                common[] = {
                    {"DSR_Item_Crushed_Can",5},
                    {"DSR_Item_Fabric_Scraps",3},           
                    {"DSR_Item_Can_Opener",1},           
                    {"DSR_Item_Matches",1},
                    {"DSR_Item_Tarp",1}, 
                    {"DSR_Item_Wrench",1},   
                    {"DSR_Item_Pen_Black",1},
                    {"DSR_Item_Pen_Red",1},
                    {"DSR_Item_Pencil_Blue",1},
                    {"DSR_Item_Pencil_Green",1},
                    {"DSR_Item_Pencil_Red",1},           
                    {"DSR_Item_Pencil_Yellow",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semirare[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                average[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                semicommon[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
                common[] = {
                    {"DSR_Item_Camera",1},           
                    {"DSR_Item_Phoneold",1},           
                    {"DSR_Item_Phonesmart",1},         
                    {"DSR_Item_Extension_Cord",1},
                    {"DSR_Item_Battery_Charged",1},
                    {"DSR_Item_Battery_Dead",1},           
                    {"DSR_Item_Electrical_Comp",1},   
                    {"DSR_Item_Portable_Generator",1}
                };
            };
            class CarPart {
                rare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semirare[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                average[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                semicommon[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
                common[] = {
                    {"DSR_Item_Engine_Block",10},               
                    {"DSR_Item_Gas_Tank",5},           
                    {"DSR_Item_Glass_Part",10},
                    {"DSR_Item_Gascan_Large_Full",5},
                    {"DSR_Item_Gascan_Small_Full",10},
                    {"DSR_Item_Tire",15},
                    {"DSR_Item_Main_Rotor",5},           
                    {"DSR_Item_Tail_Rotor",5},           
                    {"DSR_Item_Toolbox",10},
                    {"DSR_Item_Wrench",5},
                    {"DSR_Item_Tire_RepairKit",15},
                    {"DSR_Item_Car_Battery",5}
                };
            };
            class Attachment {
                rare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semirare[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                average[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                semicommon[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
                common[] = {
                    {"acc_flashlight_pistol",1},          
                    {"bnae_reddot_virtual",1},
                    {"bnae_scope_snd_virtual",1},           
                    {"bnae_bipod_snd_virtual",1},   
                    {"rhsusf_acc_M8541_low_wd",1},
                    {"rhsusf_acc_harris_bipod",1},            
                    {"rhs_acc_dh520x56",1},           
                    {"rhsusf_acc_LEUPOLDMK4_2_d",1},
                    {"rhsusf_acc_LEUPOLDMK4",1}
                };
            };
        };
    };
    class Buildings {
        class Land_NAV_Lighthouse2 {
            table = "Military";
            positions[] = {{-1.11377,-1.48682,2.41768},{-0.117676,0.0644531,-6.7829}
            };
        };
        
        class Land_NAV_Lighthouse {
            table = "Military";
            positions[] = {{-1.18262,-1.47314,2.41768},{-0.0981445,-0.241211,-6.7829}
            };
        };
        
        class Land_Majak {
            table = "Military";
            positions[] = {{-0.233887,1.18701,-8.07446},{1.60449,-0.822754,1.72104}
            };
        };
        
        class Land_Majak_v_celku {
            table = "Military";
            positions[] = {{1.36377,-6.80273,3.72537},{0.00439453,-4.53857,-6.07013}
            };
        };
        
        class Land_tent_east {
            table = "Military";
            positions[] = {{2.38379,-2.12842,-1.75578},{-3.35693,1.79541,-1.75579}
            };
        };
        
        class CampEast_EP1  {
            table = "Military";
            positions[] = {{1.80957,-2.83521,-1.25191},{-1.64502,-2.09741,-1.25194},{-1.77686,2.25,-1.25194}
            };
        };

        class Land_Ind_Shed_01_EP1 {
            table = "Industrial";
            positions[] = {{-7.79321,4.93457,-3.33529},{7.87134,11.2715,-3.33529},{7.83423,-8.58789,-3.33527},{-7.64038,-8.85791,-3.33529}
            };
        };
        
        class Land_Ind_Shed_02_EP1 {
            table = "Industrial";
            positions[] = {{3.91968,-8.97266,-2.08116},{3.9292,3.23779,-2.08117},{4.4707,12.1157,-2.08114}
            };
        };

        class Land_Airport_01_controlTower_F {
            table = "Military";
            positions[] = {{-3.00696, 3.91602, 4.21086}, {3.06915, 3.89941, 4.23131}, {0.0256958, -2.06201, 4.21085}, {0.376404,1.16602, 4.65663}, {-1.27332, 0.373535, 7.91646}
            };
        };

        class Land_Airport_02_terminal_F {
            table = "Commercial";
            positions[] = {{3.36981,10.9082, -1.40149}, {0.277771, 4.55811, -1.40149}, {2.60266, -0.411133, -1.40149}, {5.20868, 3.13037, -1.40149}, {9.82227,1.33496, -1.40149}, {10.3759, -2.8335, -1.40149}, {-3.33417, -9.50488, -1.40149}, {-19.4422, -10.1187, -1.40149}, {12.8807, -10.3208, -1.40149}, {22.9008, -5.79883, -1.40149}, {21.9941,10.5249, -1.40149}
            };
        };

        class Land_Airport_01_terminal_F {
            table = "Commercial";
            positions[] = {{-14.3466, -0.588379, -4.02741}, {-11.2858, 2.41602, -4.02741}, {-8.2597, 4.43359, -3.98237}, {-5.414, 7.771, -3.98237}, {8.09961, 8.10889, -4.01762}, {6.22021, -7.17871, -4.00997}, {9.02838, -10.4839, -4.00997}, {5.16388, 5.54004, -4.02803}, {-1.08685,1.23682, -4.10765}, {3.38068, -4.2085, -4.12297}
            };
        };

        class Land_Airport_01_hangar_F {
            table = "Mechanical";
            positions[] = {{12.7657, -8.04395, -2.68443}, {12.7607,12.7231, -2.68448}, {-13.3329,13.9307, -2.68448}, {-12.2171, -7.75732, -2.68444}, {0.403809,13.1753, -2.68448}, {13.1948, -2.32715, -2.68444}
            };
        };

        class Land_House_Big_04_F {
            table = "Civilian";
            positions[] = {{3.31604, 6.40625, -2.94933}, {-8.47241, 6.26709, -2.95065}, {-8.08984, -6.6377, -2.94858}, {1.90912, -6.72803, -2.94858}, {-8.40582, -6.66602, 0.276856}, {11.6814, -7.04492, 0.276991}, {-0.609863, -7.23633, 0.27781}, {-8.26996, 6.34521, 0.303274}, {4.09497, 6.37451, 0.302769}, {3.77234,1.79395, 0.301416}, {-5.09198, 4.31494, 0.301416}, {-4.98438,1.64209, 0.301415}, {-5.69537, -4.48975, -2.94858}, {3.39117, -3.10498, -2.94858}
            };
        };

        class Land_MultistoryBuilding_03_F
        {
            table = "Commercial";
            positions[] = {{-2.22174, 7.31934, -25.9053}, {-5.63617, 4.71777, -25.9053}, {-1.87103, 4.64307, -25.9053}, {-7.48083, -0.407715, -24.22}, {-7.4483, -3.91064, -24.2191}
            };
        };

        class Land_House_Small_04_F
        {
            table = "Civilian";
            positions[] = {{-3.64771, 3.82129, -0.866206}, {-3.73071, -2.66895, -0.866206}, {0.299927, 3.69971, -0.866206}, {-1.31946, -3.97314, -0.866206}, {3.38403, -1.32324, -0.866206}, {-0.83905, -6.95166, -0.866206}
            };
        };

        class Land_House_Small_05_F
        {
            table = "Civilian";
            positions[] = {{-2.06793, -3.41797, -1.08627}, {0.886169, 4.17969, -1.08733}, {-2.90967, 3.9873, -1.08697}, {-2.92603, -0.64502, -1.08615}
            };
        };

        class Land_Shop_City_01_F
        {
            table = "Commercial";
            positions[] = {{1.18323, 0.0922852, -4.91619}, {6.22626, 4.52588, -4.9378}, {2.29846, 4.09277, -4.94828}
            };
        };

        class Land_Shop_City_02_F
        {
            table = "Commercial";
            positions[] = {{-0.675201, -5.24316, -4.36327}, {-2.94293, -7.92676, -4.36245}, {-10.3821, -2.96924, -4.35083}, {-8.8096, -7.85156, -4.35083}, {1.24158, -7.73242, -4.3625}, {1.84985, -2.86328, -4.36363}, {7.10519, -3.02295, -4.36247}, {1.10577, -0.0512695, -4.36428}, {6.86386,1.68848, -4.36254}, {4.33301, 7.78174, -4.368}, {6.64581, 9.625, -4.36479}
            };
        };

        class Land_FireEscape_01_short_F
        {
            table = "Civilian";
            positions[] = {{-1.92456, -2.33057, 5.87384}, {-0.687744,1.20215, 4.12385}, {-1.83334, -2.31396, 2.36634}, {-1.86963, -2.36035, -1.14366}, {-1.8194,1.26514, 0.616343}
            };
        };

        class Land_FireEscape_01_tall_F
        {
            table = "Civilian";
            positions[] = {{-0.839661, -0.429199, 5.98783}, {-1.03955, 3.11719, 4.23783}, {-1.88132, -0.458496, 2.48032}, {-1.98297, 3.11963, -2.77967}, {-1.7475, -0.564453, -1.02967}
            };
        };

        class Land_House_Big_05_F
        {
            table = "Civilian";
            positions[] = {{-8.4136, -4.73389, -1.50791}, {-2.1731, -4.72119, -1.50986}, {5.57956, -4.89111, -1.10227}, {4.74078, 5.41748, -1.1154}, {-2.39563, 5.27197, -1.50986}, {-8.5723, 5.36475, -1.50889}
            };
        };

        class Land_Addon_01_F
        {
            table = "Civilian";
            positions[] = {{-0.162262, -3.75, -1.17012}, {-0.0673828, 3.73633, -1.17012}
            };
        };

        class Land_Addon_04_F
        {
            table = "Civilian";
            positions[] = {{-5.5575, -6.90771, 0.333342}, {-4.92792, 4.2417, 0.333342}, {5.39682, -0.76123, 0.333343}, {2.92578, -6.26123, 0.333342}, {-3.0574,1.4624, 0.333342}, {-0.601196, -0.920898, 0.333342}, {5.26059, 4.20752, 0.333342}
            };
        };

        class Land_Shop_City_05_F
        {
            table = "Commercial";
            positions[] = {{0.827393, -10.8149, -7.26246}, {-1.22951, -12.0522, -7.27676}
            };
        };

        class Land_Shop_City_03_F
        {
            table = "Commercial";
            positions[] = {{1.4767, -7.66504, -4.96703}, {5.70377, -2.34131, -4.95675}, {1.59322, 2.7832, -4.97481}, {3.5081, 9.0791, -4.97082}
            };
        };

        class Land_Shop_City_06_F
        {
            table = "Commercial";
            positions[] = {{-5.3772, -6.00781, -4.04819}, {-5.99379, 0.533691, -4.0484}, {-3.99609, 7.38623, -4.04862}, {1.19998, 8.27539, -2.34276}, {-4.85144, 7.39014, -0.319801}, {7.30609, 3.1167, -0.319942}, {-4.53831, 2.94531, -0.318829}, {-1.19354, 7.81641, -0.319835}
            };
        };

        class Land_Shop_City_07_F
        {
            table = "Commercial";
            positions[] = {{2.7469, 2.46387, 0.0339336}, {1.1144, 7.68164, 0.0339508}, {-3.86372, 7.56201, 3.63137}, {-2.88173, -5.72949, 3.63136}, {2.03906, -0.931641, 3.63136}, {2.27966, -6.27881, 3.63136}
            };
        };

        class Land_MultistoryBuilding_01_F
        {
            table = "Commercial";
            positions[] = {{10.3646, -11.7373, -21.0179}, {10.9926, -2.41699, -21.018}, {10.8797, 3.23242, -21.018}, {19.1703, 3.99951, -21.0179}, {19.2338, -12.2734, -21.018}, {-18.4634,16.6816, -21.0179}, {-5.52731,16.2871, -21.0179}, {-18.555, -11.5474, -21.0179}, {-18.4026, 2.79199, -21.0179}, {-11.7448, -8.86279,19.2657}, {-12.1009, 9.86328,19.2656}, {17.3746, -10.2432,19.2657}, {9.97755,1.6665,19.2657}, {18.8899,10.8208,19.2657}
            };
        };

        class Land_MultistoryBuilding_04_F
        {
            table = "Commercial";
            positions[] = {{8.58585, -11.7158, -36.3151}, {-2.73436, -11.4868, -36.3152}, {-11.4193, -11.5947, -36.3152}, {-10.7024, 0.208008, -36.3152}, {-10.8938,10.6709, -36.3152}, {-4.59261,10.0254, 22.396}, {9.54498,10.1509, 22.396}, {10.3787, -5.79199, 22.396}
            };
        };

        class Land_School_01_F
        {
            table = "Civilian";
            positions[] = {{12.5829, -4.72314, -1.3499}, {5.64906, -4.41797, -1.3499}, {-2.35116, -4.51416, -1.34991}, {-13.0124, -4.5957, -1.3499}, {-13.5541, 3.14209, -1.25486}, {-13.1472, -1.72852, -1.25354}, {-7.8992, -1.9585, -1.24099}, {-2.83229, -1.9165, -1.24139}, {-0.00878716, 3.48877, -1.25486}, {5.56185, -1.90625, -1.24072}, {13.2059, 3.23486, -1.24905}, {13.2425, -1.62842, -1.24132}, {0.097558, -1.6709, -1.24214}
            };
        };

        class Land_House_Big_03_F {
            table = "Civilian";
            positions[] = {{2.81361, -1.31836, -3.17496}, {5.83369, -4.93799, -3.17496}, {9.58751, -1.87451, -3.17496}, {10.1001, 5.53369, -3.20496}, {3.31785, 5.73145, -3.20496}, {10.4125, 0.702148, -3.17496}, {1.97136, 3.28271, -3.17496}, {-11.5872, -4.88965, -0.111648}, {-12.0157, 4.62109, -0.111648}, {-7.68954, -5.24902, -0.111648}, {2.43372, -5.17139, -0.111647}, {9.50365, -4.35547, -0.111646}, {9.58155, 5.29199, -0.111646}, {2.44902, 5.5708, -0.111649}, {3.10835, -2.11768, -0.0905371}, {7.9266, -1.31445, -0.090538}, {7.36005, 3.07031, -0.090538}, {2.70773, 2.98096, -0.090538}
            };
        };

        class Land_MobileCrane_01_F
        {
            table = "Industrial";
            positions[] = {{7.85629, 5.55029, -19.4707}, {12.0654, 5.69873, -19.4707}, {10.0373, 2.60645, -19.0873}, {6.98733, -2.43115, -19.0873}, {13.9328, -2.59424, -14.0242}, {13.9299, 2.29443, -14.0242}, {8.70084, 2.69189, -14.0242}, {8.80087, -2.91406, -14.0242}, {11.6297, -5.54541, -19.4707}, {7.02059, 2.59668, -19.0873}, {10.1519, -2.59424, -19.0873}
            };
        };

        class Land_MobileCrane_01_hook_F
        {
            table = "Industrial";
            positions[] = {{11.0956, -5.58643, -19.4707}, {6.91805, -2.21387, -19.0873}, {6.82528, 2.53857, -19.0873}, {13.3552, -2.09229, -14.0242}, {8.42605, -2.42188, -14.0242}, {13.9843, 2.74951, -14.0242}, {8.44981, 2.72217, -14.0242}, {10.0628, 2.66943, -19.0873}, {12.0439, 5.68994, -19.4707}, {7.33242, 5.74414, -19.4707}, {7.36204, -5.54248, -19.4707}
            };
        };

        class Land_House_Native_01_F
        {
            table = "Civilian";
            positions[] = {{-3.92445, 2.28174, -3.10247}, {3.39246, -1.94092, -3.10247}, {-3.28581, -1.92529, -3.10247}, {3.17792, 2.13477, -3.10247}, {-0.199219, -2.16943, -3.10247}
            };
        };

        class Land_House_Native_02_F
        {
            table = "Civilian";
            positions[] = {{1.9373,1.4082, -2.41631}, {1.87907, -1.9209, -2.41631}, {-3.27092,1.9707, -2.41631}, {-3.23453, -2.0166, -2.41631}
            };
        };

        class Land_Temple_Native_01_F
        {
            table = "Civilian";
            positions[] = {{3.20041, -2.3374, -5.95458}, {-3.14743, -2.46436, -5.95458}, {2.58812, 0.324219, -5.95457}, {2.43742, 3.89014, -5.95457}, {-2.53903, 0.67041, -5.95458}, {-2.64441, 4.02686, -5.95457}, {-3.061, 6.80176, -5.95458}, {3.79857, 6.44727, -5.95457}
            };
        };

        class Land_DPP_01_mainFactory_F
        {
            table = "Industrial";
            positions[] = {{-21.92, 4.79346, -9.16247}, {-21.8768, -14.186, -9.18247}, {15.5463, -18.0396, -4.11747}, {17.3237, -14.4956, -4.11747}, {17.8664, -10.7212, -4.11747}, {15.7866, -7.29785, -4.11747}, {12.6862, -4.30322, -4.25747}, {12.8652, -2.36035, -4.25747}, {12.7665, 4.97803, -4.25747}, {12.8564, 6.83545, -5.54747}, {19.0106, -5.35059, -5.54747}, {18.969, 2.31885, -5.54747}, {20.6808, -4.05322, -7.44347}, {20.4157,1.51514, -7.44347}, {21.2942, 4.77588, -7.44347}, {19.0013, 5.16553, -7.64927}, {8.50312, 8.93994, -0.31447}, {10.524, -1.4873, -0.314478}, {4.05009, 8.87256,1.14823}, {-0.406693, -0.691895,1.14823}, {-7.21104, 2.40869,1.14823}, {-4.97194, -10.0967,1.14823}, {1.74726, -14.9678,1.14823}
            };
        };

        class Land_DPP_01_smallFactory_F
        {
            table = "Industrial";
            positions[] = {{10.0669, -5.00342, 0.989646}, {10.1559, 2.146, 0.989654}, {0.462799, 3.25684, 2.4038}, {-2.98578, 3.05713, 2.40379}
            };
        };

        class Land_dp_smallFactory_F
        {
            table = "Industrial";
            positions[] = {{10.0669, -5.00342, 0.989646}, {10.1559, 2.146, 0.989654}, {0.462799, 3.25684, 2.4038}, {-2.98578, 3.05713, 2.40379}
            };
        };

        class Land_i_Shed_Ind_F
        {
            table = "Industrial";
            positions[] = {{14.0747, 6.86572, -1.56921}, {-1.59459, -0.653809, -1.56921}, {-3.98872, 6.8667, -1.56921}, {10.0919, -0.314453, -1.56921}, {-5.87579, -0.795898, -1.56921}, {-5.62433,1.68408, -1.56921}
            };
        };

        class Land_SM_01_shed_F
        {
            table = "Industrial";
            positions[] = {{14.0747, 6.86572, -1.56921}, {-1.59459, -0.653809, -1.56921}, {-3.98872, 6.8667, -1.56921}, {10.0919, -0.314453, -1.56921}, {-5.87579, -0.795898, -1.56921}, {-5.62433,1.68408, -1.56921}
            };
        };

        class Land_SM_01_shed_unfinished_F
        {
            table = "Industrial";
            positions[] = {{-7.00366, 6.81445, -1.61709}, {-5.36069,1.57568, -1.61709}, {-5.80513, -1.16357, -1.61709}, {3.29742, 0.314453, -1.61709}, {14.6968, -0.174316, -1.61709}, {3.89108, 7.02344, -1.61709}
            };
        };

        class Land_SY_01_conveyor_end_F
        {
            table = "Industrial";
            positions[] = {{3.50247, 2.69287, -3.35729}, {3.48972, -2.6001,1.40514}, {1.32748, 2.69922, 5.25539}, {-1.38519, 2.59424, 5.25539}, {-1.37393, -1.79199, 5.25539}
            };
        };

        class Land_SY_01_crusher_F
        {
            table = "Industrial";
            positions[] = {{-7.73892,1.16895, -1.09281}, {7.70358,16.8159, -1.07898}, {-7.75183,15.2749, -1.07731}, {7.88333, 2.37988, -1.08442}, {0.680634,1.1582, -1.09289}, {-6.45386,11.2256,11.4876}, {6.70441, 9.83057,11.5466}, {0.257385, 9.21436, -11.2428}
            };
        };

        class Land_SY_01_reclaimer_F
        {
            table = "Industrial";
            positions[] = {{-12.5131, 0.818359, -2.44122}, {-14.1992, 4.99902, -2.43626}
            };
        };
        
        class Land_Barn_W_01 
        {
            table = "Industrial";
            positions[] = {{4.80933,-16.4067,-2.63218},{-3.96802,-18.3599,-2.63184},{1.125,-2.99658,-2.63452},{4.46094,16.3979,-2.6379},{-4.21777,16.0718,-2.63784}
            };
        };
        
        class Land_Barn_W_02 
        {
            table = "Industrial";
            positions[] = {{4.07202,-5.87305,-2.30336},{-5.76001,-6.05322,-2.31093},{3.42773,4.25879,-2.31514},{-4.55078,4.34424,-2.3084}
            };
        };
        
        class Land_Ind_Pec_01 
        {
            table = "Industrial";
            positions[] = {{1.99097,-11.2202,-22.5782},{4.33423,-6.77637,-17.5766},{-6.45752,4.51611,-22.5782},{-1.75439,-3.19727,-3.965},{-1.13135,-6.21826,6.08639},{0.0241699,-9.7417,14.5424},{4.77417,-2.64502,14.5425},{-0.303223,-14.2153,1.0274}
            };
        };
        
        class Land_Ind_Expedice_1 
        {
            table = "Industrial";
            positions[] = {{13.1108,-12.583,-5.7587},{-0.0917969,-1.2749,-3.48817},{-1.82178,13.0806,-3.48817},{2.92163,17.8716,-5.68533},{-11.9666,-12.8394,-3.48816}
            };
        };

        class Land_SCF_01_boilerBuilding_F
        {
            table = "Industrial";
            positions[] = {{20.4062,1.76416, -13.1931}, {12.6199, 2.29736, -13.1931}, {19.1641,12.5249, -13.1931}, {13.0838,13.4111, -13.1931}, {19.3361, 6.896, -13.193}, {21.7828,1.04639, -8.64783}, {11.6639,1.13867, -8.64783}, {11.6371, -1.03662, -5.52507}, {11.9275, -8.00977, -5.52507}, {-2.03784, 23.6602, -13.1631}, {18.4623, 9.35156, -8.62783}
            };
        };

        class Land_SCF_01_chimney_F
        {
            table = "Industrial";
            positions[] = {{-2.89178, -3.82471, -8.19502}, {-1.37646, 4.09912, -8.19501}, {-5.56982, 0.607422, -8.19502}, {-2.37286, -3.05908, 24.3167}, {-0.946167, 2.91748, 24.3167}
            };
        };

        class Land_SCF_01_clarifier_F
        {
            table = "Industrial";
            positions[] = {{5.16095, -5.48291, -2.02836}, {5.43793,1.60498, 0.396125}, {-0.846191, -4.61816, 0.396124}, {-7.2016, 2.52979, 0.396124}, {2.42871, 5.18262, 0.396125}, {-1.64771, 0.993652, 8.5348}
            };
        };

        class Land_SCF_01_condenser_F
        {
            table = "Industrial";
            positions[] = {{3.0542, -1.01611,1.98746}, {6.01874, 0.0473633,1.98747}, {3.11456, 3.13037,1.98746}, {-7.3927,13.7788, -1.52646}, {-4.51294, 7.1416, -1.52646}, {-7.06055,10.3657, -1.52646}
            };
        };

        class Land_SCF_01_crystallizerTowers_F
        {
            table = "Industrial";
            positions[] = {{-9.3371, -3.31641, -9.8089}, {-3.36139, -2.99854, -6.95771}, {4.14148, -3.05127, -6.95771}, {-0.121643, -0.0981445, -7.18977}, {1.98773, 2.02637,12.1745}, {6.20105, -3.16553,12.1745}, {-6.76501, -0.98584,12.9881}, {-2.0943, 2.76416,12.37}
            };
        };

        class Land_SCF_01_crystallizer_F
        {
            table = "Industrial";
            positions[] = {{2.2359, 8.30762, -5.88057}, {8.7561, 7.07324, -2.84587}, {2.21698, 8.77686, -0.447963}, {8.15094,1.03223, -0.440189}, {0.874512,1.38867, -0.440188}, {7.10388, 4.74316, -0.440193}, {-8.89655,1.19043, -0.440192}, {-7.01703, 4.94238, -0.440189}, {1.51508, 6.84766, 4.98345}, {-8.77814, 4.89258, 5.00417}, {-8.59552, -0.862305, 5.01047}, {4.62744, -0.416016, 5.00403}, {5.25385, 4.87744, 5.00415}
            };
        };

        class Land_SCF_01_diffuser_F
        {
            table = "Industrial";
            positions[] = {{-6.1275,16.5728, -2.34902}, {-7.93939, 23.563, -2.34902}, {6.34424, 23.2031, -2.34902}, {6.09753, 9.38672, -2.34902}, {1.71259, 5.66504, 0.989358}, {-3.52942, 5.32617, 0.983278}, {6.54865, -8.6416, -2.34902}, {6.21283, -22.5537, 2.35732}, {3.62836, -21.2036, 2.35732}, {-5.05341, -21.7944, 2.35732}, {-7.55786, -19.8203, 2.35732}, {-3.86725, -17.2979, 4.55072}, {0.824524, -13.2207, 4.55072}, {4.81476, -19.0898, 4.55072}, {4.96899, -13.124, 4.55072}
            };
        };

        class Land_SCF_01_feeder_F
        {
            table = "Industrial";
            positions[] = {{4.57166,17.146, -3.2917}, {-1.12738,17.4243, -3.2917}, {-4.72894,11.957, -3.2917}
            };
        };

        class Land_SCF_01_generalBuilding_F
        {
            table = "Industrial";
            positions[] = {{13.7668, 3.3667, -4.84506}, {5.23486, -14.1592, -4.82014}, {2.16504, -16.2207, -0.336995}, {3.49451, -20.2495, -0.336994}, {5.50555, -23.8975, -0.330949}, {1.70123, -21.7822, -4.82014}, {-4.39288, -15.479, -4.82014}, {-5.02173, -21.3472, -4.82014}, {-5.44708, -23.9912, -0.328772}, {-3.40857, -15.0322, -0.336995}, {-4.04376, -19.9419, -0.333236}, {-7.72589, -8.42334, -0.306211}, {-2.13281, -21.9604, 9.71007}, {-2.1366, -3.09473, 9.71008}
            };
        };

        class Land_SCF_01_storageBin_big_F
        {
            table = "Industrial";
            positions[] = {{4.19385, -9.50781, 8.08185}, {-7.11786, 7.35254, 8.08648}, {-7.30212, -6.74121, 8.09786}, {1.07813, -2.38184, 8.36898}, {5.74097, 7.80664, 8.11623}
            };
        };

        class Land_SCF_01_storageBin_medium_F
        {
            table = "Industrial";
            positions[] = {{-3.46143, 5.7192, 6.799}, {4.72754, -1.49947, 6.88451}, {-4.22803, -3.10316, 6.85781}};
        };

        class Land_SCF_01_storageBin_small_F
        {
            table = "Industrial";
            positions[] = {{-0.780762, 3.31348, 7.58101}, {1.15662, -0.510254, 7.53981}
            };
        };

        class Land_SCF_01_warehouse_F
        {
            table = "Industrial";
            positions[] = {{4.28088, -12.4028, -4.56458}, {8.55493, -13.3931, -4.56458}, {16.1413,14.8442, -4.53404}, {-9.50293,16.6538, -4.56258}, {-11.0309,13.7896, -4.56258}
            };
        };

        class Land_SCF_01_washer_F
        {
            table = "Industrial";
            positions[] = {{-5.66089, -10.9932, -1.77585}, {-4.77167, 8.43359, -1.77585}, {0.351501, 9.09912, -1.77585}, {3.99756, 7.39648, -1.77585}, {5.72986, 2.22656, 2.2026}, {5.43201, 0.609375, -1.77584}, {5.75275, -11.5483, -1.77584}, {-5.56262,1.96045, 2.20261}, {-2.67273, 7.06201, 3.2295}, {2.84528, 7.07959, 3.2295}, {-5.63361, -4.71387, -1.77585}
            };
        };

        class Land_Warehouse_03_F
        {
            table = "Industrial";
            positions[] = {{-10.0099, 4.12891, -2.36559}, {4.32355, -0.524414, -2.36164}, {6.4068, 4.54395, -2.36594}, {6.07056, 4.87842, 0.188947}, {7.8252,1.41455, 0.199012}, {5.80853, -0.0791016, -2.36267}, {-3.52875, 4.18555, -2.36564}
            };
        };

        class Land_MilOffices_V1_F
        {
            table = "Military";
            positions[] = {{-16.1816,10.5855, -2.8682}, {-15.25, 7.0052, -2.8682}, {-14.397, 4.58313, -2.8682}, {-15.9063, 0.529099, -2.8682}, {-16.1011, -1.63214, -2.8682}, {-13.9727, -4.74777, -2.8682}, {-11.3452, -4.54674, -2.8682}, {-9.02881, -4.78514, -2.8682}, {-6.62061, -1.74809, -2.8682}, {-4.65186, -4.65324, -2.8682}, {-2.29053, -2.09383, -2.8682}, {-0.324707, -4.71222, -2.8682}, {0.648926, -1.75002, -2.8682}, {4.48535,10.3548, -2.8682}, {4.16016, 7.36406, -2.8682}, {-0.951172,10.0732, -2.8682}, {-2.95361,10.4825, -2.8682}, {-5.6792, 7.17572, -2.8682}, {-10.2358,10.4713, -2.8682}, {-8.00684, 7.69765, -2.8682}, {15.668, 2.64484, -2.8682}, {15.8232,10.4867, -2.8682}, {6.89941, 9.9433, -2.8682}, {15.6289, 5.74121, -2.8682}, {8.72412, -1.60283, -2.8682}, {8.59863, -4.65935, -2.8682}};
        };

        class Land_Barracks_01_dilapidated_F
        {
            table = "Military";
            positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088,1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957,1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393,1.98193, 3.93806}, {2.94727,1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
            };
        };

        class Land_Barracks_01_grey_F
        {
            table = "Military";
            positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088,1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957,1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393,1.98193, 3.93806}, {2.94727,1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
            };
        };

        class Land_Barracks_01_camo_F
        {
            table = "Military";
            positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088,1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957,1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393,1.98193, 3.93806}, {2.94727,1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
            };
        };

        class Land_BagBunker_01_large_green_F
        {
            table = "Military";
            positions[] = {{-3.14728, -3.43408, -0.839155}, {-1.14655,1.00586, -0.836318}, {3.11304, -3.87305, -0.834461}, {0.91864, 0.737793, -0.831506}, {-1.09125, 3.10645, -0.846669}
            };
        };

        class Land_HBarrier_01_tower_green_F
        {
            table = "Military";
            positions[] = {{0.400085,1.87744, 0.482887}, {-0.725647, -2.3208, 0.482884}, {-0.749512,1.93896, -2.29711}, {-0.959229, -2.50342, -2.29711}
            };
        };

        class Land_HBarrier_01_big_tower_green_F
        {
            table = "Military";
            positions[] = {{-0.0388794, -2.06543, -0.0721803}, {-0.5849,1.0791, -0.0721803}
            };
        };

        class Land_Cargo_House_V4_F
        {
            table = "Military";
            positions[] = {{1.93024, 3.46777, -0.134219}, {-1.99597, 0.757813, -0.270255}
            };
        };

        class Land_Cargo_HQ_V4_F
        {
            table = "Military";
            positions[] = {{-2.59113, -4.27148, -0.748882}, {-2.59424, 2.74121, -0.748883}, {6.12561, -1.43262, -0.748886}, {4.92139, 3.66553, -0.748884}, {2.82428, -4.5127, -0.673725}, {6.75214, 0.595215, -3.27373}, {3.83301, -4.36865, -3.27373}, {-1.38422, -4.49805, -3.27373}, {-1.2486, 2.95898, -3.27373}, {3.09406, 3.60059, -3.27373}
            };
        };

        class Land_Cargo_Patrol_V4_F
        {
            table = "Military";
            positions[] = {{1.79944, 0.629883, -2.9121}, {1.91803, -1.25488, -0.560959}, {-1.87482,1.36816, -0.764956}, {-1.87756, -1.37646, -0.560959}
            };
        };

        class Land_Cargo_Tower_V4_F
        {
            table = "Military";
            positions[] = {{-3.17126, 4.56006, 5.00328}, {4.43848, 3.68555, 5.00327}, {4.6236, -2.42139, 5.00327}, {-3.37885, -5.12842, 4.90572}, {-3.29187, -1.0376, 5.00328}, {0.343079,1.63135, 5.07844}, {-5.09668, 4.59131, 2.47844}, {-4.39246, -5.45313, 2.61447}, {-1.25903, -0.762695, 2.47844}, {6.07666, 4.14551, 2.6936}, {4.90717, -1.02637, 2.47844}, {1.21716, -0.616699, -0.121563}, {-4.05151, -3.43164, -0.121563}, {-3.77576, 4.30664, 0.108913}, {4.41241, 4.19043, -0.121563}, {-3.32153,1.43799, -4.29724}, {-2.58942, 3.13281, -4.29724}, {1.42841, 2.67432, -8.24476}
            };
        };

        class Land_PillboxBunker_01_big_F
        {
            table = "Military";
            positions[] = {{-2.7843, 4.40234, -0.79799}, {0.65155, 4.40039, -0.79799}, {3.16467, -0.414063, -0.79799}, {-0.919983,1.5918,1.43985}
            };
        };

        class Land_PillboxBunker_01_hex_F
        {
            table = "Military";
            positions[] = {{-1.9942, -0.828613, -0.959151}, {-2.32397,1.28271, -0.97937}
            };
        };

        class Land_PillboxBunker_01_rectangle_F
        {
            table = "Military";
            positions[] = {{-0.931946,1.00244, -0.390276}, {-1.341, -0.984375, 0.111176}
            };
        };

        class Land_Cathedral_01_F
        {
            table = "Civilian";
            positions[] = {{12.4813, -13.7446, -10.1117}, {11.6747, -9.44678, -11.2517}, {12.2565, -17.9878, -11.2227}, {3.78693, -14.6914, -12.7812}, {-3.62018, -15.4463, -12.7812}, {-12.1761, -18.0459, -11.2227}, {-12.5489, -13.8569, -10.1117}, {-11.6001, -9.25293, -11.2517}, {-7.80066, -13.1929, -8.7991}, {2.38251, -13.2998, -7.80105}, {-3.08685, -14.3218, -7.80105}, {7.91278, -13.8066, -8.7991}, {8.16644, -0.892578, -9.3812}, {-8.27832, -1.06299, -9.3812}
            };
        };

        class Land_Church_01_F
        {
            table = "Civilian";
            positions[] = {{8.10126, -0.416504, -9.91359}, {8.00543, 7.06006, -9.86603}, {-7.94092,1.38867, -9.84217}, {-7.92584, 8.74805, -9.84217}
            };
        };

        class Land_Church_02_F
        {
            table = "Civilian";
            positions[] = {{2.1095, -17.0308, -3.31493}, {-1.98883, -17.0156, -3.31492}
            };
        };

        class Land_Mausoleum_01_F
        {
            table = "Civilian";
            positions[] = {{1.35419, -1.64746, -1.89905}, {-1.00244,1.26172, -1.88787}
            };
        };

        class Land_GuardHouse_01_F
        {
            table = "Civilian";
            positions[] = {{4.39807,1.53076, -0.987735}, {-1.53021, 2.07129, -0.987734}, {3.81836, -4.1709, -1.00742}, {-1.42365, -0.541016, -1.00742}, {-1.45483, -4.01563, -1.00742}
            };
        };

        class Land_FuelStation_01_shop_F
        {
            table = "Commercial";
            positions[] = {{1.34039, -0.319824, -2.01301}, {-4.40387, -2.54102, -2.01301}, {-4.43878, -0.146484, -2.01301}, {-4.48163, 4.30127, -2.01301}, {1.37292,1.87549, -2.01301}
            };
        };

        class Land_FuelStation_02_workshop_F
        {
            table = "Mechanical";
            positions[] = {{-4.65692, 7.44629, -1.2575}, {-2.69397, -0.881348, -1.2575}, {3.96014, -0.874023, -1.2575}, {1.59766, 7.14111, -1.2575}, {4.02576, 3.44238, -1.2575}
            };
        };

        class Land_Hotel_01_F
        {
            table = "Commercial";
            positions[] = {{3.96973, -4.05664, -5.28721}, {3.93524, 4.78174, -5.28721}, {0.112183, 2.06885, -5.28721}, {-5.19159, 5.24316, -5.28721}, {-5.53912, -4.07227, -5.28721}, {-8.18829, 0.800781, -1.56211}, {-7.80768, 7.61572, -1.56212}, {6.01831, 7.55127, -1.56212}, {5.84296, -5.86084, -1.56211}, {-7.78247, -6.09717, -1.56211}, {-3.86163, 0.643066, -1.56212}, {-0.725769, 4.19727, -1.56212}, {2.85748, 0.849121, -1.56212}, {-1.03076, -3.27588, -1.56211}, {1.3125, 0.710449,1.68788}, {-0.789001, 4.49854,1.68789}, {-4.82312, 0.928711,1.68788}, {5.86011, 7.3125, 4.51359}, {6.05499, 7.36133,1.68789}, {-2.10968, 7.91797,1.68789}, {-7.46893, 7.12549,1.68789}, {6.11334, -6.15576,1.68788}, {-7.67957, -5.83838,1.68788}, {-7.62677,1.54541,1.68788}, {-7.32611, 7.44043, 4.51359}, {-7.36676, -5.59521, 4.51364}, {5.93842, -5.94629, 4.51364}, {-0.767456, 4.4707, 4.51355}, {-5.61255, -1.47998, 4.51355}, {3.86053, -4.14502, 4.51363}, {1.37054, -1.40869, 4.51358}
            };
        };

        class Land_Hotel_02_F
        {
            table = "Commercial";
            positions[] = {{6.9483, -0.910156, -3.38828}, {3.59357, 3.63965, -3.38828}, {-7.33313, -1.19873, -3.38828}, {-2.39691,1.2168, -3.38828}, {-1.81409,12.2061, -3.38828}, {-2.21124, -9.90088, -3.38828}, {-7.5498,1.07813, 0.107927}, {0.997925, 2.77393, 0.107927}, {4.06665, -0.816406, 0.226008}
            };
        };

        class Land_Offices_01_V1_F
        {
            table = "Commercial";
            positions[] = {{11.7757, 6.68115, -7.06043}, {9.26523,1.76611, -7.06043}, {-14.7141, 5.92773, -7.06043}, {0.595245, -5.12402, -7.06043}, {6.3175, -6.09131, -3.16043}, {6.37814, 2.47754, -3.1612}, {5.75436, -6.26221, 0.736337}, {5.70242, 2.3208, 0.755594}, {10.5309, -5.43262, 4.66112}, {10.5088, -1.64355, 4.65775}, {5.68307, 2.51416, 4.65285}, {10.9102, -5.58057, 9.85026}, {10.6314, 5.40381, 9.84746}, {-4.27469, -9.28857, 9.86152}, {-10.3628, -0.207031, 9.86283}, {-10.9413, -5.81445, 9.85157}, {-15.5463, -9.02832, 9.85218}, {-11.9033, 6.12891, 9.8623}};
        };

        class Land_Supermarket_01_F
        {
            table = "Commercial";
            positions[] = {{6.30194, -11.0469, -1.53671}, {-4.51752, -11.3296, -1.53671}, {0.467468, -10.2432, -1.53671}, {-4.89508, -7.5459, -1.48064}, {-0.474976, -0.0825195, -1.48064}, {-3.8714,1.80322, -1.48064}, {4.35724, -2.51172, -1.48064}, {7.13202, 2.08887, -1.48064}, {6.94672, 7.76709, -1.48064}, {3.10266, 7.8999, -1.48064}, {-4.03607,11.3711, -1.48064}, {-3.44031, 8.20215, -1.48064}, {4.05859,11.8423, -1.48064}
            };
        };

        class Land_Warehouse_02_F
        {
            table = "Industrial";
            positions[] = {{-2.4668, -12.4736, -3.92001}, {7.32794, -12.4351, -3.92001}, {14.8786, -12.542, -3.92001}
            };
        };

        class Land_StorageTank_01_small_F
        {
            table = "Industrial";
            positions[] = {{-16.3601, 0.801758, -1.05007}, {0.522583,1.60889, 4.88674}, {0.0722656, -0.759766, 4.88674}, {-1.02252,1.0459, 4.88673}
            };
        };

        class Land_StorageTank_01_large_F
        {
            table = "Industrial";
            positions[] = {{1.97491, 4.17188, 0.684248}, {8.29785, -9.72461, 0.684288}, {-11.0208, -3.45361, 0.684258}, {1.8186,17.9902,1.2294}, {19.0656, 0.043457, 2.1993}, {-6.35602, -16.9229,1.24216}, {15.979, -9.30664,1.22207}
            };
        };

        class Land_SM_01_reservoirTower_F
        {
            table = "Industrial";
            positions[] = {{0.744629, 2.54785, -1.95139}, {-0.625549, -2.69141, -1.95139}, {-2.89954,1.08691, -1.95139}
            };
        };

        class Land_WaterTower_01_F
        {
            table = "Industrial";
            positions[] = {{-0.0684204, -0.130371, 3.76693}
            };
        };

        class Land_House_Small_02_F
        {
            table = "Civilian";
            positions[] = {{-3.23962, -4.72266, -0.71564}, {-0.786072, -4.95947, -0.71564}, {-0.187805,1.87402, -0.71564}, {-3.37006, 4.82764, -0.71564}, {-3.28796,1.29834, -0.71564}
            };
        };

        class Land_House_Big_02_F
        {
            table = "Civilian";
            positions[] = {{7.52789, -7.47266, -1.44289}, {7.94958, 7.4585, -1.44289}, {-4.53009, 8.71436, -1.44289}, {-2.10052, 5.26074, -1.44289}, {0.351624,1.78467, -1.44289}, {4.65405, 3.19971, -1.44289}, {-9.56982, 3.0293, -1.44289}, {-5.66528, -0.0429688, -1.44289}
            };
        };

        class Land_House_Small_03_F
        {
            table = "Civilian";
            positions[] = {{1.85565, -1.06055, -1.32402}, {-1.10022, 4.04395, -1.32402}, {-3.39624, 4.35059, -1.32402}, {-5.51508, -1.06006, -1.32402}, {-3.18793, -1.27197, -1.32402}
            };
        };

        class Land_House_Small_06_F
        {
            table = "Civilian";
            positions[] = {{-3.56342,1.42627, -1.00212}, {-3.30609, -4.31396, -1.00212}, {1.72375, -4.1626, -1.00212}, {-3.36035, 4.01172, -1.00212}
            };
        };

        class Land_House_Big_01_F
        {
            table = "Civilian";
            positions[] = {{-0.168579, -2.8916, -1.01287}, {-6.79626, -3.13574, -1.01287}, {6.28888, -2.93799, -1.01287}, {6.88696, 4.87793, -1.01287}, {0.589661, 4.896, -1.01287}, {0.561768, -0.488281, -1.01287}, {6.22552, -0.22168, -1.01287}
            };
        };

        class Land_Shed_07_F
        {
            table = "Industrial";
            positions[] = {{3.49219, -1.09473, -1.39405}, {3.34741,1.29395, -1.39405}, {-3.42761, -0.976074, -1.39405}
            };
        };

        class Land_Shed_05_F
        {
            table = "Industrial";
            positions[] = {{-2.00177, 0.643066, -0.89049}, {1.9892, -1.92578, -0.89049}, {-2.02496, -2.06836, -0.89049}, {1.84515, 0.745605, -0.89049}
            };
        };

        class Land_Shed_02_F
        {
            table = "Industrial";
            positions[] = {{-1.11359,1.68359, -0.847519}, {0.985229, -0.0498047, -0.844183}
            };
        };

        class Land_Shed_03_F
        {
            table = "Industrial";
            positions[] = {{-0.726868, -0.477051, -0.707936}, {1.9704, -0.0673828, -0.707935}
            };
        };

        class Land_Slum_02_F
        {
            table = "Civilian";
            positions[] = {{3.38623, -0.645996, 0.183215}, {-1.6817, -3.64404, 0.183216}, {2.09442, -3.65576, 0.183216}, {-1.79016, 3.66748, 0.183216}, {1.58813, 2.20703, 0.183216}
            };
        };

        class Land_Slum_01_F
        {
            table = "Civilian";
            positions[] = {{-2.13098,1.81494, 0.641667}, {4.75482, -1.82471, 0.668514}, {-0.47876,1.56104, 0.668515}, {4.61261,1.65479, 0.668515}
            };
        };

        class Land_GarageShelter_01_F
        {
            table = "Mechanical";
            positions[] = {{4.01392, 2.63623, -1.25478}, {0.764343, -1.36768, -1.25478}, {-3.85114, 2.88916, -1.25478}, {-1.22278, -1.68896, -1.25478}
            };
        };

        class Land_Shop_Town_03_F
        {
            table = "Commercial";
            positions[] = {{-0.00872803, -8.08594, -3.36008}, {-5.54944, -8.7085, -3.36202}, {-5.9541, -0.202637, -3.35966}, {-2.71411, -2.58154, -3.35966}, {-0.143982, -0.276855, -3.35966}, {5.16455, -5.21777, -3.35966}, {5.52393, -0.544434, -3.35966}, {-5.91083, 5.50439, -3.35966}, {0.127686, 7.56934, -3.35966}, {2.57611, 2.4585, -3.35966}, {5.67163, 7.2915, -3.35966}
            };
        };

        class Land_Shop_Town_05_F
        {
            table = "Commercial";
            positions[] = {{7.25494, -6.48438, -2.70163}, {-4.45245, -6.21143, -2.70163}, {2.8161, -6.51611, -2.70163}
            };
        };

        class Land_Shop_Town_01_F
        {
            table = "Commercial";
            positions[] = {{3.24677, -6.03857, -3.24511}, {-3.33325, -5.69287, -3.24511}, {-3.68738,1.44141, -3.24511}, {3.55231, -2.40527, -3.24511}, {-3.48401, -3.26318, -3.24511}, {-3.72571, 4.51416, -3.24511}
            };
        };

        class Land_House_Small_01_F
        {
            table = "Civilian";
            positions[] = {{5.71362, 2.77393, -0.700801}, {1.74152, 2.91113, -0.700801}, {1.97015, -3.09521, -0.700801}, {5.78699, -2.71338, -0.700801}, {-5.24707, 2.52246, -0.700801}, {-0.623718, 2.41797, -0.700801}, {-5.39386, -2.89844, -0.700801}, {-1.83771, -2.96729, -0.700801}
            };
        };

        class Land_Slum_03_F
        {
            table = "Civilian";
            positions[] = {{-5.96301, -3.12549, -0.649454}, {4.46039, -2.96729, -0.649454}, {-6.04901, 0.859863, -0.649454}, {-0.613708, -0.942871, -0.649454}, {-4.32275,1.02051, -0.649454}, {-4.48254, 6.70654, -0.649455}, {-0.675964, 3.31787, -0.649454}, {1.74304, 2.79688, -0.649454}, {3.23267, 6.64746, -0.649455}, {2.06952, -0.73877, -0.649455}
            };
        };

        class Land_Shop_Town_04_F
        {
            table = "Commercial";
            positions[] = {{-3.46161, -6.2124, -2.43639}, {3.01746, -6.52197, -2.43639}
            };
        };

        class Land_Shop_Town_02_F
        {
            table = "Commercial";
            positions[] = {{-3.1637, -4.87451, -2.14306}, {3.44916, -4.88867, -2.14306}
            };
        };

        class Land_Shed_01_F
        {
            table = "Mechanical";
            positions[] = {{1.75861,1.10742, -0.914464}, {0.0146484,1.12256, -0.914464}, {-1.73743,1.06445, -0.914464}
            };
        };

        class Land_Shed_04_F
        {
            table = "Mechanical";
            positions[] = {{-0.0791626, 0.706543, -0.721425}
            };
        };
        class Land_Shed_W4
        {
            table = "Mechanical";
            positions[] =
            {
                {1.73682,3.6377,-1.31815},
                {-1.80176,2.46289,-1.31815},
                {-1.05566,-1.75488,-1.31815},
                {2.06885,-1.13672,-1.31815}
            };
        };

        class Land_Shed_W01
        {
            table = "Mechanical";
            positions[] =
            {
                {1.5249,0.228516,-1.34076},
                {-1.34961,0.0869141,-1.34076}
            };
        };
    
        class Land_Shed_W02
        {
            table = "Mechanical";
            positions[] =
            {
                {0.447266,2.37109,0.100006},
                {-1.81152,0.0478516,0.100006}
            };
        };
    
        class Land_Shed_M01
        {
            table = "Mechanical";
            positions[] =
            {
                {-0.984375,-0.0146484,-1.11377}
            };
        };
    
        class Land_Shed_M03
        {
            table = "Mechanical";
            positions[] =
            {
                {-0.32959,-0.160156,-0.93576}
            };
        };
    
        class Land_Shed_W03
        {
            table = "Mechanical";
            positions[] =
            {
                {-1.51318,0.166016,-0.782166},
                {1.52832,1.12695,-0.782166}
            };
        };
    };
};
class CfgVehicleSpawns {
	class Buildings {	
		//air
		class Land_Ss_hangard {locations[] = {{0.605835,-4.5835,-5.91507}};directions[] = {182.505};};
		class Land_Ss_hangar {locations[] = {{0.0341797,-6.04883,-5.91507}};directions[] = {182.505};};
		class WarfareBAirport {locations[] = {{-0.204224,-0.669434,-5.91507}};directions[] = {182.505};};
		class Land_Mil_hangar_EP1 {locations[] = {{0.543823,-0.458984,-5.42382}};directions[] = {182.505};};

		class Land_A_Hospital {locations[] = {{4.33032,-4.32495,3.2904}};directions[] = {98.3031};};
		
		//helis
		
		class VR_Area_01_square_2x2_grey_F {locations[] = {{11252.138,313.01895,9395.2529}};directions[] = {1.469};};
		class VR_GroundIcon_01_F {locations[] = {{2215.51,337.31476,17953.355}};directions[] = {65.092};};
		class VR_Area_01_square_1x1_yellow_F {locations[] = {{8517.9189,179.5739,17030.416}};directions[] = {119.259};};
		class VR_Area_01_square_1x1_grey_F {locations[] = {{2099.135,31.222525,5086.3569}};directions[] = {62.243};};
		class VR_Area_01_circle_4_yellow_F {locations[] = {{4654.5967,338.98053,15365.902}};directions[] = {288.191};};
		class VR_Area_01_circle_4_grey_F {locations[] = {{2566.637,193.9805,10184.65}};directions[] = {150.941};}; 

		//water
		class Land_Nav_Boathouse {locations[] = {{2.77588,1.64014,2.87225},{-2.92737,-1.27783,2.87226}};directions[] = {183.33,183.33};};
		class Sign_Sphere100cm_Geometry_F {locations[] = {{13227.927,0,13307.267},{13221.189,0,15169.317},{13548.745,0,18870.107}};;directions[] = {169.357,203.627,109.952}; };

		//bike
		class Land_A_Villa_dam_EP1 {locations[] = {{1.68018,-4.86719,-5.5403}};directions[] = {-82.6785};};
		class Land_A_BuildingWIP {locations[] = {{7.49622,8.90771,-6.39662}};directions[] = {55.0266};};
		class Land_House_C_10_dam_EP1 {locations[] = {{-1.32324,3.52832,-2.21058}};directions[] = {-89.0262};};
		class Land_House_C_4_EP1 {locations[] = {{-2.84558,-4.96045,-4.05999}};directions[] = {266.003};};
		class Land_House_C_10_EP1 {locations[] = {{-2.33752,3.36572,-4.17852}};directions[] = {266.003};};
		class Land_A_BuildingWIP_EP1 {locations[] = {{-14.834,-14.0762,-6.50464}};directions[] = {81.7221};};
		class Land_Dum_istan4_big {locations[] = {{-0.84082,5.79785,-10.29}};directions[] = {78.0132};};
		class Land_Dum_istan4 {locations[] = {{-0.756226,6.13281,-7.2938}};directions[] = {77.5515};};
		class Land_House_C_2_DAM_EP1 {locations[] = {{4.32861,-3.77246,-1.8373}};directions[] = {266.003};};
		class Land_House_C_2_EP1 {locations[] = {{5.10828,-3.7832,-2.43191}};directions[] = {266.003};};
		class Land_House_C_1_v2_dam_EP1 {locations[] = {{-0.833618,-0.900879,-1.44163}};directions[] = {0};};
		class Land_House_C_1_EP1 {locations[] = {{-1.02222,-0.535645,-1.02564}};directions[] = {0};};

		//small car
		class Land_Benzina_schnell {locations[] = {{-0.163086,-0.973083,-2.28967},{-0.362305,-6.73993,-2.28967}};directions[] = {82.1838,-91.3002};};
		class Land_Kasarna_prujezd {locations[] = {{0.0734863,-0.756836,-8.73949}};directions[] = {179.713};};
		class Land_HouseBlock_A1_1 {locations[] = {{-4.1897,-2.60547,-4.72375}};directions[] = {179.713};};
		class Land_HouseBlock_A1 {locations[] = {{-4.18091,-2.50195,-8.8069}};directions[] = {179.713};};
		class Land_HouseBlock_A3 {locations[] = {{0.00952148,-1.41016,-5.44316}};directions[] = {179.713};};
		class Land_HouseBlock_B6 {locations[] = {{-4.0896,-1.52197,-7.62031}};directions[] = {178.602};};
		class Land_Barn_W_01 {locations[] = {{2.57849,-1.63721,-2.63476}};directions[] = {185.234};};
		class Land_Barn_W_02 {locations[] = {{2.1134,2.39746,-2.31528}};directions[] = {185.234};};
		class Land_Barn_W_01_dam {locations[] = {{2.46631,-5.99512,-2.63399}};directions[] = {185.234};};

		//large car
		class Land_FuelStation_Shed_PMC {locations[] = {{-3.70422,-0.61084,-3.03309},{3.4884,-0.416992,-3.03309}};directions[] = {179.713,2.22761};};
		class Land_A_FuelStation_Shed {locations[] = {{-3.44031,-0.324219,-3.17141},{3.45264,-0.713379,-3.17141}};directions[] = {179.713,3.19362};};
		class Land_Ind_FuelStation_Shed_EP1 {locations[] = {{-3.24402,-1.00879,-3.03309},{3.03516,-0.0151367,-3.03309}};directions[] = {179.713,355.358};};
		class Land_Hangar_2 {locations[] = {{9.83496,2.92285,-2.56463},{-7.33044,4.56055,-2.56463}};directions[] = {199.768,161.957};};
		class Land_A_Stationhouse_ep1 {locations[] = {{3.82056,-0.645996,-9.47203},{10.0288,-0.380371,-9.47203},{15.7979,0.135742,-9.47203}};directions[] = {179.713,179.713,179.713};};
		class Land_a_stationhouse {locations[] = {{3.70081,-0.908691,-9.47203},{9.73267,-0.664063,-9.47203},{16.1388,-0.929688,-9.47203}};directions[] = {179.713,179.713,179.713};};
		class Land_Ind_Vysypka {locations[] = {{2.48682,17.3027,-4.97203}};directions[] = {49.982};};

		//military
		class Sign_sphere100cm_EP1 {locations[] = {{2178.2961,175.35593,10351.612},{6968.3804,363.43835,17025.635}};directions[] = {89.96,211.367};};
		class Sign_sphere10cm_EP1 {locations[] = {{3453.2288,171.31532,8930.5498},{12089.489,158.83798,17749.654},{4598.502,338.93109,14711.096},{4882.1768,5.4813924,7440.8931}};directions[] = {323.503,339.279,32.945,136.766};};
		class Sign_sphere25cm_EP1 {locations[] = {{9393.9102,324.5314,14086.41},{7085.854,5.9699998,7852.0933},{11465.112,220.98,12586.184},{3690.6721,401.98999,11117.439},{}};directions[] = {228.805,145.504,107.819,9.772,127.154};};
		class Sr_border {locations[] = {{7219.978,7.0267053,7337.5278},{10186.237,23.290001,7426.502},{12126.583,3.1019135,8564.333},{4156.4712,323.96057,14030.575},{1600.512,283.96033,12905.654},{7136.6558,279.98846,12625.506},{6561.6172,386.2883,10734.502},{9110.9893,258.15378,9239.6338}};directions[] = {45.869,106.253,278.447,58.283,111.989,93.688,191.258,219.334};};
	};
	class Vehicles {
		//--- transport trucks
		class RHS_Ural_MSV_01 {
			class Spawns {
				class Sign_sphere25cm_EP1 {};
			};
		};
		class rhs_gaz66_msv {
			class Spawns {
				class Sign_sphere25cm_EP1 {};
			};
		};
		class C_Truck_02_transport_F {
			class Spawns {
				class Sign_sphere25cm_EP1 {};
			};
		};
		class B_Truck_01_fuel_F {
			class Spawns {
				class Sign_sphere25cm_EP1 {};
			};
		};
		//--- industrial
		class C_Van_01_box_F {
			class Spawns {
				class Land_FuelStation_Shed_PMC {};
				class Land_A_FuelStation_Shed {};
				class Land_Ind_FuelStation_Shed_EP1 {};
				class Land_Hangar_2 {};
				class Land_A_Stationhouse_ep1 {};
				class Land_a_stationhouse {};
				class Land_Ind_Vysypka {};
			};
		};
		class DSR_Hilux_Open_3_F {
			class Spawns {
				class Land_FuelStation_Shed_PMC {};
				class Land_A_FuelStation_Shed {};
				class Land_Ind_FuelStation_Shed_EP1 {};
				class Land_Hangar_2 {};
				class Land_A_Stationhouse_ep1 {};
				class Land_a_stationhouse {};
				class Land_Ind_Vysypka {};
			};
		};
		class DSR_Hilux_Open_4_F {
			class Spawns {
				class Land_FuelStation_Shed_PMC {};
				class Land_A_FuelStation_Shed {};
				class Land_Ind_FuelStation_Shed_EP1 {};
				class Land_Hangar_2 {};
				class Land_A_Stationhouse_ep1 {};
				class Land_a_stationhouse {};
				class Land_Ind_Vysypka {};
			};
		};

		//--- military
		class rhsusf_mrzr4_w_mud {
			class Spawns {
				class Sign_sphere100cm_EP1 {};
			};
		class rhsusf_m998_w_s_4dr_fulltop {
			class Spawns {
				class Sign_sphere10cm_EP1 {};
			};
		class rhsusf_m998_w_s_2dr {
			class Spawns {
				class Sign_sphere10cm_EP1 {};
			};
		class rhs_tigr_m_3camo_msv {
			class Spawns {
				class Sr_border {};
			};
		class rhs_uaz_vv {
			class Spawns {
				class Sr_border {};
			};
		class DSR_SUV_2_F {
			class Spawns {
				class Sr_border {};
			};
		class rhsgref_cdf_b_reg_uaz {
			class Spawns {
				class Sr_border {};
			};			
		};

		//--- civ
		class DSR_SUV_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_SUV_Camo_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hilux_Open_4_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hilux_Covered_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hatchback_Black_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hatchback_Blue_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hatchback_Green_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class DSR_Hatchback_Silver_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		//--- quads
		class B_Quadbike_01_Fsa {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};
		class I_G_Quadbike_01_F {
			class Spawns {
				class Land_Benzina_schnell {};
				class Land_Kasarna_prujezd {};
				class Land_HouseBlock_A1_1 {};
				class Land_HouseBlock_A1 {};
				class Land_HouseBlock_A3 {};
				class Land_HouseBlock_B6 {};
				class Land_Barn_W_01 {};
				class Land_Barn_W_02 {};
				class Land_Barn_W_01_dam {};
			};
		};		//--- bikes
		class DSR_Bike_White_F {
			class Spawns {
				class Land_A_Villa_dam_EP1 {};
				class Land_A_BuildingWIP {};
				class Land_House_C_10_dam_EP1 {};
				class Land_House_C_4_EP1 {};
				class Land_House_C_10_EP1 {};
				class Land_A_BuildingWIP_EP1 {};
				class Land_Dum_istan4_big {};
				class Land_Dum_istan4 {};
				class Land_House_C_2_DAM_EP1 {};
				class Land_House_C_2_EP1 {};
				class Land_House_C_1_v2_dam_EP1 {};
				class Land_House_C_1_EP1 {};
			};
		};
		class DSR_Bike_Green_F {
			class Spawns {
				class Land_A_Villa_dam_EP1 {};
				class Land_A_BuildingWIP {};
				class Land_House_C_10_dam_EP1 {};
				class Land_House_C_4_EP1 {};
				class Land_House_C_10_EP1 {};
				class Land_A_BuildingWIP_EP1 {};
				class Land_Dum_istan4_big {};
				class Land_Dum_istan4 {};
				class Land_House_C_2_DAM_EP1 {};
				class Land_House_C_2_EP1 {};
				class Land_House_C_1_v2_dam_EP1 {};
				class Land_House_C_1_EP1 {};
			};
		};
		
		//--- plans
		class RHS_AN2_B {
			class Spawns {
				class Land_Ss_hangard {};
				class Land_Ss_hangar {};
				class WarfareBAirport {};
				class Land_Mil_hangar_EP1 {};
			};
		///class DSR_C130J_F {
		///	class Spawns {
		///		class HeliHEmpty {};
		///	};
		///};
		class DSR_AN2_F {
			class Spawns {
				class Land_Ss_hangard {};
				class Land_Ss_hangar {};
				class WarfareBAirport {};
				class Land_Mil_hangar_EP1 {};
			};
		};

		//--- jelli's
		class RHS_MELB_MH6M {
			class Spawns {
				class VR_GroundIcon_01_F { };
			};
		};
		class RHS_UH60M2_d {
			class Spawns {
				class VR_Area_01_circle_4_grey_F { };
			};
		};
		class I_C_Heli_Light_01_civil_F {
			class Spawns {
				class VR_Area_01_square_2x2_grey_F { };
			};
		};
		class rhsgref_ins_Mi8amt {
			class Spawns {
				class VR_Area_01_circle_4_yellow_F { };
			};
		class RHS_Mi8AMT_civilian {	
			class Spawns {
				class VR_Area_01_square_1x1_grey_F { };
			};
		};
		class RHS_UH1Y_UNARMED {	
			class Spawns {
				class VR_Area_01_square_1x1_yellow_F { };
			};
		};
		
		//--- boats
		class DSR_FishingBoat_F {
			class Spawns {
				class Sign_Sphere100cm_Geometry_F {};
			};
		};
		class DSR_Dingy_F {
			class Spawns {
				class Land_Nav_Boathouse {};
			};
		};
		class DSR_Raft_F {
			class Spawns {
				class Land_Nav_Boathouse {};
			};
		};
		class O_Lifeboat {
			class Spawns {
				class Land_Nav_Boathouse {};
			};
		};		
	};
};
class CfgBuildables {
    class Type1Houses {
        condition = "true"; 
        preview = "\dsr_ui\Assets\object_previews\preview_house_lv1.paa"; 
        name = "Type 1 Houses"; 
        class Buildables {
            class HouseLvl1 {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Lumber",30},
                    {"DSR_Item_Plywood",7},
                    {"DSR_Item_Hardware",5},
                    {"DSR_Item_Logs",15}
                };
                name = "Lvl 1 House V1";
                model = "DSR_Object_House_Lv1";
                crateObject = "DSR_Object_House_Lv1_Preview2";
                description = "The small shack is small... and a shack... a good starting house for losers.";
                preview = "\dsr_ui\Assets\object_previews\preview_house_lv1.paa";
                condition = "true";
            };
            class HouseLvl1v2 {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Tarp",1},
                    {"DSR_Item_Bricks",3},
                    {"DSR_Item_Lumber",30},
                    {"DSR_Item_Plywood",7},
                    {"DSR_Item_Hardware",5},
                    {"DSR_Item_Logs",15}
                };
                name = "Lvl 1 House V2";
                model = "DSR_Object_House_Lv1_2";
                crateObject = "DSR_Object_House_Lv1_2_Preview2";
                description = "The small shack is small... and a shack... a good starting house for losers.";
                preview = "\dsr_ui\Assets\object_previews\preview_house_lv1_2.paa";
                condition = "true";
            };
            class HouseLvl2 {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Lumber",60},
                    {"DSR_Item_Plywood",14},
                    {"DSR_Item_Hardware",10},
                    {"DSR_Item_Logs",45}
                };
                name = "Lvl 2 House V1";
                model = "DSR_Object_House_Lv2";
                crateObject = "DSR_Object_House_Lv2_Preview2";
                description = "Large wood shack.";
                preview = "\dsr_ui\Assets\object_previews\preview_house_lv2.paa";
                condition = "true";
            };
            class HouseLvl3 {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Lumber",120},
                    {"DSR_Item_Plywood",34},
                    {"DSR_Item_Hardware",20},
                    {"DSR_Item_Scrap_Metal",2},
                    {"DSR_Item_Logs",85}
                };
                name = "Lvl 3 House V1";
                model = "DSR_Object_House_Lv3";
                crateObject = "DSR_Object_House_Lv3_Preview2";
                description = "A small Wood Cabin.";
                preview = "\dsr_ui\Assets\object_previews\preview_house_lv3.paa";
                condition = "true";
            };
        };
    };
    class Stockade {
        condition = "true"; 
        preview = "\dsr_ui\Assets\object_previews\preview_stockade_wall.paa";  
        name = "Stockade Items";  
        class Buildables {
            class StockadeWall {
                parts[] = {
                    {"DSR_Item_Lumber",23},
                    {"DSR_Item_Hardware",4}
                };
                name = "Stockade Wall";
                model = "DSR_Object_Stockade_Wall";
                crateObject = "DSR_Object_Stockade_Wall_Preview2";
                description = "Basic stockade wall piece";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_wall.paa";
                condition = "true";
            };
            class StockadeWallWindow {
                parts[] = {
                    {"DSR_Item_Lumber",23},
                    {"DSR_Item_Hardware",6},
                    {"DSR_Item_Scrap_Metal",1}
                };
                name = "Stockade Wall (Window)";
                model = "DSR_Object_Stockade_Wall_Window";
                crateObject = "DSR_Object_Stockade_Wall_Window_Preview2";
                description = "Basic stockade wall piece";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_window.paa";
                condition = "true";
            };
            class StockadeRampart {
                parts[] = {
                    {"DSR_Item_Lumber",45},
                    {"DSR_Item_Hardware",6}
                };
                name = "Stockade Wall (Ramp)";
                model = "DSR_Object_Stockade_Rampart";
                crateObject = "DSR_Object_Stockade_Rampart_Preview2";
                description = "Stockade Wall with Rampart and Ramp";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_rampart.paa";
                condition = "true";
            };
            class StockadeRampart_2 {
                parts[] = {
                    {"DSR_Item_Lumber",38},
                    {"DSR_Item_Hardware",5}
                };
                name = "Stockade Wall (Walkway)";
                model = "DSR_Object_Stockade_Rampart_2";
                crateObject = "DSR_Object_Stockade_Rampart_2_Preview2";
                description = "Stockade Wall with Rampart";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_rampart_2.paa";
                condition = "true";
            };
            class StockadeGate {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Lumber",30},
                    {"DSR_Item_Hardware",4},
                    {"DSR_Item_Scrap_Metal",2},
                    {"DSR_Item_Logs",2}
                };
                name = "Stockade Gate";
                model = "DSR_Object_Stockade_Gate";
                crateObject = "DSR_Object_Stockade_Gate_Preview2";
                description = "Stockade Wall with Rampart";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_gate.paa";
                condition = "true";
            };
            class StockadeTower {
                parts[] = {
                    {"DSR_Item_Lumber",40},
                    {"DSR_Item_Hardware",10},
                    {"DSR_Item_Scrap_Metal",4},
                    {"DSR_Item_Logs",10}
                };
                name = "Stockade Guard Tower";
                model = "DSR_Object_Stockade_Tower";
                crateObject = "DSR_Object_Stockade_Tower_Preview2";
                description = "Stockade Guard Tower";
                preview = "\dsr_ui\Assets\object_previews\preview_stockade_tower.paa";
                condition = "true";
            };
        };
    };
    class Misc {
        condition = "true"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";  
        name = "Miscellaneous";  
        class Buildables {
            
            class Crate_Small {
                parts[] = {
                    {"DSR_Item_Lumber",4},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Scrap_Metal",1}
                };
                name = "Small Crate";
                model = "DSR_Object_Storage_Small";
                description = "A small storage container";
                preview = "\dsr_ui\Assets\object_previews\preview_storage_small.paa";
                crateObject = "DSR_Object_Storage_Small_Preview2";
                condition = "true";
            };
            class Crate_Large {
                parts[] = {
                    {"DSR_Item_Lumber",6},
                    {"DSR_Item_Hardware",2},
                    {"DSR_Item_Scrap_Metal",2}
                };
                name = "Large Crate";
                model = "DSR_Object_Storage_Large";
                description = "A large storage container";
                preview = "\dsr_ui\Assets\object_previews\preview_storage_large.paa";
                crateObject = "DSR_Object_Storage_Large_Preview2";
                condition = "true";
            };
            class Camp_Fire {
                parts[] = {
                    {"DSR_Item_Logs",4}
                };
                name = "Campfire";
                model = "Land_FirePlace_F";
                description = "A Simple Campfire";
                preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
                crateObject = "DSR_Object_Storage_Small_Preview2";
                condition = "true";
            };
            class Camp_Fire_Tripod {
                parts[] = {
                    {"DSR_Item_Logs",4},
                    {"DSR_Item_Scrap_Metal",2}
                };
                name = "Campfire w/ Tripod";
                model = "DSR_Object_Campfire_Tripod";
                description = "A Survival Campfire";
                preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
                crateObject = "DSR_Object_Storage_Small_Preview2";
                condition = "true";
            };
            class Workbench {
                parts[] = {
                    {"DSR_Item_Lumber",10},
                    {"DSR_Item_Hardware",1},
                    {"DSR_Item_Scrap_Metal",1}
                };
                name = "Workbench";
                model = "DSR_Object_Workbench";
                crateObject = "DSR_Object_Workbench_Preview2";
                description = "Crafting Workbench";
                preview = "\dsr_ui\Assets\object_previews\preview_workbench.paa";
                condition = "true";
            };
            class WaterCatchment {
                parts[] = {
                    {"DSR_Item_Logs",6},
                    {"DSR_Item_Duct_Tape",1},
                    {"DSR_Item_Tarp",1},
                    {"DSR_Item_Plastic_Drum",1}
                };
                name = "Water Catch";
                model = "DSR_Object_Water_Catchment";
                crateObject = "DSR_Object_Water_Catchment_Preview2";
                description = "System for catching rain water";
                preview = "\dsr_ui\Assets\object_previews\preview_water_catch.paa";
                condition = "true";
            };
            class StorageShed {
                parts[] = {
                    {"DSR_Item_Padlock",1},
                    {"DSR_Item_Lumber",50},
                    {"DSR_Item_Plywood",6},
                    {"DSR_Item_Hardware",10},
                    {"DSR_Item_Scrap_Metal",10},
                    {"DSR_Item_Logs",20}
                };
                name = "Storage Shed";
                model = "DSR_Object_Storage_Shed";
                crateObject = "DSR_Object_Storageshed_Preview2";
                description = "A place to store stuff.";
                preview = "\dsr_ui\Assets\object_previews\preview_storage_shed.paa";
                condition = "true";
            };
            class Cot {
                parts[] = {
                    {"DSR_Item_Scrap_Metal",4},
                    {"DSR_Item_Tarp",1}
                };
                name = "Sleeping Cot";
                model = "DSR_Object_Cot";
                crateObject = "DSR_Object_Cot_Preview";
                description = "A place to sleep, when implemented.";
                preview = "\dsr_ui\Assets\object_previews\preview_cot.paa";
                condition = "true";
            };
            class Anvil {
                parts[] = {
                    {"DSR_Item_Logs",1},
                    {"DSR_Item_Scrap_Metal",10}
                };
                name = "Smithing Anvil";
                model = "DSR_Object_Anvil_Log";
                crateObject = "DSR_Object_Anvil_Log_Preview";
                description = "A place to metalwork, once implemented.";
                preview = "\dsr_ui\Assets\object_previews\preview_anvil&log.paa";
                condition = "true";
            };
            class Farm1 {
                parts[] = {
                    {"DSR_Item_Plywood",4},
                    {"DSR_Item_Hardware",3},
                    {"DSR_Item_Fertilizer",2}
                };
                name = "Farming Plot (Small)";
                model = "DSR_Object_Woodplot_Small";
                crateObject = "DSR_Object_Woodplot_Small_Preview";
                description = "A place to farm, once implemented.";
                preview = "\dsr_ui\Assets\object_previews\preview_anvil&log.paa";
                condition = "true";
            };
            class Farm2 {
                parts[] = {
                    {"DSR_Item_Plywood",8},
                    {"DSR_Item_Hardware",6},
                    {"DSR_Item_Fertilizer",4}
                };
                name = "Farming Plot (Medium)";
                model = "DSR_Object_Woodplot_Med";
                crateObject = "DSR_Object_Woodplot_Med_Preview";
                description = "A place to farm, once implemented.";
                preview = "\dsr_ui\Assets\object_previews\preview_anvil&log.paa";
                condition = "true";
            };
            class Farm3 {
                parts[] = {
                    {"DSR_Item_Plywood",12},
                    {"DSR_Item_Hardware",9},
                    {"DSR_Item_Fertilizer",6}
                };
                name = "Farming Plot (Large)";
                model = "DSR_Object_Woodplot_Large";
                crateObject = "DSR_Object_Woodplot_Large_Preview";
                description = "A place to farm, once implemented.";
                preview = "\dsr_ui\Assets\object_previews\preview_anvil&log.paa";
                condition = "true";
            };
        };
    };
};
class CfgCraftables {
    class Materials {
        condition = "true"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa"; 
        name = "Materials"; 
        class Craftables {
            class Lumber {
                input[] = {
                    {"DSR_Item_Logs",1},
                    {"DSR_Item_Saw",1}
                };
                output[] = {
                    {"DSR_Item_Lumber",1},
                    {"DSR_Item_Saw",1}
                };
                requiredBuildings[] = {};
                
                name = "Lumber";
                description = "General Purpose Lumber.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
                condition = "true";
            };
            class Plywood {
                input[] = {
                    {"DSR_Item_Lumber",4},
                    {"DSR_Item_Saw",1},
                    {"DSR_Item_Toolbox",1}
                };
                output[] = {
                    {"DSR_Item_Plywood",1},
                    {"DSR_Item_Saw",1},
                    {"DSR_Item_Toolbox",1}
                };
                requiredBuildings[] = {"DSR_Object_Workbench"};
                
                name = "Plywood";
                description = "General Purpose Plywood.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
                condition = "true";
            };
            class ScrapMetal {
                input[] = {
                    {"DSR_Item_Crushed_Can",6},
                    {"DSR_Item_Butane_Torch",1}
                };
                output[] = {
                    {"DSR_Item_Scrap_Metal",1},
                    {"DSR_Item_Butane_Torch",1}
                };
                requiredBuildings[] = {"DSR_Object_Anvil_Log"};
                
                name = "Scrap Metal";
                description = "General Purpose Scrap Metal.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";     
                condition = "true";
            };
        };
    };
    class Tools {
        condition = "true"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa"; 
        name = "Tools"; 
        class Craftables {
            /*class FishingRod {
                input[] = {
                    {"DSR_Item_Fishingrod_Broken",1},
                    {"DSR_Item_Duct_Tape",1}
                };
                output[] = {
                    {"DSR_Melee_Fishingrod",1}
                };
                requiredBuildings[] = {};
                
                name = "Fishing Rod";
                description = "Great for catching small fishies.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
                condition = "true";
            };*/
        };
    };
    class Food {
        condition = "true"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa"; 
        name = "Food"; 
        class Craftables {
            
        };
    };
    class Gear {
        condition = "false";
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa"; 
        name = "Gear";
        class Craftables {
            
        };
    };
    class Weapons {
        condition = "false"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
        name = "Weapons"; 
        class Craftables {
            
        };
    };
    class Medical {
        condition = "true"; 
        preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
        name = "Medical"; 
        class Craftables {
            class Splint {
                input[] = {
                    {"dsr_item_Lumber",1},
                    {"DSR_Item_Bandage",2}
                };
                output[] = {
                    {"DSR_Item_Splint",1}
                };
                requiredBuildings[] = {};
                
                name = "Splint";
                description = "Fixes broken legs.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
                condition = "true";
            };
            class Bandage {
                input[] = {
                    {"DSR_Item_Fabric_Scraps",2},
                    {"DSR_Item_Duct_Tape",1}
                };
                output[] = {
                    {"DSR_Item_Makeshift_Bandage",1}
                };
                requiredBuildings[] = {};
                
                name = "Makeshift Bandage";
                description = "Stops bleeding wounds.";
                preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
                condition = "true";
            };
        };
    };
};
