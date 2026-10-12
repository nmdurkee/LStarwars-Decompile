/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ef810; label: FUN_005ef810
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ef810(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  _DAT_0297dc40 = 1;
  iVar2 = FUN_005ef1d0(param_2,&stack0x0000000c,param_1);
  if (((iVar2 != 0) && (DAT_0297dc44 != 0)) &&
     (iVar3 = 0, *(int *)(*(int *)(iVar2 + 0x110) + 0x6c) != 0)) {
    do {
      pbVar1 = (byte *)(*(int *)(*(int *)(iVar2 + 0x110) + 0x48) + iVar3);
      *pbVar1 = *pbVar1 | 0x20;
      iVar3 = iVar3 + 1;
    } while (iVar3 != *(int *)(*(int *)(iVar2 + 0x110) + 0x6c));
  }
  _DAT_0297dc40 = 0;
  return;
}

