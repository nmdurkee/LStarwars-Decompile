/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a4a20; label: FUN_004a4a20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4a20(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  if ((DAT_0087b8cc == 0) || ((*(uint *)(param_1 + 0xef0) & 0x10000000) != 0)) {
    fVar3 = (float10)1e+06;
  }
  else {
    fVar3 = (float10)FUN_005b3c50(param_1 + 0x80,DAT_0087b8cc,0);
  }
  if (*(char *)(param_1 + 0x7b5) != '\"') {
    if (((((DAT_0087b8cc != 0) && (param_1 != DAT_0087b8c8)) &&
         ((DAT_0087b8d0 != 2 || ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x10) != 0)))) &&
        (iVar2 = FUN_004e4a80(param_1), iVar2 == 0)) &&
       ((((DAT_0087b8d0 != 3 || (DAT_0087b8c8 == 0)) || (*(int *)(DAT_0087b8c8 + 0x790) == param_1))
        && ((float)fVar3 < (_DAT_0087b890 - 0.2) * (_DAT_0087b890 - 0.2))))) {
      FUN_0055e4a0(param_1,1);
      FUN_0055e4e0(param_1 + 0x6c4);
      *(undefined4 *)(param_1 + 0x77c) = 0x3f000000;
      *(undefined1 *)(param_1 + 0x7b5) = 0x22;
      *(undefined2 *)(param_1 + 0x7aa) = 5;
      *(undefined4 *)(param_1 + 0x778) = 0;
      FUN_00681f40("JForcePush",param_1 + 0x80);
    }
    return;
  }
  iVar2 = FUN_004e4a80(param_1);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 100) = 0x40bb3333;
  }
  *(float *)(param_1 + 0x778) = _DAT_00925018 + *(float *)(param_1 + 0x778);
  if ((0.0 < *(float *)(param_1 + 0x77c)) &&
     (fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018, *(float *)(param_1 + 0x77c) = fVar1,
     fVar1 < 0.0)) {
    *(undefined4 *)(param_1 + 0x77c) = 0;
  }
  iVar2 = DAT_0087b8d0;
  if ((DAT_0087b8cc == 0) || ((_DAT_0087b890 + 0.2) * (_DAT_0087b890 + 0.2) < (float)fVar3)) {
    if (*(float *)(param_1 + 0x77c) <= 0.0) {
      *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfdffffff;
      *(undefined4 *)(param_1 + 0xd24) = 0;
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x400;
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
  }
  else if (DAT_0087b8d0 == 4) {
    if (*(float *)(param_1 + 0x77c) < 0.2) {
      *(undefined4 *)(param_1 + 0x77c) = 0x3e4ccccd;
    }
    goto LAB_004a4b97;
  }
  if (iVar2 == 2) {
    FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x8ac),
                 param_1 + 0x80,0x32,_DAT_00925018,0,0,0);
  }
LAB_004a4b97:
  iVar2 = FUN_0054fa60(0);
  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),(float)iVar2 * 1.5259022e-05 * 0.6);
  return;
}

