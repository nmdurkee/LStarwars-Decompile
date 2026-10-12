/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e3b0; label: FUN_0058e3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058e3b0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_00955598 != (code *)0x0) {
    iVar2 = (*DAT_00955598)(param_1);
    if (iVar2 == 2) {
      *(undefined4 *)(param_1 + 0xde4) = 0;
    }
    else if (DAT_00802820 != -1) {
      iVar2 = FUN_0058dfa0(param_1);
      if (iVar2 != 0) {
        uVar1 = (undefined1)DAT_00802820;
        *(undefined4 *)(param_1 + 0x77c) = 0x3e99999a;
        *(undefined1 *)(param_1 + 0x7b5) = uVar1;
        FUN_00548540(0,param_1,0,1);
        return;
      }
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  return;
}

