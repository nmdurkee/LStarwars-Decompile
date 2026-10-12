/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59ccd0; label: FUN_0059ccd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059ccd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                 undefined1 param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_004f1ff0(param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_00552670(param_10,param_11,iVar1 + 1);
    FUN_004f1f10(uVar2,param_1);
  }
  unaff_ESI[1] = param_2;
  unaff_ESI[2] = param_3;
  *unaff_ESI = uVar2;
  *(undefined1 *)(unaff_ESI + 4) = param_5;
  unaff_ESI[3] = param_4;
  *(undefined1 *)((int)unaff_ESI + 0x11) = param_6;
  *(undefined1 *)((int)unaff_ESI + 0x12) = param_7;
  *(undefined1 *)((int)unaff_ESI + 0x13) = param_8;
  *(undefined1 *)(unaff_ESI + 5) = param_9;
  return;
}

