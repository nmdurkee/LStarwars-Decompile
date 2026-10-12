/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46d820; label: FUN_0046d820
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

