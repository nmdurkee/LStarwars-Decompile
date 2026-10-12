/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d38f0; label: FUN_006d38f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d38f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < param_2) {
    psVar2 = (short *)(param_1 + 0x5e);
    do {
      if ((*(int *)(param_3 + 0x40) == *(int *)(psVar2 + -0xf)) &&
         (*(short *)(param_3 + 0x5e) == *psVar2)) break;
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x4e;
    } while (iVar1 < param_2);
  }
  if (iVar1 == param_2) {
    iVar1 = param_2 + -1;
  }
  if (0 < iVar1) {
    FUN_004ef660(param_1 + 0x9c,param_1,iVar1 * 0x9c);
  }
  FUN_004ef660(param_1,param_3,0x9c);
  return;
}

