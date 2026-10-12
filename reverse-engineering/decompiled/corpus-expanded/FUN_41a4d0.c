/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x41a4d0; label: FUN_0041a4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0041a4d0(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0093d7f4;
  if ((((param_1 != DAT_0093d7f0) && (iVar1 = DAT_0093d7f0, param_1 != DAT_0093d7f4)) ||
      (iVar1 == 0)) || ((*(byte *)(iVar1 + 0x1fc) & 0x80) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

