/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46dce0; label: FUN_0046dce0
 */

undefined4 FUN_0046dce0(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = FUN_0041aef0(param_1);
  if (iVar4 != 0) {
    return 1;
  }
  switch(*(undefined1 *)(param_2 + 0x61)) {
  case 0:
    uVar5 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
    uVar3 = uVar5 & 0x40;
    goto LAB_0046dd23;
  case 1:
    uVar5 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
    uVar3 = uVar5 & 0x20;
LAB_0046dd23:
    if (uVar3 != 0) {
      return 1;
    }
    bVar6 = (undefined *)(uVar5 & 0x1000010) == &DAT_01000010;
    break;
  case 2:
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x1000000) != 0) {
      return 1;
    }
    bVar6 = *(char *)(param_1 + 0x1082) == '\x06';
    break;
  case 3:
    if (*(char *)(param_1 + 0x1082) == '\x05') {
      return 1;
    }
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x40000) != 0) {
      return 1;
    }
    sVar2 = *(short *)(param_1 + 0x1064);
    cVar1 = *(char *)(sVar2 * 0x120 + 0x116 + DAT_0093b284);
    if (cVar1 == '\x01') {
      return 1;
    }
    if (cVar1 == '\b') {
      return 1;
    }
    if (sVar2 == DAT_007f199c) {
      return 1;
    }
    if (sVar2 == DAT_007f19a0) {
      return 1;
    }
    if (sVar2 == DAT_007f1a4c) {
      return 1;
    }
    if (sVar2 == DAT_007f1a48) {
      return 1;
    }
    bVar6 = sVar2 == DAT_007f1a44;
    break;
  default:
    goto switchD_0046dd14_default;
  }
  if (bVar6) {
    return 1;
  }
switchD_0046dd14_default:
  return 0;
}

