/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0a80; label: FUN_004f0a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined8 FUN_004f0a80(int *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (int)param_2 >> 0x1f;
  if (*param_1 < -1) {
    uVar1 = uVar1 << 8 | param_2 >> 0x18;
    param_2 = param_2 << 8;
  }
  return CONCAT44(((int)DAT_0091ee9c >> 0x1f) + uVar1 + (uint)CARRY4(DAT_0091ee9c,param_2),
                  DAT_0091ee9c + param_2);
}

