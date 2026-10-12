/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51f600; label: FUN_0051f600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051f600(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if (0.0 < *(float *)(param_2 + 0x1c4)) {
    fVar2 = (float10)FUN_005b3c50(param_2 + 0x1b4,(undefined4 *)(param_3 + 0x5c),local_c);
    if ((float)fVar2 < *(float *)(param_2 + 0x1c4) * *(float *)(param_2 + 0x1c4)) {
      *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_3 + 0x5c);
      *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
      uVar1 = *(undefined4 *)(param_3 + 100);
      *(undefined4 *)(param_2 + 0x110) = 0;
      *(undefined4 *)(param_2 + 0x10c) = uVar1;
      return;
    }
  }
  *(undefined4 *)(param_2 + 0x110) = 0;
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_2 + 0x1b4);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0x1b8);
  *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_2 + 0x1bc);
  return;
}

