/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d1780; label: FUN_004d1780
 */

undefined4 FUN_004d1780(int param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x19c) = *param_2;
  *(undefined4 *)(param_1 + 0x1a0) = param_2[1];
  *(undefined4 *)(param_1 + 0x1a4) = param_2[2];
  *(undefined4 *)(param_1 + 400) = *param_2;
  *(undefined4 *)(param_1 + 0x194) = param_2[1];
  *(undefined4 *)(param_1 + 0x198) = param_2[2];
  *(undefined4 *)(param_1 + 0x80) = *param_2;
  *(undefined4 *)(param_1 + 0x84) = param_2[1];
  uVar2 = param_2[2];
  *(float *)(param_1 + 0x194) = *(float *)(param_1 + 0x1e0) + *(float *)(param_1 + 0x194);
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  *(float *)(param_1 + 0x1a0) = *(float *)(param_1 + 0x1a0) - *(float *)(param_1 + 0x1e0);
  iVar4 = FUN_004d1510();
  if (iVar4 != 0) {
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x88);
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x80000) == 0) {
      fVar1 = *(float *)(param_1 + 0xff4);
    }
    else {
      fVar1 = *(float *)(param_1 + 0xff0);
    }
    uVar3 = *(uint *)(param_1 + 0xe24);
    *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x758) - fVar1 * *(float *)(param_1 + 0xa8);
    *(uint *)(param_1 + 0xe24) = uVar3 & 0xfffffff7;
    FUN_0055d2b0(param_1);
    *(uint *)(param_1 + 0xe24) =
         *(uint *)(param_1 + 0xe24) ^ ((uVar3 >> 3 & 1) * 8 ^ *(uint *)(param_1 + 0xe24)) & 8;
    return 1;
  }
  return 0;
}

