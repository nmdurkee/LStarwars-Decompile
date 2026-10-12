/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d6620; label: FUN_005d6620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d6620(undefined4 param_1,float param_2,int param_3)

{
  undefined1 local_1c [8];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_3 == 0) {
    FUN_005b30a0(local_1c,param_1,&DAT_0080b708);
  }
  else {
    FUN_005b30a0(local_1c,param_1,param_3);
    FUN_005b30a0(local_1c,local_1c,&DAT_0080b708);
  }
  if ((0.0 <= param_2 + (local_14 - DAT_00973730)) && (0.0 <= param_2 + (DAT_00973734 - local_14)))
  {
    FUN_005b3ec0(&local_10,local_1c,&DAT_0080b988);
    param_2 = -param_2;
    if ((param_2 <= local_10) &&
       (((param_2 <= local_c && (param_2 <= local_8)) && (param_2 <= local_4)))) {
      return 0;
    }
  }
  return 1;
}

