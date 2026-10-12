/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdec0; label: FUN_006bdec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bdec0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x70);
  if (iVar1 < 8) {
    *(undefined4 *)(in_ECX + 0x10 + iVar1 * 0xc) = *param_1;
    iVar1 = in_ECX + 0x10 + iVar1 * 0xc;
    *(undefined4 *)(iVar1 + 4) = param_1[1];
    *(undefined4 *)(iVar1 + 8) = param_1[2];
    *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + 1;
  }
  return;
}

