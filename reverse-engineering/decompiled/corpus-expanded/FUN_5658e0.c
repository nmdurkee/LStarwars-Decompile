/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x5658e0; label: FUN_005658e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005658e0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 fVar5;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined *local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined4 local_28;
  undefined *local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined *local_8;
  undefined *local_4;
  
  FUN_005d4290(1);
  local_48 = 0.0;
  local_4c = 0.0;
  fVar5 = (float10)1;
  iVar2 = -0x20;
  local_50 = (float)fVar5;
  local_54 = (float)fVar5;
  iVar1 = -0xc;
  iVar3 = 0x2814;
  iVar4 = 0xe08;
  if ((DAT_0095077c & 3) == 0) {
    if ((DAT_0095077c & 0xc) != 0) {
      if ((DAT_0095077c & 4) == 0) {
        local_10 = 0x80808080;
        local_c = 0x80808080;
        local_8 = &DAT_00808080;
        local_4 = &DAT_00808080;
        iVar4 = FUN_006e6b90();
        local_54 = (float)extraout_ST0_02;
        FUN_005dc3f0(0xffffffe0,iVar4 + -0xc,0x2814,0x167,(float)fVar5,local_54,
                     (float)extraout_ST1_02,local_54 + 0.1,&local_10,DAT_00950660);
      }
      else {
        local_20 = &DAT_00808080;
        local_1c = &DAT_00808080;
        local_18 = 0x80808080;
        local_14 = 0x80808080;
        iVar1 = FUN_006e6b90();
        local_4c = (float)extraout_ST0_01;
        iVar4 = 0xe08 - iVar1;
        FUN_005dc3f0(0xffffffe0,iVar1 + -0x167,0x2814,0x167,(float)fVar5,local_4c - 0.1,
                     (float)extraout_ST1_01,local_4c,&local_20,DAT_00950660);
      }
    }
  }
  else if ((DAT_0095077c & 1) == 0) {
    local_30 = 0x80808080;
    local_2c = &DAT_00808080;
    local_28 = 0x80808080;
    local_24 = &DAT_00808080;
    iVar3 = FUN_006e6b90();
    local_50 = (float)extraout_ST0_00;
    FUN_005dc3f0(iVar3 + -0x20,0xfffffff4,0x402,0xe08,local_50,(float)fVar5,local_50 + 0.1,
                 (float)extraout_ST1_00,&local_30,DAT_00950660);
  }
  else {
    local_40 = &DAT_00808080;
    local_3c = 0x80808080;
    local_38 = &DAT_00808080;
    local_34 = 0x80808080;
    iVar2 = FUN_006e6b90();
    local_48 = (float)extraout_ST0;
    iVar3 = 0x2814 - iVar2;
    FUN_005dc3f0(iVar2 + -0x402,0xfffffff4,0x402,0xe08,local_48 - 0.1,(float)fVar5,local_48,
                 (float)extraout_ST1,&local_40,DAT_00950660);
    iVar1 = -0xc;
  }
  FUN_005dba30(iVar2,iVar1,iVar3,iVar4,local_48,local_4c,local_50,local_54,0x80808080,DAT_00950660);
  FUN_005f3950();
  return;
}

