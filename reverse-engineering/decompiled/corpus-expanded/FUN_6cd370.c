/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd370; label: FUN_006cd370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006cd370(float *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  float10 fVar2;
  float local_80;
  float local_7c;
  undefined4 local_78;
  int *local_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float local_60;
  float fStack_5c;
  float fStack_58;
  undefined1 local_50 [48];
  undefined1 auStack_20 [28];
  
  local_7c = 0.0;
  local_80 = 3.4028235e+38;
  iVar1 = FUN_006c6a10(&local_78,param_2,8,1);
  if (iVar1 != 0) {
    if ((*(byte *)(local_74 + 7) & 8) != 0) {
      if (local_74[3] == DAT_02973abc) {
        (**(code **)(*local_74 + 4))(local_78,DAT_02973abc,local_50,0);
        FUN_004ef660(&local_60,auStack_20,0x10);
      }
      else {
        (**(code **)(*local_74 + 4))(local_78,DAT_02973ab8,&local_60,0);
      }
    }
    iVar1 = FUN_006c6a10(&local_78,param_2,0x40,1);
    if ((iVar1 != 0) && ((*(byte *)(local_74 + 7) & 0x40) != 0)) {
      (**(code **)(*local_74 + 4))(local_78,DAT_02973ab4,&local_7c,0);
    }
    fStack_70 = *param_1 - local_60;
    fStack_6c = param_1[1] - fStack_5c;
    fStack_68 = param_1[2] - fStack_58;
    fVar2 = (float10)FUN_005c0240(fStack_68 * fStack_68 +
                                  fStack_6c * fStack_6c + fStack_70 * fStack_70);
    local_80 = (float)fVar2 - local_7c;
    if (local_80 < 0.0) {
      local_80 = 0.0;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return (float10)local_80;
}

