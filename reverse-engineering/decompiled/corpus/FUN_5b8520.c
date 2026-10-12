/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8520; label: FUN_005b8520
 */

void FUN_005b8520(float *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *extraout_EDX_00;
  int extraout_EDX_01;
  float10 fVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined8 uVar3;
  
  FUN_005b83b0(param_2,param_3);
  FUN_005b83b0(extraout_EDX,param_4);
  FUN_005b83b0(param_4,param_5);
  fVar2 = (float10)FUN_005b8460(*param_2,*extraout_EDX_00,*param_4,*param_5,param_6);
  *param_1 = (float)fVar2;
  uVar3 = FUN_005b8460(param_2[1],*(undefined4 *)(extraout_EDX_01 + 4),param_4[1],param_5[1],param_6
                      );
  *(float *)((int)uVar3 + 4) = (float)extraout_ST0;
  uVar3 = FUN_005b8460(param_2[2],*(undefined4 *)((int)((ulonglong)uVar3 >> 0x20) + 8),param_4[2],
                       param_5[2],param_6);
  *(float *)((int)uVar3 + 8) = (float)extraout_ST0_00;
  iVar1 = FUN_005b8460(param_2[3],*(undefined4 *)((int)((ulonglong)uVar3 >> 0x20) + 0xc),param_4[3],
                       param_5[3],param_6);
  *(float *)(iVar1 + 0xc) = (float)extraout_ST0_01;
  return;
}

