/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x52db30; label: FUN_0052db30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0052db30(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  if (param_6 == 0) {
    return 1;
  }
  if (param_2 != 0) {
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"state");
        if (iVar1 != 0) {
          local_4 = iVar1 + 6;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
      if ((local_4 != 0) && (*(int *)(param_2 + 0xbc) != 0)) {
        iVar2 = FUN_004f20f0(local_4,*(undefined4 *)(*(int *)(param_2 + 0xbc) + 0x18));
        if (iVar2 == 0) {
          *(undefined4 *)(param_2 + 0xb8) = 0;
          *(undefined1 *)(param_2 + 0xb4) = 0;
          *(undefined1 *)(param_2 + 0xb5) = 0;
          *(undefined4 *)(param_2 + 0xbc) = 0;
          return 1;
        }
      }
    }
    return 1;
  }
  return 1;
}

