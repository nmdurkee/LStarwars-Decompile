/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60e250; label: FUN_0060e250
 */

void FUN_0060e250(int param_1,char param_2)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_254;
  undefined4 local_250;
  int local_24c;
  char local_248;
  undefined1 local_247 [579];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_254;
  local_248 = param_2;
  local_254 = 0;
  local_250 = 0;
  local_24c = param_1;
  FUN_0060df50(local_247);
  piVar1 = *(int **)(in_ECX + 4);
  local_247[0] = 0;
  do {
    if (piVar1 == (int *)0x0) {
LAB_0060e301:
      __security_check_cookie(local_4 ^ (uint)&local_254);
      return;
    }
    if ((piVar1[2] == local_24c) && ((char)piVar1[3] == local_248)) {
      if (*piVar1 == 0) {
        *(int *)(in_ECX + 8) = piVar1[1];
      }
      else {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      if ((int *)piVar1[1] == (int *)0x0) {
        *(int *)(in_ECX + 4) = *piVar1;
      }
      else {
        *(int *)piVar1[1] = *piVar1;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
      FUN_006334d0(piVar1,0x250);
      goto LAB_0060e301;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}

