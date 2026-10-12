/* Ghidra pseudocode, not original source.
 * ev_aa81935a86a90d95efe1cd13896fafaf1f7525855a34f109f6da8479aa997be3
 * Entry: 0x5877c0; label: FUN_005877c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005877c0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076362c);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 0;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"green");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 1;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00754f70);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 2;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"purple");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 3;
    }
  }
  return;
}

