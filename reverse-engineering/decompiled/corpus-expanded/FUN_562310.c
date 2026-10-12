/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x562310; label: FUN_00562310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00562310(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  if (((DAT_0080286c != -1) && (DAT_00804c80 != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c80 * 4) != 0)) {
    *(char *)(param_1 + 0x7b5) = (char)DAT_0080286c;
    FUN_0062e650(param_1 + 8,0xffffffff);
    iVar1 = (int)DAT_00804c80;
    *(short *)(param_1 + 0x7aa) = DAT_00804c80;
    fVar2 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar1,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar2;
    if ((float)fVar2 <= 0.0) {
      *(undefined4 *)(param_1 + 0x77c) = 0x3f800000;
    }
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x100000;
    *(undefined4 *)(param_1 + 0xd48) = 0;
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffff7fff;
    *(undefined4 *)(param_1 + 0xd2c) = 0;
    FUN_00547f30(param_1,2);
    return 1;
  }
  return 0;
}

