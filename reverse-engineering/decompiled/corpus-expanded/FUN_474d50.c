/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474d50; label: FUN_00474d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00474d50(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    piVar2 = &DAT_007f939c;
    do {
      if (((int *)*piVar2 != (int *)0x0) && (*(int *)*piVar2 == param_1)) {
        return 1;
      }
      piVar1 = piVar2 + 2;
      piVar2 = piVar2 + 0xf;
    } while (*piVar1 != 0);
  }
  return 0;
}

