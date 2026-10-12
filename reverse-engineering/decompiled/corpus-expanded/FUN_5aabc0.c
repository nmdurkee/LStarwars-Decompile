/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aabc0; label: FUN_005aabc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005aabc0(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = FUN_004f1440(param_1 + 0x10); iVar1 != 0;
        iVar1 = FUN_004f1460(param_1 + 0x10,iVar1)) {
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
  }
  return;
}

