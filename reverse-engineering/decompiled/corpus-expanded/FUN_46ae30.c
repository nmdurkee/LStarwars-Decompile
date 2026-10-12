/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46ae30; label: FUN_0046ae30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ae30(undefined4 param_1)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + in_EAX * 0x14);
  if (iVar1 != -1) {
    fVar2 = _DAT_007f8df4;
    if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x104) == 4)) {
      fVar2 = _DAT_007f8df4 * 0.5;
    }
    iVar3 = FUN_0062c350(fVar2,_DAT_00925018);
    if (0 < iVar3) {
      FUN_00684c90(iVar1,param_1,iVar3,0,0);
    }
  }
  return;
}

