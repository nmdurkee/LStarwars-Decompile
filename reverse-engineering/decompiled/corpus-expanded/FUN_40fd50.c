/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x40fd50; label: FUN_0040fd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040fd50(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x511c);
  *param_2 = *(undefined4 *)(iVar1 + 0x636f0);
  param_2[1] = *(undefined4 *)(iVar1 + 0x636f4);
  param_2[2] = *(undefined4 *)(iVar1 + 0x636f8);
  return;
}

