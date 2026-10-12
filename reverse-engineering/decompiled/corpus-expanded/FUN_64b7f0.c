/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b7f0; label: FUN_0064b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064b7f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0081020c) {
    piVar1 = (int *)(DAT_0291f664 + 0x154);
    do {
      if ((((*(byte *)(piVar1 + -4) & 1) != 0) && (*piVar1 != 0)) && (piVar1[-3] == param_1)) {
        piVar1[-3] = 0;
        piVar1[-2] = 0;
        piVar1[-1] = 0;
        piVar1[-4] = piVar1[-4] & 0xfffffffe;
        *piVar1 = 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x88;
    } while (iVar2 < DAT_0081020c);
  }
  return;
}

