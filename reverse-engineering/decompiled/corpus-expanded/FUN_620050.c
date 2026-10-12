/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620050; label: FUN_00620050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00620050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  *(undefined4 *)(PTR_DAT_0080f7ec + 0x74) = param_1;
  *(undefined4 *)(puVar1 + 0x78) = param_2;
  *(undefined4 *)(puVar1 + 0x7c) = param_3;
  return;
}

