/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bde10; label: FUN_004bde10
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004bde10(int param_1)

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int local_100c;
  int local_1008;
  int local_1004;
  int local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x4bde1a;
  iVar6 = *(int *)(param_1 + 0x4b10);
  iVar5 = 0;
  local_100c = 0;
  if (0 < iVar6) {
    psVar3 = (short *)(param_1 + 0x471c);
    do {
      local_1000[iVar5] = (int)*psVar3;
      iVar5 = iVar5 + 1;
      psVar3 = psVar3 + 8;
      iVar6 = iVar6 + -1;
      local_100c = iVar5;
    } while (iVar6 != 0);
  }
  if (0 < *(int *)(param_1 + 0x46e4)) {
    FUN_005485f0("fly_paddle_rotate_lp",local_1000,&local_100c,0x400);
    FUN_005485f0("fly_paddle_stuck",local_1000,&local_100c,0x400);
  }
  if (0 < *(int *)(param_1 + 0x4684)) {
    FUN_005485f0("env_door_flap",local_1000,&local_100c,0x400);
  }
  FUN_005479b0(0x50,local_1000,&local_100c,0x400);
  FUN_005479b0(0x51,local_1000,&local_100c,0x400);
  FUN_005479b0(0x52,local_1000,&local_100c,0x400);
  FUN_005485f0("Grv_GuardWeaponLp",local_1000,&local_100c,0x400);
  if (*(int *)(param_1 + 0x46ec) != 0) {
    if (*(int *)(param_1 + 0x128) == DAT_0087b224) {
      FUN_005485f0("CarbonFreezeCraneLp",local_1000,&local_100c,0x400);
      FUN_005485f0("CarbonFreezeCrane",local_1000,&local_100c,0x400);
    }
    else {
      if (*(int *)(param_1 + 0x128) == DAT_0087b284) {
        pcVar8 = "env_hover_box_lp";
      }
      else {
        pcVar8 = "env_crane_mvt_lp";
      }
      FUN_005485f0(pcVar8,local_1000,&local_100c,0x400);
    }
    FUN_005485f0("env_crane_in",local_1000,&local_100c,0x400);
    FUN_005485f0("env_grabber_down",local_1000,&local_100c,0x400);
    FUN_005485f0("env_grabber_pickup",local_1000,&local_100c,0x400);
    FUN_005485f0("env_grabber_up",local_1000,&local_100c,0x400);
    FUN_005485f0("Explode2",local_1000,&local_100c,0x400);
    if (*(int *)(param_1 + 0x128) == DAT_0087b220) {
      FUN_005485f0("imp_C3PO_magnet",local_1000,&local_100c,0x400);
      FUN_005485f0("imp_C3PO_magnet_drop",local_1000,&local_100c,0x400);
    }
  }
  piVar2 = *(int **)(param_1 + 0x2ab0);
  if ((piVar2 != (int *)0x0) && (iVar5 = 0, iVar6 = local_100c, 0 < piVar2[1])) {
    do {
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0x70);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0x84);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0x98);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0xac);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0xc0);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar7 = (int)*(short *)(*(int *)(*piVar2 + iVar5 * 4) + 0xd4);
      if (iVar7 != -1) {
        local_1000[iVar6] = iVar7;
        iVar6 = iVar6 + 1;
        local_100c = iVar6;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < piVar2[1]);
  }
  FUN_005a3450(*(undefined4 *)(param_1 + 0x5050),local_1000,&local_100c,0x400);
  if ((*(int **)(param_1 + 0x5074) != (int *)0x0) && (0 < **(int **)(param_1 + 0x5074))) {
    FUN_005485f0("SwLever",local_1000,&local_100c,0x400);
    FUN_005485f0("HatOn",local_1000,&local_100c,0x400);
  }
  if (0 < *(int *)(param_1 + 0x506c)) {
    FUN_005485f0("SwLever",local_1000,&local_100c,0x400);
  }
  if ((*(int *)(param_1 + 300) == 0) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 1) == 0)) {
    FUN_005485f0("Char_Slide_Lp",local_1000,&local_100c,0x400);
    if (0 < *(int *)(param_1 + 0x46c0)) {
      FUN_005485f0("Block_Shove",local_1000,&local_100c,0x400);
      FUN_005485f0("Block_Push_Lp",local_1000,&local_100c,0x400);
    }
    FUN_005485f0("exp_thermalDet",local_1000,&local_100c,0x400);
    FUN_005485f0("imp_thermalDet_attach",local_1000,&local_100c,0x400);
    if (*(int *)(param_1 + 300) == DAT_0087afd4) {
      FUN_005485f0("XWing_LoopDeLoop",local_1000,&local_100c,0x400);
    }
  }
  else {
    FUN_005485f0("XWing_Torpedo",local_1000,&local_100c,0x400);
    FUN_005485f0("imp_proton_torp",local_1000,&local_100c,0x400);
    FUN_005485f0("XWing_LoopDeLoop",local_1000,&local_100c,0x400);
  }
  FUN_005485f0("Explode1",local_1000,&local_100c,0x400);
  iVar6 = *(int *)(param_1 + 0x128);
  if (*(short *)(iVar6 + 0x96) != -1) {
    local_1000[local_100c] = (int)*(short *)(iVar6 + 0x96);
    local_100c = local_100c + 1;
  }
  if ((iVar6 == DAT_00951b98) || ((*(uint *)(iVar6 + 100) & 0x400) != 0)) {
    FUN_005485f0("StatusAward",local_1000,&local_100c,0x400);
    FUN_005485f0("Status_GoldBarDec",local_1000,&local_100c,0x400);
    FUN_005485f0("TrueJedi_100pc",local_1000,&local_100c,0x400);
    FUN_005485f0("TrueJedi_NOT",local_1000,&local_100c,0x400);
    FUN_005485f0("MK-Panel",local_1000,&local_100c,0x400);
    FUN_005485f0("Char_Icon_App",local_1000,&local_100c,0x400);
    FUN_005485f0("Char_Icon_Slide",local_1000,&local_100c,0x400);
    FUN_005485f0("LegoClicks",local_1000,&local_100c,0x400);
    FUN_005485f0("Shop_BuyCheat",local_1000,&local_100c,0x400);
    FUN_005485f0("Explode1",local_1000,&local_100c,0x400);
    FUN_005485f0("Jp_Ana_Jump",local_1000,&local_100c,0x400);
    FUN_005485f0("PickupCoin",local_1000,&local_100c,0x400);
  }
  else if ((*(int *)(param_1 + 300) == 0) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 4) == 0))
  {
    if (iVar6 == DAT_00951b9c) {
      FUN_005485f0("StatusAward",local_1000,&local_100c,0x400);
    }
  }
  else {
    FUN_005485f0("Victory",local_1000,&local_100c,0x400);
    FUN_005485f0("exp_debris",local_1000,&local_100c,0x400);
  }
  if (*(int *)(param_1 + 300) != 0) {
    if (*(char *)(*(int *)(param_1 + 300) + 0x7f) != '\0') {
      FUN_005479b0(0x53,local_1000,&local_100c,0x400);
    }
    iVar6 = *(int *)(param_1 + 300);
    if ((iVar6 == DAT_0087b014) || (iVar6 == DAT_0087af5c)) {
      FUN_005485f0("PodX_TuskenBlast",local_1000,&local_100c,0x400);
      FUN_005485f0("Pod_TuskHit",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngSebulba_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngAnakin_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngGeneric1_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngGeneric2_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngGeneric3_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngStartup1",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngStartup2",local_1000,&local_100c,0x400);
      FUN_005485f0("Pod_Race_Go",local_1000,&local_100c,0x400);
      FUN_005485f0("Pod_Race_Light",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_EngGeneric_Lp",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_Collide",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_Crash",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_Booster",local_1000,&local_100c,0x400);
      FUN_005485f0("CountdownTimerTick",local_1000,&local_100c,0x400);
      FUN_005485f0("CountdownTimerTock",local_1000,&local_100c,0x400);
      FUN_005485f0("PodX_PurpCrysHit",local_1000,&local_100c,0x400);
    }
    else if ((iVar6 == DAT_0087af78) || (iVar6 == DAT_0087b01c)) {
      FUN_005485f0("GC_GunshipBlasterFire",local_1000,&local_100c,0x400);
      FUN_005485f0("GC_GunshipEngineLp",local_1000,&local_100c,0x400);
      FUN_005485f0("GC_GunshipDeath",local_1000,&local_100c,0x400);
      FUN_005485f0("GC_LaserBeam",local_1000,&local_100c,0x400);
      FUN_005485f0("Explode1",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_00951364) {
      FUN_005485f0("Shop_BuyCheat",local_1000,&local_100c,0x400);
      FUN_005485f0("Shop_NotEnufMuny",local_1000,&local_100c,0x400);
      FUN_005485f0("ui_ZoomIn",local_1000,&local_100c,0x400);
      FUN_005485f0("ui_ZoomOut",local_1000,&local_100c,0x400);
      FUN_005485f0("ui_hover_lp",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087afcc) {
      FUN_005485f0("swdisco",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b028) {
      FUN_005485f0("BBounce",local_1000,&local_100c,0x400);
    }
  }
  iVar6 = *(int *)(param_1 + 0x128);
  if (iVar6 == DAT_0087b04c) {
    FUN_005485f0("NegA_CoinMDoorUp",local_1000,&local_100c,0x400);
    pcVar8 = "NegA_CoinMDoorDn";
LAB_004bf89e:
    FUN_005485f0(pcVar8,local_1000,&local_100c,0x400);
  }
  else {
    if (iVar6 == DAT_0087b050) {
      FUN_005485f0("FField",local_1000,&local_100c,0x400);
      pcVar8 = "NegC_Crate";
      goto LAB_004bf89e;
    }
    if (iVar6 == DAT_0087b054) {
      FUN_005485f0("NegC_MagnetCoil",local_1000,&local_100c,0x400);
      FUN_005485f0("NegC_MagnetCoilH",local_1000,&local_100c,0x400);
      FUN_005485f0("NegC_MagnetCoilS",local_1000,&local_100c,0x400);
      FUN_005485f0("FField",local_1000,&local_100c,0x400);
      FUN_005485f0("NegC_Crate",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b058) {
      FUN_005485f0("GunA_TreeFall",local_1000,&local_100c,0x400);
      FUN_005485f0("FS_CreaRun",local_1000,&local_100c,0x400);
      FUN_005485f0("IkopiGrowl",local_1000,&local_100c,0x400);
      FUN_005485f0("KaaduBark",local_1000,&local_100c,0x400);
      FUN_005485f0("KaaduGrowl",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b05c) {
      FUN_005485f0("ResX_MarbColLp",local_1000,&local_100c,0x400);
      FUN_005485f0("ResX_PoleLift_Rise",local_1000,&local_100c,0x400);
      FUN_005485f0("ResX_PoleLift_Lower",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b0a4) {
      FUN_005485f0("ResX_MarbColLp",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b0a8) {
      FUN_005485f0("ResX_PortCulLp",local_1000,&local_100c,0x400);
      FUN_005485f0("ResX_PortCulEnd",local_1000,&local_100c,0x400);
      FUN_005485f0("Ep1_5_OutdoorPlatform",local_1000,&local_100c,0x400);
    }
    else if (iVar6 == DAT_0087b0ac) {
      FUN_005485f0("Ep1_5_OutdoorPlatform",local_1000,&local_100c,0x400);
      FUN_005485f0("ResX_PortCulLp",local_1000,&local_100c,0x400);
      FUN_005485f0("ResX_PortCulEnd",local_1000,&local_100c,0x400);
    }
    else {
      if (iVar6 != DAT_0087b0b8) {
        if (iVar6 == DAT_0087b0c0) {
          FUN_005485f0("Ep1_7_FloatPlatRise",local_1000,&local_100c,0x400);
          pcVar8 = "NegC_Crate";
        }
        else if (iVar6 == DAT_0087b114) {
          FUN_005485f0("Kam_Slave1BlasterFire",local_1000,&local_100c,0x400);
          pcVar8 = "Slave1_EngineLp";
        }
        else if (iVar6 == DAT_0087b110) {
          FUN_005485f0("Kam_DiscoFloorPanelOn",local_1000,&local_100c,0x400);
          FUN_005485f0("Kam_DiscoFloorPanelDone",local_1000,&local_100c,0x400);
          FUN_005485f0("Kam_SparkLp",local_1000,&local_100c,0x400);
          FUN_005485f0("Kam_SparkLp",local_1000,&local_100c,0x400);
          FUN_005485f0("Kam_ForceFieldLp",local_1000,&local_100c,0x400);
          pcVar8 = "Kam_ForceFieldOff";
        }
        else {
          if (iVar6 != DAT_0087b0fc) {
            if (iVar6 == DAT_0087b100) {
              FUN_005485f0("Fac_BucketGearUD",local_1000,&local_100c,0x400);
              FUN_005485f0("Fac_BucketAwayFB",local_1000,&local_100c,0x400);
              FUN_005485f0("Fac_BucketLp",local_1000,&local_100c,0x400);
              FUN_005485f0("Fac_BucketArriveLock",local_1000,&local_100c,0x400);
              FUN_005485f0("Fac_BucketOpens",local_1000,&local_100c,0x400);
            }
            else if (iVar6 == DAT_0087b104) {
              FUN_005485f0("Fac_LaserGateLoop",local_1000,&local_100c,0x400);
            }
            else if (iVar6 == DAT_0087b108) {
              FUN_005485f0("Fac_ObiRestraintLoop",local_1000,&local_100c,0x400);
            }
            else {
              if (iVar6 == DAT_0087b0d8) {
LAB_004bee78:
                FUN_005485f0("CountdownTimerTick",local_1000,&local_100c,0x400);
                pcVar8 = "CountdownTimerTock";
                goto LAB_004bf89e;
              }
              if (iVar6 == DAT_0087b11c) {
                FUN_005485f0("Dooku_LightningLp",local_1000,&local_100c,0x400);
              }
              else if (iVar6 == DAT_0087b0f8) {
                FUN_005485f0("Ep3_1_StarDestEngLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Ep3_1_ProtoXWingMissile",local_1000,&local_100c,0x400);
                FUN_005485f0("Ep3_1_ExplosionM",local_1000,&local_100c,0x400);
                FUN_005485f0("Ep3_1_ExplosionXXL",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TurretFire",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_CloneARC170Gun",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_JediStFighterGun",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_JediStFighterGun2",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_JediStFighterGun3",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_JediStFighterEngLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_CloneARC170EngLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_DroidFighterBlast",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TriFighterGuns",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TriFighterGuns2",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_DroidFighterEngLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TriFighterEngLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_DroidFighterHit",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TriFighterHit",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_HugeBeamGunFire",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_HugeBeamGunLp",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_SepShieldPwrDown",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_ShipBreakExplo",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_ShipDoorOpen",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_StDestTurretSpins",local_1000,&local_100c,0x400);
                FUN_005485f0("Dog_TowerBreakExplo",local_1000,&local_100c,0x400);
              }
              else {
                if (iVar6 != DAT_0087b14c) {
                  if (iVar6 == DAT_0087b154) {
                    FUN_005485f0("NegA_CoinMDoorUp",local_1000,&local_100c,0x400);
                    pcVar8 = "NegA_CoinMDoorDn";
                  }
                  else {
                    if (iVar6 != DAT_0087b140) {
                      if (iVar6 == DAT_0087b158) goto LAB_004bee78;
                      if (iVar6 == DAT_0087b180) {
                        FUN_005485f0("env_shower_lp",local_1000,&local_100c,0x400);
                      }
                      else if (iVar6 == DAT_0087b184) {
                        FUN_005485f0("greenlighton",local_1000,&local_100c,0x400);
                        FUN_005485f0("env_suckerspit_3PO",local_1000,&local_100c,0x400);
                        FUN_005485f0("env_suckerspit_gonk",local_1000,&local_100c,0x400);
                        FUN_005485f0("conveyorlp",local_1000,&local_100c,0x400);
                      }
                      else if (iVar6 == DAT_0087b190) {
                        FUN_005485f0("env_jacuzzi_lp",local_1000,&local_100c,0x400);
                      }
                      else if (iVar6 == DAT_0087b198) {
                        FUN_005485f0("Droid_BeamLp",local_1000,&local_100c,0x400);
                        FUN_005485f0("FField",local_1000,&local_100c,0x400);
                        FUN_005485f0("FFieldOff",local_1000,&local_100c,0x400);
                        FUN_005485f0("SwPPad",local_1000,&local_100c,0x400);
                      }
                      else {
                        if (iVar6 == DAT_0087b1a8) {
                          FUN_005485f0("env_tractorbeam_off",local_1000,&local_100c,0x400);
                          pcVar8 = "env_tractorbeam_lp";
                          goto LAB_004bf89e;
                        }
                        if (iVar6 == DAT_0087b1ac) {
                          FUN_005485f0("ffield",local_1000,&local_100c,0x400);
                        }
                        else if (iVar6 == DAT_0087b1b4) {
                          FUN_005485f0("Turret_PitchLp",local_1000,&local_100c,0x400);
                          FUN_005485f0("Turret_YawLp",local_1000,&local_100c,0x400);
                          FUN_005485f0("Turbo_Fire",local_1000,&local_100c,0x400);
                        }
                        else {
                          if ((iVar6 == DAT_0087b1b8) || (iVar6 == DAT_0087b1c4)) {
                            FUN_005485f0("Dianoga_Groan",local_1000,&local_100c,0x400);
                            pcVar8 = "Dianoga_Roar";
                            goto LAB_004bf89e;
                          }
                          if (iVar6 != DAT_0087b1bc) {
                            if (iVar6 == DAT_0087b1c0) goto LAB_004bf454;
                            if ((((iVar6 == DAT_0087b1c8) || (iVar6 == DAT_0087b1cc)) ||
                                (iVar6 == DAT_0087b1d0)) || (iVar6 == DAT_0087b1d4)) {
                              FUN_005485f0("FField",local_1000,&local_100c,0x400);
                              pcVar8 = "FFieldOff";
                            }
                            else {
                              if (iVar6 != DAT_0087b1f4) {
                                if (iVar6 == DAT_0087b1fc) {
                                  FUN_005485f0("env_padLight_on",local_1000,&local_100c,0x400);
                                }
                                else if (iVar6 == DAT_0087b210) {
                                  FUN_005485f0("exp_asteroid",local_1000,&local_100c,0x400);
                                }
                                else if (iVar6 == DAT_0087b224) {
                                  FUN_005485f0("Env_Steam_Lp",local_1000,&local_100c,0x400);
                                }
                                else {
                                  if (iVar6 == DAT_0087b218) {
                                    FUN_005485f0("env_steam_lp",local_1000,&local_100c,0x400);
                                    pcVar8 = "Env_ctrl_desk_on";
                                    goto LAB_004bf89e;
                                  }
                                  if (iVar6 == DAT_0087b220) {
                                    FUN_005485f0("env_steam_lp",local_1000,&local_100c,0x400);
                                  }
                                  else {
                                    if (iVar6 == DAT_0087b250) {
                                      FUN_005485f0("FField",local_1000,&local_100c,0x400);
                                      pcVar8 = "FFieldOff";
                                      goto LAB_004bf89e;
                                    }
                                    if (iVar6 == DAT_0087b254) {
                                      FUN_005485f0("ForceLightningLp",local_1000,&local_100c,0x400);
                                    }
                                    else if (((iVar6 == DAT_0087b280) || (iVar6 == DAT_0087b284)) ||
                                            (iVar6 == DAT_0087b288)) {
                                      FUN_005485f0("SwDisco",local_1000,&local_100c,0x400);
                                    }
                                    else if (iVar6 == DAT_0087b28c) {
                                      FUN_005485f0("exp_minecart",local_1000,&local_100c,0x400);
                                    }
                                    else if (iVar6 == DAT_0087b270) {
                                      FUN_005485f0("env_curtain_lp",local_1000,&local_100c,0x400);
                                      FUN_005485f0("Kam_DiscoFloorPanelOn",local_1000,&local_100c,
                                                   0x400);
                                      FUN_005485f0("Kam_DiscoFloorPanelDone",local_1000,&local_100c,
                                                   0x400);
                                    }
                                    else if (iVar6 == DAT_0087b274) {
                                      FUN_005485f0("FField",local_1000,&local_100c,0x400);
                                      FUN_005485f0("FFieldOff",local_1000,&local_100c,0x400);
                                      FUN_005485f0("imp_c3po_magnet_drop",local_1000,&local_100c,
                                                   0x400);
                                      FUN_005485f0("env_magnet_on",local_1000,&local_100c,0x400);
                                    }
                                    else {
                                      if (iVar6 == DAT_0087b234) {
LAB_004bf454:
                                        FUN_005485f0("FField",local_1000,&local_100c,0x400);
                                        pcVar8 = "FFieldOff";
                                        goto LAB_004bf89e;
                                      }
                                      if (iVar6 == DAT_0087b294) {
                                        FUN_005485f0("env_lantern_lp",local_1000,&local_100c,0x400);
                                      }
                                      else if (iVar6 == DAT_0087b298) {
                                        FUN_005485f0("waterfall",local_1000,&local_100c,0x400);
                                        FUN_005485f0("drd_r2_mvt_water_lp",local_1000,&local_100c,
                                                     0x400);
                                        FUN_005485f0("env_lantern_lp",local_1000,&local_100c,0x400);
                                      }
                                      else {
                                        if (iVar6 == DAT_0087b2a0) goto LAB_004bf454;
                                        if (iVar6 == DAT_0087b268) {
                                          FUN_005485f0("env_block_light_on",local_1000,&local_100c,
                                                       0x400);
                                          pcVar8 = "env_padlight_on";
                                          goto LAB_004bf89e;
                                        }
                                      }
                                    }
                                  }
                                }
                                goto LAB_004bf8a6;
                              }
                              FUN_005485f0("ThermalDet_Beep",local_1000,&local_100c,0x400);
                              pcVar8 = "env_padLight_on";
                            }
                            goto LAB_004bf89e;
                          }
                          FUN_005485f0("SqueakWash",local_1000,&local_100c,0x400);
                        }
                      }
                      goto LAB_004bf8a6;
                    }
                    FUN_005485f0("Kas_BoulderLoop",local_1000,&local_100c,0x400);
                    pcVar8 = "Kas_BoulderExplo";
                  }
                  goto LAB_004bf89e;
                }
                FUN_005485f0("Cru_HugeWallMoveLp",local_1000,&local_100c,0x400);
              }
            }
            goto LAB_004bf8a6;
          }
          FUN_005485f0("FacB_BeltLp",local_1000,&local_100c,0x400);
          FUN_005485f0("FacB_ConvStop",local_1000,&local_100c,0x400);
          FUN_005485f0("Fac_StampHydros",local_1000,&local_100c,0x400);
          FUN_005485f0("Fac_StampImpacts",local_1000,&local_100c,0x400);
          FUN_005485f0("Fac_BonusCylUp",local_1000,&local_100c,0x400);
          pcVar8 = "Fac_BonusBeep";
        }
        goto LAB_004bf89e;
      }
      FUN_005485f0("Ep1_7_BDroidPlatf",local_1000,&local_100c,0x400);
      FUN_005485f0("Ep1_7_SFPowerUp",local_1000,&local_100c,0x400);
      FUN_005485f0("Ep1_7_SFHoverLp",local_1000,&local_100c,0x400);
      FUN_005485f0("Ep1_7_SFTakeOff",local_1000,&local_100c,0x400);
    }
  }
LAB_004bf8a6:
  if (DAT_00951288 != 0) {
    FUN_005485f0("TieDoorsOpen",local_1000,&local_100c,0x400);
  }
  iVar6 = FUN_0058a900(0);
  if (iVar6 != 0) {
    FUN_005485f0("Victory",local_1000,&local_100c,0x400);
  }
  if (DAT_0093b324 != 0) {
    FUN_005485f0("env_padLight_on",local_1000,&local_100c,0x400);
  }
  iVar6 = *(int *)(param_1 + 300);
  if ((iVar6 == DAT_0087afb8) || (iVar6 == DAT_0087afcc)) {
    pcVar8 = "fs_ice";
  }
  else {
    if (iVar6 != DAT_0087afc0) goto LAB_004bf96a;
    pcVar8 = "fs_swamp";
  }
  FUN_005485f0(pcVar8,local_1000,&local_100c,0x400);
LAB_004bf96a:
  if (((0 < DAT_029130e4[4]) && ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 2) != 0)) &&
     (DAT_00951288 == 0)) {
    FUN_005479b0(0x14,local_1000,&local_100c,0x400);
    FUN_005479b0(0x15,local_1000,&local_100c,0x400);
  }
  local_1008 = 0;
  if (0 < *DAT_029130e4) {
    local_1004 = 0;
    do {
      iVar6 = local_1008;
      sVar1 = *(short *)(DAT_029130e4[7] + local_1008 * 2);
      if ((sVar1 != -1) && ((*(byte *)(sVar1 * 0x54 + 2 + DAT_029130e4[6]) & 1) != 0)) {
        iVar7 = *(int *)(local_1004 + 0x24 + DAT_0093b274);
        iVar5 = local_1004 + DAT_0093b274;
        if (*(short *)(iVar7 + 0xdc) == -1) {
          if ((*(uint *)(iVar5 + 4) & 0x44002010) == 0) {
            FUN_005479b0(0x1c - (uint)((*(uint *)(iVar7 + 0x90) & 0x20000) != 0),local_1000,
                         &local_100c,0x400);
          }
        }
        else {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xdc);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xde) == -1) {
          if ((*(uint *)(iVar5 + 4) & 0x44002010) == 0) {
            FUN_005479b0(~(*(uint *)(iVar7 + 0x90) >> 0x11) & 1 | 0x16,local_1000,&local_100c,0x400)
            ;
          }
        }
        else {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xde);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xe0) == -1) {
          if ((*(uint *)(iVar5 + 4) & 0x44002010) == 0) {
            FUN_005479b0(~(*(uint *)(iVar7 + 0x90) >> 0x11) & 1 | 0x14,local_1000,&local_100c,0x400)
            ;
          }
        }
        else {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xe0);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xe2) != -1) {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xe2);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xe4) != -1) {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xe4);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xe6) != -1) {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xe6);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xe8) != -1) {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xe8);
          local_100c = local_100c + 1;
        }
        if (*(short *)(iVar7 + 0xea) != -1) {
          local_1000[local_100c] = (int)*(short *)(iVar7 + 0xea);
          local_100c = local_100c + 1;
        }
        iVar4 = 0;
        psVar3 = (short *)(iVar7 + 0xd0);
        do {
          if (*psVar3 == -1) break;
          local_1000[local_100c] = (int)*psVar3;
          local_100c = local_100c + 1;
          iVar4 = iVar4 + 1;
          psVar3 = psVar3 + 1;
          iVar6 = local_1008;
        } while (iVar4 < 6);
        if ((*(byte *)(iVar5 + 4) & 0x40) != 0) {
          FUN_005485f0("drd_r2_scope_up",local_1000,&local_100c,0x400);
          FUN_005485f0("drd_r2_scope_down",local_1000,&local_100c,0x400);
          FUN_005485f0("drd_r2_mvt_water_lp",local_1000,&local_100c,0x400);
        }
        if ((*(uint *)(iVar7 + 0x90) & 0x400) != 0) {
          FUN_005485f0("TowCable_Fire",local_1000,&local_100c,0x400);
          FUN_005485f0("TowCable_Latch",local_1000,&local_100c,0x400);
          FUN_005485f0("TowCable_Detach",local_1000,&local_100c,0x400);
          FUN_005485f0("TowCable_Snap",local_1000,&local_100c,0x400);
        }
        if ((*(uint *)(iVar5 + 4) & 0x2000) != 0) {
          FUN_005485f0("XWing_Torpedo",local_1000,&local_100c,0x400);
          FUN_005485f0("env_tractorbeam_lp",local_1000,&local_100c,0x400);
          if ((*(uint *)(iVar5 + 4) & 0x4000000) == 0) {
            FUN_005485f0("Explode1",local_1000,&local_100c,0x400);
          }
        }
        if (iVar6 == DAT_007f18ec) {
          FUN_005485f0("C3_Hurt",local_1000,&local_100c,0x400);
          FUN_005485f0("C3_Death",local_1000,&local_100c,0x400);
        }
        if (*(code **)(iVar5 + 0x18) == FUN_004b3000) {
          FUN_005485f0("Lego_Poo",local_1000,&local_100c,0x400);
          FUN_005485f0("Lego_PLOP",local_1000,&local_100c,0x400);
          FUN_005485f0("FliesLp",local_1000,&local_100c,0x400);
        }
        if (*(char *)(iVar7 + 0x116) == '\n') {
          FUN_005485f0("veh_tie_by",local_1000,&local_100c,0x400);
          FUN_005485f0("Tie_Spins",local_1000,&local_100c,0x400);
        }
        if ((iVar6 == DAT_007f1924) || (iVar6 == DAT_007f1928)) {
          FUN_005485f0("wpn_bomb_drop",local_1000,&local_100c,0x400);
          FUN_005485f0("exp_bomb",local_1000,&local_100c,0x400);
        }
        if ((*(uint *)(iVar7 + 0x90) & 4) == 0) {
          if ((*(uint *)(iVar7 + 0x90) & 2) != 0) {
            pcVar8 = "ForceChokeCrunch";
            goto LAB_004bfe69;
          }
          if ((*(byte *)(iVar5 + 4) & 8) != 0) {
            pcVar8 = "ForceMindTrick";
            goto LAB_004bfe69;
          }
        }
        else {
          pcVar8 = "ForceLightningLp";
LAB_004bfe69:
          FUN_005485f0(pcVar8,local_1000,&local_100c,0x400);
        }
        if ((((*(char *)(iVar7 + 0x116) == '\f') && ((*(byte *)(iVar5 + 4) & 8) != 0)) &&
            (DAT_007f1884 != -1)) && (*(short *)(DAT_029130e4[7] + DAT_007f1884 * 2) != -1)) {
          FUN_005485f0("ForceChokeCrunch",local_1000,&local_100c,0x400);
        }
        if ((*(uint *)(iVar7 + 0x94) & 0x20000000) != 0) {
          FUN_005479b0(0x4c,local_1000,&local_100c,0x400);
          FUN_005479b0(0x4d,local_1000,&local_100c,0x400);
          FUN_005479b0(0x4e,local_1000,&local_100c,0x400);
        }
        psVar3 = *(short **)(iVar5 + 0x28);
        if (psVar3 != (short *)0x0) {
          sVar1 = *psVar3;
          iVar7 = local_100c;
          while (sVar1 != -1) {
            if (psVar3[0x14] != -1) {
              local_1000[iVar7] = (int)psVar3[0x14];
              iVar7 = iVar7 + 1;
              local_100c = iVar7;
            }
            psVar3 = psVar3 + 0x1a;
            sVar1 = *psVar3;
          }
        }
        if ((*(byte *)(iVar5 + 4) & 0x20) != 0) {
          FUN_005485f0("TC14_VLA",local_1000,&local_100c,0x400);
          FUN_005485f0("TC14_VLN",local_1000,&local_100c,0x400);
        }
        if ((*(byte *)(iVar5 + 4) & 0x40) != 0) {
          FUN_005485f0("R2D2_VLA",local_1000,&local_100c,0x400);
        }
      }
      local_1004 = local_1004 + 0x4c;
      local_1008 = iVar6 + 1;
    } while (local_1008 < *DAT_029130e4);
  }
  if ((DAT_0093b324 == 0) && ((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x800) == 0)) {
    for (iVar6 = 0x4c; iVar6 < 0x5d; iVar6 = iVar6 + 4) {
      if (*(int *)(iVar6 + *(int *)(param_1 + 0x2ac4)) != 0) goto LAB_004bfffd;
    }
  }
  else {
LAB_004bfffd:
    FUN_005485f0("ui_DoubleScoreEntry",local_1000,&local_100c,0x400);
    FUN_005485f0("ui_DoubleScoreText",local_1000,&local_100c,0x400);
  }
  FUN_00559a80(*(undefined4 *)(param_1 + 0x2ac8),param_1,local_1000,&local_100c,0x400);
  FUN_005b1dd0(local_1000,&local_100c,param_1);
  local_1000[local_100c] = -1;
  if (0 < local_100c) {
    FUN_00681db0(local_1000,FUN_00650570);
  }
  FUN_00650850(&DAT_00924cf8);
  return;
}

