/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e2b0; label: FUN_0055e2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055e2b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_0093d7f0;
  while ((((iVar1 = *piVar2, iVar1 == 0 || ((*(uint *)(iVar1 + 0x1fc) & 1) == 0)) ||
          ((*(uint *)(iVar1 + 0x1fc) & 0x1000) == 0)) || (*(short *)(iVar1 + 0x1064) != param_1))) {
    piVar2 = piVar2 + 1;
    if (0x93d80f < (int)piVar2) {
      return 0;
    }
  }
  return iVar1;
}

