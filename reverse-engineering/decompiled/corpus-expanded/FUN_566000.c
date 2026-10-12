/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566000; label: FUN_00566000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00566000(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = 0;
  local_18 = 0;
  FUN_005d4290(1);
  bVar1 = 0.0 <= _DAT_00950780;
  iVar4 = 0x2800;
  iVar5 = 0xe00;
  if ((DAT_0095077c & 3) == 0) {
    if ((DAT_0095077c & 0xc) == 0) goto LAB_005661b2;
    if ((DAT_0095077c & 4) == 0) {
      if (0.0 < _DAT_00950784) goto LAB_00566172;
LAB_00566119:
      local_18 = 0;
      local_4 = 0;
      local_8 = 0;
      local_10 = 0x80000000;
      local_c = 0x80000000;
      iVar2 = FUN_006e6b90();
      iVar5 = iVar2;
    }
    else {
      if (0.0 < _DAT_00950784) goto LAB_00566119;
LAB_00566172:
      local_10 = 0;
      local_c = 0;
      local_8 = 0x80000000;
      local_4 = 0x80000000;
      local_18 = FUN_006e6b90();
      iVar5 = 0xe00 - local_18;
      iVar2 = FUN_006e6b90();
    }
    FUN_005dbd70(0xfffffff0,iVar2 + -0x10,0x2810,0x176,&local_10,DAT_00950700);
    goto LAB_005661b2;
  }
  if ((DAT_0095077c & 1) == 0) {
    if (0.0 < _DAT_00950784) goto LAB_005660bf;
LAB_00566065:
    local_4 = 0;
    local_c = 0;
    iVar3 = 0;
    local_10 = 0x80000000;
    local_8 = 0x80000000;
    iVar2 = FUN_006e6b90();
    iVar4 = iVar2;
  }
  else {
    if (0.0 < _DAT_00950784) goto LAB_00566065;
LAB_005660bf:
    local_10 = 0;
    local_c = 0x80000000;
    local_8 = 0;
    local_4 = 0x80000000;
    iVar3 = FUN_006e6b90();
    iVar4 = 0x2800 - iVar3;
    iVar2 = FUN_006e6b90();
  }
  FUN_005dbd70(iVar2 + -0x10,0xfffffff0,0x410,0xe10,&local_10,DAT_00950700);
LAB_005661b2:
  if (bVar1) {
    FUN_005db880(iVar3 + -0x10,local_18 + -0x10,iVar4 + 0x10,iVar5 + 0x10,0,DAT_0093b104);
  }
  FUN_005f3950();
  return;
}

