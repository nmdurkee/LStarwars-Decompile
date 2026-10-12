/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4500; label: FUN_006d4500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_006d4500(byte param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if ((param_1 & 4) != 0) {
    iVar2 = 0;
    iVar4 = in_ECX + 0x2700;
    do {
      iVar1 = FUN_004f8b10(iVar4,param_2);
      if (iVar1 == 0) {
        return (char *)((iVar2 + 0x40) * 0x9c + in_ECX);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x9c;
    } while (iVar2 < 0x40);
  }
  if ((param_1 & 2) != 0) {
    iVar2 = 0;
    iVar4 = in_ECX;
    do {
      iVar1 = FUN_004f8b10(iVar4,param_2);
      if (iVar1 == 0) {
        return (char *)(iVar2 * 0x9c + in_ECX);
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x9c;
    } while (iVar2 < 0x40);
  }
  if ((param_1 & 1) != 0) {
    iVar4 = 0;
    pcVar5 = s_USB_Joystick_00824fc0;
    uVar3 = 0;
    do {
      iVar2 = FUN_004f8b10(pcVar5,param_2);
      if (iVar2 == 0) {
        return s_USB_Joystick_00824fc0 + iVar4 * 0x9c;
      }
      uVar3 = uVar3 + 0x9c;
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 0x9c;
    } while (uVar3 < 0xea0);
  }
  return (char *)0x0;
}

