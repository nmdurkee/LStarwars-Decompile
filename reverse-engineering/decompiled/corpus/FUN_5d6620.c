/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d6620; label: FUN_005d6620
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

