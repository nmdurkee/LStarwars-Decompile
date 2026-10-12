/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc700; label: FUN_006bc700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bc700(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = in_ECX + 0x2ac;
  do {
    iVar1 = FUN_004f8b10(iVar3,param_1);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0xa8;
  } while (iVar2 < 10);
  return -1;
}

