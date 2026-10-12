/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x433be0; label: FUN_00433be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433be0(int param_1,float param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float local_4;
  
  iVar2 = (int)param_2;
  if (param_2 == 0.0) {
    return;
  }
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 1) == 0)) {
    param_1 = 0;
  }
  if ((*(float *)((int)param_2 + 0xd30) == 1.0) && (0.0 < *(float *)((int)param_2 + 0xd34))) {
    if (param_1 == 0) goto LAB_00433c5c;
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) && (*(char *)(param_1 + 0x7b5) != '9')) {
      param_3 = 0;
    }
  }
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    FUN_004399e0(param_1,param_1 + 0x80);
  }
LAB_00433c5c:
  iVar1 = (int)param_2 + 0x80;
  uVar3 = FUN_00547820(param_1,0);
  FUN_00547930(0x41,iVar1,uVar3);
  if ((*(byte *)((int)param_2 + 0x1fc) & 0x80) != 0) {
    FUN_0054aae0(param_2,0x3f19999a);
  }
  if ((DAT_00855de0 != 0) && ((*(byte *)((int)param_2 + 0x1fc) & 0x80) != 0)) {
    param_3 = 0;
  }
  if ((*(char *)((int)param_2 + 0xe38) == '\0') || (param_3 < 1)) {
    if (param_1 != 0) {
      FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
      return;
    }
  }
  else {
    if (((*(byte *)((int)param_2 + 0x1fc) & 0x80) != 0) &&
       (iVar4 = FUN_0055f1d0(param_2), iVar4 != 0)) {
      param_3 = 0;
    }
    param_3 = (uint)*(byte *)((int)param_2 + 0xe38) - param_3;
    if (param_3 < 1) {
      FUN_00681f40("DDekaFlicker",iVar1);
      *(undefined4 *)((int)param_2 + 0xd34) = 0x3f000000;
      *(undefined1 *)((int)param_2 + 0xe38) = 0;
      *(undefined4 *)((int)param_2 + 0xd30) = 0;
      param_2 = 0.8;
      local_4 = 0.3;
    }
    else {
      FUN_00681f40("DDekaHit",iVar1);
      param_2 = 0.5;
      *(char *)(iVar2 + 0xe38) = (char)param_3;
      local_4 = 0.0;
      *(undefined4 *)(iVar2 + 0xd34) = _DAT_007fb0a0;
    }
    if (param_1 != 0) {
      if (0.0 < param_2) {
        FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),param_2,0);
      }
      if (0.0 < local_4) {
        FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),local_4,0);
        return;
      }
    }
  }
  return;
}

