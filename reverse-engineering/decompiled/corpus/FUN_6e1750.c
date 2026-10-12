/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e1750; label: FUN_006e1750
 */

void FUN_006e1750(void)

{
  int iVar1;
  undefined1 *in_ECX;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  *(undefined4 *)(in_ECX + 0xb8) = 0x42c80000;
  *in_ECX = 1;
  *(undefined4 *)(in_ECX + 0xbc) = 0x42c80000;
  *(undefined4 *)(in_ECX + 0xc0) = 0x44160000;
  *(undefined4 *)(in_ECX + 0xc4) = 0x43fa0000;
  FUN_006dffc0();
  *(undefined1 **)(in_ECX + 0xb4) = in_ECX + 0x10;
  FUN_006e0320();
  if (in_ECX[0x504] != '\0') {
    _sprintf(local_404,"Log.txt");
    iVar1 = FUN_004fa5f0(local_404,1);
    *(int *)(in_ECX + 0x500) = iVar1;
    if (iVar1 != 0) {
      FUN_004f0750(iVar1,"-- Log Started --\n\n");
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

