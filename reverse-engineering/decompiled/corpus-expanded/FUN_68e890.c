/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68e890; label: FUN_0068e890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068e890(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = &DAT_02924b60;
  do {
    if ((*(char *)((int)piVar3 + 0x41) == (char)param_1) && (*piVar3 == 99999)) {
      *piVar3 = -1;
      iVar1 = FUN_00658330(piVar3 + 5,param_1,0);
      piVar3[-1] = iVar1;
      FUN_0068e6f0(iVar2);
      if (*piVar3 == -1) {
        *piVar3 = 99999;
      }
    }
    piVar3 = piVar3 + 0x16;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0x292fb60);
  *(undefined4 *)(&DAT_02948eb0 + (char)param_1 * 4) = 1;
  return;
}

