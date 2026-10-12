/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c030; label: FUN_0060c030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060c030(int param_1,int param_2,undefined4 param_3)

{
  int *unaff_FS_OFFSET;
  int local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_0074fbc0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  local_8 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0060a240(param_1,param_3);
    param_1 = param_1 + 8;
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

