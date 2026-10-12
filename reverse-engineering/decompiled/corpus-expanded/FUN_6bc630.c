/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc630; label: FUN_006bc630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bc630(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x2a8)) {
    iVar2 = in_ECX + 0x2ac;
    do {
      iVar1 = FUN_004f8b10(iVar2,param_1);
      if (iVar1 == 0) {
        iVar2 = iVar3 * 0xa8 + in_ECX;
        *(undefined4 *)(iVar2 + 0x34c) = param_2;
        *(uint *)(iVar2 + 0x350) =
             *(uint *)(iVar2 + 0x350) ^ (*(uint *)(iVar2 + 0x350) ^ param_3) & 1;
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xa8;
    } while (iVar3 < *(int *)(in_ECX + 0x2a8));
  }
  iVar3 = *(int *)(in_ECX + 0x2a8);
  iVar2 = 0;
  if (iVar3 < 10) {
    *(int *)(in_ECX + 0x2a8) = iVar3 + 1;
    iVar2 = in_ECX + iVar3 * 0xa8;
    FUN_004f1f40(iVar2 + 0x2ac,param_1,0x20);
    *(uint *)(iVar2 + 0x350) = *(uint *)(iVar2 + 0x350) ^ (*(uint *)(iVar2 + 0x350) ^ param_3) & 1;
    *(undefined4 *)(iVar2 + 0x34c) = param_2;
    iVar2 = iVar3;
  }
  return iVar2;
}

