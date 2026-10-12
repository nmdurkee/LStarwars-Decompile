/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x568580; label: FUN_00568580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00568580(int param_1)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((param_1 == 0) || ((*(byte *)(param_1 + 0x94) & 1) != 0)) ||
     ((*(byte *)(param_1 + 0x98) & 4) == 0)) {
    return 0;
  }
  if (*(short *)(param_1 + 0x102) == -1) {
    uVar3 = FUN_005cffb0(*(int *)(param_1 + 0xa4) + 0x30);
    uVar1 = *(uint *)(param_1 + 0x98);
    if ((((uVar1 & 0x2000) == 0) || ((uVar1 & 0x800000) != 0)) && ((uVar1 & 0x20000000) != 0)) {
      sVar2 = FUN_0067c760(uVar3);
    }
    else {
      sVar2 = FUN_0067bf50(param_1,uVar3);
    }
    *(short *)(param_1 + 0x102) = sVar2;
    if (sVar2 == -1) {
      return 0;
    }
    if ((*(uint *)(param_1 + 0x94) & 0x4000) == 0) {
      FUN_0067c8e0((int)sVar2,0);
    }
  }
  FUN_0067c7b0((int)*(short *)(param_1 + 0x102),1);
  if ((*(short *)(param_1 + 0x104) == -1) &&
     (iVar4 = FUN_005cfac0(*(int *)(param_1 + 0xa4) + 0x54), iVar4 != 0)) {
    uVar3 = FUN_005cffb0(*(int *)(param_1 + 0xa4) + 0x54);
    sVar2 = FUN_0067bf50(param_1,uVar3);
    *(short *)(param_1 + 0x104) = sVar2;
    if (sVar2 == -1) {
      return 0xffffffff;
    }
  }
  FUN_0067c7b0((int)*(short *)(param_1 + 0x104),1);
  return 1;
}

