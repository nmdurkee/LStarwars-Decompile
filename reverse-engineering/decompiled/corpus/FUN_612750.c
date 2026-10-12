/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612750; label: FUN_00612750
 */

void FUN_00612750(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  _memset((void *)(in_ECX + 0x30),0,0xc000);
  _memset((void *)(in_ECX + 0xc034),0,0x1000);
  FUN_0060e1b0(in_ECX,3,&DAT_0076ac54);
  if (in_ECX == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = in_ECX + 4;
  }
  FUN_006be8f0(iVar1);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
  *(undefined1 *)(in_ECX + 0xd96c) = 1;
  return;
}

