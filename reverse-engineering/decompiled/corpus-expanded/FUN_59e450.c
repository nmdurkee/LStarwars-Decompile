/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e450; label: FUN_0059e450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e450(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00956430 < 0x20) {
    iVar1 = (-1 - param_1) * 0x70 + 0x20;
    do {
      iVar2 = (int)*(short *)(iVar1 + DAT_009562f8);
      if (iVar2 == param_1) {
        return;
      }
      if (*(short *)(iVar1 + DAT_009562f8) < 0) {
        FUN_0059e450(iVar2);
      }
      else {
        (&DAT_00956350)[DAT_00956430] = iVar2;
        DAT_00956430 = DAT_00956430 + 1;
      }
      iVar1 = iVar1 + 2;
    } while (DAT_00956430 < 0x20);
  }
  return;
}

