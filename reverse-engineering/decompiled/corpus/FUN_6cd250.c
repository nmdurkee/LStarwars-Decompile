/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cd250; label: FUN_006cd250
 */

float10 FUN_006cd250(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  float10 fVar2;
  float local_70;
  float local_6c;
  undefined4 local_68;
  int *local_64;
  undefined1 local_60 [16];
  undefined1 local_50 [48];
  undefined1 auStack_20 [28];
  
  local_6c = 1.0;
  local_70 = 3.4028235e+38;
  iVar1 = FUN_006c6a10(&local_68,param_3,8,1);
  if (iVar1 != 0) {
    if ((*(byte *)(local_64 + 7) & 8) != 0) {
      if (local_64[3] == DAT_02973abc) {
        (**(code **)(*local_64 + 4))(local_68,DAT_02973abc,local_50,0);
        FUN_004ef660(local_60,auStack_20,0x10);
      }
      else {
        (**(code **)(*local_64 + 4))(local_68,DAT_02973ab8,local_60,0);
      }
    }
    iVar1 = FUN_006c6a10(&local_68,param_3,0x40,1);
    if ((iVar1 != 0) && ((*(byte *)(local_64 + 7) & 0x40) != 0)) {
      (**(code **)(*local_64 + 4))(local_68,DAT_02973ab4,&local_6c,0);
    }
    fVar2 = (float10)FUN_006c0a10(param_1,param_2,local_60,0);
    local_70 = (float)fVar2 - local_6c;
    if (local_70 < 0.0) {
      local_70 = 0.0;
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  return (float10)local_70;
}

