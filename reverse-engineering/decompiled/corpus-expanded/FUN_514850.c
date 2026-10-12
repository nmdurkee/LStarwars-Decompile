/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x514850; label: FUN_00514850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00514850(undefined4 param_1,float *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  float local_4;
  
  local_4 = 0.0;
  iVar1 = FUN_004f8b10(param_1,&DAT_00760000);
  if (iVar1 == 0) {
    fVar3 = (float10)FUN_005b9dd0();
  }
  else {
    iVar1 = FUN_004f8b10(param_1,"false");
    if (iVar1 == 0) {
      fVar3 = (float10)0;
    }
    else {
      iVar1 = FUN_004f8b10(param_1,&DAT_0075fff8);
      if (iVar1 == 0) {
        fVar3 = (float10)1;
      }
      else {
        iVar1 = FUN_004f8b10(param_1,&PTR_s_ORM_00786158_0x15_007584a8);
        if (iVar1 == 0) {
          fVar3 = (float10)3.4028235e+38;
        }
        else {
          if (DAT_009238c0 != (code *)0x0) {
            iVar1 = (*DAT_009238c0)(DAT_0092225c,DAT_00922260,param_1,&local_4);
            if (iVar1 != 0) goto LAB_005148f5;
          }
          fVar3 = (float10)FUN_005147c0(DAT_00922260,param_1);
        }
      }
    }
  }
  local_4 = (float)fVar3;
LAB_005148f5:
  if (param_2 != (float *)0x0) {
    *param_2 = local_4;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = FUN_006e6b90();
    *param_3 = uVar2;
    return 0;
  }
  return 0;
}

