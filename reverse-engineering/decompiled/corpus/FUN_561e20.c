/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561e20; label: FUN_00561e20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00561e20(int param_1,float *param_2,int param_3,float param_4,float param_5,undefined1 param_6)

{
  short sVar1;
  undefined2 uVar2;
  float10 fVar3;
  
  if (_DAT_0080283c == -1) {
    return 0;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x200000) != 0) {
    return 0;
  }
  FUN_0055e4a0(param_1,0);
  FUN_0055e4e0(param_1 + 0x6c4);
  *(undefined1 *)(param_1 + 0x7b4) = param_6;
  *(undefined1 *)(param_1 + 0x7b5) = DAT_0080283c;
  *(undefined1 *)(param_1 + 0x7b3) = 1;
  sVar1 = (*(code *)PTR_FUN_00802d98)(param_1);
  *(short *)(param_1 + 0x7aa) = sVar1;
  fVar3 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar1,0,0,0);
  *(float *)(param_1 + 0x784) = (float)fVar3;
  if ((float)fVar3 == 0.0) {
    *(undefined4 *)(param_1 + 0x784) = 0x3f800000;
    *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c0c;
  }
  else {
    FUN_0062e650(param_1 + 8,0xffffffff);
  }
  *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x784) = param_5 * *(float *)(param_1 + 0x784);
  *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x77c) = 0;
  *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
  *(float *)(param_1 + 0x754) = *param_2;
  *(float *)(param_1 + 0x758) = param_2[1];
  *(float *)(param_1 + 0x75c) = param_2[2];
  *(float *)(param_1 + 0x758) =
       *(float *)(param_1 + 0x758) - *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8);
  uVar2 = FUN_005be2d0(*param_2 - *(float *)(param_1 + 0x748),
                       param_2[2] - *(float *)(param_1 + 0x750));
  *(undefined2 *)(param_1 + 0x5a) = uVar2;
  *(undefined2 *)(param_1 + 0x58) = uVar2;
  *(undefined2 *)(param_1 + 0x27a) = uVar2;
  *(uint *)(param_1 + 0xef0) =
       *(uint *)(param_1 + 0xef0) ^ (param_3 << 0xd ^ *(uint *)(param_1 + 0xef0)) & 0x2000;
  FUN_00547f30(param_1,2);
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) | 0x2000000;
  *(float *)(param_1 + 0xf0c) = param_4;
  *(undefined4 *)(param_1 + 0x44c) = 0;
  if (param_4 < 0.0) {
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffffeff;
    *(undefined4 *)(param_1 + 0xf0c) = 0;
    return 1;
  }
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffffeff;
  return 1;
}

