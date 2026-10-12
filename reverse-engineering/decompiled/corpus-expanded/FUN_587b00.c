/* Ghidra pseudocode, not original source.
 * ev_aa81935a86a90d95efe1cd13896fafaf1f7525855a34f109f6da8479aa997be3
 * Entry: 0x587b00; label: FUN_00587b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00587b00(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) | 0x40000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) & 0xfffbffff;
    }
  }
  return;
}

