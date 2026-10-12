/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x566de0; label: FUN_00566de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00566de0(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    iVar4 = 0;
    do {
      iVar1 = FUN_005d0450(iVar4 + 0x30 + *(int *)(param_1 + 0x50c4),param_2);
      if ((iVar1 != 0) &&
         (((*(uint *)(iVar4 + 0x7c + *(int *)(param_1 + 0x50c4)) & 0x2000) != 0 || (param_3 != 0))))
      {
        *param_4 = 0;
        return 0;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x100;
    } while (iVar3 < *(int *)(param_1 + 0x50bc));
  }
  if ((int)(uint)*(ushort *)(*(int *)(param_1 + 0x128) + 0xdc) <= *(int *)(param_1 + 0x50bc)) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x50bc) * 0x100 + *(int *)(param_1 + 0x50c4);
  if ((param_2 != (undefined4 *)0x0) && (iVar4 = FUN_005cfac0(param_2), iVar4 != 0)) {
    *(undefined4 *)(iVar3 + 0x30) = *param_2;
    *(undefined4 *)(iVar3 + 0x34) = param_2[1];
    *(undefined4 *)(iVar3 + 0x38) = param_2[2];
    uVar2 = FUN_005cfa50((undefined4 *)(iVar3 + 0x30));
    FUN_004f1f10(iVar3 + 0xd8,uVar2);
  }
  *(undefined4 *)(iVar3 + 0xa0) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0xa8) = 0xffffffff;
  *(undefined2 *)(iVar3 + 0xac) = 0xffff;
  *(undefined4 *)(iVar3 + 0xa4) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x80) = 100;
  *(undefined1 *)(iVar3 + 0xfb) = 1;
  *(undefined4 *)(iVar3 + 0x7c) = 0xc000;
  if (param_3 != 0) {
    *(undefined4 *)(iVar3 + 0x7c) = 0xe000;
  }
  *(undefined4 *)(iVar3 + 0x88) = 0x3f800000;
  iVar4 = FUN_005d0420((int *)(iVar3 + 0x30));
  if (iVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x8c) = 0x3f800000;
  }
  else {
    fVar5 = (float10)FUN_005ca4b0(*(undefined4 *)
                                   (*(int *)(*(int *)(iVar3 + 0x30) + 0x54) +
                                   (uint)*(ushort *)(iVar4 + 0x5c) * 4));
    *(float *)(iVar3 + 0x8c) = (float)fVar5;
  }
  *(undefined4 *)(iVar3 + 0x90) = 0x3f800000;
  *(undefined4 *)(iVar3 + 0x9c) = 0;
  *(undefined4 *)(iVar3 + 0x84) = 0x3f800000;
  FUN_0059ae10(iVar3 + 0xb4,param_2);
  *(int *)(param_1 + 0x50bc) = *(int *)(param_1 + 0x50bc) + 1;
  return iVar3;
}

