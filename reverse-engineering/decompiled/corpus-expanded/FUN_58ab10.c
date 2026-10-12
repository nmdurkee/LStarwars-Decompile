/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58ab10; label: FUN_0058ab10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058ab10(undefined2 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_ESI;
  undefined2 *unaff_EDI;
  
  iVar3 = FUN_004f7fb0();
  while (iVar3 != 0) {
    iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"character");
    if (iVar3 == 0) {
      iVar3 = FUN_004f7fb0();
      if (iVar3 != 0) {
        uVar2 = FUN_0055b1c0(*(undefined4 *)(unaff_ESI + 0x510));
        *param_1 = uVar2;
      }
    }
    else {
      iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"variant");
      if (iVar3 == 0) {
        iVar3 = FUN_004f7fb0();
        if (iVar3 != 0) {
          uVar1 = FUN_0055c0a0(*(undefined4 *)(unaff_ESI + 0x510));
          *param_2 = uVar1;
        }
      }
      else {
        iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"action");
        if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(), iVar3 != 0)) {
          uVar2 = FUN_00630740(*(undefined4 *)(unaff_ESI + 0x510));
          *unaff_EDI = uVar2;
        }
      }
    }
    iVar3 = FUN_004f7fb0();
  }
  return;
}

