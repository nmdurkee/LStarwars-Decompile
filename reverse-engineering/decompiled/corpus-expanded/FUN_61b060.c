/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61b060; label: FUN_0061b060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061b060(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  float fVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_4 + 0x9e);
  if (*(byte *)(param_4 + 0x9c) != 0) {
    bVar1 = *(byte *)(param_4 + 0x9c);
  }
  bVar2 = *(byte *)(param_4 + 0x9f);
  if (*(byte *)(param_4 + 0x9d) != 0) {
    bVar2 = *(byte *)(param_4 + 0x9d);
  }
  if (bVar1 == 0) {
    if (bVar2 == 0) {
      *(undefined4 *)(param_2 + 0x58) = 0;
      *(undefined4 *)(param_2 + 0x54) = 0;
      if (((*(byte *)(param_4 + 0x78) & 0x40) != 0) && (*(code **)(param_2 + 0x70) != (code *)0x0))
      {
        (**(code **)(param_2 + 0x70))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
      }
      return 0;
    }
    fVar3 = (float)bVar2 / 4192.0 + *(float *)(param_2 + 0x5c);
    uVar4 = 0x3f800000;
    if (1.0 < fVar3) goto LAB_0061b0e9;
  }
  else {
    fVar3 = *(float *)(param_2 + 0x5c) - (float)bVar1 / 4192.0;
    uVar4 = 0;
    if (fVar3 < 0.0) {
LAB_0061b0e9:
      *(undefined4 *)(param_2 + 0x5c) = uVar4;
      return 1;
    }
  }
  *(float *)(param_2 + 0x5c) = fVar3;
  return 1;
}

