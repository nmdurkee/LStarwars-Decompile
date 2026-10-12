/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de060; label: FUN_005de060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005de060(void)

{
  int *piVar1;
  int *piVar2;
  int *in_ECX;
  int *piVar3;
  
  if (DAT_00973ecc == (int *)0x0) {
    DAT_00973ecc = in_ECX;
    in_ECX[2] = 0;
    DAT_00973ec8 = DAT_00973ec8 + 1;
    return;
  }
  piVar2 = DAT_00973ecc;
  piVar3 = (int *)0x0;
  do {
    piVar1 = piVar2;
    piVar2 = piVar1;
    if (*in_ECX <= *piVar1) break;
    piVar2 = (int *)piVar1[2];
    piVar3 = piVar1;
  } while (piVar2 != (int *)0x0);
  if (piVar3 == (int *)0x0) {
    in_ECX[2] = (int)DAT_00973ecc;
    DAT_00973ec8 = DAT_00973ec8 + 1;
    DAT_00973ecc = in_ECX;
    return;
  }
  in_ECX[2] = (int)piVar2;
  piVar3[2] = (int)in_ECX;
  DAT_00973ec8 = DAT_00973ec8 + 1;
  return;
}

