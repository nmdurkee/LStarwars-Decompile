/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a380; label: FUN_0060a380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060a380(int param_1,int param_2,int param_3)

{
  int *unaff_FS_OFFSET;
  int local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_0074fb60;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_0060a240(param_3,param_1);
    param_3 = param_3 + 8;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}

