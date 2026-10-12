/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d9fa0; label: FUN_004d9fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d9fa0(undefined4 param_1,float param_2)

{
  float *pfVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  float local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  iVar5 = DAT_00882a6c;
  local_4 = DAT_00829570 ^ (uint)&local_88;
  if (DAT_00951b50 != 0) {
    *(undefined4 *)(DAT_00882a6c + 0xb000) = *DAT_008827e0;
    *(undefined4 *)(iVar5 + 0xb008) = DAT_008827e0[1];
    *(undefined4 *)(iVar5 + 0xb00c) = DAT_008827e0[2];
    DAT_00882a70 = DAT_008827e0[4];
  }
  if (*(float *)(iVar5 + 0xb000) <= 0.0) {
    if (DAT_00951b50 == 0) {
      local_88 = param_2 + *(float *)(iVar5 + 0xb004);
      *(float *)(iVar5 + 0xb004) = local_88;
      if (0.0 < *(float *)(iVar5 + 0xb00c)) {
        local_88 = *(float *)(iVar5 + 0xb00c) - local_88;
        *(float *)(iVar5 + 0xb008) = local_88;
        if ((local_88 < 0.0) && (_DAT_00950780 == 0.0)) {
          *(undefined4 *)(iVar5 + 0xb008) = 0;
          if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
            FUN_0046c6e0(DAT_0093d7f0,1);
            iVar5 = DAT_00882a6c;
          }
          if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
            FUN_0046c6e0(DAT_0093d7f4,1);
            iVar5 = DAT_00882a6c;
          }
          *(byte *)(iVar5 + 0xb020) = *(byte *)(iVar5 + 0xb020) | 2;
          FUN_00437390(DAT_0093d810,2,1,0);
          iVar5 = DAT_00882a6c;
          pfVar1 = (float *)(DAT_00882a6c + 0xb00c);
          *(int *)(DAT_00882a6c + 0xb01c) = *(int *)(DAT_00882a6c + 0xb01c) + 1;
          if (((*pfVar1 < *(float *)(iVar5 + 0xb010)) && (*(int *)(iVar5 + 0xb018) != 0)) &&
             (*(int *)(iVar5 + 0xb01c) % *(int *)(iVar5 + 0xb018) == 0)) {
            local_88 = *(float *)(iVar5 + 0xb014) + *(float *)(iVar5 + 0xb00c);
            *(float *)(iVar5 + 0xb00c) = local_88;
            if (*(float *)(iVar5 + 0xb010) < local_88) {
              *(undefined4 *)(iVar5 + 0xb00c) = *(undefined4 *)(iVar5 + 0xb010);
            }
          }
        }
      }
    }
  }
  else {
    local_88 = *(float *)(iVar5 + 0xb000);
    *(undefined4 *)(iVar5 + 0xb008) = *(undefined4 *)(iVar5 + 0xb00c);
    _DAT_0087b888 = 0;
    uVar3 = 0;
    if ((DAT_0093d7f0 != 0) &&
       (uVar3 = _DAT_0087b888, (*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
      _DAT_0087b888 = 0;
      *(undefined4 *)(DAT_0093d7f0 + 0xc44) = 0;
      uVar3 = _DAT_0087b888;
    }
    _DAT_0087b888 = uVar3;
    if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
      *(undefined4 *)(DAT_0093d7f4 + 0xc44) = 0;
    }
    if ((DAT_00951b50 == 0) && (_DAT_00950780 == 0.0)) {
      *(float *)(iVar5 + 0xb000) = *(float *)(iVar5 + 0xb000) - param_2;
    }
    if ((*(float *)(iVar5 + 0xb000) < 2.9) &&
       (!NAN(local_88) && 2.9 < local_88 != (local_88 == 2.9))) {
      FUN_00681f40("PodX_EngStartup1",0);
      iVar5 = DAT_00882a6c;
    }
    if ((*(float *)(iVar5 + 0xb000) < 1.5) &&
       (!NAN(local_88) && 1.5 < local_88 != (local_88 == 1.5))) {
      FUN_00681f40("PodX_EngStartup2",0);
      iVar5 = DAT_00882a6c;
    }
    if (0.0 < *(float *)(iVar5 + 0xb000)) {
      iVar6 = FUN_006e6b90();
      iVar4 = FUN_006e6b90();
      if (iVar6 != iVar4) {
        FUN_00681f40("Pod_Race_Light",0);
        iVar5 = DAT_00882a6c;
      }
    }
    else {
      FUN_00681f40("Pod_Race_Go",0);
      iVar5 = DAT_00882a6c;
    }
  }
  iVar6 = 0;
  do {
    if (*(int *)(iVar6 + 0xa694 + iVar5) != 0) {
      FUN_004d9760(iVar6 + 0xa600 + iVar5,param_1);
      iVar5 = DAT_00882a6c;
    }
    iVar6 = iVar6 + 0xa0;
  } while (iVar6 < 0xa00);
  bVar2 = *(byte *)(iVar5 + 0xb020);
  if (((bVar2 & 1) == 0) &&
     (((DAT_0093d7f0 != 0 && (*(char *)(DAT_0093d7f0 + 0x28b) != '\0')) ||
      ((DAT_0093d7f4 != 0 && (*(char *)(DAT_0093d7f4 + 0x28b) != '\0')))))) {
    *(byte *)(iVar5 + 0xb020) = bVar2 | 1;
    if ((bVar2 & 2) == 0) {
      pcVar7 = "EP1_PODRACE_PODEXPLODE";
    }
    else {
      pcVar7 = "Ep1_PodRace_OutOfTime";
    }
    FUN_004f1f10(local_84,pcVar7);
    FUN_0057a620(param_1,local_84,1);
    iVar5 = DAT_00882a6c;
  }
  if (DAT_00951b50 == 0) {
    *DAT_008827e0 = *(undefined4 *)(iVar5 + 0xb000);
    DAT_008827e0[4] = DAT_00882a70;
    DAT_008827e0[1] = *(undefined4 *)(iVar5 + 0xb008);
    DAT_008827e0[2] = *(undefined4 *)(iVar5 + 0xb00c);
  }
  __security_check_cookie(local_4 ^ (uint)&local_88);
  return;
}

