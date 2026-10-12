/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x621070; label: FUN_00621070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621070(undefined4 *param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  *(undefined4 *)(PTR_DAT_0080f7ec + 0x18) = *param_1;
  *(undefined4 *)(puVar1 + 0x1c) = param_1[1];
  *(undefined4 *)(puVar1 + 0x20) = param_1[2];
  return;
}

