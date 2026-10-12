/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a5ec0; label: FUN_004a5ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004a5ec0(int param_1,uint param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  
  *(undefined4 *)(param_1 + 0xc80) = *(undefined4 *)(param_2 + 0x80);
  *(undefined4 *)(param_1 + 0xc84) = *(undefined4 *)(param_2 + 0x84);
  *(undefined4 *)(param_1 + 0xc88) = *(undefined4 *)(param_2 + 0x88);
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) &&
     ((*(byte *)(param_1 + 0x1f8) & 1) != 0)) {
    fVar2 = (float10)FUN_005809a0(param_2);
    *(float *)(param_1 + 0xc84) = (float)(fVar2 + (float10)*(float *)(param_1 + 0xc84));
  }
  *(undefined4 *)(param_1 + 0xc8c) = DAT_0093b0cc;
  *(undefined4 *)(param_1 + 0xc90) = DAT_0093b0d0;
  uVar1 = DAT_0093b0d4;
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x800;
  *(undefined4 *)(param_1 + 0xc94) = uVar1;
  *(uint *)(param_1 + 0xcc8) = ~-(uint)(DAT_00951288 != 0) & param_2;
  return 1;
}

