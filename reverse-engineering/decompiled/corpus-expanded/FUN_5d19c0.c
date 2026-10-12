/* Ghidra pseudocode, not original source.
 * ev_573fcacabc8e68ea03635b0f8aa232ed45a87b6cc51fa6af4ed20e3c9ee5dc27
 * Entry: 0x5d19c0; label: FUN_005d19c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d19c0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_004eef40(param_2 + 0x1bc,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",
                         0x182);
  }
  else {
    iVar1 = *param_1;
    *param_1 = iVar1 + 0x1bc + param_2;
  }
  if (iVar1 != 0) {
    FUN_005d1950(iVar1);
    if (param_1 == (int *)0x0) {
      *(ushort *)(iVar1 + 0x1b6) = *(ushort *)(iVar1 + 0x1b6) | 1;
    }
    if (param_3 != 0) {
      FUN_004f1f10(iVar1 + 8,param_3);
    }
  }
  return iVar1;
}

