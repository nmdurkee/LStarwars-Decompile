/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x498a40; label: FUN_00498a40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00498a40(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xffffafcf;
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xf83fffef;
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0xdfffffff;
  *(undefined1 *)(param_1 + 0xe3f) = 0xff;
  *(undefined1 *)(param_1 + 0xe40) = 0xff;
  *(undefined1 *)(param_1 + 0xe3d) = 0;
  *(undefined1 *)(param_1 + 0xe3e) = 0xff;
  FUN_004988b0(param_1,0);
  if ((*(byte *)(param_1 + 0xef4) & 8) == 0) {
    return;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfff7ffff;
  iVar2 = FUN_0054fa60();
  *(float *)(param_1 + 0xc50) = (float)iVar2 * 1.5259022e-05 * 0.03 - 0.015;
  iVar2 = FUN_0054fa60();
  *(float *)(param_1 + 0xc54) = (float)iVar2 * 1.5259022e-05 * 0.03 - 0.015;
  iVar2 = FUN_0054fa60();
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffffffb;
  *(undefined4 *)(param_1 + 0xd04) = 0;
  *(undefined4 *)(param_1 + 0xcfc) = 0;
  *(undefined4 *)(param_1 + 0xd00) = 0;
  *(undefined4 *)(param_1 + 0xcb0) = 0;
  *(float *)(param_1 + 0xc58) = (float)iVar2 * 1.5259022e-05 * 0.03 - 0.015;
  if (*(char *)(param_1 + 0x7b5) != '\n') {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffff7ff;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffddfff;
  *(undefined4 *)(param_1 + 0xd7c) = 0;
  *(undefined1 *)(param_1 + 0xe34) = 1;
  *(undefined4 *)(param_1 + 0xd18) = 0;
  *(undefined1 *)(param_1 + 0xe47) = 0xff;
  *(undefined1 *)(param_1 + 0xe46) = 0xff;
  *(undefined1 *)(param_1 + 0xe45) = 0xff;
  *(undefined1 *)(param_1 + 0xe44) = 0xff;
  *(undefined2 *)(param_1 + 0x4a) = 0xffff;
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x8040) == 0) {
    *(undefined1 *)(param_1 + 0xe32) = 0;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0x7fffffff;
  if (*(int *)(param_1 + 0xe04) != -1) {
    FUN_00635970(*(int *)(param_1 + 0xe04),0);
  }
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffdbf;
  *(undefined1 *)(param_1 + 0x107d) = 0;
  if (*(char *)(param_1 + 0x281) == '\0') {
    if (0.0 < *(float *)(param_1 + 0xd24)) {
      fVar1 = *(float *)(param_1 + 0xd24) - _DAT_00925018;
      goto LAB_00498bfc;
    }
  }
  else {
    fVar1 = 0.2;
LAB_00498bfc:
    *(float *)(param_1 + 0xd24) = fVar1;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) || (iVar2 = FUN_00498120(), iVar2 == 0)) {
    if (0.0 < *(float *)(param_1 + 0x103c)) {
      fVar1 = *(float *)(param_1 + 0x103c) - _DAT_00925018;
      goto LAB_00498c37;
    }
  }
  else {
    fVar1 = 0.1;
LAB_00498c37:
    *(float *)(param_1 + 0x103c) = fVar1;
  }
  FUN_0055d130(param_1,0x3f800000,param_1 + 0xda0);
  fVar3 = (float10)FUN_00498480(param_1);
  *(float *)(param_1 + 0xdb8) = (float)fVar3;
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x117) == -1) {
    *(undefined1 *)(param_1 + 0xe43) = 0xff;
    goto LAB_00498cc4;
  }
  if (*(char *)(param_1 + 0x280) != -1) {
    iVar2 = FUN_0056e160(0x19);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 0xe43) = 0;
      goto LAB_00498cc4;
    }
    if ((*(char *)(param_1 + 0x280) != -1) && (iVar2 = FUN_0041af30(param_1), iVar2 != 0)) {
      *(undefined1 *)(param_1 + 0xe43) = 3;
      goto LAB_00498cc4;
    }
  }
  *(undefined1 *)(param_1 + 0xe43) =
       *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x117);
LAB_00498cc4:
  fVar1 = _DAT_00925018;
  if ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c) == 0) {
    if ((0.0 < *(float *)(param_1 + 0xde4)) && (*(float *)(param_1 + 0xde4) < 0.25)) {
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x40;
    }
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xffff5fff;
    *(undefined4 *)(param_1 + 0xde4) = 0;
    return;
  }
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xffff5fff;
  *(float *)(param_1 + 0xde4) = fVar1 + *(float *)(param_1 + 0xde4);
  return;
}

