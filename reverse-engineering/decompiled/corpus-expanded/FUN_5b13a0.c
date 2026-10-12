/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b13a0; label: thunk_FUN_00566000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_00566000(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar3 = 0;
  iStack_18 = 0;
  FUN_005d4290(1);
  bVar1 = 0.0 <= _DAT_00950780;
  iVar4 = 0x2800;
  iVar5 = 0xe00;
  if ((DAT_0095077c & 3) == 0) {
    if ((DAT_0095077c & 0xc) == 0) goto LAB_005661b2;
    if ((DAT_0095077c & 4) == 0) {
      if (0.0 < _DAT_00950784) goto LAB_00566172;
LAB_00566119:
      iStack_18 = 0;
      uStack_4 = 0;
      uStack_8 = 0;
      uStack_10 = 0x80000000;
      uStack_c = 0x80000000;
      iVar2 = FUN_006e6b90();
      iVar5 = iVar2;
    }
    else {
      if (0.0 < _DAT_00950784) goto LAB_00566119;
LAB_00566172:
      uStack_10 = 0;
      uStack_c = 0;
      uStack_8 = 0x80000000;
      uStack_4 = 0x80000000;
      iStack_18 = FUN_006e6b90();
      iVar5 = 0xe00 - iStack_18;
      iVar2 = FUN_006e6b90();
    }
    FUN_005dbd70(0xfffffff0,iVar2 + -0x10,0x2810,0x176,&uStack_10,DAT_00950700);
    goto LAB_005661b2;
  }
  if ((DAT_0095077c & 1) == 0) {
    if (0.0 < _DAT_00950784) goto LAB_005660bf;
LAB_00566065:
    uStack_4 = 0;
    uStack_c = 0;
    iVar3 = 0;
    uStack_10 = 0x80000000;
    uStack_8 = 0x80000000;
    iVar2 = FUN_006e6b90();
    iVar4 = iVar2;
  }
  else {
    if (0.0 < _DAT_00950784) goto LAB_00566065;
LAB_005660bf:
    uStack_10 = 0;
    uStack_c = 0x80000000;
    uStack_8 = 0;
    uStack_4 = 0x80000000;
    iVar3 = FUN_006e6b90();
    iVar4 = 0x2800 - iVar3;
    iVar2 = FUN_006e6b90();
  }
  FUN_005dbd70(iVar2 + -0x10,0xfffffff0,0x410,0xe10,&uStack_10,DAT_00950700);
LAB_005661b2:
  if (bVar1) {
    FUN_005db880(iVar3 + -0x10,iStack_18 + -0x10,iVar4 + 0x10,iVar5 + 0x10,0,DAT_0093b104);
  }
  FUN_005f3950();
  return;
}

