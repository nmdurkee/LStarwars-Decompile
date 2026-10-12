/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x530150; label: FUN_00530150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00530150(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  float10 fVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00801c94 != 0) {
    FUN_0052ff40(param_1,param_2,param_3,param_4);
    return;
  }
  if ((*(byte *)(param_2 + 0x166) & 1) != 0) {
    fVar1 = (float10)FUN_005bed80(param_3 + 0x5c,param_2 + 0x1b4,&local_c);
    if ((float)fVar1 == 0.0) {
      local_c = *(undefined4 *)(param_2 + 0x1c4);
      local_8 = 0;
      local_4 = 0;
    }
    else {
      FUN_005b3830(&local_c,&local_c,*(float *)(param_2 + 0x1c4) / (float)fVar1);
    }
    FUN_005b37d0(param_2 + 0x104,param_3 + 0x5c,&local_c);
    *(undefined4 *)(param_2 + 0x110) = 0;
    return;
  }
  FUN_0051e910(param_1,param_3,param_4);
  return;
}

