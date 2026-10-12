/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620fa0; label: FUN_00620fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00620fa0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)PTR_DAT_0080f7ec;
    param_1[1] = *(undefined4 *)(puVar1 + 4);
    param_1[2] = *(undefined4 *)(puVar1 + 8);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(puVar1 + 0xc);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(puVar1 + 0x10);
  }
  return;
}

