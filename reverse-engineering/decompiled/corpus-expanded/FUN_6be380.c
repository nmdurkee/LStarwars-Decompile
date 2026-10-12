/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be380; label: FUN_006be380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006be380(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int *in_ECX;
  undefined1 local_50 [32];
  undefined1 auStack_30 [44];
  
  if ((in_ECX[7] & param_2) != 0) {
    if (((param_2 & 8) != 0) && (in_ECX[3] == DAT_02973abc)) {
      (**(code **)(*in_ECX + 4))(param_1,DAT_02973abc,local_50,0);
      FUN_004ef660(auStack_30,param_4,0x10);
      (**(code **)(*in_ECX + 8))(param_1,DAT_02973abc,&stack0xffffffa0,0,0);
      return 1;
    }
    if ((param_2 & 0x100) == 0) {
      (**(code **)(*in_ECX + 8))(param_1,param_3,param_4,param_5,0);
      return 1;
    }
    (**(code **)(*in_ECX + 8))(param_1,DAT_02973aac,&param_4,2);
  }
  return 0;
}

