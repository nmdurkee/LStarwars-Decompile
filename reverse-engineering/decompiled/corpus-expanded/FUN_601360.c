/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x601360; label: FUN_00601360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00601360(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = true;
  FUN_005f8930();
  if ((*(uint *)(param_1 + 0x1f0) & 0x100000) == 0) {
    uVar2 = *(uint *)(param_1 + 0x40) >> 0x14 & 7;
    if (1 < uVar2) {
      if (uVar2 == 5) {
        FUN_006e5340(0xf,1);
        uVar2 = *(uint *)(param_1 + 0x40) >> 0x17 & 0xff;
      }
      else {
        FUN_006e5340(0xf,1);
        uVar2 = 0;
      }
      goto LAB_006013d3;
    }
    FUN_006e5340(0xf,0);
  }
  else {
    FUN_006e5340(0xf,1);
    uVar2 = 2;
LAB_006013d3:
    FUN_006e5340(0x18,uVar2);
    FUN_006e5340(0x19,5);
  }
  switch(*(uint *)(param_1 + 0x40) & 0xf) {
  case 0:
    FUN_006e5340(0x1b,0);
    break;
  case 1:
    FUN_006e5340(0x1b,1);
    FUN_006e5340(0xab,1);
    uVar3 = 5;
    goto LAB_0060142b;
  case 2:
    FUN_006e5340(0x1b,1);
    FUN_006e5340(0xab,1);
    FUN_006e5340(0x13,5);
    FUN_006e5340(0x14,2);
    break;
  case 3:
    FUN_006e5340(0x1b,1);
    FUN_006e5340(0xab,3);
    uVar3 = 1;
LAB_0060142b:
    FUN_006e5340(0x13,uVar3);
    FUN_006e5340(0x14,6);
    break;
  case 10:
    FUN_006e5340(0x1b,0);
    FUN_006e5340(0xf,1);
    FUN_006e5340(0x18,*(uint *)(param_1 + 0x40) >> 0x17 & 0xff);
    FUN_006e5340(0x19,7);
    break;
  case 0xd:
    bVar1 = false;
  }
  uVar2 = *(uint *)(param_1 + 0x40) >> 0xc & 3;
  if (uVar2 == 0) {
    if (DAT_02854d50 == 0) {
LAB_006014f1:
      uVar3 = 3;
    }
    else {
      uVar3 = 2;
    }
  }
  else if (uVar2 == 1) {
    if (DAT_02854d50 != 0) goto LAB_006014f1;
    uVar3 = 2;
  }
  else {
    if (uVar2 != 2) goto LAB_006014fd;
    uVar3 = 1;
  }
  FUN_006e5340(0x16,uVar3);
LAB_006014fd:
  if (DAT_02854bb0 == 0) {
    FUN_006e2810(!bVar1,(*(uint *)(param_1 + 0x40) & 0x80000) == 0,0);
  }
  else {
    FUN_006e2810(1,1,0);
    _DAT_0080e690 = 0;
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,1);
    FUN_006e5340(0x17,4);
  }
  DAT_00986ea0 = DAT_0080e9e8;
  DAT_00986ea4 = DAT_0080e9ec;
  DAT_00986ea8 = DAT_0080e9f0;
  DAT_00986eac = DAT_0080e9f4;
  FUN_007412e0(0x38,&DAT_0080e9e8);
  _DAT_0080e198 = 0xbf800000;
  return;
}

