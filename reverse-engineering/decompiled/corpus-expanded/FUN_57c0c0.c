/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57c0c0; label: FUN_0057c0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057c0c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = 0;
  if (*(short *)(iVar1 + 4) != 0) {
    do {
      FUN_0057c030(DAT_00951c64);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(ushort *)(iVar1 + 4));
  }
  return;
}

