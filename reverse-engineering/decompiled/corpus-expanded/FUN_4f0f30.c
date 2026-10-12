/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0f30; label: FUN_004f0f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f0f30(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_2 - 1;
  DAT_0091eeb8 = 0;
  if ((-1 < (int)uVar2) && (uVar2 < (uint)param_1[1])) {
    if (*param_1 == 0x12345678) {
      piVar1 = param_1 + 3;
    }
    else if (*param_1 == 0x1234567a) {
      piVar1 = param_1 + 6;
    }
    else {
      piVar1 = param_1 + 5;
    }
    if ((*(byte *)(piVar1 + uVar2 * 7 + 4) & 2) == 0) {
      if (param_3 != (int *)0x0) {
        *param_3 = piVar1[uVar2 * 7 + 1] + (int)param_1;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = piVar1[uVar2 * 7 + 2];
      }
      return 1;
    }
  }
  return 0;
}

