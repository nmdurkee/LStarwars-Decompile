/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0750; label: FUN_004f0750
 */

void FUN_004f0750(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,param_2,(int)pcVar2 - (int)(param_2 + 1),0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1);
    return;
  }
  FUN_004ff3f0(param_1 + -1,param_2,(int)pcVar2 - (int)(param_2 + 1));
  return;
}

