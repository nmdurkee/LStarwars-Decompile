/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x6015e0; label: FUN_006015e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006015e0(int *param_1)

{
  uint uVar1;
  
  DAT_02854d50 = *param_1;
  if (DAT_02854c20 != 0) {
    uVar1 = *(uint *)(DAT_02854c20 + 0x40) >> 0xc & 3;
    if (uVar1 == 0) {
      if (DAT_02854d50 != 0) goto LAB_0060160c;
    }
    else {
      if (uVar1 != 1) {
        return;
      }
      if (DAT_02854d50 == 0) {
LAB_0060160c:
        FUN_006e5340(0x16,2);
        return;
      }
    }
    FUN_006e5340(0x16,3);
  }
  return;
}

