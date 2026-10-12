/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57fe80; label: FUN_0057fe80
 */

void FUN_0057fe80(int *param_1)

{
  if (*(short *)(*param_1 + 0x66) != -1) {
    FUN_005478a0((int)*(short *)(*param_1 + 0x66));
    return;
  }
  FUN_00547930(0x28,param_1 + 0x22,0,0);
  return;
}

