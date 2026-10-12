/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dc2f0; label: FUN_005dc2f0
 */

void FUN_005dc2f0(int param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  float10 fVar5;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(0);
  FUN_00607d70(0xd,7,param_5);
  if (0 < param_3) {
    piVar3 = (int *)(param_1 + 4);
    puVar4 = param_2;
    do {
      fVar5 = (float10)FUN_005c1f70();
      if (param_2 != (undefined4 *)0x0) {
        uVar1 = *(undefined4 *)(((int)param_2 - param_1) + (int)piVar3);
        iVar2 = *DAT_02854d10;
        *(undefined4 *)(iVar2 + 0x10) = *puVar4;
        *(undefined4 *)(iVar2 + 0x14) = uVar1;
      }
      FUN_006009e0((float)(fVar5 * (float10)piVar3[-1]),(float)((float10)*piVar3 * fVar5),0);
      puVar4 = puVar4 + 2;
      piVar3 = piVar3 + 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  FUN_006009a0();
  iVar2 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar2));
  return;
}

