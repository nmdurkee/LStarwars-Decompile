/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7e90; label: FUN_006c7e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c7e90(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = DAT_0081fdf8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    iVar2 = iVar2 + *(int *)(iVar1 + 0x34);
  }
  return iVar2;
}

