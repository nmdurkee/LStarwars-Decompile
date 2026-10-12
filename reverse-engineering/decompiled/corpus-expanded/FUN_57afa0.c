/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57afa0; label: FUN_0057afa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057afa0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x10) {
      FUN_004f1f10(DAT_00951c4c + 0xf4,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

