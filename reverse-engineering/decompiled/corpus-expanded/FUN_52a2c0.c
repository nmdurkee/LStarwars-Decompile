/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a2c0; label: FUN_0052a2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052a2c0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    iVar1 = *(int *)(DAT_009238e4 + 0x371b0);
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((*(uint *)(iVar1 + 0x68) & uVar2) != 0) {
      *(uint *)(iVar1 + 0x68) = *(uint *)(iVar1 + 0x68) & ~uVar2;
      return;
    }
    *(uint *)(iVar1 + 0x68) = *(uint *)(iVar1 + 0x68) | uVar2;
  }
  return;
}

