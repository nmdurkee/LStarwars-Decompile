/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2810; label: FUN_006e2810
 */

void FUN_006e2810(char param_1,char param_2,int param_3)

{
  int in_ECX;
  uint uVar1;
  
  if ((param_3 == 0) || (*(short *)(in_ECX + 0x6e4) != 1)) {
    uVar1 = 0;
    if (param_1 == '\0') {
      uVar1 = 7;
    }
    if (param_2 == '\0') {
      uVar1 = uVar1 | 8;
    }
    if (param_3 == 0) {
      FUN_006e5340(0xa8,uVar1);
    }
    else {
      if (param_3 == 1) {
        FUN_006e5340(0xbe,uVar1);
        return;
      }
      if (param_3 == 3) {
        FUN_006e5340(0xbf,uVar1);
        return;
      }
    }
  }
  return;
}

