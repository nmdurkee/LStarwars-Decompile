/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x5756c0; label: FUN_005756c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005756c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4698);
  if ((iVar3 != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x469c))) {
    do {
      iVar1 = FUN_004f8b10(param_2,iVar3);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x128;
    } while (iVar2 < *(int *)(param_1 + 0x469c));
  }
  return 0;
}

