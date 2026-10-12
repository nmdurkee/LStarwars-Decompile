/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639c80; label: FUN_00639c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639c80(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((DAT_0291396c != 0) &&
     (iVar1 = DAT_0291396c + param_1 * 0x24, *(int *)(DAT_0291396c + 0xd0 + param_1 * 0x24) != 0)) {
    *(undefined4 *)(iVar1 + 0xd4) = *param_2;
    *(undefined4 *)(iVar1 + 0xd8) = param_2[1];
    *(undefined4 *)(iVar1 + 0xdc) = param_2[2];
  }
  return;
}

