/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa920; label: FUN_005fa920
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_005fa920(int param_1,undefined4 param_2,undefined4 param_3,float *param_4,float *param_5,
                 float *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_005fa720(&DAT_028490e8,&DAT_00991da0,param_3);
  if (iVar2 == 0) {
    DAT_028490e8 = 0;
    _DAT_00991da0 = 0;
  }
  *param_4 = (float)DAT_028490e8;
  *param_5 = (float)_DAT_00991da0;
  iVar1 = DAT_028490e8;
  iVar3 = FUN_005fa790(&DAT_028490e8,&DAT_00991da0,param_3);
  if (iVar3 == 0) {
    DAT_028490e8 = *(int *)(param_1 + 4);
    _DAT_00991da0 = *(undefined4 *)(param_1 + 8);
    *param_6 = (float)(DAT_028490e8 - iVar1);
    return true;
  }
  *param_6 = (float)(DAT_028490e8 - iVar1);
  return iVar2 == 0;
}

