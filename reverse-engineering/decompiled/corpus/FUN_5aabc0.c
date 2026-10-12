/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aabc0; label: FUN_005aabc0
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

