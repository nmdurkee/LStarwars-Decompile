/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46d820; label: FUN_0046d820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046d820(void)

{
  undefined2 uVar1;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return;
  }
  if (*(short *)(unaff_ESI + 0x86) != -1) {
    FUN_0067c930((int)*(short *)(unaff_ESI + 0x86));
  }
  switch(*(undefined1 *)(unaff_ESI + 0x61)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_0046d846_default;
  }
  uVar1 = FUN_0067c4f0();
  *(undefined2 *)(unaff_ESI + 0x86) = uVar1;
switchD_0046d846_default:
  FUN_0067c7b0((int)*(short *)(unaff_ESI + 0x86),1);
  return;
}

