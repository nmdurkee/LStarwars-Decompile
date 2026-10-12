/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ced10; label: FUN_006ced10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ced10(void)

{
  int iVar1;
  int in_ECX;
  
  for (iVar1 = *(int *)(in_ECX + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if (_DAT_0081fa00 <= *(float *)(iVar1 + 0x48)) {
      FUN_006c7730();
    }
    else {
      FUN_006c7660();
    }
  }
  return;
}

